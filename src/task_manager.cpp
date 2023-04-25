#include "task_manager.hpp"

#include "tasks/BLOOPER.hpp"
#include "tasks/EXPANSION.hpp"
#include "tasks/FLYWHEEL.hpp"
#include "tasks/INTAKE.hpp"
#include "tasks/MOTION.hpp"

#define durCastSec(ms) std::chrono::duration_cast<std::chrono::seconds>(ms).count()
#define durCastMin(ms) std::chrono::duration_cast<std::chrono::minutes>(ms).count()
#define durCastHour(ms) std::chrono::duration_cast<std::chrono::hours>(ms).count()

Blooper b;
Expansion e;
Flywheel fly;
Intake in;
Drive d;

pros::Task NONE([] {}); // Dummy task

pros::Task blooperT = NONE; // Blooper task
pros::Task expandT = NONE; // Expansion task
pros::Task flyT = NONE; // Flywheel task
pros::Task intakeT = NONE; // Intake task
pros::Task driveT = NONE; // Drive task

int aut = 0;
int timeV = 0;
uint32_t elapsed = 0;

// Main
void stopTasks() {
    blooperT.notify();
    flyT.notify();
    intakeT.notify();

    // Drive and Blooper are special
    d.override();
    b.setState(false);

    pistonIntake.set_value(false);
}

void startTasks() {
    controller.clear();
    pros::delay(110);

    pros::Task tm([] {
        char state = -1;
        std::vector<std::string> motors = {};
        
        // Expansion + Drive + Blooper (always running)
        expandT = pros::Task([] { while(true) { e.run(); pros::delay(10); } });
        driveT = pros::Task([] { while(true) { d.run(); pros::delay(10); } });
        blooperT = pros::Task([] { while(true) { b.run(); pros::delay(10); } });

        controller.setText(0, 0, autons[aut]);

        while (true) {
            if (pros::competition::get_status() != state) {
                stopTasks();

                printf("state changed to ");
                elapsed = pros::millis();

                switch (pros::competition::get_status()) {
                    case 0: // Run without competition switch
                        e.setUnlocked(true);
                        
                    case 4: // Driver, enabled
                        printf("driver (enabled)\n");
                        pros::lcd::clear();
                        flyT = pros::Task([] { while(!pros::Task::notify_take(true, 10)) { fly.run(); } fly.setState(false); });
                        intakeT = pros::Task([] { while(!pros::Task::notify_take(true, 10)) { in.run(); } in.setState(0); });
                    break;

                    case 6: // Auton, enabled
                        printf("auton (enabled)\n");
                        
                        flyT = pros::Task([] { while(!pros::Task::notify_take(true, 10)) { fly.run(); } fly.setTarget(1700); });
                        intakeT = pros::Task([] { while(!pros::Task::notify_take(true, 10)) { in.run(); } in.setState(0); });
                    break;

                    default: /*
                                (5) - Driver, disabled
                                (7) - Auton, disabled 
                             */
                            printf("default\n");
                    break;
                }
            }
            state = pros::competition::get_status();

            motors.clear();
            
            if (autonSelector.get_new_press()) {
                aut = ((aut + 1) >= numAutons) ? 0 : aut + 1;
                pros::delay(50);
                controller.rumble(".");
                pros::delay(50);
                controller.setText(0, 0, autons[aut]);
            }

            controller.setText(1, 0, "Battery at " + std::to_string((int) pros::battery::get_capacity()) + "%        ");

            if (flywheel.getTemperature() >= 48.0) motors.push_back("FW");
            if (intake.getTemperature() >= 50.0) motors.push_back("I");
            if (LD.getTemperature() >= 50.0 || RD.getTemperature() >= 50.0) motors.push_back("D");
            
            if (!motors.empty() && timeV < 100) controller.setText(2, 0, std::accumulate(motors.begin() + 1, motors.end(), motors[0], [](std::string x, std::string y) { return x + ", " + y; }) + " overheating     ");
            else if (timeV <= 200) { controller.setText(2, 0, ""); if (timeV == 200) { timeV = 0; } }
            // printf("%.3f, %.3f, %.3f, %d\n", LD.getTemperature(), RD.getTemperature(), pros::battery::get_capacity(), controller.getBatteryCapacity());

            pros::delay(10);
        }
    });
}

bool flyDone() { return fly.done(); }
bool driveDone() { return d.done(); }
bool inDone() { return in.done(); }

void autonWait(float timeout) {
    uint32_t start = pros::millis();
    while (!driveDone() || !flyDone() || !inDone()) {
        if ((pros::millis() - start) >= timeout) { d.override(); break; }
        pros::delay(10); 
    } 
}

void moveWait(float timeout) {
    uint32_t start = pros::millis();
    while (!driveDone()) {
        if ((pros::millis() - start) >= timeout) { d.override(); break; }
        pros::delay(10); 
    } 
}

// Blooper
void setBlooper(bool state) { b.setState(state); }

// Expansion
void setExpansionLock(bool state) { e.setUnlocked(state); }
void releaseExpansion() { e.release(); }

// Flywheel
void setFlywheelTarget(int target) { fly.setTarget(target); }
void setFlywheelState(bool state) { fly.setState(state); }
void setFlywheelInterpolation(bool state) { fly.setInterpolationState(state); }

// Intake
void setInSpeed(float n) { in.setState(n); }
void index(int n) { in.index(n); }

// Drive
void linearMove(float disp, float speed) { d.moveLinear(disp, speed); }
void turn(float degrees) { d.IMUTurn(degrees); }
void moveNTurn(float disp, float endAngle, float speed) { d.moveTurn(disp, endAngle, speed); }

// Odometry N/A