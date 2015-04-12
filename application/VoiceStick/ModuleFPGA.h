/*
* ModuleFPGA.h
* [PLACEHOLDER DESCRIPTION]
* Author: alle2004,dupm2216,leta1602,maia2604,poum2319,valp2602
* Date: Hiver 2015
* Copyright (c) 2015   Département de génie électrique et génie informatique
*                       Université de Sherbrooke
*/

#ifndef MODULE_FPGA_H
#define MODULE_FPGA_H

#include "CommunicationFPGA/CommunicationFPGA.h"
#include <windows.h>
#include <qthread.h>

class ModuleFPGA : public QThread
{
	Q_OBJECT

public:
	ModuleFPGA();
	~ModuleFPGA();

public slots:
	void pause();	//Pause reading FPGA
	void resume();	//Resume reading FPGA
		
signals:
	void fpgaError();//Emitted when an FPGA error is detected

	//Emitted when the n-th phonem has been detected
	void phonemDetected(int n);

private:
	CommunicationFPGA m_fpga;
	bool m_needToReadFPGA = false;	//True if we need to read the FPGA
	bool m_timeToDie = false;	//True if thread must stop

	//Check for buttons pressed on the FPGA and emits signals accordingly
	//If there is an FPGA error, emit fpgaError() and pause
	//Make sure to "pause" ModuleFPGA before quitting your program, or else the FPGA will freeze and need to be reset
	void run();

	//Simulate a key stroke on the program currently on focus
	//This needs to be redesigned because we can only simulate keys associated with a character (i.e. no F1..F12, delete, backspace, etc keys)
	//WINDOWS ONLY!
	void simulateKeyStroke(char key); //Move to VoiceStick sometimes
};

#endif //MODULE_FPGA_H