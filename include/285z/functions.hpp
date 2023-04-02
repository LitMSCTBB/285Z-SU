#pragma once
#include "../include/285z/initRobot.hpp"
#include "../include/285Z_Subsystems/flywheel.hpp"
#include "../include/285Z_Subsystems/intake.hpp"

// flywheel
void autoSpin(double speed = 0);
void autoShoot();
void moveDrive(double amount, bool fast);

// intake
void autoRun();

// endgame
void endgame();

//   **AUTON FUNCTIONS**    //
void noAuton(std::shared_ptr<okapi::AsyncMotionProfileController> med,
             std::shared_ptr<okapi::AsyncMotionProfileController> fast);
void skillsAuto(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast);

void leftLow(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast);

void leftHigh(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast);

void rightLow(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast);

void rightHigh(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast);

void winPoint(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast);

const bool fwd {false};
const bool bwd {true};

/*****************************   AUX AUTONS    **********************/
void move(std::shared_ptr<okapi::AsyncMotionProfileController> profile, okapi::QLength distance, bool dir);
void parkingBrake();
