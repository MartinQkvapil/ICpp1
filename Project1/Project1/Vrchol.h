#pragma once

#include "Hrana.h"

const int limit = 100;

template <typename V, typename H>
class Vrchol
{
public: 
	V data; 
	Hrana<V, H> hrany[limit];
public:
	Vrchol();
	~Vrchol();
};

