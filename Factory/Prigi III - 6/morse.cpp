#include "morse.h"

//void morse::translate(const std::string& str)
//{
//	int size = str.size();
//	std::string translated;
//
//		for (int i = 0; i < size; i++)
//		{
//			switch (str[i])
//			{
//			case 'a': case 'A':
//				translated += "._";
//				break;
//			case 'b': case 'B':
//				translated += "_...";
//				break;
//			case 'c': case 'C':
//				translated += "_._.";
//				break;
//			case 'd': case 'D':
//				translated += "_..";
//				break;
//			case 'e': case 'E':
//				translated += ".";
//				break;
//			case 'f': case'F':
//				translated += ".._.";
//				break;
//			case 'g': case'G':
//				translated += "__.";
//				break;
//			case 'h': case'H':
//				translated += "....";
//				break;
//			case 'i': case'I':
//				translated += "..";
//				break;
//			case 'j': case'J':
//				translated += ".___";
//				break;
//			case 'k': case'K':
//				translated += "_._";
//				break;
//			case 'l': case'L':
//				translated += "._..";
//				break;
//			case 'm': case'M':
//				translated += "__";
//				break;
//			case 'n': case'N':
//				translated += "_.";
//				break;
//			case 'o': case'O':
//				translated += "___";
//				break;
//			case 'p': case'P':
//				translated += ".__.";
//				break;
//			case 'q': case'Q':
//				translated += "__._";
//				break;
//			case 'r': case'R':
//				translated += "._.";
//				break;
//			case 's': case'S':
//				translated += "...";
//				break;
//			case 't': case'T':
//				translated += "_";
//				break;
//			case 'u': case'U':
//				translated += ".._";
//				break;
//			case 'v': case'V':
//				translated += "..._";
//				break;
//			case 'w': case'W':
//				translated += ".__";
//				break;
//			case 'x': case'X':
//				translated += "_.._";
//				break;
//			case 'y': case'Y':
//				translated += "_.__";
//				break;
//			case 'z': case'Z':
//				translated += "__..";
//				break;
//			case ' ':
//				translated += "|";
//				break;
//			case '1':
//				translated += ".____";
//				break;
//			case '2':
//				translated += "..___";
//				break;
//			case '3':
//				translated += "...__";
//				break;
//			case '4':
//				translated += "...._";
//				break;
//			case '5':
//				translated += ".....";
//				break;
//			case '6':
//				translated += "_....";
//				break;
//			case '7':
//				translated += "__...";
//				break;
//			case '8':
//				translated += "___..";
//				break;
//			case '9':
//				translated += "____.";
//				break;
//			case '0':
//				translated += "_____";
//				break;
//			case '.':
//				translated += "._._._";
//				break;
//			}
//		}
//
//		translated_morse = translated;
//	
//}

morse::morse()
{
}

void morse::translate(int in)
{
	std::string temp = std::to_string(in);
	//translate(temp);
}

void morse::setDot_time()
{
}

void morse::setDash_time()
{
	int x;
}

void morse::setFrequency()
{
}

void morse::set_char_pause()
{
}

void morse::set_space_pause()
{
}



//void morse::translate(double in)
//{
//	std::string temp = std::to_string(in);
//	translate(temp);
//}
//


