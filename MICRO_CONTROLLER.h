/* 
 * File:   MICRO_CONTROLLER.h
 * Author: A7med.G.Ashour
 *
 * Created on 30 ?????, 2019, 07:09 ?
 */

#ifndef MICRO_CONTROLLER_H
#define	MICRO_CONTROLLER_H
#include "config.h"

#define     NO_MCU                      (0)
#define     PIC16F877A                  (1)
#define     PIC18F4620                  (2)
#define     ATMEGA32A                   (3)
#define     ATMEGA16A                   (4)

#define     MCU_NAME                    (PIC16F877A)   // MICRO CONTROLLER NAME


#if (MCU_NAME == PIC16F877A)


/* ************ DATA TYPES ****************** */

typedef     unsigned char               tByte;          // 8 bits
typedef     unsigned short int          tWord;          // 16 bits
typedef     unsigned long int           tDword;         /* *** 32 BITS *** */
typedef     float                       tFloat32;       /* *** 32 BIT FLOATING NUMBERS *** */
typedef     double                      tFloat64;       /* *** 64 BIT FLOATING NUMBERS *** */
typedef union {
    tByte Reg;
    struct{
        tByte BIT0 : 1;
        tByte BIT1 : 1;
        tByte BIT2 : 1;
        tByte BIT3 : 1;
        tByte BIT4 : 1;
        tByte BIT5 : 1;
        tByte BIT6 : 1;
        tByte BIT7 : 1;
    }Bits;
}tRegister8;

typedef union {
    tWord Reg;
    struct {
        tByte BIT0  : 1;
        tByte BIT1  : 1;
        tByte BIT2  : 1;
        tByte BIT3  : 1;
        tByte BIT4  : 1;
        tByte BIT5  : 1;
        tByte BIT6  : 1;
        tByte BIT7  : 1;
        tByte BIT8  : 1;
        tByte BIT9  : 1;
        tByte BIT10 : 1;
        tByte BIT11 : 1;
        tByte BIT12 : 1;
        tByte BIT13 : 1;
        tByte BIT14 : 1;
        tByte BIT15 : 1;
    }Bits;

}tRegister16;

#define         MCU_OUTPUT                      (0)
#define         MCU_INPUT                       (1)

/* *************** GPIO REGISTERS *************** */

#define         TRISA_R                         (*((volatile tRegister8 *)(0x85)))
#define         TRISB_R                         (*((volatile tRegister8 *)(0x86)))
#define         TRISC_R                         (*((volatile tRegister8 *)(0x87)))
#define         TRISD_R                         (*((volatile tRegister8 *)(0x88)))
#define         TRISE_R                         (*((volatile tRegister8 *)(0x89)))

#define         PORTA_R                         (*((volatile tRegister8 *)(0x05)))
#define         PORTB_R                         (*((volatile tRegister8 *)(0x06)))
#define         PORTC_R                         (*((volatile tRegister8 *)(0x07)))
#define         PORTD_R                         (*((volatile tRegister8 *)(0x08)))
#define         PORTE_R                         (*((volatile tRegister8 *)(0x09)))


/* *************** GENERAL REGISTERS *************** */

#define         INTCON_R                        (*((volatile tRegister8 *)(0x0B)))
#define         OPTION_REG_R                    (*((volatile tRegister8 *)(0x81)))
#define         PIR1_R                          (*((volatile tRegister8 *)(0x0C)))
#define         PIE1_R                          (*((volatile tRegister8 *)(0x8C)))
#define         PIR2_R                          (*((volatile tRegister8 *)(0x0D)))
#define         PIE2_R                          (*((volatile tRegister8 *)(0x8D)))


/* *************** INERRUPT COMMANDS *************** */

#define         GLOBAL_INTERRUPT_STATE              (INTCON_R.Bits.BIT7)
#define         GLOBAL_INTERRUPT_ENABLE             (INTCON_R.Bits.BIT7 = 1)
#define         GLOBAL_INTERRUPT_DISABLE            (INTCON_R.Bits.BIT7 = 0)
#define         PERIPHERAL_INTERRUPT_ENABLE         (INTCON_R.Bits.BIT6 = 1)
#define         PERIPHERAL_INTERRUPT_DISABLE        (INTCON_R.Bits.BIT6 = 0)

/* *************** TIMER 0 REGISTERS *************** */

