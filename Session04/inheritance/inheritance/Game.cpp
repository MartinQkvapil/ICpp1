#include "pch.h"
#include "Game.h"
#include "StaticObject.h"

#define FIRST_INIT 0


Game::Game()
{
	this->objects = new Object*[FIRST_INIT];  //first allocate array of row pointers
	this->countOfObject = 0;
}


Game::~Game()
{
	delete[] objects;
}

void Game::InsertObject(Object * o)
{
	if (countOfObject == 0) {
		this->objects[this->countOfObject] = o;
		countOfObject++;
	}
	else {
		Object **tmp = new Object *[++countOfObject];
		for (int i = 0; i < countOfObject-1; i++)
		{
			tmp[i] = this->objects[i];
		}
		tmp[countOfObject] = o;
		
		// erase array 
		for (int i = 0; i < countOfObject-1; i++)
		{
			delete this->objects[i];
		}
		//delete this->objects;
		
	
		//fill with new values
		this->objects = new Object *[countOfObject];
		for (int i = 0; i < countOfObject; i++)
		{
			this->objects[i] = tmp[i];
		}

		/*for (int i = 0; i < countOfObject; i++)
		{
			delete tmp[i];
		}
		delete[] tmp;*/
		
	}

	//if (sizeof(this->objects) / sizeof(this->objects[0]) <= countOfObject) {
	/*}
	else {
		Object **tmp = new Object*[countOfObject + 1];
		for (int i = 0; i >= countOfObject; i++)
		{
			tmp[i] = this->objects[i];
		}
	}*/
}
//
int * Game::findIdOfStaticObject(double xmin, double xmax, double ymin, double ymax)
{
	int* arr = new int[10];
	int countInArr = 0;

	for (int i = 0; i < countOfObject; i++) {
		if (objects[i]->getX() > xmin && objects[i]->getX() < xmax && objects[i]->getY() > ymin && objects[i]->getY() < ymax) {
			StaticObject* so = dynamic_cast<StaticObject*>(objects[i]);
			if (so != nullptr) {
				arr[countInArr] = so->getId();
				countInArr++;
			}
		}

	}
	return arr;
}

DynamicObject ** Game::FindDynObjects(double x, double y, double r)
{
	DynamicObject** pole = new DynamicObject*[10];
	int pocetV = 0;

	for (int i = 0; i < countOfObject; i++) {
		DynamicObject* so = dynamic_cast<DynamicObject*>(objects[i]);
		if (so != nullptr) {
			pole[pocetV] = so;
			pocetV++;
		}
	}


	return pole;
}

DynamicObject ** Game::FindDynObjects(double x, double y, double r, double umin, double umax)
{
	DynamicObject** pole = new DynamicObject*[10];
	int pocetV = 0;

	for (int i = 0; i < countOfObject; i++) {
		DynamicObject* so = dynamic_cast<DynamicObject*>(objects[i]);
		if (so != nullptr) {
			pole[pocetV] = so;
			pocetV++;
		}
	}


	return pole;
}
