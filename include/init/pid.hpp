typedef struct {
  float kP;               // kP
  float kI;               // kI
  float kD;               // kD
  float kF;               // kF
  float pInner;           // errpr lower bound to use proportional
  float pOuter;           // error upper bound to use proportional
  float EpsilonInner;     // error accumulation lower bound
  float EpsilonOuter;     // error accumulation upper bound
  float dInner;           // error lower bound to use derivative
  float dOuter;           // error upper bound to use derivative
  float sigma;            // total error
  float lastError;        // last error relative to target
  float lastTarget;       // last set target value
  unsigned long lastTime; // last time (in milliseconds)
} PID;

extern PID pidInit(float fKP, float fKI, float fKD, float fKF, float pInner,
                   float pOuter, float fEpsilonInner, float fEpsilonOuter,
                   float dInner, float dOuter);
extern float pidCalculate(PID &pid, float fSetPoint, float fProcessVariable,
                          float min, float max, bool uniDirectional = false);
extern float pidCalculateWithE(PID &pid, float err, float fSetPoint,
                               float fProcessVariable, float min, float max,
                               bool uniDirectional = false);

extern PID flywheelPID, drivePID, turnPID;