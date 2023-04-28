#include "../include/init/initRobot.hpp"
#include "okapi/api/device/motor/abstractMotor.hpp"
#include "okapi/api/util/logging.hpp"
#include "okapi/api/util/mathUtil.hpp"
#include "okapi/impl/device/button/controllerButton.hpp"
#include "okapi/impl/device/controllerUtil.hpp"
#include "pros/rtos.hpp"

okapi::Controller controller;

// Controller Button
ControllerButton blooperButton = ControllerDigital::right;
ControllerButton intakeButton = ControllerDigital::Y;
ControllerButton intakeInButton = ControllerDigital::L2;
ControllerButton intakeOutButton = ControllerDigital::R2;
ControllerButton flywheelButton = ControllerDigital::L1;
ControllerButton expandButton = ControllerDigital::R1;
ControllerButton brakeButton = ControllerDigital::X;
ControllerButton laserButton = ControllerDigital::up;
ControllerButton distanceButton = ControllerDigital::down;

// drive motor points
int rightFrontPort = 19;
int rightMiddlePort = -18;
int rightBackPort = 17;

int leftFrontPort = -13;
int leftMiddlePort = 16;
int leftBackPort = -14;

int intakePort = 20;

int flywheelPort = 1;

Motor rightFrontMotor(rightFrontPort, true, AbstractMotor::gearset::blue,
                      AbstractMotor::encoderUnits::degrees,
                      Logger::getDefaultLogger());
Motor rightMiddleMotor(rightMiddlePort, true, AbstractMotor::gearset::blue,
                       AbstractMotor::encoderUnits::degrees,
                       Logger::getDefaultLogger());
Motor rightBackMotor(rightBackPort, true, AbstractMotor::gearset::blue,
                     AbstractMotor::encoderUnits::degrees,
                     Logger::getDefaultLogger());

Motor leftFrontMotor(leftFrontPort, true, AbstractMotor::gearset::blue,
                     AbstractMotor::encoderUnits::degrees,
                     Logger::getDefaultLogger());
Motor leftMiddleMotor(leftMiddlePort, true, AbstractMotor::gearset::blue,
                      AbstractMotor::encoderUnits::degrees,
                      Logger::getDefaultLogger());
Motor leftBackMotor(leftBackPort,true, AbstractMotor::gearset::blue,
                    AbstractMotor::encoderUnits::degrees,
                    Logger::getDefaultLogger());

Motor intakeMotor(intakePort);

Motor flywheelMotor(flywheelPort, false, AbstractMotor::gearset::blue,
                    AbstractMotor::encoderUnits::degrees);

MotorGroup driveL({leftFrontPort, leftMiddlePort, leftBackPort});
MotorGroup driveR({rightFrontPort, rightMiddlePort, rightBackPort});