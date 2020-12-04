#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <mutex>


class Balloons
{
private:

	struct Coords
	{
		long _x;
		long _y;

		Coords() : _x(0), _y(0) {};
		Coords(const Coords& cpy) : _x(cpy._x), _y(cpy._y) {};
		Coords(long x, long y) : _x(x), _y(y) {};
	};

	struct Pair
	{
		std::vector<Coords> _small;
		std::vector<Coords> _large;
	};
	

	std::vector<Coords> _small;
	std::vector<Coords> _large;

	Pair _up;
	Pair _down;

	size_t _amount;

	std::mutex _mutex[1];
	std::thread _threads[6];


public:

	Balloons()
		:_small(0), _large(0),  _amount(0)
	{
	}

	~Balloons() {};

	Balloons(const Balloons& cpy) = delete;

	Balloons& operator= (const Balloons& cpy) = delete;

	void addSmall(size_t amount)
	{
		_small.reserve(amount);
		_up._small.reserve(amount);
		_down._small.reserve(amount);

		long x;
		long y;

		for (size_t i = 0; i < amount; i++)
		{
			std::cin >> x;
			std::cin >> y;

			_small.emplace_back( x, y );
		}
			
	}

	void addLarge(size_t amount)
	{
		_large.reserve(amount);
		_up._large.reserve(amount);
		_down._large.reserve(amount);

		long x;
		long y;

		for (size_t i = 0; i < amount; i++)
		{
			std::cin >> x;
			std::cin >> y;

			_large.emplace_back( x, y );
		}
	}

	int isInside(Coords& first, Coords& second, Coords& third, Coords& point, bool up)
	{

		//std::lock_guard<std::mutex> _guard(_mutex[0]);
		int one = getSide(first, third, point);
		int two = getSide(third, second, point);
		int three = getSide(second, first, point);

		if (one == 0 || two == 0 || three == 0)
			return 1;
		else if (up == true && (one + two + three) == -3)
			return 1;
		else if (up == false && (one + two + three == 3))
			return 1;
		else
			return -1;
	}

	int getSide(Coords& first, Coords& second, Coords& point)
	{
		long long temp1 = (point._y - first._y) * (second._x - first._x);
		long long temp2 = (second._y - first._y) * (point._x - first._x);
		long long side = temp1 - temp2;

		if (side > 0)
			return 1;
		if (side < 0)
			return -1;
		else if (point._x >= std::min(first._x, second._x) && point._x <= std::max(first._x, second._x) && point._y >= std::min(first._y, second._y) && point._y <= std::max(first._y, second._y))
			return 0;
		else
			return -4;
	}

	int getDist(Coords& first, Coords& second, Coords& point)
	{
		return abs((point._y - first._y) * (second._x - first._x) -	(second._y - first._y) * (point._x - first._x));
	}

	void Increment()
	{
		std::lock_guard<std::mutex> _guard(_mutex[0]);

		_amount++;
	}

	void SearchSmall(Pair& points, Coords first, Coords second, Coords third /*int& index*/, bool up)
	{
		//std::lock_guard<std::mutex> _guard(_mutex[2]);

		//Coords third = points._large.at(index);
		
		size_t size = points._small.size();

		for (size_t i = 0; i < size;)
		{
			int temp = isInside(first, second, third , points._small.at(i), up);
		
			if (temp == 1 || temp == 0)
			{
				size--;
				points._small.erase(points._small.begin() + i);
				Increment();
			}
			else
				i++;
		}
	}

	void SearchLarge(Pair& points, Coords first, Coords second, Coords third, int index, bool up)
	{
	//	std::lock_guard<std::mutex> _guard(_mutex[3]);
		int tempIndex = index;
		size_t sizeLarge = points._large.size();
		for (size_t i = 0; i < sizeLarge;)
		{
			int temp = isInside(first, second, third, points._large.at(i), up);

			if ((temp == 1 || temp == 0) && i != static_cast<size_t>(tempIndex))
			{
				if (i < static_cast<size_t>(tempIndex))
				{
					sizeLarge--;
					tempIndex--;
					points._large.erase(points._large.begin() + i);
				}
				else
				{
					sizeLarge--;
					points._large.erase(points._large.begin() + i);
				}
			}
			else
				i++;
		}

	
	}



