/*

morse

Klasa konwertuj�ca ciag znak�w na sygna� dzwi�kowy kodu morsa

Autor
Bartosz Sk�rka


Historia zmian

Autor				Co zmienil									Data
Bartosz Sk�rka		Data Utworzenia								16.10.2018
Bartosz Sk�rka		Utworzenie metod set oraz get				16.10.2018
Bartosz Sk�rka		Przeci��enie operator�w						18.10.2018
Bartosz Sk�rka		Dodanie opis�w metod						28.10.2018
Bartosz Sk�rka		Wersja Oryginalna							28.10.2018
*/

#ifndef _Morse_H
#define _Morse_H
#include "convert.h"
#define pause " "

class morse
{
private:
	int Frequency; // cz�stotliwo��
	int Pause; // przerwa pomiedzy kropkami i kreskami
	int DotTime; // czas trwania kropki alfabetu morsa
	int DashTime; // czas trwania kreski alfabetu morsa
	int CharPause; // przerwa pomiedzy poszcze�lnymi literami
	convert converter; // obiekt klasy convert, odpowiedzialny za t�umaczenie 

public:
	/*
	Konstruktor
	*/
	morse();

	/*
	Konstruktor kopiuj�cy
	*/
	morse(const morse& M);

	/*
	Destruktor
	*/
	~morse();

	/*
	Metoda nadaje warto�� zmiennej Frequency
	*/
	void setFrequency(int Freq);

	/*
	Metoda nadaje warto�� zmiennej Pause
	*/
	void setPause(int P);

	/*
	Metoda nadaje warto�� zmiennej DotTime
	*/
	void setDotTime(int DotT);

	/*
	Metoda nadaje warto�� zmiennej DashTime
	*/
	void setDashTime(int DashT);

	/*
	Metoda nadaje warto�� zmiennej CharPause
	*/
	void setCharPause(int ChP);
	
	/*
	Metoda zwraca wartosc zmiennej Frequency
	*/
	const int getFrequency() const;

	/*
	Metoda zwraca wartosc zmiennej Pause
	*/
	const int getPause() const;

	/*
	Metoda zwraca wartosc zmiennej DotTime
	*/
	const int getDotTime() const;

	/*
	Metoda zwraca wartosc zmiennej DashTime
	*/
	const int getDashTime() const;

	/*
	Metoda zwraca wartosc zmiennej CharPause
	*/
	const int getCharPause() const;

	/*
	Metoda zwraca obiekt klasy convert
	*/
	const convert getConverter() const;

	/*
	Przeci��ony operator przypisania
	*/
	morse & operator = (const morse& m);

	/*
	Przeci��ony operator t�umaczy ci�g znak�w typu const char* na morsa
	*/
	morse & operator << (const char* chr);

	/*
	Przeci��ony operator t�umaczy ci�g znak�w typu char na morsa
	*/
	morse & operator << (char chr);

	/*
	Przeci��ony operator t�umaczy liczby zmienno przecinkowe typu double na morsa
	*/
	morse & operator << (double dbl);

	/*
	Przeci��ony operator t�umaczy liczby ca�kowite przecinkowe typu double na morsa
	*/
	morse & operator << (long lng);




	
};


/*
Funkcja oblicza ilo�� cyfr zmiennej typu long
*/
const int longDigits(long lng);

#endif 


