#include <iostream>
#include <ctime>
#include <cmath>
#include <math.h>

using namespace std;

double beta = 0.2;
short dimension = 7 * 3;

//wspolczynnik uczenia 
double n = 0.1;

double x[2][13] = { { 1.0,-1.0,-1.0,1.0,-1.0,-1.0,1.0,-1.0,-1.0,1.0,-1.0,-1.0,1.0 },
					{ 1.0,1.0,-1.0,1.0,1.0,1.0,1.0,-1.0,-1.0,1.0,-1.0,-1.0,1.0 } };
double d[2] = { 1.0, -1.0 };

//poczatkowe wagi
double w[13];

//sygnal wyjsciowy
double y[2];

//blad
double E;

//maxymalny blad 
double Emax = 0.00000003;
double sum;

double wzor(double x) {
	return (1.0 - exp(-beta * x)) / (1.0 + exp(-beta * x));
}

void fill()
{
	for (int i = 0; i < 13; i++)
	{
		w[i] = double(rand()) / RAND_MAX;
	}
}

int main() {
	srand(time(NULL));

		fill();


		do {
			E = 0.0;
			for (int p = 0; p < 2; p++) {
				sum = 0.0;
				for (int i = 0; i < 13; i++) {
					sum += x[p][i] * w[i];
				}

				y[p] = wzor(sum);

				for (int i = 0; i < 13; i++) {
					w[i] = w[i] + n * d[p] * x[p][i];
				}

				E += 0.5*(d[p] - y[p])*(d[p] - y[p]);
			}

			cout << E << endl;

		} while (E > Emax);

		cout << y[0] << " " << y[1];

		getchar();
		return 0;
}
