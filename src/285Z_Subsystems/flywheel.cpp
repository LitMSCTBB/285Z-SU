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
    flywheelFrontMotor.moveVoltage(12000);
    flywheelBackMotor.moveVoltage(12000);
  } else {
    flywheelFrontMotor.moveVoltage(0);
    flywheelBackMotor.moveVoltage(0);
  }
}