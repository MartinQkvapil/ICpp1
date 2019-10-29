#pragma once
#include "IComparable.h"
class Time : public IComparable
{
public:
	Time(int _h, int _m, int _s);
	~Time();

	int compareTo(IComparable* obj) const override;

	std::string ToString() const override;

	void SortArray(IComparable** arr, int arraySize);


private:
	int _hours;
	int _minutes;
	int _seconds;

};

