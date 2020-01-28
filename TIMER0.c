#include "TIMER0.h"

static void timer0_set_prescaller(tTMR0_Prescaller);
    
static void timer0_set_mode(tTMR0_Mode);

static void timer0_ovf_setState(tTMR0_OVF_State);    

void timer0_init(tTMR0_Prescaller p,tTMR0_Mode m, tTMR0_OVF_State o){
    timer0_set_prescaller(p);
    
    timer0_set_mode(m);
    
    timer0_ovf_setState(o);
    
    switch(m){
        case T0_TIMER_MODE : 
            T0_timer_mode_state(T0_OFF);
            break;
        case T0_COUNTER_MODE : 
            T0_counter_mode_state(T0_OFF);
            break;
        default : 
            /* ** DO NOTHING ** */
            break;
    }
    
    timer0_reload(TMR0_START_VAL);
    
}

void timer0_reload(TMR0_SIZE val){
    /* ** PUT VAL IN TMR0_VAL_REG ** */
    TMR0_VAL_REG = val;
}
TMR0_SIZE timer0_getValue(void){
    /* ** RETURN TMR0_VAL_REG ** */
    return TMR0_VAL_REG;
}
void T0_timer_mode_state(tTMR0_State s){
    /* ** SWITCH STATE AND EXECUTE EACH ONE COMMAND ** */
    switch(s) {
        case T0_ON : 
            TMR0_TIMER_MODE;
            break;
        case T0_OFF : 
            TMR0_COUNTER_MODE;
            break;
        default:
            /* ** DO NOTHING ** */
            break;
    }
}

void T0_counter_mode_state(tTMR0_State s){
    /* ** SWITCH STATE AND EXECUTE EACH ONE COMMAND ** */
  
    switch(s) {
        case T0_ON : 
            TMR0_COUNTER_MODE;
            break;
        case T0_OFF : 
            TMR0_TIMER_MODE;
            break;
        default:
            /* ** DO NOTHING ** */
            break;
    }
}

static void timer0_set_prescaller(tTMR0_Prescaller p){
    /* ** SWITCH PRECALLER AND EXECUTE EACH ONE COMMAND ** */
    switch(p){
        case T0_PRESCALLER_2:
            TMR0_PRESCALLER_2;
            break;
        case T0_PRESCALLER_4:
            TMR0_PRESCALLER_4;
            break;
        case T0_PRESCALLER_8:
            TMR0_PRESCALLER_8;
            break;
        case T0_PRESCALLER_16:
            TMR0_PRESCALLER_16;
            break;
        case T0_PRESCALLER_32:
            TMR0_PRESCALLER_32;
            break;
        case T0_PRESCALLER_64:
            TMR0_PRESCALLER_64;
            break;
        case T0_PRESCALLER_128:
            TMR0_PRESCALLER_128;
            break;
        case T0_PRESCALLER_256:
            TMR0_PRESCALLER_256;
            break;
        default :
            /* ** DO NOTHING ** */
            break;
    }
}

static void timer0_set_mode(tTMR0_Mode m){
    /* ** SWITCH MODE AND EXECUTE EACH ONE COMMAND ** */
    switch(m){
        case T0_TIMER_MODE:
            TMR0_TIMER_MODE;
            break;
        case T0_COUNTER_MODE :
            TMR0_COUNTER_MODE;
            break;
        default : 
            /* ** DO NOTHING ** */
            break;
    }
}

static void timer0_ovf_setState(tTMR0_OVF_State o ){
    switch(o){
        case T0_OVF_ENABLE : 
            GLOBAL_INTERRUPT_ENABLE;
            TMR0_OVF_INT_ENABLE;
            break;
        case T0_OVF_DISABLE : 
            TMR0_OVF_INT_DISABLE;
            break;
        default : 
            /* ** DO NOTHING ** */
            break;
    }
}
