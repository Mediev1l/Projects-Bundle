#include "Ccolor.h"

void colorChange(int x)
{
	HANDLE hd;
	hd = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hd, x);

}

std::ostream & defcolor(std::ostream & out)
{
	colorChange(7);
	return out;
}


std::ostream & blue(std::ostream & out)
{
	colorChange(1);
	return out;
}

std::ostream & green(std::ostream & out)
{
	colorChange(2);
	return out;
}

std::ostream & red(std::ostream & out)
{
	colorChange(4);
	return out;
}

std::ostream & yellow(std::ostream & out)
{
	colorChange(6);
	return out;
}

std::ostream & white(std::ostream & out)
{
	colorChange(7);
	return out;
}

std::ostream & black(std::ostream & out)
{
	colorChange(0);
	return out;
}

void color(std::ios_base& os, int l)
{
	colorChange(l);
}


std::_Smanip<int> setcolor(int no)
{
	return (std::_Smanip<int>(&color, no));
}