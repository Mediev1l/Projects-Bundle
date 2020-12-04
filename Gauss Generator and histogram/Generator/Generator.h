#pragma once

#include <random>
#include <time.h>


class Generator
{
public:
	Generator();
	~Generator();

	float Rand01();
	float GenExp(int lambda);
	float Gauss();
	
	float Eliminacja(float (*pf)(float), int a, int b, int c);
};

