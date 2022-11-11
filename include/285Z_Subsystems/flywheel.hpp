#pragma once
#include "../285z/initRobot.hpp"
#include "main.h"

class Flywheel {

public:
  void spin();
  void shooter();
  void pid(int vel);
};

extern bool shooterRunning;

extern Flywheel fw;