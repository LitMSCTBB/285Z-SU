#include "../../include/init/functions.hpp"
#include "../../include/init/initRobot.hpp"
#include "../../include/init/initSensors.hpp"
#include "../../include/subsystems/flywheel.hpp"

std::atomic<int> bState = 0;

void Blooper::run() {
  if (blooperButton.changedToPressed())
    bState = ((bState != 1) ? 1 : -1);
  blooper.set_value((bState == 1) ? true : false);
}

void Blooper::setState(int state) { bState = state; }