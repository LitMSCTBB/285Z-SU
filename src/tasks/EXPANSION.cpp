#ifndef EXPANSION_CPP
#define EXPANSION_CPP

#include "tasks/EXPANSION.hpp"

bool UNLOCK = false, overrideB = false, pressed = true;
uint32_t clockV;
uint32_t pressTime = pros::millis();

void Expansion::run() {
    clockV = pros::millis();
    if ((pros::millis() - clockV) >= 95000 || UNLOCK || overrideB) {
        if (expand.isPressed() || overrideB) { topExpansion.set_value(true); laserExpansion.set_value(true); }
        if (laser.changedToPressed()) {
            pressed = !pressed;
            pressTime = clockV;
            laserExpansion.set_value(pressed);
        }
    }
    if (clockV - pressTime > 500) { pressed = true; }
}

void Expansion::setUnlocked(bool state) {
    UNLOCK = state;
}

void Expansion::release() {
    overrideB = true;
}

#endif