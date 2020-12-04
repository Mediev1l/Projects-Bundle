/*

convert

Klasa t�umaczy ci�g znak�w na kod morsa i przechowuje go

Autor
Bartosz Sk�rka


Historia zmian

Autor				Co zmienil									Data
Bartosz Sk�rka		Data Utworzenia								16.10.2018
Bartosz Sk�rka		Dodanie podstawowych funkcjonalno�ci		16.10.2018
Bartosz Sk�rka		Utworzenie metod set oraz get				16.10.2018
Bartosz Sk�rka		Usuni�cie wyciek�w pami�ci					18.10.2018
Bartosz Sk�rka		Dodanie opis�w metod						28.10.2018
Bartosz Sk�rka		Wersja Oryginalna							28.10.2018
*/

#ifndef _Convert_H
#define _Convert_H


class convert
{
private:
	char** Letter; // zmienna przechowuj�ca przet�umaczone znaki
	int Size; // wielko�� pierwszego wymiaru zmiennej Letter
	int* Size2d; // wielko�ci drugiegich wymiar�w zmiennej Letter

public:
	/*
	Konstruktor
	*/
	convert();

	/*
	Konstruktor kopiuj�cy
	*/
	convert(const convert& c);

	/*
	Destruktor
	*/
	virtual ~convert();

	/*
	Metoda t�umaczy ci�g znak�w na alfabet morsa
	*/
	void translate(const char* word);

	/*
	Metoda zapisuje przet�umaczone litery w zmiennej Letter
	*/
	void save(int i, const char* chr);

	/*
	Metoda zwalniaj�ca pami��
	*/
	void clear();

	/*
	Metoda alokuje konkretn� ilo�� pami�ci dla zmiennej Letter
	*/
	void setLetter(int i, int j);

	/*
	Metoda nadaje warto�� zmiennej Size
	*/
	void setSize(int i);

	/*
	Metoda nadaje warto�� zmiennej Size2d
	*/
	void setSize2d(int i);

	/*
	Metoda zwraca znak zapisany w zmiennej Letter
	*/
	const char returnLetter(int i, int j) const;

	/*
	Metoda zwraca warto�� zmiennej Size
	*/
	const int returnSize() const;

	/*
	Metoda zwraca warto�� zmiennej Size2d
	*/
	const int returnSize2d(int i) const;

	/*
	Przeci��ony operator przypisania
	*/
	convert & operator = (const convert& m);

};

#endif

