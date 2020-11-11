//
//自动优先右场

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// DL1                  motor         18              
// XQ                   motor         9               
// LR                   motor         12              
// DR1                  motor         15              
// DR2                  motor         6               
// DL2                  motor         4               
// RR                   motor         11              
// S                    motor         7               
// Inertial16           inertial      16              
// bumper_              bumper        A               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
#include "Left.h"
#include "Right.h"
#include "robot.h"

using namespace vex;

competition Competition;
//================//
// Don't change the numbers here
int choose = 0;
//================//

void pre_auton(void) {
    // Initializing Robot Configuration. DO NOT REMOVE!
    vexcodeInit();
    
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*       Important:    Description of automatic time period                  */
/*                                                                           */
/*     The goal in the corner is No.1 goal, the middle goal on               */
/*     the side is No.2 goal, and the goal in the middle of the              */
/*     field is No.3 goal.                          Ziyang Jiang             */
/*---------------------------------------------------------------------------*/



void autonomous(void) {
    Brain.resetTimer();

    //choose = 4;
    switch (choose) {
        case 0:
            break;
        case 1:
            Left1();
            break;
        case 2:
            Right1();
            break;
        case 3:
            Left1and2();
            break;
        case 4:
            Right1and2();
            break;
        case 5:
            Left1and3();
            break;
        case 6:
            Right1and3();
            break;
        case 7:
            Right_super();
            break;
        case 8:
            Right_no_enemy_L();
            break;
        default:
            //robot::time.auto_default_print();
            break;

    }
    
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
void usercontrol(void) {
    // User control code here, inside the loop
    //###
    robot::time.setup();
    //###
    //Controller1.Screen.clearScreen();
    //###
    while (1) {
        
        wait(20, msec);
        int C1, C2, C3, C4, X, Y, A, B, U, D, L, R, L1, L2, R1, R2;
        
        C1 = Controller1.Axis1.position(percent);
        C2 = Controller1.Axis2.position(percent);
        C3 = Controller1.Axis3.position(percent);
        C4 = Controller1.Axis4.position(percent);
        X = Controller1.ButtonX.pressing();
        Y = Controller1.ButtonY.pressing();
        A = Controller1.ButtonA.pressing();
        B = Controller1.ButtonB.pressing();
        U = Controller1.ButtonUp.pressing();
        D = Controller1.ButtonDown.pressing();
        R = Controller1.ButtonRight.pressing();
        L = Controller1.ButtonLeft.pressing();
        L1 = Controller1.ButtonL1.pressing();
        L2 = Controller1.ButtonL2.pressing();
        R1 = Controller1.ButtonR1.pressing();
        R2 = Controller1.ButtonR2.pressing();
        
        int lv = C3 * 0.85 + C1 * 0.55;
        int rv = C3 * 0.85 - C1 * 0.55;
        if(!(R||L||Y||A)){
            //To disable/enable PID, change the namespace
           pid::move(lv,rv);
        }
        
        if (R1) {
           up.shot();
            
        } else if (R2) {
            
            down.shot();
            
        } else {
            pause.shot();

        }
        
        if (L1) {
            pid::up.roll();
        } else if (L2) {
            pid::down.roll();
        } else {
            pid::pause.roll();
        }
        
        //微调----------------------------------------------
        if (L || R || Y || A) {
            int microlv =8.5*C3;
            int microrv =8.5*C2;
            micromove(microlv, microrv);
            
        }
        //--------------------------------------------------
        //###
        robot::time.report();
        //###
    }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {

    static double time_to_choose = Brain.timer(vex::timeUnits::msec);
    while (1) {
        if (Brain.timer(vex::timeUnits::msec) - time_to_choose > 150) {
            if (bumper_.pressing()) {
                Brain.Screen.clearScreen();
                choose = choose % 8 + 1;
                time_to_choose = Brain.timer(vex::timeUnits::msec);
            }
           
        }
        switch (choose) {
            case 0:
                Brain.Screen.printAt(10, 80, "Automatic time period selection");
                Brain.Screen.printAt(10, 100, "Use the Bumper to select the program");
                Brain.Screen.printAt(68, 52, "<-----------");
                Brain.Screen.drawRectangle(20, 28, 20, 35); 
                Brain.Screen.setFillColor(red);
                Brain.Screen.drawRectangle(39, 35, 18, 24); 
                // Brain.Screen.drawLine(88, 35, 40, 3); 
                break;


            case 1:
                // Brain.Screen.clearScreen();
                Brain.Screen.setFillColor(black);
                Brain.Screen.drawCircle(80, 100, 20);
                Brain.Screen.setFillColor(black);
                Brain.Screen.printAt(10, 40, "Left 1");
                Brain.Screen.printAt(10, 80, "Goal in the corner");
                // Brain.Screen.printAt(10, 60, "After the code is written, we will tell you how to put the car");
                break;
            case 2:
                // Brain.Screen.clearScreen();
                Brain.Screen.setFillColor(black);
                Brain.Screen.drawCircle(80, 100, 20);
                Brain.Screen.setFillColor(black);
                Brain.Screen.printAt(10, 40, "Right 1");
                Brain.Screen.printAt(10, 80, "Goal in the corner");
                // Brain.Screen.printAt(10, 60, "After the code is written, we will tell you how to put the car");
                break;
            case 3:
                // Brain.Screen.clearScreen();
                Brain.Screen.setFillColor(black);
                Brain.Screen.drawCircle(80, 80, 20);
                Brain.Screen.drawCircle(135, 80, 20);
                Brain.Screen.setFillColor(black);
                Brain.Screen.printAt(10, 40, "Left 1 and 2");
                Brain.Screen.printAt(10, 80, "Corner and side");
                // Brain.Screen.printAt(10, 60, "After the code is written, we will tell you how to put the car");
                break;
            case 4:
                // Brain.Screen.clearScreen();
                Brain.Screen.setFillColor(black);
                Brain.Screen.drawCircle(80, 80, 20);
                Brain.Screen.drawCircle(135, 80, 20);
                Brain.Screen.setFillColor(black);
                Brain.Screen.printAt(10, 40, "Right 1 and 2");
                Brain.Screen.printAt(10, 80, "Corner and side");
                // Brain.Screen.printAt(10, 60, "After the code is written, we will tell you how to put the car");
                break;
                
            case 5:
                // Brain.Screen.clearScreen();
                Brain.Screen.setFillColor(black);
                Brain.Screen.drawCircle(80, 80, 20);
                Brain.Screen.drawCircle(135, 135, 20);
                Brain.Screen.setFillColor(black);
                Brain.Screen.printAt(10, 40, "Left 1 and 3");
                Brain.Screen.printAt(10, 80, "Corner and middle of field");
                // Brain.Screen.printAt(10, 60, "After the code is written, we will tell you how to put the car");
                break;
            case 6:
                // Brain.Screen.clearScreen();
                Brain.Screen.setFillColor(black);
                Brain.Screen.drawCircle(80, 80, 20);
                Brain.Screen.drawCircle(135, 135, 20);
                Brain.Screen.setFillColor(black);
                Brain.Screen.printAt(10, 40, "Right 1 and 3");
                Brain.Screen.printAt(10, 80, "Corner and middle of field");
                // Brain.Screen.printAt(10, 60, "After the code is written, we will tell you how to put the car");
                break;
            case 7:
                // Brain.Screen.clearScreen();
                Brain.Screen.setFillColor(black);
                Brain.Screen.drawCircle(80, 80, 20);
                Brain.Screen.drawCircle(135, 80, 20);
                Brain.Screen.drawCircle(190, 80, 20);
                Brain.Screen.setFillColor(black);
                Brain.Screen.printAt(10, 40, "Right \"Super!!!\" Must be placed on the right");
                Brain.Screen.printAt(10, 80, "home alliance");
                // Brain.Screen.printAt(10, 60, "After the code is written, we will tell you how to put the car");
                break;
            case 8:
                // Brain.Screen.clearScreen();
                Brain.Screen.setFillColor(black);
                Brain.Screen.drawRectangle(25, 25, 10, 35); 
                Brain.Screen.drawRectangle(25, 60, 20, 10); 
                Brain.Screen.setFillColor(black);
                Brain.Screen.printAt(10, 40, "Right NO ENEMY!!!");
                Brain.Screen.printAt(10, 80, "Shape L");
                // Brain.Screen.printAt(10, 60, "After the code is written, we will tell you how to put the car");
                break;
            default:
                // Brain.Screen.clearScreen();
                Brain.Screen.printAt(10, 40, "If this text appears, there is a BUG."); 
                Brain.Screen.setFillColor(red);      
                Brain.Screen.printAt(10, 60, "Tell the programmer the problem "); 
                Brain.Screen.printAt(10, 75, "or press the button several times");   
                Brain.Screen.printAt(10, 95, "Error: the MOD number is wrong");
                break;
   
        }
        Brain.Screen.printAt(10, 180, "HSEFZCZ, Shanghai");
        Brain.Screen.setFillColor(black);
        Brain.Screen.printAt(10, 205, "Team 96331A  ");
        Brain.Screen.setFillColor(black);
        Brain.Screen.printAt(10, 222, "3 Generation");
        
        
    }
    // Set up callbacks for autonomous and driver control periods.
    Competition.autonomous(autonomous);
    Competition.drivercontrol(usercontrol);
    
    // Run the pre-autonomous function.
    pre_auton();
    
    // Prevent main from exiting with an infinite loop.
    while (true) {
        wait(100, msec);
    }
}




