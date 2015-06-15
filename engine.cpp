/**
The game's engine containing the userMain function

This file will be responsible for:
-calling parsing functions
-creating the graphics and I/0 tasks
-setting up intertask communication (i.e. intitializing sempahores/queues)
-containing the main game loop (and game logic) 
	to update the game's state over time
	
The game map is a collection of IDs that identify the position and dimensions of every ship or projectile in the game
each ship is identified by it's index into the shipList array, and every projectile is identified by it's index in it's own
array with the second MSB set

each player is identified by a reserved ID

the MSB of each ID is reserved to track which ships have been updated in the current turn
*/

//C++ STUFF
#include <iostream>
#include <cstdio>
#include <stdlib.h>

#using <System.dll>

//using namespace System;
using namespace System::Threading;

#include "PixelToaster.h"
using namespace PixelToaster; 

#define BLUEMASK 0x001F
#define GREENMASK 0x03E0
#define REDMASK 0x7C00

#include "initialization.h"
#include "userIO.h"
#include "world.h"
#include "AI.h"
#include "graphics.h"
#include "fontGraphics.h"
#include "moveCollide.h"
#include "startScreen.h"


//#include "includes.h"
//#include "system.h"
//#include "sys/alt_irq.h"
#include <io.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TASK_STACKSIZE 2048
#define MAIN_TASK_PRIO 1
#define CONTROLLER1_PRIORITY 2
#define CONTROLLER2_PRIORITY 3

#define TICK_CONSTANT_TIME_MS 15

#define TASK_ALLOWANCE_DELAY_MS 5

//OS_STK mainstk[TASK_STACKSIZE];

int mainTask(void* pdata);
//OS_EVENT * semVGA;

#include "global.h"
using namespace Global;

Display disp( "Image Example", XRES, YRES);
//map of the game world for collision detection
char** theMap; 

//extern OEVENT S_*controller1semaphore;
//extern OS_EVENT *controller2semaphore;


/**
Moves ships onto the onscreen list according to the current game time
Inputs:
	gameWorld - World object containing world state
	onscreen - array of pointers to onscreen ships
	numOnscreen - number of onscreen objects
Outputs:
	the number of ships created
*/
short int createShips(world gameWorld, ship** onscreen, int numOnscreen);

/**
Updates the player's ship according to the given inputs
Inputs:
	input - the user input structure with x y and z values
	player - pointer to the player's ship
	proj - pointer to an array of all active projectiles
*/
void playerUpdate(ship* player1,ship* player2,world* gameWorld);

/**
Modes given projectile along its trajectory
Inputs:
    proj - pointer to the given projectile
Outputs: 
    true if a projectile has moved offscreen and needs to be cleaned up
*/
short int projUpdate(projectile* proj);

/**
checks for collisions after all ships and projectiles have moved

Inputs:
    onscreen - the pointer to the array of all ships that are active
    gameWorld - the gameWorld object
    map - the map of the game world
    nships - pointer to the number of ships onscreen
    nProj - pointer to the numer of projectiles onscreen
Outputs:
    none
*/
void collisionMove(ship** onscreen,world * gameWorld, short int *map,int nShips);

/**
 * Redraws the screen based on the given pixel map
 * 
 * Inputs:
 *  gameWorld - the gameWorld object
 *  pixelMap - pixel bit map representing the frame
 * onscreen - pointer to a list of all onscreen ships
 *  nShips - number of ships currently onscreen
 * 
 * returns:
 *  the number of dead ships found and erased
 */
short int redraw(world* gameWorld,short int* pixelMap,ship** onscreen,short int nShips);

/*
 * shift any ships that have undergone collisions to the end of the list
 */
void shuffleCollisions(ship** onscreen,int nShips, short int* collisionMap);

/*
 * shift any projectiles that have undergone collisions to the end of the list
 */
void shuffleProj(world gameWorld);

/**
 * remove a point of damage from the player character and kill it if required
 */
void damagePlayer(ship* player,int currentTime);

short int copyScreen(short int* pixelMap,Display& disp);
/*
 * ends the level once the end conditions have been reached
 */
