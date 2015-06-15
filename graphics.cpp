/**
This file will interpret game data and handle VGA output
**/
#include "graphics.h"
#include "initialization.h"
#include <stdio.h>
#include "colors.h"

short int* shapeDIM1()
{ 
    //THE "SPOT-MARKER" 15x15
   static short int array[] = {
        R,R,R,R,Z,Z,Z,Z,Z,Z,Z,R,R,R,R,
        R,R,R,R,R,Z,Z,Z,Z,Z,R,R,R,R,R,
        R,R,R,R,R,R,Z,Z,Z,R,R,R,R,R,R,
        R,R,R,R,R,R,R,Z,R,R,R,R,R,R,R,
        Z,R,R,R,R,R,R,R,R,R,R,R,R,R,Z,
        Z,Z,R,R,R,R,R,R,R,R,R,R,R,Z,Z,
        Z,Z,Z,R,R,R,R,R,R,R,R,R,Z,Z,Z,
        Z,Z,Z,Z,R,R,R,R,R,R,R,Z,Z,Z,Z,
        Z,Z,Z,R,R,R,R,R,R,R,R,R,Z,Z,Z,
        Z,Z,R,R,R,R,R,R,R,R,R,R,R,Z,Z,
        Z,R,R,R,R,R,R,R,R,R,R,R,R,R,Z,
        R,R,R,R,R,R,R,Z,R,R,R,R,R,R,R,
        R,R,R,R,R,R,Z,Z,Z,R,R,R,R,R,R,
        R,R,R,R,R,Z,Z,Z,Z,Z,R,R,R,R,R,
        R,R,R,R,Z,Z,Z,Z,Z,Z,Z,R,R,R,R
    };
        
    return array;
}

void drawDIM1(short int* array,ship ship)
{
    short int *shape = shapeDIM1();
    
 int count = 0;
 for(int i = ship.y_pos; i < ship.y_pos + DIM1_Y; i++)
 {
    for(int n = ship.x_pos; n < ship.x_pos + DIM1_X; n++){
     if(shape[count]!=0)
     {
        if( ((i*WORLD_X_SIZE +n) > 0) && ((i*WORLD_X_SIZE +n) < (WORLD_X_SIZE*WORLD_Y_SIZE)) )
        array[i*320 + n] = shape[count];
     }
    count++;
    }
  }
   //printf("printed once\n");
 return;
}

short int* shapeDIM2()
{ 
    //aka "HOMER's FAVE" 15x15
   static short int array[] = {
        Z,Z,Z,Z,Z,P,P,P,P,P,Z,Z,Z,Z,Z,
        Z,Z,Z,P,P,P,P,P,P,P,P,P,Z,Z,Z,
        Z,Z,P,P,P,P,P,P,P,P,P,P,P,Z,Z,
        Z,P,P,P,P,P,P,P,P,P,P,P,P,P,Z,
        Z,P,P,P,P,P,Z,Z,Z,P,P,P,P,P,Z,
        P,P,P,P,P,Z,Z,Z,Z,Z,P,P,P,P,P,
        P,P,P,P,Z,Z,Z,Z,Z,Z,Z,P,P,P,P,
        P,P,P,P,Z,Z,Z,Z,Z,Z,Z,P,P,P,P,
        P,P,P,P,Z,Z,Z,Z,Z,Z,Z,P,P,P,P,
        P,P,P,P,P,Z,Z,Z,Z,Z,P,P,P,P,P,
        Z,P,P,P,P,P,Z,Z,Z,P,P,P,P,P,Z,
        Z,P,P,P,P,P,P,P,P,P,P,P,P,P,Z,
        Z,Z,P,P,P,P,P,P,P,P,P,P,P,Z,Z,
        Z,Z,Z,P,P,P,P,P,P,P,P,P,Z,Z,Z,
        Z,Z,Z,Z,Z,P,P,P,P,P,Z,Z,Z,Z,Z,
    };
        
    return array;
}

