


#ifndef _Morse_H
#define _Morse_H

#include <string>

#include <iostream>


class morse
{
protected:
	std::string translated_morse;
	int Frequency; // czêstotliwoœæ
	int Pause; // przerwa pomiedzy kropkami i kreskami
	int DotTime; // czas trwania kropki alfabetu morsa
	int DashTime; // czas trwania kreski alfabetu morsa
	int CharPause; // przerwa pomiedzy poszczeólnymi literami
	//convert converter; // obiekt klasy convert, odpowiedzialny za t³umaczenie 

public:
	morse();
	//void translate(const std::string& str);
	void translate(int in);
	//void translate(double in);
	void setDot_time();
	void setDash_time();
	void setFrequency();
	void set_char_pause();
	void set_space_pause();


	virtual void to_morse() = 0;




};




#endif