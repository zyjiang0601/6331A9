/*---------------------------------------------------------------------------*/
/*                                                                           */
/*       Important:    Description of automatic time period                  */
/*                                                                           */
/*     The goal in the corner is No.1 goal, the middle goal on               */
/*     the side is No.2 goal, and the goal in the middle of the              */
/*     field is No.3 goal.                          Ziyang Jiang             */
/*---------------------------------------------------------------------------*/
// Right
#pragma once
#include "robot.h"
#include "vex.h"

void Right1() {
  // 蓝右-红右-仅1goal
  up.shot();
  up.roll();
  wait(130, msec);
  pause.shot();
  pause.roll();
  //-------------
  automove(-355, -150, 1000, 60, 45);
  automove(540, 540, 800, 50, 50);
  automove(350, 350, 600, 20, 20);
  up.shot();
  up.roll();
  wait(700, msec);
  // down.shot();
  // wait(110,msec);
  pause.shot();
  pause.roll();
  automove(-200, -200, 950, 80, 80);
}
void Right1and2() {

  up.shot();
  up.roll();
  wait(120, msec);
  pause.shot();
  pause.roll();
automove(25,25,200,30,30);
  automove(-375, -165, 1000, 60, 45);
  automove(540, 540, 800, 50, 50);
  automove(350, 350, 750, 20, 20);
  up.shot();
  up.roll();
  wait(1000, msec);
  down.shot();
  wait(300,msec);
  pause.shot();
  pause.roll();
  wait(400,msec);
  automove(-405, -210, 950, 80, 70);

  automove(-1000, -1000, 2000, 60, 60);
  automove(225, -225, 600, 40, 40);
  automove(420, 420, 650, 30, 30);
  shot.up();
  up.roll();
  wait(1300, msec);
  down.shot();
  wait(250,msec);
  pause.shot();
  pause.roll();

  automove(-600, -600, 800, 70, 70);
  // //蓝右-红右-边中goal
  //   up.shot();
  //   wait(500,msec);;
  //   pause.shot();
  //   automove(-300,-140,950,60,45);
  //   automove(540,540,800,50,50);
  //   automove(350,350,500,20,20);
  //   up.shot();
  //   up.roll();
  //   wait(1300,msec);
  //   pause.shot();
  //   pause.roll();
  //   automove(-380,-170,950,80,75);
  //   automove(-900,-1300,3000,50,50);
  //   automove(800,800,1500,40,40);
  //   up.shot();
  //   up.roll();
  //   wait(1000,msec);
  //   automove(-360,-360,1000,100,100);
}

void Right1and3() {
  // 蓝右-红右-1号和3号goal
  //必须保证在1号goal处只放一个本队颜色球，剩下的一个需要放到3号goal

  automove(-380, -170, 2000, 80, 75);
  automove(540, 540, 1500, 50, 50);
  automove(350, 350, 400, 20, 20);
  up.shot();
  up.roll();
  wait(700, msec);
  pause.shot();
  pause.roll();
  automove(-550, -550, 800, 20, 20);
  automove(355, -355, 900, 75, 75);
  automove(2000, 2000, 2000, 90, 90);

  up.shot();
  up.roll();
  wait(900, msec);
  pause.shot();
  pause.roll();
  automove(-200, -200, 500, 70, 70);
}

void Right_threeGoals() {
  /*up.shot();
  up.roll();
  wait(130, msec);
  pause.shot();
  pause.roll();

  automove(-355, -150, 1000, 60, 45);
  automove(540, 540, 800, 50, 50);
  automove(350, 350, 600, 20, 20);
  up.shot();
  up.roll();
  wait(700, msec);
  pause.shot();
  pause.roll();
  automove(-430, -210, 950, 80, 75);

  automove(-1000, -1000, 2000, 60, 60);
  automove(210, -210, 600, 40, 40);
  automove(400, 400, 550, 30, 30);
  shot.up();
  up.roll();
  wait(900, msec);
  down.shot();
  wait(380, msec);//
  pause.shot();
  pause.roll();*/
  up.shot();
  up.roll();
  wait(130, msec);
  pause.shot();
  pause.roll();

  automove(-355, -150, 1000, 60, 45);
  automove(540, 540, 800, 50, 50);
  automove(350, 350, 600, 20, 20);
  up.shot();
  up.roll();
  wait(950, msec);


  pause.shot();
  pause.roll();
  automove(-430, -210, 950, 80, 75);

  automove(-1000, -1000, 2000, 60, 60);
  automove(210, -210, 600, 40, 40);
  automove(420, 420, 550, 30, 30);
  shot.up();
  up.roll();
  wait(945, msec);
  down.shot();
  wait(180, msec);
  pause.shot();
  pause.roll();
  automove(-650, -650, 800, 70, 70);
  automove(290, -290, 1300, 30, 30);
  automove(375, 375, 1300, 40, 40);
  automove(-90, 90, 600, 50, 50);
  automove(1200, 1200, 1200, 80, 80);
  shot.up();
  up.roll();
  wait(950, msec);//
  //------
  pause.roll();
  pause.shot();
  automove(500, 500, 1000, 100, 100);////--to

}
