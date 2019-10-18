#ifndef DYNAMIC_OBJECT_H
#define DYNAMIC_O

#include "Object.h"

# define M_PI 3.14159265358979323846 

class DynamicObject : public Object
{
public:
	DynamicObject(int id);
	~DynamicObject();

	void SetAngle(double);
	double GetAngle();
private:
	double angle;
	int id;


};

#endif // !DYNAMIC_OBJECT_H