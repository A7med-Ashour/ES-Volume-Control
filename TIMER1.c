/* 
    *** FILE : TIMER1.c
    *** AUTHOR : AHMED GALAL ASHOUR
    *** DATE : 22 / 8 / 2019
 */

/* **** DIRECTIVES **** */

#include    "TIMER1.h"
#include    "MICRO_CONTROLLER.h"

/* **** PUBLIC FUNCTIONS IMPLEMENTATION **** */

void TMR1_init(TMR1_Prescaller p , TMR1_Mode m , TMR1_OVF_State s){
    
    /* *** SET PRESCALLER AND MODE AND OVF STATE ***  */
    
    switch(p){
        
        case TMR1_PRS_1 :
            TMR1_PRESCALLER_1;
            break;
            
        case TMR1_PRS_2 :
            TMR1_PRESCALLER_2;
            break;
            
        case TMR1_PRS_4:
            TMR1_PRESCALLER_4;
            break;
            
        case TMR1_PRS_8 : 
            TMR1_PRESCALLER_8;
            break;
            
        default : 
            break;
    }
    
    switch(m) {
        
        case TMR1_TMR_MODE :
            TMR1_TIMER_MODE;
            break;
            
        case TMR1_CNT_MODE :
            TMR1_COUNTER_MODE;
            break;
            
        default : 
            break;
    }
    
    switch(s) {
        case TMR1_OVF_EN :
            GLOBAL_INTERRUPT_ENABLE;
            PERIPHERAL_INTERRUPT_ENABLE;
            TMR1_OVF_INT_ENABLE;
            break;
            
        case TMR1_OVF_DS : 
            TMR1_OVF_INT_DISABLE;
            break;
            
        default:
            break;
    }
    
}

void TMR1_reload(TMR1_SIZE val) {

    /* *** SET VAL INTO TMR 1 REGISTER *** */
    
    TMR1L_R.Reg = val;
    TMR1H_R.Reg = val >> 8;
    
}

void TMR1_getVal(TMR1_SIZE * pval){
    
    /* *** PUT TMR1 VAL INTO THIS POINTER *** */
    *pval = (((tWord)(TMR1H_R.Reg)) << 8) | (TMR1L_R.Reg);
}

void TMR1_setState(TMR1_State s){
    
    switch(s) {
        
        case TMR1_ON_STATE:
            TMR1_ON;
            break;
            
        case TMR1_OFF_STATE : 
            TMR1_OFF;
            break;
            
        default : 
            break;
    }
}