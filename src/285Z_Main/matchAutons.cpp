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
  // turn(15);
  // PIDchassis->moveDistance(-0.5_ft);
  // turn(-15);

  // // roller spin

  // turn(-15);
  // autoSpin();
  // autoShoot();
  // pros::delay(5000);
  // autoShoot();
  // autoSpin(); // stops spinning

  move(med, 0.5_ft, bwd);
  intakeMotor.moveVelocity(600);
  pros::delay(200);
  intakeMotor.moveVelocity(0);
}



void redRightBlueRight(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

  turn(90);
  PIDchassis->moveDistance(2_ft);
  turn(-90);
  
  // roller spin

  turn(15);
  autoSpin();
  autoShoot();
  pros::delay(5000);
  autoShoot();
  autoSpin(); // stops spinning
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
  autoSpin();
  autoShoot();
  pros::delay(5000);
  autoShoot();
  autoSpin(); // stops spinning
}