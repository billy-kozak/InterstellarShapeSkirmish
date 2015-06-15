#ifndef FONTGRAPHICS
#define FONTGRAPHICS

#include "world.h"
#include <stdlib.h>
#include "graphics.h"

#define SCORE_AREA_UPDATE_FREQUENCY 20//score area only ever allowed to update x ticks

typedef struct{
    int score;
    short int* pixels;
    short int update;//true if the score area needs an update
    short int p1health;
    short int p2health;
}scoreArea;

/**
 * returns a new score area object initialized according to the macros of graphics.h and world.h
 * top of frame is a pointer to the top of the temporary frame
 */
scoreArea initScoreArea(short int* topofframe);

/**
 * updates the scoreArea structure that scoreBar points to according to the gameWorld structure and
 * some internal logic
 */
void updateScoreArea(world gameWorld,scoreArea* scoreBar);

//FONT SHAPES
short int* shapeNUM_0();
short int* shapeNUM_1();
short int* shapeNUM_2();
short int* shapeNUM_3();
short int* shapeNUM_4();
short int* shapeNUM_5();
short int* shapeNUM_6();
short int* shapeNUM_7();
short int* shapeNUM_8();
short int* shapeNUM_9();

short int* shapeALPHA_S();
short int* shapeALPHA_C();
short int* shapeALPHA_O();
short int* shapeALPHA_R();
short int* shapeALPHA_E();
short int* shapeALPHA_P();
short int* shapeALPHA_T();
short int* shapeALPHA_A();
short int* shapeALPHA_H();
short int* shapeALPHA_L();
short int* shapeALPHA_I();
short int* shapeALPHA_G();
short int* shapeALPHA_M();
short int* shapeALPHA_V();
short int* shapeALPHA_Y();
short int* shapeALPHA_N();
short int* shapeALPHA_K();

short int* shapeALPHA_EXCLAMATION();
short int* shapeALPHA_COLON();

void drawALPHANUM(short int* array, short int* shape, int x, int y);

void printScore(int score, short int* array, int x, int y);
void eraseScore(short int* array, int x, int y);

void drawGAMEOVER(short int* array);
void drawVICTORY(short int* array, short int lastLevel);

#endif
