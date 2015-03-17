/*
*   Ce programme écrit et lit des données sur la carte FPGA afin de faire
*   quelques tests fonctionnels. Il utilise la classe CommunicationFPGA
*   qui est distribuée dans le cadre de S2.
*
*   Il est assumé que la communication est faite avec la carte FPGA qui
*   a été préalablement configurée correctement.
*
*   $Author: bruc2001 $
*   $Date: 2013-01-11 16:09:24 -0500 (ven., 11 janv. 2013) $
*   $Revision: 84 $
*   $Id: TestCommunicationFPGA.cpp 84 2013-01-11 21:09:24Z bruc2001 $
*
*   Copyright 2013 Département de génie électrique et génie informatique
*                  Université de Sherbrooke
*/

#include <iostream>
#include "CommunicationFPGA.h"

using namespace std;

int FPGA(int argc, char * argv[]) {
	CommunicationFPGA fpga;
	int val;

	if (!fpga.estOk())
	{
		cout << fpga.messageErreur() << endl;
		return 1;
	}

	//if (!fpga.lireRegistre(SW, val))
	//{
	//	cout << fpga.messageErreur() << endl;
	//	return 1;
	//}

	//cout << "SW: " << hex << val << endl;

	if (!fpga.lireRegistre(BTN, val))
	{
		cout << fpga.messageErreur() << endl;
		return 1;
	}
	else
	{
		cout << "BTN: " << hex << val << endl;
		val = 0xac;
	}
	
	//if (!fpga.ecrireRegistre(LD, val))
	//{
	//	cout << fpga.messageErreur() << endl;
	//	return 1;
	//}

	//val = 0xa;
	//if (!fpga.ecrireRegistre(AN3, val))
	//{
	//	cout << fpga.messageErreur() << endl;
	//	return 1;
	//}

	//val++;
	//if (!fpga.ecrireRegistre(AN2, val))
	//{
	//	cout << fpga.messageErreur() << endl;
	//	return 1;
	//}

	//val++;
	//if (!fpga.ecrireRegistre(AN1, val))
	//{
	//	cout << fpga.messageErreur() << endl;
	//	return 1;
	//}

	//val++;

	//if (!fpga.ecrireRegistre(AN0, val))
	//{
	//	cout << fpga.messageErreur() << endl;
	//	return 1;
	//}
	system("PAUSE");
	return 0;
}