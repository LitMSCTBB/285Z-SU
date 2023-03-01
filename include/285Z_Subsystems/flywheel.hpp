#pragma once
#include "../285z/initRobot.hpp"
#include "main.h"

class Flywheel {

public:
  void spin();
  void blooperToggle();
  void shooter();
  float pid();
  void pistonOnce();
};

extern bool shooterRunning;
extern double target;

extern Flywheel fw;