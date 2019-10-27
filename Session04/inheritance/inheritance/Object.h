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

	double GetX() const;
	double GetY() const;
	void SetX(double) ;
	void SetY(double) ;

	int GetId();





};


#endif // OBJECT_H
