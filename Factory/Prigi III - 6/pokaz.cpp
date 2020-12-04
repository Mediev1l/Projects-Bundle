//#define _WIN32_WINNT 0x403
//#include <windows.h>
//
//void capslockBlink();
//
//int main()
//{
//	for (int i = 0; i < 10; i++)
//	{
//		capslockBlink();
//		Sleep(300);
//	}
//
//	return 0;
//}
//
//void capslockBlink()
//{
//	INPUT in[2]; // struktura input ki - keyboard / mi mouse / 0 = wcisniecie 1 = wycisniecie
//	in[0].type = INPUT_KEYBOARD; // typu keyboard
//	in[0].ki.wVk = VK_CAPITAL; //word virtual key - symulacja wcisniecia klawisza caps lock	
//	in[0].ki.wScan = 0; // flagi 
//	in[0].ki.time = 0;
//	in[0].ki.dwFlags = 0;
//	in[0].ki.dwExtraInfo = 0;
//	//Sleep(1000);
//	in[1] = in[0];
//	in[1].ki.dwFlags = KEYEVENTF_KEYUP;  //
//	::SendInput(2, in, sizeof(INPUT)); // wpycha w kolejke zadan zdarzenie
//
//}