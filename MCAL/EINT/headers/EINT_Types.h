/*
* EINT_Types.h
*
* Created: 10/9/2022 2:25:56 PM
*  Author: Mahmoud
*/


#ifndef EINT_TYPES_H_
#define EINT_TYPES_H_


typedef enum{
	
	Ext_INT0=0,
	Ext_INT1,
	Ext_INT2
}Ext_Int_Types;


typedef enum{
	Low_Level=0,
	Both_Edges,
	Falling_Edge,
	Rising_Edge
}Ext_ISC_Types;



#endif /* EINT_TYPES_H_ */