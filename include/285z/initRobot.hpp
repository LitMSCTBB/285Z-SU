#pragma once
#include "main.h"

//Controller
extern Controller controller;

//Controller Button
extern ControllerButton flywheelButton;

//drive motor points
extern int rightFrontPort;
extern int rightBackPort;
extern int leftFrontPort;
extern int leftBackPort;

extern int flywheelFrontPort;
extern int flywheelBackPort;

//Motors
extern Motor rightFrontMotor;
extern Motor rightBackMotor;
extern Motor leftFrontMotor;
extern Motor leftBackMotor;

extern Motor flywheelFrontMotor;
extern Motor flywheelBackMotor;

//Drive motor groups

extern std::shared_ptr<okapi::ChassisController> PIDchassis;
extern std::shared_ptr<okapi::ChassisController> PIDchassisGoal;
