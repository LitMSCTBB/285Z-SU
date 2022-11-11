#include "../../include/285Z_Subsystems/flywheel.hpp"
#include "../../include/285z/functions.hpp"
#include "../../include/285z/initRobot.hpp"
#include "../../include/285z/initSensors.hpp"
#include "pros/rtos.h"
#include "pros/rtos.hpp"

bool fastSpinning = false;
bool slowSpinning = false;

// void Flywheel::pid() {
  
// }

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