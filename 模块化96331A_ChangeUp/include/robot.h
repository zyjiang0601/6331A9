#pragma once
#include "vex.h"
#include "parameter.h"

//---------------------------------------------

namespace pid{
void setPID(double pp, double pi,double pd);
void moving();
void set_speed(double leftSpeed, double rightSpeed);
void data_update();
void move(double leftS, double rightS);



class PID {
private:
    double last_data;
    double now_data;
    double I_data;
    double P,I,D;
    double goal;
    
public:
    void data_in(double Data)
    {
        last_data=now_data;
        now_data=Data;
        I_data+=goal-now_data;
    }
    void set_goal(double goal_speed)
    {
        goal=goal_speed;
    }
    double data_out()
    {
        return now_data+P*(goal-now_data)+I*I_data-D*(now_data-last_data);
    }
    
    PID(double P_in,double I_in,double D_in)
    {
        P=P_in;
        I=I_in;
        D=D_in;
    }
};


PID Left=PID(left_p,left_i,left_d);
//PID Left2=PID(left_p,left_i,left_d);
PID Right=PID(right_p,right_i,right_d);
//PID Right2=PID(right_p,right_i,right_d);
PID LeftRoller=PID(roll_p,roll_i,roll_d);
PID RightRoller=PID(roll_p,roll_i,roll_d);
PID Ball=PID(roll_p,roll_i,roll_d);
PID Shot=PID(shot_p,shot_i,shot_d);



void data_update()
{
    Left.data_in((DL1.velocity(percent)+DL2.velocity(percent))/2);
    //Left2.data_in(DL2.velocity(percent));
    Right.data_in((DR1.velocity(percent)+DR2.velocity(percent))/2);
    //Right2.data_in(DR2.velocity(percent));
    
}
void set_speed(double leftSpeed, double rightSpeed){
    Left.set_goal(leftSpeed);
    //Left2.set_goal(leftSpeed);
    Right.set_goal(rightSpeed);
    //Right2.set_goal(rightSpeed);
}

void moving()
{
    DL1.spin(forward,Left.data_out(),pct);
    DL2.spin(forward,Left.data_out(),pct);
    //DL2.spin(forward,Left2.data_out(),pct);
    DR1.spin(forward,Right.data_out(),pct);
    DR2.spin(forward,Right.data_out(),pct);
    //DR2.spin(forward,Right2.data_out(),pct);
}

void move(double leftS, double rightS)
{
    set_speed(leftS,rightS);
    data_update();
    moving();
}

//////////

void roll_dataupdate(){
    LeftRoller.data_in(LR.velocity(percent));
    RightRoller.data_in(RR.velocity(percent));
    Ball.data_in(XQ.velocity(percent));
}
void roll_setspeed(double Speed){//请注意:RR在设置中没有reverse.故我会在此处对其的数据进行相反数运算.
    LeftRoller.set_goal(Speed);
    RightRoller.set_goal(-(Speed));
    Ball.set_goal(Speed);
    
}
void roll_moving()
{
    LR.spin(forward,LeftRoller.data_out(),pct);
    RR.spin(forward,RightRoller.data_out(),pct);
    XQ.spin(forward,Ball.data_out(),pct);
    
}

//////////

void shot_dataupdate(){
    Shot.data_in(S.velocity(percent));
}
void shot_setspeed(double Speed){//请注意:Shot在设置中没有reverse.故我会在此处对其的数据进行相反数运算.
    Shot.set_goal(-(Speed));
    
}
void shot_moving()
{
    S.spin(forward,Shot.data_out(),pct);
}
//---------------------------------------------
//This is inside namespace PID
class up{
public:
    
    void roll()//roll_up
    {
        roll_setspeed(100);
        roll_dataupdate();
        roll_moving();
    }
    
    void shot()//shot_up
    {
        
        shot_setspeed(100);
        shot_dataupdate();
        shot_moving();
        
    }
    
    
    
};
up up;


class down{
public:
    void roll()//roll_down
    {
        roll_setspeed(-100);
        roll_dataupdate();
        roll_moving();
    }
    
