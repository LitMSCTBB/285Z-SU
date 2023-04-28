#include "../../include/subsystems/flywheel.hpp"
#include "../../include/subsystems/blooper.hpp"
#include "../../include/init/initRobot.hpp"
#include "../../include/init/initSensors.hpp"
#include "../../include/init/initRobot.hpp"
#include "init/pid.hpp"
#include "subsystems/blooper.hpp"

// How smooth the PID output should be
#define smoothDegree 16
// Base flywheel speed
#define baseSpeed 1650
// Blooper flywheel speed
#define bloopSpeed 1550

bool flywheelB = false;
bool flyD = false;
int FLY_TARGET = baseSpeed;
int fwSpeeds[2] = {baseSpeed, bloopSpeed};

int16_t voltage;
int voltageT = 0;
float voltages[smoothDegree] = {};
int voltageIndex = 0;

float err;
float deltaErr;
float lastErr = 0;

bool distToggle = false;
int prevBloopState = 10;

void Flywheel::run() {
  err = FLY_TARGET - (flywheelMotor.getActualVelocity() * 6.0);
  deltaErr = err - lastErr;

  if (flywheelButton.changedToPressed())
    this->setState(!flywheelB);

  if (flywheelB)
  {
    voltageT -= voltages[voltageIndex];
    float val =
        pidCalculate(flywheelPID, FLY_TARGET, flywheelMotor.getActualVelocity() * 6.0, 0, 12000);
    
    voltages[voltageIndex] = val;

    voltageT += voltages[voltageIndex];
    voltageIndex = (voltageIndex == smoothDegree - 1) ? 0 : voltageIndex + 1;

    voltage = (err > 90) ? 12000 : ((float)voltageT / smoothDegree);
    flyD = (fabs(err) < 60) && (fabs(deltaErr) < 100);

    // if (distanceButton.changedToPressed() && (bState != 1)) {
    //   distToggle = !distToggle;
    // }

    // if (bState != prevBloopState) {
    //   prevBloopState = bState;
    //   switch (bState) {
    //   case (-1):
    //     setTarget(baseSpeed);
    //     break;
    //   case (0):
    //     setTarget(FLY_TARGET);
    //     break;
    //   case (1):
    //     setTarget(bloopSpeed);
    //     break;
    //   }
    // }
    
    // printf("voltage: %04d | speed: %10.5f | %s\n", voltage,
    //        flywheelMotor.getActualVelocity() * 6.0,
    //        (flyD) ? "target reached" : "approaching target");
  }
  else
  {
    FLY_TARGET = 0;
    voltage = 0;
  }
  flywheelMotor.moveVoltage(voltage);
}

void Flywheel::setState(bool st) {
  FLY_TARGET = fwSpeeds[bState];
  flywheelB = st;
  flyD = false;
}

void Flywheel::setTarget(float tar) {
  FLY_TARGET = tar;
  flywheelB = true;
  flyD = false;
}

void Flywheel::auton()
{
  this->setState(true);
  this->run();
}

void Flywheel::op()
{
  this->setState(true);
  this->run();
}

bool Flywheel::done() { return flyD; }