/*
 * ADC_HW.h
 *
 * Created: 10/10/2022 10:19:51 AM
 *  Author: Mahmoud
 */ 


#ifndef ADC_HW_H_
#define ADC_HW_H_

#define ADC_Output_Adj_Bit 5
#define ADMUX_REF1_Bit 7
#define ADMUX_REF0_Bit 6


#define ADCSRA_ADPS0_Bit 0
#define ADCSRA_ADPS1_Bit 1
#define ADCSRA_ADPS2_Bit 2
#define ADCSRA_ADIF_Bit 4
#define ADCSRA_ADSC_Bit 6
#define ADCSRA_Enable_Bit 7

// # define ACSR_Reg (*(volatile Uint8*) 0x28)
# define ADMUX_Reg (*(volatile Uint8*) 0x27)
# define ADCSRA_Reg (*(volatile Uint8*) 0x26)
# define ADCH_Reg (*(volatile Uint8*) 0x25)
# define ADCL_Reg (*(volatile Uint8*) 0x24)

#endif /* ADC_HW_H_ */