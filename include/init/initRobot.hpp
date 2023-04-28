#pragma once
#include "main.h"

// Controller
extern Controller controller;

// Controller Button
extern ControllerButton blooperButton;
extern ControllerButton intakeButton;
extern ControllerButton intakeInButton;
extern ControllerButton intakeOutButton;
extern ControllerButton flywheelButton;
extern ControllerButton expandButton;
extern ControllerButton brakeButton;
extern ControllerButton laserButton;
extern ControllerButton distanceButton;

// drive motor points
extern int rightFrontPort;
extern int rightMiddlePort;
extern int rightBackPort;
extern int leftFrontPort;
extern int leftMiddlePort;
extern int leftBackPort;

extern int intakePort;
extern int indexerPort;

extern int flywheelPort;

// Motors
extern Motor rightFrontMotor;
extern Motor rightBackMotor;
extern Motor leftFrontMotor;
extern Motor leftBackMotor;

extern Motor intakeMotor;
extern Motor indexerMotor;

extern Motor flywheelMotor;

// Drive motor groups
extern MotorGroup driveL;
extern MotorGroup driveR;

extern std::shared_ptr<okapi::ChassisController> PIDchassis;
