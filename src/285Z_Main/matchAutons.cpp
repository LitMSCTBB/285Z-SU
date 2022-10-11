#include "../include/285z/initRobot.hpp"
#include "../include/285z/initSensors.hpp"
#include "../include/285z/functions.hpp"
#include "../include/285Z_Subsystems/pid.hpp"
#include "../include/285Z_Subsystems/flywheel.hpp"
#include "../include/285z/initSensors.hpp"

//***************************** RED/BLUE AUTONOMOUS PROGRAMS **********************//


void redLeftBlueLeft(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{
  turn(15);
  PIDchassis->moveDistance(-0.5_ft);
  turn(-15);

  // roller spin

  turn(-15);
  autoSpin();
  autoShoot();
  pros::delay(5000);
  autoShoot();
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
}



void neutralSideRight(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

  // //neutral rush
  // PIDchassis->moveDistanceAsync(4.3_ft);

  // clawMech.set_value(0);
  // pros::delay(1000);
  // clawMech.set_value(true);

  // PIDchassis->stop();
  // fourbarLift(150);
  // PIDchassisGoal->moveDistance(-4.6_ft);
}

void neutralSideLeft(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

  // //neutral rush
  // PIDchassis->moveDistanceAsync(4.4_ft);

  // clawMech.set_value(0);
  // pros::delay(1100);
  // clawMech.set_value(true);

  // PIDchassis->stop();
  // fourbarLift(150);
  // PIDchassisGoal->moveDistance(-4.6_ft);
}



void neutralCenterRight(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

  // //neutral rush
  // PIDchassis->moveDistanceAsync(6.4_ft);

  // clawMech.set_value(0);
  // pros::delay(1270);
  // clawMech.set_value(true);

  // PIDchassis->stop();
  // fourbarLift(200);
  // PIDchassisGoal->moveDistance(-6.5_ft);
}

void neutralCenterLeft(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

  // //neutral rush
  // PIDchassis->moveDistanceAsync(7.5_ft);

  // clawMech.set_value(0);
  // pros::delay(1400);
  // clawMech.set_value(true);

  // PIDchassis->stop();
  // fourbarLift(150);
  // PIDchassisGoal->moveDistance(-7_ft);
}


void neutralSideCenterRight(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

//   //neutral rush
//   PIDchassis->moveDistanceAsync(4.3_ft);
//   clawMech.set_value(0);
//   pros::delay(1180); //old value: 1180
//   clawMech.set_value(true);
//   fourbarLift(200);

//   PIDchassis->moveDistance(-4.3_ft);

//   turn(45);
//   clawMech.set_value(false);
//   turn(330);

//   fast->setTarget("centerNeutral", fwd);
//   pros::delay(1420);
//   clawMech.set_value(true);
//   fast->waitUntilSettled();

//   fast->setTarget("centerNeutral", bwd);
//   fourbarLift(200);

//   fast->waitUntilSettled();

//   fourbarLift(0);
//   clawMech.set_value(false);
}

void neutralSideCenterLeft(std::shared_ptr<okapi::AsyncMotionProfileController> med,
   std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

  // //neutral rush
  // PIDchassis->moveDistanceAsync(3.75_ft);

  // clawMech.set_value(0);
  // pros::delay(900);
  // clawMech.set_value(true);

  // PIDchassis->stop();
  // PIDchassisGoal->moveDistance(-3_ft);

  // fast->setTarget("centerNeutralLeft", fwd);
  // pros::delay(1420);
  // clawMech.set_value(true);
  // fourbarLift(600);
  // fast->waitUntilSettled();

  // fast->setTarget("centerNeutralLeft", bwd);
  // fast->waitUntilSettled();

  // fourbarLift(0);
  // clawMech.set_value(0);
}
