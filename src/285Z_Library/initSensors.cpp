#include "../include/285z/initRobot.hpp"

pros::ADIDigitalOut indexer('G');
pros::ADIDigitalOut eg('H');
pros::Imu imuSensor(8);
pros::ADIDigitalIn autonSelector('B');