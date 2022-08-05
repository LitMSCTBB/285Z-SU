#include "../include/285z/initRobot.hpp"
#include "../include/285z/initSensors.hpp"
#include "../include/285z/functions.hpp"
#include "../include/285Z_Subsystems/pid.hpp"
#include "../include/285z/initSensors.hpp"

//***************************** RED/BLUE AUTONOMOUS PROGRAMS **********************//


void redLeftBlueLeft(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

  // //neutral rush
  // PIDchassis->moveDistanceAsync(4.4_ft);

  // clawMech.set_value(0);
  // pros::delay(1100);
  // clawMech.set_value(true);

  // PIDchassis->stop();
  // fourbarLift(150);
  // PIDchassisGoal->moveDistance(-3.5_ft);


  // //left win point
  // turn(300);
  // move(med, 1.5_ft, bwd);

  // intakeMotor.moveVelocity(-500);
  // pros::delay(2000);
  // intakeMotor.moveVelocity(0);
  // move(fast, 1_ft, fwd);
}



void redRightBlueRight(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

  // //neutral rush
  // PIDchassis->moveDistanceAsync(4.3_ft);

  //   clawMech.set_value(0);
  //   pros::delay(1000);
  //   clawMech.set_value(true);

  // PIDchassis->stop();
  // fourbarLift(150);
  // PIDchassisGoal->moveDistance(-2.25_ft);


  // //grab alliance
  // turn(269);
  // twobarDown();
  // pros::delay(900);
  // move(med, 0.8_ft, bwd);
  // twobarUp();
  // pros::delay(950);


  // // scoring preloads
  // fourbarLift(2000);
  // intakeMotor.moveVelocity(-500);
  // pros::delay(950);
  // intakeMotor.moveVelocity(0);
  // turn(0);


  // //getting row of rings
  // med->generatePath({
  //   {0_ft,0_ft, 0_deg},
  //   {3_ft, 0_ft, 0_deg}},
  //   "rightRings"
  // );
  // med->setTarget("rightRings", fwd);

  //   intakeMotor.moveVelocity(-600);

  // med->waitUntilSettled();
  // intakeMotor.moveVelocity(0);

  // move(fast, 4.6_ft, bwd);
  // intakeMotor.moveVelocity(-600);
  // fourbarLift(0);
}



void winPoint(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

  // fourbarLift(1050);
  // move(fast, 0.3_ft, fwd);
  // pros::delay(200);
  // clawMech.set_value(false);
  // pros::delay(600);
  // move(fast, 0.8_ft, bwd);

  // turn(315);
  // move(fast, 2.15_ft, fwd);

  // turn(182);

  // fast->generatePath({
  //   {0_ft,0_ft,0_deg},
  //   {12.4_ft, 0_ft,0_deg}},
  //   "acrossField"
  // );

  // fast->setTarget("acrossField", bwd);

  // pros::delay(400);
  // twobarDown();

  // fast->waitUntilSettled();
  // pros::delay(500);
  // twobarUp();
  // pros::delay(700);
  // intakeMotor.moveVelocity(-600);
  // pros::delay(2000);
  // intakeMotor.moveVelocity(0);
  // move(fast, 2_ft, fwd);
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
