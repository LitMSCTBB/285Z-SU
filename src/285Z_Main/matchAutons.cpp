#include "../include/285Z_Subsystems/flywheel.hpp"
#include "../include/285Z_Subsystems/pid.hpp"
#include "../include/285z/functions.hpp"
#include "../include/285z/initRobot.hpp"
#include "../include/285z/initSensors.hpp"
#include "pros/rtos.hpp"

//***************************** RED/BLUE AUTONOMOUS PROGRAMS
//**********************************//
// Order: Left High, Right High, Full AWP

void leftHigh(std::shared_ptr<okapi::AsyncMotionProfileController> med,
              std::shared_ptr<okapi::AsyncMotionProfileController> fast) {
  flywheelMotor.moveVoltage(9500);

  // Back, roller, forward
  md(-12000, 180);
  pros::delay(100);
  intakeMotor.moveVoltage(12000);
  pros::delay(150);
  intakeMotor.moveVoltage(0);
  md(12000, 50);

  // Turn & intake
  turn(305);
  intakeMotor.moveVoltage(12000);
  md(12000, 200);
  pros::delay(600);
  intakeMotor.moveVoltage(0);

  // Backup from disk & turn
  driveL.moveRelative(-0.25 * 12 / (3.25 * pi) * 360 * 5 / 3, 300);
  driveR.moveRelative(-0.25 * 12 / (3.25 * pi) * 360 * 5 / 3, 300);
  pros::delay(600);
  turn(350);

  // Shoot 3 discs
  pros::delay(500);
  indexer.set_value(true);
  pros::delay(500);
  indexer.set_value(false);
  printf("%f\n", flywheelMotor.getActualVelocity());
  flywheelMotor.moveVoltage(9600);
  pros::delay(500);
  indexer.set_value(true);
  pros::delay(500);
  indexer.set_value(false);
  printf("%f\n", flywheelMotor.getActualVelocity());
  flywheelMotor.moveVoltage(9650);
  pros::delay(500);
  indexer.set_value(true);
  pros::delay(500);
  indexer.set_value(false);
  flywheelMotor.moveVoltage(7900);

  pros::delay(100);
  turnd(6000, 300);

  // moveDrive(1.4, false);
  md(3000, 650);
  intakeMotor.moveVoltage(0);
  pros::delay(100);

  // slowly intake three stack
  intakeMotor.moveVoltage(12000);
  md(6000, 1167);

  turn(315);

  // Shoot 3 discs
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

  intakeMotor.moveVoltage(0);

  autoSpin(0);
}

void rightHigh(std::shared_ptr<okapi::AsyncMotionProfileController> med,
               std::shared_ptr<okapi::AsyncMotionProfileController> fast) {
  // Turn on FW, intake disc, turn & drive to center
  // autoSpin(600);
  flywheelMotor.moveVoltage(8000);
  intakeMotor.moveVoltage(12000);
  md(12000, 300);
  pros::delay(500);
  turn(18);
  md(8000, 400);

  // autoSpin(424);
  pros::delay(2000);

  // Outtake (Jam Safety) then shoot 1st disc
  intakeMotor.moveVoltage(-12000);
  pros::delay(300);
  intakeMotor.moveVoltage(0);
  indexer.set_value(true);
  pros::delay(300);
  printf("%f\n", flywheelMotor.getActualVelocity());
  indexer.set_value(false);

  // Jerking off
  // driveL.moveVoltage(-12000);
  // driveR.moveVoltage(-12000);
  // pros::delay(100);
  // driveL.moveVoltage(0);
  // driveR.moveVoltage(0);
  // pros::delay(100);
  // driveL.moveVoltage(12000);
  // driveR.moveVoltage(12000);
  // pros::delay(100);
  // driveL.moveVoltage(0);
  // driveR.moveVoltage(0);

  flywheelMotor.moveVoltage(8100);
  pros::delay(600);
  indexer.set_value(true);
  pros::delay(300);
  printf("%f\n", flywheelMotor.getActualVelocity());
  indexer.set_value(false);
  flywheelMotor.moveVoltage(8100);
  pros::delay(1000);
  indexer.set_value(true);
  pros::delay(300);
  printf("%f\n", flywheelMotor.getActualVelocity());
  indexer.set_value(false);

  pros::delay(100);

  // Turn & backup to roller
  turn(320);
  driveL.moveVoltage(-12000);
  driveR.moveVoltage(-12000);
  pros::delay(450);
  driveL.moveVoltage(0);
  pros::delay(200);
  driveR.moveVoltage(0);
  pros::delay(100);

  // Roller
  intakeMotor.moveVoltage(12000);
  driveL.moveVoltage(-12000);
  driveR.moveVoltage(-12000);
  pros::delay(250);
  driveL.moveVoltage(0);
  driveR.moveVoltage(0);

  pros::delay(200);
  intakeMotor.moveVoltage(0);
  // autoSpin(0);
  flywheelMotor.moveVoltage(0);
}

void winPoint(std::shared_ptr<okapi::AsyncMotionProfileController> med,
              std::shared_ptr<okapi::AsyncMotionProfileController> fast) {}

void leftLow(std::shared_ptr<okapi::AsyncMotionProfileController> med,
             std::shared_ptr<okapi::AsyncMotionProfileController> fast) {
  // autoSpin(90);
  // intakeMotor.moveVoltage(12000);
  // moveDrive(0.2, false);
  // pros::delay(200);
  // intakeMotor.moveVoltage(0);
  // pros::delay(500);

  // autoShoot();
  // autoSpin(90);

  // turn(-340);
  // moveDrive(-0.2, false);
  // turn(20);
  // moveDrive(-0.2, false);

  // intakeMotor.moveVoltage(12000);
  // pros::delay(200);
  // intakeMotor.moveVoltage(0);
}

void rightLow(std::shared_ptr<okapi::AsyncMotionProfileController> med,
              std::shared_ptr<okapi::AsyncMotionProfileController> fast) {
  // autoSpin(75);
  // pros::delay(2000);
  // autoShoot();
  // autoSpin(75);

  // move(fast, -1.5_ft, bwd);
  // turn(90);
  // pros::delay(1000);
  // move(fast, -.000000001_ft, bwd);
  // intakeMotor.moveVoltage(12000);
  // pros::delay(200);
  // intakeMotor.moveVoltage(0);
}