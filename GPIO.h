/* 
 * File:   GPIO.h
 * Author: A7med.G.Ashour
 *
 * Created on 30 ?????, 2019, 07:08 ?
 */

#ifndef GPIO_H
#define	GPIO_H

#include "MICRO_CONTROLLER.h"

/* ****************** DIGITA INPUT AND OUTPUT REGISTERS  *********************** */

#define                 GPIO_A_CTRL                                                 (TRISA_R.Reg)
#define                 GPIO_A_DATA                                                 (PORTA_R.Reg)
#define                 GPIO_B_CTRL                                                 (TRISB_R.Reg)
#define                 GPIO_B_DATA                                                 (PORTB_R.Reg)
#define                 GPIO_C_CTRL                                                 (TRISC_R.Reg)
#define                 GPIO_C_DATA                                                 (PORTC_R.Reg)
#define                 GPIO_D_CTRL                                                 (TRISD_R.Reg)
#define                 GPIO_D_DATA                                                 (PORTD_R.Reg)
#define                 GPIO_E_CTRL                                                 (TRISE_R.Reg)
#define                 GPIO_E_DATA                                                 (PORTE_R.Reg)

#define                 GPIO_PIN_0                                                  (0)
#define                 GPIO_PIN_1                                                  (1)
#define                 GPIO_PIN_2                                                  (2)
#define                 GPIO_PIN_3                                                  (3)
#define                 GPIO_PIN_4                                                  (4)
#define                 GPIO_PIN_5                                                  (5)
#define                 GPIO_PIN_6                                                  (6)
#define                 GPIO_PIN_7                                                  (7)

#define                 GPIO_HIGH                                                   (1)
#define                 GPIO_LOW                                                    (0)

#define                 GPIO_OUTPUT                                                 (MCU_OUTPUT)  
#define                 GPIO_INPUT                                                  (MCU_INPUT)

#define                 ZERO                                                        (0)

/* *********** BIT MANIPULATION MACROS ***************** */

        /* ** FULL PORT ** */

#define                 GPIO_PORT_DIRECTION(PORT,DIR)                               ((PORT) = ((DIR) ? (~GPIO_LOW) : (GPIO_LOW))) //  to be generic in any MCU AND ANY REGISTER SIZE
#define                 GPIO_PORT_WRITE(PORT,VAL)                                   ((PORT) = (VAL))
#define                 GPIO_PORT_READ(PORT)                                        (PORT)

       /* ** SPECIFIC PIN ** */

#define                 GPIO_PIN_DIRECTION(CTRL,PIN,DIR)                            ((CTRL) = ((CTRL & (~(1 << PIN))) | (DIR << PIN)))
#define                 GPIO_PIN_WRITE(PORT,PIN,VAL)                                (GPIO_PIN_DIRECTION(PORT,PIN,VAL))
#define                 GPIO_PIN_READ(PORT,PIN)                                     ((PORT >> PIN) & (1))
#define                 GPIO_PIN_TOGGLE(PORT,PIN)                                   (GPIO_PIN_WRITE(PORT,PIN,!GPIO_PIN_READ(PORT,PIN)))




#endif	/* GPIO_H */

