#pragma once
#include "main.h"

class Blooper {
  public:
    void setState(int state);
    void run();
};

extern std::atomic<int> bState;

extern Blooper b;