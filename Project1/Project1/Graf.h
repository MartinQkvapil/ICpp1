#pragma once
#include "Hrana.h"
#include "Vrchol.h"

class Graf
{
public:
	Graf();
	~Graf();

	template<typename V, typename H>
	static void napojit(Vrchol<V, H>* a, Vrchol<V, H>* b, Hrana<V, H>* h) {
		
		h->v1 = a;
		h->v2 = b;
		for (int  i = 0; i < limit; i++)
		{
			if (h->v1->hrany[i] == nullptr) {
				
				a->hrany[i] = h;
				
				
			}
		}	

	}
};

