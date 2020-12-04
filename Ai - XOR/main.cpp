#include <iostream>
#include <string>
#include <fstream>
#include "Neuron.hpp"

using namespace std;

int main() {
	const int N = 4;
	vector<vector<double>> data = {

		{1.,1.,1.}
		,{-1.,1.,1.}
		,{-1.,-1.,1.}
		,{1.,-1.,1.}

	};
	double sum;

	//Wartosci oczekiwane
	std::vector<double> T = { 0.,1.,0.,1. };


	//blad
	double E;

	//maxymalny blad 
	double Emax = 0.00002;

	//wspolczynnik uczenia 
	double n = 0.1;

	//sygnal wyjsciowy
	std::vector<double> y(N, 0.);

	std::vector<std::vector<Neuron>> vecLayers =
	{
		 {{2},{2}} //Layer1
		,{{2}}   //Layer2
	};

	printf("Ucze sie Xora...\nWielkosc bledu: ");
	do {
		E = 0.0;
		for (int i = 0; i < N; ++i)
		{
			//Wpusc na wejscie neuronow dane
			for (int warstwa = 0, e = vecLayers.size(); warstwa < e; ++warstwa)
			{
				for (int neuron = 0, e = vecLayers[warstwa].size(); neuron < e; ++neuron)
				{
					if (warstwa == 0) vecLayers[warstwa][neuron].use(data[i]);
					else
					{
						std::vector<double> tmp = { vecLayers[0][0].getActiv(), vecLayers[0][1].getActiv(),1. };
						vecLayers[warstwa][neuron].use(tmp);
					}
				}
			}

			//Ustaw bledy
			Neuron* end = &vecLayers[1][0];
			std::vector<double> tmp = end->getWeights();
			for (int warstwa = vecLayers.size() - 1, e = -1; warstwa > e; --warstwa)
			{
				for (int neuron = 0, e = vecLayers[warstwa].size(); neuron < e; ++neuron)
				{
					if (warstwa == 1) end->setFault((T[i] - end->getActiv()) * end->getDerived());
					else
					{
						vecLayers[warstwa][neuron].setFault(tmp[neuron] * end->getFault() * vecLayers[warstwa][neuron].getDerived());
					}
				}
			}

			//Poprawianie wag
			for (int warstwa = 0, e = vecLayers.size(); warstwa < e; ++warstwa)
			{
				for (int neuron = 0, e = vecLayers[warstwa].size(); neuron < e; ++neuron)
				{
					//vecBiasWeights[warstwa] = vecBiasWeights[warstwa] + n*
					if (warstwa == 0)
					{
						vecLayers[warstwa][neuron].updateWeights(n, data[i]);
					}
					else
					{
						std::vector<double> tmp = { vecLayers[0][0].getActiv(), vecLayers[0][1].getActiv(),1. };
						vecLayers[warstwa][neuron].updateWeights(n, tmp);
					}
				}
			}

			//Policz blad
			E += 0.5 * ((T[i] - end->getActiv()) * (T[i] - end->getActiv()));
		}
	} while (E > Emax);
	printf("%4.8f\n", E);






	printf("Gotowy do klasyfikowania\n");

	std::vector<double> yes = { 1.,-1.,1. };
	Neuron* end = &vecLayers[1][0];
	for (int warstwa = 0, e = vecLayers.size(); warstwa < e; ++warstwa)
	{
		for (int neuron = 0, e = vecLayers[warstwa].size(); neuron < e; ++neuron)
		{
			if (warstwa == 0) vecLayers[warstwa][neuron].use(yes);
			else
			{
				std::vector<double> tmp = { vecLayers[0][0].getActiv(), vecLayers[0][1].getActiv(),1. };
				vecLayers[warstwa][neuron].use(tmp);
			}
		}
	}

	printf("Na wyjsciu jest: %c\n", abs(T[0] - end->getActiv()) < abs(T[1] - end->getActiv()) ? '0' : '1');
	printf("%0.4f\n", end->getActiv());

	std::vector<double> no = { 1.,1.,1. };
	for (int warstwa = 0, e = vecLayers.size(); warstwa < e; ++warstwa)
	{
		for (int neuron = 0, e = vecLayers[warstwa].size(); neuron < e; ++neuron)
		{
			if (warstwa == 0) vecLayers[warstwa][neuron].use(no);
			else
			{
				std::vector<double> tmp = { vecLayers[0][0].getActiv(), vecLayers[0][1].getActiv(),1. };
				vecLayers[warstwa][neuron].use(tmp);
			}
		}
	}
	printf("Na wyjsciu jest: %c\n", abs(T[0] - end->getActiv()) < abs(T[1] - end->getActiv()) ? '0' : '1');

	printf("%0.4f\n", end->getActiv());
	getchar();
	return 0;
}
