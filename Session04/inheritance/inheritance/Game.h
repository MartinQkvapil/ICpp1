#pragma once

#ifndef GAME_H
#define GAME_H

#include "Object.h"
#include "DynamicObject.h"



class Game
{
public:
	Game();
	~Game();

	//	Vloží objekt do pole.
	void InsertObject(Object* o);
	
	//Vrátí pole id všech statických objektù v zadaných souøadnicích.
	int* findIdOfStaticObject(double xmin, double xmax, double	ymin, double ymax);
	
	//Vrátí pole ukazelù na pohyblivé objekty v kruhové oblasti(S = [x, y], radius = r).
	DynamicObject** FindDynObjects(double x, double y, double r);
	
	//Viz pøedchozí, navíc kontrola úhlu natoèení
	DynamicObject** FindDynObjects(double x, double y, double r, double umin, double umax);
	
private:
	Object** objects;
	int countOfObject;

};


#endif // !GAME_H
