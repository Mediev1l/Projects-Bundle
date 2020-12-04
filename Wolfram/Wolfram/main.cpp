#include <iostream>
#include <vector>
#include <fstream>

/*
<xy> - <x><y> / 6x6y
*/
	const int N = 80;

float countM(std::vector<int>& data)
{
	float temp = 0;

	for (int i = 0; i < data.size(); i++)
		temp += data[i] == 1 ? 1 : -1;

	return temp /float(N);
}

int main()
{
	int counter = 0;
	std::fstream file;
	file.open("wolfram1.txt", std::ios::out);
	std::vector<int> data(N, 0);

	data[N / 2 - 1] = 1;
	int rule = 69;
	int dt = 5;

	struct output
	{
		std::vector<std::pair<double, double>> results;

		output() {}
		output(int x)
		{
			results.resize(x);
		}
	};

	std::vector<output> o(dt - 1);

	float first = (float)rand() / RAND_MAX;
	float second = (float)rand() / RAND_MAX;

	for (int i = 1; i < dt; i++)
	{
		for (int j = 0; j < 100; j++)
		{
			first = (float)rand() / RAND_MAX;
			for (int k = 0; k < i; k++)
			{
				second = (float)rand() / RAND_MAX;
			}
			//file << first << ' ' << second<<'\n';
			o.at(i - 1).results.push_back(std::make_pair(first, second));
		}

		//file << "\n";
		
	}

	file << "DT 1, DT 1\tDT 2, DT 2\tDT 3, DT 3\tDT 4, DT 4\t" << '\n';
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			file << o.at(j).results.at(i).first << ',' << o.at(j).results.at(i).second << '\t';
		}
		file << '\n';

	}




	file.close();

	//file.open("wolfram.txt", std::ios::out);

	float m1 = 0;
	float m2 = 0;


	for(int k = 0; k <100; k++)
	{
		for (int& x : data)
			std::cout << (x == 1 ? '*' : ' ');


		std::vector<int> tmp = data;
		for (int i = 0; i < N; ++i)
		{
			char num = 0;
			int lewy = i - 1 < 0 ? N - 1 : i - 1;
			int prawy = i + 1 >= N ? 0 : i + 1;

			num <<= 1;
			num |= data[lewy];

			num <<= 1;
			num |= data[i];

			num <<= 1;
			num |= data[prawy];

			tmp[i] = ((rule >> num) & 1) == 1 ? 1 : 0;
		}
		data = tmp;

		m1 = countM(data);

		if (counter > 40)
		{
			if (counter % 2 == 0)
			{
				file << m2 << " " << m1 << '\n';
				m2 = m1;
			}
		}
		else
			m2 = m1;


		counter++;



	std::cout << '\n';
	}

	return 0;
}