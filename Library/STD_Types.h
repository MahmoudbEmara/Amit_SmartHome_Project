/*
 * STD_Types.h
 *
 * Created: 9/24/2022 8:03:56 PM
 *  Author: Mahmoud
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char Uint8;
typedef char int8;
typedef unsigned short Uint16;
typedef short int16;
typedef unsigned int Uint32;
typedef int int32;



// integers are not consistant could be 2 or 4 so use short long char


typedef enum{
	STD_Low = 0,
	STD_High
	}STD_LevelTypes;

typedef enum{
	false = 0,
	true
}boolean;

#endif /* STD_TYPES_H_ */