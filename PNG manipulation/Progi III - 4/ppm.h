/*

ppm

Klasa otwierajaca i modyfikujaca plik w formacie ppm

Autor
Bartosz Skórka


Historia zmian

Autor				Co zmienil									Data
Bartosz Skórka		Data Utworzenia								13.11.2018
Bartosz Skórka		Utworzenie metod invert, reverse, to_grey	24.11.2018
Bartosz Skórka		Utworzenie metod to_ascii i grey_color		25.11.2018
Bartosz Skórka		Wersja oryginalna							26.11.2018

*/

#ifndef _ppm_H
#define _ppm_H
#include "obraz.h"

class ppm : public obraz
{
public:

	/*
	Wczytywanie pliku w formacie PPM
	*/
	ppm(std::string file);


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
	Medota przeksztalcajaca kolor rgb na szarosc
	*/
	const int grey_color(int i) const;
	
};

#endif


