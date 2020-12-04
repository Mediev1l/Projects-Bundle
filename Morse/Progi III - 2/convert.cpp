#include "convert.h"
#include "cstring"

convert::convert()
	:Letter(0), Size(20), Size2d(new int[10])
{
	Letter = new char*[20];
	for (int i = 0; i < 20; i++)
		Letter[i] = new char[4];
}

convert::convert(const convert & c)
{
	*this = c;
}

convert::~convert()
{
	clear();
}



void convert::translate(const char * word)
{
	clear();
	Size = strlen(word);
	Size2d = new int[Size];
	Letter = new char*[strlen(word)+1];

	
	for (int i = 0; i < returnSize(); i++)
	{
		switch (word[i])
		{
		case 'a': case 'A':
			save(i, "._");
			break;
		case 'b': case 'B':
			save(i , "_...");
			break;
		case 'c': case 'C':
			save(i, "_._.");
			break;
		case 'd': case 'D':
			save(i, "_..");
			break;
		case 'e': case 'E':
			save(i, ".");
			break;
		case 'f': case'F':
			save(i, ".._.");
			break;
		case 'g': case'G':
			save(i, "__.");
			break;
		case 'h': case'H':
			save(i, "....");
			break;
		case 'i': case'I':
			save(i, "..");
			break;
		case 'j': case'J':
			save(i, ".___");
			break;
		case 'k': case'K':
			save(i, "_._");
			break;
		case 'l': case'L':
			save(i, "._..");
			break;
		case 'm': case'M':
			save(i, "__");
			break;
		case 'n': case'N':
			save(i, "_.");
			break;
		case 'o': case'O':
			save(i, "___");
			break;
		case 'p': case'P':
			save(i, ".__.");
			break;
		case 'q': case'Q':
			save(i, "__._");
			break;
		case 'r': case'R':
			save(i, "._.");
			break;
		case 's': case'S':
			save(i, "...");
			break;
		case 't': case'T':
			save(i, "_");
			break;
		case 'u': case'U':
			save(i, ".._");
			break;
		case 'v': case'V':
			save(i, "..._");
			break;
		case 'w': case'W':
			save(i, ".__");
			break;
		case 'x': case'X':
			save(i, "_.._");
			break;
		case 'y': case'Y':
			save(i, "_.__");
			break;
		case 'z': case'Z':
			save(i, "__..");
			break;
		case ' ':
			save(i, " ");
			break;
		case '1':
			save(i, ".____");
			break;
		case '2':
			save(i, "..___");
			break;
		case '3':
			save(i, "...__");
			break;
		case '4':
			save(i, "...._");
			break;
		case '5':
			save(i, ".....");
			break;
		case '6':
			save(i, "_....");
			break;
		case '7':
			save(i, "__...");
			break;
		case '8':
			save(i, "___..");
			break;
		case '9':
			save(i, "____.");
			break;
		case '0':
			save(i, "_____");
			break;
		case '.':
			save(i, "._._._");
			break;
		}
	}
}


void convert::save(int i, const char * chr)
{
	Size2d[i] = strlen(chr);
	Letter[i] = new char[strlen(chr) + 1];
	strcpy_s(Letter[i], strlen(chr)+1, chr);
}

const char convert::returnLetter(int i, int j) const
{
	return Letter[i][j];

}

const int convert::returnSize() const
{
	return Size;
}

const int convert::returnSize2d(int i) const
{
	return Size2d[i];
}

convert & convert::operator=(const convert & m)
{
	this->Letter = m.Letter;
	this->Size = m.Size;
	this->Size2d = m.Size2d;

	return *this;
}

void convert::clear()
{
	if (Size != 0)
	{
		for (int i = 0; i < Size; i++)
			delete[] Letter[i];
	}
	delete[] Letter;
	delete[] Size2d;
	Size = 0;
}

void convert::setLetter(int i, int j)
{
	this->Letter = new char*[i];
	for (int a = 0; a < i; a++)
		Letter[a] = new char[j];
	setSize(i);
	setSize2d(i);

}

void convert::setSize(int i)
{
	this->Size = i;
}

void convert::setSize2d(int i)
{
	this->Size2d = new int[i];
}
