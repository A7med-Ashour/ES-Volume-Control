/* 
 * File:   ADC.h
 * Author: A7med.G.Ashour
 *
 * Created on 26 ?????, 2019, 06:21 ?
 */

#ifndef ADC_H
#define	ADC_H
#include   "MICRO_CONTROLLER.h"

/* *** PUBLIC DATATYPE *** */
typedef enum {
    ADC_CH0 = 0,
    ADC_CH1,
    ADC_CH2,
    ADC_CH3,
    ADC_CH4,
    ADC_CH5,
    ADC_CH6,
    ADC_CH7
    
}tADC_Channel;

/* *** PUBLIC FUNCTIONS PROTOTYPE *** */

void ADC_init(void);
void ADC_read(tADC_Channel,tWord *);

#endif	/* ADC_H */

