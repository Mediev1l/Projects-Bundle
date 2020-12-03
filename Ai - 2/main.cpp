#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <istream>
#include <iterator>
#include <time.h>
#include <random>
#include <math.h>
#include <windows.h>


#define e 2.71828182
float weights[5]{};
COORD c;
float y{};

const float f1(const float value)
{
	if (value >= 0)
	{
		return 1.0f;
	}
	else
	{
		return 0.0f;
	}
}

const float f2(const float value)
{
	return value;
}

const float f3(const float value)
{
	return static_cast<float>(1.0f / (1.0f + static_cast<float>(pow((1.0f / e), value))));
}

const float normalized_point(const float value, const int min, const int max, const int new_min, const int new_max)
{
	return ((value - (min)) / (max - min)) * (new_max - new_min) + (new_min);
}

void initial_weights(float* weights, const size_t size)
{
	//RANDOM GENERATOR
	std::random_device random;  //Will be used to obtain a seed for the random number engine
	std::mt19937 generator(random()); //Standard mersenne_twister_engine seeded with rd()
	std::uniform_real_distribution<float> dis(-5.0f, 5.0f);

	for (size_t i = 0; i < size; ++i)
	{
		weights[i] = dis(generator);
	}
}

void first_without_bias(size_t iterations,const float (*pf)(float), bool condition)
{

	for (size_t i = 0; i < iterations; ++i)
	{
		for (size_t j = 0; j < iterations; ++j)
		{
			float sum{};
			sum += normalized_point(i, 0, iterations, (-5), 5) * weights[0];
			sum += normalized_point(j, 0, iterations, (-5), 5) * weights[1];
			y = pf(sum);
			c.X = i;
			c.Y = j;
			if ((y == 1 && !condition) ||  (y <= 1 && y > 0.5 && condition))
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				std::cout << 'o';
			}

			else
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				std::cout << 'x';
			}
		}
	}

}

void first_with_bias(size_t iterations, const float (*pf)(float), bool condition)
{
	for (size_t i = 0; i < iterations; ++i)
	{
		for (size_t j = 0; j < iterations; ++j)
		{
			float sum{};
			sum += weights[0];
			sum += normalized_point(i, 0, iterations, (-5), 5) * weights[1];
			sum += normalized_point(j, 0, iterations, (-5), 5) * weights[2];

			y = pf(sum);

			c.X = i;
			c.Y = j;
			if ((y == 1 && !condition) || (y <= 1 && y > 0.5 && condition))
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				std::cout << 'o';
			}
			else
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				std::cout << 'x';
			}
		}
	}

}


void second_without_bias(size_t iterations, const float (*pf)(float), bool condition)
{
	for (size_t i = 0; i < iterations; ++i)
	{
		for (size_t j = 0; j < iterations; ++j)
		{
			float sum1{};
			float sum2{};
			float sum3{};

			sum1 += normalized_point(i, 0, iterations, (-5), 5) * weights[0];	//w 1 1 1
			sum2 += normalized_point(i, 0, iterations, (-5), 5) * weights[2];	//w 1 2 1
										   
			sum1 += normalized_point(j, 0, iterations, (-5), 5) * weights[1];	//w 1 1 2
			sum2 += normalized_point(j, 0, iterations, (-5), 5) * weights[3];	//w 1 2 2 

			sum3 += sum1 * weights[0];
			sum3 += sum2 * weights[1];

			y = pf(sum3);
			c.X = i;
			c.Y = j;
			if ((y == 1 && !condition) || (y <= 1 && y > 0.5 && condition))
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				std::cout << 'o';
			}
			else
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				std::cout << 'x';
			}
		}
	}
}

void second_with_bias(size_t iterations, const float (*pf)(float), bool condition)
{
	for (size_t i = 0; i < iterations; ++i)
	{
		for (size_t j = 0; j < iterations; ++j)
		{
			float sum1{};
			float sum2{};
			float sum3{};


			sum1 += normalized_point(i, 0, iterations, (-5), 5) * weights[0];	//w 1 1 1
			sum2 += normalized_point(i, 0, iterations, (-5), 5) * weights[2];	//w 1 2 1
										   
			sum1 += normalized_point(j, 0, iterations, (-5), 5) * weights[1];	//w 1 1 2
			sum2 += normalized_point(j, 0, iterations, (-5), 5) * weights[3];	//w 1 2 2 

			sum1 += 1;
			sum2 += 1;

			sum3 += sum1 * weights[0];
			sum3 += sum2 * weights[1];
			sum3 += 1;

			y = f3(sum3);
			c.X = i;
			c.Y = j;
			if ((y == 1 && !condition) || (y <= 1 && y > 0.5 && condition))
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
				std::cout << 'o';
			}
			else
			{
				SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				std::cout << 'x';
			}
		}
	}
}



int main(int argc, char* argv[])
{

	srand(time(NULL));


	int choice{};

	std::cin >> choice;
	if (choice == 0)	//without bias
	{

		initial_weights(weights, 4);
		choice = {};
		std::cin >> choice;
		switch (choice)
		{
			//first neural
		case 1:
		{
			first_without_bias(100,f1, false);
		}
		break;
		case 2:
		{
			first_without_bias(100, f2, true);
		}
		break;
		case 3:
		{
			first_without_bias(100, f3, true);
		}
		break;
		//second neural
		case 4:
		{
			second_without_bias(100, f1, false);
		}
		break;
		case 5:
		{
			second_without_bias(100, f2, true);
		}
		break;
		case 6:
		{
			second_without_bias(100, f3, true);
		}
		break;

		default:	
			std::cout << "ERROR";
			break;
		}
	}
	else  //with bias
	{

		initial_weights(weights, 5);

		std::cin >> choice;
		switch (choice)
		{
			//first neural
		case 1:
		{
			first_with_bias(100, f1, false);
		}
		break;
		case 2:
		{
			first_with_bias(100, f2, true);
		}
		break;
		case 3:
		{
			first_with_bias(100, f3, true);
		}
		break;
		//second neural
		case 4:
		{
			second_with_bias(100, f1, false);
		}
		break;
		case 5:
		{
			second_with_bias(100, f2, true);
		}
		break;
		case 6:
		{
			second_with_bias(100, f3, true);
		}
		break;

		default:	
			std::cout << "ERROR";
			break;
		}
	}


	system("pause");
	return 0;
}


