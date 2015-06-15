/**
The purpose of this C file is to implement level initilization
DataFile Format:

@ denotes attribute type

types are: background, player, enemy, score and objective

*/


#include "world.h"
#include "initialization.h"
#include "AI.h"
#include "graphics.h"
#include "moveCollide.h"
#include "levels.h"

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/**
finds the index of the token char within str, returns -1 if failure
*/
int findSubchar(char* str, char token);

/**
Used to sort a list of ships by their creation times
*/
int compare(const void* element1, const void * element2);

/**
Inputs: 
none

Returns: the initialized World object ready to be played
*/
world makeGame(short int level, short int numPlayers,int score){
    
    world gameWorld;
    gameWorld.nProj = 0;
    gameWorld.projList = (projectile*)calloc(MAX_PROJECTILES,sizeof(projectile));
    gameWorld.currentTime = 0; 
    
    gameWorld.player1 = (ship*)malloc(sizeof(ship));
    gameWorld.player1->AI_routine = NULL;
    gameWorld.player1->x_pos = (WORLD_X_SIZE/8)*3;
    gameWorld.player1->y_pos = WORLD_Y_SIZE-15;    
    gameWorld.player1->x_accel = 0; 
    gameWorld.player1->y_accel = UP;   
    gameWorld.player1->isAlive = 1;
    gameWorld.player1->last_x = 0;
    gameWorld.player1->last_y = 0;
    gameWorld.player1->dimensionID = 8;
    gameWorld.player1->startTime = 0;
    gameWorld.player1->ID = RESERVED_PLAYER1_ID;
    gameWorld.player1->drawPixels =  drawDIM8;
    gameWorld.player1->erase = eraseDIM8;
    gameWorld.player1->drawID = collideDIM8;    
    gameWorld.player1->AI_routine = NULL;
    gameWorld.player1->health = MAX_HEALTH;
    gameWorld.player1->lastHit = 0;
    
    gameWorld.score = score;
    
    if(numPlayers == 1){
        gameWorld.player2 = NULL; 
    }
    else{
    gameWorld.player2 = (ship*)malloc(sizeof(ship));
    gameWorld.player2->AI_routine = NULL;
    gameWorld.player2->x_pos = (WORLD_X_SIZE/8)*5;
    gameWorld.player2->y_pos = WORLD_Y_SIZE-15;    
    gameWorld.player2->x_accel = 0; 
    gameWorld.player2->y_accel = UP;   
    gameWorld.player2->isAlive = 1;
    gameWorld.player2->last_x = 0;
    gameWorld.player2->last_y = 0;
    gameWorld.player2->dimensionID = 8;
    gameWorld.player2->startTime = 0;
    gameWorld.player2->ID = RESERVED_PLAYER2_ID;
    gameWorld.player2->drawPixels =  drawDIM7;
    gameWorld.player2->erase = eraseDIM7;
    gameWorld.player2->drawID = collideDIM7;    
    gameWorld.player2->AI_routine = NULL;
    gameWorld.player2->health = MAX_HEALTH;
    gameWorld.player2->lastHit = 0;
    }
    
    if(level == 1){
        return level1(gameWorld);
    }
    else if(level == 2){
        return level2(gameWorld);
    }
    else if(level == 3){
        return level3(gameWorld);
    }
    else{
        return level1(gameWorld);
    }
}

world level1(world gameWorld){
    
    gameWorld.levelEndTime = 6000;
    gameWorld.shipList_size = 82;  
    gameWorld.shipList = (ship*)malloc(gameWorld.shipList_size*sizeof(ship));
    gameWorld.level = 1;
    short int shipIndex = 0;
    short int shipTime = 0;
    
    shipIndex = makePattern1(gameWorld, shipIndex, shipTime);   
    shipTime += 40*12+240;
    shipIndex = makePattern2(gameWorld, shipIndex, shipTime); 
    shipTime += 40*12+240;
    shipIndex = makePattern1(gameWorld, shipIndex, shipTime); 
    shipTime += 40*12+360;
    shipIndex = makePattern5(gameWorld, shipIndex, shipTime); 
    shipTime += 40*12+240;
    shipIndex = makePattern2(gameWorld, shipIndex, shipTime);
    shipTime += 40*12+240;
    shipIndex = makePattern5(gameWorld, shipIndex, shipTime); 
    shipTime += 40*12+500;
    shipIndex = makeBoss1(gameWorld, shipIndex, shipTime); 
    
    return gameWorld; 
}

