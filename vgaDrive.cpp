#include "vgaDrive.h"
#include "world.h"

#include <stdlib.h>
#include "includes.h"
#include "graphics.h"
#include <stdio.h>

//#include "sys/alt_cache.h"
//#include "sys/alt_dma.h"

//semaphores to control access to dma
//OS_EVENT * sem1;

/**
 * these function called when the transmit and recieve requests are finished
 */
static void txdone(void* handle){
    // OSSemPost(sem2);
}

static void rxdone(void* handle){
    //OSSemPost(sem1);
}

/**
 * copy the frame as referred to by array to the screen
 * dstate is the strcuture given by initWrites
 * score Area is the copy of the score Area
 */
void copyScreen(short int* array,dmaState dstate){

/**
 * returns dmastate for input to copy screen
 */
dmaState initVGAwrites(){
        
    /*alt_dma_rxchan rxChan = alt_dma_rxchan_open(DMA_0_NAME);
    if(rxChan == NULL){
        printf("DMA access error\n"); 
    }
    
     alt_dma_txchan txChan = alt_dma_txchan_open (DMA_0_NAME);
     if(txChan == NULL){
        printf("DMA access error\n"); 
    }
    
     if( alt_dma_txchan_ioctl(txChan,ALT_DMA_SET_MODE_16,NULL) < 0){
        printf("io control error\n");
    }
    
     if( alt_dma_rxchan_ioctl(rxChan,ALT_DMA_SET_MODE_16,NULL) < 0){
        printf("io control error\n");
    }*/
    
    dmaState output = {0};
    
    return output;
}

/**
 * initialize semaphores needed for the frame buffer driver
 */
/*OS_EVENT * initVGASems(){
    
    sem1 = OSSemCreate(1);
    
    if(sem1 == NULL){
        printf("wth");
    }
    
    return sem1;
}*/

