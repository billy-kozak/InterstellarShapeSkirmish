/**
This header file defines a list of AI routines for use on the enemy ships
*/
#ifndef AI
#define AI

#include "world.h"
#include <stdlib.h>

//SHIP DIRECTION MACROS
#define NONE 0
#define LEFT 1
#define RIGHT 2
#define UP 3
#define DOWN 4

/**
A test AI routine that will do literally nothing
*/
void testAI(ship* someShip,char** map,world gameWorld);

short int routine1(ship* someShip,world* gameWorld);
short int routine2(ship* someShip,world* gameWorld);
short int routine3(ship* someShip,world* gameWorld);
short int routine4(ship* someShip,world* gameWorld);
short int routine5(ship* someShip,world* gameWorld);
short int routine6(ship* someShip,world* gameWorld);

#endif
