/*
* SmartHome.c
*
* Created: 12/11/2022 4:36:16 PM
* Author : Mahmoud
*/

#include "includes.h"

boolean connected = false; // check if connected to bluetooth device

boolean AdminMode = false; // check admin mode or user
boolean UserMode = false; // check admin mode or user

// User database initialize
#define maxUserInput  5
#define totalNumberofUsers 3
int8 usersHard[totalNumberofUsers][maxUserInput] = {{"user1"},{"user2"},{"user3"}};
int8 userTemp[maxUserInput] = "aaaaa";
int8 userPassTemp[maxUserInput] = "aaaaa";
int8 usersBlu[totalNumberofUsers][maxUserInput];
int8 passes[totalNumberofUsers][maxUserInput];


// Admin Controls initialize
boolean editUsers = false;

boolean editUser[totalNumberofUsers]= {false,false,false};
boolean deltUser[totalNumberofUsers]= {false,false,false};
boolean editPasses[totalNumberofUsers]= {false,false,false};

boolean lights = false;
boolean door = false;
boolean keypad = false;



// Auxiliary variables initialize
Uint8 counter = 0;
Uint8 counterTwo = 0;
int16 temp = 0;
Uint8 dimming = 0;
Uint8 ButtonPressed = 0;
int16 keypadInput = 0;
boolean Lamp = false;
boolean Alarm = false;
boolean keypadUser = false;
boolean getUsername = true;
boolean lcdReset = true;
boolean keypadallowed = false;
int8 TempReading = 0;


