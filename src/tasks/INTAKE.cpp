#ifndef INTAKE_CPP
#define INTAKE_CPP

#include "tasks/INTAKE.hpp"

#define TIMEOUT 3

float intakeB = 0;
// bool changed = false,
int indexN = 0;

void Intake::run() {
    if (intakeToggle.changedToPressed()) { intakeB = (intakeB != 1) ? 1 : 0; }
    else if (intakeIn.changedToPressed()) { intakeB = 1; }
    else if (intakeOut.changedToPressed()) { intakeB = -1; }
    else if (intakeIn.changedToReleased() || intakeOut.changedToReleased()) { intakeB = 0; }
    
    if (indexN != 0) {
        while (indexN > 0) {
            intake.moveVoltage(-12000);
            pros::delay((indexN == 1) ? 250 : 145);
            intake.moveVoltage(0);
            while (!flyDone() && indexN != 0) pros::delay(5);
            pros::delay(400);
            indexN--;
        }
    }
    else intake.moveVoltage((int) (intakeB * 12000));
}

void Intake::setState(float n) {
    intakeB = (n / 600.0);
    // indexing = false;
}

void Intake::index(int n) {
    if (!done()) return;
    indexN = n;

    
//     int numShots = n, time = 0;
//     intakeB = -1;

//     while (numShots > 0 && time < TIMEOUT * 1000) { 
//         intakeB = -1;
//         if (indexerSwitch.get_value()) changed = true;
//         if (!indexerSwitch.get_value() && changed) { numShots--; changed = false; }
//         time += 10;
//         pros::delay(10);
//     }
//     pros::delay(250);
//     intakeB = 0;
//     indexing = false;
}

bool Intake::done() {
    return indexN == 0;
}

void Intake::override() {
    indexN = 0;
    intakeB = 0;
}

#endif