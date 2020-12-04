#include "ppm.h"

ppm::ppm(std::string name) 
	: obraz(name)
{
	int R;
	int G;
	int B;
	std::string tmp;

	try
	{
		std::fstream file;
		file.open(name, std::ios::in);


		if (!file.good())
			throw std::runtime_error("Nie mozna otworzyc pliku");


		if(file.peek() == std::ifstream::traits_type::eof())
			throw std::runtime_error("Plik jest pusty");

		open = true;


		file >> tmp;

		if (tmp != "P3")
			throw std::runtime_error("Zly format pliku");


		file >> tmp;


		while (tmp == "#")
		{
			std::getline(file, tmp);
			file >> tmp;
		}


		pixel_X = std::stoi(tmp);

		file >> pixel_Y;

		file >> max_value;

		all_pixels.reserve(pixel_X*pixel_Y);



		while (!file.eof())
		{
			file >> R;
			file >> G;
			file >> B;
			all_pixels.emplace_back(color(R,G,B));
		}

		file.close();

	}
	catch (const std::exception& err)
	{
		std::cerr << err.what();
		
	}



}

ppm::~ppm()
{
}

void ppm::invert()
{
	try {

		if (!open)
			throw std::runtime_error("Nie wczytano pliku");


		std::fstream file;
		file.open("inverted_" + name, std::ios::out);

		if (!file.good())
			throw std::runtime_error("Nie mozna otworzyc pliku");

		file << "P3" << std::endl;
		file << pixel_X << " " << pixel_Y << " " << max_value << std::endl;

		for (int i = 0; i < pixel_Y; i++)
		{

			for (int j = (i + 1) * pixel_X - 1; j > i*pixel_X - 1; j--)
			{

				if (j % pixel_X != 0 && j % 5 == 0)
					file << std::endl;

				file << all_pixels[j].getR() << " " << all_pixels[j].getG() << " " << all_pixels[j].getB() << " ";

			}

			file << '\n' << std::endl;

		}

		file.close();
	}
	catch (std::exception& err)
	{
		std::cerr << err.what();
	}
}

void ppm::to_grey()
{
	try {

		if (!open)
			throw std::runtime_error("Nie wczytano pliku");


		std::fstream file;
		file.open("grey_" + name, std::ios::out);

		if (!file.good())
			throw std::runtime_error("Nie mozna otworzyc pliku");

		file << "P3" << std::endl;
		file << pixel_X << " " << pixel_Y << " " << max_value << std::endl;

		for (int i = 0; i < all_pixels.size(); i++)
		{

			int temp = grey_color(i);

			for (int j = 0; j < 3; j++)
			{
				file << temp << " ";
			}


			if (i % 5 == 0)
				file << std::endl;


			if (i != 0 && i % pixel_X == 0)
				file << '\n' << std::endl;

		}

		file.close();


	}
	catch (std::exception& err)
	{
		std::cerr << err.what();
	}
}

void ppm::reverse()
{
	try {

		if (!open)
			throw std::runtime_error("Nie wczytano pliku");


		std::fstream file;
		file.open("reversed_" + name, std::ios::out);

		if (!file.good())
			throw std::runtime_error("Nie mozna otworzyc pliku");

		file << "P3" << std::endl;
		file << pixel_X << " " << pixel_Y << " " << max_value << std::endl;

		for (int i = all_pixels.size() - 2; i > 0; i--)
		{



			file << all_pixels[i].getR() << " " << all_pixels[i].getG() << " " << all_pixels[i].getB() << " ";



			if (i % 5 == 0)
				file << std::endl;


			if (i != 0 && i % pixel_X == 0)
				file << '\n' << std::endl;

		}

		file.close();


	}
	catch (std::exception& err)
	{
		std::cerr << err.what();
	}
}

void ppm::to_PBM()
{
	try {

		if (!open)
			throw std::runtime_error("Nie wczytano pliku");


		std::fstream file;
		file.open("PBM_" + name.substr(0,name.length()-4) +".PBM", std::ios::out);


		if (!file.good())
			throw std::runtime_error("Nie mozna otworzyc pliku");

		file << "P1" << std::endl;
		file << pixel_X << " " << pixel_Y << std::endl;

		for (int i = 0; i < all_pixels.size(); i++)
		{

			int temp = grey_color(i);

			if (temp > 127)
				file << 0 << " ";
			else
				file << 1 << " ";
			


			if (i % 5 == 0)
				file << std::endl;


			if (i != 0 && i % pixel_X == 0)
				file << '\n' << std::endl;

		}

		file.close();


	}
	catch (std::exception& err)
	{
		std::cerr << err.what();
	}
}

void ppm::to_ASCII()
{
	try {

		if (!open)
			throw std::runtime_error("Nie wczytano pliku");


		std::fstream file;
		file.open("ASCII_" + name.substr(0, name.length() - 4) + ".txt", std::ios::out);

		if (!file.good())
			throw std::runtime_error("Nie mozna otworzyc pliku");

		for (int i = 0; i < all_pixels.size(); i++)
		{


			switch ((grey_color(i) / 17))
			{
			case 1:
			{
				file << "!";
				break;
			}
			case 2:
			{
				file << "@";
				break;
			}
			case 3:
			{
				file << "#";
				break;
			}
			case 4:
			{
				file << "$";
				break;
			}
			case 5:
			{
				file << "%";
				break;
			}
			case 6:
			{
				file << "^";
				break;
			}
			case 7:
			{
				file << "&";
				break;
			}
			case 8:
			{
				file << "*";
				break;
			}
			case 9:
			{
				file << "?";
				break;
			}
			case 10:
			{
				file << "-";
				break;
			}
			case 11:
			{
				file << "=";
				break;
			case 12:
			{
				file << "+";
				break;
			}
			case 13:
			{
				file << "/";
				break;
			}
			case 14:
			{
				file << "~";
				break;
			}
			case 15:
			{
				file << "|";
				break;
			}

			}

			}

			file << " ";


			if (i != 0 && i % pixel_X == 0)
			{
				file << '\n';
			}

		}

		file.close();


	}
	catch (std::exception& err)
	{
		std::cerr << err.what();
	}

}

const int ppm::grey_color(int i) const
{
	return (all_pixels[i].getR() + all_pixels[i].getG() + all_pixels[i].getB()) / 3;
}


