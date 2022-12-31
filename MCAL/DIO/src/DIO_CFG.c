/*
* DIO_CFG.c
*
* Created: 9/24/2022 8:44:38 PM
*  Author: user
*/

#include "DIO_CFG.h"

DIO_PinCfg PinCfg[] = {
	//PORTA
	{Input,STD_Low},  // LM35
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	
	//PORTB
	{Input,STD_Low}, // push buttons or keypad
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Input,STD_Low}, // push buttons or keypad
	{Input,STD_Low}, // push buttons or keypad
	{Input,STD_Low}, // push buttons or keypad
	{Input,STD_Low}, // push buttons or keypad
	
	//PORTC
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},

	//PORTD
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
	{Output,STD_High},
};

void DIO_Init(void){
	DIO_ChannelTypes count = DIO_ChannelA0;
	DIO_PortTypes Portx;
	DIO_ChannelTypes BitNo;
	for (count = DIO_ChannelA0;count<PINCOUNT;count++)
	{
		Portx = count/8;
		BitNo = count%8;
		switch(Portx){
			case DIO_PortA:
			if (PinCfg[count].PinDir == Output)
			{
				Setbit(DDRA_Reg,BitNo);
			}
			else{
				Clearbit(DDRA_Reg,BitNo);
			}
			break;
			case DIO_PortB:
			if (PinCfg[count].PinDir == Output)
			{
				Setbit(DDRB_Reg,BitNo);
			}
			else{
				Clearbit(DDRB_Reg,BitNo);
			}
			break;
			case DIO_PortC:
			if (PinCfg[count].PinDir == Output)
			{
				Setbit(DDRC_Reg,BitNo);
			}
			else{
				Clearbit(DDRC_Reg,BitNo);
			}
			break;
			case DIO_PortD:
			if (PinCfg[count].PinDir == Output)
			{
				Setbit(DDRD_Reg,BitNo);
			}
			else{
				Clearbit(DDRD_Reg,BitNo);
			}
			break;
		}
	}
}