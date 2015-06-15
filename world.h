/**
The header file for world.c which will define a class to contain all nescearry
level data (in a performance optimized format) and functions to manipulate said
data
*/

#ifndef WORLD
#define WORLD

#define PLAYER_DAMAGE_MIN_TIME 10

//maximum allowed number of onscreen projectiles
#define MAX_PROJECTILES 45
//the number of AI functions that exist in this header
#define AI_COUNT 0
//size of the world array in pixels
#define WORLD_Y_SIZE 220
#define WORLD_X_SIZE 320

//if first MSB is set then this object has been updated this round
#define UPDATED_MASK 0x8000
//if second MSB is set then the object is a projectile
#define PROJECTILE_MASK 0x4000
//in the game map the player's number will always be this
#define RESERVED_PLAYER1_ID 0x3FFF
#define RESERVED_PLAYER2_ID 0X3FFE

//an empty space on the game map
#define EMPTY_SPACE 0x00

#define AI_PROJECTILE 1
#define PLAYER_PROJECTILE 2

/**
The ship structure specifies the state of any given ship
*/

struct _world;
struct _ship; //weirdness to deal with circular references

/**
This strucutre defines the location and direction of every projectile onscreen

every projectile should have a fixed speed
*/
typedef struct{

short int x_pos; 
short int y_pos; //current location of the projectile

short int last_x; 
short int last_y; //postion the projectile wants to go to

short int x_dir; 
short int y_dir; //the vector direction of the projectile

short int active; //true if the projectile exists onscreen

short int ID; //it's id on the game map

short int allignment;

}projectile; 

typedef struct _ship{
void (*drawPixels)(short int*,struct _ship);
void (*erase)(short int*,struct _ship);

/*
 *  someShip: the ship we want to draw to the collison map
 *  colMap: the collision map
 *  index: specifies a pixel within the ship
 *  sqaure: address of a short int that will be updated with value of pixel we replaced (zero if nothing replaced)
 *  gameTime: current Time in game ticks
 */
short int (*drawID)(short int index,short int* colMap,int gameTime,short int* square,struct _ship someShip);

int startTime; //time in game ticks when this ship should appear

short int dimensionID; //the id number that refers to this ship's dimensions

short int x_pos; //current position of this ship
short int y_pos;

short int x_accel; 
short int y_accel; //2D acceleration values

//the position that the ship would like to be in after the current game turn
//these values will then be subjected to collision detecion
short int last_x;
short int last_y;

//function pointer to the ship's AI routine
short int (*AI_routine)(struct _ship*,struct _world*);

short int ID; //it's id on the game map

short int isAlive; //set to true if the ship is alive

short int health;//amount of health of the ship
int lastHit;//time in game ticks of last time the player was hit, applies only to the player
}ship;

/**
This data structure will serve to contain initiliation data for a level
*/
typedef struct _world{

int levelEndTime; //level end time in game ticks

ship* shipList; //a pointer to the full list of ships for this level
short int shipList_size; //size of ship list

ship* player1; //the player ship
ship* player2; 

 //a list of projectiles of size MAX_PROJECTILES 
projectile* projList;
short int nProj; //number of currently active projectiles

int currentTime; //current Time in game ticks
short int level; //level we are currently on

int score;
}world; 

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
short int isFull(short int square, int gameTime);

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
short int isShip(short int square,short int* index);

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
short int isPlayer(short int square);

/**
 * returns the value that you should fill the collison map with when moving this object
 */
short int squareFill(short int id,int gameTime);

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
short int makeProjectile(int x, int y, int xdir, int ydir,world* gameWorld,char allignment);

#endif
