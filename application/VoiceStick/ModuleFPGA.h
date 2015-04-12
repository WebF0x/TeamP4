/*
* ModuleFPGA.h
* ModuleFPGA is used to read the FPGA and emit a signal everytime the state of the FPGA changes
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

	//Check for buttons pressed on the FPGA and emits phonemDetected(int) signals accordingly
	//If there is an FPGA error, emit fpgaError() and pause
	void run();
};

#endif //MODULE_FPGA_H