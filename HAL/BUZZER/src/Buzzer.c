/*
 * Buzzer.c
 *
 * Created: 12/31/2022 3:40:22 PM
 *  Author: Mahmoud
 */ 


#include "Buzzer.h"


void Buzzer_TurnOn(void){
	DIO_WriteChannel(Buzzer_Signal,STD_High);
}
void Buzzer_TurnOff(void){
	DIO_WriteChannel(Buzzer_Signal,STD_Low);
}