#include "../include/285z/initRobot.hpp"
#include "okapi/impl/device/controllerUtil.hpp"
#include "pros/rtos.hpp"

okapi::Controller controller;

//Controller Button
ControllerButton intakeButton = ControllerDigital::Y;
ControllerButton intakeStopButton = ControllerDigital::left;
ControllerButton outtakeButton = ControllerDigital::B;
ControllerButton flywheelSlowButton = ControllerDigital::L1;
ControllerButton indexerButton = ControllerDigital::right;
// ControllerButton rollerButton = ControllerDigital::R2;
ControllerButton endgameButton = ControllerDigital::R1;
ControllerButton pistonButton = ControllerDigital::down;
ControllerButton pistonOnceButton = ControllerDigital::L2;

//drive motor ports
int rightFrontPort = 9; 
int rightMiddlePort = 10;
int rightBackPort = 8; 

int leftFrontPort = -1;
int leftMiddlePort = -2;
int leftBackPort = -3;

int intakePort = 20;

int flywheelPort = 19;

Motor rightFrontMotor(rightFrontPort);
Motor rightMiddleMotor(rightMiddlePort);
Motor rightBackMotor(rightBackPort);

Motor leftFrontMotor(leftFrontPort);
Motor leftMiddleMotor(leftMiddlePort);
Motor leftBackMotor(leftBackPort);

pros::Mutex mutex;
Motor intakeMotor(intakePort);

Motor flywheelMotor(flywheelPort);

MotorGroup driveL({leftFrontPort, leftMiddlePort, leftBackPort});
MotorGroup driveR({rightFrontPort, rightMiddlePort, rightBackPort});
