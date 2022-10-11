#include "../../include/285Z_Subsystems/flywheel.hpp"
#include "../../include/285z/functions.hpp"
#include "../../include/285z/initRobot.hpp"
#include "../../include/285z/initSensors.hpp"

bool spinning = false;

void Flywheel::spin() {
  if (flywheelButton.changedToPressed()) {
    spinning = !spinning;
  }
  if (spinning) {
    flywheelMotor.moveVoltage(12000);
  } else {
    flywheelMotor.moveVoltage(0);
  }
}

void Flywheel::shooter() {
  // if (indexerButton.isPressed()) {
  //   indexerMotor.moveVelocity(120);
  //   pros::delay(1200);
  // }
  if (indexerButton.isPressed()) {
    indexerMotor.moveRelative(360, 150);
    // intakeMotor.moveVelocity(-600);
    // async controller or somemthing
  }
}