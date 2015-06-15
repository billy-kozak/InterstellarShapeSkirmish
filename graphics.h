/**
Header file for graphics.c which will interpret game data and handle VGA output
*/
#ifndef GRAPHICS
#define GRAPHICS

#include "world.h"
#include <stdlib.h>

#define XRES 320
#define YRES 240

#define SCORE_AREA_X 320
#define SCORE_AREA_Y 20

// SHIP DIMENSTION IDs
#define DIMID_1 1
#define DIM1_X  15
#define DIM1_Y  15

#define DIMID_2 2
#define DIM2_X  15
#define DIM2_Y  15

#define DIMID_3 3
#define DIM3_X  15
#define DIM3_Y  15

#define DIMID_4 4
#define DIM4_X  15
#define DIM4_Y  15

#define DIMID_5 5
#define DIM5_X  15
#define DIM5_Y  15

#define DIMID_6 6
#define DIM6_X  15
#define DIM6_Y  15

#define DIMID_7 7
#define DIM7_X  15
#define DIM7_Y  15

#define DIMID_8 8
#define DIM8_X  15
#define DIM8_Y  15

#define DIMP_X 2
#define DIMP_Y 2

#define DIMALPHANUM_Y 5
#define DIMALPHANUM_X 3

#define DIMSCORE_X 39
#define DIMSCORE_Y 5

#define P1_HEALTH_X 19
#define P2_HEALTH_X 241
#define HEALTH_Y 14

// QUICK-REFERENCE COLOR GUIDE
#define W 0xffff //WHITE
#define Z 0x0000 //BLACK
#define R 0x7c00 //RED
#define B 0x001f //BLUE
#define G 0x03e0 //GREEN

#define L 0x1f1f //LIGHT BLUE
#define F 0xaaaa //DARK GREEN "FOREST"
#define Y 0x7fe0 //YELLOW
#define P 0x7c1f //PINK
#define O 0xfe00 //ORANGE
#define V 0x3c0f //VIOLET
#define S 0x56b5 //SILVER
#define M 0x4654 //METAL

//FUNCTIONS
void drawDIM1(short int* array,ship ship);
short int* shapeDIM1(); //RED X
void eraseDIM1(short int* array, ship ship);

void drawDIM2(short int* array,ship ship);
short int* shapeDIM2(); //PINK DONUT
void eraseDIM2(short int* array, ship ship);

void drawDIM3(short int* array,ship ship);
short int* shapeDIM3(); //GREEN TRIANGLE
void eraseDIM3(short int* array, ship ship);

void drawDIM4(short int* array,ship ship);
short int* shapeDIM4(); //YELLOW SQUARE
void eraseDIM4(short int* array, ship ship);

void drawDIM5(short int* array,ship ship);
short int* shapeDIM5(); //ORANGE PLUS
void eraseDIM5(short int* array, ship ship);

void drawDIM6(short int* array,ship ship);
short int* shapeDIM6(); //BLUE DIAMOND
void eraseDIM6(short int* array, ship ship);

void drawDIM7(short int* array,ship ship);
short int* shapeUFO();
void eraseDIM7(short int* array, ship ship);

void drawDIM8(short int* array,ship ship);
short int* shapeROCKET();
void eraseDIM8(short int* array, ship ship);

void drawPROJ(short int* array, projectile proj);
short int* shapePROJ();
void erasePROJ(short int* array, projectile proj);

//Health bar shapes
short int* shapeHEALTH_G();
short int* shapeHEALTH_Y();
short int* shapeHEALTH_R();
short int* shapeHEALTH_Z();

//EXPLOSIONS AL 15X15
short int* shapeEXPLODE1();
short int* shapeEXPLODE2();
short int* shapeEXPLODE3();

void draw15x15(short int* array, short int* shape, int x, int y);

void printHEALTH(short int score, short int* array, int x, int y, int player);
void eraseHealth(short int* array, int x, int y);

#endif
