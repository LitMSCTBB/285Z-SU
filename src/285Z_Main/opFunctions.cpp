#include "../include/285z/functions.hpp"
#include "../include/285z/initRobot.hpp"
#include "../include/285z/initSensors.hpp"
#include "285Z_Subsystems/flywheel.hpp"
#include "pros/rtos.hpp"

int endCount = 0;
void endgame() {
  if (endgameButton.changedToPressed()) {
    endCount++;
    if (endCount == 2) {
      for (int i=0; i<8; i++) {
        eg.set_value(true);
        pros::delay(500);
        eg.set_value(false);
        pros::delay(500);
      }
      eg.set_value(true);
    }
  }
}

// void roller() {
//   if (!shooterRunning) {
//     if (rollerButton.isPressed()) {
//       intakeMotor.moveVelocity(400);
//     }
//   }
// }

bool autSpinning = false;
void autoSpin() {
  autSpinning = !autSpinning;
  if (autSpinning) {
    flywheelMotor.moveVelocity(400);
  } else {
    flywheelMotor.moveVelocity(0);
  }
}

void autoShoot() {
  intakeMotor.moveVelocity(-400);
  indexer.set_value(false);
  indexer.set_value(true);
  indexer.set_value(false);
  indexer.set_value(true);
  indexer.set_value(false);
  indexer.set_value(true);
}

void move(std::shared_ptr<okapi::AsyncMotionProfileController> profile,
  okapi::QLength distance,
  bool dir)
{
  profile->generatePath({
    {0_ft,0_ft,0_deg},
    {distance, 0_ft,0_deg}},
    "M"
  );

  profile->setTarget("M", dir);
  profile->waitUntilSettled();
  profile->removePath("M");
}
