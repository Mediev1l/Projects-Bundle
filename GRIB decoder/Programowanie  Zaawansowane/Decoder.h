#include <iostream>
#include <fstream>
#include <vector>
#include <string>
static class Decoder
{
public:
	
	static std::ifstream file_in;

	static std::string file_path;

	static std::vector<char> messaage;

	static size_t position;

	Decoder() {};
	Decoder(const std::string & file_path)
	{
		this->file_path = file_path;
	};

	static void load(const std::string& file_path)
	{
		Decoder::file_path = file_path;

		Decoder::File_Reader();
	}
	static void grib();
	static void findGrib();
	static void find7777();
	static size_t read1byte(size_t position);
	static size_t read2byte(size_t position);
	static size_t read3byte(size_t position);
	static int read3byteNeg(size_t position);
	static void findInFile(std::string filename, size_t position);

	static void codingInfo();
	static void File_Reader();
	static void print();
	static void Decode(size_t index);

private:
	static void section1();
	static void section2();
	static void section3();
	static void section4();
};

