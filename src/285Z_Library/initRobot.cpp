#include "../include/285z/initRobot.hpp"
#include "okapi/impl/device/controllerUtil.hpp"
#include "pros/rtos.hpp"

okapi::Controller controller;

//Controller Button
ControllerButton intakeButton = ControllerDigital::Y;
ControllerButton outtakeButton = ControllerDigital::B;
ControllerButton flywheelFastButton = ControllerDigital::L1;
ControllerButton flywheelSlowButton = ControllerDigital::L2;
ControllerButton indexerButton = ControllerDigital::right;
ControllerButton endgameButton = ControllerDigital::R1;

//drive motor points
int rightFrontPort = 10; 
int rightMiddlePort = 9;
int rightBackPort = 8; 

int leftFrontPort = -5;
int leftMiddlePort = -6;
int leftBackPort = -7;

int intakePort = 1;
int indexerPort = 20;
int endgamePort = 18;

int flywheelPort = 3;

Motor rightFrontMotor(rightFrontPort);
Motor rightBackMotor(rightBackPort);

Motor leftFrontMotor(leftFrontPort);
Motor leftBackMotor(leftBackPort);

pros::Mutex mutex;
Motor intakeMotor(intakePort);
Motor indexerMotor(indexerPort, false, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
Motor endgameMotor(endgamePort, false, okapi::AbstractMotor::gearset::green,
                   okapi::AbstractMotor::encoderUnits::degrees);

Motor flywheelMotor(flywheelPort);

MotorGroup driveL({leftFrontPort, leftMiddlePort, leftBackPort});
MotorGroup driveR({rightFrontPort, rightMiddlePort, rightBackPort});
