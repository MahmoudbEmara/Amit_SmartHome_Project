/*
 * LM35.h
 *
 * Created: 10/8/2022 10:25:12 PM
 *  Author: user
 */ 


#ifndef LM35_H_
#define LM35_H_

#include "ADC.h"

#define LM35_ADC_Channel ADC_Channel0

void LM35_Init();
int16 LM35_Read(ADC_ChannelTypes ChannelId);

#endif /* LM35_H_ */