void endLevelVictory(world* gameWorld,ship*** onscreen,short int* nShips,short int* colMap,short int* pixelMap,Display& disp);


/*
 * end the level once all the players have dies
 */
void endLevelLoss(world* gameWorld,ship*** onscreen,short int* nShips,short int*colMap,short int* pixelMap);


/**
 * returns true if the game is lost
 */
short int isLoss(ship* player1, ship* player2);

/**
 * returns true if the game is won
 */
short int isWon(int currentTime, int endTime);

int main(void){
  //controller1semaphore = OSSemCreate(1);
  //controller2semaphore = OSSemCreate(1);
	GlobalsEng::controller1semaphore = gcnew Semaphore( 1,1 );
	GlobalsEng::controller2semaphore = gcnew Semaphore( 1,1 );
	GlobalsEng::semVGA = gcnew Semaphore( 1,1 );

  //Initialize the controller tasks
    /*OSTaskCreateExt(controller1_task,
                  NULL,
                  (void *)&controller1_stk[TASK_STACKSIZE-1],
                  CONTROLLER1_PRIORITY,
                  CONTROLLER1_PRIORITY,
                  controller1_stk,
                  TASK_STACKSIZE,
                  NULL,
                  0);
                  
   OSTaskCreateExt(controller2_task,
                  NULL,
                  (void *)&controller2_stk[TASK_STACKSIZE-1],
                  CONTROLLER2_PRIORITY,
                  CONTROLLER2_PRIORITY,
                  controller2_stk,
                  TASK_STACKSIZE,
                  NULL,
                  0);*/

	Thread^ cont1 = gcnew Thread(gcnew ParameterizedThreadStart( controller1_task ) );
	Thread^ cont2 = gcnew Thread(gcnew ParameterizedThreadStart( controller2_task ) );

	cont1->Start( 1 );
	cont2->Start( 2 );
  
  //short int nPlayers = IORD(PLAYER_SELECT_BASE,0)+1;
	short int nPlayers = 1;

	world gameWorld = makeGame(1,nPlayers,0);
  
  //array of pointers to onscreen ships, will be set to all NULL
  ship** onscreenShips = (ship**)calloc(gameWorld.shipList_size,sizeof(ship*));
  
  short int* pixelMap = (short int*)calloc(XRES*YRES,sizeof(short int));
  short int* collisionMap = (short int*)calloc(WORLD_X_SIZE*WORLD_Y_SIZE,sizeof(short int));

  int windowOpen = 1;

  initStartScreen(pixelMap);

  int startPressed = 0;
  //start screen here
    while(!detectStart() && disp.open()){
		Thread::Sleep(500);
		copyScreen(pixelMap,disp);
	}

	for(int i = 0; i < XRES*YRES; i++){
		pixelMap[i] = 0;
	}
  
  scoreArea scoreBar = initScoreArea(pixelMap);
  
  //true when a projectile has gone off the screen during the current game tick
  short int projectileGone = 0;
  short int shipSuicide = 0;
  
  //the current number of onscreen enemy ships
  short int nShips = 0;
  //the current number of projectiles
  
  //INT32U t1 = 0;
  //INT32U t2 = 0;
  //INT32U elapsed = 0;
  
  //the main game loop starts here
    while(windowOpen){
        //t1 =  OSTimeGet();

        //step 1: create all new ships
        nShips += createShips(gameWorld,onscreenShips,nShips);
        
       //step 2: take user input and update the player's ship
       playerUpdate(gameWorld.player1,gameWorld.player2,&gameWorld);
  
        //step 3: run AI routines on enemy ships
        //this for loop will be a problem if we don't activate c99 mode
        for(short int i = 0; i < nShips; i++){
	   //run each AI routine
	
	       //first null orship indicates end of list
	       if(onscreenShips[i] == NULL){
		      break; 
	       }
           if(onscreenShips[i]->isAlive){
            if( onscreenShips[i]->AI_routine(onscreenShips[i],&gameWorld)){
                shipSuicide = 1; 
            }
           }
        }
        
        if(shipSuicide){
            shipSuicide = 0;
            shuffleCollisions(onscreenShips,nShips,collisionMap); 
        }
  
        //step 4: update onscreen projectiles
        for(short int i = 0; i < MAX_PROJECTILES;i++){
	
	       if(!gameWorld.projList[i].active){
		      break; 
	       }
	       if(projUpdate(&gameWorld.projList[i])){
                projectileGone = 1;
           }
        }
        
        if(projectileGone){
            shuffleProj(gameWorld);
            projectileGone = 0;
        }
  
        //step 5: collision detection and resolution
        collisionMove(onscreenShips,&gameWorld,collisionMap,nShips);
        //step 6: redraw screen
        //OSSemPend(semVGA,0,&err);
        updateScoreArea(gameWorld,&scoreBar);
        nShips -= redraw(&gameWorld,pixelMap,onscreenShips,nShips);
        windowOpen = copyScreen(pixelMap,disp);
        
        //step 7 check end conditions
        if(isLoss(gameWorld.player1,gameWorld.player2)){
            gameWorld.currentTime++;
            endLevelLoss(&gameWorld,&onscreenShips,&nShips,collisionMap,pixelMap);
        }
        else if( isWon(gameWorld.currentTime,gameWorld.levelEndTime)){
             endLevelVictory(&gameWorld,&onscreenShips,&nShips,collisionMap,pixelMap,disp);
        }
        else{                  
        //increment game time
        gameWorld.currentTime++;
        }
        
        //step 8 normalize game tick
        //OSTimeDlyHMSM(0, 0, 0, TASK_ALLOWANCE_DELAY_MS);
        //t2 = OSTimeGet();
        //elapsed = (t2 -t1)/(OS_TICKS_PER_SEC/1000);
        
        /*if(elapsed <= TICK_CONSTANT_TIME_MS){
            OSTimeDlyHMSM(0, 0, 0, TICK_CONSTANT_TIME_MS-elapsed);
        }*/ 
    }

	//Exit gracefully
	GlobalsEng::controller1semaphore->WaitOne();
	controller1state.quit = 1;
	GlobalsEng::controller1semaphore->Release();
	GlobalsEng::controller2semaphore->WaitOne();
	controller2state.quit = 1;
	GlobalsEng::controller2semaphore->Release();
    
    
    return 0;
}

