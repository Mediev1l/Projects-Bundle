#include <iostream>
#include <vector>

#define MAX_INT 2147483647

class Node
{
private:
	struct Vertice
	{
		Vertice() : _neighbor(0), _value(-1), _visited(false) {};
		Vertice(bool visit) : _visited(visit) {};
		std::vector<std::pair<int, int>> _neighbor;
		int _value;
		bool _visited;
	};

	std::vector<Vertice> _vertices;

public:
	Node() : _vertices(0) {};
	~Node() {};
	Node(const Node& cpy)
	{
		if (this != &cpy)
			_vertices = cpy._vertices;
	}

	Node& operator=(const Node& nd)
	{
		if (this != &nd)
			_vertices = nd._vertices;

		return *this;
	}

	int getLower(int first, int second)
	{
		return first > second ?  second : first;
	}

	int getHigher(int first, int second)
	{
		return first > second ? first : second;
	}

	void find(int index)
	{

		for (size_t i = 0; i < _vertices.at(index)._neighbor.size(); i++)
		{

			int tempFirst = _vertices.at(index)._neighbor.at(i).first;
			
				//wartosc drogi
				int tempSecond = _vertices.at(index)._neighbor.at(i).second;
				//node poczatkowy
				int tempValueStart = _vertices.at(index)._value;
				//node koncowy
				int tempValueEnd = _vertices.at(tempFirst)._value;

				int calculate = getHigher(getLower(tempValueStart, tempSecond), tempValueEnd);
				if (tempValueEnd < calculate && _vertices.at(tempFirst)._visited == true)
				{
					_vertices.at(tempFirst)._value = calculate;
					find(tempFirst);
				}
				else
					_vertices.at(tempFirst)._value = calculate;
			
		}
		_vertices.at(index)._visited = true;

		for (size_t i = 0; i < _vertices.at(index)._neighbor.size(); i++)
		{
			if (_vertices.at(_vertices.at(index)._neighbor.at(i).first)._visited != true)
				find(_vertices.at(index)._neighbor.at(i).first);
		}
	}

	void reset()
	{
		for (auto &x : _vertices)
		{
			x._visited = false;
			x._value = -1;
		}
	}

	void init()
	{
		int temp;

		int v1 = -1;
		int v2 = -1;
		int value;

		std::cin >> temp;

		_vertices.reserve(temp + 1);
		_vertices.emplace_back(true);
		
		for (int i = 0; i < temp; i++)
			_vertices.emplace_back();

		std::cin >> temp;

		while (temp--)
		{
			std::cin >> v1;
			std::cin >> v2;
			std::cin >> value;

			_vertices.at(v1)._neighbor.push_back(std::make_pair(v2, value));
			_vertices.at(v2)._neighbor.push_back(std::make_pair(v1, value));
		}

		std::cin >> v1;
		std::cin >> v2;

		while (v1 != 0 && v2 != 0)
		{
			std::cin >> value;

			reset();

			_vertices.at(v1)._value = MAX_INT;		
			find(v1);

			int val = _vertices.at(v2)._value - 1;
			int result = value / val;

			std::cout << (value % val == 0 || val + 1 == MAX_INT ? result :	result + 1);

			std::cin >> v1;
			std::cin >> v2;

			if (v1 != 0 && v2 != 0) std::cout << '\n';
		}
	}	
};

int main()
{
	Node nd;
	nd.init();
	return 0;
}