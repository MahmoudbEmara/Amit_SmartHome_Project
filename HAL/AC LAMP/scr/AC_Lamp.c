/*
 * AC_Lamp.c
 *
 * Created: 12/31/2022 3:40:05 PM
 *  Author: Mahmoud
 */ 


#include "AC_Lamp.h"


void AC_Lamp_Init(void){
	
	
	// initialize lamp bits for trigger and detector to 0
	DIO_WriteChannel(Lamp_AC_Zero_detect,STD_Low);
	DIO_WriteChannel(Lamp_trigger,STD_Low);
	
	// Enable global interrupts and external interrupt to use in zero detect circuit
	Globle_Int_Enable();			// Enable global interrupt
	Ext_Int_Enable(Ext_INT0);		// Enable external interrupt on PIN 2 in PORT D
	Ext_Int_Disable(Ext_INT0);
	Ext_Int_SC(Ext_INT0,Low_Level); // interrupt on low levels
	
	
}
void AC_Lamp_On(void){
	DIO_WriteChannel(Lamp_trigger,STD_High);

}
void AC_Lamp_Off(void){
	DIO_WriteChannel(Lamp_trigger,STD_Low);

}

int16 AC_Lamp_Set_Dimming(Uint8 data){
	int16 dimming = 75*data; // set delay value to control dimming of lamp	
	return dimming;
}

void delayDimming(int8 dimming){
	
	while(dimming > 0){
		
		_delay_ms(1);
		dimming--;
		
	}
	
	
	
}

