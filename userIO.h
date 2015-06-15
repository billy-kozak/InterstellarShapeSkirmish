/**
The header file for userIO.c which will recieve and interpret
data from the wireless controller
*/

#ifndef USERIO
#define USERIO

#using <System.dll>
//using namespace System;
using namespace System::Threading;

#include "PixelToaster.h"
using namespace PixelToaster;

#define ACCEL_SENSITIVITY 64
#define TASK_STACKSIZE 2048

#define CONTROLLER_X_DIVIDER 14
#define CONTROLLER_Y_DIVIDER 6

#define FIRE_MIN_TIME 5

#define CONTROLLER1_X_OFFSET 8
#define CONTROLLER1_Y_OFFSET 0
#define CONTROLLER1_Z_OFFSET 0

#define CONTROLLER2_X_OFFSET 6
#define CONTROLLER2_Y_OFFSET 0
#define CONTROLLER2_Z_OFFSET 0 

//Controller state struct
typedef struct {
    double roll;
    double pitch;
    short int fire;
    short int start;

	short int quit;
} ControllerState;

extern ControllerState controller1state;
extern ControllerState controller2state;

//OS_STK    controller1_stk[TASK_STACKSIZE];
//OS_STK    controller2_stk[TASK_STACKSIZE];

void controller1_task( System::Object ^ );
void controller2_task( System::Object ^ );


#endif
