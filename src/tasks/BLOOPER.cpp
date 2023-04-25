#ifndef BLOOPER_CPP
#define BLOOPER_CPP

#include "tasks/BLOOPER.hpp"

std::atomic<int> bState = 0;

void Blooper::run() {
    if (bloop.changedToPressed()) bState = ((bState != 1) ? 1 : -1);
    blooper.set_value((bState == 1) ? true : false);
}

void Blooper::setState(int state) {
    bState = state;
}

#endif