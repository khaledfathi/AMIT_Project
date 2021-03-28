/*
 * main.c
 *
 *  Created on: Mar 28, 2021
 *      Author: khaled
 */
#include "UART.h"
#include "SPI.h"
#include "LCD.h"

int main (){
	//drivers initializing
	UART_Init();
	SPI_Init();
	LCD_Init();

	//variable needed ;
	Uint8t data =0 ;

	while(1){
		data = UART_Receive();//waiting data from bluetooth (UART Side)
		switch (data){
			case 'A' :
				SPI_Transmit('A');
				LCD_Clear();
				LCD_Write_String((Uint8t*)"   Send ON to");
				LCD_Cursor_Position(1, 2);
				LCD_Write_String((Uint8t*)"     LED 1");
			break;
			case 'a' :
				SPI_Transmit('a');
				LCD_Clear();
				LCD_Write_String((Uint8t*)"   Send OFF to");
				LCD_Cursor_Position(1, 2);
				LCD_Write_String((Uint8t*)"     LED 1");
			break;
			case 'B' :
				SPI_Transmit('B');
				LCD_Clear();
				LCD_Write_String((Uint8t*)"   Send ON to");
				LCD_Cursor_Position(1, 2);
				LCD_Write_String((Uint8t*)"     LED 2");
			break;
			case 'b' :
				SPI_Transmit('b');
				LCD_Clear();
				LCD_Write_String((Uint8t*)"   Send OFF to");
				LCD_Cursor_Position(1, 2);
				LCD_Write_String((Uint8t*)"     LED 2");
			break;
			case 'C' :
				SPI_Transmit('C');
				LCD_Clear();
				LCD_Write_String((Uint8t*)"   Send ON to");
				LCD_Cursor_Position(1, 2);
				LCD_Write_String((Uint8t*)"     LED 3");
			break;
			case 'c' :
				SPI_Transmit('c');
				LCD_Clear();
				LCD_Write_String((Uint8t*)"   Send OFF to");
				LCD_Cursor_Position(1, 2);
				LCD_Write_String((Uint8t*)"     LED 3");
			break;
			case '@' :
				SPI_Transmit('@');
				LCD_Clear();
				LCD_Write_String((Uint8t*)"   Send ON to");
				LCD_Cursor_Position(1, 2);
				LCD_Write_String((Uint8t*)"    ALL LEDS");
			break;
			case '#' :
				SPI_Transmit('#');
				LCD_Clear();
				LCD_Write_String((Uint8t*)"   Send OFF to");
				LCD_Cursor_Position(1, 2);
				LCD_Write_String((Uint8t*)"    ALL LEDS");
			break;
		}
		data = 0;
	}
}
