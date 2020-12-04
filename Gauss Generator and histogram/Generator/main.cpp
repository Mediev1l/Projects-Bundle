#include "Generator.h"
#include <iostream>

float pow(float x)
{
	return x * x;
}


int main()
{
	Generator gen;

	std::cout << "RAND \n";
	for (int i = 0; i < 10; i++)
		std::cout << gen.Rand01()<<" ";

	std::cout << std::endl;
	std::cout << "GAUSS \n";
	for (int i = 0; i < 10; i++)
		std::cout << gen.Gauss() << " ";

	std::cout << std::endl;
	std::cout << "EXP \n";
	for (int i = 0; i < 10; i++)
		std::cout << gen.GenExp(1.0f) << " ";

	std::cout << std::endl;
	std::cout << "GAUSS \n";
	for (int i = 0; i < 10; i++)
		std::cout << gen.Eliminacja(pow, 1, 5, 20) << " ";

	std::cin.get();
	return 0;
}