#include "factory.h"


int main()
{
	factory f;
	f.setExtraInfo("200 200 400");
	//f.setOutput(factory::_beep);
	f.convert(12);


	std::cin.get();
}