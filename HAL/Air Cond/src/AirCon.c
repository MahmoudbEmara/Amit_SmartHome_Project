/*
 * AirCon.c
 *
 * Created: 12/31/2022 1:42:00 PM
 *  Author: Mahmoud
 */ 


#include "AirCon.h"


void AirCon_TurnOn(void){

	DIO_WriteChannel(AirCon_Motor_Signal,STD_High); // switch relay on

	
}
void AirCon_TurnOff(void){
	
	DIO_WriteChannel(AirCon_Motor_Signal,STD_Low); // switch relay off
	
	
}