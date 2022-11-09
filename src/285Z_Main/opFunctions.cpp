#include "../include/285z/functions.hpp"
#include "../include/285z/initRobot.hpp"
#include "../include/285z/initSensors.hpp"
#include "285Z_Subsystems/flywheel.hpp"

int endCount = 0;
void endgame() {
  endgameMotor.setBrakeMode(AbstractMotor::brakeMode::hold);
  if (endgameButton.isPressed()) {
    endCount++;
  }
  if (endCount == 4) {
    endgameMotor.moveRelative(-90, 600);
  }
}

// void roller() {
//   if (!shooterRunning) {
//     if (rollerButton.isPressed()) {
//       intakeMotor.move
//     }
//   }
  
// }

bool autSpinning = false;
void autoSpin() {
  autSpinning = !autSpinning;
  if (autSpinning) {
    flywheelMotor.moveVelocity(3600);
  } else {
    flywheelMotor.moveVelocity(0);
  }
}

void autoShoot() {
  intakeMotor.moveVelocity(-600);
  indexerMotor.moveRelative(120, 150);
  pros::delay(1500);
  indexerMotor.moveRelative(120, 150);
  pros::delay(1500);
  indexerMotor.moveRelative(120, 150);
  pros::delay(1500);
  indexerMotor.moveRelative(120, 150);
  pros::delay(1500);
  intakeMotor.moveVelocity(0);
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
