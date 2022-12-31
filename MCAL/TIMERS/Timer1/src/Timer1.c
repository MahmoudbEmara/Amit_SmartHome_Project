/*
* Timer1.c
*
* Created: 12/29/2022 4:17:37 PM
*  Author: Mahmoud
*/


#include "Timer1.h"


void TIMER1_Init(void){
	TCCR1A_Reg|= (TCCR1A_COM1A1)|(TCCR1A_COM1B1)|(TCCR1A_WGM11); // //NON Inverted PWM
	TCCR1B_Reg|= (TCCR1B_WGM13)|(TCCR1B_WGM12)|(TCCR1B_CS11)|(TCCR1B_CS10); //PRESCALER=64 MODE   14(FAST PWM) 1110
}

void TIMER1_Set_ICR(Uint16 ICR){
	
	ICR1H_Reg = (Uint8) ((ICR>>8) & 0x00FF);
	ICR1L_Reg = (Uint8) (ICR & 0x00FF);
	
		
}

void TIMER1_Set_OCR1A(Uint16 OCRA){
	
	OCR1AH_Reg = (Uint8) ((OCRA>>8) & 0x00FF);
	OCR1AL_Reg = (Uint8) (OCRA & 0x00FF);
	
	
}






