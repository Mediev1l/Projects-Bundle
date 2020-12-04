#include <string>
#include <iostream>
#include "Edit.h"
#include "Ccolor.h"



int main()
{
	Edit e;
	e.setPosition(7, 3); 
	e.setLength(6); 
	e.setText("Ala");
	e.setTextColor(Edit::White); 
	e.setBackgroundColor(Edit::Blue); 
	e.display(); 
	std::string s = e.getText(); 

	e.userText(); 
	s = e.getText(); 


	

	std::cout << "A" << red << "l" << blue << "a " << green << "ma "<< white << "kota"<<std::endl; 

	std::cout << setcolor(FOREGROUND_RED | BACKGROUND_GREEN) << "Miauu" << defcolor << "xyzyw"<<std::endl; 




	return 0;
	


}

