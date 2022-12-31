/*
 * App_Cfg.h
 *
 * Created: 12/25/2022 3:44:57 PM
 *  Author: Mahmoud
 */ 


#ifndef APP_CFG_H_
#define APP_CFG_H_

#include "STD_Types.h"

	boolean checkIfAdmin(int8 data);
	boolean checkIfUser(int8 data);
	boolean checkIfConnected(int8 data);
	boolean allowKeypad(int8 data);

	boolean checkIfAdmin(int8 data){
	
	if (data == 'A'){
		return true;
	}else{
		return false;
	}

}
	boolean checkIfUser(int8 data){
	
	if (data == 'U'){
		return true;
	}else{
		return false;
	}
}
	boolean checkIfConnected(int8 data){

	
	if (data == '/'){
		return true;
	}else{
		return false;
	}

}

boolean allowKeypad(int8 data){

		
		if (data == 'K'){
			return true;
			}else{
			return false;
		}

	}


#endif /* APP_CFG_H_ */