#include "../../include/285Z_Subsystems/flywheel.hpp"
#include "../../include/285z/functions.hpp"
#include "../../include/285z/initRobot.hpp"
#include "../../include/285z/initSensors.hpp"
#include "flywheel.hpp"
#include "pid.hpp"
#include "pros/rtos.h"
#include "pros/rtos.hpp"
#include "sylib/motor.hpp"
#include <string>

// auto fwSyl = sylib::Motor(19, 3600);

const double FLYWHEEL_kP = 0.7;
const double FLYWHEEL_kI = 0;
const double FLYWHEEL_kD = 0;
const double kF = 3.3333;
double currVoltage = 0;
double target = 2000;
double error, oldError, sumError;
bool spinning = false;
int dc = 0;

void Flywheel::pid() {
  // double sensorValue = fwSyl.get_velocity();
  double sensorValue = flywheelMotor.getActualVelocity();
  double speedTarget = target;

  if (flywheelButton.changedToPressed())
    spinning = !spinning;

  printf("%.3f\n", flywheelMotor.getActualVelocity() * 6.0);
  // double sensorValue = 400;

  // PROPORTIONAL
  error = speedTarget - sensorValue;
  // DERIVATIVE
  double changeInError = error - oldError;
  // INTEGRAL
  if (abs(error) < 40) {
    sumError += error;
  } else {
    sumError = 0;
  }

  // P, I, D
  double P = FLYWHEEL_kP * error;
  double I = FLYWHEEL_kI * sumError;
  double D = FLYWHEEL_kD * changeInError;

  double sum = P;
  currVoltage = speedTarget * kF + P;
  flywheelMotor.moveVoltage((spinning) ? currVoltage : 0);

  oldError = error;
}

void Flywheel::spin() {
  if (flywheelButton.changedToPressed()) {
    spinning = !spinning;
    printf("AYYEEEEE WFG");
  }
  if (spinning) {
    // target = 2400;
    // // pros::Task {
    // //   [=] {
    // //     pid();
    // //   }
    // // };
    // dc++;

    flywheelMotor.moveVelocity(100);
  } else {
    target = 0;
    currVoltage = 0;
    flywheelMotor.moveVoltage(0);
  }
  if (dc % 50 == 0)
    printf("%s %f %f %d\n", spinning ? "true" : "false", (double)target,
           flywheelMotor.getActualVelocity(), dc);
}

bool shooterRunning = false;
void Flywheel::shooter() {
  if (indexerButton.changedToPressed()) {
    pros::Task{[=] {
      if (!shooterRunning) {
        shooterRunning = true;
        indexer.set_value(false);
        // pros::delay(350);
        // indexer.set_value(true);
        // pros::delay(50);
        // shooterRunning = false;
      } else if (shooterRunning) {
        shooterRunning = false;
        indexer.set_value(true);
      }
    }};
  }
}

bool actuated = false;
void Flywheel::pistonOnce() {
  if (pistonOnceButton.changedToPressed()) {
    actuated = !actuated;
    indexer.set_value(actuated);
  }
}