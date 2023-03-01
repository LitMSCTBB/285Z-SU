#include "../include/285z/initRobot.hpp"

pros::ADIDigitalOut blooper('H');
pros::ADIDigitalOut indexer('G');
pros::ADIDigitalOut eg('A');
pros::Imu imuSensor(8);
pros::ADIDigitalIn autonSelector('B');