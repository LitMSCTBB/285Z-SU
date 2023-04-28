#ifndef EXPANSION_CPP
#define EXPANSION_CPP

#include "tasks/EXPANSION.hpp"

bool UNLOCK = false, overrideB = false, pressedL = true, pressedA = true;
uint32_t clockV;

uint32_t pressTimeLaser = pros::millis();
uint32_t pressTimeAll = pressTimeLaser;

void Expansion::run() {
    clockV = pros::millis();
    // if ((pros::millis() - clockV) >= 95000 || UNLOCK || overrideB) {
        // if (expand.isPressed() || overrideB) { topExpansion.set_value(true); laserExpansion.set_value(true); }
    if (laser.changedToPressed() && pressedA) {
        pressedL = !pressedL;
        pressTimeLaser = clockV;
        laserExpansion.set_value(pressedL);
    }
    else if (expand.changedToPressed() && pressedL) {
        pressedA = !pressedA;
        pressTimeAll = clockV;
        topExpansion.set_value(pressedA);
        laserExpansion.set_value(pressedA);
    }
    // }
    if (clockV - pressTimeLaser > 500) { pressedL = true; }
    if (clockV - pressTimeAll > 500) { pressedA = true; }
}

void Expansion::setUnlocked(bool state) {
    UNLOCK = state;
}

void Expansion::release() {
    overrideB = true;
}

#endif