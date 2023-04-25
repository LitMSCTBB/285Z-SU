#ifndef INIT_CPP
#define INIT_CPP

#include "main.h"
#include "util/PID.hpp"

// -------------------------------------- Declarations --------------------------------------

/* Buttons */
button bloop = btn::right; // Left Scuff
button intakeToggle = btn::Y; // Right Scuff
button brake = btn::X;
button flywheelbtn = btn::L1;
button intakeIn = btn::L2;
button expand = btn::R1;
button intakeOut = btn::R2;
button laser = btn::up;
button distancebtn = btn::down;

/* Standalone Motors */
int8_t intakePort = 20;
int8_t flywheelPort = 1;

/* IMU */
int8_t imuPort = 15;

/* 3-Wire Ports */
uint8_t autonPort = cast 'D';
uint8_t blooperPort = cast 'H';
uint8_t topExpansionPort = cast 'F';
uint8_t laserExpansionPort = cast 'E';
uint8_t pistonIntakePort = cast 'G';

/* V5 Ports */
// N/A

/* Drive */
int8_t driveFLPort = 13;
int8_t driveMLPort = 16;
int8_t driveBLPort = 14;

int8_t driveFRPort = 19;
int8_t driveMRPort = 18;
int8_t driveBRPort = 17;

// ------------------------------------ End Declarations ------------------------------------

// ---------------------------------- Initialization -----------------------------------

/* Controller */
Controller controller;

/* Motors (edit parameters in main.h) */
Motor driveFL(driveFLPort, true, driveParams);
Motor driveML(driveMLPort, false, driveParams);
Motor driveBL(driveBLPort, true, driveParams);

Motor driveFR(driveFRPort, false, driveParams);
Motor driveMR(driveMRPort, true, driveParams);
Motor driveBR(driveBRPort, false, driveParams);

Motor intake(intakePort, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);
Motor flywheel(flywheelPort, false, AbstractMotor::gearset::blue, AbstractMotor::encoderUnits::degrees);

/* IMU */
pros::IMU imu(imuPort);

/* Encoders */
IntegratedEncoder leftEnc = IntegratedEncoder(driveBLPort);
IntegratedEncoder rightEnc = IntegratedEncoder(driveBRPort);

/* 3-Wire Inputs */
pros::ADIDigitalIn autonSelector(autonPort);

/* 3-Wire Outputs */
pros::ADIDigitalOut topExpansion(topExpansionPort);
pros::ADIDigitalOut laserExpansion(laserExpansionPort);
pros::ADIDigitalOut blooper(blooperPort);
pros::ADIDigitalOut pistonIntake(pistonIntakePort);

/* Motor Groups */
MotorGroup RD({ driveFR, driveMR, driveBR });
MotorGroup LD({ driveFL, driveML, driveBL });

/* Drive (edit parameters in main.h) */
std::shared_ptr<ChassisController> drive = okapi::ChassisControllerBuilder()
  .withMotors(LD, RD)
  .withDimensions(chassisParams)
  .withMaxVelocity(600)
  .build();
  
/* Tune PID below */
PID flywheelPID = pidInit(95, 2, 0.15, 6.45, -FLT_MAX, FLT_MAX, -200, 200, -50, 200); // error units are RPM
PID drivePID = pidInit(1000, 400, 85, 0, -FLT_MAX, FLT_MAX, -5, 5, -13.5, 13.5); // error units are inches
PID turnPID = pidInit(800, 9000, 60, 0, -FLT_MAX, FLT_MAX, -1.75, 1.75, -40, 40);

/*
  ---- Odometry ----
  These constants are based off of 5225A's position tracking document located here. (end of pg. 3 + beginning of pg. 4) http://thepilons.ca/wp-content/uploads/2018/10/Tracking.pdf
  All units are inches.
  Precision is extremely important when measuring and setting these values.
*/

float wheelDiameterS = 260.0 / (25.4 * M_PI); // Diameters of both the left and right tracking wheels

// -------------------------------- End Initialization ---------------------------------

#endif