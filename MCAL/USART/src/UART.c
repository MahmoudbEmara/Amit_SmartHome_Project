/*
* UART.c
*
* Created: 10/14/2022 9:10:20 PM
*  Author: user
*/
#include "UART.h"
#include <util/delay.h>
#include "Clock.h"

void UART_Init(){
	UART_UCSRB_Reg = (UART_UCSRB_RX_ENABLE|UART_UCSRB_TX_ENABLE|UART_UCSRB_RXI_ENABLE|
	UART_UCSRB_TXI_ENABLE);//enable TX & RX
	UART_UCSRC_Reg = (UART_UCSRC_SELECT_REG|UART_UCSRC_8BIT_DATA);//8 BIT DATA & SELECT UCSRC REG.
	UART_UBRRL_Reg = MyUBRR;
	UART_UBRRH_Reg = MyUBRR>>8;
}
void UART_Transmit(int8 data){
	//while(Getbit(UART_UCSRA_Reg,UART_UCSRA_UDRE_FLAG) == STD_Low);
	UART_UDR_Reg = data;
}
int8 UART_Receive(){
	//while(Getbit(UART_UCSRA_Reg,UART_UCSRA_RXC_FLAG) == STD_Low);
	return UART_UDR_Reg;
}
void UART_TransmitString(int8 * string){
	Uint8 i=0;
	while (string[i] != '\0')
	{
		UART_Transmit(string[i]);
		//_delay_us(100);
		i++;
	}
}