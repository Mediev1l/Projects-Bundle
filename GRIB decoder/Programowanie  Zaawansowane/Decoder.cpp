#include "Decoder.h"

std::vector<char> Decoder::messaage;
std::ifstream Decoder::file_in;
std::string Decoder::file_path;
std::size_t Decoder::position;


void Decoder::grib()
{
	Decoder::findGrib();
	Decoder::find7777();
	Decoder::Decode(Decoder::position);
	Decoder::codingInfo();

	section1();
	section2();
	section3();
	section4();
}

void Decoder::findGrib()
{
	char temp = 0;
	const char* tempGrib = "GRIB";
	int place = 0;
	file_in.open(Decoder::file_path, std::ios::in | std::ios::binary);

	if (!file_in.good())
		std::cerr << "ERROR\n";
	while (file_in.get(temp))
	{
	
		if (tempGrib[0] == static_cast<char>(temp))
		{
			file_in >> temp;
			if (tempGrib[1] == static_cast<char>(temp))
			{
				file_in >> temp;
				if (tempGrib[2] == static_cast<char>(temp))
				{
					file_in >> temp;
					if (tempGrib[3] == static_cast<char>(temp))
					{
						std::cout << "GRIB on position: " << place << '\n';
						break;
					}
				}

			}
		}
		place++;
	}

	file_in.close();
	Decoder::position = place + 4;
}

void Decoder::find7777()
{
	char temp = 0;
	const char* temp7 = "7777";
	int place = 0;
	file_in.open(Decoder::file_path, std::ios::in | std::ios::binary);

	if (!file_in.good())
		std::cerr << "ERROR\n";
	while (file_in.get(temp))
	{

		if (temp7[0] == static_cast<char>(temp))
		{
			file_in >> temp;
			if (temp7[1] == static_cast<char>(temp))
			{
				file_in >> temp;
				if (temp7[2] == static_cast<char>(temp))
				{
					file_in >> temp;
					if (temp7[3] == static_cast<char>(temp))
					{
						std::cout << "7777 on position: " << place + 23 << '\n';
						break;
					}
				}

			}
		}
		place++;
	}
	file_in.close();
}

size_t Decoder::read1byte(size_t position)
{
	Decoder::position = position + 1;
return (unsigned char)messaage[position];
}

size_t Decoder::read2byte(size_t position)
{
	Decoder::position = position + 2;
	return (unsigned char)messaage[position] << 8 | (unsigned char)messaage[position + 1] << 0;
}


size_t Decoder::read3byte(size_t position)
{
	Decoder::position = position + 3;
	return  (unsigned char)messaage[position] << 16 | (unsigned char)messaage[position + 1] << 8 | (unsigned char)messaage[position + 2];
}

int Decoder::read3byteNeg(size_t position)
{
	char temp = messaage[position];

	if (((messaage[position] >> 7) & 1) == 1)
	{
		temp &= 0b01111111;
		int value = (temp << 16 | messaage[position + 1] << 8 | messaage[position + 2] << 0);
		return -1 * value;
	}

	return (messaage[position] << 16 | messaage[position + 1] << 8 | messaage[position + 2] << 0);
}

void Decoder::findInFile(std::string filename, size_t position)
{
	std::string temp;
	std::string tempPosition = position < 10 ? '0' + std::to_string(position) : std::to_string(position);
	file_in.open(filename);

	if (!file_in.good())
		std::cerr << "ERROR\n";

	while (file_in >> temp)
	{
		if (temp == tempPosition)
		{
			//file_in >> temp;
			std::getline(file_in, temp);
			std::getline(file_in, temp);
			std::cout << temp << '\n';
			file_in.close();
			return;
		}
	}
	file_in.close();
}


void Decoder::codingInfo()
{
	std::cout << "CODING INFO: ";
	for (int i = 19; i < 25; i++)
		std::cout << messaage[i];

	std::cout << '\n';
}

void Decoder::File_Reader()
{
	char temp = 0;
	file_in.open(Decoder::file_path, std::ios::in | std::ios::binary);

	while (file_in.get(temp))
	{
		messaage.push_back(temp);
	}
	file_in.close();
}

void Decoder::print()
{
	for (size_t i = 0; i < messaage.size(); i++)
		std::cout << messaage[i] << std::endl;
}

void Decoder::Decode(size_t index)
{
	Decoder::position = index + 3;
	std::cout << "Message Length: " << ((unsigned char)messaage[44] << 16 | (unsigned char)messaage[45] << 8 | (unsigned char)messaage[46]) << '\n';
}

