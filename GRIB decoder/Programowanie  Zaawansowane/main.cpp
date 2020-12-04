#include <iostream>
#include "Decoder.h"

int main()
{
	Decoder::load("message_1.grib");
	Decoder::grib();
	


	std::cin.get();
	return 0;
}