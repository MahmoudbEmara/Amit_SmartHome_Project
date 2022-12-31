/*
* Door.c
*
* Created: 12/31/2022 1:41:33 PM
*  Author: Mahmoud
*/



#include "Door.h"



void DOOR_Init(void){
	TIMER1_Init();
	TIMER1_Set_ICR(4999);
}


void DOOR_Open(void){
	TIMER1_Set_OCR1A(50); // Servo Angle 0
	_delay_ms(1500);
}
void DOOR_Close(void){
	TIMER1_Set_OCR1A(700); // Servo Angle 180
	_delay_ms(1500);
}