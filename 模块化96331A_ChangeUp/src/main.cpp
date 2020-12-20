// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller                    
// DL1                  motor         18              
// XQ                   motor         9               
// LR                   motor         12              
// DR1                  motor         15              
// DR2                  motor         21              
// DL2                  motor         4               
// RR                   motor         11              
// S                    motor         7               
// Inertial16           inertial      16              
// bumper_              bumper        A               
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "Left.h"
#include "Right.h"
#include "robot.h"
#include "screen.h"
#include "vex.h"

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

  choose = 4;
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
    Right_threeGoals();
    break;
  case 8:
    // Right_no_enemy_L();
    break;
  default:
    // screen::time.autoDefaultPrint();
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
  screen::time.setup();
  //###
  // Controller1.Screen.clearScreen();
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
    if (!(R || L || Y || A)) {
      // To disable/enable PID, change the namespace
      pid::move(lv,rv);
    }

    if (R1) {
      shot.up();

    } else if (R2) {

      shot.down();

    } else {
      shot.pause();
    }

    if (L1) {
      up.roll();
    } else if (L2) {
      down.roll();
    } else {
      pause.roll();
    }

    //微调----------------------------------------------
    if (L || R || Y || A) {
      int microlv = 9 * C3;
      int microrv = 9 * C2;
      micromove(microlv, microrv);
    }
    //--------------------------------------------------
    //###
    // screen::time.report();
    //###
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {

  static double time_to_choose = Brain.timer(vex::timeUnits::msec);
  while (1) {
    if (Brain.timer(vex::timeUnits::msec) - time_to_choose > 175) {
      if (bumper_.pressing()) {
        Brain.Screen.clearScreen();
        choose = choose % 8 + 1;
        time_to_choose = Brain.timer(vex::timeUnits::msec);
      }
    }
    switch (choose) {
    case 0:
      print::autochoose.start();
      break;
    case 1:
      print::autochoose.Left1();
      break;
    case 2:
      print::autochoose.Right1();
      break;
    case 3:
      print::autochoose.Left1and2();
      break;
    case 4:
      print::autochoose.Right1and2();
      break;
    case 5:
      print::autochoose.Left1and3();
      break;
    case 6:
      print::autochoose.Right1and3();
      break;
    case 7:
      print::autochoose.threeGoals();
      break;
    case 8:
      print::autochoose.shapeL();
      break;
    default:
      print::autochoose.bugReport();
      break;
    }
    Brain.Screen.printAt(10, 180, "HSEFZCZ, Shanghai");
    Brain.Screen.setFillColor(black);
    Brain.Screen.printAt(10, 205, "VRC");
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
