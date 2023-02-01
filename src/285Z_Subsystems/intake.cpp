#include "../../include/285Z_Subsystems/intake.hpp"
#include "../../include/285Z_Subsystems/flywheel.hpp"
#include "../../include/285z/functions.hpp"
#include "../../include/285z/initRobot.hpp"
#include "../../include/285z/initSensors.hpp"
#include "pros/llemu.hpp"

bool running = false;
bool reverse = false;

void Intake::run() {
  if (!shooterRunning) {
    if (intakeButton.changedToPressed()) {
      running = !running;
    }
    if (outtakeButton.changedToPressed()) {
      reverse = !reverse;
      if (reverse && running)
        running = false;
    }
    if (running) {
      intakeMotor.moveVoltage(12000);
    } else if (reverse) {
      intakeMotor.moveVoltage(-12000);
    } else {
      intakeMotor.moveVoltage(0);
    }
  }
}

void Intake::stop() {
  if (intakeStopButton.changedToPressed()) {
    intakeMotor.moveVoltage(0);
  }
}