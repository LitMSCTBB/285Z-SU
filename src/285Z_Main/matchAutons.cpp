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
  move(med, 0.00000000000000000000000000000000000000000000000000000000000000000000005_ft, bwd);
  autoSpin(90);
  moveDrive(-30);
  intakeMotor.moveVoltage(12000);
  pros::delay(150);
  intakeMotor.moveVoltage(0);
  
  pros::delay(500);
  moveDrive(30);
  turn(105);
  autoShoot();
  autoSpin(90);
}

void leftHigh(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast) {
  autoSpin(128);
  pros::delay(6000);
  autoShoot();
  autoSpin(128);

  move(med, 0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001_ft, bwd);
  intakeMotor.moveVoltage(12000);
  pros::delay(150);
  intakeMotor.moveVoltage(0); 
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
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{
  autoSpin(133.5);
  turn(22.5);
  pros::delay(4300);
  
  intakeMotor.moveVoltage(-12000);
  indexer.set_value(false);
  pros::delay(500);
  indexer.set_value(true);
  pros::delay(2000); // Delay
  indexer.set_value(false);
  pros::delay(1000);
  indexer.set_value(true);
  pros::delay(400);
  intakeMotor.moveVoltage(0);

  move(fast, 1.5_ft, fwd);
  turn(330);
  move(fast, 0.4_ft, bwd);
  turn(2.5);
  intakeMotor.moveVoltage(12000);
  pros::delay(200);
  intakeMotor.moveVoltage(0);
  autoSpin(133.5);
}

void rightHigh3(std::shared_ptr<okapi::AsyncMotionProfileController> med,
                std::shared_ptr<okapi::AsyncMotionProfileController> fast) {
  autoSpin(128);
  intakeMotor.moveVoltage(7000);
  // turn(355);
  move(fast, 1.5_ft, fwd);
  move(fast, 1.5_ft, bwd);
  turn(27);

  pros::delay(100);

  intakeMotor.moveVoltage(-12000);
  indexer.set_value(false);
  pros::delay(500);
  indexer.set_value(true);
  pros::delay(2000); // Delay
  indexer.set_value(false);
  pros::delay(500);
  indexer.set_value(true);
  pros::delay(2000);
  indexer.set_value(false);
  pros::delay(1000);
  intakeMotor.moveVoltage(0);

  move(fast, 1.5_ft, fwd);
  turn(320);
  move(fast, 4.8_ft, bwd);
  turn(2.5);
  // moveDrive(-10);
  move(fast, 0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001_ft, bwd);

  // turn(68.5);
  // pros::delay(100);
  // move(fast, 1.5_ft, fwd);
  // pros::delay(100);
  // turn(270);
  // move(fast, 0.00000000000001_ft, bwd);

  intakeMotor.moveVoltage(12000);
  pros::delay(150);
  intakeMotor.moveVoltage(0);
  autoSpin(128);
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