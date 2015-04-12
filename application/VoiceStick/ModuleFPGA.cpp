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
				if (!m_fpga.estOk() || !m_fpga.lireRegistre(BTN, val))
				{
					emit fpgaError();
					m_needToReadFPGA = false;
				}

			} while (val == oldVal && m_needToReadFPGA);

			if (!m_needToReadFPGA) break;	//Skip remaining actions if there was a problem with the FPGA

			switch (val)
			{
			case 1:	//BTN0
				emit phonemDetected(0);
				break;

			case 2:	//BTN1
				emit phonemDetected(1);
				break;

			case 4:	//BTN2
				emit phonemDetected(2);
				break;

			case 8:	//BTN3
				emit phonemDetected(3);
				break;

			default: break; //Zero or more than one button pressed
			}
		}
	}
}

void ModuleFPGA::resume()
{
	m_needToReadFPGA = true;
}

void ModuleFPGA::pause()
{
	m_needToReadFPGA = false;
}