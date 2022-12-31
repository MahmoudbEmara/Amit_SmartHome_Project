/*
 * GINT.c
 *
 * Created: 10/9/2022 3:58:23 PM
 *  Author: Mahmoud
 */ 


# include "GINT.h"

void Globle_Int_Enable(){
	
	Setbit(SREG_Reg,SREG_Enable_bit);
	
}