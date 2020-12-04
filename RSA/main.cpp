#include <iostream>
#include <vector>

int invmod(int n, int a)
{
	std::vector<int> s{ 0,1 }, x{ 1 }, t{ 0,1 }, r{ n,a }, q(2);
	int i = 1;

	do {
		int tempQ{};
		int tempR{};
		int tempS{};

		tempQ = r[i - 1] / r[i];
		q.push_back(tempQ);

		tempR = r[i - 1] - (q[i + 1] * r[i]);
		r.push_back(tempR);

		if (r[i + 1] == 0) 	break;

		tempS = s[i - 1] - (q[i + 1] * s[i]);
		s.push_back(tempS);
	} while (r[i++] != 0);

	if (r[i] == 1 && s[i] > 0) 	return s[i];
	else if (r[i] == 1 && s[i] < 0) return s[i] + n;
	else if (r[i] == 0 && r[i - 1] != 1) return -1;

	return -1;
}

void code(std::string text, std::vector<std::vector<int>>& blocks, std::vector<int>& count)
{
	int counter = 0;

	for (int i = 0; i < blocks.size(); i++)
	{
		blocks[i].resize(3);
		for (int j = 0; j < 3; ++j)
		{
			if (counter < text.size())
			{
				blocks[i][j] = static_cast<int>(text[counter]);
				++counter;
			}
			else
				blocks[i][j] = 0;
		}
		count[i] = (blocks[i][0] << 16) + (blocks[i][1] << 8) + (blocks[i][2]);
	}
}

void decode(std::vector<int> coded, std::string& out)
{
	for (int i = 0; i < coded.size(); i++)
	{
		out += (char)(coded[i] / 65536) % 256;
		out += (char)(coded[i] / 256) % 256;
		out += (char)(coded[i]) % 256;
	}
}

int main()
{
	auto prime = [&](int num) -> bool
	{
		if (num < 2) return false;

		for (int i = 2; i * i <= num; i++)
			if (num % i == 0) return false;

		return true;
	};

	auto nwd = [&](int a, int b) -> int
	{
		int temp = 0;
		while (b != 0)
		{
			temp = b;
			b = a % b;
			a = temp;
		}
		return a;
	};


	int p, q, n, fi, e, d;
	std::string text{ "Bartosz_Skorka" };
	std::string decoded{};
	std::vector<std::vector<int>> blocks;
	std::vector<int> cipher;

	do {
		std::cout << "p:";
		std::cin >> p;
		std::cout << '\n';
	} while (!prime(p));

	do {
		std::cout << "q:";
		std::cin >> q;
		std::cout << '\n';
	} while(!prime(q));


	n = p * q;
	fi = (p - 1) * (q - 1);
	d = -1;
	
	std::cout << "e:";
	std::cin >> e;

	while (d == -1)
	{
		d = invmod(e, fi);

		if (e < fi) e++;
		else break;
	}
	std::cout << "=========================" << '\n';

	std::cout << "text: " << text << '\n';
	std::cout << "p: " << p << '\n';
	std::cout << "q: " << q << '\n';
	std::cout << "n: " << n << '\n';
	std::cout << "fi(n): " << fi << '\n';
	std::cout << "e: " << e << '\n';
	std::cout << "d: " << d << '\n';

	std::cout << "=========================" << "\n\n";


	blocks.resize(ceil((text.size() / 3.0)));
	cipher.resize(ceil((text.size() / 3.0)));

	code(text, blocks, cipher);


	std::cout << "==========bloki=========="<< '\n';
	for (int i = 0; i < blocks.size(); i++)
	{
		for (int j = 0; j < 3; ++j)
			std::cout << blocks[i][j] << ' ';
		std::cout << '\n';
	}
	std::cout << "=========================" << "\n\n";

	std::cout << "==========szyfr==========" << '\n';
	for (int i = 0; i < blocks.size(); i++)
	{
		std::cout << cipher[i];
		
		if (i % 2 == 0 && i != 0 && i != blocks.size() - 1)
			std::cout << '\n';
		else
			std::cout << ' ';
	}

	std::cout<< '\n' << "=========================" << "\n\n";

	std::cout << "=======odszyfrowany======" << '\n';
	decode(cipher, decoded);
	std::cout << decoded << '\n';
	std::cout << "=========================" << "\n\n";
	
	std::cin.get();
	return 0;
}