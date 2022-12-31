/*
 * LED.c
 *
 * Created: 9/24/2022 9:11:37 PM
 *  Author: Mahmoud
 */ 

#include "LED.h"


void LED_ON(LED ChannelID){
	DIO_WriteChannel(ChannelID,STD_High);
}

void LED_OFF(LED ChannelID){
	DIO_WriteChannel(ChannelID, STD_Low);
}

void LED_Toggle(LED ChannelID){
	DIO_ToggleChannel(ChannelID);
}

void LED_Control(Uint8 data){
	
	// Based on received character from bluetooth --> switch LED 
	
	switch (data)
	{
		case 'C':
			LED_Toggle(LED_1);
			LCD_SetPos(2,1);
			LCD_String("LED 1 TOGGELED");
			break;
		case 'V':
			LED_Toggle(LED_2);
			LCD_SetPos(2,1);
			LCD_String("LED 2 TOGGELED");
			break;
		case 'B':
			LED_Toggle(LED_3);
			LCD_SetPos(2,1);
			LCD_String("LED 3 TOGGELED");
			break;
		case 'N':
			LED_Toggle(LED_4);
			LCD_SetPos(2,1);
			LCD_String("LED 4 TOGGELED");
			break;
		case 'M':
			LED_Toggle(LED_5);
			LCD_SetPos(2,1);
			LCD_String("LED 5 TOGGELED");
			break;
		default:
			return;
	}
	return;
}