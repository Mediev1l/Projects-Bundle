#include "morse.h"
#include <iostream>


int main()
{
	morse m;

	m.setFrequency(1000); 
	m.setPause(50);
	m.setDotTime(100); 
	m.setDashTime(200); 
	m.setCharPause(100);


	m << "Ala ma kota";  

	long i = 0x5A5A5A5A; 
	double d = 1.23456789; 

	m << i << pause << d; 

	return 0;
}