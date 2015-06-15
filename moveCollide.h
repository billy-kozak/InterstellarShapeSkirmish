#ifndef MOVECOLLIDE
#define MOVECOLLIDE

#include "graphics.h"
#include "world.h"


/**
 * atempts to move a pixel of the given ship (the pixel being specified by index) to a target square in colMap
 * (target specified by ship coordinates and location of the specified pixel within the ship)
 * the adress pointed to by square will be filled with the value of the sqaure we are moving into
 * or zero if no squares in colMap were updated
 * 
 * the function returs zero if index specified a pixel outside of the bounds of the ship (can use like 
 * an iterator)
 * inputs:
 *  someShip: the ship we want to draw to the collison map
 *  colMap: the collision map
 *  index: specifies a pixel within the ship
 *  sqaure: address of a short int that will be updated with value of pixel we replaced (zero if nothing replaced)
 *  gameTime: current Time in game ticks
 * 
 * outputs:
 *  1 if index specified a pixel within the ships bounds
 *  0 otherwise
 */
short int collideDIM1(short int index,short int* colMap,int gameTime,short int* square, ship someShip);
short int collideDIM2(short int index,short int* colMap,int gameTime,short int* square, ship someShip);
short int collideDIM3(short int index,short int* colMap,int gameTime,short int* square, ship someShip);
short int collideDIM4(short int index,short int* colMap,int gameTime,short int* square, ship someShip);
short int collideDIM5(short int index,short int* colMap,int gameTime,short int* square, ship someShip);
short int collideDIM6(short int index,short int* colMap,int gameTime,short int* square, ship someShip);
short int collideDIM7(short int index,short int* colMap,int gameTime,short int* square, ship someShip);
short int collideDIM8(short int index,short int* colMap,int gameTime,short int* square, ship someShip);

/**
 * atempts to move a pixel of the given projectile (the pixel being specified by index) to a target square in colMap
 * (target specified by ship coordinates and location of the specified pixel within the projectile)
 * the adress pointed to by square will be filled with the value of the sqaure we are moving into
 * or zero if no squares in colMap were updated
 * 
 * the function returs zero if index specified a pixel outside of the bounds of the ship (can use like 
 * an iterator)
 * inputs:
 *  someShip: the ship we want to draw to the collison map
 *  colMap: the collision map
 *  index: specifies a pixel within the ship
 *  sqaure: address of a short int that will be updated with value of pixel we replaced (zero if nothing replaced)
 *  gameTime: current Time in game ticks
 * 
 * outputs:
 *  1 if index specified a pixel within the ships bounds
 *  0 otherwise
 */
short int collideProjectiles(short int index,short int* colMap, int gameTime,short int* square, projectile someProj);
#endif
