#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "levels.h"
#include "world.h"
#include "initialization.h"
#include "AI.h"
#include "graphics.h"
#include "moveCollide.h"

/**
 * Pattern which initializes 12 ships using AI routine 1 (a straight line trajectory)
 * Ships enter the screen individually, but in 2 groups of 6 with a longer space in between the 2 groups
 */
short int makePattern1(world gameWorld, short int shipIndex, short int shipTime)
{
    ship* thisShip = NULL;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 1;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = UP;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 1;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM1;
    thisShip->erase = eraseDIM1;
    thisShip->drawID = collideDIM1;    
    thisShip->AI_routine = routine1;
    
    shipIndex++;
    shipTime += 40;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 60;
    thisShip->y_pos = 0;
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = DOWN;
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 3;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->AI_routine = routine1;
    thisShip->drawPixels =  drawDIM3;
    thisShip->erase = eraseDIM3;
    thisShip->drawID = collideDIM3;
    
    shipIndex++;
    shipTime += 40;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 200;
    thisShip->y_pos = 0;
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = DOWN;
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 2;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->AI_routine = routine1;
    thisShip->drawPixels =  drawDIM2;
    thisShip->erase = eraseDIM2;
    thisShip->drawID = collideDIM2;
    
    shipIndex++;
    shipTime += 40;
     
    thisShip = &gameWorld.shipList[shipIndex];;
    thisShip->x_pos = 150;
    thisShip->y_pos = 0;
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = DOWN;
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 5;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->AI_routine = routine1;
    thisShip->drawPixels =  drawDIM1;
    thisShip->erase = eraseDIM1;
    thisShip->drawID = collideDIM1;
    
    shipIndex++;
    shipTime += 40;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 90;
    thisShip->y_pos = 0;
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = DOWN;
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 4;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->AI_routine = routine1;
    thisShip->drawPixels =  drawDIM3;
    thisShip->erase = eraseDIM3;
    thisShip->drawID = collideDIM3;
    
    shipIndex++;
    shipTime += 40;
     
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 280;
    thisShip->y_pos = 0;
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = DOWN;
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 6;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->AI_routine = routine1;
    thisShip->drawPixels =  drawDIM6;
    thisShip->erase = eraseDIM6;
    thisShip->drawID = collideDIM6;
    
    shipIndex++;
    shipTime += 120;
     
     //coming in from the right
     
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 180;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = UP;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 4;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM4;
    thisShip->erase = eraseDIM4;
    thisShip->drawID = collideDIM4;    
    thisShip->AI_routine = routine1;
    
    shipIndex++;
    shipTime += 40;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 300;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = UP;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 5;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM5;
    thisShip->erase = eraseDIM5;
    thisShip->drawID = collideDIM5;    
    thisShip->AI_routine = routine1;
    
    shipIndex++;
    shipTime += 40;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 60;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = UP;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 2;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM2;
    thisShip->erase = eraseDIM2;
    thisShip->drawID = collideDIM2;    
    thisShip->AI_routine = routine1;
    
    shipIndex++;
    shipTime += 40;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 1;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = UP;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 4;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM4;
    thisShip->erase = eraseDIM4;
    thisShip->drawID = collideDIM4;    
    thisShip->AI_routine = routine1;
    
    shipIndex++;
    shipTime += 40;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 100;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = UP;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 5;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM5;
    thisShip->erase = eraseDIM5;
    thisShip->drawID = collideDIM5;    
    thisShip->AI_routine = routine1;
    
    shipIndex++;
    shipTime += 40;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 230;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = UP;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 6;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM6;
    thisShip->erase = eraseDIM6;
    thisShip->drawID = collideDIM6;    
    thisShip->AI_routine = routine1;
    
    shipIndex++;
    
    return shipIndex;
}

/**
 * SPACE INVADER themed pattern. again, 12 ships total, alternating the side from which they enter
 */
