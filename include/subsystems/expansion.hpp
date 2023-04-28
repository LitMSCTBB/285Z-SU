#pragma once
#include "main.h"

class Expansion {
  public:
    void run();
    void setUnlocked(bool state);
    void release();
};

extern Expansion ex;

