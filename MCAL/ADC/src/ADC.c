/*
 * ADC.c
 *
 * Created: 10/10/2022 10:20:17 AM
 *  Author: Mahmoud
 */ 


#include "ADC.h"



void ADC_Init(){
	//ACSR_Reg = (ACSR_Reg & 0xFC)|(mode<<0);
	Setbit(ADMUX_Reg,ADMUX_REF0_Bit); // internal volt ref set 2.56v
	Setbit(ADMUX_Reg,ADMUX_REF1_Bit); 
	Clearbit(ADMUX_Reg,ADC_Output_Adj_Bit);
	
	Setbit(ADCSRA_Reg,ADCSRA_Enable_Bit); // enable
	
	Setbit(ADCSRA_Reg,ADCSRA_ADPS0_Bit); // F_CPU /128
	Setbit(ADCSRA_Reg,ADCSRA_ADPS1_Bit);
	Setbit(ADCSRA_Reg,ADCSRA_ADPS2_Bit);	
}


int16 ADC_Read(ADC_ChannelTypes ChannelId){
	int16 read = 0;
	
	ADMUX_Reg = (ADMUX_Reg & 0xE0)|(ChannelId & 0b00011111);
	Setbit(ADCSRA_Reg,ADCSRA_ADSC_Bit);
	while(!ADCSRA_ADIF_Bit);
	Setbit(ADCSRA_Reg,ADCSRA_ADIF_Bit);
	read = ADCL_Reg;
	read = read | (ADCH_Reg << 8);
	return read; 
}


