/* 
 * File:   LCD.h
 * Author: A7med.G.Ashour
 *
 * Created on 23 ?????, 2019, 10:28 ?
 */

#ifndef LCD_H
#define	LCD_H

/* *** DIRECTIVES *** */

#include "MICRO_CONTROLLER.h"

/* *** PUBLIC DATATYPES *** */

typedef enum {
    LCD_4_MODE,
    LCD_8_MODE
}tLCD_Mode;

typedef enum{
    L1 = 0,
    L2
}tLine;

typedef enum {
    C1 = 0,C2,C3,C4,
    C5,C6,C7,C8,
    C9,C10,C11,C12,
    C13,C14,C15,C16
}tColumn;


/* **** PUBLIC FUNCTIONS PROTOTYPES **** */

void LCD_init(tLCD_Mode);
void LCD_char(tByte,tLine,tColumn);
void LCD_str(tByte *,tLine,tColumn);
void LCD_num(tDword , tLine, tColumn);
void LCD_clear(void);
void LCD_ON(void);
void LCD_OFF(void);
void LCD_custom(tByte * arr);

#endif	/* LCD_H */

