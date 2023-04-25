#ifndef FLYWHEEL_HPP
#define FLYWHEEL_HPP

class Flywheel {
    public:
        void run();
        void setState(bool state);
        void setInterpolationState(bool state);
        void setTarget(int target);
        bool done();
};

#endif