int main(void)
{
	
	// LOAD DATA FROM EEPROM (saved user names and passwords)
	for (int16 j = 0;j<maxUserInput;j++)
	{
		usersBlu[0][j] = EEPROM_Read(j);
		passes[0][j] = EEPROM_Read(j+(maxUserInput));

		usersBlu[1][j] = EEPROM_Read(j+(maxUserInput*2));
		passes[1][j] = EEPROM_Read(j+(maxUserInput*3));

		usersBlu[2][j] = EEPROM_Read(j+(maxUserInput*4));
		passes[2][j] = EEPROM_Read(j+(maxUserInput*5));
	}
	
	
	
	
	// MCAL AND HAL INITIALIZATIONS
	
	DIO_Init();
	AC_Lamp_Init();
	LM35_Init();
	DOOR_Init();
	Bluetooth_Init();
	LCD_Init();

	

	_delay_ms(10);
	
	
	
	LCD_String("*** Welcome. ***");
	DOOR_Close();
	AC_Lamp_Off();
	
	while (1)
	{
		
		if (Alarm == true){
			LCD_Clear();
			LCD_String("Restart");
			LCD_SetPos(2,2);
			LCD_String("Required");
			break;
			
		}else{
			
			// Air Conditioning Control
			TempReading = LM35_Read(LM35_ADC_Channel); // Read Sensor values constantly
			if (TempReading > 28){
				AirCon_TurnOn();
				}else if (TempReading < 21 ){
				AirCon_TurnOff();
			}
			else{
				// do nothing
			}
			
			
// *******Keypad Control******* temp due to hardware keypad failure, else would just use getKey() function in KEYPAD source to get key input and store it for comparison /////////////////////////////////////
			
			if ((isButtonPressed(tempButton1) ||  isButtonPressed(tempButton2) || isButtonPressed(tempButton3) || isButtonPressed(tempButton4) || isButtonPressed(tempButton5) ) && keypadInput < 5){
				
				if (lcdReset)
				{
					LCD_Clear();
					lcdReset = false;
				}
				
				
				if (keypadallowed == true){
					LCD_SetPos(0,0);
					LCD_String("KEYPAD MODE");
					LCD_SetPos(2,keypadInput);
					
					// only compare data to first user data only is this method is for demonstration only due to keypad fault
					if (isButtonPressed(tempButton1))
					{
						ButtonPressed = TempKeypad(tempButton1); // char = u
					}
					else if (isButtonPressed(tempButton2))
					{
						ButtonPressed = TempKeypad(tempButton2); // char = s
					}else if (isButtonPressed(tempButton3))
					{
						ButtonPressed = TempKeypad(tempButton3); // char = e
					}
					else if (isButtonPressed(tempButton4))
					{
						ButtonPressed = TempKeypad(tempButton4); // char = r
					}
					else if (isButtonPressed(tempButton5))
					{
						ButtonPressed = TempKeypad(tempButton5); // char = 1
					}
					else
					{
						// do nothing
					}
					
					LCD_Char(ButtonPressed);
					
					if (getUsername){
						userTemp[keypadInput] = ButtonPressed;
						}else{
						userPassTemp[keypadInput] = ButtonPressed;
					}
					keypadInput++;
					
					if (keypadInput == 4 && getUsername == true){
						getUsername = false;
						keypadInput = 0;
					}
					
					
					}else{
					LCD_Clear();
					LCD_String("Keypad Control");
					LCD_SetPos(2,0);
					LCD_String("Not Allowed.");
				}
			}
			
			for (int16 j =0; j < totalNumberofUsers; j++)
			{
				for (int16 i = 0; i < maxUserInput;i++)
				{
					if (usersHard[j][i] == userTemp[i] && passes[j][i] == userPassTemp[i]){
						keypadUser = true;
						}else{
						keypadUser = false;
						break;
					}
					
					if (keypadUser == true)
					{
						break;
					}
					
				}
			}

			
			
			if (keypadUser == true && keypadallowed == true){
				LCD_Clear();
				LCD_String("1- USER INFO");
				LCD_SetPos(2,0);
				LCD_String("2- LIGHT CONTROL");
				
				if (isButtonPressed(tempButton1))
				{
					LCD_Clear();
					while (1)
					{
						if (isButtonPressed(tempButton1) ||  isButtonPressed(tempButton2) || isButtonPressed(tempButton3) || isButtonPressed(tempButton4) || isButtonPressed(tempButton5)){
							break;
							}else{
							LCD_String("user ");
							LCD_String(usersHard[0]);
							
							LCD_SetPos(0,0);
							
							LCD_String("pass");
							LCD_String(passes[0]);
							
							
						}
						
					}
				}else if (isButtonPressed(tempButton2))
				{
					while (1)
					{
						if (isButtonPressed(tempButton1)){
							break;
						}else if (isButtonPressed(tempButton1) )
						{
							LED_Control(LED_1);
						}
						else if (isButtonPressed(tempButton1) )
						{
							LED_Control(LED_2);
						}
						else if (isButtonPressed(tempButton1) )
						{
							LED_Control(LED_3);
						}
						else if (isButtonPressed(tempButton1) )
						{
							LED_Control(LED_4);
						}
						else{
						}
						

					}
				}
				else{
				}
				
			}
// *******Keypad Control******* temp due to hardware keypad failure, else would just use getKey() function in KEYPAD source to get key input and store it for comparison /////////////////////////////////////////////
			
			

		}
	}
}

/////////////////////////////////////////////////////////////////////////////// REMOTE CONTROL INTERRUPTS (TX and RX) //////////////////////////////////////////////////////////////////////////////////



ISR(USART_TXC_vect){
	// Send User names and passwords stored in EEPROM
	
	if (counterTwo == maxUserInput){
		counterTwo = 0;
	}
	
	if (temp < (maxUserInput)){
		Bluetooth_Transmit(usersBlu[0][counterTwo]);  // user1
	}
	
	else if (temp < (maxUserInput*2)){
		Bluetooth_Transmit(passes[0][counterTwo]);    // password1
	}
	
	else if (temp < (maxUserInput*3)){
		Bluetooth_Transmit(usersBlu[1][counterTwo]);  //u2
	}
	
	else if (temp < (maxUserInput*4)){
		Bluetooth_Transmit(passes[1][counterTwo]);   //p2
	}
	
	else if (temp < (maxUserInput*5)){
		Bluetooth_Transmit(usersBlu[2][counterTwo]); //u3
	}
	
	else if (temp < (maxUserInput*6)){
		Bluetooth_Transmit(passes[2][counterTwo]);  //p3
		}else{
		temp = 0;
	}
	
	counterTwo++;
	temp++;
	
}


