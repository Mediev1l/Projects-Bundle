/*

 n = 3
 dziecko L = 2n +1 
 dziecko R = 2n +2
 rodzic (int) n-1 / 2

*/

#include <iostream>


class HeapSort
{
protected:

	long* _data;

	long _size;

	long _amount;

public:

	HeapSort() : _data(nullptr), _size(0),_amount(0) {};

	~HeapSort() { clear(); };

	HeapSort(const HeapSort& cpy)
	{
		if (this != &cpy)
		{
			_data = new long[cpy._size];

			for (long i = 0; i < _size; i++)
				_data[i] = cpy._data[i];

			_size = cpy._size;
			_amount = cpy._amount;
		}
	}

	HeapSort& operator = (const HeapSort& h)
	{
		if (this != &h)
		{
			clear();

			_data = new long[h._size];

			for (long i = 0; i < _size; i++)
				_data[i] = h._data[i];

			_size = h._size;
			_amount = h._amount;
		}
		return *this;
	}

	void Init()
	{

		std::cin >> _amount;

		while (_amount--)
		{
			std::cin >> _size;

			if (_size > 0)
			{
				clear();
				_data = new long[_size];

				for (long i = 0; i < _size; i++)
				{
					std::cin >> _data[i];
				}

				heapit();

				print(_size - 1);

			}
				std::cout << '\n';
		}
		
	}

	void heapit()
	{
		int temp = _size - 1;

		while (temp != 0)
		{
			for (int i = temp; i >= 0; i--)
			{
				checkRoot(i, temp);
			}
			temp--;
		}
	}

	void print(int last)
	{
		for (int i = 0; i <= last; i++)
		{
			std::cout << _data[i] << " ";
		}
		std::cout << '\n';
	}

	void checkRoot(int index, int last)
	{
		if(_data[static_cast<unsigned int>((index - 1) /2)] < _data[index])
			std::swap(_data[static_cast<unsigned int>((index - 1) / 2)], _data[index]);

		if (index == 0)
		{
			print(last);
			std::swap(_data[index], _data[last]);
		}

	}

	void clear()
	{
		if (_data != nullptr)
			delete[] _data;
	}

};

int main()
{
	HeapSort HS;
	HS.Init();
	return 0;
}
