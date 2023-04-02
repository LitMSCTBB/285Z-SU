#include "../include/285Z_Subsystems/pid.hpp"
#include "../include/285z/functions.hpp"
#include "../include/285z/initRobot.hpp"
#include "../include/285z/initSensors.hpp"
#include "pros/rtos.hpp"

//****************** SKILLS ***********************************//

void noAuton(std::shared_ptr<okapi::AsyncMotionProfileController> med,
             std::shared_ptr<okapi::AsyncMotionProfileController> fast) {

  // pros::delay(15000); 
  // driveL.moveRelative(-600, 600);
  // driveR.moveRelative(-600, 600);
  // pros::delay(2000);
  // moveDrive(-1, false);
  leftHigh(med, fast);
}

void skillsAuto(std::shared_ptr<okapi::AsyncMotionProfileController> med,
                std::shared_ptr<okapi::AsyncMotionProfileController> fast) {
  imuSensor.reset();
  // moveDrive(30);
  // pros::delay(350);
  move(med, 0.5_ft, bwd);
  // autoSpin(-180);
  // moveDrive(-30);
  intakeMotor.moveVoltage(12000);
  pros::delay(500);
  intakeMotor.moveVoltage(0);
  move(med, 1_ft, fwd);
  turn(80);
  move(med, 1.5_ft, bwd);
  intakeMotor.moveVoltage(12000);
  pros::delay(9000);
  intakeMotor.moveVoltage(0);
  move(med, 1_ft, fwd);
  turn(50);
  move(med, 1_ft, bwd);
  for (int i = 0; i < 3; i++) {
    eg.set_value(true);
    pros::delay(500);
    eg.set_value(false);
    pros::delay(500);
  }
  eg.set_value(true);
  // eg.set_value(true);
  // pros::delay(500);
  // eg.set_value(false);
  // pros::delay(500);
  // eg.set_value(true);
  // pros::delay(500);
  // eg.set_value(false);
  // pros::delay(500);
  // eg.set_value(true);
  // pros::delay(500);
}
