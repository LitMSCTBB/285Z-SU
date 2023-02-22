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

const double FLYWHEEL_kP = 175;
const double FLYWHEEL_kI = 1;
const double FLYWHEEL_kD = -60;
const double BANG_BANG = 150;
double target = 300; // real target rpm is 300 * 6 = 1800
double error, oldError, sumError;
bool spinning = false;
int dc = 0;

float Flywheel::pid() {
  double sensorValue = flywheelMotor.getActualVelocity();
  double speedTarget = target;
  error = speedTarget - sensorValue;

  if (abs(error) >= 80)
    return (BANG_BANG * error > 600) ? 600 : BANG_BANG * error;
  if (abs(error) >= 10) {
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

    double sum = P + I + D;

    oldError = error;
    dc++;

    return ((sum > 600) ? 600 : sum);
  }
  return sensorValue;
}

void Flywheel::spin() {
  if (flywheelButton.changedToPressed()) {
    spinning = !spinning;
  }
  if (spinning) {
    // float val = pid();
    // if (val != 0)
    //   flywheelMotor.moveVelocity(val);
    // dc++;
    // if (dc % 5 == 0)
    //   // printf("%f %f \n", val, flywheelMotor.getActualVelocity());
    //   printf("(%f,%f)\n", (double)dc / 5, flywheelMotor.getActualVelocity());
    // flywheelMotor.moveVelocity(200);
    flywheelMotor.moveVelocity(250);
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
        pros::delay(300);
        indexer.set_value(false);
        pros::delay(150);
        shooterRunning = false;
      }
    }};
  }
}
