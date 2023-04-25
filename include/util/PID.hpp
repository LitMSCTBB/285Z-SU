#ifndef PID_HPP
#define PID_HPP

#include "main.h"

extern PID pidInit(float fKP, float fKI, float fKD, float fKF, float pInner, float pOuter, float fEpsilonInner, float fEpsilonOuter, float dInner, float dOuter);
extern float pidCalculate(PID& pid, float fSetPoint, float fProcessVariable, float min, float max, bool uniDirectional = false);
extern float pidCalculateWithE(PID& pid, float err, float fSetPoint, float fProcessVariable, float min, float max, bool uniDirectional = false);

#endif