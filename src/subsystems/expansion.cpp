#include "main.h"
#include "../include/subsystems/expansion.hpp"
#include "../include/init/initRobot.hpp"
#include "../include/init/initSensors.hpp"

bool UNLOCK = true, overrideB = false, pressed = true;
uint32_t clockV;
uint32_t pressTime = pros::millis();

void Expansion::run() {
  clockV = pros::millis();
  if ((pros::millis() - clockV) >= 95000 || UNLOCK || overrideB) {
    if (expandButton.isPressed() || overrideB) {
      topExpansion.set_value(true);
      laserExpansion.set_value(true);
    }
    if (laserButton.changedToPressed()) {
      pressed = !pressed;
      pressTime = clockV;
      laserExpansion.set_value(pressed);
    }
  }
  if (clockV - pressTime > 500) {
    pressed = true;
  }
}

void Expansion::setUnlocked(bool state) { UNLOCK = state; }

void Expansion::release() { overrideB = true; }