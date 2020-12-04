/*

Ccolor

Funkcje Zmieniajace kolory tekstu w konsoli

Autor
Bartosz Skórka


Historia zmian

Autor				Co zmienil									Data
Bartosz Skórka		Data Utworzenia								30.10.2018
Bartosz Skórka		Utworzenie deklaracji i definicji			12.11.2018
Bartosz Skórka		Wersja oryginalna							12.11.2018

*/


#ifndef _Ccolor_H
#define _Ccolor_H

#include <iostream>
#include <windows.h>
#include <iomanip>

/*
Funkcja zmieniajaca kolor tekstu strumienia wyjsciowego
*/
void colorChange(int x);

/*
Funkcja zmieniajaca kolor tekstu i tla
*/
void color(std::ios_base& os, int l);

/*
Manipulator zmieniajacy kolor tekstu i tla
*/
std::_Smanip<int> setcolor(int no);

/*
Manipulator zmieniajacy kolor tekstu strumienia wyjsciowego na niebieski
*/
std::ostream& blue(std::ostream& out);

/*
Manipulator zmieniajacy kolor tekstu strumienia wyjsciowego na zielony
*/
std::ostream& green(std::ostream& out);

/*
Manipulator zmieniajacy kolor tekstu strumienia wyjsciowego na czerwony
*/
std::ostream& red(std::ostream& out);

/*
Manipulator zmieniajacy kolor tekstu strumienia wyjsciowego na zolty
*/
std::ostream& yellow(std::ostream& out);

/*
Manipulator zmieniajacy kolor tekstu strumienia wyjsciowego na bialy
*/
std::ostream& white(std::ostream& out);

/*
Manipulator zmieniajacy kolor tekstu strumienia wyjsciowego na czarny
*/
std::ostream& black(std::ostream& out);

/*
Manipulator zmieniajacy kolor tekstu strumienia wyjsciowego na domyslny
*/
std::ostream& defcolor(std::ostream& out);



#endif
