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

  // for 3 stack
  // intakeMotor.moveVoltage(11000);
  // turn(45);
  // move(fast, 4_ft, fwd);
  // intakeMotor.moveVoltage(0);
  // turn(55);
  // autoShoot();
  // autoSpin(400); // turns off fw
}

void leftHigh(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast) {
  turn(-15);
  autoSpin(150);
  pros::delay(2000);
  autoShoot();
  autoSpin(150);

  move(med, 0.00000000000000000000000000000000000000000000000000000000000000000000005_ft, bwd);
  moveDrive(-30);
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
  autoSpin(130);
  turn(23);
  pros::delay(5000);
  
  intakeMotor.moveVoltage(-12000);
  indexer.set_value(false);
  pros::delay(500);
  indexer.set_value(true);
  pros::delay(2000); // Delay
  indexer.set_value(false);
  pros::delay(500);
  indexer.set_value(true);
  pros::delay(400);
  intakeMotor.moveVoltage(0);

  // autoSpin(125);
  // pros::delay(1000);
  // indexer.set_value(true);
  

  move(fast, 1.5_ft, fwd);
  turn(330);
  move(med,1.2_ft, bwd);
  intakeMotor.moveVoltage(12000);
  pros::delay(200);
  intakeMotor.moveVoltage(0);
}

void winPoint(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{
  turn(15);
  PIDchassis->moveDistance(-0.5_ft);
  turn(-15);

  // roller spin

  move(fast, 1_ft, fwd);
  // move diagonally parallel to center diagonal white line
  turn(45);
  move(fast, 6_ft, fwd);
  turn(135);
  
  move(fast, -0.5_ft, bwd);
  
  // roller spin

  turn(15);
  autoSpin(200);
  autoShoot();
  pros::delay(5000);
  autoShoot();
  autoSpin(200); // stops spinning
}