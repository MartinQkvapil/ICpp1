#include "Vrchol.h"


template <typename V, typename H>
Vrchol<V, H>::Vrchol()
{
	for (int i = 0; i < limit; i++)
	{
		hrany[i] = nullptr;

	}
}

template <typename V, typename H>
Vrchol<V, H>::~Vrchol()
{
}