void Decoder::section1()
{
	std::cout << "\n===SECTION 1===\n";
	std::cout << "SECTION 1 Length: " << Decoder::read3byte(Decoder::position + 1) << '\n';
	std::cout << "SECTION 1 VERSION: " << Decoder::read1byte(Decoder::position) << '\n';
	Decoder::findInFile("table.txt", Decoder::read1byte(Decoder::position));
	Decoder::findInFile("TableA.txt", Decoder::read1byte(Decoder::position));
	std::cout << "IDENTIFICATION: " << (int)Decoder::read1byte(Decoder::position) << '\n';

	char temp = Decoder::read1byte(position);
	std::cout << "GDS & BMS: " << (((temp >> 7) & 1) == 1 ? "INCLUDED" : "OMITTED") << " : " << (((temp >> 6) & 1) == 1 ? "INCLUDED" : "OMITTED") << '\n';

	std::cout << "UNIT PARAMETERS: " << Decoder::read1byte(Decoder::position) << '\n';

	std::cout << "LEVEL OR LAYER TYPE: " << Decoder::read1byte(Decoder::position) << '\n';

	std::cout << "LEVEL OR LAYER PARAMETERS " << Decoder::read2byte(Decoder::position) << '\n';
	
	std::cout << "DATE YY|MM|DD HH:MM : ";
	std::cout << Decoder::read1byte(Decoder::position) << "|";
	std::cout << Decoder::read1byte(Decoder::position) << "|";
	std::cout << Decoder::read1byte(Decoder::position) << " ";
	std::cout << Decoder::read1byte(Decoder::position) << "0:0";
	std::cout << Decoder::read1byte(Decoder::position) << '\n';

	std::cout << "TIME UNIT: " << Decoder::read1byte(Decoder::position) << '\n';

	std::cout << "P1 TIME PERIOD: " << Decoder::read1byte(Decoder::position) << '\n';

	std::cout << "P2 TIME PERIOD: " << Decoder::read1byte(Decoder::position) << '\n';

	std::cout << "TIME RANGE: " << Decoder::read1byte(Decoder::position) << '\n';

	std::cout << "LAST ROW: " << Decoder::read2byte(Decoder::position) << '\n';

	std::cout << "NUMBER MISSING: " << Decoder::read1byte(Decoder::position) << '\n';

	std::cout << "CENTURY REFERENCE: " << Decoder::read1byte(Decoder::position) << '\n';

	std::cout << "SUB CENTER IDENTYFICATION: " << Decoder::read1byte(Decoder::position) << '\n';

	std::cout << "DECIMAL SCALE FACTOR: " << Decoder::read2byte(Decoder::position) << '\n';
}

void Decoder::section2()
{
	std::cout << "\n===SECTION 2===\n";
	std::cout << "SECTION 2 Length: " << Decoder::read3byte(Decoder::position) << '\n';

	std::cout << "NUMBER OF VERTICAL COORDINATES: " << Decoder::read1byte(Decoder::position) << '\n';

	std::cout << "OCTET: " << Decoder::read1byte(Decoder::position) << '\n';

	std::cout << "DATA REPRESENTATION TYPE: " << Decoder::read1byte(Decoder::position) << '\n';

	std::cout << "POINTS ALONG LATITUDE CIRCLE: " << Decoder::read2byte(Decoder::position) << '\n';

	int longtitude = Decoder::read2byte(Decoder::position);
	std::cout << "POINTS ALONF LONGTITUDE: " << longtitude << '\n';

	std::cout << "Longtitude: " << Decoder::read3byte(Decoder::position) / 1000 << '\n';

	std::cout << "Longtitude: " << Decoder::read3byteNeg(Decoder::position) / 1000 << '\n';

	int temp = Decoder::read1byte(Decoder::position);

	std::cout << "POINTS SCAN IN: " << (((temp >> 7) & 1) == 1 ? "-" : "+") << "i and  " << (((temp >> 6) & 1) == 1 ? "-" : "+")
		<< "j DIRECTION - FORTRAN ["<< (((temp >> 5) & 1) == 1 ? "J,I]" : "I,J]") <<'\n';

	Decoder::position += 18;

	for (int i = 0; i < longtitude; i++)
	{
		std::cout << i + 1 << ". PUNKTY: " << Decoder::read2byte(Decoder::position) << '\n';
	}
	std::cout << '\n';


}

void Decoder::section3()
{
}

void Decoder::section4()
{

	std::cout << "\n===SECTION 4===\n";
	std::cout << "SECTION 4 Length: " << Decoder::read3byte(Decoder::position) << '\n';

	std::cout << "FLAG: " << Decoder::read1byte(Decoder::position) << '\n';

	std::cout << "SCALE FACTOR: " << Decoder::read2byte(Decoder::position) << '\n';


}
