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
  mutex.take();
  shooterRunning = true;
  intakeMotor.moveVoltage(-12000);
  indexerMotor.moveRelative(120, 150);
  pros::delay(1500);
  indexerMotor.moveRelative(120, 150);
  pros::delay(1500);
  indexerMotor.moveRelative(120, 150);
  pros::delay(1500);
  intakeMotor.moveVoltage(0);
  shooterRunning = false;
  mutex.give();
}

void Flywheel::shooter() {
  indexerMotor.setBrakeMode(AbstractMotor::brakeMode::hold);

  // if (indexerButton.isPressed()) {
  //   indexerMotor.moveVelocity(120);
  //   pros::delay(1200);
  // }
  if (indexerButton.isPressed()) {
    if (!shooterRunning) {
      pros::Task sp(shooterProc);
    }

    // intakeMotor.moveVelocity(-600);
    // indexerMotor.moveRelative(120, 150);
    // pros::delay(1500);
    // indexerMotor.moveRelative(120, 150);
    // pros::delay(1500);
    // indexerMotor.moveRelative(120, 150);
    // pros::delay(1500);
    // indexerMotor.moveRelative(120, 150);
    // pros::delay(1500);
    // intakeMotor.moveVelocity(0);

    // intakeMotor.moveVoltage(-12000);
    // pros::delay(1500);
    // intakeMotor.moveVelocity(0);
    // async controller or something
  }
}