void drawDIM2(short int* array,ship ship)
{
 short int *shape = shapeDIM2();    
    
 int count = 0;
 for(int i = ship.y_pos; i < ship.y_pos + DIM2_Y; i++)
 {
    for(int n = ship.x_pos; n < ship.x_pos + DIM2_X; n++){
     if(shape[count]!=0)
     {  
        if( ((i*WORLD_X_SIZE +n) > 0) && ((i*WORLD_X_SIZE +n) < (WORLD_X_SIZE*WORLD_Y_SIZE)) )
        array[i*320 + n] = shape[count];
     }
    count++;
    }
  }
   //printf("printed once\n");
 return;
}

short int* shapeDIM3()
{ 
    //GREEN TRIANGLE OF DOOOOOM 15x15
    static short int array[] = {
        G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,
        G,G,G,G,G,G,G,G,G,G,G,G,G,G,G,
        Z,G,G,G,G,G,G,G,G,G,G,G,G,G,Z,
        Z,G,G,G,G,G,G,G,G,G,G,G,G,G,Z,
        Z,Z,G,G,G,G,G,G,G,G,G,G,G,Z,Z,
        Z,Z,G,G,G,G,G,G,G,G,G,G,G,Z,Z,
        Z,Z,Z,G,G,G,G,G,G,G,G,G,Z,Z,Z,
        Z,Z,Z,G,G,G,G,G,G,G,G,G,Z,Z,Z,
        Z,Z,Z,Z,G,G,G,G,G,G,G,Z,Z,Z,Z,
        Z,Z,Z,Z,G,G,G,G,G,G,G,Z,Z,Z,Z,
        Z,Z,Z,Z,Z,G,G,G,G,G,Z,Z,Z,Z,Z,
        Z,Z,Z,Z,Z,G,G,G,G,G,Z,Z,Z,Z,Z,
        Z,Z,Z,Z,Z,Z,G,G,G,Z,Z,Z,Z,Z,Z,
        Z,Z,Z,Z,Z,Z,G,G,G,Z,Z,Z,Z,Z,Z,
        Z,Z,Z,Z,Z,Z,Z,G,Z,Z,Z,Z,Z,Z,Z,
    };
        
    return array;
}


void drawDIM3(short int* array,ship ship)
{
 short int *shape = shapeDIM3(); 
        
 int count = 0;
 for(int i = ship.y_pos; i < ship.y_pos + DIM3_Y; i++)
 {
    for(int n = ship.x_pos; n < ship.x_pos + DIM3_X; n++){
     if(shape[count]!=0)
     {
       if( ((i*WORLD_X_SIZE +n) > 0) && ((i*WORLD_X_SIZE +n) < (WORLD_X_SIZE*WORLD_Y_SIZE)) )
        array[i*320 + n] = shape[count];
     }
    count++;
    }
  }
   //printf("printed once\n");
 return;
}

short int* shapeDIM4()
{ 
    //yellow sQUARE 15x15
    static short int array[] = {
        Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,
        Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,
        Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,
        Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,
        Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,
        Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,
        Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,
        Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,
        Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,
        Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,
        Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,
        Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,
        Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,
        Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,
        Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y,Y
    };
        
    return array;
}

void drawDIM4(short int* array,ship ship)
{
 //Boring old square 15x15, color can be changed with change of macro
 for(int i = ship.y_pos; i < ship.y_pos + DIM4_Y; i++)
 {
    for(int n = ship.x_pos; n < ship.x_pos + DIM4_X; n++){
     //printf("wtf?\n");   
     if( ((i*WORLD_X_SIZE +n) > 0) && ((i*WORLD_X_SIZE +n) < (WORLD_X_SIZE*WORLD_Y_SIZE)) )
        array[i*320 + n] = Y;
    //count++;
    }
  }
   //printf("printed once\n");
 return;
}

