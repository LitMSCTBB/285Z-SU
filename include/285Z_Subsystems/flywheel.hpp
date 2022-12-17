#pragma once
#include "../285z/initRobot.hpp"
#include "main.h"

class Flywheel {

public:
  void spin();
  void shooter();
  void pid();
  void pistonOnce();
};

extern bool shooterRunning;
extern double target;

extern Flywheel fw;