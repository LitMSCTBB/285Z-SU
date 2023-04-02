#include "../include/285z/initRobot.hpp"
#include "../include/285z/initSensors.hpp"
#include "../include/285z/functions.hpp"
#include "../include/285Z_Subsystems/pid.hpp"
#include "../include/285Z_Subsystems/flywheel.hpp"
#include "../include/285z/initSensors.hpp"
#include "pros/rtos.hpp"

//***************************** RED/BLUE AUTONOMOUS PROGRAMS **********************//


void leftLow(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{
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
  autoSpin(129);
  // moveDrive(-0.25, false);
  driveL.moveRelative(-0.25 * 12 / (3.25 * pi) * 360 * 5 / 3, 300);
  driveR.moveRelative(-0.25 * 12 / (3.25 * pi) * 360 * 5 / 3, 300);
  pros::delay(100);
  intakeMotor.moveVoltage(12000);
  pros::delay(200);
  intakeMotor.moveVoltage(0);

  pros::delay(200);

  moveDrive(0.25, false);
  turn(315);
  intakeMotor.moveVoltage(12000);
  moveDrive(0.5, false);
  pros::delay(800);
  intakeMotor.moveVoltage(0);

  driveL.moveRelative(-0.4 * 12 / (3.25 * pi) * 360 * 5 / 3, 300);
  driveR.moveRelative(-0.4 * 12 / (3.25 * pi) * 360 * 5 / 3, 300);
  pros::delay(600);
  turn(355.5);

  pros::delay(2500);

  intakeMotor.moveVoltage(-12000);
  indexer.set_value(false);
  pros::delay(500);
  indexer.set_value(true);
  pros::delay(2000);
  indexer.set_value(false);
  pros::delay(500);
  indexer.set_value(true);
  pros::delay(2000);
  indexer.set_value(false);
  pros::delay(1000);
  intakeMotor.moveVoltage(0);
  autoSpin();
}

void rightLow(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{
  autoSpin(75);
  pros::delay(2000);
  autoShoot();
  autoSpin(75);
  
  move(fast, -1.5_ft, bwd);
  turn(90);
  pros::delay(1000);
  move(fast, -.000000001_ft, bwd);
  intakeMotor.moveVoltage(12000);
  pros::delay(200);
  intakeMotor.moveVoltage(0);
}

void rightHigh(std::shared_ptr<okapi::AsyncMotionProfileController> med,
                std::shared_ptr<okapi::AsyncMotionProfileController> fast) {
  autoSpin(131);
  intakeMotor.moveVoltage(8000);
  pros::delay(100);
  move(fast, 1.5_ft, fwd);
  move(fast, 1.5_ft, bwd);
  turn(26);

  pros::delay(2000);

  intakeMotor.moveVoltage(-12000);
  indexer.set_value(false);
  pros::delay(500);
  indexer.set_value(true);
  pros::delay(2000);
  indexer.set_value(false);
  pros::delay(500);
  indexer.set_value(true);
  pros::delay(2000);
  indexer.set_value(false);
  pros::delay(2000);
  intakeMotor.moveVoltage(0);

  move(fast, 1.5_ft, fwd);
  turn(320);
  move(fast, 4.8_ft, bwd);
  turn(2.5);
  move(fast, 0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001_ft, bwd);

  intakeMotor.moveVoltage(12000);
  pros::delay(150);
  intakeMotor.moveVoltage(0);
  autoSpin();
}

void winPoint(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{
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