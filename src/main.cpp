#include "main.h"
#include "../include/285Z_Subsystems/flywheel.hpp"
#include "../include/285Z_Subsystems/intake.hpp"
#include "../include/285z/functions.hpp"
#include "../include/285z/initSensors.hpp"
#include "../include/pros/llemu.hpp"
#include "285Z_Subsystems/pid.hpp"
#include "285z/initRobot.hpp"
#include "sylib/system.hpp"

Intake in;
Flywheel fw;

int autoIndex = 0;

std::string autList[] = {
    "No Auton",  "Skills Auton", "Left Low",      "Left High",
    "Right Low", "Right High",   "Full Winpoint",
};

int len = sizeof(autList) / sizeof(autList[0]);

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
void initialize() { pros::lcd::initialize(); }

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
void competition_initialize() {
  imuSensor.reset();
  while (imuSensor.is_calibrating()) {
    pros::delay(15);
  }

  driveL.setBrakeMode(AbstractMotor::brakeMode::hold);
  driveR.setBrakeMode(AbstractMotor::brakeMode::hold);

  pros::lcd::set_text(6, "// CALIBRATION COMPLETE //");

  while (true) {
    bool autval = autonSelector.get_value();

    if (autval == 1) {
      pros::delay(200);
      autoIndex = (autoIndex + 1) % len;
    }

    pros::lcd::set_text(7, autList[autoIndex]);

    pros::delay(20);
  }
}

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
  switch (autoIndex) {
  case (0):
    noAuton(normalAuto, fastAuto);
    break;
  case (1):
    skillsAuto(normalAuto, fastAuto);
    break;
  case (2):
    leftLow(normalAuto, fastAuto);
    break;
  case (3):
    leftHigh(normalAuto, fastAuto);
    break;
  case (4):
    rightLow(normalAuto, fastAuto);
    break;
  case (5):
    rightHigh(normalAuto, fastAuto);
    break;
  case (6):
    winPoint(normalAuto, fastAuto);
    break;
  default:
    noAuton(normalAuto, fastAuto);
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

  while (1) {
    model->tank(controller.getAnalog(okapi::ControllerAnalog::leftY),
                controller.getAnalog(okapi::ControllerAnalog::rightY));

    // model->arcade(controller.getAnalog(okapi::ControllerAnalog::rightY),
    // controller.getAnalog(okapi::ControllerAnalog::rightX));

    in.run();
    fw.spin();
    fw.shooter();
    endgame();
    pros::delay(20);
  }
}
