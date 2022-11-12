#include "../include/285z/initRobot.hpp"

pros::ADIDigitalOut indexer('H');
pros::ADIDigitalOut eg('G');
pros::Imu imuSensor(19);
pros::ADIDigitalIn autonSelector('B');