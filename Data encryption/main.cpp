#include <string>
#include <vector>
#include <time.h>
#include <map>
#include <iostream>

struct results
{
	std::string a;
	std::string b;
	unsigned long c;
};

int main()
{
	const std::string alphabet = "abcdefghijklmnoprstuwxyzABCDEFGHIJKLMNOPRSTUWXYZ";

	std::vector<results> adler_8_result;
	std::vector<results>adler_100_result;

	std::vector<results>djb_8_result;
	std::vector<results>djb_100_result;

	srand(time(NULL));



	auto DJB = [&](std::string text) -> unsigned long
	{
		unsigned long hash = 5381;

		for (auto& letter : text)
			hash = (hash << 5) + hash + letter;

		return hash;
	};

	auto adler32 = [&](std::string text) -> unsigned long
	{
		unsigned long A = 1;
		unsigned long B = 0;
		unsigned long P = 65521;

		for (auto& letter : text)
		{
			A = (A + letter) % P;
			B = (B + A) % P;
		}

		return (B << 16) + A;
	};


	auto generator = [&](size_t length, size_t amount, const std::string alphabet) -> std::vector<std::string>
	{
		std::vector <std::string> output;

		output.reserve(amount);

		for (int i = 0; i < amount; i++)
		{
			std::string tempS = "";

			for (int j = 0; j < length; j++)
				tempS += alphabet[rand() % alphabet.size()];

			output.push_back(tempS);
		}
		return output;
	};

	std::vector<std::string> adler_8 = generator(8, 100000, alphabet);
	std::vector<std::string> adler_100 = generator(100, 100000, alphabet);
	
	std::vector<std::string> djb_8 = generator(8, 100000, alphabet);
	std::vector<std::string> djb_100 = generator(100, 100000, alphabet);


	std::map<unsigned long, std::vector < std::string>> adler_8_value;
	std::map<unsigned long, std::vector < std::string>> adler_100_value;

	std::map<unsigned long, std::vector < std::string>> djb_8_value;
	std::map<unsigned long, std::vector < std::string>> djb_100_value;

	for (auto& x : adler_8)
		adler_8_value[adler32(x)].push_back(x);

	for (auto& x : adler_8_value)
		if (x.second.size() > 1)
			adler_8_result.push_back({x.second[0],x.second[1], x.first});
		
	for (auto& x : adler_100)
		adler_100_value[adler32(x)].push_back(x);

	for (auto& x : adler_100_value)
		if (x.second.size() > 1)
			adler_100_result.push_back({ x.second[0],x.second[1], x.first });

	for (auto& x : djb_8)
		djb_8_value[DJB(x)].push_back(x);

	for (auto& x : djb_8_value)
		if (x.second.size() > 1)
			djb_8_result.push_back({ x.second[0],x.second[1], x.first });

	for (auto& x : djb_100)
		djb_100_value[DJB(x)].push_back(x);

	for (auto& x : djb_100_value)
		if (x.second.size() > 1)
			djb_100_result.push_back({ x.second[0],x.second[1], x.first });


	std::cout << "ADLER 32, D=8, N=100 000" << '\n' << adler_8_result.size() << " kolozji" << '\n';
	if (adler_8_result.size() > 0) std::cout << adler_8_result[0].a << " " << adler_8_result[0].b << " " << adler_8_result[0].c << '\n';

	std::cout << "ADLER 32, D=100, N=100 000" << '\n' << adler_100_result.size() << " kolozji" << '\n';
	if (adler_100_result.size() > 0) std::cout << adler_100_result[0].a << " " << adler_100_result[0].b << " " << adler_100_result[0].c << '\n';

	std::cout << "DJB, D=8, N=100 000" << '\n' << djb_8_result.size() << " kolozji" << '\n';
	if (djb_8_result.size() > 0) std::cout << djb_8_result[0].a << " " << djb_8_result[0].b << " " << djb_8_result[0].c << '\n';

	std::cout << "DJB, D=100, N=100 000" << '\n' << djb_100_result.size() << " kolozji" << '\n';
	if (djb_100_result.size() > 0) std::cout << djb_100_result[0].a << " " << djb_100_result[0].b << " " << djb_100_result[0].c << '\n';

	return 0;
}