/**
Moves ships onto the onscreen list according to the current game time
could probably be optimized
Inputs:
	gameWorld - World object containing world state
	onscreen - array of pointers to onscreen ships
	numOnscreen - number of onscreen objects
Outputs:
	the number of ships created
*/
short int createShips(world gameWorld, ship** onscreen, int numOnscreen){
	//won't compile out of c99 mode
	static short int starti = 0; //list is sorted so no need to retraverse ships we've already created
    
    /**
     * indicates new level
     */
    if(gameWorld.currentTime == 0){
        starti = 0;
    }
    
    short int startn = 0;
	short int shipsCreated = 0; 
	
	for(short int i = starti; i<gameWorld.shipList_size;i++){
		if(gameWorld.shipList[i].startTime == gameWorld.currentTime){
            shipsCreated++;
			//fill first null slot in onscreen list with the new ship
			for(short int n = startn; n<gameWorld.shipList_size; n++){
				if(onscreen[n] == NULL || !(onscreen[n]->isAlive)){
					onscreen[n] = &(gameWorld.shipList[i]);
                    startn = n+1;
                    break; 
				}	
				else if (n == (gameWorld.shipList_size - 1)){
					printf("Error, onscreen Ship buffer is full\n");
					exit(-1); 
				}
			}
		}
        else{
            break;
        }
	}
    
    starti+=shipsCreated; 
    
	return shipsCreated;
}

