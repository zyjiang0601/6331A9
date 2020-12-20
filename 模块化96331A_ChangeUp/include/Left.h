/*---------------------------------------------------------------------------*/
/*                                                                           */
/*       Important:    Description of automatic time period                  */
/*                                                                           */
/*     The goal in the corner is No.1 goal, the middle goal on               */
/*     the side is No.2 goal, and the goal in the middle of the              */
/*     field is No.3 goal.                          Ziyang Jiang             */
/*---------------------------------------------------------------------------*/
// Left
#pragma once
#include "robot.h"
#include "vex.h"

void Left1() {

  automove(-140, -330, 1800, 45, 60);
  automove(540, 540, 800, 50, 50);
  automove(350, 350, 500, 20, 20);
  up.shot();
  up.roll();
  wait(1000, msec);
  pause.shot();
  pause.roll();

  automove(-200, -200, 1000, 20, 20);
  automove(0, 0, 0, 0, 0);
}
void Left1and2() {
  //蓝右-红右-边中goal

  automove(-140, -330, 1800, 45, 60);
  automove(540, 540, 800, 50, 50);
  automove(350, 350, 500, 20, 20);
  up.shot();
  up.roll();
  wait(1000, msec);
  pause.shot();
  pause.roll();
  automove(-150, -360, 1800, 75, 80);
  automove(-1300, -900, 4000, 50, 50);
  automove(400, 400, 1800, 40, 40);
  up.shot();
  up.roll();
  wait(1000, msec);
  automove(-360, -360, 1000, 100, 100);
}

void Left1and3() {
  // 蓝右-红右-1号和3号goal
  //必须保证在1号goal处只放一个本队颜色球，剩下的一个需要放到3号goal

  automove(-170, -380, 2000, 75, 80);
  automove(540, 540, 1500, 50, 50);
  automove(350, 350, 400, 20, 20);
  up.shot();
  up.roll();
  wait(700, msec);
  pause.shot();
  pause.roll();
  automove(-550, -550, 1200, 20, 20);
  automove(-400, 400, 1200, 75, 75);

  automove(2000, 2000, 2500, 30, 30);

  up.shot();
  up.roll();
  wait(700, msec);
  pause.shot();
  pause.roll();
  automove(-200, -200, 500, 70, 70);
}
