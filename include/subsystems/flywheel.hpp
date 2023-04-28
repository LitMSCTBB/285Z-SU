#pragma once
#include "main.h"

class Flywheel {
  private:
    bool state;
    float target;
    void run();

  public:
    void setState(bool st);
    void setTarget(float tar);
    void auton();
    void op();
    bool done();
};

extern Flywheel fw;