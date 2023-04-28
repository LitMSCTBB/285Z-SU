#include "main.h"
#include "../include/init/initRobot.hpp"

pros::Imu imuSensor(15);

IntegratedEncoder leftEnc = IntegratedEncoder(-leftBackPort);
IntegratedEncoder rightEnc = IntegratedEncoder(rightBackPort);

/* 3-Wire Ports */
char autonPort = 'D';
char blooperPort = 'H';
char topExpansionPort = 'F';
char laserExpansionPort = 'E';
char pistonIntakePort = 'G';

pros::ADIDigitalIn autonSelector(autonPort);

pros::ADIDigitalOut topExpansion(topExpansionPort);
pros::ADIDigitalOut laserExpansion(laserExpansionPort);
pros::ADIDigitalOut blooper(blooperPort);
pros::ADIDigitalOut pistonIntake(pistonIntakePort);