#include "freqcounter.h"   
#include <time.h>   
#include <fstream>


/*
	Funkcja otwiera plik, zlicza znaki i zapisuje wyniki w formacie csv
*/
void Open_bible_characters(const std::string nazwa, freqcounter<char>& x)
{
	std::fstream file;
	try
	{
		file.open(nazwa, std::ios::in);

		if (!file.good())
			throw std::runtime_error("Nie mozna otworzyc pliku");


		if (file.peek() == std::ifstream::traits_type::eof())
			throw std::runtime_error("Plik jest pusty");

		char temp;


		while (!file.eof())
		{
			file.get(temp);
			x.addData(temp);
		}



		x.create();
		x.to_CSV(nazwa + ".CSV");
	}
	catch (std::exception& err)
	{
		std::cerr << err.what();
	}
	file.close();
}


/*
	Funkcja otwiera plik, zlicza wyrazy i zapisuje wyniki w formacie csv
*/
void Open_bible_strings(const std::string nazwa, freqcounter<std::string>& x)
{
	std::fstream file;
	try
	{
		file.open(nazwa, std::ios::in);

		if (!file.good())
			throw std::runtime_error("Nie mozna otworzyc pliku");


		if (file.peek() == std::ifstream::traits_type::eof())
			throw std::runtime_error("Plik jest pusty");

		std::string temp;
		
		

		while (!file.eof())
		{
			file >> temp;
			x.addData(temp);
		}

		

		x.create();


	}
	catch (const std::exception& err)
	{
		std::cerr << err.what();

	}
	file.close();

}


/*
	Funkcja zlicza wystapienia losowych liczb
*/
void Random_Ints(int range, int count, freqcounter<int>& x)
{
	srand(time(NULL));


	for (int i = 0; i < count; i++)
		x.addData(rand() % range);

	x.create();
}



int main()
{
	freqcounter<int> fc_i;
	

	Random_Ints(1000, 1000000, fc_i);
	fc_i.to_PPM_chart("ints_in_ppm");
	fc_i.print();




	freqcounter<char> fc_ch;

	Open_bible_characters("biblia-en.txt", fc_ch);
	//fc_ch.print();
	fc_ch.clear();

	Open_bible_characters("biblia-it.txt", fc_ch);
	//fc_ch.print();
	fc_ch.clear();

	Open_bible_characters("biblia-pl_ksiega_rdzaju_3.txt", fc_ch);
	//fc_ch.print();
	fc_ch.clear();

	Open_bible_characters("biblia-pl_ksiega_rdzaju.txt", fc_ch);
	//fc_ch.print();
	fc_ch.clear();

	
	

	freqcounter<std::string> fc_s;

	Open_bible_strings("biblia-en.txt", fc_s);
	//fc_s.print();
	fc_s.clear();

	Open_bible_strings("biblia-it.txt", fc_s);
	//fc_s.print();
	fc_s.clear();

	Open_bible_strings("biblia-pl_ksiega_rdzaju_3.txt", fc_s);
	//fc_s.print();
	fc_s.clear();

	Open_bible_strings("biblia-pl_ksiega_rdzaju.txt", fc_s);
	//fc_s.print();
	fc_s.clear();


	ppm ppm("lena.ppm");
	freqcounter<color> fc_c;
	
	for (int i = 0; i < ppm.get_size(); i++)
		fc_c.addData(ppm.get_one_pixel(i));

	fc_c.create();  
	fc_c.to_PPM_chart("assaaa");
	fc_c.print();
	

	

	std::cout << "END";

	std::cin.get();

	return 0;
}


