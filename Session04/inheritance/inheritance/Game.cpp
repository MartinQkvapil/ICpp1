#include "pch.h"
#include "Game.h"
#include "StaticObject.h"

#define  FIRST_INIT 0 //first allocation  


Game::Game()
{
	this->objects = new Object*[FIRST_INIT];  //first allocate array of row pointers
	this->countOfObject = 0;
}


Game::~Game()
{
	delete[] objects;
}

void Game::InsertObject(Object * object)
{
	Object **tmp = new Object *[countOfObject + 1];
	for (int i = 0; i < countOfObject; i++)
	{
		tmp[i] = this->objects[i];
	}
	tmp[countOfObject++] = object;

	if (objects != nullptr) {
		delete[] objects;
	}
	objects = tmp;

}

//Vrátí pole id všech statických objektù v zadaných souøadnicích.
/*

*/
int * Game::findIdOfStaticObject(double xmin, double xmax, double ymin, double ymax)
{
	int* arr = new int[10];
	int countInArr = 0;

	for (int i = 0; i < countOfObject; i++) {
		if (objects[i]->GetX() > xmin && objects[i]->GetX() < xmax && objects[i]->GetY() > ymin && objects[i]->GetY() < ymax) {
			StaticObject* so = dynamic_cast<StaticObject*>(objects[i]); // if is static object return it else nullptr
			if (so != nullptr) {
				arr[countInArr] = so->GetId();
				countInArr++;
			}
		}

	}
	return arr;
}

//Vrátí pole ukazelù na pohyblivé objekty v kruhové oblasti(S = [x, y], radius = r).
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
