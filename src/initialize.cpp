#include "main.h"

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	pros::lcd::initialize();
	controller.clear();
	pros::delay(110);
	pros::lcd::print(0, "Initializing...");

	LD.setBrakeMode(AbstractMotor::brakeMode::coast);
	RD.setBrakeMode(AbstractMotor::brakeMode::coast);
	intake.setBrakeMode(AbstractMotor::brakeMode::hold);
	flywheel.setBrakeMode(AbstractMotor::brakeMode::coast);
	pros::lcd::print(2, "Brake modes set");

	leftEnc.reset();
	rightEnc.reset();
	pros::lcd::print(3, "Tracking wheels reset");


	pros::lcd::print(4, "Calibrating...");
	imu.reset();
	while (imu.is_calibrating()) { pros::delay(5); }
	imu.set_heading(0);
	pros::lcd::print(4, "Reset IMU     ");

	topExpansion.set_value(false);
	laserExpansion.set_value(false);
	blooper.set_value(false);
	pistonIntake.set_value(false);
	pros::lcd::print(5, "Set pistons");

	startTasks();
	pros::lcd::print(6, "Started tasks");

	pros::lcd::set_text(0, "Done Initializing     ");
	
	printf("Detected %d autonomous routines\n", numAutons);
}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}