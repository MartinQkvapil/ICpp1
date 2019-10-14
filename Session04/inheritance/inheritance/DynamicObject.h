#ifndef DYNAMIC_OBJECT_H
#define DYNAMIC_O

#include "Object.h"
# define M_PI 3.14159265358979323846 

#define _USE_MATH_DEFINES

class DynamicObject : public Object
{
private:
	double angle;
	int id;

public:
	DynamicObject(int id);
	~DynamicObject();

	void setAngle(double);
	double getAngle();
};

#endif // !DYNAMIC_OBJECT_H