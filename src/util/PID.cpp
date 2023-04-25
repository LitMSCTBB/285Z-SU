#ifndef PID_CPP
#define PID_CPP

#include "util/PID.hpp"

int t1 = 0;
/**
 * Initialize settings for a new PID controller instance.
 * 
 * @param fKP kP value for the PID instance
 * @param fKI kI value for the PID instance
 * @param fKD kD value for the PID instance
 * @param fKF kF value for the PID instance
 * @param pInner lower threshold for the Proportional term to be applied
 * @param pOuter upper threshold for the Proportional term to be applied
 * @param fEpsilonInner lower threshold for error to be accumulated (for the "I" term to change, the measured error must be GREATER than this value)
 * @param fEpsilonOuter upper threshold for error to be accumulated (for the "I" term to change, the measured error must be LESS than this value )
 * @param dInner lower threshold for the Derivative term to be applied
 * @param dOuter upper threshold for the Derivative term to be applied
 * 
 * @return Initialized controller
**/
PID pidInit(float fKP, float fKI, float fKD, float fKF, float pInner, float pOuter, float fEpsilonInner, float fEpsilonOuter, float dInner, float dOuter) {
    PID pid;

    pid.kP = fKP;
    pid.kI = fKI;
    pid.kD = fKD;
    pid.kF = fKF;

    pid.pInner = pInner;
    pid.pOuter = pOuter;
    
    pid.EpsilonInner = fEpsilonInner;
    pid.EpsilonOuter = fEpsilonOuter;

    pid.sigma = 0;
    pid.lastError = 0;
    pid.lastTime = pros::millis();

    pid.dInner = dInner;
    pid.dOuter = dOuter;

    return pid;
}

/**
 * Calculate the output for a given PID instance.
 * 
 * @param pid PID instance to calculate the output for
 * @param fSetPoint "target value" of the PID controller instance
 * @param fProcessVariable sensor value to compare to (and move towards) target
 * @param min minimum value the PID controller should output
 * @param max maximum value the PID controller should output
 * @param uniDirectional (optional) set the PID controller to only output positive values
 * 
 * @return Output value constrained from @param min to @param max
**/
float pidCalculate(PID& pid, float fSetPoint, float fProcessVariable, float min, float max, bool uniDirectional) {
    if (fSetPoint != pid.lastTarget) {
        pid.sigma = 0;
        pid.lastTarget = fSetPoint;
    }
    float fDeltaTime = (float) (pros::millis() - pid.lastTime) / 1000.00;
    pid.lastTime = pros::millis();
    float fError = fSetPoint - fProcessVariable;

    float fDeltaE = 0;
    if (fError > pid.dInner && fError < pid.dOuter) fDeltaE = (fError - pid.lastError) / fDeltaTime;
    else fDeltaE = 0;

    pid.lastError = fError;

    if (fError > pid.EpsilonInner && fError < pid.EpsilonOuter) pid.sigma += fError * fDeltaTime;
    else pid.sigma = 0;

    if (fError < pid.pInner || fError > pid.pOuter) fError = 0;

    float fOutput = (
        fError * pid.kP  // add proportional
        + pid.sigma * pid.kI // add integral
        + fDeltaE * pid.kD // add derivative
        + fSetPoint * pid.kF // add base value
    );
    t1++;
    /*if (t1 % 10 == 0)*/ printf("%11.5f + %11.5f + %11.5f | ", fError * pid.kP, pid.sigma * pid.kI, fDeltaE * pid.kD);
    fOutput = (fOutput > max) ? max : ((fOutput < min) ? min : fOutput);
    return (fOutput > 0 || (!uniDirectional && fOutput < 0)) ? fOutput : 0;
}

float pidCalculateWithE(PID& pid, float err, float fSetPoint, float fProcessVariable, float min, float max, bool uniDirectional) {
    if (fSetPoint != pid.lastTarget) {
        pid.sigma = 0;
        pid.lastTarget = fSetPoint;
    }
    float fDeltaTime = (float) (pros::millis() - pid.lastTime) / 1000.00;
    pid.lastTime = pros::millis();
    float fError = err;

    float fDeltaE = 0;
    if (fError > pid.dInner && fError < pid.dOuter) fDeltaE = (fError - pid.lastError) / fDeltaTime;
    else fDeltaE = 0;

    pid.lastError = fError;

    if (fError > pid.EpsilonInner && fError < pid.EpsilonOuter) pid.sigma += fError * fDeltaTime;
    else pid.sigma = 0;

    if (fError < pid.pInner || fError > pid.pOuter) fError = 0;

    float fOutput = (
        fError * pid.kP  // add proportional
        + pid.sigma * pid.kI // add integral
        + fDeltaE * pid.kD // add derivative
        + fSetPoint * pid.kF // add base value
    );
    t1++;
    /* if (t1 % 10 == 0) */ printf("%11.5f + %11.5f + %11.5f | ", fError * pid.kP, pid.sigma * pid.kI, fDeltaE * pid.kD);
    fOutput = (fOutput > max) ? max : ((fOutput < min) ? min : fOutput);
    return (fOutput > 0 || (!uniDirectional && fOutput < 0)) ? fOutput : 0;
}

#endif