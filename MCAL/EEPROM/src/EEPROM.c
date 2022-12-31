#include <EEPROM.h>
#include "EEPROM_Hw.h"

void EEPROM_Write(Uint16 address,Uint8 data)
{
	/* Wait for completion of previous write */
	while(EEPROM_CR_REG & (1<<EEWE))
	{
		;	/*	Do Nothing	*/
	}
	
	/* Set up address and data registers */
	EEPROM_ARL_REG=address;
	EEPROM_ARH_REG = address>>8;

/*	
	address -> 0b0000 0010 1101 1111
	address>>8 -> 0b0000 0000 0000 0010
*/	
	EEPROM_DR_REG = data;
	
	/* Write logical one to EEMWE */
	EEPROM_CR_REG |= (1<<EEMWE);
	
	/* Start EEPROM write by setting EEWE */
	EEPROM_CR_REG |= (1<<EEWE);
}

Uint8 EEPROM_Read(Uint16 address)
{
	/* Wait for completion of previous write */
	while(EEPROM_CR_REG & (1<<EEWE))
	{
		;	/*	Do Nothing	*/	
	}
	/* Set up address register */
	EEPROM_ARL_REG	=address;
	EEPROM_ARH_REG = address>>8;
	
	/* Start EEPROM read by writing EERE */
	EEPROM_CR_REG |= (1<<EERE);
	
	/* Return data from data register */
	return EEPROM_DR_REG;
}