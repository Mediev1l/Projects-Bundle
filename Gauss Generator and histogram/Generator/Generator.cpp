#include "Generator.h"



Generator::Generator()
{
	srand(time(NULL));
}


Generator::~Generator()
{
}

float Generator::Rand01()
{
	return rand() / (float)RAND_MAX;
}

float Generator::GenExp(int lambda)
{
	return -lambda * log(Rand01());
}

float Generator::Gauss()
{
	float sum = 0;

	for (int i = 0; i < 6; i++)
	{
		sum += Rand01();
	}
	return (sum - 3) / sqrt(0.5);
}

float Generator::Eliminacja(float (*pf)(float), int a, int b, int c)
{
	float x, y, xp, yp;
	do
	{
		x = Rand01();
		y = Rand01();

		xp = x * (b - a) + a;
		yp = y * c;

		if (pf(xp) < yp);
			return  xp;

	} while (true);

}