#define         TMR0_R                          (*((volatile tRegister8 *)(0x01)))
#define         PRESC_VAL_BIT0                  (OPTION_REG_R.Bits.BIT0)
#define         PRESC_VAL_BIT1                  (OPTION_REG_R.Bits.BIT1)
#define         PRESC_VAL_BIT2                  (OPTION_REG_R.Bits.BIT2)
#define         PRESC_ASSIGNMENT_BIT            (OPTION_REG_R.Bits.BIT3)
#define         PRESC_TO_WDT                    (1)
#define         PRESC_TO_TMR0                   (0)
#define         TMR0_EDGE_BIT                   (OPTION_REG_R.Bits.BIT4)
#define         TMR0_CS_BIT                     (OPTION_REG_R.Bits.BIT5)
#define         TMR0_OVF_INT_EN_BIT             (INTCON_R.Bits.BIT5)
#define         TMR0_OVF_FLAG_BIT               (INTCON_R.Bits.BIT2)

/* *************** TIMER 0 COMMANDS *************** */

typedef         unsigned char                   TMR0_SIZE;

#define         TMR0_PRESCALLER_2               PRESC_ASSIGNMENT_BIT = PRESC_TO_TMR0;\
                                                 PRESC_VAL_BIT0 = 0;\
                                                 PRESC_VAL_BIT1 = 0;\
                                                 PRESC_VAL_BIT2 = 0

#define         TMR0_PRESCALLER_4               PRESC_ASSIGNMENT_BIT = PRESC_TO_TMR0;\
                                                 PRESC_VAL_BIT0 = 1;\
                                                 PRESC_VAL_BIT1 = 0;\
                                                 PRESC_VAL_BIT2 = 0

#define         TMR0_PRESCALLER_8               PRESC_ASSIGNMENT_BIT = PRESC_TO_TMR0;\
                                                 PRESC_VAL_BIT0 = 0;\
                                                 PRESC_VAL_BIT1 = 1;\
                                                 PRESC_VAL_BIT2 = 0

#define         TMR0_PRESCALLER_16              PRESC_ASSIGNMENT_BIT = PRESC_TO_TMR0;\
                                                 PRESC_VAL_BIT0 = 1;\
                                                 PRESC_VAL_BIT1 = 1;\
                                                 PRESC_VAL_BIT2 = 0

#define         TMR0_PRESCALLER_32              PRESC_ASSIGNMENT_BIT = PRESC_TO_TMR0;\
                                                 PRESC_VAL_BIT0 = 0;\
                                                 PRESC_VAL_BIT1 = 0;\
                                                 PRESC_VAL_BIT2 = 1

#define         TMR0_PRESCALLER_64              PRESC_ASSIGNMENT_BIT = PRESC_TO_TMR0;\
                                                 PRESC_VAL_BIT0 = 1;\
                                                 PRESC_VAL_BIT1 = 0;\
                                                 PRESC_VAL_BIT2 = 1

#define         TMR0_PRESCALLER_128             PRESC_ASSIGNMENT_BIT = PRESC_TO_TMR0;\
                                                 PRESC_VAL_BIT0 = 0;\
                                                 PRESC_VAL_BIT1 = 1;\
                                                 PRESC_VAL_BIT2 = 1

#define         TMR0_PRESCALLER_256             PRESC_ASSIGNMENT_BIT = PRESC_TO_TMR0;\
                                                 PRESC_VAL_BIT0 = 1;\
                                                 PRESC_VAL_BIT1 = 1;\
                                                 PRESC_VAL_BIT2 = 1

#define         TMR0_VAL_REG                    (TMR0_R.Reg)
#define         TMR0_START_VAL                  (0xFF)
#define         TMR0_TIMER_MODE                 (TMR0_CS_BIT = 0)                
#define         TMR0_COUNTER_MODE               (TMR0_CS_BIT = 1) 
#define         TMR0_COUNT_RISING               (TMR0_EDGE_BIT = 0)
#define         TMR0_COUNT_FALLING              (TMR0_EDGE_BIT = 1)
#define         TMR0_OVF_INT_ENABLE             (TMR0_OVF_INT_EN_BIT = 1)             
#define         TMR0_OVF_INT_DISABLE            (TMR0_OVF_INT_EN_BIT = 0)
#define         TMR0_OVF_FLAG                   (TMR0_OVF_FLAG_BIT)
#define         TMR0_ON                         ()
#define         TMR0_OFF                        ()



