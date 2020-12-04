#include <iostream>

#define MAX 100

void fill(double arr[][MAX], int dim)
{
	for (int i = 0; i < dim; i++)
		for (int j = 0; j < dim; j++)
			arr[i][j] = 0;
}

void print(double arr[][MAX], int dim)
{
	for (int i = 0; i < dim; i++) 
	{
		for (int j = 0; j < dim; j++)
		{
			std::cout << arr[i][j] << "\t";
		}
		std::cout << '\n';
	}
	std::cout << '\n';
		
}	

void print(double arr[], int dim)
{
	for (int i = 0; i < dim; i++)
		std::cout << arr[i] << "\t";
	std::cout << '\n';
}

void LU(double src[][MAX], double lower[][MAX], double upper[][MAX], int dim)
{
	for (int i = 0; i < dim; i++) {

		// macierz gorna 
		for (int k = i; k < dim; k++) {

			// suma  Lower(i, j) * Upper(j, k) 
			double sum = 0;
			for (int j = 0; j < i; j++)
				sum += (lower[i][j] * upper[j][k]);

			// obliczanie upper(i, k) 
			upper[i][k] = src[i][k] - sum;
		}

		// macierz dolna 
		for (int k = i; k < dim; k++) 
		{
			if (i == k)
				//tworzenie macierzy jednostkowej
				lower[i][i] = 1; 
			else {

				// Suma Lower(k, j) * Upper(j, i) 
				double sum = 0;
				for (int j = 0; j < i; j++)
					sum += (lower[k][j] * upper[j][i]);

				// Obliczanie Lower(k, i) 
				lower[k][i] = (src[k][i] - sum) / upper[i][i];
			}
		}
	}
}

void solve(double src[][MAX], double values[], double output[], int dim)
{
	    for (int i=dim - 1; i>=0; i--) 
		{
			output[i] = values[i]/src[i][i];

			for (int k=i-1;k>=0; k--) 			
			    values[k] -= src[k][i] * output[i];
		}
}

int main()
{

	double matrix[][MAX] = { { 1, 3, 3 },
						  { 5, 3, 1 },
						  { 2, 3, 1 } };
	double lower[3][MAX];
	double upper[3][MAX];
	double in[3] = { 2, 3, -1 };
	double out[3] = { 0,0,0 };

	fill(lower, 3);
	fill(upper, 3);

	LU(matrix, lower, upper, 3);

	print(lower, 3);
	print(upper, 3);

	solve(upper, in, out, 3);
	print(out, 3);


	std::cin.get();
	return 0;
}