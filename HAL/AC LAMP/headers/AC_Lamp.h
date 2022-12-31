/*
 * AC_Lamp.h
 *
 * Created: 12/31/2022 3:39:53 PM
 *  Author: Mahmoud
 */ 








#ifndef AC_LAMP_H_
#define AC_LAMP_H_

#include "STD_Types.h"
#include "DIO.h"
#include "GINT.h"
#include "EINT.h"
#include "Clock.h"

#define Lamp_trigger DIO_ChannelC5
#define Lamp_AC_Zero_detect DIO_ChannelD2

void AC_Lamp_Init(void);
void AC_Lamp_On(void);
void AC_Lamp_Off(void);
int16 AC_Lamp_Set_Dimming(Uint8 data);
void delayDimming(int8 dimming);


#endif /* AC_LAMP_H_ */