short int makePattern2(world gameWorld, short int shipIndex, short int shipTime)
{
    ship* thisShip = NULL;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 1;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = UP;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 1;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM1;
    thisShip->erase = eraseDIM1;
    thisShip->drawID = collideDIM1;    
    thisShip->AI_routine = routine3;
    
    shipIndex++;
    shipTime += 40;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = XRES - DIM1_X-1;
    thisShip->y_pos = 15;
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = DOWN;
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 3;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->AI_routine = routine3;
    thisShip->drawPixels =  drawDIM3;
    thisShip->erase = eraseDIM3;
    thisShip->drawID = collideDIM3;
    
    shipIndex++;
    shipTime += 40;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 1;
    thisShip->y_pos = 0;
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = DOWN;
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 2;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->AI_routine = routine3;
    thisShip->drawPixels =  drawDIM2;
    thisShip->erase = eraseDIM2;
    thisShip->drawID = collideDIM2;
    
    shipIndex++;
    shipTime += 40;
     
    thisShip = &gameWorld.shipList[shipIndex];;
    thisShip->x_pos = XRES - DIM1_X-1;
    thisShip->y_pos = 15;
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = DOWN;
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 5;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->AI_routine = routine3;
    thisShip->drawPixels =  drawDIM1;
    thisShip->erase = eraseDIM1;
    thisShip->drawID = collideDIM1;
    
    shipIndex++;
    shipTime += 40;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 1;
    thisShip->y_pos = 0;
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = DOWN;
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 4;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->AI_routine = routine3;
    thisShip->drawPixels =  drawDIM3;
    thisShip->erase = eraseDIM3;
    thisShip->drawID = collideDIM3;
    
    shipIndex++;
    shipTime += 40;
     
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = XRES - DIM1_X-1;
    thisShip->y_pos = 15;
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = DOWN;
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 6;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->AI_routine = routine3;
    thisShip->drawPixels =  drawDIM6;
    thisShip->erase = eraseDIM6;
    thisShip->drawID = collideDIM6;
    
    shipIndex++;
    shipTime += 240;
     
     //coming in from the right
     
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = XRES - DIM1_X-1;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = UP;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 4;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM4;
    thisShip->erase = eraseDIM4;
    thisShip->drawID = collideDIM4;    
    thisShip->AI_routine = routine3;
    
    shipIndex++;
    shipTime += 40;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 1;
    thisShip->y_pos = 15;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = UP;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 5;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM5;
    thisShip->erase = eraseDIM5;
    thisShip->drawID = collideDIM5;    
    thisShip->AI_routine = routine3;
    
    shipIndex++;
    shipTime += 40;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = XRES - DIM1_X-1;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = UP;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 2;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM2;
    thisShip->erase = eraseDIM2;
    thisShip->drawID = collideDIM2;    
    thisShip->AI_routine = routine3;
    
    shipIndex++;
    shipTime += 40;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 1;
    thisShip->y_pos = 15;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = UP;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 4;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM4;
    thisShip->erase = eraseDIM4;
    thisShip->drawID = collideDIM4;    
    thisShip->AI_routine = routine3;
    
    shipIndex++;
    shipTime += 40;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = XRES - DIM1_X-1;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = UP;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 5;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM5;
    thisShip->erase = eraseDIM5;
    thisShip->drawID = collideDIM5;    
    thisShip->AI_routine = routine3;
    
    shipIndex++;
    shipTime += 40;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 1;
    thisShip->y_pos = 15;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = UP;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 6;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM6;
    thisShip->erase = eraseDIM6;
    thisShip->drawID = collideDIM6;    
    thisShip->AI_routine = routine3;
    
    shipIndex++;
    
    return shipIndex;
}

/**
 * ENEMIES BOUNCE OF BOUNDARIES. again, 12 ships total, alternating the side from which they enter
 */
