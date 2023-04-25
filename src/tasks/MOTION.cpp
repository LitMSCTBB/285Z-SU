#ifndef MOTION_CPP
#define MOTION_CPP

#include "tasks/MOTION.hpp"

#include "util/PID.hpp"

bool braking = true;

float dist, angleT, mSpeed;
int moveState = 0;

void Drive::run() {
    if (brake.changedToPressed()) {
        if (braking) {
            LD.setBrakeMode(AbstractMotor::brakeMode::coast);
            RD.setBrakeMode(AbstractMotor::brakeMode::coast);
        }
        else {
            LD.setBrakeMode(AbstractMotor::brakeMode::hold);
            RD.setBrakeMode(AbstractMotor::brakeMode::hold);
        }
        braking = !braking;
    }

    if (moveState != 0) {
      bool driveDone = false, turnDone = false;

      float voltage = 0, lastVoltage = 0;
      float err = dist, lastErr = err, deltaErr = 0;

      float travel = 0;
      float leftVal = -leftEnc.get(), rightVal = rightEnc.get(), lastLeft = leftVal, lastRight = rightVal;
      float phi, theta, lastTheta;

      if (moveState == 1 || moveState == 3) {
        while (!driveDone && (moveState == 1 || moveState == 3)) {
          if (dist != drivePID.lastTarget) travel = 0;
          voltage = pidCalculate(drivePID, dist, travel, -12000 * mSpeed, 12000 * mSpeed);
          if (fabs(voltage - lastVoltage) > 4000) { lastVoltage += (voltage - lastVoltage) / 25; }
          else { lastVoltage = voltage; }

          LD.moveVoltage(lastVoltage);
          RD.moveVoltage(lastVoltage);

          travel += (((leftVal - lastLeft) + (rightVal - lastRight)) / 2.0) / driveTPR * driveRatio * (M_PI * 2) * (wheelDiameterS / 2);

          lastErr = err; err = dist - travel;

          lastLeft = leftVal; lastRight = rightVal;
          leftVal = -leftEnc.get(); rightVal = rightEnc.get();
          driveDone = (fabs(err) < 0.75) && (fabs(err - lastErr) < 0.5);
          
          printf("voltage - %10.3f | err - %6.3f | traveled %6.3f | LD - %.3f RD - %.3f | %s\n", voltage, err, travel, leftVal, rightVal, (driveDone) ? "done" : "not done");
          
          pros::delay(10);
        }

        LD.moveVoltage(0);
        RD.moveVoltage(0);
      }

      printf("\n\n");

      if (moveState == 2 || moveState == 3) {
        err = angleT, lastErr = err, deltaErr = 0;
        theta = imu.get_heading(), phi = fabs(angleT - theta);
        if (phi > 180) {
          if (angleT > 180) angleT -= 360;
          if (theta > 180) theta -= 360;
        }

        lastTheta = theta;
        err = 0, lastErr = 0;
        
        while (!turnDone && (moveState == 2 || moveState == 3)) {
          
          lastTheta = theta;
          theta = imu.get_heading();
          printf("actual imu val - %.3f | ", theta);
          if (phi > 180 && theta > 180) theta -= 360;
          
          err = (fabs(angleT - theta) < fabs(angleT - theta - 360)) ? (angleT - theta) : (angleT - theta - 360);
          voltage = pidCalculateWithE(turnPID, err, angleT, theta, -12000, 12000);
          
          LD.moveVoltage(voltage);
          RD.moveVoltage(-voltage);

          turnDone = (fabs(err) < 0.35) && (fabs(err - lastErr) < 0.25);

          lastErr = err;

          printf("voltage - %10.3f | err - %8.3f | angle is %7.3f | t: %5.3f | %s\n", voltage, err, theta, angleT, (turnDone) ? "done" : "not done");
          pros::delay(10);
        }

        LD.moveVoltage(0);
        RD.moveVoltage(0);
        
      }

      moveState = 0;
    }
}

void Drive::override() {
  moveState = 0;
}

bool Drive::done() {
  return (moveState == 0);
}

void Drive::moveLinear(float disp, float speed) {
  moveState = 1;
  dist = disp;
  mSpeed = speed;
}

void Drive::IMUTurn(float degrees) {
  moveState = 2;
  angleT = degrees;
}

void Drive::moveTurn(float disp, float endAngle, float speed) {
  moveState = 3;
  dist = disp;
  angleT = endAngle;
  mSpeed = speed;
  // printf("%.3f | %s\n", travel, (atTarget) ? "done" : "not done");
}

#endif