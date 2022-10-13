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
  indexerMotor.setBrakeMode(AbstractMotor::brakeMode::hold);

  // if (indexerButton.isPressed()) {
  //   indexerMotor.moveVelocity(120);
  //   pros::delay(1200);
  // }
  if (indexerButton.isPressed()) {
    indexerMotor.moveRelative(120, 150);
    intakeMotor.moveRelative(-(600.0 / 60) * 1.5 * 360, 600);
    // intakeMotor.moveVoltage(-12000);
    // pros::delay(1500);
    // intakeMotor.moveVelocity(0);
    // async controller or something
  }
}