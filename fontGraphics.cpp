#include "fontGraphics.h"
#include "initialization.h"
#include <stdio.h>
#include "colors.h"

/**
 * 
 */
scoreArea initScoreArea(short int* topofframe){
    short int* pixels = topofframe + WORLD_X_SIZE*WORLD_Y_SIZE;
    
    scoreArea output;
    output.pixels = pixels;
    output.score = 0;
    output.update = 0;
    output.p1health = 0;
    output.p2health = 0;
    
    int i = 0;
    //draw scoreborder
    for(i; i < SCORE_AREA_X; i++)
    {
        output.pixels[i] = S;
    }
    for(i; i < SCORE_AREA_X*2; i++)
    {
        if(i%2 == 1)
        output.pixels[i] = Z;
        else output.pixels[i] = S;
    }
    for(i; i < SCORE_AREA_X*3; i++)
    {
        output.pixels[i] = S;
    }
    for(i; i< SCORE_AREA_X*SCORE_AREA_Y; i++)
    {
        output.pixels[i] = O;
    }
    
    //draw health bars
    //P1
    for(i = SCORE_AREA_X*13+18; i < SCORE_AREA_X*13+79; i++)
    {
        output.pixels[i] = W;
    }
    for(i = SCORE_AREA_X*17+18; i < SCORE_AREA_X*17+79; i++)
    {
        output.pixels[i] = W;
    }
    output.pixels[SCORE_AREA_X*14+18] = W;
    output.pixels[SCORE_AREA_X*15+18] = W;
    output.pixels[SCORE_AREA_X*16+18] = W;
    output.pixels[SCORE_AREA_X*14+79] = W;
    output.pixels[SCORE_AREA_X*15+79] = W;
    output.pixels[SCORE_AREA_X*16+79] = W;
    //P2
    for(i = SCORE_AREA_X*13+241; i < SCORE_AREA_X*13+302; i++)
    {
        output.pixels[i] = W;
    }
    for(i = SCORE_AREA_X*17+241; i < SCORE_AREA_X*17+302; i++)
    {
        output.pixels[i] = W;
    }
    output.pixels[SCORE_AREA_X*14+301] = W;
    output.pixels[SCORE_AREA_X*15+301] = W;
    output.pixels[SCORE_AREA_X*16+301] = W;
    output.pixels[SCORE_AREA_X*14+240] = W;
    output.pixels[SCORE_AREA_X*15+240] = W;
    output.pixels[SCORE_AREA_X*16+240] = W;
    

    //draw "SCORE:"
    int x = 150;
    int y = 5;
    short int * shape = shapeALPHA_S();
    drawALPHANUM(output.pixels, shape, x, y);
    shape = shapeALPHA_C();
    drawALPHANUM(output.pixels, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_O();
    drawALPHANUM(output.pixels, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_R();
    drawALPHANUM(output.pixels, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_E();
    drawALPHANUM(output.pixels, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_COLON();
    drawALPHANUM(output.pixels, shape, x = x+DIMALPHANUM_X+1, y);
    
    printScore(0, output.pixels, 139+DIMSCORE_X, 12);
    
    //draw P1 ship, "P1 HEALTH"
    shape = shapeROCKET();
    draw15x15(output.pixels, shape, 1, 4);
    x = 18;
    y = 6;
    shape = shapeALPHA_P();
    drawALPHANUM(output.pixels, shape, x, y);
    shape = shapeNUM_1();
    drawALPHANUM(output.pixels, shape, x = x+DIMALPHANUM_X+1, y);
    x = x+DIMALPHANUM_X+1; // space
    shape = shapeALPHA_H();
    drawALPHANUM(output.pixels, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_E();
    drawALPHANUM(output.pixels, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_A();
    drawALPHANUM(output.pixels, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_L();
    drawALPHANUM(output.pixels, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_T();
    drawALPHANUM(output.pixels, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_H();
    drawALPHANUM(output.pixels, shape, x = x+DIMALPHANUM_X+1, y);
    
    //draw P2 ship, "P2 HEALTH"
    shape = shapeUFO();
    draw15x15(output.pixels, shape, XRES-DIM1_X-1, 4);
    x = XRES-DIM1_X-2-(DIMALPHANUM_X+1)*9;
    y = 6;
    shape = shapeALPHA_P();
    drawALPHANUM(output.pixels, shape, x, y);
    shape = shapeNUM_2();
    drawALPHANUM(output.pixels, shape, x = x+DIMALPHANUM_X+1, y);
    x = x+DIMALPHANUM_X+1; // space
    shape = shapeALPHA_H();
    drawALPHANUM(output.pixels, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_E();
    drawALPHANUM(output.pixels, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_A();
    drawALPHANUM(output.pixels, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_L();
    drawALPHANUM(output.pixels, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_T();
    drawALPHANUM(output.pixels, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_H();
    drawALPHANUM(output.pixels, shape, x = x+DIMALPHANUM_X+1, y);
    
    // used only for testing printHEALTH
    printHEALTH(MAX_HEALTH, output.pixels, P1_HEALTH_X, HEALTH_Y, 1);
    printHEALTH(MAX_HEALTH, output.pixels, P2_HEALTH_X, HEALTH_Y, 2);
    
    return output;
}


/**
 * updates the scoreArea structure that scoreBar points to according to the gameWorld structure and
 * some internal logic: the score and health of both players are updated accordingly.
 */
void updateScoreArea(world gameWorld,scoreArea* scoreBar){
    if(gameWorld.currentTime%SCORE_AREA_UPDATE_FREQUENCY == 0){
        if(gameWorld.score != scoreBar->score){
            scoreBar->update = 1;
            scoreBar->score = gameWorld.score;
            printScore(scoreBar->score, scoreBar->pixels, 139+DIMSCORE_X, 12);
        }
        if(gameWorld.player1->health != scoreBar->p1health){
            scoreBar->update = 1;
            scoreBar->p1health = gameWorld.player1->health;
            printHEALTH(scoreBar->p1health, scoreBar->pixels, P1_HEALTH_X, HEALTH_Y, 1);
        }
        if(gameWorld.player2 != NULL){
            if(gameWorld.player2->health != scoreBar->p2health){
                scoreBar->update = 1;
                scoreBar->p2health = gameWorld.player2->health;
                printHEALTH(scoreBar->p2health, scoreBar->pixels, P2_HEALTH_X, HEALTH_Y, 2);
            }
        }
    }
}

/**
 * Simple function to draw any letter or number that conforms to 3x5 dimensions
 */
void drawALPHANUM(short int* array, short int* shape, int x, int y)
{
 int count = 0;
 for(int i = y; i < y+DIMALPHANUM_Y; i++)
 {
    for(int n = x; n < x + DIMALPHANUM_X; n++){
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


// ************   DEFINITION OF FONT SHAPES ******************** //
short int* shapeALPHA_S()
{ 
   //3x3
   static short int array[] = { 
   W,W,W,
   W,Z,Z,
   W,W,W,
   Z,Z,W,
   W,W,W
  };
        
    return array;
}

short int* shapeALPHA_C()
{ 
   //3x3
   static short int array[] = { 
   W,W,W,
   W,Z,Z,
   W,Z,Z,
   W,Z,Z,
   W,W,W
  };
        
    return array;
}

short int* shapeALPHA_O()
{ 
   //3x3
   static short int array[] = { 
   W,W,W,
   W,Z,W,
   W,Z,W,
   W,Z,W,
   W,W,W
  };
        
    return array;
}

short int* shapeALPHA_R()
{ 
   //3x3
   static short int array[] = { 
   W,W,W,
   W,Z,W,
   W,W,Z,
   W,Z,W,
   W,Z,W
  };
        
    return array;
}

short int* shapeALPHA_E()
{ 
   //5x3
   static short int array[] = { 
   W,W,W,
   W,Z,Z,
   W,W,W,
   W,Z,Z,
   W,W,W
  };
        
    return array;
}

short int* shapeALPHA_P()
{ 
   //3x3
   static short int array[] = { 
   W,W,W,
   W,Z,W,
   W,W,W,
   W,Z,Z,
   W,Z,Z
  };
        
    return array;
}

short int* shapeALPHA_T()
{ 
   //3x3
   static short int array[] = { 
   W,W,W,
   Z,W,Z,
   Z,W,Z,
   Z,W,Z,
   Z,W,Z
  };
        
    return array;
}

short int* shapeALPHA_A()
{ 
   //3x3
   static short int array[] = { 
   W,W,W,
   W,Z,W,
   W,W,W,
   W,Z,W,
   W,Z,W
  };
        
    return array;
}

short int* shapeALPHA_H()
{ 
   //3x3
   static short int array[] = { 
   W,Z,W,
   W,Z,W,
   W,W,W,
   W,Z,W,
   W,Z,W
  };
        
    return array;
}

short int* shapeALPHA_L()
{ 
   //3x3
   static short int array[] = { 
   W,Z,Z,
   W,Z,Z,
   W,Z,Z,
   W,Z,Z,
   W,W,W
  };
        
    return array;
}

short int* shapeALPHA_I()
{ 
   //3x3
   static short int array[] = { 
   W,W,W,
   Z,W,Z,
   Z,W,Z,
   Z,W,Z,
   W,W,W
  };
        
    return array;
}

short int* shapeALPHA_G()
{ 
   //3x3
   static short int array[] = { 
   W,W,W,
   W,Z,Z,
   W,Z,W,
   W,Z,W,
   W,W,W
  };
        
    return array;
}

short int* shapeALPHA_V()
{ 
   //3x3
   static short int array[] = { 
   W,Z,W,
   W,Z,W,
   W,Z,W,
   W,Z,W,
   Z,W,Z
  };
        
    return array;
}

short int* shapeALPHA_M()
{ 
   //3x3
   static short int array[] = { 
   W,Z,W,
   W,W,W,
   W,Z,W,
   W,Z,W,
   W,Z,W
  };
        
    return array;
}

short int* shapeALPHA_Y()
{ 
   //3x3
   static short int array[] = { 
   W,Z,W,
   W,Z,W,
   W,W,W,
   Z,Z,W,
   W,W,W
  };
        
    return array;
}

short int* shapeALPHA_N()
{ 
   //3x3
   static short int array[] = { 
   W,Z,W,
   W,W,W,
   W,W,W,
   W,Z,W,
   W,Z,W
  };
        
    return array;
}

short int* shapeALPHA_K()
{ 
   //3x3
   static short int array[] = { 
   W,Z,W,
   W,Z,W,
   W,W,Z,
   W,Z,W,
   W,Z,W
  };
        
    return array;
}

short int* shapeALPHA_COLON()
{ 
   //3x3
   static short int array[] = { 
   Z,Z,Z,
   Z,W,Z,
   Z,Z,Z,
   Z,Z,Z,
   Z,W,Z
  };
        
    return array;
}

short int* shapeALPHA_EXCLAMATION()
{ 
   //3x3
   static short int array[] = { 
   Z,W,Z,
   Z,W,Z,
   Z,W,Z,
   Z,Z,Z,
   Z,W,Z
  };
        
    return array;
}

short int* shapeNUM_0()
{ 
   //3x3
   static short int array[] = { 
   Z,W,Z,
   W,Z,W,
   W,Z,W,
   W,Z,W,
   Z,W,Z
  };
        
    return array;
}

short int* shapeNUM_1()
{ 
   //3x3
   static short int array[] = { 
   Z,W,Z,
   W,W,Z,
   Z,W,Z,
   Z,W,Z,
   W,W,W
  };
        
    return array;
}

short int* shapeNUM_2()
{ 
   //3x3
   static short int array[] = { 
   W,W,W,
   Z,Z,W,
   W,W,W,
   W,Z,Z,
   W,W,W
  };
        
    return array;
}

short int* shapeNUM_3()
{ 
   //3x3
   static short int array[] = { 
   W,W,W,
   Z,Z,W,
   W,W,W,
   Z,Z,W,
   W,W,W
  };
        
    return array;
}

short int* shapeNUM_4()
{ 
   //3x3
   static short int array[] = { 
   W,Z,W,
   W,Z,W,
   W,W,W,
   Z,Z,W,
   Z,Z,W
  };
        
    return array;
}

short int* shapeNUM_5()
{ 
   //3x3
   static short int array[] = { 
   W,W,W,
   W,Z,Z,
   W,W,W,
   Z,Z,W,
   W,W,W
  };
        
    return array;
}

short int* shapeNUM_6()
{ 
   //3x3
   static short int array[] = { 
   W,W,W,
   W,Z,Z,
   W,W,W,
   W,Z,W,
   W,W,W
  };
        
    return array;
}

short int* shapeNUM_7()
{ 
   //3x3
   static short int array[] = { 
   W,W,W,
   Z,Z,W,
   Z,Z,W,
   Z,Z,W,
   Z,Z,W
  };
        
    return array;
}

short int* shapeNUM_8()
{ 
   //3x3
   static short int array[] = { 
   W,W,W,
   W,Z,W,
   W,W,W,
   W,Z,W,
   W,W,W
  };
        
    return array;
}

short int* shapeNUM_9()
{ 
   //3x3
   static short int array[] = { 
   W,W,W,
   W,Z,W,
   W,W,W,
   Z,Z,W,
   W,W,W
  };
        
    return array;
}

// ************ END OF FONT SHAPE DEFINITIONS ***************** //

/**
 * Given an integer score input, this function prints out using the font numbers defined above
 * a 10-digit score equivalent to the int input, extending zeroes where needed
 */
void printScore(int score, short int* array, int x, int y)
{
    int num;
    short int * shape;
    eraseScore(array, x-DIMSCORE_X+3, y);
    
    for(int i = 0; i < 10; i++)
    {
        num = score%10;
        
        if(num == 1)
        {
            shape = shapeNUM_1(); 
            drawALPHANUM(array, shape, x, y);  
        }
        else if(num == 2)
        {
            shape = shapeNUM_2(); 
            drawALPHANUM(array, shape, x, y);   
        }
        else if(num == 3)
        {
            shape = shapeNUM_3(); 
            drawALPHANUM(array, shape, x, y);   
        }
        else if(num == 4)
        {
            shape = shapeNUM_4(); 
            drawALPHANUM(array, shape, x, y);   
        }
        else if(num == 5)
        {
            shape = shapeNUM_5(); 
            drawALPHANUM(array, shape, x, y);   
        }
        else if(num == 6)
        {
            shape = shapeNUM_6(); 
            drawALPHANUM(array, shape, x, y);   
        }
        else if(num == 7)
        {
            shape = shapeNUM_7(); 
            drawALPHANUM(array, shape, x, y);   
        }
        else if(num == 8)
        {
            shape = shapeNUM_8(); 
            drawALPHANUM(array, shape, x, y);   
        }
        else if(num == 9)
        {
            shape = shapeNUM_9(); 
            drawALPHANUM(array, shape, x, y);   
        }
        else
        {
            shape = shapeNUM_0(); 
            drawALPHANUM(array, shape, x, y);  
        }
        
        score/=10;
        x = x-DIMALPHANUM_X-1;
    }
    
}

/**
 * Called solely in the printScore() function to remove the previous score so it can be updated
 */
void eraseScore(short int * array, int x, int y)
{
    for(int i = y; i < y+DIMSCORE_Y; i++)
    {
        for(int n = x; n < x+DIMSCORE_X; n++)
        {
            //printf("%d %d\n", x,y);
            array[i*WORLD_X_SIZE + n] = O;
        }
    } 
}

/**
 * Prints "GAME OVER" to the screen in a predetermined location
 */
void drawGAMEOVER(short int* array)
{
    int x = 145;
    int y = 100;
    short int * shape = shapeALPHA_G();
    drawALPHANUM(array, shape, x, y);
    shape = shapeALPHA_A();
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_M();
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_E();
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
    
    x = x+DIMALPHANUM_X+1; // space
    
    shape = shapeALPHA_O();
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_V();
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_E();
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_R();
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
    
    //new line
    x = 141;
    y += 11;
    
    shape = shapeALPHA_P();
    drawALPHANUM(array, shape, x, y);
    shape = shapeALPHA_R();
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_E();
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_S();
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_S();
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
    
    x = x+DIMALPHANUM_X+1; // space
    
    shape = shapeALPHA_S();
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_T();
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_A();
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_R();
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_T();
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
}

/**
 * Prints "VICTORY!" to the screen in a predetermined location
 */
void drawVICTORY(short int* array,short int lastLevel)
{
    int x = 145;
    int y = 100;
    short int * shape = shapeALPHA_V();
    drawALPHANUM(array, shape, x, y);
    shape = shapeALPHA_I();
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_C();
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_T();
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_O();
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_R();
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_Y();
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_EXCLAMATION();
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
    
    x = 126;
    y = 120;
    
    shape = shapeALPHA_L();
    drawALPHANUM(array, shape, x, y);
    shape = shapeALPHA_E();
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_V();
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_E();
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_L();
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
    
    x = x+DIMALPHANUM_X+1; //space
    
    if(lastLevel == 1)
        shape = shapeNUM_1();
    else if (lastLevel == 2)
        shape = shapeNUM_2();
    else if (lastLevel == 3)
        shape = shapeNUM_3();
        
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
    
    x = x+DIMALPHANUM_X+1; //space
    x = x+DIMALPHANUM_X+1; //space
    
    shape = shapeALPHA_C();
    drawALPHANUM(array, shape, x, y);
    shape = shapeALPHA_O();
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_M();
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_P();
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_L();
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_E();
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_T();
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_E();
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_EXCLAMATION();
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
    
    x = 138;
    y += 11;
    
    shape = shapeALPHA_P();
    drawALPHANUM(array, shape, x, y);
    shape = shapeALPHA_R();
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_E();
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_S();
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_S();
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
    
    x = x+DIMALPHANUM_X+1; // space
    
    shape = shapeALPHA_S();
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_T();
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_A();
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_R();
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
    shape = shapeALPHA_T();
    drawALPHANUM(array, shape, x = x+DIMALPHANUM_X+1, y);
    
}   
