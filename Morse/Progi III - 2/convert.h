/*

convert

Klasa t³umaczy ci¹g znaków na kod morsa i przechowuje go

Autor
Bartosz Skórka


Historia zmian

Autor				Co zmienil									Data
Bartosz Skórka		Data Utworzenia								16.10.2018
Bartosz Skórka		Dodanie podstawowych funkcjonalnoœci		16.10.2018
Bartosz Skórka		Utworzenie metod set oraz get				16.10.2018
Bartosz Skórka		Usuniêcie wycieków pamiêci					18.10.2018
Bartosz Skórka		Dodanie opisów metod						28.10.2018
Bartosz Skórka		Wersja Oryginalna							28.10.2018
*/

#ifndef _Convert_H
#define _Convert_H


class convert
{
private:
	char** Letter; // zmienna przechowuj¹ca przet³umaczone znaki
	int Size; // wielkoœæ pierwszego wymiaru zmiennej Letter
	int* Size2d; // wielkoœci drugiegich wymiarów zmiennej Letter

public:
	/*
	Konstruktor
	*/
	convert();

	/*
	Konstruktor kopiuj¹cy
	*/
	convert(const convert& c);

	/*
	Destruktor
	*/
	virtual ~convert();

	/*
	Metoda t³umaczy ci¹g znaków na alfabet morsa
	*/
	void translate(const char* word);

	/*
	Metoda zapisuje przet³umaczone litery w zmiennej Letter
	*/
	void save(int i, const char* chr);

	/*
	Metoda zwalniaj¹ca pamiêæ
	*/
	void clear();

	/*
	Metoda alokuje konkretn¹ iloœæ pamiêci dla zmiennej Letter
	*/
	void setLetter(int i, int j);

	/*
	Metoda nadaje wartoœæ zmiennej Size
	*/
	void setSize(int i);

	/*
	Metoda nadaje wartoœæ zmiennej Size2d
	*/
	void setSize2d(int i);

	/*
	Metoda zwraca znak zapisany w zmiennej Letter
	*/
	const char returnLetter(int i, int j) const;

	/*
	Metoda zwraca wartoœæ zmiennej Size
	*/
	const int returnSize() const;

	/*
	Metoda zwraca wartoœæ zmiennej Size2d
	*/
	const int returnSize2d(int i) const;

	/*
	Przeci¹¿ony operator przypisania
	*/
	convert & operator = (const convert& m);

};

#endif

