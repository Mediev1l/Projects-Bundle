#include <iostream>
#include <ctime>
#include <cmath>
#include <math.h>
#include <vector>
#include <string>

using namespace std;


double P[2][7] = { {11111, 10001,  10001, 10001,  11111,  10001, 10001},
					{11111, 10000, 10000, 10000, 10000, 10000, 11111 }
};
double T[2] = { 0.0, 1.0 };



//funkcja aktywacji
double wzor(double x)
{
	return 1. / (1 + exp(-1 * x));
}

void fill(double w[], int size)
{
	for (int i = 0; i < size; i++)
	{
		w[i] = double(rand()) / RAND_MAX;
	}
}

vector<vector<double>> change(double tab[2][7])
{
	vector<vector<double>> temp;

	temp.resize(2);
	
	for (int i = 0; i < 2; ++i)
	{
		//bias
		temp[i].push_back(1.0);

		for (int j = 0; j < 7; ++j)
		{
			string s = to_string(tab[i][j]);
			s.erase(s.find_last_not_of('0'), std::string::npos);
			while (!s.empty())
			{
				double t = s[0] == '1' ? 1.0 : -1.0;
				temp[i].push_back(t);
				s.erase(0, 1);
			}

		}
	}

	return temp;

}


int main() {
	srand(time(NULL));	


	vector<vector<double>> data = change(P);
	double sum = 0;

	//poczatkowe wagi
	double w[36];

	//blad
	double E = 0;

	//maxymalny blad 
	double Emax = 0.00002;

	//wspolczynnik uczenia 
	double n = 0.1;


	//sygnal wyjsciowy
	double y[2];

	double y2;

	int count = 0;


	fill(w, 36);


	do {
		E = 0.0;

		for (int p = 0; p < data.size(); p++) {
			sum = 0.0;
			for (int i = 0; i < data[p].size(); i++) {
				sum += data[p][i] * w[i];
			}

			y[p] = wzor(sum);


			double data1[36] = { 1,1,1,1,1,1,-1 ,1,1,-1 ,1,1,-1 ,1,1,-1 ,1,1,-1 ,1,1,-1 ,1,1,-1 ,1,1,-1 ,1,1,-1 ,1,1,-1 ,1,1 };

			double sum2 = 0.0;

			for (int i = 0; i < 36; i++) {
				sum2 += data1[i] * w[i];
			}




			for (int i = 1; i < data[p].size(); i++) {
				//w[i] = w[i] + n * T[p] * data[p][i];
				w[i] = w[i] + n * (T[p] - y[p]) * (1. - y[p]) * data[p][i] * y[p];
			}
			//eta - n
			//T i t
			y2 = wzor(sum2) ;
			//dactiv y
			E += 0.5 * (T[p] - y[p]) * (T[p] - y[p]);
		}

		//cout << E << endl;

		count++;

	} while (E > Emax /*&& count < 100*/);

	//cout << y[0] << " " << y[1];

	std::cout << "Podano A : " << y[0] << " Wyjscie dla A " << T[0]<<'\n';

	std::cout << "Podano C : " << y[1] << " Wyjscie dla C " << T[1]<<'\n';

	std::cout << y2;

	getchar();
	return 0;
}
