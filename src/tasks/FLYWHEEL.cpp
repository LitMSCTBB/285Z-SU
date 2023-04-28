#ifndef FLYWHEEL_CPP
#define FLYWHEEL_CPP

#include "tasks/FLYWHEEL.hpp"

#include "util/PID.hpp"

// How smooth the PID output should be
#define smoothDegree 16
// Base flywheel speed
#define baseSpeed 1700
// Secondary flywheel speed
#define secondSpeed 2000
// Blooper flywheel speed
#define bloopSpeed 1600

bool flywheelB = false;
bool flyD = true;
bool interpolate = false;

int FLY_TARGET = baseSpeed;

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
    err = FLY_TARGET - (flywheel.getActualVelocity() * 6.0);
    deltaErr = err - lastErr;

    if (flywheelbtn.changedToPressed()) flywheelB = !flywheelB;

    if (flywheelB) {
        voltageT -= voltages[voltageIndex];
        // tmp = pidCalculate(flywheelPID, t / 6.0, flywheel.getActualVelocity(), -12000 - voltage, 12000 - voltage);
        // voltages[voltageIndex] = voltage + tmp;
        voltages[voltageIndex] = pidCalculate(flywheelPID, FLY_TARGET, flywheel.getActualVelocity() * 6.0, 0, 12000);
        // voltage += (tmp - prevOutput);
        // prevOutput = tmp;
        voltageT += voltages[voltageIndex];
        voltageIndex = (voltageIndex == smoothDegree - 1) ? 0 : voltageIndex + 1;
        
        voltage = (err > 90) ? 12000 : ((float) voltageT / smoothDegree);

        flyD = (fabs(err) < 60) && (fabs(deltaErr) < 100);

        if (distancebtn.changedToPressed() && (bState != 1)){ distToggle = !distToggle; }
        
        if (bState != prevBloopState) {
            prevBloopState = bState;
            switch (bState) {
                case (-1): setTarget((distToggle) ? secondSpeed : baseSpeed); break;
                case (0): setTarget(FLY_TARGET); break;
                case (1): setTarget(bloopSpeed); break;
            }
        }
        
        // if (t % 10 == 0) printf("(%f, %f) | %.5f, %d\n", t * 0.01, flywheel.getActualVelocity() * 6.0, tmp, voltage);
        // if (t % 10 == 0) printf("(%9.5f, %11.5f) | %d\n", t * 0.01, flywheel.getActualVelocity() * 6.0, voltage);
        // if (t % 10 == 0) printf("(%9.5f, %11.5f) | %d\n", t * 0.01, flywheel.getActualVelocity() * 6.0, voltage);
        // if (t % 10 == 0) printf("(%f-s_{croll}, %f)\n", t * 0.01, flywheel.getActualVelocity() * 6.0);
        // if (t % 10 == 0) printf("(%f-s_{croll}, %f)\n", t * 0.01, tmp);

        // printf("voltage: %04d | speed: %10.5f | %s\n", voltage, flywheel.getActualVelocity() * 6.0, (flyD) ? "target reached" : "approaching target");
    }
    else { voltage = 0; }
    flywheel.moveVoltage(voltage);
    // controller.setText(1, 0, std::to_string(flywheel.getActualVelocity() * 6.0));
}

void Flywheel::setState(bool state) {
    flywheelB = state;
    flyD = false;
}

void Flywheel::setInterpolationState(bool state) {
    interpolate = state;
    flyD = false;
}

void Flywheel::setTarget(int target) {
    FLY_TARGET = target;
    flywheelB = true;
    flyD = false;
    interpolate = false;
}

bool Flywheel::done() {
    return flyD;
}

#endif