#ifndef PROUDY_H
#define PROUDY_H 

#include <iostream>
#include <ostream>

class Proudy
{
	Proudy() {};
	~Proudy() {};


	friend std::ostream& operator<<(std::ostream& os, const Proudy& obj) {
		
	}

	friend std::istream& operator>>(std::istream& is, Proudy& obj) {
	
	}


};

#endif 