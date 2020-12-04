#define _USE_MATH_DEFINES
#include <math.h>
#include <fstream>
#include <iostream>
#include <vector>
#include <complex>

#define  M_E    2.71828182845904523536
#define  M_PI   3.14159265358979323846

struct Complex
{
	float Im;
	float Re;

	Complex() : Im(0), Re(0) {}
	Complex(const float Im, const float Re) : Im(Im), Re(Re) {}

	void Set_Im(const float Im) { this->Im = Im; }
	void Set_Re(const float Re) { this->Re = Re; }

	float Get_Im() const { return Im; }
	float Get_Re() const { return Re; }
};

void load(std::vector<Complex>& container)
{
	std::fstream file;
	file.open("in.txt", std::ios::in);

	int counter = 0;
	float t2 = 0;
	float t1 = 0;

	file >> counter;

	container.resize(counter);

	for (int i = 0; i < counter; i++)
	{
		file >> t2 >> t1;
		container.at(i).Set_Re(t2);
		container.at(i).Set_Im(t1);
		t2 = 0;
		t1 = 0;
	}

	file.close();


}


void Fast_Furier_Transform(std::vector<std::complex<double>>& data, bool invert)
{
	int size;
	double angle;
	std::vector<std::complex<double>> first;
	std::vector<std::complex<double>> second;
	std::complex<double> temp;

	angle = 0;
	size = data.size();
	first.resize(size / 2);
	second.resize(size / 2);
	temp.real(1);


	if (invert)
	{
		angle = 2 * M_PI / -size;
	}
	else
	{
		angle = 2 * M_PI / size;
	}

	std::complex<double> temp2(cos(angle), sin(angle));


	if (size != 1)
	{

		for (int i = 0; 2 * i < size; i++)
		{
			first[i] = data[2 * i];
			second[i] = data[2 * i + 1];
		}

		Fast_Furier_Transform(first, invert);
		Fast_Furier_Transform(second, invert);


		for (int i = 0; 2 * i < size; i++)
		{
			data[i] = first[i] + temp * second[i];
			data[i + size / 2] = first[i] - temp * second[i];

			if (invert)
			{
				data[i] /= 2;
				data[i + size / 2] /= 2;
			}
			temp *= temp2;
		}
	}
	else
	{
		return;
	}


}





int main(int argc, char* argv[])
{

	std::vector<Complex> numbers;
	std::vector<Complex> numbersOUT;

	//=====================================================
	//Furier transform
	//=====================================================

	/*std::fstream file;

	file.open("out.txt", std::ios::out);

	load(numbers);

	size_t size = numbers.size();

	std::cout << "Index" << '\t' << "A" << '\t' << "B" << '\n';

	for (size_t i = 0; i < size; ++i)
	{

		float t1 = 0;
		float t2 = 0;

		for (size_t j = 0; j < size; ++j)
		{
			t1 += numbers[j].Get_Re() * cos((2 * M_PI * i * j) / size);
			t2 += numbers[j].Get_Re() * sin((2 * M_PI * i * j) / size);
		}

		if (t1 < 0.01f && t1 > -0.01f)
		{
			t1 = 0.0f;
		}
		if (t2 < 0.01f && t2 > -0.01f)
		{
			t2 = 0.0f;
		}

		 std::cout << i << '\t' << t1 << '\t' << t2 << '\n';

		 numbersOUT.emplace_back(t1, t2);

		 file << t1 << '\t' << t2 << '\n';
	}
	file << '\n';
	*/

	//=====================================================
	//Fast Furier Transform
	//=====================================================


	size_t size;
	double t1;
	double t2;
	std::vector<std::complex<double>> data;

	std::cin >> size;

	data.resize(size);


	for (size_t i = 0; i < size; i++)
	{
		std::cin >> t1 >> t2;;
		data[i].real(t1);
		data[i].imag(t2);
	}
	

	Fast_Furier_Transform(data, false);

	for (size_t i = 0; i < size; i++)
	{
		t1 = data.at(i).real();
		t2 = data.at(i).imag();

		if (t1 < 0.0001)
		{
			t1 = 0.0;
		}
		if (t2 < 0.0001)
		{
			t2 = 0.0;
		}

		std::cout  << t1 << '\t' << t2 << '\n';

	}

	std::cout << "\n\n";

	Fast_Furier_Transform(data, true);

	for (size_t i = 0; i < size; i++)
	{
		t1 = data.at(i).real();
		t2 = data.at(i).imag();

		if (abs(t1) < 0.0001)
		{
			t1 = 0.0;
		}
		if (abs(t2) < 0.0001)
		{
			t2 = 0.0;
		}

		std::cout << t1 << '\t' << t2 << '\n';
	}

	system("pause");
	return 0;
}



