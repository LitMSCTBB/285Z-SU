#pragma once
#include "main.h"

//Controller
extern Controller controller;

//Controller Button
extern ControllerButton intakeButton;
extern ControllerButton intakeStopButton;
extern ControllerButton outtakeButton;
extern ControllerButton flywheelFastButton;
extern ControllerButton flywheelSlowButton;
extern ControllerButton indexerButton;
extern ControllerButton rollerButton;
extern ControllerButton endgameButton;
extern ControllerButton pistonButton;


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

//Motors
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
extern std::shared_ptr<okapi::ChassisController> PIDchassisGoal;
