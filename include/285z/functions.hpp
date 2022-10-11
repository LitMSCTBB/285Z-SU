#pragma once
#include "../include/285z/initRobot.hpp"
#include "../include/285Z_Subsystems/flywheel.hpp"
#include "../include/285Z_Subsystems/intake.hpp"

// flywheel
void autoSpin();
void autoShoot();

// intake
void autoRun();

// endgame
void endgame();

//   **AUTON FUNCTIONS**    //
void noAuton();
void skillsAuto(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast);

void redLeftBlueLeft(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast);

void redRightBlueRight(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast);

void winPoint(std::shared_ptr<okapi::AsyncMotionProfileController> med,
  std::shared_ptr<okapi::AsyncMotionProfileController> fast);

const bool fwd {false};
const bool bwd {true};

/*****************************   AUX AUTONS    **********************/
void move(std::shared_ptr<okapi::AsyncMotionProfileController> profile, okapi::QLength distance, bool dir);
void parkingBrake();
