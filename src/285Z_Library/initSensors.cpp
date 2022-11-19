#include "../include/285z/initRobot.hpp"

pros::ADIDigitalOut indexer('G');
pros::ADIDigitalOut eg('H');
pros::Imu imuSensor(19);
pros::ADIDigitalIn autonSelector('B');