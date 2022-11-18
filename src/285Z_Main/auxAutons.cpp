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
  move(med, 0.5_ft, bwd);
  intakeMotor.moveVoltage(12000);
  pros::delay(400);
  intakeMotor.moveVoltage(0);

  move(fast, 2_ft, fwd);
  turn(-45);
  move(fast, 2_ft, bwd);
  eg.set_value(true);
  pros::delay(500);
  eg.set_value(false);
  pros::delay(500);
  eg.set_value(true);
  pros::delay(500);
  eg.set_value(false);
  pros::delay(500);
  eg.set_value(true);
  pros::delay(500);
  pros::delay(15000);
}
