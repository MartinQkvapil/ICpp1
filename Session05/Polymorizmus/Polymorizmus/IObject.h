#pragma once

#include <string>

class IObject
{
public:
	IObject();
	~IObject();

	virtual std::string ToString() const = 0; 
private:

};

