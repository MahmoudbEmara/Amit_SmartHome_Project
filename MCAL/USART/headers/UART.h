/*
 * UART.h
 *
 * Created: 10/14/2022 8:58:46 PM
 *  Author: user
 */ 


#ifndef UART_H_
#define UART_H_

#include "UART_HW.h"
#include "Clock.h"
#include "BitMath.h"

#define BaudRate (9600)

//#define DoubleSpeed

#ifndef DoubleSpeed
#define MyUBRR ((F_CPU/(16UL*BaudRate))-1)
#else
#define MyUBRR ((F_CPU/(8UL*BaudRate))-1)
#endif

#define UART_UCSRA_UDRE_FLAG (5)
#define UART_UCSRA_TXC_FLAG (6)
#define UART_UCSRA_RXC_FLAG (7)

#define UART_UCSRB_RX_ENABLE (1<<4)
#define UART_UCSRB_TX_ENABLE (1<<3)
#define UART_UCSRB_RXI_ENABLE (1<<7)
#define UART_UCSRB_TXI_ENABLE (1<<6)

#define UART_UCSRC_5BIT_DATA (0<<1)
#define UART_UCSRC_6BIT_DATA (1<<1)
#define UART_UCSRC_7BIT_DATA (2<<1)
#define UART_UCSRC_8BIT_DATA (3<<1)
#define UART_UCSRC_SELECT_REG (1<<7)

void UART_Init();
void UART_Transmit(int8 data);
int8 UART_Receive();
void UART_TransmitString(int8 * string);

#endif /* UART_H_ */