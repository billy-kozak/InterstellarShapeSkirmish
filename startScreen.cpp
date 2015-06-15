#include "startScreen.h"
#include "userIO.h"
#include "graphics.h"
#include "fontGraphics.h"

#include "global.h"
using namespace Global; 

/**
 * runs only once, puts an image on the start screen
 * used for background or permanant static images
 */
void initStartScreen(short int* pixelMap){
    for(int i = 0; i < XRES*YRES; i++){
        pixelMap[i] = L;
    }
    int x = 140;
    int y = 180;
    short int * shape = shapeALPHA_P();
    drawALPHANUM(pixelMap, shape, x, y);
    shape = shapeALPHA_R();
    drawALPHANUM(pixelMap, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_E();
    drawALPHANUM(pixelMap, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_S();
    drawALPHANUM(pixelMap, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_S();
    drawALPHANUM(pixelMap, shape, x = x+DIMALPHANUM_X+1, y);
    
    x = x+DIMALPHANUM_X+1; // space
    
    shape = shapeALPHA_S();
    drawALPHANUM(pixelMap, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_T();
    drawALPHANUM(pixelMap, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_A();
    drawALPHANUM(pixelMap, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_R();
    drawALPHANUM(pixelMap, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_T();
    drawALPHANUM(pixelMap, shape, x = x+DIMALPHANUM_X+1, y);
    
    x = 95;
    y = 80;
    
    shape = shapeDIM6();
    draw15x15(pixelMap, shape, x = x, y);
    shape = shapeDIM2();
    draw15x15(pixelMap, shape, x = x+DIM4_X*2, y);
    shape = shapeDIM3();
    draw15x15(pixelMap, shape, x = x+DIM3_X*2, y);
    shape = shapeDIM5();
    draw15x15(pixelMap, shape, x = x+DIM5_X*2, y);
    shape = shapeDIM1();
    draw15x15(pixelMap, shape, x = x+DIM1_X*2, y);
    
    x = 101;
    y = 85;
    
    shape = shapeALPHA_S();
    drawALPHANUM(pixelMap, shape, x, y);
    shape = shapeALPHA_H();
    drawALPHANUM(pixelMap, shape, x = x+DIM1_X*2, y);
    shape = shapeALPHA_A();
    drawALPHANUM(pixelMap, shape, x = x+DIM1_X*2, y);
    shape = shapeALPHA_P();
    drawALPHANUM(pixelMap, shape, x = x+DIM1_X*2, y);
    shape = shapeALPHA_E();
    drawALPHANUM(pixelMap, shape, x = x+DIM1_X*2, y);
    
    x = 135;
    y = 70;
    
    shape = shapeALPHA_I();
    drawALPHANUM(pixelMap, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_N();
    drawALPHANUM(pixelMap, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_T();
    drawALPHANUM(pixelMap, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_E();
    drawALPHANUM(pixelMap, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_R();
    drawALPHANUM(pixelMap, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_S();
    drawALPHANUM(pixelMap, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_T();
    drawALPHANUM(pixelMap, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_E();
    drawALPHANUM(pixelMap, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_L();
    drawALPHANUM(pixelMap, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_L();
    drawALPHANUM(pixelMap, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_A();
    drawALPHANUM(pixelMap, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_R();
    drawALPHANUM(pixelMap, shape, x = x+DIMALPHANUM_X+1, y);
    
    x = 143;
    y = 100;
    
    shape = shapeALPHA_S();
    drawALPHANUM(pixelMap, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_K();
    drawALPHANUM(pixelMap, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_I();
    drawALPHANUM(pixelMap, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_R();
    drawALPHANUM(pixelMap, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_M();
    drawALPHANUM(pixelMap, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_I();
    drawALPHANUM(pixelMap, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_S();
    drawALPHANUM(pixelMap, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_H();
    drawALPHANUM(pixelMap, shape, x = x+DIMALPHANUM_X+1, y);
    
}

/**
 * goes true when the start button has been pressed on the first contoller
 */
int detectStart(){
    int output = 0;
    //INT8U err;
    //OSSemPend(controller1semaphore,0,&err);
	GlobalsEng::controller1semaphore->WaitOne();

        output = controller1state.start;
	GlobalsEng::controller1semaphore->Release();
    
    return output;
}

/**
 * gets rid of the start screen
 */
void eraseStart(short int* pixelMap){
    for(int i = 0; i < XRES*YRES; i++){
        pixelMap[i] = 0;
    }
}
