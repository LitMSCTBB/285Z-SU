#include "../../include/285Z_Subsystems/flywheel.hpp"
#include "../../include/285z/functions.hpp"
#include "../../include/285z/initRobot.hpp"
#include "../../include/285z/initSensors.hpp"
#include "flywheel.hpp"
#include "pros/rtos.h"
#include "pros/rtos.hpp"

bool fastSpinning = false;
bool slowSpinning = false;

const double FLYWHEEL_kP = 3.5;
const double FLYWHEEL_kI = 0.0;
const double FLYWHEEL_kD = 0.0;

void Flywheel::pid(int vel) {
  double vI = flywheelMotor.getActualVelocity();

  double vF = vel;

  printf("%f %f", vI, vF);

  double sensorValue = vI;
  double speedTarget = vF;

  double deltaV = abs(vF - vI);

  double error = speedTarget - sensorValue;
  double oldError = error;
  double sumError = 0;

  bool ACCEL_NOT_FINISH = true;
  while (ACCEL_NOT_FINISH) {
    sensorValue = flywheelMotor.getActualVelocity();

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

    double sum = P + I + D;

    driveL.moveVelocity(sum);
    driveR.moveVelocity(-sum);

    oldError = error;
    double errorThreshold = 1.5;
    double velocityThreshold = 2;

    ACCEL_NOT_FINISH = !((abs(error) < errorThreshold) &&
                        (abs(changeInError) < velocityThreshold));
  }
  driveL.moveVoltage(0);
  driveR.moveVoltage(0);
}

void Flywheel::spin() {
  if (flywheelFastButton.changedToPressed()) {
    fastSpinning = !fastSpinning;
  } else if (flywheelSlowButton.changedToPressed()) {
    slowSpinning = !slowSpinning;
  }
  if (fastSpinning) {
    flywheelMotor.moveVelocity(2500);
  } else if (slowSpinning) {
    flywheelMotor.moveVelocity(1600);
  } else {
    flywheelMotor.moveVelocity(0);
  }
  printf("%f\n", flywheelMotor.getActualVelocity());
}

bool shooterRunning = false;

void shooterProc(void* param) {
  // std::lock_guard<pros::Mutex> guard(mutex);

}

void Flywheel::shooter() {
  intakeMotor.setBrakeMode(AbstractMotor::brakeMode::hold);

  if (indexerButton.isPressed()) {
    if (!shooterRunning) {
      shooterRunning = true;
      intakeMotor.moveVelocity(-400);
      indexer.set_value(false);
      indexer.set_value(true);
      indexer.set_value(false);
      indexer.set_value(true);
      indexer.set_value(false);
      indexer.set_value(true);
      shooterRunning = false;
    }
  }
}