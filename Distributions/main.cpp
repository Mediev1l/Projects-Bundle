/*
		Roczny koszt utrzymania auta

		Etap 1 - Koszt Paliwa
			
			Koszt paliwa (rozk³ad normalny)

			Spalanie (rozk³ad normalny)

			Liczba km / rok (rozk³ad normalny)

		Etap 2 - Naprawy roczne

			Czy auto siê popsuje (rozk³ad bernoulliego)
				
				Tak ? - Co siê popsu³o (rozk³ad dyskretny)

					koszt naprawy (rozk³ad normalny)

		Etap 3 - Ubezpieczenie samochodu

			Czy kupujemy OC czy rowniez AC (rozk³ad bernoulliego)

				koszt OC (rozklad normalny)
				koszt AC (rozklad normalny)

		Etap 4 - Dodatkowe wydatki (kosmetyki, myjnie itp.)

			Koszt (rozk³ad normalny)



*/



#include <iostream>
#include <random>
#include <time.h>
#include <fstream>

std::mt19937 generator(time(nullptr));

double rozklad_normalny(double reasult, double sigma)
{
	double temp = -1;
	std::normal_distribution<> distribution(reasult, sigma);

	while (temp < 0)
		temp = static_cast<double>(distribution(generator));

	return temp;
}

bool rozklad_bernoulliego(double true_probability)
{
	std::bernoulli_distribution distribution(true_probability);

	return distribution(generator);
}

int rozklad_dyskretny(double one, double two, double three, double four, double five)
{
	std::discrete_distribution<> distribution({ one, two, three, four, five });

	return static_cast<int>(distribution(generator));
}


double etap_1()
{
	double paliwo = rozklad_normalny(4.0, 0.5);

	double spalanie = rozklad_normalny(10.0, 2.0);

	int trasa = static_cast<int>(rozklad_normalny(15000, 5000));

	return (trasa / 100) * spalanie * paliwo;

}

double etap_2()
{
	bool popsute = rozklad_bernoulliego(0.5);
	double koszt = 0;

	if (popsute)
	{
		int usterka = rozklad_dyskretny(25.0, 20.0, 30.0, 20.0, 5.0);


		// uszkodzenie opon 25%
		if (usterka == 0)
		{
			koszt = rozklad_normalny(500, 200);

			koszt = koszt < 50 ? 50 : koszt;
		}
		// uszkodzenie karoserii 20%
		else if (usterka == 1)
		{
			koszt = rozklad_normalny(1000, 400);
		}
		// uszkodzenie zawieszenie 30%
		else if (usterka == 2)
		{
			koszt = rozklad_normalny(2000, 1000);
		}
		//uszkodzenie elektryki 20%
		else if (usterka == 3)
		{
			koszt = rozklad_normalny(500, 300);
		}
		//uszkodzenie silnika 5%
		else if (usterka == 4)
		{
			koszt = rozklad_normalny(3000, 1500);
		}
	}

	return koszt;
}

double etap_3()
{
	bool pelne_ubezpieczenie = rozklad_bernoulliego(0.3);
	double OC = 0;
	double AC = 0;

	OC = rozklad_normalny(1200, 300);

	// Czy kupione AC 
	if(pelne_ubezpieczenie)
	{
		AC = rozklad_normalny(1200, 500);
	}

	return OC + AC;
}

double etap_4()
{
	return rozklad_normalny(200, 100);
}

void Monte_Carlo()
{
	std::fstream file("Auto.txt", std::ios::out);

	for (int i = 0; i < 2000; i++)
	{
		double koszt = 0;

		koszt += etap_1();
		koszt += etap_2();
		koszt += etap_3();
		koszt += etap_4();

		file << static_cast<int>(koszt) << '\n';
		std::cout << static_cast<int>(koszt) << '\n';

	}

	file.close();
}


int main()
{

	Monte_Carlo();

	return 0;
}