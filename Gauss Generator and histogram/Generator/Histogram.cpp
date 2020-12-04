#include "Histogram.h"




Histogram::Histogram(double nxd, double nxg, int nNk)
	: xd(nxd), xg(nxg), Nkl(nNk)
{
	H = new int[Nkl + 2];
	for (int i = 0; i < Nkl; i++)
	{
		H[i] = 0;
	}
	h = (xg - xd) / Nkl;
}

Histogram::~Histogram()
{
}

void Histogram::AddToHist(double x)
{
	int i = floor((x - xd) / h) + 1;
	if (i < 0) i = 0;
	if (i > Nkl + 1) i = Nkl + 1;
	H[i]++;
}

void Histogram::Display()
{
	std::cout << "nr kl:" << "ile" << std::endl;
	for (int i = 0; i <= Nkl; i++)
		printf("%3d %5d \n", i, H[i]);
}

void Histogram::Figure()
{
	for (int i = 0; i <= Nkl; i++)
	{
		for (int j = 0; j < H[i]; j++)
			std::cout << "*";
		std::cout << '\n';
	}
		
}
