#include "../include/285z/initRobot.hpp"
#include "okapi/impl/device/controllerUtil.hpp"

okapi::Controller controller;

//Controller Button
ControllerButton intakeButton = ControllerDigital::Y;
ControllerButton outtakeButton = ControllerDigital::B;
ControllerButton flywheelButton = ControllerDigital::up;
ControllerButton indexerButton = ControllerDigital::right;
ControllerButton endgameButton = ControllerDigital::L1;

//drive motor points
int rightFrontPort = -20; 
int rightBackPort = -11; 

int leftFrontPort = 10;
int leftBackPort = 1;

int intakePort = 6;
int indexerPort = 7;
int endgamePort = 8;

int flywheelPort = 18;

Motor rightFrontMotor(rightFrontPort);
Motor rightBackMotor(rightBackPort);

Motor leftFrontMotor(leftFrontPort);
Motor leftBackMotor(leftBackPort);

Motor intakeMotor(intakePort);
Motor indexerMotor(indexerPort, false, okapi::AbstractMotor::gearset::green, okapi::AbstractMotor::encoderUnits::degrees);
Motor endgameMotor(endgamePort);

Motor flywheelMotor(flywheelPort);

MotorGroup driveL({leftFrontPort, leftBackPort});
MotorGroup driveR({rightFrontPort, rightBackPort});