short int* shapeDIM5()
{ 
   //"ADDITION IN ORANGE" 15x15
   static short int array[] = { 
   Z,Z,Z,Z,Z,O,O,O,O,O,Z,Z,Z,Z,Z,
   Z,Z,Z,Z,Z,O,O,O,O,O,Z,Z,Z,Z,Z, 
   Z,Z,Z,Z,Z,O,O,O,O,O,Z,Z,Z,Z,Z, 
   Z,Z,Z,Z,Z,O,O,O,O,O,Z,Z,Z,Z,Z, 
   Z,Z,Z,Z,Z,O,O,O,O,O,Z,Z,Z,Z,Z, 
   O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
   O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
   O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
   O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
   O,O,O,O,O,O,O,O,O,O,O,O,O,O,O,
   Z,Z,Z,Z,Z,O,O,O,O,O,Z,Z,Z,Z,Z,       
   Z,Z,Z,Z,Z,O,O,O,O,O,Z,Z,Z,Z,Z, 
   Z,Z,Z,Z,Z,O,O,O,O,O,Z,Z,Z,Z,Z, 
   Z,Z,Z,Z,Z,O,O,O,O,O,Z,Z,Z,Z,Z, 
   Z,Z,Z,Z,Z,O,O,O,O,O,Z,Z,Z,Z,Z,
  };
        
    return array;
}

void drawDIM5(short int* array,ship ship)
{
 short int *shape = shapeDIM5(); 
    
 int count = 0;
 for(int i = ship.y_pos; i < ship.y_pos + DIM5_Y; i++)
 {
    for(int n = ship.x_pos; n < ship.x_pos + DIM5_X; n++){
      if(shape[count]!=0)
      {
        if( ((i*WORLD_X_SIZE +n) > 0) && ((i*WORLD_X_SIZE +n) < (WORLD_X_SIZE*WORLD_Y_SIZE)) )
        array[i*320 + n] = shape[count];
      }
      count++;
    }
  }
   //printf("printed once\n");
 return;
}

short int* shapeDIM6()
{ 
   //"BLUE DIAMOND" 15x15
   static short int array[] = { 
   Z,Z,Z,Z,Z,Z,Z,B,Z,Z,Z,Z,Z,Z,Z,
   Z,Z,Z,Z,Z,Z,B,B,B,Z,Z,Z,Z,Z,Z, 
   Z,Z,Z,Z,Z,B,B,B,B,B,Z,Z,Z,Z,Z, 
   Z,Z,Z,Z,B,B,B,B,B,B,B,Z,Z,Z,Z, 
   Z,Z,Z,B,B,B,B,B,B,B,B,B,Z,Z,Z, 
   Z,Z,B,B,B,B,B,B,B,B,B,B,B,Z,Z,
   Z,B,B,B,B,B,B,B,B,B,B,B,B,B,Z,
   B,B,B,B,B,B,B,B,B,B,B,B,B,B,B,
   Z,B,B,B,B,B,B,B,B,B,B,B,B,B,Z,
   Z,Z,B,B,B,B,B,B,B,B,B,B,B,Z,Z,
   Z,Z,Z,B,B,B,B,B,B,B,B,B,Z,Z,Z,       
   Z,Z,Z,Z,B,B,B,B,B,B,B,Z,Z,Z,Z, 
   Z,Z,Z,Z,Z,B,B,B,B,B,Z,Z,Z,Z,Z, 
   Z,Z,Z,Z,Z,Z,B,B,B,Z,Z,Z,Z,Z,Z, 
   Z,Z,Z,Z,Z,Z,Z,B,Z,Z,Z,Z,Z,Z,Z
  };
        
    return array;
}

void drawDIM6(short int* array,ship ship)
{
 short int *shape = shapeDIM6(); 
    
 int count = 0;
 for(int i = ship.y_pos; i < ship.y_pos + DIM6_Y; i++)
 {
    for(int n = ship.x_pos; n < ship.x_pos + DIM6_X; n++){
      if(shape[count]!=0)
      {
        if( ((i*WORLD_X_SIZE +n) > 0) && ((i*WORLD_X_SIZE +n) < (WORLD_X_SIZE*WORLD_Y_SIZE)) )
        array[i*320 + n] = shape[count];
      }
      count++;
    }
  }
   //printf("printed once\n");
 return;
}

