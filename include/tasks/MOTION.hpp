#ifndef MOTION_HPP
#define MOTION_HPP

#include "main.h"

// #include <deque>
// #include <algorithm>

// extern void setBrakes(bool state);
// extern void followPath(float targetX, float targetY, pathType type, float res, POINT controlPts[]);
class Drive {
    public:
        void run();
        void override();
        bool done();
        void moveLinear(float disp, float speed);
        void IMUTurn(float degrees);
        void moveTurn(float disp, float endAngle, float speed);
};
// extern void turn(float targetAngle);
// extern void move(std::shared_ptr<okapi::AsyncMotionProfileController> profile, okapi::QLength xDistance, okapi::QLength yDistance, okapi::QAngle angle, bool dir);
#endif