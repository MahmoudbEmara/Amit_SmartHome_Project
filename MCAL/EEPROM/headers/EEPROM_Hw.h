/************************************************
 * EEPROM_Hw.h
 * Created: 10/22/2022 8:03:37 PM
 *  Author: Eng_Fawzi
 ************************************************/ 


#ifndef EEPROM_HW_H_
#define EEPROM_HW_H_

#define EEPROM_ARH_REG				(*(volatile Uint8*)0x3F)
#define EEPROM_ARL_REG				(*(volatile Uint8*)0x3E)
#define EEPROM_DR_REG				(*(volatile Uint8*)0x3D)
#define EEPROM_CR_REG				(*(volatile Uint8*)0x3C)

#define EERE				(0u)
#define EEWE             	(1u)
#define EEMWE				(2u)


#endif /* EEPROM_HW_H_ */