short int* shapeUFO()
{ 
   //"P2" 15x15 BLUEUFO
   static short int array[] = { 
   Z,Z,Z,Z,Z,L,L,L,L,L,Z,Z,Z,Z,Z,
   Z,Z,Z,Z,L,L,L,L,W,L,L,Z,Z,Z,Z, 
   Z,Z,Z,L,L,L,L,W,L,W,L,L,Z,Z,Z, 
   Z,Z,Z,L,L,L,L,L,W,L,L,L,Z,Z,Z, 
   Z,Z,Z,L,L,L,L,L,L,L,L,L,Z,Z,Z, 
   Z,S,S,S,L,L,L,L,L,L,L,S,S,S,Z,
   S,S,S,W,W,S,S,S,S,S,W,W,S,S,S,
   S,S,W,W,S,S,S,S,S,S,S,W,W,S,S,
   S,W,W,S,S,S,S,S,S,S,S,S,W,W,S,
   Z,M,S,S,S,S,S,S,S,S,S,S,S,M,Z,
   Z,Z,M,M,M,M,M,M,M,M,M,M,M,Z,Z,       
   Z,Z,S,B,B,L,W,W,W,L,B,B,S,Z,Z, 
   Z,Z,S,B,B,L,L,W,L,L,B,B,S,Z,Z, 
   Z,S,S,Z,B,B,L,L,L,B,B,Z,S,S,Z, 
   S,S,Z,Z,Z,B,B,L,B,B,Z,Z,Z,S,S,
  };
        
    return array;
}

void drawDIM7(short int* array,ship ship)
{
 short int *shape = shapeUFO(); 
    
 int count = 0;
 for(int i = ship.y_pos; i < ship.y_pos + DIM7_Y; i++)
 {
    for(int n = ship.x_pos; n < ship.x_pos + DIM7_X; n++){
      if(shape[count]!=0)
      {
        if( ((i*WORLD_X_SIZE +n) > 0) && ((i*WORLD_X_SIZE +n) < (WORLD_X_SIZE*WORLD_Y_SIZE)) )
        array[i*320 + n] = shape[count];
      }
      count++;
    }
  }
   //printf("printed once\n");
 return;
}

short int* shapeROCKET()
{ 
   //"P1" 15x15 REDROCKET
   static short int array[] = { 
   Z,Z,Z,Z,Z,Z,Z,R,Z,Z,Z,Z,Z,Z,Z,
   Z,Z,Z,Z,Z,Z,R,R,R,Z,Z,Z,Z,Z,Z, 
   Z,Z,Z,Z,Z,R,R,R,R,R,Z,Z,Z,Z,Z, 
   Z,Z,Z,Z,S,R,R,R,R,R,S,Z,Z,Z,Z, 
   Z,Z,Z,M,S,S,R,R,R,S,S,M,Z,Z,Z, 
   Z,Z,Z,M,S,S,S,S,S,W,S,M,Z,Z,Z,
   Z,Z,R,M,S,S,S,S,S,W,S,M,R,Z,Z,
   Z,R,R,M,S,S,S,S,S,W,S,M,R,R,Z,
   R,R,R,M,S,S,S,S,S,W,S,M,R,R,R,
   R,R,R,M,S,S,S,S,S,W,S,M,R,R,R,
   R,R,Z,M,S,S,S,S,S,S,S,M,Z,R,R, 
   R,Z,Z,R,R,O,Y,Y,Y,O,R,R,Z,Z,R,  
   Z,Z,Z,R,R,O,O,Y,O,O,R,R,Z,Z,Z, 
   Z,Z,Z,Z,R,R,O,O,O,R,R,Z,Z,Z,Z, 
   Z,Z,Z,Z,Z,R,R,O,R,R,Z,Z,Z,Z,Z,
  };
        
    return array;
}

