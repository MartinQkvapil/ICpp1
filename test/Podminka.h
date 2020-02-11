#ifndef PODMINKA_H
#define PODMINKA_H

#include <string>
#include <iostream>

class Podminka
{
public:
	Podminka() {};
	Podminka(std::string msg) : _msg(msg){};
	~Podminka() {};
	std::string GetMsg() const {
		return _msg;
	}
private:
	std::string _msg;
};

#endif