/**
Updates the player's ship according to the given inputs
Inputs:
	input - the user input structure with x y and z values
	player - pointer to the player's ship
	proj - pointer to an array of all active projectiles
*/
void playerUpdate(ship* player1,ship* player2,world* gameWorld){   
    static int thisFire1 = 0;
    static int lastFire1 = -FIRE_MIN_TIME;  
    
    static int thisFire2 = 0;
    static int lastFire2 = -FIRE_MIN_TIME;
    
    short int newX = 0;
    short int newY = 0;
    
    short int fire = 0;
    
    if(gameWorld->currentTime == 0){
        lastFire1 = -FIRE_MIN_TIME;
    }   
    thisFire1 = gameWorld->currentTime;
    
    if(!player1->isAlive){
        player1->last_x = player1->x_pos;
        player1->last_y = player1->y_pos;
        if(player2 == NULL){
            return;
        }
    }
    else{    
        //INT8U err = 0;
    
        GlobalsEng::controller1semaphore->WaitOne();
    
	   newX = player1->x_pos + ((short int)controller1state.roll);
	   newY = player1->y_pos + ((short int)controller1state.pitch);
       fire = controller1state.fire;
    
        player1->last_x = player1->x_pos;
        player1->last_y = player1->y_pos;    
        //OSSemPost(controller1semaphore);
		GlobalsEng::controller1semaphore->Release();

	   //do out of bounds checking
	   if(newX+DIM1_X > WORLD_X_SIZE){
		  newX = WORLD_X_SIZE-DIM1_X;
	   }
	   else if (newX < 0){
		  newX = 0; 
	   }
	   if(newY+DIM1_Y > WORLD_Y_SIZE){
		  newY = WORLD_Y_SIZE-DIM1_Y; 
	   }
	   else if(newY < 0){
		  newY = 0; 
	   }	
	   player1->x_pos = newX;
	   player1->y_pos = newY;     
        if(fire && (thisFire1-lastFire1 > FIRE_MIN_TIME)){
            lastFire1 = gameWorld->currentTime;
            makeProjectile(player1->x_pos+DIM1_X/2, player1->y_pos-DIMP_Y, NONE, -7, gameWorld,PLAYER_PROJECTILE);
        }
    }
    
    if(player2 == NULL){
        return;
    }
    else{  
        if(gameWorld->currentTime == 0){
            lastFire2 = -FIRE_MIN_TIME;
        }   
        thisFire2 = gameWorld->currentTime;
    
        if(!player2->isAlive){
            player2->last_x = player2->x_pos;
            player2->last_y = player2->y_pos;
            return;
        }    
        //INT8U err = 0;

		GlobalsEng::controller2semaphore->WaitOne();
    
            newX = player2->x_pos + ((short int)controller2state.roll);
            newY = player2->y_pos + ((short int)controller2state.pitch);
            fire = controller2state.fire;
    
        player2->last_x = player2->x_pos;
        player2->last_y = player2->y_pos;    
		GlobalsEng::controller2semaphore->Release();
        //do out of bounds checking
        if(newX+DIM1_X > WORLD_X_SIZE){
            newX = WORLD_X_SIZE-DIM1_X;
        }
        else if (newX < 0){
            newX = 0; 
        }
        if(newY+DIM1_Y > WORLD_Y_SIZE){
            newY = WORLD_Y_SIZE-DIM1_Y; 
        }
        else if(newY < 0){
            newY = 0; 
        }   
        player2->x_pos = newX;
        player2->y_pos = newY;     
        if(fire && (thisFire2-lastFire2 > FIRE_MIN_TIME)){
            lastFire2 = gameWorld->currentTime;
            makeProjectile(player2->x_pos+DIM1_X/2, player2->y_pos-DIMP_Y, NONE, -7, gameWorld,PLAYER_PROJECTILE);
        }
    }
}

/**
Modes given projectile along its trajectory
Inputs:
	proj - pointer to the given projectile
Outputs: 
	true if a projectile has moved offscreen and needs to be cleaned up
*/
short int projUpdate(projectile* proj){
    
     proj->last_x =  proj->x_pos;
     proj->last_y =  proj->y_pos;
    
    int newx = proj->last_x + proj->x_dir; 
    int newy = proj->last_y + proj->y_dir;
    
        if(newx < 0 || newx > WORLD_X_SIZE){
            proj->active = 0;
            return 1;
        }
        else if(newy < 0 || newy > WORLD_Y_SIZE){
            proj->active = 0;
             return 1; 
        }
        else{
		  proj->x_pos = newx;
		  proj->y_pos = newy;
          return 0;
        }
}

