#include <iostream>
#include <fstream>
#include <vector>
#include <string>

/*


LL max prime = 35888607147294831;
Unsigned LL max prime = 72057594037927931

*/

const long long prime = 35888607147294831;
const int base = 257;

bool Brute(std::vector<wchar_t> lhs, std::vector<wchar_t> rhs)
{
	for (size_t i = 0; i < lhs.size(); i++)
	{
		if (lhs.at(i) != rhs.at(i))
			return false;
	}

	return true;
}

long long Hash(std::vector<wchar_t> pattern)
{
	long long value = 0;
	
	for (size_t i = 0; i < pattern.size(); i++)
		value = (value * base +  pattern[i]) % prime;

	return value;
}

void KarpRabin()
{
	int counter = 0;

	std::wifstream file;
	std::string filename;
	std::wstring pattern;
	std::vector<size_t> position;

	
	std::vector<wchar_t> text;
	std::vector<wchar_t> vecpattern;
	long long hashedPattern;
	long long hashedText;
	wchar_t temp;


	std::cin >> counter;
	while (counter--)
	{
		std::cin >> filename;

		std::getline(std::wcin, pattern);
		std::getline(std::wcin, pattern);

		for (size_t i = 0; i < pattern.size(); i++)
			vecpattern.push_back(pattern.at(i));

		file.open(filename);

		size_t charCounter = 0;
		

		// ladowanie wektora 
		while (text.size() != pattern.size() && !file.eof())
		{
			
			temp = (wchar_t)file.get();

			text.push_back(temp);
			
		}

		hashedPattern = Hash(vecpattern);
		hashedText = Hash(text);

		if (hashedPattern == hashedText && Brute(text,vecpattern))
			position.push_back(charCounter);

		long long baseval = 1;
		for (size_t i = 0; i < vecpattern.size(); i++)
			baseval = (baseval * base) % prime;

		while (!file.eof())
		{
				temp = (wchar_t)file.get();
				charCounter++;

				hashedText = (hashedText * base + temp) % prime;

				text.push_back(temp);

				hashedText -= (baseval * text.at(0)) % prime;

				text.erase(text.begin());

				if (hashedText < 0) 
					hashedText += prime;

				if (hashedPattern == hashedText && Brute(text, vecpattern))
					position.push_back(charCounter);
		}

		for (size_t i = 0; i < position.size(); i++)
		{
			std::cout << position.at(i) << ' ';
		}

		if(counter > 0)
			std::cout << std::endl;

		text.clear();
		pattern.clear();
		vecpattern.clear();
		position.clear();

		file.close();

	}
}


int main()
{
	KarpRabin();
	return 0;
}