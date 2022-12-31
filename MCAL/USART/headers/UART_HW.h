/*
 * UART_HW.h
 *
 * Created: 10/14/2022 8:59:01 PM
 *  Author: user
 */ 


#ifndef UART_HW_H_
#define UART_HW_H_

#include "STD_Types.h"

#define UART_UDR_Reg (*(volatile Uint8 *)0x2C)
#define UART_UCSRA_Reg (*(volatile Uint8 *)0x2B)
#define UART_UCSRB_Reg (*(volatile Uint8 *)0x2A)
#define UART_UCSRC_Reg (*(volatile Uint8 *)0x40)
#define UART_UBRRL_Reg (*(volatile Uint8 *)0x29)
#define UART_UBRRH_Reg (*(volatile Uint8 *)0x40)

#endif /* UART_HW_H_ */