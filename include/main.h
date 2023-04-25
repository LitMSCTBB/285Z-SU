/**
 * \file main.h
 *
 * Contains common definitions and header files used throughout your PROS
 * project.
 *
 * Copyright (c) 2017-2021, Purdue University ACM SIGBots.
 * All rights reserved.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef _PROS_MAIN_H_
#define _PROS_MAIN_H_

/**
 * If defined, some commonly used enums will have preprocessor macros which give
 * a shorter, more convenient naming pattern. If this isn't desired, simply
 * comment the following line out.
 *
 * For instance, E_CONTROLLER_MASTER has a shorter name: CONTROLLER_MASTER.
 * E_CONTROLLER_MASTER is pedantically correct within the PROS styleguide, but
 * not convienent for most student programmers.
 */
#define PROS_USE_SIMPLE_NAMES

/**
 * If defined, C++ literals will be available for use. All literals are in the
 * pros::literals namespace.
 *
 * For instance, you can do `4_mtr = 50` to set motor 4's target velocity to 50
 */
#define PROS_USE_LITERALS

#include "api.h"

/**
 * You should add more #includes here
 */
#include "okapi/api.hpp"
#include "pros/apix.h"
//#include "pros/api_legacy.h"

/**
 * If you find doing pros::Motor() to be tedious and you'd prefer just to do
 * Motor, you can use the namespace with the following commented out line.
 *
 * IMPORTANT: Only the okapi or pros namespace may be used, not both
 * concurrently! The okapi namespace will export all symbols inside the pros
 * namespace.
 */
// using namespace pros;
// using namespace pros::literals;
using namespace okapi;

/**
 * Prototypes for the competition control tasks are redefined here to ensure
 * that they can be called from user code (i.e. calling autonomous from a
 * button press in opcontrol() for testing purposes).
 */
#ifdef __cplusplus
extern "C" {
#endif

// ----------------------------------------- ADD TYPE DEFINITIONS HERE -----------------------------------------

typedef struct {
    float kP; // kP
    float kI; // kI
    float kD; // kD
    float kF; // kF
    float pInner; // errpr lower bound to use proportional
    float pOuter; // error upper bound to use proportional
    float EpsilonInner; // error accumulation lower bound
    float EpsilonOuter; // error accumulation upper bound
    float dInner; // error lower bound to use derivative
    float dOuter; // error upper bound to use derivative
    float sigma; // total error
    float lastError; // last error relative to target
    float lastTarget; // last set target value
    unsigned long lastTime; // last time (in milliseconds)
} PID;

// -------------------------------------------- END TYPE DEFINITIONS -------------------------------------------

// -------------------------------------- ADD DEFINES & DECLARATIONS HERE --------------------------------------

#define button ControllerButton
#define btn ControllerDigital
#define cast (uint8_t)

#define driveGearset AbstractMotor::gearset::blue
#define driveTPR imev5BlueTPR
#define driveRatio (36.0 / 60.0)
#define driveWheels 3.25_in
#define wheelBase 10.5_in

#define ANALOG_TO_VOLTAGE 94.488189

#define driveParams driveGearset, AbstractMotor::encoderUnits::counts
#define chassisParams {driveGearset, driveRatio}, {{driveWheels, wheelBase}, driveTPR}

#define sqr(n) powf(n, 2)
#define sign(n) ((n > 0) - (n < 0))
#define todeg(rad) (rad * 180 / M_PI)
#define torad(deg) (deg * M_PI / 180)

extern Controller controller;

extern button brake;
extern button flywheelbtn;
extern button intakeIn;
extern button intakeOut;
extern button intakeToggle;
extern button expand;
extern button laser;
extern button distancebtn;
extern button bloop;

extern Motor driveFL;
extern Motor driveFR;
extern Motor driveML;
extern Motor driveMR;
extern Motor driveBL;
extern Motor driveBR;

extern Motor intake;
extern Motor flywheel;

extern pros::IMU imu;

extern IntegratedEncoder leftEnc;
extern IntegratedEncoder rightEnc;

extern pros::ADIDigitalOut topExpansion;
extern pros::ADIDigitalOut laserExpansion;
extern pros::ADIDigitalOut blooper;
extern pros::ADIDigitalOut pistonIntake;

extern pros::ADIDigitalIn autonSelector;

extern MotorGroup LD;
extern MotorGroup RD;

extern std::shared_ptr<ChassisController> drive;

extern std::atomic<int> bState;

extern PID flywheelPID;
extern PID drivePID;
extern PID turnPID;

extern pros::Task driveT;
extern pros::Task flyT;
extern pros::Task intakeT;
extern pros::Task expandT;

// ---------------------------------------- END DEFINES & DECLARATIONS -----------------------------------------

// ------------------------------------------- ODOMETRY -------------------------------------------

extern float Sl;
extern float Sr;
extern float wheelDiameterS;

// ----------------------------------------- END ODOMETRY -----------------------------------------

// ------------------------------------------- AUTONS -------------------------------------------

extern int aut;

extern void noAuton();
extern void fullWP();
extern void rightSideHighGoal();
extern void leftSideHighGoal();

const std::vector<std::string> autons = {
	"No Autonomous       ",
	"Full WP             ",
	"RS High Goal        ",
    "LS High Goal        "
};

const int numAutons = (int) autons.size();

// ----------------------------------------- END AUTONS -----------------------------------------

extern void autonomous(void);
extern void initialize(void);
extern void disabled(void);
extern void competition_initialize(void);
extern void opcontrol(void);

#ifdef __cplusplus
}
#endif

#ifdef __cplusplus
/**
 * You can add C++-only headers here
 */

#endif

#include "task_manager.hpp"

#endif  // _PROS_MAIN_H_
