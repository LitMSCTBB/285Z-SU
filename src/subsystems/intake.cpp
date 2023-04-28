#include "../../include/subsystems/intake.hpp"
#include "../../include/init/functions.hpp"
#include "../../include/init/initRobot.hpp"
#include "../../include/init/initSensors.hpp"
#include "../../include/subsystems/flywheel.hpp"
#include "../../include/init/initRobot.hpp"


float intakeB = 0;
// bool changed = false,
int indexN = 0;

void Intake::run() {
  if (intakeButton.changedToPressed()) {
    intakeB = (intakeB != 1) ? 1 : 0;
  } else if (intakeInButton.changedToPressed()) {
    intakeB = 1;
  } else if (intakeOutButton.changedToPressed()) {
    intakeB = -1;
  } else if (intakeInButton.changedToReleased() || intakeOutButton.changedToReleased()) {
    intakeB = 0;
  }

  if (indexN != 0) {
    while (indexN > 0) {
      intakeMotor.moveVoltage(-12000);
      pros::delay((indexN == 1) ? 250 : 145);
      intakeMotor.moveVoltage(0);
      while (!fw.done())
        pros::delay(5);
      pros::delay(400);
      indexN--;
    }
  } else
    intakeMotor.moveVoltage((int)(intakeB * 12000));
}

void Intake::setState(float n) {
  intakeB = (n / 600.0);
  // indexing = false;
}

void Intake::index(int n) {
  if (!this->done())
    return;
  indexN = n;

  //     int numShots = n, time = 0;
  //     intakeB = -1;

  //     while (numShots > 0 && time < TIMEOUT * 1000) {
  //         intakeB = -1;
  //         if (indexerSwitch.get_value()) changed = true;
  //         if (!indexerSwitch.get_value() && changed) { numShots--; changed =
  //         false; } time += 10; pros::delay(10);
  //     }
  //     pros::delay(250);
  //     intakeB = 0;
  //     indexing = false;
}

bool Intake::done() { return indexN == 0; }
