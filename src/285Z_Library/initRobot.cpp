#include "../include/285z/initRobot.hpp"
#include "okapi/impl/device/controllerUtil.hpp"

okapi::Controller controller;

//Controller Button
ControllerButton flywheelButton = ControllerDigital::A;

//drive motor points
int rightFrontPort = -20; 
int rightBackPort = -19; 

int leftFrontPort = 11;
int leftBackPort = 12;

int flywheelFrontPort = -18;
int flywheelBackPort = 17;

Motor rightFrontMotor(rightFrontPort);
Motor rightBackMotor(rightBackPort);

Motor leftFrontMotor(leftFrontPort);
Motor leftBackMotor(leftBackPort);

Motor flywheelFrontMotor(flywheelFrontPort);
Motor flywheelBackMotor(flywheelBackPort);
