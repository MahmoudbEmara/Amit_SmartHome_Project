/*
 * LED_HW.h
 *
 * Created: 10/10/2022 10:07:26 AM
 *  Author: Mahmoud
 */ 


#ifndef LED_HW_H_
#define LED_HW_H_

#include "DIO.h"


typedef enum{
	LED_1=DIO_ChannelC0,
	LED_2=DIO_ChannelC1,
	LED_3=DIO_ChannelC2,
	LED_4=DIO_ChannelC3,
	LED_5=DIO_ChannelC4
	}LED;

#endif /* LED_HW_H_ */