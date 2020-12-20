#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor DL1 = motor(PORT18, ratio18_1, false);
motor XQ = motor(PORT9, ratio18_1, true);
motor LR = motor(PORT12, ratio18_1, false);
motor DR1 = motor(PORT15, ratio18_1, true);
motor DR2 = motor(PORT21, ratio18_1, false);
motor DL2 = motor(PORT4, ratio18_1, true);
motor RR = motor(PORT11, ratio18_1, false);
motor S = motor(PORT7, ratio18_1, false);
inertial Inertial16 = inertial(PORT16);
bumper bumper_ = bumper(Brain.ThreeWirePort.A);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}