short int* shapeEXPLODE1()
{ 
   //"P2" 15x15 EXPOSION STAGE1
   static short int array[] = { 
   Z,Z,Z,Z,Z,Z,R,R,R,Z,Z,Z,Z,Z,Z,
   Z,R,R,R,Z,R,R,R,R,R,Z,R,R,R,Z,
   Z,R,R,R,R,O,O,O,O,O,R,R,R,R,Z,
   Z,R,R,R,O,O,O,O,O,O,O,R,R,R,Z,
   Z,Z,R,O,O,O,Y,Y,Y,O,O,O,R,Z,Z,
   Z,R,R,O,O,Y,Y,W,Y,Y,O,O,R,R,Z,
   R,R,O,O,Y,Y,W,W,W,Y,Y,O,O,R,R,
   R,R,O,O,Y,Y,W,W,W,Y,Y,O,O,R,R,
   R,R,O,O,Y,Y,W,W,W,Y,Y,O,O,R,R,
   Z,R,O,O,O,Y,Y,W,Y,Y,O,O,O,R,Z,
   Z,Z,R,O,O,O,Y,Y,Y,O,O,O,R,Z,Z,
   Z,R,R,R,O,O,O,O,O,O,O,R,R,R,Z,
   Z,R,R,R,R,O,O,O,O,O,R,R,R,R,Z,
   Z,R,R,R,Z,R,R,R,R,R,Z,R,R,R,Z,
   Z,Z,Z,Z,Z,Z,R,R,R,Z,Z,Z,Z,Z,Z,
  };
  
      return array;
}

short int* shapeEXPLODE2()
{ 
   //15x15 EXPOSION STAGE2
   static short int array[] = { 
   Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,
   Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,
   Z,Z,Z,Z,Z,Z,R,R,R,Z,Z,Z,Z,Z,Z,
   Z,Z,Z,Z,R,R,R,R,R,R,R,Z,Z,Z,Z,
   Z,Z,Z,R,R,O,O,O,O,O,R,R,Z,Z,Z,
   Z,Z,Z,R,O,O,O,Y,O,O,O,R,Z,Z,Z,
   Z,Z,R,R,O,O,Y,Y,Y,O,O,R,R,Z,Z,
   Z,Z,R,R,O,Y,Y,Y,Y,Y,O,R,R,Z,Z,
   Z,Z,R,R,O,O,Y,Y,Y,O,O,R,R,Z,Z,
   Z,Z,Z,R,O,O,O,Y,O,O,O,R,Z,Z,Z,
   Z,Z,Z,R,R,O,O,O,O,O,R,R,Z,Z,Z,
   Z,Z,Z,Z,R,R,R,R,R,R,R,Z,Z,Z,Z,
   Z,Z,Z,Z,Z,Z,R,R,R,Z,Z,Z,Z,Z,Z,
   Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,
   Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,
  };
  
  return array;
}

short int* shapeEXPLODE3()
{ 
   //15x15 EXPOSION STAGE3
   static short int array[] = { 
   Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,
   Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,
   Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,
   Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,
   Z,Z,Z,Z,Z,Z,R,R,R,Z,Z,Z,Z,Z,Z,
   Z,Z,Z,Z,Z,R,O,O,O,R,Z,Z,Z,Z,Z,
   Z,Z,Z,Z,R,O,O,Y,O,O,R,Z,Z,Z,Z,
   Z,Z,Z,Z,R,O,Y,Y,Y,O,R,Z,Z,Z,Z,
   Z,Z,Z,Z,R,O,O,Y,O,O,R,Z,Z,Z,Z,
   Z,Z,Z,Z,Z,R,O,O,O,R,Z,Z,Z,Z,Z,
   Z,Z,Z,Z,Z,Z,R,R,R,Z,Z,Z,Z,Z,Z,
   Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,
   Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,
   Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,
   Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,Z,
  };
        
    return array;
}

void drawDIM8(short int* array,ship ship)
{
 short int *shape = shapeROCKET(); 
    
 int count = 0;
 for(int i = ship.y_pos; i < ship.y_pos + DIM8_Y; i++)
 {
    for(int n = ship.x_pos; n < ship.x_pos + DIM8_X; n++){
      if(shape[count]!=0)
      {
        if( ((i*WORLD_X_SIZE +n) > 0) && ((i*WORLD_X_SIZE +n) < (WORLD_X_SIZE*WORLD_Y_SIZE)) )
        array[i*320 + n] = shape[count];
      }
      count++;
    }
  }
   //printf("printed once\n");
 return;
}

short int* shapePROJ()
{ 
   //"tiny white square" 2x2
   static short int array[] = { 
   W,W,W,W
  };
        
    return array;
}