world level2(world gameWorld){
    
    gameWorld.levelEndTime = 6000;
    gameWorld.shipList_size = 96;
    gameWorld.shipList = (ship*)malloc(gameWorld.shipList_size*sizeof(ship));
    gameWorld.level = 2;
    short int shipIndex = 0;
    short int shipTime = 0;
    
    shipIndex = makePattern6(gameWorld, shipIndex, shipTime); 
    shipTime += 480;
    shipIndex = makePattern6(gameWorld, shipIndex, shipTime);
    shipTime += 480;
    shipIndex = makePattern2(gameWorld, shipIndex, shipTime);
    shipTime += 40*12+240;
    shipIndex = makePattern5(gameWorld, shipIndex, shipTime);
    shipTime += 40*12+240;
    shipIndex = makePattern3(gameWorld, shipIndex, shipTime);
    shipTime += 40*12+240;
    shipIndex = makePattern5(gameWorld, shipIndex, shipTime);
    shipTime += 40*12+500;
    shipIndex = makeBoss2(gameWorld, shipIndex, shipTime);
    shipTime += 40*12+240;
    shipIndex = makeBoss2(gameWorld, shipIndex, shipTime);
    
    return gameWorld;
    
}

world level3(world gameWorld){
    
    gameWorld.levelEndTime = 8500;
    gameWorld.shipList_size = 119;
    gameWorld.shipList = (ship*)malloc(gameWorld.shipList_size*sizeof(ship));
    gameWorld.level = 3;
    short int shipIndex = 0;
    short int shipTime = 0;
    
    shipIndex = makePattern3(gameWorld, shipIndex, shipTime); 
    shipTime += 40*12+500;
    shipIndex = makePattern4(gameWorld, shipIndex, shipTime);
    shipTime += 40*12+500;
    shipIndex = makePattern7(gameWorld, shipIndex, shipTime);
    shipTime += 40*12+250;
    shipIndex = makePattern5(gameWorld, shipIndex, shipTime);
    shipTime += 40*12+250;
    shipIndex = makePattern7(gameWorld, shipIndex, shipTime);
    shipTime += 40*12+250;
    shipIndex = makePattern4(gameWorld, shipIndex, shipTime);
    shipTime += 40*12+500;
    shipIndex = makeBoss1(gameWorld, shipIndex, shipTime);
    shipTime += 40*12+500;
    shipIndex = makeBoss2(gameWorld, shipIndex, shipTime);
    shipTime += 40*12+240;
    shipIndex = makeBoss2(gameWorld, shipIndex, shipTime);
    shipTime += 40*12+500;
    shipIndex = makeBoss3(gameWorld, shipIndex, shipTime);
    
    
    return gameWorld;
    
}

/**
Initilizes the game map to be all empty
Inputs:
	map - the game's WORLD_X_SIZE by WORLD_Y_SIZE map
*/
void initMap(char** map){
	for(int x = 0; x < WORLD_X_SIZE; x++){
		for(int y = 0; y < WORLD_Y_SIZE; y++){
			map[x][y] = EMPTY_SPACE;
		}
	}
}

/**
finds the index of the token char within str, returns -1 if failure
*/
int findSubchar(char* str, char token){
	char* subPointer;
	
	if( NULL == (subPointer = (strchr(str,token)))){
		return -1; 
	}
	
	return (int)(subPointer - str); 
}

/**
Used to sort a list of ships by their creation times
*/
int compare(const void* element1, const void * element2){
	int startTime1 = ((ship*)element1)->startTime;
	int startTime2 = ((ship*)element2)->startTime;
	
	return (startTime1>startTime2);
}