short int makePattern3(world gameWorld, short int shipIndex, short int shipTime)
{
    ship* thisShip = NULL;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 1;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = UP;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 1;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM1;
    thisShip->erase = eraseDIM1;
    thisShip->drawID = collideDIM1;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    shipTime += 40;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = XRES - DIM1_X-1;
    thisShip->y_pos = 15;
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = DOWN;
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 3;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->AI_routine = routine4;
    thisShip->drawPixels =  drawDIM3;
    thisShip->erase = eraseDIM3;
    thisShip->drawID = collideDIM3;
    
    shipIndex++;
    shipTime += 40;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 1;
    thisShip->y_pos = 0;
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = DOWN;
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 2;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->AI_routine = routine4;
    thisShip->drawPixels =  drawDIM2;
    thisShip->erase = eraseDIM2;
    thisShip->drawID = collideDIM2;
    
    shipIndex++;
    shipTime += 40;
     
    thisShip = &gameWorld.shipList[shipIndex];;
    thisShip->x_pos = XRES - DIM1_X-1;
    thisShip->y_pos = 15;
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = DOWN;
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 5;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->AI_routine = routine4;
    thisShip->drawPixels =  drawDIM1;
    thisShip->erase = eraseDIM1;
    thisShip->drawID = collideDIM1;
    
    shipIndex++;
    shipTime += 40;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 1;
    thisShip->y_pos = 0;
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = DOWN;
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 4;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->AI_routine = routine4;
    thisShip->drawPixels =  drawDIM3;
    thisShip->erase = eraseDIM3;
    thisShip->drawID = collideDIM3;
    
    shipIndex++;
    shipTime += 40;
     
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = XRES - DIM1_X-1;
    thisShip->y_pos = 15;
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = DOWN;
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 6;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->AI_routine = routine4;
    thisShip->drawPixels =  drawDIM6;
    thisShip->erase = eraseDIM6;
    thisShip->drawID = collideDIM6;
    
    shipIndex++;
    shipTime += 240;
     
     //coming in from the right
     
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = XRES - DIM1_X-1;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = UP;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 4;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM4;
    thisShip->erase = eraseDIM4;
    thisShip->drawID = collideDIM4;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    shipTime += 40;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 1;
    thisShip->y_pos = 15;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = UP;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 5;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM5;
    thisShip->erase = eraseDIM5;
    thisShip->drawID = collideDIM5;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    shipTime += 40;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = XRES - DIM1_X-1;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = UP;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 2;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM2;
    thisShip->erase = eraseDIM2;
    thisShip->drawID = collideDIM2;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    shipTime += 40;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 1;
    thisShip->y_pos = 15;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = UP;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 4;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM4;
    thisShip->erase = eraseDIM4;
    thisShip->drawID = collideDIM4;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    shipTime += 40;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = XRES - DIM1_X-1;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = UP;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 5;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM5;
    thisShip->erase = eraseDIM5;
    thisShip->drawID = collideDIM5;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    shipTime += 40;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 1;
    thisShip->y_pos = 15;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = UP;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 6;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM6;
    thisShip->erase = eraseDIM6;
    thisShip->drawID = collideDIM6;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    
    return shipIndex;
}

