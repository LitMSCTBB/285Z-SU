#include "285z/initRobot.hpp"
#include "../include/285z/functions.hpp"
#include "285Z_Subsystems/pid.hpp"
#include "285Z_Subsystems/flywheel.hpp"
#include "../include/285z/initSensors.hpp"
#include "../include/pros/llemu.hpp"
#include "pros/misc.h"

Flywheel fw;

//**************** INITIALIZE ALL CHASSIS FOR AUTON ********************//


std::shared_ptr<ChassisController> chassis = okapi::ChassisControllerBuilder()
      .withMotors(leftFrontMotor, rightFrontMotor, rightBackMotor, leftBackMotor)
      .withDimensions({AbstractMotor::gearset::green, (1.0 / 1.0)}, {{3.25_in, 12.5_in}, imev5GreenTPR})
      .withMaxVoltage(12000)
      .build();

std::shared_ptr<okapi::XDriveModel> model = std::dynamic_pointer_cast<okapi::XDriveModel>(chassis->getModel());

// std::shared_ptr<okapi::AsyncMotionProfileController> fastAuto = AsyncMotionProfileControllerBuilder()
//       .withLimits({
//         2.7, //max linear velocity of Chassis in m/s
//         9, //max linear acceleration in m/s^2
//         18.0 //max linear jerk in m/s^3
//       })
//       .withOutput(chassis)
//       .buildMotionProfileController();

// std::shared_ptr<okapi::AsyncMotionProfileController> normalAuto = AsyncMotionProfileControllerBuilder()
//       .withLimits({
//         0.5, //max linear velocity of Chassis in m/s
//         1.5, //max linear acceleration in m/s^2
//         3.5 //max linear jerk in m/s^3
//       })
//       .withOutput(chassis)
//       .buildMotionProfileController();

// std::shared_ptr<okapi::ChassisController> PIDchassis = okapi::ChassisControllerBuilder()
//     .withMotors(driveL, driveR)
//     .withDimensions({AbstractMotor::gearset::blue, (60.0 / 36.0)}, {{3.25_in, 14.5_in}, imev5BlueTPR})
//     .withMaxVoltage(12000)
//     .withGains(
//       {0.00191, 0.0, 0.00005}, // Distance controller gains  
//       {0.001, 0, 0.0001}, // Turn controller gains
//       {0.001, 0, 0.0001}  // Angle controller gains (helps drive straight)
//     )
//     .withClosedLoopControllerTimeUtil(50, 5, 250_ms)
//     .withDerivativeFilters(
//         std::make_unique<AverageFilter<3>>() // Distance controller filter
//     )
//     .build();

// std::shared_ptr<okapi::ChassisController> PIDchassisGoal = okapi::ChassisControllerBuilder()
//     .withMotors(driveL, driveR)
//     .withDimensions({AbstractMotor::gearset::blue, (60.0 / 36.0)}, {{3.25_in, 14.5_in}, imev5BlueTPR})
//     .withMaxVoltage(12000)
//     .withGains(
//       {0.0014, 0, 0.000007}, // Distance controller gains 
//       {0.001, 0, 0.0001}, // Turn controller gains
//       {0.001, 0, 0.0001}  // Angle controller gains (helps drive straight)
//     )
//     .withClosedLoopControllerTimeUtil(50, 5, 250_ms)
//     .withDerivativeFilters(
//         std::make_unique<AverageFilter<3>>() // Distance controller filter
//     )
//     .build();

// std::shared_ptr<ChassisController> xdrive = okapi::XDriveModel(std::shared_ptr<AbstractMotor> itopLeftMotor,
//                                 std::shared_ptr<AbstractMotor> itopRightMotor,
//                                 std::shared_ptr<AbstractMotor> ibottomRightMotor,
//                                 std::shared_ptr<AbstractMotor> ibottomLeftMotor,
//                                 std::shared_ptr<ContinuousRotarySensor> ileftEnc,
//                                 std::shared_ptr<ContinuousRotarySensor> irightEnc,
//                                 double imaxVelocity,
//                                 double imaxVoltage)

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
-+
  */

void disabled()
{
}

//
/** Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */

void competition_initialize()
{
  // imuSensor.reset();
  // while (imuSensor.is_calibrating())
  //   pros::delay(15);


  leftFrontMotor.setBrakeMode(AbstractMotor::brakeMode::hold);
  rightFrontMotor.setBrakeMode(AbstractMotor::brakeMode::hold);
  leftBackMotor.setBrakeMode(AbstractMotor::brakeMode::hold);
  rightBackMotor.setBrakeMode(AbstractMotor::brakeMode::hold);

  pros::lcd::initialize();

  pros::lcd::set_text(6, "// CALIBRATION COMPLETE //");

  while(true) {
    pros::delay(20);
  }

}

void autonomous()
{
  // switch(autoIndex) {
  //   case (0): noAuton(); break;
  //   case (1): skillsAuto(normalAuto, fastAuto); break;
  //   case (2): redLeftBlueLeft(normalAuto, fastAuto); break;
  //   case (3): redRightBlueRight(normalAuto, fastAuto); break;
  //   case (4): winPoint(normalAuto, fastAuto); break;
  //   case (5): neutralSideRight(normalAuto, fastAuto); break;
  //   case (6): neutralSideLeft(normalAuto, fastAuto); break;
  //   case (7): neutralCenterRight(normalAuto, fastAuto); break;
  //   case (8): neutralCenterLeft(normalAuto, fastAuto); break;
  //   case (9): neutralSideCenterRight(normalAuto, fastAuto); break;
  //   case (10): neutralSideCenterLeft(normalAuto, fastAuto); break;
  //   default: noAuton();
  // }
}


void opcontrol()
{
  model->setBrakeMode(AbstractMotor::brakeMode::hold);

  while (1) {
    double power = controller.getAnalog(okapi::ControllerAnalog::leftY);
    double turn = controller.getAnalog(okapi::ControllerAnalog::leftX);
    double strafe = controller.getAnalog(okapi::ControllerAnalog::rightX);
    // model->tank(controller.getAnalog(okapi::ControllerAnalog::leftY), controller.getAnalog(okapi::ControllerAnalog::rightY));
    model->xArcade(strafe, power, turn);

    fw.spin();

    // double LF = (power + turn + strafe) * 200;
    // double LB = (power + turn - strafe) * 200;
    // double RF = (power - turn - strafe) * 200;
    // double RB = (power - turn + strafe) * 200;

    // leftFrontMotor.moveVelocity(LF);
    // leftBackMotor.moveVelocity(LB);
    // rightFrontMotor.moveVelocity(RF);
    // rightBackMotor.moveVelocity(RB);

    pros::delay(20);
  }
}
