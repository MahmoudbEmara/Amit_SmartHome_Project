/**********************************************
 * EEPROM.h
 * Created: 10/22/2022 8:03:23 PM
 *  Author: Eng_Fawzi
 **********************************************/ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include "STD_Types.h"

void EEPROM_Write(Uint16 address,Uint8 data);
Uint8 EEPROM_Read(Uint16 address);


#endif /* EEPROM_H_ */