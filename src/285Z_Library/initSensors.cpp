#include "../include/285z/initRobot.hpp"

pros::ADIDigitalOut indexer('A');
pros::ADIDigitalOut eg('C');
pros::Imu imuSensor(19);
pros::ADIDigitalIn autonSelector('B');