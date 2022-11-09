#include "../include/285z/initRobot.hpp"
#include "../include/285z/functions.hpp"
#include "../include/285Z_Subsystems/pid.hpp"
#include "../include/285z/initSensors.hpp"

//****************** SKILLS ***********************************//

void noAuton()
{
  pros::delay(15000);

}

void skillsAuto(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast)
{

//   clawMech.set_value(0);


//   //alliance grab + score
//   move(med, 1.6_ft, fwd);
//   twobarDown();
//   turn(270);
//   // pros::delay(700);
//   move(med, 1.1_ft, bwd);
//   twobarUp();
//   pros::delay(900);
//   intakeMotor.moveVoltage(-12000);
//   pros::delay(1200);
//   intakeMotor.moveVoltage(0);


//   //grabbing neutral (side)
//   move(fast, 1.3_ft, fwd);
//   turn(0);
//   fast->generatePath({
//     {0_ft, 0_ft, 0_deg},
//     {4_ft, 0_ft, 0_deg}},
//     "first"
//     );

//   fast->setTarget("first", fwd);
//   clawMech.set_value(0);
//   pros::delay(1100);
//   clawMech.set_value(true);
//   fourbarLift(200);
//   fast->waitUntilSettled();
//   fourbarLift(2200);
//   turn(325);


//   //(side) neutral scoring on platform
//   fast->generatePath({
//     {0_ft, 0_ft, 0_deg},
//     {7.7_ft, 0_ft, 0_deg}},
//     "skillsPlat"
//     );

//   fast->setTarget("skillsPlat", fwd);
//   intakeMotor.moveVoltage(-12000);
//   pros::delay(1200);
//   intakeMotor.moveVoltage(0);
//   fast->waitUntilSettled();
//   intakeMotor.moveVoltage(-12000);
//   fourbarLift(1300);
//   pros::delay(500);
//   clawMech.set_value(false);
//   pros::delay(500);
//   fourbarLift(1900);
//   intakeMotor.moveVoltage(0);
//   move(fast, 2.3_ft, bwd);
//   turn(230);
//   twobarDown();
//   fourbarLift(0);
//   pros::delay(700);

//   //center neutral
//   move(fast, 1.5_ft, fwd);
//   clawMech.set_value(true);
//   fourbarLift(2200);
//   turn(180);
//   med->generatePath({
//     {0_ft, 0_ft, 0_deg},
//     {6_ft, 0_ft, 0_deg}},
//     "secondpath"
//     );

//   med->setTarget("secondpath", fwd);
//   intakeMotor.moveVoltage(-12000);
//   pros::delay(1200);
//   intakeMotor.moveVoltage(0);
//   med->waitUntilSettled();
//   intakeMotor.moveVoltage(-12000);
//   fourbarLift(1300);
//   pros::delay(900);
//   clawMech.set_value(false);
//   pros::delay(900);
//   move(med, 0.5_ft, bwd);
//   pros::delay(700);
//   fourbarLift(1900);
//   intakeMotor.moveVoltage(0);
//   twoBarController->setTarget(0);
//   move(med, 1.8_ft, bwd);

// //next side neutralSideLeft

//   turn(310);

//   fast->generatePath({
//     {0_ft, 0_ft, 0_deg},
//     {3.7_ft, 0_ft, 0_deg}},
//     "thirdPath"
//   );

//   fast->setTarget("thirdPath", fwd);
//   intakeMotor.moveVoltage(-12000);
//   fourbarLift(0);
//   pros::delay(1250);
//   clawMech.set_value(true);
//   fast->waitUntilSettled();
//   fourbarLift(200);
//   turn(0);
//   move(fast, 4.3_ft,fwd);
//   fourbarLift(0);
//   pros::delay(900);
//   clawMech.set_value(false); //set down neutral
//   pros::delay(900);
//   move(med, 0.5_ft, bwd);

//   //pick up another alliance goal
//   turn(90);
//   move(med, 1.1_ft, bwd);
//   twobarUp();
//   pros::delay(900);
//   move(fast, 1.3_ft, fwd);
//   turn(180);
//   move(fast, 6_ft, fwd);
//   intakeMotor.moveVoltage(0);

// /*
//   turn(215);
//   fourbarLift(0);
//   pros::delay(900);
//   move(med, 9_ft, fwd);
// */

}
