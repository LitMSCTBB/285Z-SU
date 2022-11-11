#pragma once
#include "../285z/initRobot.hpp"
#include "main.h"

class Intake {

public:
  void run();
  void stop();
};

extern Intake in;