ISR(USART_RXC_vect)
{
	int8 data = Bluetooth_Receive();
	
	if (data == 'J')
	{
		Buzzer_TurnOn();
		
		LCD_Clear();
		LCD_String("Restart");
		LCD_SetPos(2,2);
		LCD_String("Required");
		
		connected = false;
		AdminMode = false;
		UserMode = false;
		
		}else if (data == 'Q'){
		// nothing
		}else{
		if (connected == false)
		connected = checkIfConnected(data);
		if (AdminMode == false)
		AdminMode = checkIfAdmin(data);
		if (UserMode == false)
		UserMode = checkIfUser(data);
		
		if(connected){

			counterTwo = 0;
			temp = 0;
			
			LCD_Clear();
			LCD_String("Connected");
			Bluetooth_Transmit('A'); // Start TX interrupt to send data stored in EEPROM
			
			editUser[0] = false;
			editUser[1] = false;
			editUser[2] = false;
			
			deltUser[0] = false;
			deltUser[1] = false;
			deltUser[2] = false;

			editPasses[0] = false;
			editPasses[1] = false;
			editPasses[2] = false;
			
			AdminMode = false;
			UserMode = false;
			connected = false;
			
			editUsers = false;
			lights = false;
			door = false;
			keypad = false;
			
			Lamp = false;
			Alarm = false;
		}
		

		
		
		///////////////////////////ADMIN MODE////////////////////////////////////
		if (AdminMode){
			
			LCD_Clear();
			LCD_String("ADMIN MODE");
			
			if (data == 'E'){
				editUsers = true;
				}else if (data == 'D'){
				door = true;
			}else if (data == 'L')
			{
				lights = true;
				}else if (data == 'H') {
				LCD_SetPos(2,1);
				LCD_String("SIGNED OUT");
				
				editUsers = false;
				lights = false;
				door = false;
				AdminMode = false;
				
				}else{
				// do nothing
			}
			
			
			
			if(editUsers){
				
				LCD_SetPos(2,1);
				LCD_String("USER CONTORLS");
				
				keypad = allowKeypad(data);
				
				if (editUser[0] == true){
					
					if (counter < maxUserInput){
						EEPROM_Write(counter,data);
						usersBlu[0][counter] = data;
						counter++;
						}if (counter == maxUserInput){
						
						editUser[0] = false;
						editPasses[0] = true;
						counter = 0;
					}
				}
				else if (editUser[1] == true){
					if (counter < maxUserInput){
						EEPROM_Write(counter+(maxUserInput*2),data);
						usersBlu[1][counter] = data;
						counter++;
						}if (counter == maxUserInput){
						editUser[1] = false;
						editPasses[1] = true;
						counter = 0;
					}
					}else if (editUser[2] == true){
					if (counter < maxUserInput){
						EEPROM_Write(counter+(maxUserInput*4),data);
						usersBlu[2][counter] = data;
						counter++;
						}if (counter == maxUserInput){
						editUser[2] = false;
						editPasses[2] = true;
						counter = 0;
					}
					}else if(editPasses[0] == true){
					if (counter < maxUserInput){
						EEPROM_Write(counter+maxUserInput,data);
						passes[0][counter] = data;
						counter++;
						}if (counter == maxUserInput){
						editPasses[0] = false;
						counter = 0;
					}
					}else if(editPasses[1] == true){
					if (counter < maxUserInput){
						EEPROM_Write(counter+(maxUserInput*3),data);
						passes[1][counter] = data;
						counter++;
						}if (counter == maxUserInput){
						editPasses[1] = false;
						counter = 0;
					}
					}else if (editPasses[2] == true){
					if (counter < maxUserInput){
						EEPROM_Write(counter+(maxUserInput*5),data);
						passes[2][counter] = data;
						counter++;
						}if (counter == maxUserInput){
						editPasses[2] = false;
						counter = 0;
					}
					}else if (keypad){
					if(keypadallowed){
						LCD_SetPos(2,0);
						LCD_String("KEYPAD DISABLED");
						keypadallowed = false;
						}else{
						LCD_SetPos(2,1);
						LCD_String("KEYPAD ALLOWED");
						keypadallowed = true;
					}
					
				}
				else if (data == '#'){
					editUsers = false;
				}
				else{
					
					switch(data){
						// based on the received predefined alphabetic letters action is taken
						case 'I':
						editUser[0] = true;
						break;
						case 'O':
						editUser[1] = true;
						break;
						case 'P':
						editUser[2] = true;
						break;
						case '%':
						deltUser[0] = true;
						break;
						case '@':
						deltUser[1] = true;
						break;
						case '*':
						deltUser[2] = true;
						break;
						default:
						break;
					}
					
					if (deltUser[0] == true){
						for (int16 i = 0; i < (maxUserInput*2); i++){
							EEPROM_Write(i,'-');
						}
						for (int16 i = 0; i < maxUserInput; i++){
							usersBlu[0][i] = '-';
							passes[0][i] = '-';
						}
					}
					else if (deltUser[1] == true){
						for (int16 i = 0; i < (maxUserInput*2); i++){
							EEPROM_Write(i+10,'-');
						}
						for (int16 i = 0; i < maxUserInput; i++){
							usersBlu[1][i] = '-';
							passes[1][i] = '-';
						}
					}
					else if (deltUser[2] == true){
						for (int16 i = 0; i < (maxUserInput*2); i++){
							EEPROM_Write(i+20,'-');
						}
						for (int16 i = 0; i < maxUserInput; i++){
							usersBlu[2][i] = '-';
							passes[2][i] = '-';
						}
					}
					
					// do nothing END OF USER EDIT if()
				}
				
				
				
				
				}else if (door){
				LCD_SetPos(2,1);
				if (data == 'F'){
					DOOR_Open();
					LCD_SetPos(2,1);
					LCD_String("DOOE OPENED");
					}else if (data == 'G'){
					DOOR_Close();
					LCD_SetPos(2,1);
					LCD_String("DOOR CLOSED");
					}else if (data == 'W'){
					door = false;
				}
				else{
					// do nothing END OF DOOR if()
				}
				
				
				
				
			}
			else if (lights){
				
				if (data == 'Z'){
					LCD_SetPos(2,1);
					LCD_String("LAMP ON");
					Lamp = true;
					}else if (data == 'X'){
					LCD_SetPos(2,1);
					LCD_String("LAMP OFF");
					Lamp = false;
				}
				else if (data == '!'){
					lights = false;
					}else{
					LED_Control(data);
					//END OF LIGHTS if()
				}
				
				
				if (Lamp){
					LCD_SetPos(2,1);
					LCD_String("LAMP ON");
					dimming = AC_Lamp_Set_Dimming(data);
					}else{
					// do nothing END OF LAMP if()
				}
				
				}else{
				// do nothing END OF ADMIN MODE if()
			}
			///////////////////////////ADMIN MODE////////////////////////////////////


			///////////////////////////USER MODE////////////////////////////////////
			
			}else if (UserMode){
			LCD_Clear();
			LCD_String("USER MODE");

			if (data == 'L'){
				lights = true;
				}else if (data == 'H') {
				LCD_SetPos(2,1);
				LCD_String("SIGNED OUT");
				
				lights = false;
				UserMode = false;
				
				}else{
				// do nothing
			}
			
			if (data == 'Z'){
				LCD_SetPos(2,1);
				LCD_String("LAMP ON");
				Lamp = true;
				}else if (data == 'X'){
				LCD_SetPos(2,1);
				LCD_String("LAMP OFF");
				Lamp = false;
			}
			else if (data == '!'){
				lights = false;
				}else{
				LED_Control(data);
				//END OF LIGHTS if()
			}

			
			if (Lamp){
				LCD_SetPos(2,1);
				LCD_String("LAMP ON");
				dimming = AC_Lamp_Set_Dimming(data);
				}else{
				// do nothing END OF LAMP if()
			}
			
			}else{
			//// do nothing END OF USER MODE & BLUETOOTH RECIVING DATA if()
		}
	}

	///////////////////////////USER MODE////////////////////////////////////
}


/////////////////////////////////////////////////////////////////////////////// AC LAMP INTERRUPT (INT0) ///////////////////////////////////////////////////////////////////////////////////////////////

ISR(INT0_vect){

	if (Lamp)
	{
		delayDimming(dimming); // delay used to dim the light by only using part of tha AC voltage, adjusting the delay will adjust the brightness --> (0 = max brightness  ---  1024 = min brightness)
		AC_Lamp_On(); // switch light on/off quick to make use of the dimming delay and turn light on
		_delay_ms(10);
		AC_Lamp_Off();
	}


}

