#include "../include/285Z_Subsystems/flywheel.hpp"
#include "../include/285Z_Subsystems/pid.hpp"
#include "../include/285z/functions.hpp"
#include "../include/285z/initRobot.hpp"
#include "../include/285z/initSensors.hpp"
#include "pros/rtos.hpp"

//***************************** RED/BLUE AUTONOMOUS PROGRAMS
//**********************//

void leftLow(std::shared_ptr<okapi::AsyncMotionProfileController> med,
             std::shared_ptr<okapi::AsyncMotionProfileController> fast) {
  // autoSpin(90);
  // intakeMotor.moveVoltage(12000);
  // moveDrive(0.2, false);
  // pros::delay(200);
  // intakeMotor.moveVoltage(0);
  // pros::delay(500);

  // autoShoot();
  // autoSpin(90);

  // turn(-340);
  // moveDrive(-0.2, false);
  // turn(20);
  // moveDrive(-0.2, false);

  // intakeMotor.moveVoltage(12000);
  // pros::delay(200);
  // intakeMotor.moveVoltage(0);
}

void leftHigh(std::shared_ptr<okapi::AsyncMotionProfileController> med,
              std::shared_ptr<okapi::AsyncMotionProfileController> fast) {
  autoSpin(550);
  // move back to roller
  driveL.moveRelative(-0.35 * 12 / (3.25 * pi) * 360 * 5 / 3, 150);
  driveR.moveRelative(-0.35 * 12 / (3.25 * pi) * 360 * 5 / 3, 150);

  // roller
  pros::delay(200);
  intakeMotor.moveVoltage(12000);
  pros::delay(300);
  intakeMotor.moveVoltage(0);

  pros::delay(100);

  // move forward from roller
  // driveL.moveRelative(1.0 * 12 / (3.25 * pi) * 360 * 5 / 3, 300);
  // driveR.moveRelative(1.0 * 12 / (3.25 * pi) * 360 * 5 / 3, 300);
  moveDrive(0.22, false);
  pros::delay(100);

  // turn to intake
  turn(310);
  intakeMotor.moveVoltage(12000);
  moveDrive(0.3, false);
  pros::delay(1100);
  intakeMotor.moveVoltage(0);
  pros::delay(100);
  intakeMotor.moveVoltage(-12000);
  pros::delay(100);
  intakeMotor.moveVoltage(0);

  // back up from disk
  driveL.moveRelative(-0.25 * 12 / (3.25 * pi) * 360 * 5 / 3, 300);
  driveR.moveRelative(-0.25 * 12 / (3.25 * pi) * 360 * 5 / 3, 300);
  pros::delay(600);

  // turn for shooting (between disk-roller line and line
  // perpendicular to roller)
  turn(350);

  // shoot
  pros::delay(500);
  indexer.set_value(true);
  pros::delay(200);
  indexer.set_value(false);
  pros::delay(200);
  indexer.set_value(true);
  pros::delay(200);
  indexer.set_value(false);
  pros::delay(400);
  indexer.set_value(true);
  pros::delay(200);
  indexer.set_value(false);

  // move to three stack
  pros::delay(100);
  turn(50);
  intakeMotor.moveVoltage(-12000);
  // moveDrive(1.4, false);
  driveL.moveVoltage(8000);
  driveR.moveVoltage(8000);
  pros::delay(400);
  driveL.moveVoltage(0);
  driveR.moveVoltage(0);
  intakeMotor.moveVoltage(0);
  pros::delay(100);
  intakeMotor.moveVoltage(12000);
  moveDrive(0.2, false);
  intakeMotor.moveVoltage(0);

  autoSpin();
}

void rightLow(std::shared_ptr<okapi::AsyncMotionProfileController> med,
              std::shared_ptr<okapi::AsyncMotionProfileController> fast) {
  // autoSpin(75);
  // pros::delay(2000);
  // autoShoot();
  // autoSpin(75);

  // move(fast, -1.5_ft, bwd);
  // turn(90);
  // pros::delay(1000);
  // move(fast, -.000000001_ft, bwd);
  // intakeMotor.moveVoltage(12000);
  // pros::delay(200);
  // intakeMotor.moveVoltage(0);
}

void rightHigh(std::shared_ptr<okapi::AsyncMotionProfileController> med,
               std::shared_ptr<okapi::AsyncMotionProfileController> fast) {
//Turn on FW, Intake disc, go back and turn
  autoSpin(440);
  intakeMotor.moveVoltage(12000);
  //move(fast, 1.2_ft, fwd);
  //pros::delay(1000);
  //move(fast, 1.2_ft, bwd);
  driveL.moveVoltage(12000);
  driveR.moveVoltage(12000);
  pros::delay(250);
  driveL.moveVoltage(0);
  driveR.moveVoltage(0);
  pros::delay(2000);
  turn(24);
  driveL.moveVoltage(8000);
  driveR.moveVoltage(8000);
  pros::delay(400);
  driveL.moveVoltage(0);
  driveR.moveVoltage(0);

  pros::delay(200);

//Outtake just in case then shoot 3 discs
  intakeMotor.moveVoltage(-12000);
  pros::delay(300);
  intakeMotor.moveVoltage(0);
  indexer.set_value(true);
  pros::delay(200);
  indexer.set_value(false);
  pros::delay(300);
  indexer.set_value(true);
  pros::delay(200);
  indexer.set_value(false);
  pros::delay(1000);
  indexer.set_value(true);
  pros::delay(200);
  indexer.set_value(false);

  turn(320);
  driveL.moveVoltage(-12000);
  driveR.moveVoltage(-12000);
  pros::delay(500);
  driveL.moveVoltage(0);
  pros::delay(200);
  driveR.moveVoltage(0);
  pros::delay(100);

  driveL.moveVoltage(-12000);
  driveR.moveVoltage(-12000);
  pros::delay(200);
  driveL.moveVoltage(0);
  driveR.moveVoltage(0);

  intakeMotor.moveVoltage(12000);
  pros::delay(150);
  intakeMotor.moveVoltage(0);
  autoSpin();
}

void winPoint(std::shared_ptr<okapi::AsyncMotionProfileController> med,
              std::shared_ptr<okapi::AsyncMotionProfileController> fast) {
  // turn(15);
  // PIDchassis->moveDistance(-0.5_ft);
  // turn(-15);

  // // roller spin

  // move(fast, 1_ft, fwd);
  // // move diagonally parallel to center diagonal white line
  // turn(45);
  // move(fast, 6_ft, fwd);
  // turn(135);

  // move(fast, -0.5_ft, bwd);

  // // roller spin

  // turn(15);
  // autoSpin(200);
  // autoShoot();
  // pros::delay(5000);
  // autoShoot();
  // autoSpin(200); // stops spinning
}