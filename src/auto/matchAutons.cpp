#include "../include/subsystems/flywheel.hpp"
#include "../include/init/functions.hpp"
#include "../include/init/initRobot.hpp"
#include "../include/init/initSensors.hpp"
#include "main.h"

void noAuton() {
  // linearMove(5);
  // autonWait();
  // linearMove(-5);
  // autonWait();
  // linearMove(10);
  // autonWait();
  // linearMove(-10);
  // autonWait();
  // linearMove(15);
  // autonWait();
  // linearMove(-15);
  // autonWait();
  // linearMove(20);
  // autonWait();
  // linearMove(-20);
  // autonWait();
  // linearMove(25);
  // autonWait();
  // linearMove(-25);
  // autonWait();
  // linearMove(30);
  // autonWait();
  linearMove(-6);
  autonWait();
  turn(-90);
  // autonWait();
  // turn(0);
  // autonWait();
  // turn(-75);
  // autonWait();
  // turn(0);
  // autonWait();
  // turn(-60);
  // autonWait();
  // turn(0);
  // autonWait();
  // turn(-45);
  // autonWait();
  // turn(0);
  // autonWait();
  // turn(-30);
  // autonWait();
  // turn(0);
  // autonWait();
  // turn(-15);
  // autonWait();
  // turn(0);
  // autonWait();
  // turn(15);
  // autonWait();
  // turn(0);
  // autonWait();
  // turn(30);
  // autonWait();
  // turn(0);
  // autonWait();
  // turn(45);
  // autonWait();
  // turn(0);
  // autonWait();
  // turn(60);
  // autonWait();
  // turn(0);
  // autonWait();
  // turn(75);
  // autonWait();
  // turn(0);
  // autonWait();
  // turn(90);
  // autonWait();
  // turn(0);
  // autonWait();
}

void fullWP() {
  setFlywheelTarget(2250);
  pistonIntake.set_value(true);
  linearMove(-3);
  moveWait(250);

  setInSpeed(600);
  pros::delay(225);
  setInSpeed(0);

  moveNTurn(3, 350);
  autonWait();

  index(2);
  autonWait();

  setFlywheelTarget(2125);
  turn(45);
  moveWait();

  linearMove(21.5);
  moveWait();

  setInSpeed(600);
  pistonIntake.set_value(false);
  pros::delay(1625);

  turn(341);
  autonWait();

  index(3);
  autonWait();

  turn(45);
  moveWait();

  setInSpeed(600);
  moveNTurn(109, 270, 0.90);
  moveWait();

  // index(3);
  // autonWait();

  // turn(230);
  // moveWait();

  // moveNTurn(-24, 270);
  // moveWait();

  linearMove(-6);
  moveWait(750);

  setInSpeed(600);
  pros::delay(140);
  setInSpeed(0);
}

