#ifndef TASKMANAGER_HPP
#define TASKMANAGER_HPP

#include "main.h"

// Main
extern void startTasks();
extern void stopTasks();

extern bool flyDone();
extern bool driveDone();
extern bool inDone();

extern void autonWait(float timeout = 10000);
extern void moveWait(float timeout = 10000);

// Expansion
extern void setExpansionLock(bool state);

// Flywheel
extern void setFlywheelTarget(int target);
extern void setFlywheelState(bool state);
extern void setFlywheelInterpolation(bool state);

// Intake
extern void setInSpeed(float n);
extern void index(int n);

// Drive
extern void linearMove(float disp, float speed = 1.0);
extern void turn(float degrees);
extern void moveNTurn(float disp, float endAngle, float speed = 1.0);

// Odometry N/A

#endif