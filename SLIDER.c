/* 
    *** FILE : SLIDER.c
    *** AUTHOR : AHMED GALAL ASHOUR
    *** DATE : 28 / 8 / 2019
 */

/* *** DIRECTIVES *** */

#include "SLIDER.h"
#include "ADC.h"
#include "HARDWARE.h"

/* *** PRIVATE CONSTANTS *** */

#define         SLIDER_UPDATE_PERIOD                (20) /* *** 20 MS *** */
#define         SLIDER_CHANNEL                      (ADC_CH1)

/* *** PRIVATE DATATYPES *** */

/* *** PRIVATE VARIABLES *** */

static tWord SLIDER_val;

/* *** PRIVATE FUNCTIONS PROTOTYPE *** */

/* *** PUBLIC FUNCTIONS IMPLEMENTATION *** */

void SLIDER_init(void){

    /* *** INTIALIZE ADC *** */
    
    ADC_init();
    
}

void SLIDER_getVal(tWord * pVal){

    *pVal = SLIDER_val;
    
}

void SLIDER_update(void){
    
    static tByte SLIDER_counter = ZERO; 
    
    SLIDER_counter += SYSTEM_TICK;
    
    if(SLIDER_counter < SLIDER_UPDATE_PERIOD){
        return;
    }
    
    SLIDER_counter = ZERO;
    
    /* *** READ ADC VALUE *** */
    
    ADC_read(SLIDER_CHANNEL,&SLIDER_val);
    
}