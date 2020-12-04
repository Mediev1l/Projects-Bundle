/*

freqcounter

Klasa szablonowa zliczajaca wystapienia danych

Autor
Bartosz Skórka


Historia zmian

Autor				Co zmienil									Data
Bartosz Skórka		Data Utworzenia								27.11.2018
Bartosz Skórka		Dodanie sortowania							27.11.2018
Bartosz Skórka		Dodanie wykresow ppm i csv					05.12.2018
Bartosz Skórka		Poprawki w kodzie							10.12.2018
Bartosz Skórka		Wersja oryginalna							10.12.2018


*/


#ifndef _Freqcounter_H
#define _Freqcounter_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "color.h"
#include "ppm.h"



template <class T>
class freqcounter
{
protected:
	std::vector<T> data;
	std::vector<T> counted_data;
	std::vector<int> count;
	ppm ppm;

public:

	/*
	Konstruktor bezparametrowy
	*/
	freqcounter();


	/*
	Konstruktor Kopiujacy
	*/
	freqcounter(const freqcounter& fr);


	/*
	Destruktor
	*/
	~freqcounter();



	/*
	Metoda dodajaca dane do klasy
	*/
	void addData(T temp_var);


	/*
	Metoda zliczajaca wystapienia wprowadzdonych danych
	*/
	void create();


	/*
	Metoda wypisujaca policzone dane do konsoli
	*/
	void print();


	/*
	Metoda sortujaca vektor danych
	*/
	void sort(std::vector<T>& x);


	/*
	Metoda usuwajaca przechowywane dane
	*/
	void clear();


	//////////////////////////////////
	//		Algorytm szybkiego sortowania
	
	void quicksort(std::vector<T>& tablica, int p, int r);
	int partition(std::vector<T>& tablica, int p, int r);
	/////////////////////////////////


	/*
	Metoda zwraca liczbe najczesciej pojawiajacego sie elementu
	*/
	const int get_max() const;


	/*
	Metoda tworzy wykres z zliczonych danych w formacie ppm
	*/
	void to_PPM_chart(std::string name);


	/*
	Metoda zapisuje policzone dane w formacie csv
	*/
	void to_CSV(std::string name);

};



template<class T>
inline freqcounter<T>::freqcounter()
	:data(0), counted_data(0), count(0), ppm()
{
}

template<class T>
inline freqcounter<T>::freqcounter(const freqcounter & fr)
	:data(fr.data)
	,counted_data(fr.counted_data)
	,count(fr.count)
	,ppm(fr.ppm)
{
}

template<class T>
inline freqcounter<T>::~freqcounter()
{
}

template<class T>
inline void freqcounter<T>::addData(T temp_var)
{
	data.push_back(temp_var);
}

template<class T>
inline void freqcounter<T>::create()
{
	try
	{
		if (data.empty())
			throw std::runtime_error("Brak danych do zliczenia");

		sort(data);

		int counter = 0;


		counted_data.push_back(data[0]);
		count.push_back(1);




		for (int i = 1; i < data.size(); i++)
		{

			if (data[i] == counted_data[counter])
			{
				count[counter]++;
			}
			else
			{
				counted_data.push_back(data[i]);
				count.push_back(1);
				counter++;
			}
		}
	}
	catch (const std::exception& err)
	{
		std::cerr << err.what();
	}


}



template<class T>
inline void freqcounter<T>::print()
{
	for (int i = 0; i < counted_data.size(); i++)
		std::cerr << counted_data[i] << ": "  << count[i] << std::endl;
}

template<class T>
inline void freqcounter<T>::sort(std::vector<T>& x)
{
	quicksort(x, 0, x.size() - 1);
}

template<class T>
inline void freqcounter<T>::clear()
{
	data.clear();
	counted_data.clear();
	count.clear();
}

template<class T>
inline void freqcounter<T>::quicksort(std::vector<T>& tablica, int p, int r)
{
	int q;
	if (p < r)
	{
		q = partition(tablica, p, r); 
		quicksort(tablica, p, q); 
		quicksort(tablica, q + 1, r);
	}
}
template<class T>
inline int freqcounter<T>::partition(std::vector<T>& tablica, int p, int r)
{

	T x = tablica[p]; 
	T w;
	int i = p, j = r; 
	while (true) 
	{
		while (tablica[j] > x) 
			j--;
		while (tablica[i] < x) 
			i++;
		if (i < j)
		{
			w = tablica[i];
			tablica[i] = tablica[j];
			tablica[j] = w;
			i++;
			j--;
		}
		else 
			return j;
	}
	
}

template<class T>
inline const int freqcounter<T>::get_max() const
{
	int temp = 0;


	for (int i = 0; i < count.size(); i++)
		if (temp < count[i])
			temp = count[i];

	return temp;

}

template<class T>
inline void freqcounter<T>::to_PPM_chart(std::string name)
{
	try
	{
		if (count.empty())
			throw std::runtime_error("Brak danych do utworzenia wykresu");


		ppm.make_chart(name, count, get_max(), count.size(), 255);

	}
	catch (std::exception& err)
	{
		std::cerr << err.what();
	}
}

template<class T>
inline void freqcounter<T>::to_CSV(std::string name)
{
	std::fstream file;
	try
	{

		
		file.open(name + ".CSV", std::ios::out);

		if (!file.good())
			throw std::runtime_error("Nie mozna otworzyc pliku");

		
		file << "Element" << "                         " << "Ilosc" << std::endl;


		for (int i = 0; i < counted_data.size(); i++)
			file<<counted_data[i] << "                         " << count[i] << std::endl;


		
	}
	catch (std::exception& err)
	{
		std::cerr << err.what();
	}
	file.close();
}


#endif