short int makePattern4(world gameWorld, short int shipIndex, short int shipTime)
{
    ship* thisShip = NULL;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 1;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = UP;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 1;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM1;
    thisShip->erase = eraseDIM1;
    thisShip->drawID = collideDIM1;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    shipTime += 40;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 60;
    thisShip->y_pos = 0;
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = DOWN;
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 3;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->AI_routine = routine4;
    thisShip->drawPixels =  drawDIM3;
    thisShip->erase = eraseDIM3;
    thisShip->drawID = collideDIM3;
    
    shipIndex++;
    shipTime += 40;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 200;
    thisShip->y_pos = 0;
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = DOWN;
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 2;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->AI_routine = routine4;
    thisShip->drawPixels =  drawDIM2;
    thisShip->erase = eraseDIM2;
    thisShip->drawID = collideDIM2;
    
    shipIndex++;
    shipTime += 40;
     
    thisShip = &gameWorld.shipList[shipIndex];;
    thisShip->x_pos = 150;
    thisShip->y_pos = 0;
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = DOWN;
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 5;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->AI_routine = routine4;
    thisShip->drawPixels =  drawDIM1;
    thisShip->erase = eraseDIM1;
    thisShip->drawID = collideDIM1;
    
    shipIndex++;
    shipTime += 40;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 90;
    thisShip->y_pos = 0;
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = DOWN;
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 4;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->AI_routine = routine4;
    thisShip->drawPixels =  drawDIM3;
    thisShip->erase = eraseDIM3;
    thisShip->drawID = collideDIM3;
    
    shipIndex++;
    shipTime += 40;
     
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 280;
    thisShip->y_pos = 0;
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = DOWN;
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 6;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->AI_routine = routine4;
    thisShip->drawPixels =  drawDIM6;
    thisShip->erase = eraseDIM6;
    thisShip->drawID = collideDIM6;
    
    shipIndex++;
    shipTime += 120;
     
     //coming in from the right
     
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 180;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = UP;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 4;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM4;
    thisShip->erase = eraseDIM4;
    thisShip->drawID = collideDIM4;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    shipTime += 40;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 300;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = UP;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 5;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM5;
    thisShip->erase = eraseDIM5;
    thisShip->drawID = collideDIM5;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    shipTime += 40;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 60;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = UP;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 2;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM2;
    thisShip->erase = eraseDIM2;
    thisShip->drawID = collideDIM2;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    shipTime += 40;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 1;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = UP;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 4;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM4;
    thisShip->erase = eraseDIM4;
    thisShip->drawID = collideDIM4;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    shipTime += 40;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 100;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = UP;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 5;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM5;
    thisShip->erase = eraseDIM5;
    thisShip->drawID = collideDIM5;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    shipTime += 40;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 230;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = UP;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 6;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM6;
    thisShip->erase = eraseDIM6;
    thisShip->drawID = collideDIM6;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    
    return shipIndex;
}

short int makePattern5(world gameWorld, short int shipIndex, short int shipTime) //snakey movement ships
{
    ship* thisShip = NULL;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 25;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = thisShip->x_pos;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 1;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM1;
    thisShip->erase = eraseDIM1;
    thisShip->drawID = collideDIM1;    
    thisShip->AI_routine = routine2;
    
    shipIndex++;
    shipTime += 40;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 80;
    thisShip->y_pos = 0;
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = thisShip->x_pos;
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 3;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->AI_routine = routine2;
    thisShip->drawPixels =  drawDIM3;
    thisShip->erase = eraseDIM3;
    thisShip->drawID = collideDIM3;
    
    shipIndex++;
    shipTime += 40;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 200;
    thisShip->y_pos = 0;
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = thisShip->x_pos;
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 2;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->AI_routine = routine2;
    thisShip->drawPixels =  drawDIM2;
    thisShip->erase = eraseDIM2;
    thisShip->drawID = collideDIM2;
    
    shipIndex++;
    shipTime += 40;
     
    thisShip = &gameWorld.shipList[shipIndex];;
    thisShip->x_pos = 150;
    thisShip->y_pos = 0;
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = thisShip->x_pos;
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 5;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->AI_routine = routine2;
    thisShip->drawPixels =  drawDIM1;
    thisShip->erase = eraseDIM1;
    thisShip->drawID = collideDIM1;
    
    shipIndex++;
    shipTime += 40;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 120;
    thisShip->y_pos = 0;
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = thisShip->x_pos;
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 4;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->AI_routine = routine2;
    thisShip->drawPixels =  drawDIM3;
    thisShip->erase = eraseDIM3;
    thisShip->drawID = collideDIM3;
    
    shipIndex++;
    shipTime += 40;
     
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 280;
    thisShip->y_pos = 0;
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = thisShip->x_pos;
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 6;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->AI_routine = routine2;
    thisShip->drawPixels =  drawDIM6;
    thisShip->erase = eraseDIM6;
    thisShip->drawID = collideDIM6;
    
    shipIndex++;
    shipTime += 120;
     
     //coming in from the right
     
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 180;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = thisShip->x_pos;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 4;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM4;
    thisShip->erase = eraseDIM4;
    thisShip->drawID = collideDIM4;    
    thisShip->AI_routine = routine2;
    
    shipIndex++;
    shipTime += 40;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 240;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = thisShip->x_pos;
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 5;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM5;
    thisShip->erase = eraseDIM5;
    thisShip->drawID = collideDIM5;    
    thisShip->AI_routine = routine2;
    
    shipIndex++;
    shipTime += 40;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 60;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = thisShip->x_pos;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 2;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM2;
    thisShip->erase = eraseDIM2;
    thisShip->drawID = collideDIM2;    
    thisShip->AI_routine = routine2;
    
    shipIndex++;
    shipTime += 40;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 160;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = thisShip->x_pos;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 4;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM4;
    thisShip->erase = eraseDIM4;
    thisShip->drawID = collideDIM4;    
    thisShip->AI_routine = routine2;
    
    shipIndex++;
    shipTime += 40;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 100;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = thisShip->x_pos;  
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 5;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM5;
    thisShip->erase = eraseDIM5;
    thisShip->drawID = collideDIM5;    
    thisShip->AI_routine = routine2;
    
    shipIndex++;
    shipTime += 40;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 230;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = thisShip->x_pos;  
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 6;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM6;
    thisShip->erase = eraseDIM6;
    thisShip->drawID = collideDIM6;    
    thisShip->AI_routine = routine2;
    
    shipIndex++;
    
    return shipIndex;
}

