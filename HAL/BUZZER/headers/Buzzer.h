/*
 * Buzzer.h
 *
 * Created: 12/31/2022 3:40:34 PM
 *  Author: Mahmoud
 */ 






#ifndef BUZZER_H_
#define BUZZER_H_

#include "STD_Types.h"
#include "DIO.h"
#include "Clock.h"

#define Buzzer_Signal DIO_ChannelA3

void Buzzer_TurnOn(void);
void Buzzer_TurnOff(void);


#endif /* BUZZER_H_ */