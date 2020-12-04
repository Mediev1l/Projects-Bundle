#include <iostream>
#include "morse.h"
#include <Windows.h>


morse::morse()
	:converter(), Frequency(440), Pause(100), DotTime(100), DashTime (200), CharPause (200)
{
}

morse::morse(const morse & M)
{
	*this = M;
}

morse::~morse()
{
}

void morse::setFrequency(int Freq)
{
	Frequency = Freq;
}

void morse::setPause(int P)
{
	Pause = P;
}

void morse::setDotTime(int DotT)
{
	DotTime = DotT;
}

void morse::setDashTime(int DashT)
{
	DashTime = DashT;
}

void morse::setCharPause(int ChP)
{
	CharPause = ChP;
}


const int morse::getFrequency() const
{
	return Frequency;
}

const int morse::getPause() const
{
	return Pause;
}

const int morse::getDotTime() const
{
	return DotTime;
}

const int morse::getDashTime() const
{
	return DashTime;
}

const int morse::getCharPause() const
{
	return CharPause;
}

const convert morse::getConverter() const
{
	return converter;
}

morse & morse::operator=(const morse & m)
{
	this->Frequency = m.Frequency;
	this->Pause = m.Pause;
	this->DotTime = m.DotTime;
	this->DashTime = m.DashTime;
	this->CharPause = m.CharPause;

	return *this;
}

morse & morse::operator<<(const char* chr)
{
	converter.translate(chr);
	
	for (int i = 0; i < converter.returnSize(); i++)
	{
		for (int j = 0; j < converter.returnSize2d(i); j++)
		{
			switch (converter.returnLetter(i,j))
			{
			case '.':
			{
				Beep(Frequency,DotTime);
				break;
			}
			case '_':
			{
				Beep(Frequency, DashTime);
				break;
			}
			case ' ':
			{
				Sleep(CharPause);
				break;
			}
			}
			Sleep(Pause);
		}
		Sleep(CharPause);
		
	}
	return *this;
}

morse & morse::operator<<(char chr)
{
	*this << &chr;
	return *this;
}

morse & morse::operator<<(double dbl)
{
	char* temp = new char[50];
	sprintf_s(temp, 50, "%0.8f", dbl);
		*this << temp;
		delete[] temp;

	return *this;
}

morse & morse::operator<<(long lng)
{
	char* temp = new char[longDigits(lng)+1];
	_itoa_s(lng, temp, longDigits(lng)+1, 10);
		*this << temp;
		delete[] temp;

	return *this;

}


const int longDigits(long lng)
{
	int digits = 0;
	if (lng < 0) digits = 1;
	while (lng)
	{
		lng /= 10;
		digits++;
	}
	return digits;
}