void drawPROJ(short int* array,projectile proj)
{
 short int *shape = shapePROJ(); 
    
 int count = 0;
 for(int i = proj.y_pos; i < proj.y_pos + DIMP_Y; i++)
 {
    for(int n = proj.x_pos; n < proj.x_pos + DIMP_X; n++){
      if(shape[count]!=0)
      {
        if( ((i*WORLD_X_SIZE +n) > 0) && ((i*WORLD_X_SIZE +n) < (WORLD_X_SIZE*WORLD_Y_SIZE)) )
        array[i*320 + n] = shape[count];
      }
      count++;
    }
  }
   //printf("printed once\n");
 return;
}



short int* shapeHEALTH_G()
{
    static short int array[] = {G,G,G};   
    return array;
}

short int* shapeHEALTH_Y()
{
    static short int array[] = {Y,Y,Y};   
    return array;
}

short int* shapeHEALTH_R()
{
    static short int array[] = {R,R,R};   
    return array;
}

short int* shapeHEALTH_Z()
{
    static short int array[] = {Z,Z,Z};   
    return array;
}

void draw15x15(short int* array, short int* shape, int x, int y)
{
 int count = 0;
 for(int i = y; i < y+DIM1_Y; i++)
 {
    for(int n = x; n < x + DIM1_X; n++){
      if(shape[count]!=0)
      {
        array[i*320 + n] = shape[count];
      }
      count++;
    }
  }
   //printf("printed once\n");
 return;
}

void drawHEALTH(short int* array, short int* shape, int x, int y)
{
    int count = 0;
 for(int i = y; i < y+3; i++)
 {
    for(int n = x; n <= x ; n++)
    {
      array[i*320 + n] = shape[count];
      count++;
    }
  }
   //printf("printed once\n");
 return;
}

/////////////////////////////////////////////////

void eraseDIM1(short int* array, ship ship)
{    
    short int *shape = shapeDIM1();  
    int count = 0; 
 for(int i = ship.last_y; i < ship.last_y + DIM1_Y; i++)
 {
    for(int n = ship.last_x; n < ship.last_x + DIM1_X; n++)
    {
       if(shape[count]!=0)
       {
        if( ((i*WORLD_X_SIZE +n) > 0) && ((i*WORLD_X_SIZE +n) < (WORLD_X_SIZE*WORLD_Y_SIZE)) )
        array[i*WORLD_X_SIZE + n] = 0;
       }
       count++;
    }
  }
}

void eraseDIM2(short int* array, ship ship)
{    
    short int *shape = shapeDIM2();  
    int count = 0; 
 for(int i = ship.last_y; i < ship.last_y + DIM2_Y; i++)
 {
    for(int n = ship.last_x; n < ship.last_x + DIM2_X; n++)
    {
       if(shape[count]!=0)
       {
       if( ((i*WORLD_X_SIZE +n) > 0) && ((i*WORLD_X_SIZE +n) < (WORLD_X_SIZE*WORLD_Y_SIZE)) )
        array[i*WORLD_X_SIZE + n] = 0;
       }
       count++;
    }
  }
}

void eraseDIM3(short int* array, ship ship)
{
    short int *shape = shapeDIM3();  
    int count = 0; 
 for(int i = ship.last_y; i < ship.last_y + DIM3_Y; i++)
 {
    for(int n = ship.last_x; n < ship.last_x + DIM3_X; n++){
       if(shape[count]!=0)
       {
        if( ((i*WORLD_X_SIZE +n) > 0) && ((i*WORLD_X_SIZE +n) < (WORLD_X_SIZE*WORLD_Y_SIZE)) )
        array[i*WORLD_X_SIZE + n] = 0;
       }
       count++;
    }
  }
}

void eraseDIM4(short int* array, ship ship)
{
 for(int i = ship.last_y; i < ship.last_y + DIM4_Y; i++)
 {
    for(int n = ship.last_x; n < ship.last_x + DIM4_X; n++){
     //printf("wtf?\n");   
    if( ((i*WORLD_X_SIZE +n) > 0) && ((i*WORLD_X_SIZE +n) < (WORLD_X_SIZE*WORLD_Y_SIZE)) )
    array[i*320 + n] = Z;
    }
  }
}

