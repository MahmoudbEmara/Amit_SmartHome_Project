/*
 * includes.h
 *
 * Created: 12/19/2022 12:21:52 PM
 *  Author: Mahmoud
 */ 


#ifndef INCLUDES_H_
#define INCLUDES_H_

////////////////////////////////////////////////
// Created headers


#include "App_Cfg.h"

// General lib
#include "BitMath.h"
#include "STD_Types.h"
#include "Clock.h"

// HAL
#include "LED.h"
#include "LCD.h"
#include "Keypad.h"
#include "Bluetooth.h"
#include "LM35.h"
#include "AC_Lamp.h"
#include "Buzzer.h"
#include "Door.h"
#include "AirCon.h"

// MCAL
#include "DIO.h"
#include "EINT.h"
#include "GINT.h"
#include "ADC.h"
#include "Timer0.h"
#include "UART.h"
#include "EEPROM.h"
#include "Timer1.h"
////////////////////////////////////////////////


////////////////////////////////////////////////
// Avr libs
#include <util/delay.h>
#include <avr/interrupt.h>
////////////////////////////////////////////////



#endif /* INCLUDES_H_ */