/*
 * main.c
 *
 *  Created on: Mar 28, 2021
 *      Author: khaled
 */


#include "UART.h"
#include "SPI.h"
#include "LCD.h"
#include "LED.h"


int main (){
	//drivers initializing
	UART_Init();
	SPI_Init();
	LCD_Init();
	LED_Init();

	//variable needed
	Uint8t data =0 ;
	while(1){
		data = SPI_Receive();//waiting data from bluetooth (UART Side)
		switch (data){
		case 'A' :
			LED_ON(1);
			LCD_Clear();
			LCD_Write_String((Uint8t*)"    LED 1 ON");
		break;
		case 'a' :
			LED_OFF(1);
			LCD_Clear();
			LCD_Write_String((Uint8t*)"    LED 1 OFF");
		break;
		case 'B' :
			LED_ON(2);
			LCD_Clear();
			LCD_Write_String((Uint8t*)"    LED 2 ON");
		break;
		case 'b' :
			LED_OFF(2);
			LCD_Clear();
			LCD_Write_String((Uint8t*)"    LED 2 OFF");
		break;
		case 'C' :
			LED_ON(3);
			LCD_Clear();
			LCD_Write_String((Uint8t*)"    LED 3 ON");
		break;
		case 'c' :
			LED_OFF(3);
			LCD_Clear();
			LCD_Write_String((Uint8t*)"    LED 3 OFF");
		break;
		case '@' :
			LED_ON(1); LED_ON(2); LED_ON(3);
			LCD_Clear();
			LCD_Write_String((Uint8t*)"  ALL LEDS OFF");
		break;
		case '#' :
			LED_OFF(1); LED_OFF(2); LED_OFF(3);
			LCD_Clear();
			LCD_Write_String((Uint8t*)"  ALL LEDS OFF");
		break;
		}
		data = 0;
	}
}