/**
checks for collisions after all ships and projectiles have moved

Inputs:
	onscreen - the pointer to the array of all ships that are active
	gameWorld - the gameWorld object
	map - the map of the game world
	nships - pointer to the number of ships onscreen
	nProj - pointer to the numer of projectiles onscreen
Outputs:
	none
*/
void collisionMove(ship** onscreen,world * gameWorld, short int *map,int nShips){
    short int deadShip = 0;
    short int deadProj = 0;
    int scoreIncrease = 0;
    short int square = 0;
    short int index = 0;
    short int whichPlayer = 0;
    //move all ships
    
    gameWorld->player1->erase(map,*gameWorld->player1);
    
    if(gameWorld->player1->isAlive){
        for(short int n = 0;  gameWorld->player1->drawID(n,map,gameWorld->currentTime,&square,*gameWorld->player1); n++);
    }
    
    if(gameWorld->player2 != NULL){
        gameWorld->player2->erase(map,*gameWorld->player2);
        if(gameWorld->player2->isAlive){
            for(short int n = 0;  gameWorld->player2->drawID(n,map,gameWorld->currentTime,&square,*gameWorld->player2); n++);
        }
    }
    
    for(short int i = 0; i < nShips; i++){
        
        onscreen[i]->erase(map,*onscreen[i]);
        
        if(onscreen[i]->isAlive){
            for(short int n = 0;  onscreen[i]->drawID(n,map,gameWorld->currentTime,&square,*onscreen[i]); n++){
                
                if(isFull(square,gameWorld->currentTime)){
                    if(whichPlayer = isPlayer(square)){
                        deadShip = 1;
                            onscreen[i]->isAlive = 0;
                        if(whichPlayer == 1){
                            //gameWorld.player1->isAlive = 0;
                            damagePlayer(gameWorld->player1,gameWorld->currentTime);
                        }
                        else if(whichPlayer == 2){
                            //gameWorld.player1->isAlive = 0;
                            damagePlayer(gameWorld->player2,gameWorld->currentTime);
                        }
                        
                    }
                }
            }
        }
        else{
            deadShip = 1;
        }
    } 
    //move all projectiles
    for(short int i = 0; i < gameWorld->nProj; i++){
        erasePROJ(map,gameWorld->projList[i]);
        
        //collision move here
         if(gameWorld->projList[i].active){
            for(short int n = 0;  collideProjectiles(n,map,gameWorld->currentTime,&square,gameWorld->projList[i]); n++){
                if(isFull(square,gameWorld->currentTime)){                   
                    
                    if(isShip(square,&index)){
                        
                        if(whichPlayer = isPlayer(square)){
                            if(gameWorld->projList[i].allignment == AI_PROJECTILE){
                                 deadProj = 1;
                                 gameWorld->projList[i].active = 0;
                                 if(whichPlayer == 1){
                                    damagePlayer(gameWorld->player1,gameWorld->currentTime);
                                 }
                                else if(whichPlayer == 2){
                                    damagePlayer(gameWorld->player2,gameWorld->currentTime);
                                }
                            }
                        }
                        else if(gameWorld->projList[i].allignment == PLAYER_PROJECTILE){
                                
                            deadShip = 1;
                            gameWorld->shipList[index].isAlive = 0;
                            deadProj = 1;
                            gameWorld->projList[i].active = 0;
                            scoreIncrease ++;
                      }
                    }
                }
            }
            if(scoreIncrease){
                scoreIncrease = 0;
                gameWorld->score += 1000;
            }
         }
    }
    
    if(deadShip){
       shuffleCollisions(onscreen,nShips,map); 
    }
    if(deadProj){
       shuffleProj(*gameWorld);
    }
}

