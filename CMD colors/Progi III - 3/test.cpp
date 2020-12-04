/*#include <Windows.h>
#include <iostream>
#include <conio.h>

using namespace std;

int main()
{
	HANDLE hc;
	hc = GetStdHandle(STD_OUTPUT_HANDLE); //pobiera standardowy uchwyt i zpisuje go do hc
	for (int i = 0; i < 16; i++)
	{
		//SetConsoleTextAttribute(hc, 0x00010  ); // ustawia atrybut koloru
		SetConsoleTextAttribute(hc, i);
		std::cout << "Kolor: " << i << std::endl;

	}
		char x = _getch();
		std::cout << x;

	COORD c;
	c.X = 5;
	c.Y = 5;
	SetConsoleCursorPosition(hc, c);
	cout << "Witaj Swiecie";

	cin.get(); // usun

	return 0;
}*/