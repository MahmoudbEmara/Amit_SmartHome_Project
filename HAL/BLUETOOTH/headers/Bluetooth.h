/*
 * Bluetooth.h
 *
 * Created: 10/14/2022 9:57:28 PM
 *  Author: user
 */ 


#ifndef BLUETOOTH_H_
#define BLUETOOTH_H_

#include "UART.h"


void Bluetooth_Init();
void Bluetooth_Transmit(int8 data);
int8 Bluetooth_Receive();
boolean BluetoothCheckIfAlpha(int8 data);
void Bluetooth_TransmitString(int8 * string);


#endif /* BLUETOOTH_H_ */