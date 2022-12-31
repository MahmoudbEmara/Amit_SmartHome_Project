
#include "DIO.h"

void DIO_WriteChannel(DIO_ChannelTypes ChannelId,STD_LevelTypes Level){
	DIO_PortTypes Portx = ChannelId/8;
	DIO_ChannelTypes BitNo = ChannelId%8;
	switch (Portx)
	{
		case DIO_PortA:
		if (Level == STD_High)
		{
			Setbit(PORTA_Reg,BitNo);
		}
		else{
			Clearbit(PORTA_Reg,BitNo);
		}
		break;
		case DIO_PortB:
		if (Level == STD_High)
		{
			Setbit(PORTB_Reg,BitNo);
		}
		else{
			Clearbit(PORTB_Reg,BitNo);
		}
		break;
		case DIO_PortC:
		if (Level == STD_High)
		{
			Setbit(PORTC_Reg,BitNo);
		}
		else{
			Clearbit(PORTC_Reg,BitNo);
		}
		break;
		case DIO_PortD:
		if (Level == STD_High)
		{
			Setbit(PORTD_Reg,BitNo);
		}
		else{
			Clearbit(PORTD_Reg,BitNo);
		}
		break;
	}
}


void DIO_ToggleChannel(DIO_ChannelTypes ChannelId){
		DIO_PortTypes Portx = ChannelId/8;
		DIO_ChannelTypes BitNo = ChannelId%8;
		switch (Portx)
		{
			case DIO_PortA:
				Togglebit(PORTA_Reg,BitNo);
			break;
			case DIO_PortB:
				Togglebit(PORTB_Reg,BitNo);
			break;
			case DIO_PortC:
				Togglebit(PORTC_Reg,BitNo);
			break;
			case DIO_PortD:
				Togglebit(PORTD_Reg,BitNo);
			break;
		}
}

STD_LevelTypes DIO_ReadChannel(DIO_ChannelTypes ChannelId){
	DIO_PortTypes Portx = ChannelId/8;
	DIO_ChannelTypes BitNo = ChannelId%8;
	STD_LevelTypes BitValue = STD_Low;
	switch(Portx){
		case DIO_PortA:
		BitValue = Getbit(PINA_Reg,BitNo);
		break;
		case DIO_PortB:
		BitValue = Getbit(PINB_Reg,BitNo);
		break;
		case DIO_PortC:
		BitValue = Getbit(PINC_Reg,BitNo);
		break;
		case DIO_PortD:
		BitValue = Getbit(PIND_Reg,BitNo);
		break;
	}
	return BitValue;
}

Uint8 DIO_ReadPort(DIO_PortTypes PortId){
	Uint8 PortValue = 0;
	switch(PortId){
		case DIO_PortA:
		PortValue = PORTA_Reg;
		break;
		case DIO_PortB:
		PortValue = PORTB_Reg;
		break;
		case DIO_PortC:
		PortValue = PORTC_Reg;
		break;
		case DIO_PortD:
		PortValue = PORTD_Reg;
		break;
	}
	return PortValue;
}

void DIO_WritePort(DIO_PortTypes PortId,Uint8 PortValue){
	switch(PortId){
		case DIO_PortA:
		PORTA_Reg = PortValue;
		break;
		case DIO_PortB:
		PORTB_Reg = PortValue;
		break;
		case DIO_PortC:
		PORTC_Reg = PortValue;
		break;
		case DIO_PortD:
		PORTD_Reg = PortValue;
		break;
	}
}

void DIO_ConfigureChannel(DIO_ChannelTypes ChannelId,DIO_DirTypes Direction){
	DIO_PortTypes Portx = ChannelId/8;
	DIO_ChannelTypes BitNo = ChannelId%8;
	switch (Portx)
	{
		case DIO_PortA:
		if (Direction == Output)
		{
			Setbit(DDRA_Reg,BitNo);
		}
		else{
			Clearbit(DDRA_Reg,BitNo);
		}
		break;
		case DIO_PortB:
		if (Direction == Output)
		{
			Setbit(DDRB_Reg,BitNo);
		}
		else{
			Clearbit(DDRB_Reg,BitNo);
		}
		break;
		case DIO_PortC:
		if (Direction == Output)
		{
			Setbit(DDRC_Reg,BitNo);
		}
		else{
			Clearbit(DDRC_Reg,BitNo);
		}
		break;
		case DIO_PortD:
		if (Direction == Output)
		{
			Setbit(DDRD_Reg,BitNo);
		}
		else{
			Clearbit(DDRD_Reg,BitNo);
		}
		break;
	}
}