/**
 * Chain of bouncing enemies all entering top left corner - Boss for level 1
 */
short int makeBoss1(world gameWorld, short int shipIndex, short int shipTime)
{
    ship* thisShip = NULL;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 1;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = DOWN;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 1;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM1;
    thisShip->erase = eraseDIM1;
    thisShip->drawID = collideDIM1;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    shipTime += 15;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 1;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = DOWN;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 1;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM1;
    thisShip->erase = eraseDIM1;
    thisShip->drawID = collideDIM1;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    shipTime += 15;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 1;
    thisShip->y_pos = 0;
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = DOWN;
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 1;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM1;
    thisShip->erase = eraseDIM1;
    thisShip->drawID = collideDIM1;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    shipTime += 15;
     
    thisShip = &gameWorld.shipList[shipIndex];;
    thisShip->x_pos = 1;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = DOWN;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 1;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM1;
    thisShip->erase = eraseDIM1;
    thisShip->drawID = collideDIM1;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    shipTime += 15;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 1;
    thisShip->y_pos = 0;
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = DOWN;
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 1;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM1;
    thisShip->erase = eraseDIM1;
    thisShip->drawID = collideDIM1;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    shipTime += 15;
     
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 1;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = DOWN;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 1;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM1;
    thisShip->erase = eraseDIM1;
    thisShip->drawID = collideDIM1;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    shipTime += 15;
     
     //coming in from the right
     
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 1;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = DOWN;      
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 1;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM1;
    thisShip->erase = eraseDIM1;
    thisShip->drawID = collideDIM1;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    shipTime += 15;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 1;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = DOWN;     
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 1;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM1;
    thisShip->erase = eraseDIM1;
    thisShip->drawID = collideDIM1;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    shipTime += 15;   
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 1;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = DOWN;      
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 1;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM1;
    thisShip->erase = eraseDIM1;
    thisShip->drawID = collideDIM1;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    shipTime += 15;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 1;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = DOWN;      
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 1;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM1;
    thisShip->erase = eraseDIM1;
    thisShip->drawID = collideDIM1;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    
    return shipIndex;
}

/**
 * 3 crews of 4 ships moving together in a line with the snake-like ai routine movement
 */
