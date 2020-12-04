/*

Edit

Klasa wstawiajaca pole tekstowe do konsoli

Autor
Bartosz Skórka


Historia zmian

Autor				Co zmienil																Data
Bartosz Skórka		Data Utworzenia															30.10.2018
Bartosz Skórka		Utworzenie deklaracji													02.11.2018
Bartosz Skórka		Utworzenie set'erow i getter'ow											05.11.2018
Bartosz Skórka		Utworzenie definicji metod checkKey oraz userText						12.11.2018
Bartosz Skórka		Dodanie opisow metod													12.11.2018
Bartosz Skórka		Wersja oryginalna														12.11.2018


*/

#ifndef _Edit_H
#define _Edit_H

#include <string>
#include <windows.h>
#include <iostream>
#include <conio.h>



class Edit
{
public:
	enum colors { Blue = 1, Green = 2, Red = 4, Yellow = 6, White = 7, Black = 0 };
protected:
	int length;
	int pos_X;
	int pos_Y;
	std::string text;
	colors text_color;
	colors background_color;
	HANDLE hd;
	COORD crd;
	
	
public:
	
	/*
	Konstruktor Bezparametrowy
	*/
	Edit();

	/*
	Konstruktor Kopiujacy
	*/
	Edit(const Edit& E);

	/*
	Destruktor
	*/
	~Edit();

	/*
	Ustawia pozycje pola tekstowego w konsoli
	*/
	void setPosition(int x, int y);

	/*
	Ustawia dlugosc pola tekstowego
	*/
	void setLength(int length);

	/*
	Wstawia tekst do utworzonego pola tekstowego
	*/
	void setText(std::string text);

	/*
	Ustawia kolor liter w polu tekstowym
	*/
	void setTextColor(colors text_col);

	/*
	Ustawia kolor tla w polu tekstowym
	*/
	void setBackgroundColor(colors backgroud_col);

	/*
	Ustawia pozycje X pola tekstowego
	*/
	void setPos_X(int X);

	/*
	Ustawia pozycje Y pola tekstowego
	*/
	void setPos_Y(int Y);

	/*
	Wyswietla pole tekstowe
	*/
	void display();

	/*
	Pozwala wprowadzic znaki do pola tekstowego przez uzytkownika
	*/
	void userText();

	/*
	Zwraca wartosc zmiennej Length
	*/
	const int getLength() const;

	/*
	Zwraca wartosc zmiennej pos_X
	*/
	const int getPos_X() const;

	/*
	Zwraca wartosc zmiennej pos_Y
	*/
	const int getPos_Y() const;

	/*
	Zwraca wpisany tekst
	*/
	const std::string getText() const;

	/*
	Metoda sprawdzajacy ktory przycisk zostal wcisniety
	*/
	const int checkKey() const;


	/*
	Przeciazony operator przypisania
	*/
	Edit & operator = (const Edit& E);

	


};




#endif