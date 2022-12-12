#include "../../include/285Z_Subsystems/flywheel.hpp"
#include "../../include/285z/functions.hpp"
#include "../../include/285z/initRobot.hpp"
#include "../../include/285z/initSensors.hpp"
#include "flywheel.hpp"
#include "pid.hpp"
#include "pros/rtos.h"
#include "pros/rtos.hpp"
#include "sylib/motor.hpp"

bool spinning = false;
int dc = 0;

// auto fwSyl = sylib::Motor(19, 3600);

const double FLYWHEEL_kP = 0.7;
const double FLYWHEEL_kI = 0.07;
const double FLYWHEEL_kD = 0.55;
const double kF = 2;
double currVoltage = 0;
std::atomic<double> target;

void Flywheel::pid() {
  double error, oldError, sumError;
  while (true) {
    if (target.load() != 0) {
      double sensorValue = 400;
      // double sensorValue = fwSyl.get_velocity();
      double speedTarget = target.load();

      if (dc % 50 == 0) printf("%f %f\n", sensorValue, speedTarget);

      double error = speedTarget - sensorValue;
      double oldError = error;
      double sumError = 0;
      while (abs(error) >= 30) {
        // PROPORTIONAL
        error = speedTarget - sensorValue;
        // DERIVATIVE
        double changeInError = error - oldError;
        // INTEGRAL
        if (abs(error) < 50) {
          sumError += error;
        } else {
          sumError = 0; // might be += 0?
        }

        // P, I, D
        double P = FLYWHEEL_kP * error;
        double I = FLYWHEEL_kI * sumError;
        double D = FLYWHEEL_kD * changeInError;

        double sum = P;
        currVoltage = speedTarget * kF + P;
        // if (dc % 5 == 0) printf("%f\n", sum);
        flywheelMotor.moveVoltage(currVoltage);

        oldError = error;
      }      
    }
  }
}

void Flywheel::spin() {
  if (flywheelButton.changedToPressed()) {
    spinning = !spinning;
  }
  if (spinning) {
    // target.store(3600);
    flywheelMotor.moveVelocity(93);
    dc++;
  } else {
    // target.store(0);
    currVoltage = 0;
    flywheelMotor.moveVoltage(0);
  }
  // if (dc % 50 == 0) printf("%f %f %f %d\n", target.load(), flywheelMotor.getActualVelocity(), fwSyl.get_velocity(), dc);
}

bool shooterRunning = false;
void Flywheel::shooter() {
  if (indexerButton.changedToPressed()) {
    pros::Task {
      [=] {
        if (!shooterRunning) {
          shooterRunning = true;
          indexer.set_value(false);
          pros::delay(350);
          indexer.set_value(true);
          pros::delay(50);
          shooterRunning = false;
        }
      }
    };
  }
}

bool actuated = false;
void Flywheel::pistonOnce() {
  if (pistonOnceButton.changedToPressed()) {
    actuated = !actuated;
    indexer.set_value(actuated);
  }
}