/*

obraz

Klasa posiadajace metody wirtualne oraz zmienne do obslugi obrazow

Autor
Bartosz Skórka


Historia zmian

Autor				Co zmienil									Data
Bartosz Skórka		Data Utworzenia								13.11.2018
Bartosz Skórka		Utworzenie definicji i deklaracji			24.11.2018
Bartosz Skórka		Dodanie metod wirtualnych					24.11.2018
Bartosz Skórka		Wersja oryginalna							26.11.2018

*/


#ifndef _Obraz_H
#define _Obraz_H

#include <vector>
#include "color.h"
#include <string>
#include <iostream>
#include <unordered_set>
#include <fstream>

class obraz
{
protected:
	std::string name;
	bool open;
	int pixel_X;
	int pixel_Y;
	int max_value;
	std::vector<color> all_pixels;

public:

	/*
	Konstruktor
	*/
	obraz(std::string name);

	/*
	Konstruktor Kopiujacy
	*/
	obraz(const obraz& ob) = delete;

	
	/*
	Destruktor
	*/
	virtual ~obraz();


	//////////////////////////////////////////
	
	//Metody przeznaczone na cele dziedziczenia
	
	virtual void invert() = 0;
	virtual void to_grey() = 0;
	virtual void reverse() = 0;
	virtual void to_PBM() = 0;
	virtual void to_ASCII() = 0;

	//////////////////////////////////////////


	/*
	Metoda zwracajaca nazwe pliku
	*/
	const std::string get_name() const;


	/*
	Metoda zwracajaca czy plik zostal otworzony
	*/
	const bool get_open() const;


	/*
	Metoda zwracajaca liczbe pixeli X
	*/
	const int get_pixel_X() const;


	/*
	Metoda zwracajaca liczbe pixeli Y
	*/
	const int get_pixel_Y() const;


	/*
	Metoda zwracajaca liczbe maksymalnej wartosci koloru
	*/
	const int get_max_value() const;


	/*
	Metoda zwracajaca vektor kolorow wszystkich pixeli danego obrazka
	*/
	const std::vector<color> get_all_pixels() const;


	/*
	Przeciazony operator przypisania
	*/
	obraz& operator = (const obraz& rhs);
};

#endif