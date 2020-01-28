/*
 * File:   VolumeControl.c
 * Author: A7med.G.Ashour
 *
 * Created on 28 ?????, 2019, 09:56 ?
 */


#include <xc.h>
#include "SLIDER.h"
#include "DISPLAY.h"
#include "TIMER0.h"
#include "GPIO.h"

void main(void) {
    
    timer0_init(T0_PRESCALLER_256,T0_TIMER_MODE,T0_OVF_ENABLE);
    timer0_reload(216);
    SLIDER_init();
    DSP_init();
    GPIO_PIN_WRITE(GPIO_C_CTRL,GPIO_PIN_5,GPIO_OUTPUT);
    GPIO_PIN_WRITE(GPIO_C_DATA,GPIO_PIN_5,GPIO_LOW);
    T0_timer_mode_state(T0_ON);
    tWord val;
    while(1){
        //SLIDER_update();
        //DSP_update();
        //__delay_ms(5);
    }
}

void __interrupt (high_priority) ISR(void){
    
    if(TMR0_OVF_FLAG) {
        GPIO_PIN_TOGGLE(GPIO_C_DATA,GPIO_PIN_5);
        SLIDER_update();
        DSP_update();
        TMR0_OVF_FLAG = 0;
        timer0_reload(216);
        
    }
   
}
