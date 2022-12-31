/*
* EINT.c
*
* Created: 10/9/2022 2:26:39 PM
*  Author: Mahmoud
*/


#include "EINT.h"


void Ext_Int_Enable(Ext_Int_Types INT_Id){
	
	switch (INT_Id)
	{
		case Ext_INT0:
		Setbit(GICR_Reg,GICR_Reg_INT0);
		break;
		case Ext_INT1:
		Setbit(GICR_Reg,GICR_Reg_INT1);
		break;
		case Ext_INT2:
		Setbit(GICR_Reg,GICR_Reg_INT2);
		break;
	}
	
	
}
void Ext_Int_Disable(Ext_Int_Types INT_Id){
	switch (INT_Id)
	{
		case Ext_INT0:
		Clearbit(GICR_Reg,GICR_Reg_INT0);
		break;
		case Ext_INT1:
		Clearbit(GICR_Reg,GICR_Reg_INT1);
		break;
		case Ext_INT2:
		Clearbit(GICR_Reg,GICR_Reg_INT2);
		break;
	}
	
}


void Ext_Int_SC(Ext_Int_Types INT_Id, Ext_ISC_Types SC_Id){
	
	switch (INT_Id)
	{
		case Ext_INT0:
		
		MCUCR_Reg = (MCUCR_Reg & 0xFC) | (SC_Id<<0);
		
		break;
		case Ext_INT1:
		MCUCR_Reg = (MCUCR_Reg & 0xF3) | (SC_Id<<2);
		break;
		
		case Ext_INT2:
		if (SC_Id == Rising_Edge){
			Setbit(MCUCSR_Reg,MCUCSR_Reg_SC);
		}
		else if(SC_Id == Falling_Edge)
		{
			Clearbit(MCUCSR_Reg,MCUCSR_Reg_SC);
		}else
		{
			// do nuthin
		}
		break;
	}

}