    void shot()//shot_down
    {
        shot_setspeed(-100);
        shot_dataupdate();
        shot_moving();
        
    }
    
    
};
down down;

class pause{
public:
    void roll()  //roll_s
    {
        roll_setspeed(0);
        roll_dataupdate();
        roll_moving();
    }
    
    void shot()  //shot_s
    {
        shot_setspeed(0);
        shot_dataupdate();
        shot_moving();
        
    }
    
};
pause pause;


}// namespace "PID"end------

//---------------------------------------------
//This is outside namespace PID


class up{
public:
    
    void roll()//roll_up
    {
        LR.setVelocity(100,percent);
        LR.spin(forward);
        RR.setVelocity(100,percent);
        RR.spin(reverse);
        XQ.setVelocity(100,percent);
        XQ.spin(forward);
    }
    
    void shot()//shot_up
    {
        
        S.setVelocity(100,percent);
        S.spin(reverse);
        
    }
    
    
    
};
up up;

//---------------------------------------------



class down{
public:
    void roll()//roll_down
    {
        LR.setVelocity(100,percent);
        LR.spin(reverse);
        RR.setVelocity(100,percent);
        RR.spin(forward);
        XQ.setVelocity(100,percent);
        XQ.spin(reverse);
    }
    
    void shot()//shot_down
    {
        S.setVelocity(100,percent);
        S.spin(forward);
        
    }
    
    
};
down down;

//---------------------------------------------


class pause{
public:
    void roll()  //roll_s
    {
        LR.stop(hold);
        LR.setStopping(brake);
        RR.stop(hold);
        RR.setStopping(brake);
        XQ.setVelocity(0,percent);
        XQ.spin(reverse);
    }
    
    void shot()  //shot_s
    {
        S.stop(hold);
        S.setStopping(brake);
        
    }
    
};
pause pause;


//---------------------------------------------

namespace move{

void move(int leftv,int rightv)
{
    DL1.spin(forward,leftv,pct);
    DL2.spin(forward,leftv,pct);
    DR1.spin(forward,rightv,pct);
    DR2.spin(forward,rightv,pct);
}

}

//---------------------------------------------


void micromove(float leftv, float rightv){
    DL1.spin(forward,leftv*0.1,pct);
    DL2.spin(forward,leftv*0.1,pct);
    DR1.spin(forward,rightv*0.1,pct);
    DR2.spin(forward,rightv*0.1,pct);
}
void automove(double left,double right,double time,double left_speed,double right_speed){
    DL1.startSpinFor(forward,left,deg,left_speed,velocityUnits::pct);
    DL2.startSpinFor(forward,left,deg,left_speed,velocityUnits::pct);
    DR1.startSpinFor(forward,right,deg,right_speed,velocityUnits::pct);
    DR2.startSpinFor(forward,right,deg,right_speed,velocityUnits::pct);
    wait(time,msec);
}

//---------------------------------------------
namespace robottime{
int time0;
void set(){// can be only used once
    time0=Brain.timer(vex::timeUnits::msec);
}


}

//---------------------------------------------

namespace robot{

class time{
private:
    int timer0;
    int initial_sec, user_hour, user_min, user_sec;
    
public:
    class msec{// msec
    public:
        int get(){
            int time=Brain.timer(vex::timeUnits::msec);
            return time;
        }
    };
    msec msec;
    
    
    class sec{// sec
    public:
        int get(){
            int time=Brain.timer(vex::timeUnits::sec);
            return time;
        }
    };
    sec sec;
    
    void setup(){ // can be only used once
        
        //        timer0=Brain.timer(vex::timeUnits::sec);
        //        robottime::set();
    }
    
    void report(){
        
        //        if((Brain.timer(vex::timeUnits::msec)-robottime::time0)>1000){
        //            initial_sec=Brain.timer(vex::timeUnits::sec)-timer0;
        //            user_hour=initial_sec/3600;
        //            user_min=initial_sec%3600/60;
        //            user_sec=initial_sec%60;
        //            Controller1.Screen.print("Time: %d(h)%d(min)%d(s)\n",user_hour,user_min,user_sec);
        //            robottime::time0=Brain.timer(vex::timeUnits::msec);
        //    }
    }
    
    
    void auto_default_print(){
        Controller1.Screen.print("If this text appears, there is a bug");
    }
    
};
time time;

}


