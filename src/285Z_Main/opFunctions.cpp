#include "../include/285z/functions.hpp"
#include "../include/285z/initRobot.hpp"
#include "../include/285z/initSensors.hpp"

int endCount = 0;
void endgame() {
  if (endgameButton.isPressed()) {
    endCount++;
  }
  if (endCount == 4) {
    endgameMotor.moveRelative(10, 100);
  }
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
