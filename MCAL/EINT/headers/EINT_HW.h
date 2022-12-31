/*
 * EINT_HW.h
 *
 * Created: 10/9/2022 2:26:14 PM
 *  Author: Mahmoud
 */ 


#ifndef EINT_HW_H_
#define EINT_HW_H_

# include "STD_Types.h"


# define GICR_Reg_INT0 6
# define GICR_Reg_INT1 7
# define GICR_Reg_INT2 5
# define MCUCSR_Reg_SC 6

# define GICR_Reg (*(volatile Uint8*) 0x5B)
# define GIFR_Reg (*(volatile Uint8*) 0x5A)
# define MCUCR_Reg (*(volatile Uint8*) 0x55)
# define MCUCSR_Reg (*(volatile Uint8*) 0x54)


#endif /* EINT_HW_H_ */