short int makePattern6(world gameWorld, short int shipIndex, short int shipTime) //snakey movement ships in 4mations
{
    ship* thisShip = NULL;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 25;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = thisShip->x_pos;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 1;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM1;
    thisShip->erase = eraseDIM1;
    thisShip->drawID = collideDIM1;    
    thisShip->AI_routine = routine2;
    
    shipIndex++;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 50;
    thisShip->y_pos = 0;
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = thisShip->x_pos;
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 3;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->AI_routine = routine2;
    thisShip->drawPixels =  drawDIM3;
    thisShip->erase = eraseDIM3;
    thisShip->drawID = collideDIM3;
    
    shipIndex++;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 75;
    thisShip->y_pos = 0;
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = thisShip->x_pos;
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 2;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->AI_routine = routine2;
    thisShip->drawPixels =  drawDIM2;
    thisShip->erase = eraseDIM2;
    thisShip->drawID = collideDIM2;
    
    shipIndex++;
     
    thisShip = &gameWorld.shipList[shipIndex];;
    thisShip->x_pos = 100;
    thisShip->y_pos = 0;
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = thisShip->x_pos;
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 5;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->AI_routine = routine2;
    thisShip->drawPixels =  drawDIM1;
    thisShip->erase = eraseDIM1;
    thisShip->drawID = collideDIM1;
    
    shipIndex++;
    shipTime += 120;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = XRES - DIM1_X - 25;
    thisShip->y_pos = 0;
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = thisShip->x_pos;
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 4;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->AI_routine = routine2;
    thisShip->drawPixels =  drawDIM3;
    thisShip->erase = eraseDIM3;
    thisShip->drawID = collideDIM3;
    
    shipIndex++;
     
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = XRES - DIM1_X - 50;
    thisShip->y_pos = 0;
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = thisShip->x_pos;
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 6;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->AI_routine = routine2;
    thisShip->drawPixels =  drawDIM6;
    thisShip->erase = eraseDIM6;
    thisShip->drawID = collideDIM6;
    
    shipIndex++;
     
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = XRES - DIM1_X - 75;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = thisShip->x_pos;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 4;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM4;
    thisShip->erase = eraseDIM4;
    thisShip->drawID = collideDIM4;    
    thisShip->AI_routine = routine2;
    
    shipIndex++;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = XRES - DIM1_X - 100;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = thisShip->x_pos;
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 5;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM5;
    thisShip->erase = eraseDIM5;
    thisShip->drawID = collideDIM5;    
    thisShip->AI_routine = routine2;
    
    shipIndex++;
    shipTime += 120;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 125;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = thisShip->x_pos;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 2;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM2;
    thisShip->erase = eraseDIM2;
    thisShip->drawID = collideDIM2;    
    thisShip->AI_routine = routine2;
    
    shipIndex++;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 150;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = thisShip->x_pos;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 4;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM4;
    thisShip->erase = eraseDIM4;
    thisShip->drawID = collideDIM4;    
    thisShip->AI_routine = routine2;
    
    shipIndex++;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 175;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = thisShip->x_pos;  
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 5;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM5;
    thisShip->erase = eraseDIM5;
    thisShip->drawID = collideDIM5;    
    thisShip->AI_routine = routine2;
    
    shipIndex++;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 200;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = thisShip->x_pos;  
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 6;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM6;
    thisShip->erase = eraseDIM6;
    thisShip->drawID = collideDIM6;    
    thisShip->AI_routine = routine2;
    
    shipIndex++;
    
    return shipIndex;
}

/**
 * line of bouncing enemies - 2 groups of 6 from top left, then top right - Boss for level 2
 */
