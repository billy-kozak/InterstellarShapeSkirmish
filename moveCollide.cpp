#include "moveCollide.h"
#include <stdio.h>
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
short int collideDIM1(short int index,short int* colMap,int gameTime,short int* square, ship someShip){
    short int* shape = shapeDIM1();
    
    int row = index/DIM1_X;
    int col = index%DIM1_X;
    
    int thisY = row+someShip.y_pos;
    int thisX = col+someShip.x_pos;
    
    if(index < 0 || index >= DIM1_X*DIM1_Y){
        *square = 0;
        return 0;
    }
    else{
       if(shape[index]){
            if(thisY < 0 || thisY >= WORLD_Y_SIZE){
                *square = 0;
            }
            else if(thisX < 0 || thisX >= WORLD_X_SIZE){
                *square = 0;
            }
            else{
                *square = colMap[thisY*WORLD_X_SIZE + thisX];
                colMap[thisY*WORLD_X_SIZE + thisX] = squareFill(someShip.ID,gameTime);
            }
       }
       else{
           *square = 0;
       }     
        return 1;
    }
}
short int collideDIM2(short int index,short int* colMap,int gameTime,short int* square, ship someShip){
    short int* shape = shapeDIM2();
    
    int row = index/DIM2_X;
    int col = index%DIM2_X;
    
    int thisY = row+someShip.y_pos;
    int thisX = col+someShip.x_pos;
    
    if(index < 0 || index >= DIM2_X*DIM2_Y){
        *square = 0;
        return 0;
    }
    else{
       if(shape[index]){
            if(thisY < 0 || thisY >= WORLD_Y_SIZE){
                *square = 0;
            }
            else if(thisX < 0 || thisX >= WORLD_X_SIZE){
                *square = 0;
            }
            else{
                *square = colMap[thisY*WORLD_X_SIZE + thisX];
                colMap[thisY*WORLD_X_SIZE + thisX] = squareFill(someShip.ID,gameTime);
            }
       }
       else{
           *square = 0;
       }     
        return 1;
    }
}
short int collideDIM3(short int index,short int* colMap,int gameTime,short int* square, ship someShip){
    short int* shape = shapeDIM3();
    
    int row = index/DIM3_X;
    int col = index%DIM3_X;
    
    int thisY = row+someShip.y_pos;
    int thisX = col+someShip.x_pos;
    
    if(index < 0 || index >= DIM3_X*DIM3_Y){
        *square = 0;
        return 0;
    }
    else{
       if(shape[index]){
            if(thisY < 0 || thisY >= WORLD_Y_SIZE){
                *square = 0;
            }
            else if(thisX < 0 || thisX >= WORLD_X_SIZE){
                *square = 0;
            }
            else{
                *square = colMap[thisY*WORLD_X_SIZE + thisX];
                colMap[thisY*WORLD_X_SIZE + thisX] = squareFill(someShip.ID,gameTime);
            }
       }
       else{
           *square = 0;
       }     
        return 1;
    }
}

