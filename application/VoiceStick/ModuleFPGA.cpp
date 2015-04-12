/*
* ModuleFPGA.cpp
* [PLACEHOLDER DESCRIPTION]
* Author: alle2004,dupm2216,leta1602,maia2604,poum2319,valp2602
* Date: Hiver 2015
* Copyright (c) 2015   Département de génie électrique et génie informatique
*                       Université de Sherbrooke
*/

#include "ModuleFPGA.h"

ModuleFPGA::ModuleFPGA()
{
	start();
}

ModuleFPGA::~ModuleFPGA()
{
	m_timeToDie = true;
	m_needToReadFPGA = false;
	wait(5000);	//Wait max 5 seconds or until the thread is finished executing
}

void ModuleFPGA::run()
{
	int val = 0;	//holds the value of the register read
	while (!m_timeToDie)
	{
		while (m_needToReadFPGA)
		{
			//Wait until a button's state changes
			//When the do-while is over, val holds the value of the button register
			int oldVal = val;
			do
			{
				//Check for errors
				if (!m_fpga->estOk() || !m_fpga->lireRegistre(BTN, val))
				{
					emit fpgaError();
					m_needToReadFPGA = false;
				}

			} while (val == oldVal && m_needToReadFPGA);

			if (!m_needToReadFPGA) break;	//Skip remaining actions if there was a problem with the FPGA

			switch (val)
			{
			case 1:	//BTN0
				simulateKeyStroke('1');
				break;

			case 2:	//BTN1
				simulateKeyStroke('2');
				break;

			case 4:	//BTN2
				simulateKeyStroke('3');
				break;

			case 8:	//BTN3
				simulateKeyStroke('4');
				break;

			default: break; //Zero or more than one button pressed
			}
		}
	}
}

//A mettre dans voiceStick plus tard
void ModuleFPGA::simulateKeyStroke(char key)
{
	//Init input structure
	INPUT input;
	memset(&input, 0, sizeof(input)); 

	//Simulate key stroke
	//VkKeyScan(' ') = Translates a character to the corresponding virtual-key code and shift state for the current keyboard.
	//type can be:INPUT_MOUSE 0, INPUT_KEYBOARD 1 , INPUT_HARDWARE 2
	input.type = INPUT_KEYBOARD;		//INPUT_KEYBOARD is a keyboard event, use the "ki" structure of the union
	input.ki.wVk = VkKeyScan(key);	//ki = KeyBoard INPUT
	//Membre : wVk, wScan et dwFlags
	//VK_UP							//wVk = Is a virtual key code, the code must be a value in the range 1 to 254 (ASCII)
	//VK_DOWN						//dwFlags = Specifies various aspects of a keystroke, combination of certain value : KEYEVENTF_EXTENDEDKEY, KEYEVENTF_KEYUP, KEYEVENTF_SCANCODE KEYEVENTF_UNICODE
	//VK_RIGHT						//KEYEVENTF_EXTENDEDKEY	= 
	//VK_LEFT						//KEYEVENTF_KEYUP = if specified, key is released, if not, key is not released
	//wVk = Is a virtual key code, the code must be a value in the range 1 to 254 (ASCII)
	//dwFlags = Specifies various aspects of a keystroke, combination of certain value : KEYEVENTF_EXTENDEDKEY, KEYEVENTF_KEYUP, KEYEVENTF_SCANCODE KEYEVENTF_UNICODE
	//KEYEVENTF_EXTENDEDKEY	= 
	//KEYEVENTF_KEYUP = if specified, key is released, if not, key is not released
	//KEYEVENTF_SCANCODE
	//KEYEVENTF_UNICODE


	//Sleep(100);				//Pause jusqu a ce que le temps a passer et poursuit

	SendInput(1, &input, sizeof(INPUT));	//SendInput ( UINT, LPINPUT, int cbSize)
	input.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &input, sizeof(INPUT));
}

void ModuleFPGA::resume()
{
	m_needToReadFPGA = true;
}

void ModuleFPGA::pause()
{
	m_needToReadFPGA = false;
}