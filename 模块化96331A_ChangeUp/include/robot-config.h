using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor DL1;
extern motor XQ;
extern motor LR;
extern motor DR1;
extern motor DR2;
extern motor DL2;
extern motor RR;
extern motor S;
extern inertial Inertial16;
extern bumper bumper_;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );