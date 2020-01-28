/* 
    *** FILE : ADC.c
    *** AUTHOR : AHMED GALAL ASHOUR
    *** DATE : 26 / 8 / 2019
 */


/* *** DIRECTIVES *** */

#include    "MICRO_CONTROLLER.h"
#include    "ADC.h"
#include    "GPIO.h"

/* *** PRIVATE CONSTANTS *** */




void ADC_init(void){
    
    /* *** MAKE SELECTED CHANNELS AS INPUT *** */
    GPIO_PIN_WRITE(GPIO_A_CTRL,GPIO_PIN_1,GPIO_INPUT);
    
    /* *** MAKE ADC OFF *** */
    ADC_OFF;
    
    /* *** SET ADC CONFIGURATION *** */
    ADC_PORT_CONFIG;
    
    /* *** SET ADC CLK  REMEMBER THAT THE MINIMUM TAD IS 1.6 US *** */
    ADC_CLOCK_SELECT(ADC_CLK_FOSC_8);
    
    /* *** SET ADC JUSTIFY WAY *** */
    ADC_JUSTIFY(ADC_ADJUST_RIGHT);
    
    /* *** ENABLE ADC INTERRUPT IF YOU WANT TO USE IT IN FREE RUNNING MODE *** */
    
}
void ADC_read(tADC_Channel ch,tWord * pval){
    
   /* *** ADC ON *** */
   ADC_ON;
    
    /* *** SELECT ADC CHANNEL *** */
    ADC_CHANNEL_SELECT(ch);

    /* *** WAIT ACQUISITION TIME MINIMUM 20 US *** */
    __delay_us(30);
    
    /* *** ADC START CONVERSION *** */
   ADC_START_CONVERSION;
    
    /* *** WAIT FOR ADC CONVERSION TO END *** YOU CAN USE FREE RUNNING MODE TO AVOID THIS WAITING PART ***  */
    while(ADC_CONVERSION_IN_PROGRESS);
    
    
    /* *** PUT ADC VALUE INTO PASSED POINTER *** */
    *pval = ADC_VAL(ADC_ADJUST_RIGHT);
    
     /* *** ADC OFF *** */
    ADC_OFF;
    
}