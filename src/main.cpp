#include "main.h"
#include "../include/init/functions.hpp"
#include "../include/init/initRobot.hpp"
#include "../include/init/initSensors.hpp"
#include "../include/pros/llemu.hpp"
#include "../include/subsystems/drive.hpp"
#include "../include/subsystems/flywheel.hpp"
#include "../include/subsystems/intake.hpp"
#include "../include/subsystems/blooper.hpp"
#include "../include/subsystems/expansion.hpp"

Intake in;
Flywheel fw;
Drive d;
Blooper b;
Expansion ex;

const std::vector<std::string> autons = {
    "No Autonomous       ", "Full WP             ", "RS High Goal        ",
    "LS High Goal        ", "RS Rush             "};

const int numAutons = (int)autons.size();
int aut = 3;
int timeV = 0;
uint32_t elapsed = 0;

//**************** INITIALIZE ALL CHASSIS FOR AUTON ********************//

std::shared_ptr<ChassisController> chassis =
    okapi::ChassisControllerBuilder()
        .withMotors(driveL, driveR)
        .withDimensions({AbstractMotor::gearset::blue, (60.0 / 36.0)},
                        {{3.25_in, 11.5_in}, imev5BlueTPR})
        .withMaxVoltage(12000)
        .build();

std::shared_ptr<okapi::ChassisModel> model =
    std::dynamic_pointer_cast<okapi::ChassisModel>(chassis->getModel());

std::shared_ptr<okapi::ChassisController> PIDchassis =
    okapi::ChassisControllerBuilder()
        .withMotors(driveL, driveR)
        .withDimensions({AbstractMotor::gearset::blue, (60.0 / 36.0)},
                        {{3.25_in, 11.42_in}, imev5BlueTPR})
        .withMaxVoltage(12000)
        .withGains({0.3, 0.0, 0.00005}, // Distance controller gains
                   {0.0, 0.0, 0.0},     // Turn controller gains
                   {0.0, 0, 0.0}
                   // Angle controller gains (helps drive straight)
                   )
        .withClosedLoopControllerTimeUtil(50, 5, 250_ms)
        .withDerivativeFilters(
            std::make_unique<AverageFilter<3>>() // Distance controller filter
            )
        .build();

std::shared_ptr<okapi::AsyncMotionProfileController> fastAuto =
    AsyncMotionProfileControllerBuilder()
        .withLimits({
            2.7, // max linear velocity of Chassis in m/s
            9,   // max linear acceleration in m/s^2
            18.0 // max linear jerk in m/s^3
        })
        .withOutput(PIDchassis)
        .buildMotionProfileController();

std::shared_ptr<okapi::AsyncMotionProfileController> normalAuto =
    AsyncMotionProfileControllerBuilder()
        .withLimits({
            0.5, // max linear velocity of Chassis in m/s
            1.5, // max linear acceleration in m/s^2
            3.5  // max linear jerk in m/s^3
        })
        .withOutput(PIDchassis)
        .buildMotionProfileController();

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
  pros::lcd::initialize();
  controller.clear();
  pros::delay(110);
  pros::lcd::print(0, "Initializing...");

  intakeMotor.setBrakeMode(AbstractMotor::brakeMode::hold);
  flywheelMotor.setBrakeMode(AbstractMotor::brakeMode::coast);
  pros::lcd::print(2, "Brake modes set");

  leftEnc.reset();
  rightEnc.reset();
  pros::lcd::print(3, "Tracking wheels reset");

  pros::lcd::print(4, "Calibrating...");
  imuSensor.reset();
  while (imuSensor.is_calibrating()) {
    pros::delay(5);
  }
  imuSensor.set_heading(0);
  pros::lcd::print(4, "Reset IMU     ");

  topExpansion.set_value(false);
  laserExpansion.set_value(false);
  blooper.set_value(false);
  pistonIntake.set_value(false);
  pros::lcd::print(5, "Set pistons");
  
  controller.clear();
  pros::delay(110);

  pros::Task tm([] {
    std::vector<std::string> motors = {};

    controller.setText(0, 0, autons[aut]);

    while (true) {
      motors.clear();

      if (autonSelector.get_new_press()) {
        aut = ((aut + 1) >= numAutons) ? 0 : aut + 1;
        pros::delay(50);
        controller.rumble(".");
        pros::delay(50);
        controller.setText(0, 0, autons[aut]);
      }

      controller.setText(
          1, 0,
          "Battery at " + std::to_string((int)pros::battery::get_capacity()) +
              "%        ");

      if (flywheelMotor.getTemperature() >= 46.5)
        motors.push_back("FW");
      if (intakeMotor.getTemperature() >= 46.5)
        motors.push_back("I");
      if (driveL.getTemperature() >= 50.0 || driveR.getTemperature() >= 50.0)
        motors.push_back("D");

      if (!motors.empty() && timeV < 100)
        controller.setText(2, 0,
                           std::accumulate(motors.begin() + 1, motors.end(),
                                           motors[0],
                                           [](std::string x, std::string y) {
                                             return x + ", " + y;
                                           }) +
                               " overheating     ");
      else if (timeV <= 200) {
        controller.setText(2, 0, "");
        if (timeV == 200) {
          timeV = 0;
        }
      }
      // printf("%.3f, %.3f, %.3f, %d\n", LD.getTemperature(),
      // RD.getTemperature(), pros::battery::get_capacity(),
      // controller.getBatteryCapacity());

      pros::delay(10);
    }
  });
}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
  fw.setTarget(0);
  pros::Task{[=] {
    while (true)
    {
      fw.auton();
      pros::delay(10);
    }
  }};
  pros::Task{[=] {
    while (true) {
      d.run();
      pros::delay(10);
    }
  }};
  driveL.setBrakeMode(AbstractMotor::brakeMode::brake);
  driveR.setBrakeMode(AbstractMotor::brakeMode::brake);
  switch (aut) {
  case (0):
    noAuton();
    break;
  case (1):
    fullWP();
    break;
  case (2):
    rightSideHighGoal();
    break;
  case (3):
    leftSideHighGoal();
    break;
  case (4):
    rightSideRush();
    break;
  default:
    noAuton();
    break;
  }
}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */

void opcontrol() {  
  driveL.setBrakeMode(AbstractMotor::brakeMode::hold);
  driveR.setBrakeMode(AbstractMotor::brakeMode::hold);

  auto fwT = pros::Task {
    [=] {
      while (true) {
        fw.op();
        in.run();
        ex.run();
        b.run();
        pros::delay(10);
      }
    }
  };

  // auto inT = pros::Task {
  //   [=] {
  //     in.run();
  //   }
  // };

  // auto exT = pros::Task {
  //   [=] { ex.run(); }
  // };

  while (1) {
    model->tank(controller.getAnalog(okapi::ControllerAnalog::leftY),
                controller.getAnalog(okapi::ControllerAnalog::rightY));

    pros::delay(20);
  }
}
