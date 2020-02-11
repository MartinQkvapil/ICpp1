#pragma once

#include <string>
#include <iostream>     // std::cout
#include <fstream>
#include <iterator>
#include <algorithm>
#include "Osoba.h"



class DatovySouborLoader
{
	static int poziceSekci[];
	static int velikostSekci[];

	
	std::istream * vstup; 
	

	

	
	char * retezce;
public:
	DatovySouborLoader();
	~DatovySouborLoader();

	


	Osoba * nactiOsobu(int index);
	Hierarchie * nactiHierarchii(int index);
	int * najdiVsechnyHierarchie();
};

