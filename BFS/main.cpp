#include <vector>
#include <random>
#include <time.h>
#include <iostream>
#include <map>
#include <fstream>
#include <algorithm>

struct Graph
{
	int index;

	std::vector<int> n;

	bool visited = false;


	void add(int i)
	{
		n.push_back(i);
	}

	int get_index() { return index; };
};

void bfs(std::vector<Graph>& people,int index, std::vector<int>& length)
{
	people.at(index).visited = true;

	for (int i = 0; i<people.at(index).n.size(); i++)
	{
		if (i && people.at(i).visited == false)
		{
			length[index]++;
			bfs(people, i, length);

		}
	}
}

int srednica(std::vector<int>& vec)
{
	int temp{};

	for (auto& x : vec)
		temp = x > temp ? x : temp;

	return temp;
}

int promien(std::vector<int>& vec)
{
	return *std::min_element(vec.begin(), std::max_element(vec.begin(), vec.end()));
}

void histogram(std::vector <Graph> data, std::fstream& file)
{
	std::map<int, int> hist;



	for (int i = 0; i < data.size(); i++)
	{
		hist[data[i].n.size()] ++;
	}

	for (auto& h : hist)
	{
		std::cout << h.first << "\t";
		file << h.first << ',' << h.second << '\n';
		for (int i = 0; i < h.second; i++)
			std::cout << "*";
		std::cout << '\n';
	}
}

void metoda(std::string metoda, int rozmiar, double p = 0)
{
	int N = rozmiar;
	double P = p;
	std::vector<Graph> G;
	std::vector<int> length;

	if (metoda == "losowy")
	{
		G.resize(N);



		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				double R_p = (double)rand() / RAND_MAX;
				if (R_p <= P && j != i)
				{
					G.at(i).add(j);
					G.at(j).add(i);
				}
			}

		}

		double temp = 0;

		for (auto& g : G)
		{
			temp += g.n.size();
		}

		std::cout << temp / G.size();
	}
	else if (metoda == "BA")
	{
		std::vector<Graph> G(2);
		length.resize(N);
		int kc = 0;
		int index = 0;
		G[0].add(1);
		G[1].add(0);

		while (G.size() < N)
		{

			kc = 0;
			for (int i=0; i<G.size(); i++)
				kc += G.at(i).n.size();

			kc /= 2.;
			G.emplace_back();

			for (int i = 0; i < G.size() - 2; i++)
			{
				index = G.size() - 1;
				double p = G[i].n.size() / (double)kc;
				double R_p = (double)rand() / RAND_MAX;

				if (R_p <= p)
				{
					G[i].add(index);
					G[index].add(i);
				}
			}

			if (G[G.size() - 1].n.size() == 0)
				G[G.size() - 1].add(0);
		}

		double temp = 0;

		for (auto& g : G)
		{
			temp += g.n.size();
		}

		for (auto& person : G)
		{
			kc += person.n.size();
		}
		kc /= 2;

		std::cout << "AVG: "<< (double)temp / G.size() << '\n';
		std::cout << "CC: " << ((double)kc / (N * (N - 1) / (2.))) * 100.<< '\n';

		//bfs(G, 0, length);
		///std::cout << "Srednica: " << srednica(length) << '\n';
		//std::cout << "Promien: " << promien(length) << '\n';
	}


}


int main()
{
	srand(time(NULL));

	std::fstream file("hist.csv", std::ios::app);

	metoda("BA", 1000);
	//metoda("losowy", 1000, 0.3);


	std::cin.get();
	return 0;
}