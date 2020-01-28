/*
    *** FILE : DISPLAY.c
    *** AUTHOR : AHMED GALAL ASHOUR
    *** DATE : 28 / 8 / 2019
 */

/* *** DIRECTIVES *** */

#include "DISPLAY.h"
#include "LCD.h"
#include "SLIDER.h"
#include "HARDWARE.h"
#include "MICRO_CONTROLLER.h"

/* *** PRIVATE CONSTANTS *** */

#define     DSP_UPDATE_PERIOD           (20) /* *** 20 MS *** */

/* *** PUBLIC FUNCTIONS IMPLEMENTATION *** */

void DSP_init(void){

    /* *** INTIALIZE LCD *** */
    LCD_init(LCD_8_MODE);
    
    LCD_str("VOLUME : " , L1, C1);
}

void DSP_update(void){
    
    static tByte DSP_counter = ZERO;
    static tByte str [17]; 
    tWord i;
    tWord slider = ZERO;
    
    DSP_counter += SYSTEM_TICK;
    
    if (DSP_counter < DSP_UPDATE_PERIOD){
        return;
    }
    
    DSP_counter = ZERO;
    
    /* *** GET SLIDER VALUE *** */
    
    SLIDER_getVal(&slider);
    
    /* *** MAP VALUE TO STRING *** */
    
    for(i = 0; i < (slider / 63) ; i++){
        str[i] = '*';
    }
    
    while (i < 16) {
        str[i] = ' ';
        i++;
    }
    
    str[16] = '\0';
    
    /* *** SEND STRING TO LCD TO DISPLAY *** */
    
   LCD_str(str,L2,C1); /* *** THERE IS A PROBLEM *** */
}