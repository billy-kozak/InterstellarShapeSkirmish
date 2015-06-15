#ifndef STARTSCREEN
#define STARTSCREEN

//extern Globals;


/**
 * This file implments and initializes the start screen for the game
 * When player 1 presses start, the start phase ends
 */
#include "global.h"
 //#include "includes.h"
 
 #define START_LOOP_DELAY_MS 100

/**
 * runs only once, puts an image on the start screen
 * used for background or permanant static images
 */
void initStartScreen(short int* pixelMap);

/**
 * goes true when the start button has been pressed on the first contoller
 */
int detectStart();

/**
 * gets rid of the start screen
 */
void eraseStart(short int* pixelMap);

#endif
