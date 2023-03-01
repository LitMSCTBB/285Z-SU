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

const double FLYWHEEL_kP = 2.0;
const double FLYWHEEL_kI = 0.01;
const double FLYWHEEL_kD = 0;
const double kF = 20; // feed forward
const double BANG_BANG = 150;
double target = 400; // real target rpm is 400 * 6 = 2400
double error, oldError, sumError;
bool spinning = false;
int dc = 0;

// int flyVoltage = 7000;

double mem_pid = 0;

float Flywheel::pid() {
  double sensorValue = flywheelMotor.getActualVelocity();
  double speedTarget = target;
  error = speedTarget - sensorValue;

  if (abs(error) >= 60)
    return (BANG_BANG * error > 12000) ? 12000 : BANG_BANG * error;
  if (abs(error) >= 3) {
    // PROPORTIONAL

    // DERIVATIVE
    double changeInError = error - oldError;
    // INTEGRAL
    if (abs(error) < 100) {
      sumError += error;
    } else {
      sumError = 0;
    }

    // P, I, D
    double P = FLYWHEEL_kP * error;
    double I = FLYWHEEL_kI * sumError;
    double D = FLYWHEEL_kD * changeInError;

    double sum = P + I + D + kF * target;

    oldError = error;
    dc++;

    sum = (sum > 12000) ? 12000 : sum;
    mem_pid = sum;
    return sum;
  }
  return mem_pid;
}

bool ba = false;
void Flywheel::blooperToggle() {
  if (blooperButton.changedToPressed()) {
    ba = !ba;
    target = spinning ? (ba ? 375 : 400) : 0;
    // flyVoltage = (ba) ? 6000 : 7000;
  }
  blooper.set_value(ba);
}

void Flywheel::spin() {
  if (flywheelButton.changedToPressed()) {
    spinning = !spinning;
  }
  if (spinning) {
    float val = pid();
    if (val != 0)
      flywheelMotor.moveVoltage(val);
    dc++;
    if (dc % 5 == 0)
      printf("(%f,%f)\n", (double)dc / 5, flywheelMotor.getActualVelocity());
    // flywheelMotor.moveVoltage(flyVoltage);
  } else {
    flywheelMotor.moveVoltage(0);
  }
}

bool shooterRunning = false;
void Flywheel::shooter() {
  if (indexerButton.changedToPressed()) {
    pros::Task{[=] {
      if (!shooterRunning) {
        shooterRunning = true;
        indexer.set_value(true);
        pros::delay(150);
        indexer.set_value(false);
        pros::delay(100);
        shooterRunning = false;
      }
    }};
  }
}
