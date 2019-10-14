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

double Object::getX()
{
	return this->x;
}

double Object::getY()
{
	return this->y;
}

void Object::setX(double x)
{
	this->x = x;
}

void Object::setY(double y)
{
	this->y = y;
}

int Object::getId()
{
	return this->id;
}
