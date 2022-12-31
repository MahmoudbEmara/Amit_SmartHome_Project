/*
 * Keypad.h
 *
 * Created: 10/1/2022 7:37:55 PM
 *  Author: user
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "DIO.h"
#include "Clock.h"


#define r0 DIO_ChannelB0
#define r1 DIO_ChannelA1
#define r2 DIO_ChannelA2
#define r3 DIO_ChannelC6

#define c0 DIO_ChannelB4
#define c1 DIO_ChannelB5
#define c2 DIO_ChannelB6
#define c3 DIO_ChannelB7

#define tempButton1 DIO_ChannelB0
#define tempButton2 DIO_ChannelB4
#define tempButton3 DIO_ChannelB5
#define tempButton4 DIO_ChannelB6
#define tempButton5 DIO_ChannelB7


Uint8 GetKey(void);
boolean isButtonPressed(DIO_ChannelTypes x); // function used for software debouncing
Uint8 TempKeypad(Uint8 button);
	

#endif /* KEYPAD_H_ */