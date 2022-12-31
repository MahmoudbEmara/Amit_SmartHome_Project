/*
 * Door.h
 *
 * Created: 12/31/2022 1:41:21 PM
 *  Author: Mahmoud
 */ 




#ifndef DOOR_H_
#define DOOR_H_

#include "STD_Types.h"
#include "DIO.h"
#include "Clock.h"
#include "Timer1.h"

#define DOOR_Signal DIO_ChannelD5

void DOOR_Init(void);
void DOOR_Open(void);
void DOOR_Close(void);


#endif /* DOOR_H_ */