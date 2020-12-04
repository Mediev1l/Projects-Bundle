#include "Edit.h"


Edit::Edit()
	: length(20), pos_X(0), pos_Y(0), text(), hd(), crd(), text_color(White), background_color(Black)
{
	hd = GetStdHandle(STD_OUTPUT_HANDLE);
	crd.X = getPos_X();
	crd.Y = getPos_Y();
	SetConsoleCursorPosition(hd, crd);
}

Edit::Edit(const Edit & E)
{
	*this = E;
}

Edit::~Edit()
{
}

void Edit::setPosition(int x, int y)
{
	if (x < 0)
		setPos_X(0);
	else
		setPos_X(x);
	if (y < 0)
		setPos_Y(0);
	else
		setPos_Y(y);

	crd.X = getPos_X();
	crd.Y = getPos_Y();

	SetConsoleCursorPosition(hd, crd);

}

void Edit::setLength(int length)
{
	this->length = length;
}

void Edit::setText(std::string text)
{
	this -> text = text;
}

void Edit::setTextColor(colors text_col)
{
	text_color = text_col;
	SetConsoleTextAttribute(hd, text_color + background_color * 16);

	
}

void Edit::setBackgroundColor(colors backgroud_col)
{
	background_color = backgroud_col;
	SetConsoleTextAttribute(hd, text_color + background_color * 16);

}

Edit & Edit::operator=(const Edit & E)
{
	length = E.length;
	pos_X = E.pos_X;
	pos_Y = E.pos_Y;
	text = E.text;
	hd = E.hd;
	crd = E.crd;

	return *this;
}

void Edit::setPos_X(int X)
{
	pos_X = X;
}

void Edit::setPos_Y(int Y)
{
	pos_Y = Y;
}

void Edit::display()
{
	for (int i = 0; i < getLength(); i++)
	{
		if (i < text.length())
			std::cerr << text[i];
		else
			std::cerr << " ";
	}
	
}

void Edit::userText()
{
	setPosition(pos_X, pos_Y);
	char* letters = new char[getLength()+1];
	int input;
	int i = 0;
	int counter = 0;
	do
	{
			input = checkKey();

			switch (input)
			{
			case 8:
			{
				if (i > 0 && counter > 0)
				{
					letters[counter] = NULL;
					pos_X -= 1;
					setPosition(pos_X, pos_Y);
					std::cerr << letters[counter];
					setPosition(pos_X, pos_Y);
					counter -= 1;
					i -= 1;
				}
				break;
			}
			case 13:
			{

				letters[i] = '\0';
				break;
			}

			case -1000:
			{
				if (counter > 0 )
				{
					counter--;
					pos_X -= 1;
					setPosition(pos_X, pos_Y);
				}
				break;
			}
			case -1001:
			{
				if (counter < getLength() && counter < i)
				{
					counter++;
					pos_X += 1;
					setPosition(pos_X, pos_Y);
				}
				break;
			}

			default:
				if (counter < getLength())
				{
					letters[counter] = input;
					std::cerr << letters[counter];
					pos_X += 1;

					if(i < getLength())
						i++;
					counter++;
					setPosition(pos_X, pos_Y);
				}
				break;
			}

		


	} while (input != 13 );


	setText(letters);
	setBackgroundColor(Black);
	setPosition(0, pos_Y + 1);
	delete[] letters;

}





const int Edit::getLength() const
{
	return length;
}

const int Edit::getPos_X() const
{
	return pos_X;
}

const int Edit::getPos_Y() const
{
	return pos_Y;
}

const std::string Edit::getText() const
{
	return text;
}

const int Edit::checkKey() const
{
	int key;

	key = _getwch();
	if (key == 224)
	{
		do
		{
			key = _getwch();
		}while (key == 224);

		switch (key)
		{
		case 72:
			key = 32;
			break;
		case 75:
			key = -1000;
			break;
		case 77:
			key = -1001;
			break;
		case 80:
			key = 32;
			break;
		}
	}
	return key;

}



















