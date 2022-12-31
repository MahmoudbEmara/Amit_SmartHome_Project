/*
 * LED.h
 *
 * Created: 9/24/2022 9:11:47 PM
 *  Author: Mahmoud
 */ 




#ifndef LED_H_
#define LED_H_

#include "LED_HW.h"
#include "LCD.h"
#include "BitMath.h"

void LED_ON(LED ChannelID);
void LED_OFF(LED ChannelID);
void LED_Toggle(LED ChannelID);

void LED_Control(Uint8 data); // used to control which led switchs


#endif /* LED_H_ */