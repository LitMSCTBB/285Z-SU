#include "../include/285z/initRobot.hpp"
#include "../include/285z/initSensors.hpp"
#include "../include/285z/functions.hpp"
#include "../include/285Z_Subsystems/pid.hpp"
#include "../include/285Z_Subsystems/flywheel.hpp"
#include "../include/285z/initSensors.hpp"
#include "pros/rtos.hpp"

//***************************** RED/BLUE AUTONOMOUS PROGRAMS **********************//


void redLeftBlueLeft(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{
  // move(med, 0.005_ft, bwd);
  moveDrive(-100);
  intakeMotor.moveVoltage(12000);
  pros::delay(200);
  intakeMotor.moveVoltage(0);
  
  // turn(15);
  moveDrive(30);
  autoSpin(300);
  turn(100);
  autoShoot();
  autoSpin(300);

  // for 3 stack
  // intakeMotor.moveVoltage(11000);
  // turn(45);
  // move(fast, 4_ft, fwd);
  // intakeMotor.moveVoltage(0);
  // turn(55);
  // autoShoot();
  // autoSpin(400); // turns off fw
}

void redRightBlueRight(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{
  autoSpin(50);
  pros::delay(2000);
  autoShoot();
  autoSpin(50);
  
  moveDrive(-100);
  turn(90);
  moveDrive(-10);
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