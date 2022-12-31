/*
* Bluetooth.c
*
* Created: 10/14/2022 9:57:07 PM
*  Author: user
*/
#include "Bluetooth.h"

void Bluetooth_Init(){
	UART_Init();
}
void Bluetooth_Transmit(int8 data){
	UART_Transmit(data);
}
int8 Bluetooth_Receive(){
	return UART_Receive();
}
void Bluetooth_TransmitString(int8 * string){
	UART_TransmitString(string);
}

boolean BluetoothCheckIfAlpha(int8 data){
	// function used to check if data is a char from a to z (a-z 97-122)
	for( int8 i = 97 ; i <= 122; i++ ) {
		if (i == data){
			return true;
			}else{
			// continue
		}
		
	}
	return false;	
}