short int collideDIM4(short int index,short int* colMap,int gameTime,short int* square, ship someShip){
    short int* shape = shapeDIM4();
    
    int row = index/DIM4_X;
    int col = index%DIM4_X;
    
    int thisY = row+someShip.y_pos;
    int thisX = col+someShip.x_pos;
    
    if(index < 0 || index >= DIM4_X*DIM4_Y){
        *square = 0;
        return 0;
    }
   else{
       if(shape[index]){
            if(thisY < 0 || thisY >= WORLD_Y_SIZE){
                *square = 0;
            }
            else if(thisX < 0 || thisX >= WORLD_X_SIZE){
                *square = 0;
            }
            else{
                *square = colMap[thisY*WORLD_X_SIZE + thisX];
                colMap[thisY*WORLD_X_SIZE + thisX] = squareFill(someShip.ID,gameTime);
            }
       }
       else{
           *square = 0;
       }     
        return 1;
    }
}
short int collideDIM5(short int index,short int* colMap,int gameTime,short int* square, ship someShip){
    short int* shape = shapeDIM5();
    
    int row = index/DIM5_X;
    int col = index%DIM5_X;
    
    int thisY = row+someShip.y_pos;
    int thisX = col+someShip.x_pos;
    
    if(index < 0 || index >= DIM5_X*DIM5_Y){
        *square = 0;
        return 0;
    }
    else{
       if(shape[index]){
            if(thisY < 0 || thisY >= WORLD_Y_SIZE){
                *square = 0;
            }
            else if(thisX < 0 || thisX >= WORLD_X_SIZE){
                *square = 0;
            }
            else{
                *square = colMap[thisY*WORLD_X_SIZE + thisX];
                colMap[thisY*WORLD_X_SIZE + thisX] = squareFill(someShip.ID,gameTime);
            }
       }
       else{
           *square = 0;
       }     
        return 1;
    }
}
short int collideDIM6(short int index,short int* colMap,int gameTime,short int* square, ship someShip){
    short int* shape = shapeDIM6();
    
    int row = index/DIM6_X;
    int col = index%DIM6_X;
    
    int thisY = row+someShip.y_pos;
    int thisX = col+someShip.x_pos;
    
    if(index < 0 || index >= DIM6_X*DIM6_Y){
        *square = 0;
        return 0;
    }
    else{
       if(shape[index]){
            if(thisY < 0 || thisY >= WORLD_Y_SIZE){
                *square = 0;
            }
            else if(thisX < 0 || thisX >= WORLD_X_SIZE){
                *square = 0;
            }
            else{
                *square = colMap[thisY*WORLD_X_SIZE + thisX];
                colMap[thisY*WORLD_X_SIZE + thisX] = squareFill(someShip.ID,gameTime);
            }
       }
       else{
           *square = 0;
       }     
        return 1;
    }
}

short int collideDIM7(short int index,short int* colMap,int gameTime,short int* square, ship someShip){
    short int* shape = shapeUFO();
    
    int row = index/DIM7_X;
    int col = index%DIM7_X;
    
    int thisY = row+someShip.y_pos;
    int thisX = col+someShip.x_pos;
    
    if(index < 0 || index >= DIM7_X*DIM7_Y){
        *square = 0;
        return 0;
    }
    else{
       if(shape[index]){
            if(thisY < 0 || thisY >= WORLD_Y_SIZE){
                *square = 0;
            }
            else if(thisX < 0 || thisX >= WORLD_X_SIZE){
                *square = 0;
            }
            else{
                *square = colMap[thisY*WORLD_X_SIZE + thisX];
                colMap[thisY*WORLD_X_SIZE + thisX] = squareFill(someShip.ID,gameTime);
            }
       }
       else{
           *square = 0;
       }     
        return 1;
    }
}

short int collideDIM8(short int index,short int* colMap,int gameTime,short int* square, ship someShip){
    short int* shape = shapeROCKET();
    
    int row = index/DIM8_X;
    int col = index%DIM8_X;
    
    int thisY = row+someShip.y_pos;
    int thisX = col+someShip.x_pos;
    
    if(index < 0 || index >= DIM8_X*DIM8_Y){
        *square = 0;
        return 0;
    }
    else{
       if(shape[index]){
            if(thisY < 0 || thisY >= WORLD_Y_SIZE){
                *square = 0;
            }
            else if(thisX < 0 || thisX >= WORLD_X_SIZE){
                *square = 0;
            }
            else{
                *square = colMap[thisY*WORLD_X_SIZE + thisX];
                colMap[thisY*WORLD_X_SIZE + thisX] = squareFill(someShip.ID,gameTime);
            }
       }
       else{
           *square = 0;
       }     
        return 1;
    }
}

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
short int collideProjectiles(short int index,short int* colMap, int gameTime,short int* square, projectile someProj){
    short int* shape = shapePROJ();
    
    int row = index/DIMP_X;
    int col = index%DIMP_X;
    
    int thisY = row+someProj.y_pos;
    int thisX = col+someProj.x_pos;
    
    if(index < 0 || index >= DIMP_X*DIMP_Y){
        *square = 0;
        return 0;
    }
    else{
       if(shape[index]){
            if(thisY < 0 || thisY >= WORLD_Y_SIZE){
                *square = 0;
            }
            else if(thisX < 0 || thisX >= WORLD_X_SIZE){
                *square = 0;
            }
            else{
                *square = colMap[thisY*WORLD_X_SIZE + thisX];
                colMap[thisY*WORLD_X_SIZE + thisX] = squareFill(someProj.ID,gameTime);
            }
       }
       else{
           *square = 0;
       }     
        return 1;
    }
}
