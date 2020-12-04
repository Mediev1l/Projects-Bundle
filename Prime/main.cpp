#include <vector>
#include <iostream>

//17 000 000 - 18 000 000

int main()
{
	auto prime = [&](int num) -> bool
	{
		if (num < 2) return false; 

		for (int i = 2; i * i <= num; i++)
			if (num % i == 0) return false; 

		return true;
	};

	std::vector<int> prime_count;

	for (int i = 1000000; i <= 2000000; i++)
		if (prime(i)) prime_count.push_back(i);

	std::cout << prime_count.size();

	return 0;
}