/*

ppm

Klasa otwierajaca i modyfikujaca plik w formacie ppm

Autor
Bartosz Sk�rka


Historia zmian

Autor				Co zmienil									Data
Bartosz Sk�rka		Data Utworzenia								13.11.2018
Bartosz Sk�rka		Utworzenie metod invert, reverse, to_grey	24.11.2018
Bartosz Sk�rka		Utworzenie metod to_ascii i grey_color		25.11.2018
Bartosz Sk�rka		Wersja pierwsza								26.11.2018
Bartosz Sk�rka		Dodanie Metody tworzacej wykres ppm			05.12.2018
Bartosz Sk�rka		Utworzenie Konstruktora bez-par				10.12.2018
Bartosz Sk�rka		Wersja ostateczna							10.12.2018

*/

#ifndef _ppm_H
#define _ppm_H
#include "obraz.h"

class ppm : public obraz
{
public:

	/*
	Konstruktor bezparametrowy
	*/
	ppm();

	/*
	Wczytywanie pliku w formacie PPM
	*/
	ppm(std::string file);

	/*
	Konstruktor Kopiujacy
	*/
	ppm(const ppm& p);


	/*
	Destruktor
	*/
	~ppm();


	/*
	Metoda odwracajaca obrazek wokol osi Y
	*/
	void invert() override;


	/*
	Metoda Konwertujaca obrazek w odcienie szarosci
	*/
	void to_grey() override;


	/*
	Metoda odwracajaca obrazek wokol osi X
	*/
	void reverse() override;


	/*
	Metoda Konwertujaca obrazek na format PBM
	*/
	void to_PBM() override;


	/*
	Metoda Konwertujaca obrazek na kod ASCII
	*/
	void to_ASCII() override;


	/*
	Metoda tworzy wykres w  formacie ppm
	*/
	void make_chart(std::string name ,std::vector<int> vect, int x, int y,int max) override;


	/*
	Medota przeksztalcajaca kolor rgb na szarosc
	*/
	const int grey_color(int i) const;


};

#endif