/* *************** TIMER 1 REGISTERS *************** */

#define         T1CON_R                         (*((volatile tRegister8 *)(0x10)))
#define         TMR1L_R                         (*((volatile tRegister8 *)(0x0E)))
#define         TMR1H_R                         (*((volatile tRegister8 *)(0x0F)))

/* *************** TIMER 0 COMMANDS *************** */

typedef         unsigned short int              TMR1_SIZE;

#define         TMR1_PRESCALLER_1               (T1CON_R.Reg = T1CON_R.Reg & 0x0F)

#define         TMR1_PRESCALLER_2               (T1CON_R.Reg = (T1CON_R.Reg & 0x0F) | (1 << 4))

#define         TMR1_PRESCALLER_4               (T1CON_R.Reg = (T1CON_R.Reg & 0x0F) | (2 << 4))

#define         TMR1_PRESCALLER_8               (T1CON_R.Reg = (T1CON_R.Reg & 0x0F) | (3 << 4))

#define         TMR1_TIMER_MODE                 (T1CON_R.Bits.BIT1 = 0)               
#define         TMR1_COUNTER_MODE               (T1CON_R.Bits.BIT1 = 1)
#define         TMR1_OVF_INT_ENABLE             (TMR1IE = 1)        
#define         TMR1_OVF_INT_DISABLE            (TMR1IE = 0)
#define         TMR1_OVF_FLAG                   (PIR1_R.Bits.BIT0)
#define         TMR1_ON                         (T1CON_R.Bits.BIT0 = 1)
#define         TMR1_OFF                        (T1CON_R.Bits.BIT0 = 0)


/* *************** ADC REGISTERS *************** */

#define         ADCON0_R                        (*((volatile tRegister8 *)(0x1F)))
#define         ADCON1_R                        (*((volatile tRegister8 *)(0x9F)))
#define         ADRESL_R                        (*((volatile tRegister8 *)(0x9E))
#define         ADRESH_R                        (*((volatile tRegister8 *)(0x1E)))

#define         ADC_CLK_SELECT_BIT0             (ADCON0_R.Bits.BIT6)
#define         ADC_CLK_SELECT_BIT1             (ADCON0_R.Bits.BIT7)
#define         ADC_CLK_SELECT_BIT2             (ADCON1_R.Bits.BIT6)

/* *************** ADC COMMANDS *************** */

#define     ADC_CLK_FOSC_2                  (0)
#define     ADC_CLK_FOSC_4                  (4)
#define     ADC_CLK_FOSC_8                  (1)
#define     ADC_CLK_FOSC_16                 (5)
#define     ADC_CLK_FOSC_32                 (2)
#define     ADC_CLK_FOSC_64                 (6)
#define     ADC_CLK_INTERNAL_RC             (7)

#define     ADC_CHANNEL_0                   (0)
#define     ADC_CHANNEL_1                   (1)
#define     ADC_CHANNEL_2                   (2)
#define     ADC_CHANNEL_3                   (3)
#define     ADC_CHANNEL_4                   (4)
#define     ADC_CHANNEL_5                   (5)
#define     ADC_CHANNEL_6                   (6)
#define     ADC_CHANNEL_7                   (7)


#define     ADC_CHANNEL_SELECT(ch)          (ADCON0_R.Reg = (ADCON0_R.Reg & 0xC7) | (ch << 3))          


#define     ADC_CLOCK_SELECT(clk)           ADC_CLK_SELECT_BIT0 = clk & 1;\
                                            ADC_CLK_SELECT_BIT1 = (clk & 2) >> 1;\
                                            ADC_CLK_SELECT_BIT2 = (clk & 4) >> 2;

