/* 
 * File:   TIMER0.h
 * Author: A7med.G.Ashour
 *
 * Created on 07 ?????, 2019, 10:16 ?
 */

#ifndef TIMER0_H
#define	TIMER0_H
#include "MICRO_CONTROLLER.h"

typedef enum{
    T0_PRESCALLER_2 ,
    T0_PRESCALLER_4,
    T0_PRESCALLER_8,
    T0_PRESCALLER_16,
    T0_PRESCALLER_32,
    T0_PRESCALLER_64,
    T0_PRESCALLER_128,
    T0_PRESCALLER_256
}tTMR0_Prescaller;

typedef enum {
    T0_TIMER_MODE,
    T0_COUNTER_MODE,
}tTMR0_Mode;

typedef enum {
    T0_ON,
    T0_OFF
}tTMR0_State;

typedef enum {
    T0_OVF_ENABLE,
    T0_OVF_DISABLE
}tTMR0_OVF_State;

void timer0_init(tTMR0_Prescaller,tTMR0_Mode,tTMR0_OVF_State);
void timer0_reload(TMR0_SIZE);
TMR0_SIZE timer0_getValue(void);
void T0_timer_mode_state(tTMR0_State);
void T0_counter_mode_state(tTMR0_State);
#endif	/* TIMER0_H */

