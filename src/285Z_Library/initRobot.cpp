#include "../include/285z/initRobot.hpp"
#include "okapi/impl/device/controllerUtil.hpp"

okapi::Controller controller;

//Controller Button
ControllerButton intakeButton = ControllerDigital::B;
ControllerButton outtakeButton = ControllerDigital::down;
ControllerButton flywheelButton = ControllerDigital::A;

//drive motor points
int rightFrontPort = -20; 
int rightBackPort = -11; 

int leftFrontPort = 10;
int leftBackPort = 1;

int intakePort = 6;

int flywheelFrontPort = -18;
int flywheelBackPort = 17;

Motor rightFrontMotor(rightFrontPort);
Motor rightBackMotor(rightBackPort);

Motor leftFrontMotor(leftFrontPort);
Motor leftBackMotor(leftBackPort);

Motor intakeMotor(intakePort);

Motor flywheelFrontMotor(flywheelFrontPort);
Motor flywheelBackMotor(flywheelBackPort);

MotorGroup driveL({leftFrontPort, leftBackPort});
MotorGroup driveR({rightFrontPort, rightBackPort});