short int makeBoss2(world gameWorld, short int shipIndex, short int shipTime)
{
    ship* thisShip = NULL;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 1;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = DOWN;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 2;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM2;
    thisShip->erase = eraseDIM2;
    thisShip->drawID = collideDIM2;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 16;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = DOWN;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 2;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM2;
    thisShip->erase = eraseDIM2;
    thisShip->drawID = collideDIM2;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 31;
    thisShip->y_pos = 0;
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = DOWN;
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 2;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM2;
    thisShip->erase = eraseDIM2;
    thisShip->drawID = collideDIM2;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
     
    thisShip = &gameWorld.shipList[shipIndex];;
    thisShip->x_pos = 46;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = DOWN;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 2;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM2;
    thisShip->erase = eraseDIM2;
    thisShip->drawID = collideDIM2;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 61;
    thisShip->y_pos = 0;
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = DOWN;
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 2;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM2;
    thisShip->erase = eraseDIM2;
    thisShip->drawID = collideDIM2;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
     
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 76;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = DOWN;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 2;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM2;
    thisShip->erase = eraseDIM2;
    thisShip->drawID = collideDIM2;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    shipTime += 200;
     
     //coming in from the right
     
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = XRES - DIM1_X - 1;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = DOWN;      
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 5;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM5;
    thisShip->erase = eraseDIM5;
    thisShip->drawID = collideDIM5;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = XRES - DIM1_X - 16;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = DOWN;     
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 5;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM5;
    thisShip->erase = eraseDIM5;
    thisShip->drawID = collideDIM5;    
    thisShip->AI_routine = routine4;
    
    shipIndex++; 
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = XRES - DIM1_X - 31;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = DOWN;      
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 5;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM5;
    thisShip->erase = eraseDIM5;
    thisShip->drawID = collideDIM5;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = XRES - DIM1_X - 46;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = DOWN;      
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 5;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM5;
    thisShip->erase = eraseDIM5;
    thisShip->drawID = collideDIM5;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = XRES - DIM1_X - 61;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = DOWN;      
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 5;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM5;
    thisShip->erase = eraseDIM5;
    thisShip->drawID = collideDIM5;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = XRES - DIM1_X - 76;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = DOWN;      
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 5;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM5;
    thisShip->erase = eraseDIM5;
    thisShip->drawID = collideDIM5;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    
    return shipIndex;
}

/**
 * 3 crews of 4 ships moving together in a line with the snake-like ai routine movement, but more spread out than 6
 */
short int makePattern7(world gameWorld, short int shipIndex, short int shipTime) //snakey movement ships in 4mations
{
    ship* thisShip = NULL;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 25;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = thisShip->x_pos;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 1;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM1;
    thisShip->erase = eraseDIM1;
    thisShip->drawID = collideDIM1;    
    thisShip->AI_routine = routine2;
    
    shipIndex++;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 75;
    thisShip->y_pos = 0;
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = thisShip->x_pos;
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 3;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->AI_routine = routine2;
    thisShip->drawPixels =  drawDIM3;
    thisShip->erase = eraseDIM3;
    thisShip->drawID = collideDIM3;
    
    shipIndex++;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 125;
    thisShip->y_pos = 0;
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = thisShip->x_pos;
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 2;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->AI_routine = routine2;
    thisShip->drawPixels =  drawDIM2;
    thisShip->erase = eraseDIM2;
    thisShip->drawID = collideDIM2;
    
    shipIndex++;
     
    thisShip = &gameWorld.shipList[shipIndex];;
    thisShip->x_pos = 175;
    thisShip->y_pos = 0;
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = thisShip->x_pos;
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 5;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->AI_routine = routine2;
    thisShip->drawPixels =  drawDIM1;
    thisShip->erase = eraseDIM1;
    thisShip->drawID = collideDIM1;
    
    shipIndex++;
    shipTime += 120;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = XRES - DIM1_X - 25;
    thisShip->y_pos = 0;
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = thisShip->x_pos;
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 4;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->AI_routine = routine2;
    thisShip->drawPixels =  drawDIM3;
    thisShip->erase = eraseDIM3;
    thisShip->drawID = collideDIM3;
    
    shipIndex++;
     
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = XRES - DIM1_X - 75;
    thisShip->y_pos = 0;
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = thisShip->x_pos;
    thisShip-> isAlive = 1;
    thisShip->last_x = 100;
    thisShip->last_y = 100;
    thisShip->dimensionID = 6;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->AI_routine = routine2;
    thisShip->drawPixels =  drawDIM6;
    thisShip->erase = eraseDIM6;
    thisShip->drawID = collideDIM6;
    
    shipIndex++;
     
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = XRES - DIM1_X - 125;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = thisShip->x_pos;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 4;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM4;
    thisShip->erase = eraseDIM4;
    thisShip->drawID = collideDIM4;    
    thisShip->AI_routine = routine2;
    
    shipIndex++;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = XRES - DIM1_X - 175;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = thisShip->x_pos;
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 5;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM5;
    thisShip->erase = eraseDIM5;
    thisShip->drawID = collideDIM5;    
    thisShip->AI_routine = routine2;
    
    shipIndex++;
    shipTime += 120;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 100;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = thisShip->x_pos;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 2;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM2;
    thisShip->erase = eraseDIM2;
    thisShip->drawID = collideDIM2;    
    thisShip->AI_routine = routine2;
    
    shipIndex++;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 150;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = thisShip->x_pos;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 4;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM4;
    thisShip->erase = eraseDIM4;
    thisShip->drawID = collideDIM4;    
    thisShip->AI_routine = routine2;
    
    shipIndex++;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 200;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = thisShip->x_pos;  
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 5;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM5;
    thisShip->erase = eraseDIM5;
    thisShip->drawID = collideDIM5;    
    thisShip->AI_routine = routine2;
    
    shipIndex++;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 250;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = LEFT; 
    thisShip-> y_accel = thisShip->x_pos;  
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 6;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM6;
    thisShip->erase = eraseDIM6;
    thisShip->drawID = collideDIM6;    
    thisShip->AI_routine = routine2;
    
    shipIndex++;
    
    return shipIndex;
}

