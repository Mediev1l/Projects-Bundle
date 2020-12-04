

#ifndef _Factory_H
#define _Facory_H

#include "morse.h"
#include "console.h"

#include <string>
#include <sstream>
#include <vector>


#include <iostream>

class factory
{
public:
	enum handle
	{
		_beep = 0,
		_disc = 1,
		_blink = 2,
		_console = 3
	};
protected:
	morse* mors;
	//parser par;
	handle current;
public:
	factory();
	factory(const factory& fac);
	virtual ~factory();

	void setExtraInfo(std::string str);
	void setOutput(handle hd);
	void clear();

	template<class T>
	void convert(const T& x);



	


};




#endif

template<class T>
inline void factory::convert(const T & x)
{
	mors->translate(x);
	
}
