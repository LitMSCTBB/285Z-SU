#ifndef INTAKE_HPP
#define INTAKE_HPP

#include "main.h"

class Intake {
    public:
        void run();
        void setState(float n);
        void index(int n);
        bool done();
};

#endif