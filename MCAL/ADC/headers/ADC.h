/*
 * ADC.h
 *
 * Created: 10/10/2022 10:19:39 AM
 *  Author: Mahmoud
 */ 


#ifndef ADC_H_
#define ADC_H_

#include "ADC_HW.h"
#include "ADC_Types.h"
#include "BitMath.h"
#include "STD_Types.h"
#include <util/delay.h>


void ADC_Init();
int16 ADC_Read(ADC_ChannelTypes ChannelId);


#endif /* ADC_H_ */