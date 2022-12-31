/*
 * EINT.h
 *
 * Created: 10/9/2022 2:26:54 PM
 *  Author: Mahmoud
 */ 




#ifndef EINT_H_
#define EINT_H_

#include "EINT_HW.h"
#include "EINT_Types.h"
#include "BitMath.h"


void Ext_Int_Enable(Ext_Int_Types INT_Id);
void Ext_Int_Disable(Ext_Int_Types INT_Id);
void Ext_Int_SC(Ext_Int_Types INT_Id, Ext_ISC_Types SC_Id);






#endif /* EINT_H_ */