
#pragma once
#include "main.h"

extern pros::Imu imuSensor;

extern IntegratedEncoder leftEnc;
extern IntegratedEncoder rightEnc;

extern pros::ADIDigitalIn autonSelector;

extern pros::ADIDigitalOut topExpansion;
extern pros::ADIDigitalOut laserExpansion;
extern pros::ADIDigitalOut blooper;
extern pros::ADIDigitalOut pistonIntake;