#include "../include/init/initRobot.hpp"
#include "../include/subsystems/blooper.hpp"
#include "../include/subsystems/drive.hpp"
#include "../include/subsystems/expansion.hpp"
#include "../include/subsystems/flywheel.hpp"
#include "../include/subsystems/intake.hpp"
#include "main.h"

void noAuton();
void fullWP();
void rightSideHighGoal();
void leftSideHighGoal();
void rightSideRush();

void linearMove(float disp, float speed = 1.0);
void turn(float degrees);
void moveNTurn(float disp, float endAngle, float speed = 1.0);

bool flyDone();
bool driveDone();
bool inDone();

void autonWait(float timeout = 10000);

void moveWait(float timeout = 10000);

// Blooper
void setBlooper(bool state);

// Expansion
void setExpansionLock(bool state);
void releaseExpansion();

// Flywheel
void setFlywheelTarget(int target);
void setFlywheelState(bool state);

// Intake
void setInSpeed(float n);
void index(int n);