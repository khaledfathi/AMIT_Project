/*
 * LCD.h
 *
 *  Created on: Mar 28, 2021
 *      Author: khaled
 */

#ifndef LCD_H_
#define LCD_H_

#include "LCD_CONFIG.h"

void LCD_Init(void);
void LCD_Write_Command(Uint8t command);
void LCD_Write_Character(Uint8t character);
void LCD_Clear(void);
void LCD_Write_String(Uint8t* str);
void LCD_Write_Number(Uint32t number);
void LCD_Cursor_Home(void);
void LCD_Cursor_Position (Uint8t col , Uint8t row);


#endif /* LCD_H_ */
