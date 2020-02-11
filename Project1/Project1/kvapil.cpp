#include <iostream>

#include "Hrana.h"
#include "Vrchol.h"
#include "Graf.h"
#include "PruchodGrafem.h"

int main() {

	Graf *g = new Graf{};
	/*Vrchol<int, int> *v = new Vrchol<int, int>{};
	Hrana<int, int> *h = new Hrana<int, int>{};
	Graf::napojit(v, v, h);*/

	delete g;

	
	system("pause");
	return 0;
}