	void QuickHull(Pair& points, Coords& first, Coords& second, int side, bool up)
	{
		int index = -1;
		long distance = 0;

		for (int i = 0; i < static_cast<int>(points._large.size()); i++)
		{
			int temp = getDist(first, second, points._large.at(i));
			if (getSide(first, second, points._large.at(i)) == side && temp > distance)
			{
				index = i;
				distance = temp;
			}
		}


		if (index == -1)
			return;

		Coords temp = points._large.at(index);

		if (up == true)
		{
			//search of small inside -- up
			_threads[2] = std::thread(&Balloons::SearchSmall,this, std::ref(points), first, second, temp, true);
			//search of large inside -- up
			_threads[3] = std::thread(&Balloons::SearchLarge, this, std::ref(points), first, second, temp, index, true);

			if(_threads[2].joinable())
				_threads[2].join();
			if (_threads[3].joinable())
				_threads[3].join();
		
		}
		else
		{
			//search of small inside -- down
			_threads[4] = std::thread(&Balloons::SearchSmall, this, std::ref(points), first, second, temp, false);
			//search of large inside -- down
			_threads[5] = std::thread(&Balloons::SearchLarge, this, std::ref(points), first, second, temp, index, false);

			if (_threads[4].joinable())
				_threads[4].join();
			if (_threads[5].joinable())
				_threads[5].join();
		}

		

		
		if (up == true)
		{
			QuickHull(points, temp, first,  -getSide(temp, first, second), true);
			QuickHull(points, temp, second, -getSide(temp, second, first), true);
		}
		else
		{
			QuickHull(points, temp, first, -getSide(temp, first, second), false);
			QuickHull(points, temp, second, -getSide(temp, second, first), false);
		}

	}

	void findBalloons()
	{
		if (_large.size() < 3)
			return;
	

		size_t min = 0;
		size_t max = 0;

		//Find min and max X
		for (size_t i = 0; i < _large.size(); i++)
		{
			if (_large.at(i)._x < _large.at(min)._x)
				min = i;
			if (_large.at(i)._x > _large.at(max)._x)
				max = i;
		}

		//Large division
		int temp;
		for (size_t i = 0; i < _large.size(); i++)
		{
			temp = getSide(_large.at(min), _large.at(max), _large.at(i));

			if (temp == 1)
				_up._large.emplace_back(_large.at(i));
			else if (temp == 0)
				continue;
			else
				_down._large.emplace_back(_large.at(i));
				
		}

		//Small division
		for (size_t i = 0; i < _small.size(); i++)
		{
			temp = getSide(_large.at(min), _large.at(max), _small.at(i));

			if (temp == 1)
				_up._small.emplace_back(_small.at(i));
			else if (temp == 0)
				Increment();
			else
				_down._small.emplace_back(_small.at(i));

		}

		
		
		//2x quickhull here
		_threads[0] = std::thread(&Balloons::QuickHull, this, std::ref(_up), std::ref(_large.at(min)), std::ref(_large.at(max)), 1, true);
		_threads[1] = std::thread(&Balloons::QuickHull, this, std::ref(_down), std::ref(_large.at(min)), std::ref(_large.at(max)), -1, false);
		if(_threads[0].joinable())
			_threads[0].join();
		if(_threads[1].joinable())
			_threads[1].join();

	}

	size_t getAmount()
	{
		return _amount;
	}



};

int main()
{

	size_t amount = 0;

	Balloons B1;

	std::cin >> amount;

	B1.addLarge(amount);

	std::cin >> amount;

	B1.addSmall(amount);

	B1.findBalloons();

	std::cout << B1.getAmount();

	
	return 0;
}