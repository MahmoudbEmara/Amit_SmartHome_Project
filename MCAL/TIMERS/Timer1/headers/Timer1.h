/*
 * Timer1.h
 *
 * Created: 12/29/2022 4:22:35 PM
 *  Author: Mahmoud
 */ 


#ifndef TIMER1_H_
#define TIMER1_H_


#include "STD_Types.h"
#include "Timer1_HW.h"




void TIMER1_Init(void);
void TIMER1_Set_ICR(Uint16 ICR);
void TIMER1_Set_OCR1A(Uint16 OCRA);


/*
void Wait()
{
	Uint8 i;
	for(i=0;i<50;i++)
	{
		_delay_loop_2(0);
		_delay_loop_2(0);
		_delay_loop_2(0);
	}

}

*/
#endif /* TIMER1_H_ */