#pragma once
#include "../init/initRobot.hpp"
#include "main.h"

class Intake {
  public:
    void run();
    void stop();
    void index(int n);
    void setState(float n);
    bool done();
};

extern bool running;
extern bool reverse;
extern bool motorActive;

extern Intake in;