#include "pch.h"
#include "Object.h"

Object::Object(int id)
{
	this->id = id;
}

Object::Object(int id, double x, double y) {
	this->id = id;
	this->x = x;
	this->y = y;
}

Object::~Object()
{
}

double Object::GetX() const
{
	return this->x;
}

double Object::GetY() const
{
	return this->y;
}

void Object::SetX(double x) 
{
	this->x = x;
}

void Object::SetY(double y) 
{
	this->y = y;
}

int Object::GetId()
{
	return this->id;
}
