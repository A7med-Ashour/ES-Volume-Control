/* 
 * File:   TIMER1.h
 * Author: A7med.G.Ashour
 *
 * Created on 22 ?????, 2019, 11:30 ?
 */

#ifndef TIMER1_H
#define	TIMER1_H

/* **** DIRECTIVE **** */

#include "MICRO_CONTROLLER.h"


/* **** PUBLIC CONSTANTS **** */

#define     TMR1_MAX            (65535)

/* **** PUBLIC DATA TYPE **** */

typedef enum {
    TMR1_TMR_MODE = 0,
    TMR1_CNT_MODE,
}TMR1_Mode;

typedef enum {
    TMR1_PRS_1 = 0,
    TMR1_PRS_2,
    TMR1_PRS_4,
    TMR1_PRS_8
}TMR1_Prescaller;

typedef enum {
    TMR1_OVF_EN = 0,
    TMR1_OVF_DS
}TMR1_OVF_State;

typedef enum {
    TMR1_ON_STATE,
    TMR1_OFF_STATE,        
}TMR1_State;
/* **** PUBLIC FUNCTIONS PROTOTYPE **** */

void TMR1_init(TMR1_Prescaller , TMR1_Mode , TMR1_OVF_State);
void TMR1_reload(TMR1_SIZE);
void TMR1_getVal(TMR1_SIZE *);
void TMR1_setState(TMR1_State);
#endif	/* TIMER1_H */