/**
 * BOUNCING GIANT RED XXXXX O' DEATH made of 13 ships
 */
short int makeBoss3(world gameWorld, short int shipIndex, short int shipTime)
{
    ship* thisShip = NULL;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 1;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = UP;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 1;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM1;
    thisShip->erase = eraseDIM1;
    thisShip->drawID = collideDIM1;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 91;
    thisShip->y_pos = 0;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = UP;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 1;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM1;
    thisShip->erase = eraseDIM1;
    thisShip->drawID = collideDIM1;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 16;
    thisShip->y_pos = 15;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = UP;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 1;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM1;
    thisShip->erase = eraseDIM1;
    thisShip->drawID = collideDIM1;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 76;
    thisShip->y_pos = 15;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = UP;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 1;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM1;
    thisShip->erase = eraseDIM1;
    thisShip->drawID = collideDIM1;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 31;
    thisShip->y_pos = 30;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = UP;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 1;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM1;
    thisShip->erase = eraseDIM1;
    thisShip->drawID = collideDIM1;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 61;
    thisShip->y_pos = 30;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = UP;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 1;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM1;
    thisShip->erase = eraseDIM1;
    thisShip->drawID = collideDIM1;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 46;
    thisShip->y_pos = 45;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = UP;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 1;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM1;
    thisShip->erase = eraseDIM1;
    thisShip->drawID = collideDIM1;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 31;
    thisShip->y_pos = 60;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = UP;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 1;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM1;
    thisShip->erase = eraseDIM1;
    thisShip->drawID = collideDIM1;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 61;
    thisShip->y_pos = 60;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = UP;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 1;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM1;
    thisShip->erase = eraseDIM1;
    thisShip->drawID = collideDIM1;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 16;
    thisShip->y_pos = 75;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = UP;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 1;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM1;
    thisShip->erase = eraseDIM1;
    thisShip->drawID = collideDIM1;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 76;
    thisShip->y_pos = 75;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = UP;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 1;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM1;
    thisShip->erase = eraseDIM1;
    thisShip->drawID = collideDIM1;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 1;
    thisShip->y_pos = 90;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = UP;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 1;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM1;
    thisShip->erase = eraseDIM1;
    thisShip->drawID = collideDIM1;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    
    thisShip = &gameWorld.shipList[shipIndex];
    thisShip->x_pos = 91;
    thisShip->y_pos = 90;    
    thisShip-> x_accel = RIGHT; 
    thisShip-> y_accel = UP;   
    thisShip-> isAlive = 1;
    thisShip->last_x = 0;
    thisShip->last_y = 0;
    thisShip->dimensionID = 1;
    thisShip->startTime = shipTime;
    thisShip->ID = shipIndex+1;
    thisShip->drawPixels =  drawDIM1;
    thisShip->erase = eraseDIM1;
    thisShip->drawID = collideDIM1;    
    thisShip->AI_routine = routine4;
    
    shipIndex++;
    
    return shipIndex;
}