void rightSideHighGoal() {
  // Make sure initial position is good
  turn(0);
  autonWait(15);

  // Initial turn and spin up
  setFlywheelTarget(2040);
  pistonIntake.set_value(true);
  turn(19.5);
  moveWait();

  // Move to shoot preloads
  linearMove(22);
  autonWait();

  // Shoot preloads
  index(2);
  autonWait();

  // Move backwadriveRs for 3-stack
  setFlywheelTarget(2075);
  linearMove(-7);
  moveWait();

  // Turn to face 3-stack
  turn(61);
  setInSpeed(600);
  moveWait();

  // Move to 3-stack
  linearMove(4.5);
  moveWait();

  // Intake 3-stack
  pistonIntake.set_value(false);
  pros::delay(1700);

  // Move to shoot 3-stack
  moveNTurn(-2, 16);
  // pros::delay(700);
  autonWait();

  // Shoot 3-stack
  index(3);
  autonWait();

  driveL.setBrakeMode(AbstractMotor::brakeMode::hold);
  driveR.setBrakeMode(AbstractMotor::brakeMode::hold);

  driveL.moveVoltage(-12000);
  driveR.moveVoltage(-1000);
  pros::delay(500);

  driveL.moveVoltage(-2000);
  driveR.moveVoltage(-12000);
  pros::delay(425);

  driveL.moveVoltage(0);
  driveR.moveVoltage(0);

  // Run roller + increase flywheel speed for midfiedriveL shot
  setFlywheelTarget(2030);
  setInSpeed(600);
  pros::delay(225);

  // Stop running rollers + turn to line
  setInSpeed(0);
  driveR.moveVoltage(12000);
  pros::delay(225);

  driveL.setBrakeMode(AbstractMotor::brakeMode::coast);
  driveR.setBrakeMode(AbstractMotor::brakeMode::coast);

  // Turn for line of 3
  turn(317);
  moveWait();

  // Intake line of 3 + move to shoot
  moveNTurn(58, 42.5, 0.7);
  setInSpeed(600);
  autonWait();

  // Shoot line of 3
  index(3);
  autonWait();

  //

  // turn(0);
  // autonWait(25);

  // setFlywheelTarget(2400);
  // turn(16.5);
  // autonWait();

  // index(2, 500);
  // autonWait();

  // turn(42.5);
  // autonWait();

  // setFlywheelTarget(2200);
  // pistonIntake.set_value(true);
  // setInSpeed(600);

  // linearMove(19.75);
  // autonWait();

  // pistonIntake.set_value(false);
  // pros::delay(1250);

  // moveNTurn(-2, 14.5);
  // autonWait();

  // index(3, 500);
  // autonWait();

  // moveNTurn(-7, 316);
  // autonWait();

  // setInSpeed(600);
  // linearMove(52.5, 0.8);
  // autonWait();
  // // pros::delay(1000);

  // setFlywheelTarget(2000);
  // turn(44);
  // autonWait();

  // index(3, 500);
  // autonWait();

  // turn(312);
  // autonWait();

  // linearMove(-64, 0.9);
  // autonWait();

  // turn(0);
  // autonWait();

  // linearMove(-5.3);
  // autonWait(500);

  // setInSpeed(600);
  // pros::delay(200);
  // setInSpeed(0);
  // linearMove(4);
  // autonWait();
}

void leftSideHighGoal() {
  setFlywheelTarget(2125);
  pistonIntake.set_value(true);
  turn(350);
  moveWait();

  linearMove(9.5);
  autonWait();

  index(2);
  autonWait();

  setFlywheelTarget(2075);
  setInSpeed(600);
  pistonIntake.set_value(false);
  pros::delay(1750);

  index(3);
  autonWait();

  turn(0);
  moveWait();

  linearMove(-16);
  moveWait(1500);

  setInSpeed(600);
  pros::delay(100);
  setInSpeed(0);

  setFlywheelTarget(2050);
  pistonIntake.set_value(true);
  moveNTurn(5, 48);
  moveWait();

  linearMove(18);
  moveWait();

  setInSpeed(600);
  pistonIntake.set_value(false);
  pros::delay(1625);

  turn(343);
  moveWait();

  linearMove(7);
  autonWait();

  index(3);
  autonWait();

  // turn(0);
  // autonWait(25);

  // setFlywheelTarget(2470);
  // linearMove(-3);
  // moveWait(250);

  // setInSpeed(600);
  // pros::delay(100);

  // moveNTurn(3, 319);
  // moveWait();

  // linearMove(5);
  // moveWait();

  // pros::delay(800);
  // setInSpeed(0);

  // turn(355);
  // autonWait();

  // pistonIntake.set_value(true);
  // index(3);

  // setFlywheelTarget(2300);
  // turn(270);
  // moveWait();

  // moveNTurn(-19, 329.5);
  // moveWait();

  // linearMove(12.5);
  // setInSpeed(600);
  // moveWait();

  // pistonIntake.set_value(false);
  // pros::delay(1300);

  // moveNTurn(-4, 347.5);
  // autonWait();

  // index(3);

  // pistonIntake.set_value(true);
  // turn(45);
  // moveWait();

  // setInSpeed(600);
  // linearMove(11.5);
  // moveWait();

  // pistonIntake.set_value(false);
  // pros::delay(1300);

  // turn(338);
  // moveWait();

  // index(3);
}

void rightSideRush() {}