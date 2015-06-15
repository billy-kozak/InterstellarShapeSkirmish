#include "AI.h"
#include "graphics.h"

/**YRe
A test AI routine that will do literally nothing
*/
void testAI(ship* someShip,char** map,world gameWorld)
{
    
}

short int routine1(ship* someShip,world* gameWorld)
{
    // aka "The B-LINE"
    someShip->last_x = someShip->x_pos;
    someShip->last_y = someShip->y_pos;
    
    someShip->y_pos++;
    
   if(someShip->last_y>240)
   {
    someShip->isAlive = 0;
    return 1;
   }
   return 0;
}

short int routine2(ship* someShip,world* gameWorld)
{
    // aka "The SNAKE"
    if(gameWorld->currentTime == someShip->startTime)
        someShip->x_accel = RIGHT;
    
    //MUST CHOOSE START LOC. APPROPRIATELY TO AVOID X-WRAPAROUND
    /*if(someShip->startLoc_x <= 10)
    {
        someShip->x_pos = someShip->x_pos + 10;
        someShip->startLoc_x = someShip->startLoc_x + 10;
    }*/
    
   
   someShip->last_x = someShip->x_pos;
   someShip->last_y = someShip->y_pos;
   
   if((int)someShip->x_accel == RIGHT)
   {
   someShip->x_pos++;
        if(abs(someShip->x_pos - someShip->y_accel) >= 25)
        {
            someShip->x_accel = LEFT;
        }
   someShip->y_pos = someShip->y_pos + abs(someShip->x_pos - someShip->y_accel)/10;
   }
   else if((int)someShip->x_accel == LEFT)
   {
   someShip->x_pos--;
        if(abs(someShip->x_pos - someShip->y_accel) >= 25)
        {
            someShip->x_accel = RIGHT;
        }
   someShip->y_pos = someShip->y_pos + abs(someShip->x_pos - someShip->y_accel)/10;
   }
   
   if(someShip->last_y>240)
   {
    someShip->isAlive = 0;
   }
   if(gameWorld->currentTime%50 == 0)
   {
   
    makeProjectile(someShip->x_pos+DIM1_X/2, someShip->y_pos+DIM1_Y, NONE, 2, gameWorld,AI_PROJECTILE);
   }
   return 0;
}



short int routine3(ship* someShip,world* gameWorld)
{
    // aka "The Invader"    
   someShip->last_x = someShip->x_pos;
   someShip->last_y = someShip->y_pos;
   
   if(someShip->last_x == (WORLD_X_SIZE - DIM1_X))
   {
    someShip->x_accel = LEFT;
    someShip->y_pos = someShip->y_pos + 10;
    someShip->x_pos--;
   }
   else if(someShip->last_x == 0)
   {
    someShip->x_accel = RIGHT;
    someShip->y_pos = someShip->y_pos + 10;
    someShip->x_pos++;
   }
   else if(someShip->last_y>240)
   {
    someShip->isAlive = 0;
    return 1;
   }
   else
   {
       if((int)someShip->x_accel == RIGHT)
       someShip->x_pos++;
       if((int)someShip->x_accel == LEFT)
       someShip->x_pos--;
   } 
   
   if(gameWorld->currentTime%50 == 0)
   {
   
    makeProjectile(someShip->x_pos+DIM1_X/2, someShip->y_pos+DIM1_Y, NONE, 2, gameWorld,AI_PROJECTILE);
   }
   return 0;
}

short int routine4(ship* someShip,world* gameWorld)
{
    // aka "The Bounce"    
   someShip->last_x = someShip->x_pos;
   someShip->last_y = someShip->y_pos;
   
   if(someShip->last_x == (WORLD_X_SIZE - DIM2_X))
    someShip->x_accel = LEFT;
   if(someShip->last_x == 0)
    someShip->x_accel = RIGHT;
   if(someShip->last_y == 0)
    someShip->y_accel = DOWN;
   if(someShip->last_y == (WORLD_Y_SIZE - DIM2_Y))
    someShip->y_accel = UP;
    
   if((int)someShip->x_accel == RIGHT)
    someShip->x_pos++;
   if((int)someShip->x_accel == LEFT)
    someShip->x_pos--;
   if((int)someShip->y_accel == UP)
    someShip->y_pos--;
   if((int)someShip->y_accel == DOWN)
    someShip->y_pos++;
    
    if(gameWorld->currentTime%25 == 0)
   {
    
    makeProjectile(someShip->x_pos+DIM1_X/2, someShip->y_pos+DIM1_Y, 0, 4, gameWorld,AI_PROJECTILE);
   }
    
    return 0;
}
