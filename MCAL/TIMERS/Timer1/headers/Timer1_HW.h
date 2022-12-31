/*
 * Timer1_HW.h
 *
 * Created: 12/29/2022 5:29:30 PM
 *  Author: Mahmoud
 */ 


#ifndef TIMER1_HW_H_
#define TIMER1_HW_H_



#define  TCCR1A_WGM11 (1<<1)
#define  TCCR1A_COM1B1 (1<<5)
#define  TCCR1A_COM1A1 (1<<7)

#define  TCCR1B_CS10 (1<<0)
#define  TCCR1B_CS11 (1<<1)
#define  TCCR1B_WGM12 (1<<3)
#define  TCCR1B_WGM13 (1<<4)



# define TCCR1A_Reg (*(volatile Uint8*) 0x4F)
# define TCCR1B_Reg (*(volatile Uint8*) 0x4E)
# define TCNT1H_Reg (*(volatile Uint8*) 0x4D)
# define TCNT1L_Reg (*(volatile Uint8*) 0x4C)
# define OCR1AH_Reg (*(volatile Uint8*) 0x4B)
# define OCR1AL_Reg (*(volatile Uint8*) 0x4A)
# define ICR1H_Reg (*(volatile Uint8*) 0x47)
# define ICR1L_Reg (*(volatile Uint8*) 0x46)






#endif /* TIMER1_HW_H_ */