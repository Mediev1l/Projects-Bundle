/*

morse

Klasa konwertuj¹ca ciag znaków na sygna³ dzwiêkowy kodu morsa

Autor
Bartosz Skórka


Historia zmian

Autor				Co zmienil									Data
Bartosz Skórka		Data Utworzenia								16.10.2018
Bartosz Skórka		Utworzenie metod set oraz get				16.10.2018
Bartosz Skórka		Przeci¹¿enie operatorów						18.10.2018
Bartosz Skórka		Dodanie opisów metod						28.10.2018
Bartosz Skórka		Wersja Oryginalna							28.10.2018
*/

#ifndef _Morse_H
#define _Morse_H
#include "convert.h"
#define pause " "

class morse
{
private:
	int Frequency; // czêstotliwoœæ
	int Pause; // przerwa pomiedzy kropkami i kreskami
	int DotTime; // czas trwania kropki alfabetu morsa
	int DashTime; // czas trwania kreski alfabetu morsa
	int CharPause; // przerwa pomiedzy poszczeólnymi literami
	convert converter; // obiekt klasy convert, odpowiedzialny za t³umaczenie 

public:
	/*
	Konstruktor
	*/
	morse();

	/*
	Konstruktor kopiuj¹cy
	*/
	morse(const morse& M);

	/*
	Destruktor
	*/
	~morse();

	/*
	Metoda nadaje wartoœæ zmiennej Frequency
	*/
	void setFrequency(int Freq);

	/*
	Metoda nadaje wartoœæ zmiennej Pause
	*/
	void setPause(int P);

	/*
	Metoda nadaje wartoœæ zmiennej DotTime
	*/
	void setDotTime(int DotT);

	/*
	Metoda nadaje wartoœæ zmiennej DashTime
	*/
	void setDashTime(int DashT);

	/*
	Metoda nadaje wartoœæ zmiennej CharPause
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
	Przeci¹¿ony operator przypisania
	*/
	morse & operator = (const morse& m);

	/*
	Przeci¹¿ony operator t³umaczy ci¹g znaków typu const char* na morsa
	*/
	morse & operator << (const char* chr);

	/*
	Przeci¹¿ony operator t³umaczy ci¹g znaków typu char na morsa
	*/
	morse & operator << (char chr);

	/*
	Przeci¹¿ony operator t³umaczy liczby zmienno przecinkowe typu double na morsa
	*/
	morse & operator << (double dbl);

	/*
	Przeci¹¿ony operator t³umaczy liczby ca³kowite przecinkowe typu double na morsa
	*/
	morse & operator << (long lng);




	
};


/*
Funkcja oblicza iloœæ cyfr zmiennej typu long
*/
const int longDigits(long lng);

#endif 


