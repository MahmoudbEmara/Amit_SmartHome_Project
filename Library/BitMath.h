/*
 * BitMath.h
 *
 * Created: 9/24/2022 7:58:27 PM
 *  Author: Mahmoud
 */ 


#ifndef BITMATH_H_
#define BITMATH_H_

#define Setbit(Reg,BitNo) (Reg |= (1<<BitNo))
#define Clearbit(Reg,BitNo) (Reg &= ~(1<<BitNo))
#define Togglebit(Reg,BitNo) (Reg ^= (1<<BitNo))
#define Getbit(Reg,BitNo) ((Reg>>BitNo)&1)

#endif /* BITMATH_H_ */