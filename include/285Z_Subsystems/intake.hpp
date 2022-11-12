#pragma once
#include "../285z/initRobot.hpp"
#include "main.h"

class Intake {

public:
  void run();
  void stop();
};

extern bool running;
extern bool reverse;

extern Intake in;