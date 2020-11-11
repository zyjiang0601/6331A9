/*---------------------------------------------------------------------------*/
/*                                                                           */
/*       Important:    Description of automatic time period                  */
/*                                                                           */
/*     The goal in the corner is No.1 goal, the middle goal on               */
/*     the side is No.2 goal, and the goal in the middle of the              */
/*     field is No.3 goal.                          Ziyang Jiang             */
/*---------------------------------------------------------------------------*/
//Right
#pragma once
#include "vex.h"
#include "robot.h"

void Right1(){
// 蓝右-红右-仅1goal
  
  automove(-300,-140,950,60,45);
  automove(540,540,800,50,50);
  automove(350,350,500,20,20);
  up.shot();
  up.roll();
  wait(700,msec);
  automove(-200,-200,1000,20,20);
  automove(0,0,0,0,0);
}
void Right1and2(){
//蓝右-红右-边中goal
  up.shot();
  wait(500,msec);;
  pause.shot();
  automove(-300,-140,950,60,45);
  automove(540,540,800,50,50);
  automove(350,350,500,20,20);
  up.shot();
  up.roll();
  wait(1300,msec);
  pause.shot();
  pause.roll();
  automove(-380,-170,950,80,75);
  automove(-900,-1300,3000,50,50);
  automove(800,800,1500,40,40);
  up.shot();
  up.roll();
  wait(1000,msec);
  automove(-360,-360,1000,100,100);
  
}

void Right1and3(){
// 蓝右-红右-1号和3号goal
//必须保证在1号goal处只放一个本队颜色球，剩下的一个需要放到3号goal

  automove(-380,-170,2000,80,75);
  automove(540,540,1500,50,50);
  automove(350,350,400,20,20);
  up.shot();
  up.roll();
  wait(700,msec);
  pause.shot();
  pause.roll();
  automove(-550,-550,800,20,20);
  automove(355,-355,900,75,75);
  automove(2000,2000,2000,90,90);
  
  up.shot();
  up.roll();
  wait(900,msec);
  pause.shot();
  pause.roll();
  automove(-200,-200,500,70,70);
  
}

void Right_super(){
  // up.shot();
  // wait(70,msec);  
  pause.shot();
  automove(-340,-140,950,60,45);

  automove(540,540,800,50,50);
  up.roll();
  automove(350,350,500,20,20);
  up.shot();

  wait(1100,msec);
  pause.shot();
  pause.roll();
  automove(-380,-170,950,80,75);
  automove(-900,-1300,3000,50,50);
 
  automove(600,600,1000,50,50);
   up.shot();
  up.roll();
  wait(1000,msec);

  pause.shot();
  pause.roll();
  automove(-360,-360,1000,100,100);

  automove(163,-163,1200,40,40);//160
  automove(1500,1500,3000,60,60);
  up.shot();
  up.roll();
  wait(1300,msec);
  automove(-350,-350,400,80,80);
  pause.shot();
  pause.roll();
}
void Right_no_enemy_L()
{
  automove(-300,-140,950,60,45);
  automove(540,540,800,50,50);
  automove(350,350,500,20,20);
  up.shot();
  up.roll();
  wait(700,msec);
  pause.shot();
  pause.roll();
  automove(-380,-170,950,80,75);
  automove(-900,-1300,3000,50,50);
  automove(800,800,1500,40,40);
  up.shot();
  up.roll();
  wait(800,msec);
  automove(-470,-470,1000,100,100);
  automove(-385,385,1300,50,50);
  automove(400,400,1200,60,60);
  up.shot();
  up.roll();
  automove(300,300,700,1000,1000);
  pause.shot();
  pause.roll();
  automove(300,300,400,1000,1000);
 

  
}



