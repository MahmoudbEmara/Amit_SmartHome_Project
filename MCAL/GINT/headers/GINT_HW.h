/*
 * GINT_HW.h
 *
 * Created: 10/9/2022 2:46:16 PM
 *  Author: Mahmoud
 */ 


#ifndef GINT_HW_H_
#define GINT_HW_H_

# include "STD_Types.h"

#define SREG_Enable_bit 7

# define SREG_Reg (*(volatile Uint8*) 0x5F)


#endif /* GINT_HW_H_ */