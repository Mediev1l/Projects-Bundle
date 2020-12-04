#include <iostream>
#include <fstream>
#include <string>

class Decoder
{
private:
	int shift;

	std::fstream file;

	std::string in;
	std::string outCoded;
	std::string outDeCoded;

public:

	void setShift(int shift) { this->shift = shift; };

	void loadClear(std::string fileName)
	{
		char temp;
		in.clear();

		file.open(fileName, std::ios::in);
		

		while (file.get(temp))
			in += temp;

		file.close();



	}

	void loadCoded(std::string fileName)
	{
		char temp;
		outCoded.clear();

		file.open(fileName, std::ios::in);


		while (file.get(temp))
			outCoded += temp;

		file.close();



	}

	void save(std::string fileName)
	{
		file.open(fileName + "Coded.txt", std::ios::out);
		file << outCoded;

		file.close();

		file.open(fileName + "DeCoded.txt", std::ios::out);
		file << outDeCoded;

		file.close();

	}

	void code()
	{
		outCoded.clear();
		for (auto a : in)
			outCoded += __code(a);
	}

	void decode()
	{
		outDeCoded.clear();
		for (auto a : outCoded)
			outDeCoded += __decode(a);
	}

private:
	char __code(char c)
	{
		int temp = 0;

		if (c >= 48 && c <= 57)
		{
			temp = c;

			temp += shift % 36;

			if (temp > 57)
				temp += 7;

			if (temp > 90)
				temp -= 43;

			return static_cast<char>(temp);
		}
		else if (c >= 65 && c <= 90)
		{
			temp = c;

			temp += shift % 36;

			if (temp > 90)
				temp -= 43;

			if ((temp > 57 && temp < 65))
				temp += 7;

			if (temp < 65)
				temp -= 7;

			return static_cast<char>(temp);

		}
		else if (c >= 97 && c <= 122)
		{
			temp = c - 32;

			temp += shift % 36;

			if (temp > 90)
				temp -= 43;

			if ((temp > 57 && temp < 65) )
				temp += 7;

			if (temp < 65)
				temp -= 7;

			return static_cast<char>(temp);
		}

		return c;
	}

	char __decode(char c)
	{
		int temp = 0;

		if (c >= 48 && c <= 57)
		{
			temp = c;

			temp -= shift % 36;

			if (temp < 48)
				temp += 43;

			if (shift > 25)
				temp -= 7;

			if (temp > 57 && temp < 65)
				temp += 7;


			return static_cast<char>(temp);
		}
		else if (c >= 65 && c <= 90)
		{
			temp = c;

			temp -= shift % 36;

			if (temp < 65 )
				temp -= 7;

			if (temp < 48)
				temp += 43;

			return static_cast<char>(temp);

		}
		else if (c >= 97 && c <= 122)
		{
			temp = c - 32;

			temp -= shift % 36;

			if (temp < 65 )
				temp -= 7;

			if (temp < 48)
				temp += 43;

			return static_cast<char>(temp);
		}

		return c;
	}
};

int main()
{
	Decoder d;
	d.setShift(5);
	d.loadClear("Example.txt");
	//d.loadCoded("outCoded.txt");
	d.code();
	d.decode();
	d.save("out");
	return 0;
}