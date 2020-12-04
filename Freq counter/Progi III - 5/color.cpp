#include "color.h"


color::color()
	:R(0),
	G(0),
	B(0)
{
}

color::color(int r, int g, int b)
	:R(r), G(g), B(b)
{
}

color::color(const color & cl)
{
	*this = cl;
}

void color::setR(int r)
{
	this->R = r;
}

void color::setG(int g)
{
	this->G = g;
}

void color::setB(int b)
{
	this->B = b;
}

const int color::getR() const
{
	return R;
}

const int color::getG() const
{
	return G;
}

const int color::getB() const
{
	return B;
}

color & color::operator=(const color & cl)
{

	this->R = cl.R;
	this->G = cl.G;
	this->B = cl.B;

	return *this;
}



bool operator == (const color& cl, const color& cr)
{
	int temp1 = (cl.getR() << 16 + cl.getG() << 8 + cl.getB());
	int temp2 = (cr.getR() << 16 + cr.getG() << 8 + cr.getB());

	if (temp1 == temp2)
		return true;
	else
		return false;
}

bool operator < (const color& cl, const color& cr)
{
	int temp1 = cl.getR() << 16 + cl.getG() << 8 + cl.getB();
	int temp2 = cr.getR() << 16 + cr.getG() << 8 + cr.getB();

	if (temp1 < temp2)
		return true;
	else
		return false;
}

bool operator > (const color& cl, const color& cr)
{
	int temp1 = cl.getR() << 16 + cl.getG() << 8 + cl.getB();
	int temp2 = cr.getR() << 16 + cr.getG() << 8 + cr.getB();

	if (temp1 > temp2)
		return true;
	else
		return false;
}



std::ostream& operator << (std::ostream& out, const color& cl)
{
	return out << cl.getR() << " " << cl.getG() << " " << cl.getB();
}

//std::ofstream & operator>>(std::ofstream & in, const color & cl)
//{
//	return in << cl.getR() << " " << cl.getG() << " " << cl.getB();
//}