/*
 * shift any ships that have undergone collisions to the end of the list
 */
void shuffleCollisions(ship** onscreen,int nShips, short int* collisionMap){
    
    short int endofList = nShips -1;
    short int tempx; 
    short int tempy;   
    ship* temp; 
    
    for(short int i = 0; i < nShips; i++){
        if(!onscreen[i]->isAlive){
            
            //step 1 erase ghost ship
            tempx = onscreen[i]->last_x;
            tempy = onscreen[i]->last_y;         
            onscreen[i]->last_x = onscreen[i]->x_pos;
            onscreen[i]->last_y = onscreen[i]->y_pos;           
            onscreen[i]->erase(collisionMap,*onscreen[i]);       
            onscreen[i]->last_x = tempx;
            onscreen[i]->last_y = tempy;     
            
                 
            //step 2 swap location in list
            temp = onscreen[endofList];       
            onscreen[endofList] = onscreen[i]; 
            onscreen[i] = temp;     
            endofList--;
            i--;//make sure that the ship we just swapped is alive    
        }
        if(endofList <= i){
             break;
        }
    }
}

/*
 * shift any projectiles that have undergone collisions to the end of the list
 */
void shuffleProj(world gameWorld){
        
    short int endofList = gameWorld.nProj-1; 
    projectile temp; 
    
    for(short int i = 0; i < gameWorld.nProj; i++){
        if(!gameWorld.projList[i].active){
                  
            //step 2 swap location in list
            temp = gameWorld.projList[endofList];        
            gameWorld.projList[endofList] = gameWorld.projList[i]; 
            gameWorld.projList[i] = temp;
               
            //***MUST UPDATE ID'S HERE
            gameWorld.projList[i].ID =  gameWorld.projList[endofList].ID;
            gameWorld.projList[endofList].ID = temp.ID;
            
            
            endofList--;    
            i--; 
            
        }
        if(endofList <= i){
                break;
            }
    }
}

/**
 * remove a point of damage from the player character and kill it if required
 */
void damagePlayer(ship* player,int currentTime){
    
    if(currentTime - player->lastHit < PLAYER_DAMAGE_MIN_TIME){
        return;
    }
    player->lastHit = currentTime;
    player->health -= 1;
    
    if(player->health <= 0){
        player->isAlive = 0;
    }
}

/**
 * Redraws the screen based on the given pixel map
 * 
 * Inputs:
 *  gameWorld - the gameWorld object
 *  pixelMap - pixel bit map representing the frame
 * onscreen - pointer to a list of all onscreen ships
 *  nShips - number of ships currently onscreen
 * 
 * returns:
 *  the number of dead ships found and erased
 */
short int redraw(world* gameWorld,short int* pixelMap,ship** onscreen,short int nShips){
 
    short int shipsKilled = 0;
    static short int player1DeadClock = 1;
    static short int player2DeadClock = 1;
    
    if(gameWorld->player1->isAlive){
        player1DeadClock = 1;
    }
    if(gameWorld->player2 != NULL && gameWorld->player2->isAlive){
        player2DeadClock = 1;
    }
    
    if(player1DeadClock == 1){
        gameWorld->player1->erase(pixelMap,*gameWorld->player1);
    }
    
    if(gameWorld->player1->isAlive){
        gameWorld->player1->drawPixels(pixelMap,*gameWorld->player1);
    }
    else{
        player1DeadClock = 0;
    }

    
    if(gameWorld->player2 != NULL){
            if(player2DeadClock == 1){
                gameWorld->player2->erase(pixelMap,*gameWorld->player2);
    
            if(gameWorld->player2->isAlive){
                gameWorld->player2->drawPixels(pixelMap,*gameWorld->player2);
            }
            else{
                player2DeadClock = 0;
            }
        }
    }
    //redraw ships
    for(short int i = 0; i < nShips; i++){
            
            onscreen[i]->erase(pixelMap,*onscreen[i]);
            
           if(onscreen[i]->isAlive){
                 onscreen[i]->drawPixels(pixelMap,*onscreen[i]);
           }
           else{
            shipsKilled++;
           }
        
    }
    //redraw projectiles
    short int projKilled = 0;
    
    for(short int i = 0; i < gameWorld->nProj; i++){
        erasePROJ(pixelMap, gameWorld->projList[i]);
        
        
        if(gameWorld->projList[i].active){
            drawPROJ(pixelMap, gameWorld->projList[i]);
        }
        else{
            projKilled ++;
        }
    }
   gameWorld->nProj = gameWorld->nProj - projKilled;
   return shipsKilled;
    
}
/**
 * returns true if the game is lost
 */
