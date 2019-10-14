#ifndef OBJECT_H
#define OBJECT_H

class Object {
private:
	int id;
	double x;
	double y;
public:
	Object(int);
	Object(int, double, double);
	virtual ~Object();

	double getX();
	double getY();
	void setX(double);
	void setY(double);

	int getId();





};


#endif // OBJECT_H
