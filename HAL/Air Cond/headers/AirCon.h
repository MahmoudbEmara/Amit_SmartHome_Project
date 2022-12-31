/*
 * AirCon.h
 *
 * Created: 12/31/2022 1:41:45 PM
 *  Author: Mahmoud
 */ 









#ifndef AIRCON_H_
#define AIRCON_H_

#include "STD_Types.h"
#include "DIO.h"
#include "Clock.h"

#define AirCon_Motor_Signal DIO_ChannelA2

void AirCon_TurnOn(void);
void AirCon_TurnOff(void);



#endif /* AIRCON_H_ */