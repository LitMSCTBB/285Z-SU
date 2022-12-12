#include "../include/285z/functions.hpp"
#include "../include/285z/initRobot.hpp"
#include "../include/285z/initSensors.hpp"
#include "285Z_Subsystems/flywheel.hpp"
#include "okapi/api/util/mathUtil.hpp"
#include "pros/rtos.hpp"

int endCount = 0;
void endgame() {
  if (endgameButton.changedToPressed()) {
    endCount++;
    if (endCount == 2) {
      for (int i=0; i<3; i++) {
        eg.set_value(true);
        pros::delay(500);
        eg.set_value(false);
        pros::delay(500);
      }
      eg.set_value(true);
    }
  }
}

// amount is in feet
void moveDrive(double amount, bool fast) {
  double ab = abs(amount);
  double dir = amount / ab;
  int speed = 300;
  if (fast) speed = 600;
  driveL.moveRelative(dir * amount * 12 / (3.25 * pi) * 360 * 5 / 3, speed);
  driveR.moveRelative(dir * amount * 12 / (3.25 * pi) * 360 * 5 / 3, speed);
}

bool autSpinning = false;
void autoSpin(double speed) {
  autSpinning = !autSpinning;
  if (autSpinning) {
    flywheelMotor.moveVelocity(speed);
  } else {
    flywheelMotor.moveVelocity(0);
  }
}

void autoShoot() {
  intakeMotor.moveVoltage(-12000);
  indexer.set_value(false);
  pros::delay(500);
  indexer.set_value(true);
  pros::delay(2000);
  indexer.set_value(false);
  pros::delay(500);
  indexer.set_value(true);
  pros::delay(2000);
  intakeMotor.moveVoltage(0);
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
