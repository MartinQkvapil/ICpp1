#pragma once
#include "IObject.h"

class IComparable : public IObject
{
public:
	IComparable();
	~IComparable();

	virtual int compareTo(IComparable* obj) const = 0;

};