void eraseDIM5(short int* array, ship ship)
{
    short int *shape = shapeDIM5();  
    int count = 0; 
 for(int i = ship.last_y; i < ship.last_y + DIM5_Y; i++)
 {
    for(int n = ship.last_x; n < ship.last_x + DIM5_X; n++){
       if(shape[count]!=0)
       {
        if( ((i*WORLD_X_SIZE +n) > 0) && ((i*WORLD_X_SIZE +n) < (WORLD_X_SIZE*WORLD_Y_SIZE)) )
        array[i*WORLD_X_SIZE + n] = 0;
       }
       count++;
    }
  }
}

void eraseDIM6(short int* array, ship ship)
{
    short int *shape = shapeDIM6();  
    int count = 0; 
 for(int i = ship.last_y; i < ship.last_y + DIM6_Y; i++)
 {
    for(int n = ship.last_x; n < ship.last_x + DIM6_X; n++){
       if(shape[count]!=0)
       {
        if( ((i*WORLD_X_SIZE +n) > 0) && ((i*WORLD_X_SIZE +n) < (WORLD_X_SIZE*WORLD_Y_SIZE)) )
        array[i*WORLD_X_SIZE + n] = 0;
       }
       count++;
    }
  }
}

void eraseDIM7(short int* array, ship ship)
{
    short int *shape = shapeUFO();  
    int count = 0; 
 for(int i = ship.last_y; i < ship.last_y + DIM7_Y; i++)
 {
    for(int n = ship.last_x; n < ship.last_x + DIM7_X; n++){
       if(shape[count]!=0)
       {
        if( ((i*WORLD_X_SIZE +n) > 0) && ((i*WORLD_X_SIZE +n) < (WORLD_X_SIZE*WORLD_Y_SIZE)) )
        array[i*WORLD_X_SIZE + n] = 0;
       }
       count++;
    }
  }
}

void eraseDIM8(short int* array, ship ship)
{
    short int *shape = shapeROCKET();  
    int count = 0; 
 for(int i = ship.last_y; i < ship.last_y + DIM8_Y; i++)
 {
    for(int n = ship.last_x; n < ship.last_x + DIM8_X; n++){
       if(shape[count]!=0)
       {
        if( ((i*WORLD_X_SIZE +n) > 0) && ((i*WORLD_X_SIZE +n) < (WORLD_X_SIZE*WORLD_Y_SIZE)) )
        array[i*WORLD_X_SIZE + n] = 0;
       }
       count++;
    }
  }
}

void erasePROJ(short int* array, projectile proj)
{
    short int *shape = shapePROJ();  
    int count = 0; 
    
 for(int i = proj.last_y; i < proj.last_y + DIMP_Y; i++)
 {
    for(int n = proj.last_x; n < proj.last_x + DIMP_X; n++){
       if(shape[count]!=0)
       {
        if( ((i*WORLD_X_SIZE +n) > 0) && ((i*WORLD_X_SIZE +n) < (WORLD_X_SIZE*WORLD_Y_SIZE)) ){
            array[i*WORLD_X_SIZE + n] = 0;
        }
       }
       count++;
    }
  }
}

void printHEALTH(short int health, short int* array, int x, int y, int player)
{   
    short int * shape;
    short int * eraseShape = shapeHEALTH_Z();
    if(health != 0){
    if(health == 1)
        shape = shapeHEALTH_R();
    else if(MAX_HEALTH/health >= 2)
        shape = shapeHEALTH_Y();
    else shape = shapeHEALTH_G();
	}
        
    int writeStart = 0;
    int writeEnd = (60/MAX_HEALTH)*health;
    int i;
    if (player == 1)
    {
        for(i = writeStart; i < writeEnd; i++)
        {
             drawHEALTH(array, shape, i+x, y);
        }
        for( ; i < 60; i++)
        {
            drawHEALTH(array, eraseShape, i+x, y);
        }
    }
    else if (player == 2)
    {
        writeStart = 60-(60/MAX_HEALTH)*health;
        for(i = 0; i < writeStart; i++)
        {
            drawHEALTH(array, eraseShape, i+x, y);
        }
        for(i = writeStart; i < 60; i++)
        {
             drawHEALTH(array, shape, i+x, y);
        }
    }
    
}
