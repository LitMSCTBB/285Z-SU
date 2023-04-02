#include "../include/285z/initRobot.hpp"

pros::ADIDigitalOut indexer('G');
pros::ADIDigitalOut eg('H');
pros::Imu imuSensor(21);
pros::ADIDigitalIn autonSelector('B');