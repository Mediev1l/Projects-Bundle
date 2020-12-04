#include "factory.h"

factory::factory()
	:  current(_console), mors()
{
	
}

factory::factory(const factory & fac)
{
	if (this != &fac)
	{
		mors = fac.mors;
		current = fac.current;

	}
}

factory::~factory()
{
	clear();
}

void factory::setExtraInfo(std::string str)
{
	std::stringstream tempSS;
	std::string tempS;
	int check;
	std::vector<int> tempI;

	tempSS << str;

	while (!tempSS.eof())
	{
		tempSS >> tempS;

		if (std::stringstream(tempS) >> check)
			tempI.push_back(check);

	}

	//for (int i = 0; i < tempI.size(); i++)
	//	std::cout << tempI[i] << std::endl;


}

void factory::setOutput(handle hd)
{
	clear();

	switch (current)
	{
		case(0):
		{

			break;
		}
		case(1):
		{
			break;
		}
		case(2):
		{
			break;
		}
		case(3):
		{
			break;
		}
	}


}

void factory::clear()
{
	delete mors;
}
