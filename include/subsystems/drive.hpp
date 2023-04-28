#pragma once
#include "../init/initRobot.hpp"
#include "main.h"

class Drive {
  public:
    void run();
    void override();
    bool done();
    void moveLinear(float disp, float speed);
    void IMUTurn(float degrees);
    void moveTurn(float disp, float endAngle, float speed);
};

extern Drive d;