#define     ADC_ON                         (ADCON0_R.Bits.BIT0 = 1)                           
#define     ADC_OFF                        (ADCON0_R.Bits.BIT0 = 0)
#define     ADC_START_CONVERSION           (ADCON0_R.Bits.BIT2 = 1)
#define     ADC_CONVERSION_IN_PROGRESS     (ADCON0_R.Bits.BIT2)
#define     ADC_ADJUST_RIGHT               (1)
#define     ADC_ADJUST_LEFT                (0)
#define     ADC_JUSTIFY(adj)               (ADCON1_R.Bits.BIT7 = adj)
#define     ADC_PORT_CONFIG                (ADCON1_R.Reg = (ADCON1_R.Reg & 0xF0) | (0x02))
#define     ADC_INTERRUPT_ENABLE           (PIE1_R.Bits.BIT6 = 1)
#define     ADC_INTERRUPT_DISABLE          (PIE1_R.Bits.BIT6 = 0)
#define     ADC_INTERRUPT_FLAG             (PIR1_R.Bits.BIT6)
#define     ADC_VAL(adj)                   ((adj) ? ( ( ( (tWord)(ADRESH)) << 8 ) | ADRESL ) :  ( ( ( (tWord) (ADRESH) ) << 2 ) | (ADRESH >> 6 ) ) )

/* **** TIMER2 REGISTERS ****  */

#define     T2CON_R                         (*((volatile tRegister8 *)(0x12)))
#define     TMR2_R                          (*((volatile tRegister8 *)(0x11)))
#define     PR2_R                           (*((volatile tRegister8 *)(0x92)))

/* **** TIMER2 COMMANDS ****  */

#define     TMR2_POST_SCALLER(POST)         (T2CON_R.Reg = (T2CON_R.Reg & 0x87) | (POST << 3))
#define     TMR2_PRE_SCALLER(PRE)           (T2CON_R.Reg = (T2CON_R.Reg & 0xFC) | (PRE))
#define     TMR2_ON                         (T2CON_R.Bits.BIT2 = 1)
#define     TMR2_OFF                        (T2CON_R.Bits.BIT2 = 0)  
#define     TMR2_RELAOD(VAL)                (TMR2_R.Reg = VAL)
#define     TMR2_INTERRUPT_ENABLE           (PIE1_R.Bits.BIT1 = 1)
#define     TMR2_INTERRUPT_DISABLE          (PIE1_R.Bits.BIT1 = 0)
#define     TMR2_INTERRUPT_FLAG             (PIR1_R.Bits.BIT1)

/* **** CCP1 REGISTERS ****  */

#define     CCP1CON_R                       (*((volatile tRegister8 *)(0x17)))             
#define     CCPR1L_R                        (*((volatile tRegister8 *)(0x15)))
#define     CCPR1H_R                        (*((volatile tRegister8 *)(0x16)))

/* **** CCP1 COMMANDS ****  */

#define     CCP1_MODE(mode)                 (CCP1CON_R.Reg = (CCP1CON_R.Reg & 0xF0) | (mode))

/* **** EEPROM REGISTERS **** */

#define     EEADR_R                         (*((volatile tRegister8 *)(0x10D)))
#define     EEDATA_R                        (*((volatile tRegister8 *)(0x10C)))
#define     EECON1_R                        (*((volatile tRegister8 *)(0x18C)))
#define     EECON2_R                        (*((volatile tRegister8 *)(0x18D)))

/* **** EEPROM COMMANDS **** */

#define     EEPROM_START_ADDRESS                (0x00)
#define     EEPROM_END_ADDRESS                  (0xFF)

#define     EEPROM_SET_ADDRESS(ADDR)        (EEADR_R.Reg = ADDR)
#define     EEPROM_SET_DATA(DATA)           (EEDATA_R.Reg = DATA)

#define     EEPROM_IS_BUSY                  (EECON1_R.Bits.BIT1 | EECON1_R.Bits.BIT0)

#define     EEPROM_START_WRITE              EECON1_R.Bits.BIT7 = 0;\
                                            EECON1_R.Bits.BIT2 = 1;\
                                            EECON2_R.Reg = 0x55;\
                                            EECON2_R.Reg = 0xAA;\
                                            EECON1_R.Bits.BIT1 = 1;\
                                            EECON1_R.Bits.BIT2 = 0

#define     EEPROM_GET_DATA                 (EEDATA_R.Reg)

#define     EEPROM_START_READ               EECON1_R.Bits.BIT7 = 0;\
                                            EECON1_R.Bits.BIT0 = 1;

#define     EEPROM_INTERRUPT_ENABLE         (PIE2_R.Bits.BIT4 = 1)   
#define     EEPROM_INTERRUPT_DISABLE        (PIE2_R.Bits.BIT4 = 0)      
#define     EEPROM_INTERRUPT_FLAG           (PIR2_R.Bits.BIT4)      

#endif

#endif	/* MICRO_CONTROLLER_H */

