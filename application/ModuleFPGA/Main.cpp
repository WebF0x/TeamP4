/*
* main.cpp
* Ce fichier est temporaire et sera effacé lorsqu'on aura incorporé ModuleFPGA au projet VoiceStick
* Author: alle2004,dupm2216,leta1602,maia2604,poum2319,valp2602
* Date: Hiver 2015
* Copyright (c) 2015   Département de génie électrique et génie informatique
*                       Université de Sherbrooke
*/

#include <windows.h>
#include <iostream>
#include "CommunicationFPGA/CommunicationFPGA.h"
#include "ModuleFPGA.h"
#include <qcoreapplication.h>

using namespace std;

int main(int argc, char** argv)
{
	QCoreApplication app(argc, argv);

	ModuleFPGA fpga;
	fpga.start();
	system("pause");
	fpga.pause();
	//Gotta close by pressing X on the console

	return app.exec();
}