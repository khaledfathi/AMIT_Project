/*
 * LED.c
 *
 *  Created on: Mar 28, 2021
 *      Author: khaled
 */

#include "LED.h"

void LED_Init(void){
	DIO_SetPin_Direction(LED_PORT, LED1_PIN, LED_OUTPUT);
	DIO_SetPin_Direction(LED_PORT, LED2_PIN, LED_OUTPUT);
	DIO_SetPin_Direction(LED_PORT, LED3_PIN, LED_OUTPUT);
}

void LED_ON (Uint8t LED_numbers){
	switch (LED_numbers){
	case 1:
		DIO_SetPin_Value(LED_PORT, LED1_PIN, LED_HIGH);
	break;
	case 2:
		DIO_SetPin_Value(LED_PORT, LED2_PIN, LED_HIGH);
	break;
	case 3:
		DIO_SetPin_Value(LED_PORT, LED3_PIN, LED_HIGH);
	break;
	}
}

void LED_OFF (Uint8t LED_numbers){
	switch (LED_numbers){
	case 1:
		DIO_SetPin_Value(LED_PORT, LED1_PIN, LED_LOW);
	break;
	case 2:
		DIO_SetPin_Value(LED_PORT, LED2_PIN, LED_LOW);
	break;
	case 3:
		DIO_SetPin_Value(LED_PORT, LED3_PIN, LED_LOW);
	break;
	}
}
