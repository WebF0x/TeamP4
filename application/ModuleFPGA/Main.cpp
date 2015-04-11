#include <windows.h>
#include <iostream>
#include "CommunicationFPGA/CommunicationFPGA.h"

using namespace std;

int main()
{
	bool sortie = false;
	while (sortie == false)
	{
		CommunicationFPGA fpga;
		int val;
		/*int test = 0;*/
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
			/*val = 0xac;*/
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

		//system("PAUSE");

		/*cout<<"Quel test vouler vous faire?"<<endl;
		cout<<"Test a = 1" <<endl;
		cout<<"Test e = 2" <<endl;
		cout<<"Test w = 3" <<endl;
		cout<<"Test d = 4" <<endl;
		cout<<"Soritr = 5" <<endl;
		cout <<"Double tes avant entre"<< val << endl;*/
		/*cin>> val;*/

		INPUT input; // INPUT structure
		memset(&input, 0, sizeof(input));			//memset( ptr, value, num) 

		// fill it out for keyboard key presses...
		switch (val)
		{
		case 0:
		{
			cout << "Aucun bouton peser" << endl;
			/*system("PAUSE");*/
			break;
		}
		case 1:
		{
			//VkKeyScan(' ') = Translates a character to the corresponding virtual-key code and shift state for the current keyboard.
			//type can be:INPUT_MOUSE 0, INPUT_KEYBOARD 1 , INPUT_HARDWARE 2
			input.type = INPUT_KEYBOARD;		//INPUT_KEYBOARD is a keyboard event, use the "ki" structure of the union
			input.ki.wVk = VkKeyScan('1');	//ki = KeyBoard INPUT
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
			while (val == 1){
				//UINT = Number of structures in the LPINPUT array
				//LPINOUT = Array of Input structure, each structure represente an array to be inserted inkeyboard
				//cbSize = Size, in bytes, of an INPUT structure

				//modify the structure to do key up, a zero will indicate key down, as used above
				fpga.lireRegistre(BTN, val);
				cout << val << endl;
			}
			cout << input.ki.wVk << " est en ASCII! " << endl;
			break;
		}
		case 2:
		{
			input.type = INPUT_KEYBOARD;		//INPUT_KEYBOARD is a keyboard event, use the "ki" structure of the union
			input.ki.wVk = VkKeyScan('2');	//ki = KeyBoard INPUT
			SendInput(1, &input, sizeof(INPUT));	//SendInput ( UINT, LPINPUT, int cbSize)
			input.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &input, sizeof(INPUT));
			while (val == 2){
				fpga.lireRegistre(BTN, val);
				cout << val << endl;
			}
			cout << input.ki.wVk << " est en ASCII! " << endl;
			break;
		}
		case 4:
		{
			input.type = INPUT_KEYBOARD;		//INPUT_KEYBOARD is a keyboard event, use the "ki" structure of the union
			input.ki.wVk = VkKeyScan('3');	//ki = KeyBoard INPUT
			SendInput(1, &input, sizeof(INPUT));	//SendInput ( UINT, LPINPUT, int cbSize)
			input.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &input, sizeof(INPUT));
			while (val == 4){
				fpga.lireRegistre(BTN, val);
				cout << val << endl;
			}
			cout << input.ki.wVk << " est en ASCII! " << endl;
			break;
		}
		case 8:
		{
			input.type = INPUT_KEYBOARD;		//INPUT_KEYBOARD is a keyboard event, use the "ki" structure of the union
			input.ki.wVk = VkKeyScan('4');	//ki = KeyBoard INPUT
			SendInput(1, &input, sizeof(INPUT));	//SendInput ( UINT, LPINPUT, int cbSize)
			input.ki.dwFlags = KEYEVENTF_KEYUP;
			SendInput(1, &input, sizeof(INPUT));
			while (val == 8){
				fpga.lireRegistre(BTN, val);
				cout << val << endl;
			}
			cout << input.ki.wVk << " est en ASCII! " << endl;
			break;
		}
		case 3:
		{
			sortie = true;
			break;
		}
		}	//} de switch
	}	//} de while
	system("pause");
	return 0;
}