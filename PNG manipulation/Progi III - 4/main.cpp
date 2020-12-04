#include <iostream>
#include "ppm.h"



int liczkolory(const obraz& ob);

int main()
{
	obraz* ob;
	ob = new ppm("Lena.ppm");

	int kolor;
	kolor = liczkolory(*ob);
	std::cout << "kolorow: " << kolor;
	delete ob;
	system("pause");
	return 0;


}




int liczkolory(const obraz & ob)
{

	std::unordered_set<int> temp;


	for (const color &i : ob.get_all_pixels())
		temp.insert((i.getR()<<16) + (i.getG()<<8) + (i.getB()));


	return temp.size();
}
