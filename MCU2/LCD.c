/*
 * LCD.c
 *
 *  Created on: Mar 28, 2021
 *      Author: khaled
 *      This Driver Support Only 4bit Mode
 */


#include "LCD.h"
#include "stdlib.h"

void LCD_Init(void)
{
	//LCD control pins - output
	DIO_SetPin_Direction(LCD_PORT, LCD_RS, LCD_OUTPUT);
	DIO_SetPin_Direction(LCD_PORT, LCD_EN, LCD_OUTPUT);
	//LCD_RW is Grounded | Only Write on lcd

	//LCD data pins - output
	DIO_SetPin_Direction(LCD_PORT, LCD_DATA4, LCD_OUTPUT);
	DIO_SetPin_Direction(LCD_PORT, LCD_DATA5, LCD_OUTPUT);
	DIO_SetPin_Direction(LCD_PORT, LCD_DATA6, LCD_OUTPUT);
	DIO_SetPin_Direction(LCD_PORT, LCD_DATA7, LCD_OUTPUT);


	//command steps to initialize  LCD module to run in 4 bit mode [depend on datasheet]
	LCD_Write_Command(0x33);
	LCD_Write_Command(0x32);
	LCD_Write_Command(0x28);
	LCD_Write_Command(0x02);
	LCD_Write_Command(0x0C);
	LCD_Write_Command(0x01);
	LCD_Write_Command(0x06);
}

void LCD_Write_Command(Uint8t command)
{
	DIO_SetPin_Value(LCD_PORT, LCD_RS, LCD_LOW);//select command mode [RS pin]
	DIO_SetPin_Value(LCD_PORT, LCD_EN, LCD_LOW);// LCD_EN pin Low

	//HIGH Nipple
	PORTA = (command & 0xF0) | (PORTA & 0x0F); // send high nipple
	DIO_SetPin_Value(LCD_PORT, LCD_EN, LCD_HIGH); //LCD_EN High pulse for 1ms
	_delay_ms(1);
	DIO_SetPin_Value(LCD_PORT, LCD_EN, LCD_LOW);// LCD_EN pin Low

	//LOW Nipple
	PORTA = (command << 4) | (PORTA & 0x0F); // send low nipple
	/*Send High pulse for 1 millisecond*/
	DIO_SetPin_Value(LCD_PORT, LCD_EN, LCD_HIGH);//LCD_EN High pulse for 1ms
	_delay_ms(1);
	DIO_SetPin_Value(LCD_PORT, LCD_EN, LCD_LOW);// LCD_EN pin Low
	_delay_ms(5);//Wait controller to finish command
}

void LCD_Write_Character(Uint8t character)
{
	DIO_SetPin_Value(LCD_PORT, LCD_RS, LCD_HIGH);//select Data mode [RS pin]
	DIO_SetPin_Value(LCD_PORT, LCD_EN, LCD_LOW);// LCD_EN pin Low

	//HIGH Nipple
	PORTA = (character & 0xF0) | (PORTA & 0x0F);//send High nipple
	DIO_SetPin_Value(LCD_PORT, LCD_EN, LCD_HIGH);//LCD_EN High pulse for 1ms
	_delay_ms(1);
	DIO_SetPin_Value(LCD_PORT, LCD_EN, LCD_LOW);//LCD_EN Low

	//LOW Nipple
	PORTA = (character << 4) | (PORTA & 0x0F);//send Low nipple
	DIO_SetPin_Value(LCD_PORT, LCD_EN, LCD_HIGH);//LCD_EN High pulse for 1ms
	_delay_ms(1);
	DIO_SetPin_Value(LCD_PORT, LCD_EN, LCD_LOW); // LCD_en Low
	_delay_ms(5);//Wait controller to finish command
}

void LCD_Clear(void)
{
	LCD_Write_Command(0x01);
}

void LCD_Write_String(Uint8t* str)
{
	while(*str != '\0')
	{
		LCD_Write_Character(*str);
		_delay_ms(10);
		str++;
	}
}

void LCD_Write_Number(Uint32t number)
{
	Uint8t num[10];
	ltoa(number, (char*)num, 10); //i used char* instead of Uint8t because parameter 2 in ltoa function use char* pointer
	LCD_Write_String(num);
}

void LCD_Cursor_Home(void)
{
	LCD_Write_Command(0x02);
}

void LCD_Cursor_Position (Uint8t col , Uint8t row)
{
	switch(row)
	{
		case 1 :
		LCD_Write_Command(0x80 + col-1);
		break;
		case 2 :
		LCD_Write_Command(0xC0 + col-1);
		break;
	}
}
