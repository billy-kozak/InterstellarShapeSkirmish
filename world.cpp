/**
defines a class to contain all nescearry
level data (in a performance optimized format) and functions to manipulate said
data
*/

#include "world.h"
#include <stdio.h>

/**
This function determines if the given square from the game map
has been updated this round and is therefore full
Inputs:
    sqaure - the value of the given square
    gameTime - the time in game ticks
Outpus:
    true if the square is occupied
    0 otherwise
*/
short int isFull(short int square, int gameTime){
    
  short int mask = UPDATED_MASK;
	
  if(square == EMPTY_SPACE){
		return 0; 
  }
    
	//if game time is odd UPDATED bit == 1 implies the square has been updated
	if(gameTime%2 == 0){
	 return mask&square;
	}
	
	return !(mask&square);
}

/**
 * This function determines if the given square contains the id# of a ship
 * if so it returns the position of the ship in it's list
 * always call isFull First to make sure that the square has been updated this turn
 * 
 * Inputs
 *  square: the value of the square in the collision map
 *  index: a pointer to an integer that will be filled with the index of a ship that occupies this square
 * 
 * Ouputs:
 *  true if the square is a ship, zero otherwise
 * 
 */
short int isShip(short int square,short int* index){
    
    short int mask = UPDATED_MASK;
    
    if(!(PROJECTILE_MASK&square)){
        *index = (square & (~mask)) - 1;
        return 1;
    }
    
    return 0;
}

/**
 * This function determines if the given square contains the id# of a player
 * if so it returns the player number
 * always call isFull First to make sure that the square has been updated this turn
 * 
 * Inputs
 *  the value of the square in the collision map
 * 
 * Ouputs:
 *  the player number if this is a player
 *  zero otherwise
 */
short int isPlayer(short int square){
    short int mask = UPDATED_MASK;
    mask = ~mask;
    if((square&mask) == RESERVED_PLAYER1_ID){
        return 1;
    }
    if((square&mask) == RESERVED_PLAYER2_ID){
        return 2;
    }  
    return 0;
}

/**
 * returns the value that you should fill the collison map with when moving this ship
 */
short int squareFill(short int id,int gameTime){
    
    //if game time is even set UPDATED bit to 1 on update
    short int mask = UPDATED_MASK;
    if(gameTime%2 == 0){
        
        return id| mask;
    }
    else return id;
}

/**
 * Creates a projectile at the target location with the specifies direction vectors
 * returns 0 if the projectile list is overflowing
 * 
 * intputs:
 * x: location where we will create the projectile
 * y: location where we will create the projectile
 * 
 * xdir: vector x direction
 * ydir: vector y direction
 * 
 * gameWorld: contains the list of projectiles and number of projectiles
 * 
 * outputs:
 * 0 if projectile list overflow
 * 1 otherwise
 */
short int makeProjectile(int x, int y, int xdir, int ydir,world* gameWorld,char allignment){
    
    projectile proj = {x,y,x,y,xdir,ydir,1,gameWorld->nProj|PROJECTILE_MASK,allignment};
 
    
    if((gameWorld->nProj+1) >= MAX_PROJECTILES){
        return 0;
    }
    else{
         for(int i = 0; i <  MAX_PROJECTILES;i++){
            if(!gameWorld->projList[i].active){
                gameWorld->projList[i] = proj;
                break;
            }
         }
         gameWorld->nProj++;
         return 1; 
    }
}
