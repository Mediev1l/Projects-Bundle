#include "obraz.h"

obraz::obraz(std::string name)
	:name(name),
	open(false),
	pixel_X(0),
	pixel_Y(0),
	max_value(0),
	all_pixels(0)
{
}


obraz::~obraz()
{
}

const std::string obraz::get_name() const
{
	return name;
}

const bool obraz::get_open() const
{
	return open;
}

const int obraz::get_pixel_X() const
{
	return pixel_X;
}

const int obraz::get_pixel_Y() const
{
	return pixel_Y;
}

const int obraz::get_max_value() const
{
	return max_value;
}

const int obraz::get_size() const
{
	return all_pixels.size();
}

const std::vector<color> obraz::get_all_pixels() const
{
	return all_pixels;
}

const color obraz::get_one_pixel(int i) const
{
	return all_pixels[i];
}

obraz & obraz::operator=(const obraz & rhs)
{
	this->name = rhs.name;
	this->open = rhs.open;
	this->pixel_X = rhs.pixel_X;
	this->pixel_Y = rhs.pixel_Y;
	this->max_value = rhs.max_value;
	this->all_pixels = rhs.all_pixels;

	return *this;
}
