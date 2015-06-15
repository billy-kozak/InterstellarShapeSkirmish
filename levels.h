#ifndef LEVELS
#define LEVELS

#include "world.h"

// ***** EACH PATTERN HAS ***12*** SHIPS UNLESS OTHERWISE NOTED BELOW ***** //
short int makePattern1(world gameWorld, short int shipIndex, short int shipTime); //STRAIGHT LINES
short int makePattern2(world gameWorld, short int shipIndex, short int shipTime); //SPACE INVADERS
short int makePattern3(world gameWorld, short int shipIndex, short int shipTime); //BOUNCERS
short int makePattern4(world gameWorld, short int shipIndex, short int shipTime); //BOUNCERS, not from corners
short int makePattern5(world gameWorld, short int shipIndex, short int shipTime); //snakey movers
short int makeBoss1(world gameWorld, short int shipIndex, short int shipTime); //Chain of bouncers enter from same position ****** 10 ships *****

short int makePattern6(world gameWorld, short int shipIndex, short int shipTime); //3 chains of 4 snakes tightly attached
short int makeBoss2(world gameWorld, short int shipIndex, short int shipTime); //line of bouncers enter from topleft, topright

short int makePattern7(world gameWorld, short int shipIndex, short int shipTime); //like pattern 7, but chains spread out
short int makeBoss3(world gameWorld, short int shipIndex, short int shipTime); //space invader X of Xs ***** 9 ships *****

#endif /*LEVELS_H_*/
