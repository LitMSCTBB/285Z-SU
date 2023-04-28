// #include "../include/init/functions.hpp"
#include "../include/init/initRobot.hpp"
#include "../include/init/initSensors.hpp"
#include "../include/subsystems/drive.hpp"
#include "../include/subsystems/flywheel.hpp"
#include "../include/subsystems/blooper.hpp"
#include "../include/subsystems/expansion.hpp"
#include "../include/subsystems/intake.hpp"
#include "main.h"

// Drive
void linearMove(float disp, float speed) { d.moveLinear(disp, speed); }
void turn(float degrees) { d.IMUTurn(degrees); }
void moveNTurn(float disp, float endAngle, float speed) {
  d.moveTurn(disp, endAngle, speed);
}

bool flyDone() { return fw.done(); }
bool driveDone() { return d.done(); }
bool inDone() { return in.done(); }

void autonWait(float timeout) {
  uint32_t start = pros::millis();
  while (!driveDone() || !flyDone() || !inDone()) {
    if ((pros::millis() - start) >= timeout) {
      d.override();
      break;
    }
    pros::delay(10);
  }
}

void moveWait(float timeout) {
  uint32_t start = pros::millis();
  while (!driveDone()) {
    if ((pros::millis() - start) >= timeout) {
      d.override();
      break;
    }
    pros::delay(10);
  }
}

// Blooper
void setBlooper(bool state) { b.setState(state); }

// Expansion
void setExpansionLock(bool state) { ex.setUnlocked(state); }
void releaseExpansion() { ex.release(); }

// Flywheel
void setFlywheelTarget(int target) { fw.setTarget(target); }
void setFlywheelState(bool state) { fw.setState(state); }

// Intake
void setInSpeed(float n) { in.setState(n); }
void index(int n) { in.index(n); }