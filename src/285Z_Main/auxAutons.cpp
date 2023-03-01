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

  flywheelMotor.moveVoltage(8000);
  // Move back to roller
  md(-8000, 250);

  // Roller
  pros::delay(100);
  intakeMotor.moveVoltage(12000);
  pros::delay(250);
  intakeMotor.moveVoltage(0);

  // Move forward from roller
  md(12000, 50);

  // Turn & intake
  turnd(-6000, 400);
  intakeMotor.moveVoltage(12000);
  md(12000, 300);
  pros::delay(750);
  intakeMotor.moveVoltage(0);

  // 2nd Roller

  md(10000, 250);
  pros::delay(50);
  turnd(6000, 875);
  pros::delay(50);
  md(-6000, 570);
  intakeMotor.moveVoltage(12000);
  pros::delay(300);
  intakeMotor.moveVoltage(0);

  // Move to Goal
  md(12000, 100);
  turnd(-6000, 425);
  // driveR.moveVoltage(6000);
  // pros::delay(850);
  // driveR.moveVoltage(0);
  md(12000, 800);

  // // Shoot 3 discs
  pros::delay(500);
  indexer.set_value(true);
  pros::delay(200);
  printf("%f\n", flywheelMotor.getActualVelocity());
  flywheelMotor.moveVoltage(9200);
  indexer.set_value(false);
  pros::delay(500);
  indexer.set_value(true);
  pros::delay(200);
  printf("%f\n", flywheelMotor.getActualVelocity());
  flywheelMotor.moveVoltage(9200);
  indexer.set_value(false);
  pros::delay(500);
  indexer.set_value(true);
  pros::delay(200);
  indexer.set_value(false);

  // intake disc 4,5,6
  intakeMotor.moveVoltage(12000);
  turnd(6000, 70);
  md(8000, 200);
  md(-8000, 200);
  turnd(6000, 70);
  md(8000, 200);
  md(-8000, 200);
  turnd(6000, 70);
  md(8000, 200);
  intakeMotor.moveVoltage(0);

  // shoot disc 4,5,6
  md(-5000, 100);
  turnd(-5000, 70);
  pros::delay(500);
  indexer.set_value(true);
  pros::delay(200);
  printf("%f\n", flywheelMotor.getActualVelocity());
  flywheelMotor.moveVoltage(9200);
  indexer.set_value(false);
  pros::delay(500);
  indexer.set_value(true);
  pros::delay(200);
  printf("%f\n", flywheelMotor.getActualVelocity());
  flywheelMotor.moveVoltage(9200);
  indexer.set_value(false);
  pros::delay(500);
  indexer.set_value(true);
  pros::delay(200);
  indexer.set_value(false);

  // intake disc 7,8,9
  intakeMotor.moveVoltage(12000);
  driveR.moveVelocity(-8000);
  pros::delay(300);
  md(-12000, 300);
  turnd(6000, 100);
  md(12000, 100);
  turnd(-6000, 100);
  md(10000, 800);
  intakeMotor.moveVoltage(0);

  // shoot disc 7,8,9
  turnd(-6000, 200);
  pros::delay(500);
  indexer.set_value(true);
  pros::delay(200);
  printf("%f\n", flywheelMotor.getActualVelocity());
  flywheelMotor.moveVoltage(9200);
  indexer.set_value(false);
  pros::delay(500);
  indexer.set_value(true);
  pros::delay(200);
  printf("%f\n", flywheelMotor.getActualVelocity());
  flywheelMotor.moveVoltage(9200);
  indexer.set_value(false);
  pros::delay(500);
  indexer.set_value(true);
  pros::delay(200);
  indexer.set_value(false);

  // go to 3rd roller
  turnd(-6000, 300);
  md(-12000, 700);
  intakeMotor.moveVoltage(12000);
  turnd(-6000, 150);
  md(-12000, 100);
  intakeMotor.moveVoltage(0);

  // go to the 4th roller
  md(12000, 1);
}
