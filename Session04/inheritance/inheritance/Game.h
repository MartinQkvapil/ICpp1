#pragma once

#ifndef GAME_H
#define GAME_H

#include "Object.h"
#include "DynamicObject.h"



class Game
{
private:
	Object** objects;
	int countOfObject;

public:
	Game();
	~Game();

	//	Vloží objekt do pole.
	void insertObject(Object* o);
	
	int* findIdOfStaticObject(double xmin, double xmax, double	ymin, double ymax);
	//Vrátí pole id všech statických objektù v zadaných souøadnicích.
	DynamicObject** findDynObjects(double x, double y, double r);
	//Vrátí pole ukazelù na pohyblivé objekty v kruhové oblasti(S = [x, y], radius = r).
	DynamicObject** findDynObjects(double x, double y, double r, double umin, double umax);
	//Viz pøedchozí, navíc kontrola úhlu natoèení
};


#endif // !GAME_H
