/**
This header describes functions that initilize all data structures and populate the game world
*/

#ifndef INITILIZATION
#define INITILIZATION

#include "world.h"
#include <stdio.h>

//maximum line size of every line of the input file
#define LINE_SIZE 256
//max enemies is 2^6 since first two bits reserved to ID players and projectiles
#define MAX_ENEMIES 64

//tokens for parsing and their string lengths
#define ENEMY_COUNT_TOKEN "nenemies"
#define ENEMY_COUNT_LEN 8

#define BACKGROUND_TOKEN "background"
#define BACKGROUND_LEN 10

#define ENEMY_TOKEN "enemy"
#define ENEMY_LEN 5

#define OBJECTIVE_TOKEN "objective"
#define OBJECTIVE_LEN 9

#define PLAYER_TOKEN "player"
#define PLAYER_LEN 6

#define SCORE_TOKEN "score"
#define SCORE_LEN 5

#define MAX_HEALTH 5

/**
Inputs: 
level - the number of the level we want
numPlayers - the number of players in the game

Returns: the initialized World object ready to be played
*/
world makeGame(short int level, short int numPlayers,int score);

/**
 * initialization of level 1
 */
world level1(world gameWorld);
world level2(world gameWorld);
world level3(world gameWorld);

/**
Initilizes the game map to be all empty
Inputs:
	map - the game's WORLD_X_SIZE by WORLD_Y_SIZE map
*/
void initMap(char** map);


#endif