short int isLoss(ship* player1, ship* player2){
    if(!player1->isAlive && (player2 == NULL || !player2->isAlive)){
        return 1;
    }
    
    return 0;
}
/**
 * returns true if the game is won
 */
short int isWon(int currentTime, int endTime){
    if(currentTime >= endTime){
        return 1;
    }
    else{
        return 0;
    }
}
/*
 * ends the level once the end conditions have been reached
 */
void endLevelVictory(world* gameWorld,ship*** onscreen,short int* nShips,short int*colMap,short int* pixelMap,Display& disp){
    while(!detectStart()&&disp.open()){
        drawVICTORY(pixelMap, gameWorld->level);
        copyScreen(pixelMap,disp);
    }
    
   free(gameWorld->shipList);
   free(gameWorld->player1);
   free(gameWorld->projList);
    if(gameWorld->player2 == NULL){//1 player
    *gameWorld = makeGame(gameWorld->level+1,1,gameWorld->score);
   }
   else{ //2 player
    free(gameWorld->player2);
     *gameWorld = makeGame(gameWorld->level+1,2,gameWorld->score);
   }
   free(*onscreen);
   *onscreen = (ship**)calloc(gameWorld->shipList_size,sizeof(ship*));
    
  for(int i = 0; i < WORLD_X_SIZE*WORLD_Y_SIZE; i++){
    colMap[i] = 0;
  }
   for(int i = 0; i < WORLD_X_SIZE*WORLD_Y_SIZE; i++){
    pixelMap[i] = 0;
  }

  *nShips = 0;
}

/*
 * ends the level once the end conditions have been reached
 */
void endLevelLoss(world* gameWorld,ship*** onscreen,short int* nShips,short int*colMap,short int* pixelMap){
    
    if(!detectStart()){
        
        drawGAMEOVER(pixelMap);       
        return;
    }
    
   free(gameWorld->shipList);
   free(gameWorld->player1);
   free(gameWorld->projList);
   if(gameWorld->player2 == NULL){//1 player
    *gameWorld = makeGame(1,1,0);
   }
   else{ //2 player
     free(gameWorld->player2);
     *gameWorld = makeGame(1,2,0);
   }
   
   free(*onscreen);
   *onscreen = (ship**)calloc(gameWorld->shipList_size,sizeof(ship*));
    
  for(int i = 0; i < WORLD_X_SIZE*WORLD_Y_SIZE; i++){
    colMap[i] = 0;
  }
   for(int i = 0; i < WORLD_X_SIZE*WORLD_Y_SIZE; i++){
    pixelMap[i] = 0;
  }


  *nShips = 0;
}

short int copyScreen(short int* pixelMap,Display& disp){
	vector<Pixel> pixels;
	unsigned int index = 0;
	pixels.resize( XRES * YRES );
	for ( int y = 0; y < YRES; ++y )
        {
                for ( int x = 0; x < XRES; ++x )
                {
                        Pixel & pixel = pixels[index];
						
                        pixel.b = ((pixelMap[index]&BLUEMASK)<<4) * 1.0f / 255.0f;
                        pixel.g = ((pixelMap[index]&GREENMASK)>>2)* 1.0f / 255.0f;
                        pixel.r = ((pixelMap[index]&REDMASK)>>7) * 1.0f / 255.0f;

                        ++index;
                }
        }

	GlobalsEng::semVGA->WaitOne();
	disp.update( pixels );
	GlobalsEng::semVGA->Release();

	return disp.open();
}