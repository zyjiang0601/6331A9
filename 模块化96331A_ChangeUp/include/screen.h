#pragma once
#include "vex.h"

namespace screentime {
int time0;
void set() { // can be only used once
  time0 = Brain.timer(vex::timeUnits::msec);
}

} // namespace screentime

namespace screen {

class time {
private:
  int timer0;
  int initial_sec, user_hour, user_min, user_sec;

public:
  class msec { // msec
  public:
    int get() {
      int time = Brain.timer(vex::timeUnits::msec);
      return time;
    }
  };
  msec msec;

  class sec { // sec
  public:
    int get() {
      int time = Brain.timer(vex::timeUnits::sec);
      return time;
    }
  };
  sec sec;

  void setup() { // can be only used once

    //        timer0=Brain.timer(vex::timeUnits::sec);
    //        screentime::set();
  }

  void report() {

    //        if((Brain.timer(vex::timeUnits::msec)-screentime::time0)>1000){
    //            initial_sec=Brain.timer(vex::timeUnits::sec)-timer0;
    //            user_hour=initial_sec/3600;
    //            user_min=initial_sec%3600/60;
    //            user_sec=initial_sec%60;
    //            Controller1.Screen.print("Time:
    //            %d(h)%d(min)%d(s)\n",user_hour,user_min,user_sec);
    //            screentime::time0=Brain.timer(vex::timeUnits::msec);
    //    }
  }

  void autoDefaultPrint() {
    Controller1.Screen.print("If this text appears, there is a bug");
  }
};
time time;
} // namespace screen

namespace print {
class autochoose {
public:
  void start() {
    Brain.Screen.printAt(10, 100, "Automatic time period selection"); // start
    Brain.Screen.printAt(10, 120, "Use the Bumper to select the program");
    Brain.Screen.printAt(10, 140,
                         "If you stay on this page, it will do nothing.");
    Brain.Screen.setFont(propM);
    Brain.Screen.printAt(100, 55, "<");
    Brain.Screen.printAt(113, 53, "--------Bumper--------");
    Brain.Screen.setFont(monoM);
    Brain.Screen.drawRectangle(20, 14, 40, 65);
    Brain.Screen.setFillColor(red);
    Brain.Screen.drawRectangle(59, 25, 28, 44);
  }

  void Left1() {
    Brain.Screen.setFillColor(black);
    Brain.Screen.drawCircle(340, 50, 20);
    Brain.Screen.setFillColor(black);
    Brain.Screen.printAt(10, 40, "Left 1");
    Brain.Screen.printAt(10, 80, "Goal in the corner");
  }
  void Right1() {
    Brain.Screen.setFillColor(black);
    Brain.Screen.drawCircle(340, 50, 20);
    Brain.Screen.setFillColor(black);
    Brain.Screen.printAt(10, 40, "Right 1");
    Brain.Screen.printAt(10, 80, "Goal in the corner");
  }

  void Left1and2() {
    Brain.Screen.setFillColor(black);
    Brain.Screen.drawCircle(340, 80, 20);
    Brain.Screen.drawCircle(410, 80, 20);
    Brain.Screen.setFillColor(black);
    Brain.Screen.printAt(10, 40, "Left 1 and 2");
    Brain.Screen.printAt(10, 80, "Corner and side");
  }
  void Right1and2() {
    Brain.Screen.setFillColor(black);
    Brain.Screen.drawCircle(340, 80, 20);
    Brain.Screen.drawCircle(410, 80, 20);
    Brain.Screen.setFillColor(black);
    Brain.Screen.printAt(10, 40, "Right 1 and 2");
    Brain.Screen.printAt(10, 80, "Corner and side");
  }
  void Left1and3() {
    Brain.Screen.setFillColor(black);
    Brain.Screen.drawCircle(340, 135, 20);
    Brain.Screen.drawCircle(410, 80, 20);
    Brain.Screen.setFillColor(black);
    Brain.Screen.printAt(10, 40, "Left 1 and 3");
    Brain.Screen.printAt(10, 80, "Corner and middle of field");
  }
  void Right1and3() {
    Brain.Screen.setFillColor(black);
    Brain.Screen.drawCircle(340, 80, 20);
    Brain.Screen.drawCircle(410, 135, 20);
    Brain.Screen.setFillColor(black);
    Brain.Screen.printAt(10, 40, "Right 1 and 3");
    Brain.Screen.printAt(10, 80, "Corner and middle of field");
  }
  void threeGoals() {
    Brain.Screen.setFillColor(black);
    Brain.Screen.drawCircle(260, 80, 20);
    Brain.Screen.drawCircle(320, 80, 20);
    Brain.Screen.drawCircle(380, 80, 20);
    Brain.Screen.setFillColor(black);
    Brain.Screen.printAt(10, 40, "3 Goals,Must be placed on the right");
    Brain.Screen.printAt(10, 80, "home alliance");
  }
  void shapeL() {
    Brain.Screen.setFillColor(black);
    Brain.Screen.drawRectangle(285, 25, 20, 65);
    Brain.Screen.drawRectangle(285, 85, 50, 25);
    Brain.Screen.setFillColor(black);
    Brain.Screen.printAt(10, 40, "Right shape\" L \"");
    Brain.Screen.printAt(10, 80, "Shape L");
    Brain.Screen.printAt(5, 130,
                         "This program has been checked by Jiang Ziyang ");
    Brain.Screen.printAt(5, 150, "and found to be wrong and has been banned");
  }
  void bugReport() {
    Brain.Screen.printAt(10, 40, "If this text appears, there is a BUG.");
    Brain.Screen.setFillColor(red);
    Brain.Screen.printAt(10, 60, "Tell the programmer the problem ");
    Brain.Screen.printAt(10, 75, "or press the button several times");
    Brain.Screen.printAt(10, 95, "Error: the MOD number is wrong");
  }
};
autochoose autochoose;

} // namespace print