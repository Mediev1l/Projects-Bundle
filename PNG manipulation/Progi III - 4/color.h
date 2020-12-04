/*

color

Klasa przechowuje poszczegolne pixele jako RGB

Autor
Bartosz Skórka


Historia zmian

Autor				Co zmienil									Data
Bartosz Skórka		Data Utworzenia								13.11.2018
Bartosz Skórka		Wersja oryginalna							14.11.2018

*/

#ifndef _Color_H
#define _Color_H

class color
{
protected:

	int R;
	int G;
	int B;
	
public:

	/*
	Konstruktor Bezparametrowy
	*/
	color();


	/*
	Konstruktor Przyjmujacy parametry R G B
	*/
	color(int r, int g, int b);


	/*
	Konstruktor Kopiujacy
	*/
	color(const color& cl);

	/*
	Ustawia wartosc zmiennej R
	*/
	void setR(int r);


	/*
	Ustawia wartosc zmimennej G
	*/
	void setG(int g);


	/*
	Ustawia wartosc zmiennej B
	*/
	void setB(int b);


	/*
	Zwraca wartosc zmiennej R
	*/
	const int getR() const;


	/*
	Zwraca wartosc zmiennej G
	*/
	const int getG() const;


	/*
	Zwraca wartosc zmiennej B
	*/
	const int getB() const;


	/*
	Przeciazony operator przypisania
	*/
	color& operator = (const color& cl);

};

#endif