#include "main.h"

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {
    pros::delay(50);
    LD.setBrakeMode(AbstractMotor::brakeMode::coast);
    RD.setBrakeMode(AbstractMotor::brakeMode::coast);

    switch (aut) {
        case (0): noAuton(); break;
        case (1): fullWP(); break;
        case (2): rightSideHighGoal(); break;
        case (3): leftSideHighGoal(); break;
        case (4): rightSideRush(); break;
        default: noAuton(); break;
    }
}