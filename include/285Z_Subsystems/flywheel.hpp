#pragma once
#include "../285z/initRobot.hpp"
#include "main.h"

class Flywheel {

public:
  void spin();
  void shooter();
};

extern Flywheel fw;