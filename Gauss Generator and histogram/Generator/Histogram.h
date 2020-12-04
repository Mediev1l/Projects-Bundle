#pragma once
#include  <cmath>
#include <iostream>
class Histogram
{
private:
	double xd, xg, h;
	int Nkl;
	int* H;
public:
	Histogram(double nxd, double nxg, int nNk);
	~Histogram();

	void AddToHist(double x);
	void Display();
	void Figure();
};

