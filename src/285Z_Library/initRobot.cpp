#include "../include/285z/initRobot.hpp"
#include "okapi/api/device/motor/abstractMotor.hpp"
#include "okapi/api/util/logging.hpp"
#include "okapi/api/util/mathUtil.hpp"
#include "okapi/impl/device/button/controllerButton.hpp"
#include "okapi/impl/device/controllerUtil.hpp"
#include "pros/rtos.hpp"

okapi::Controller controller;

//Controller Button
ControllerButton intakeButton = ControllerDigital::Y;
ControllerButton intakeStopButton = ControllerDigital::left;
ControllerButton outtakeButton = ControllerDigital::R2;
ControllerButton flywheelButton = ControllerDigital::L1;
// ControllerButton rollerButton = ControllerDigital::R2;
ControllerButton endgameButton = ControllerDigital::R1;
ControllerButton indexerButton = ControllerDigital::right;
ControllerButton pistonOnceButton = ControllerDigital::L2;

//drive motor points
int rightFrontPort = 9; 
int rightMiddlePort = 10;
int rightBackPort = 20; 

int leftFrontPort = -2;
int leftMiddlePort = -1;
int leftBackPort = -11;

int intakePort = 6;

int flywheelPort = 7;

Motor rightFrontMotor(rightFrontPort, false, AbstractMotor::gearset::blue,
                      AbstractMotor::encoderUnits::degrees,
                      Logger::getDefaultLogger());
Motor rightMiddleMotor(rightMiddlePort, false, AbstractMotor::gearset::blue,
                       AbstractMotor::encoderUnits::degrees,
                       Logger::getDefaultLogger());
Motor rightBackMotor(rightBackPort, false, AbstractMotor::gearset::blue,
                     AbstractMotor::encoderUnits::degrees,
                     Logger::getDefaultLogger());

Motor leftFrontMotor(leftFrontPort, false, AbstractMotor::gearset::blue,
                     AbstractMotor::encoderUnits::degrees,
                     Logger::getDefaultLogger());
Motor leftMiddleMotor(leftMiddlePort, false, AbstractMotor::gearset::blue,
                      AbstractMotor::encoderUnits::degrees,
                      Logger::getDefaultLogger());
Motor leftBackMotor(leftBackPort, false, AbstractMotor::gearset::blue,
                    AbstractMotor::encoderUnits::degrees,
                    Logger::getDefaultLogger());

Motor intakeMotor(intakePort);

Motor flywheelMotor(flywheelPort);

MotorGroup driveL({leftFrontPort, leftMiddlePort, leftBackPort});
MotorGroup driveR({rightFrontPort, rightMiddlePort, rightBackPort});
