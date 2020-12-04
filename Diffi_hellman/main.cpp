#include <iostream>
#include <bitset>

int powmod(int a, int b, int mod)
{
	int value = 1;
	int modValue = a% mod;

	std::bitset<sizeof(a) * 8> bits(b);

	for (int i = 0; i < bits.size(); ++i)
	{
		if (bits[i] == 1)
		{
			value *= modValue;
			value %= mod;
		}
		modValue = (modValue * modValue) % mod;
	}
	return value;
}

int main(int argc, char* argv[])
{
	auto prime = [&](int num) -> bool
	{
		if (num < 2) return false;

		for (int i = 2; i * i <= num; i++)
			if (num % i == 0) return false;

		return true;
	};

	int p, g, a, A, B, k;

	std::cout << "p=";
	std::cin >> p;
	if (prime(p))
	{
		std::cout << "g=";
		std::cin >> g;
		std::cout << "a=";
		std::cin >> a;

		A = powmod(g, a, p);
		std::cout << "A=" << A << '\n';

		std::cout << "B=";
		std::cin >> B;

		k = powmod(B, a, p);
		std::cout << "k=" << k << '\n';
	}

	std::cin.get();
	return 0;
}
