#pragma once
#include "Hrana.h"
#include "Vrchol.h"

template <typename V, typename H>
class PruchodGrafem
{
public:
	Vrchol<V, H> zasobnik[limit];
	Vrchol<V, H> dosazene[limit];
	int TOP = -1;
public:
	PruchodGrafem();
	~PruchodGrafem();
	template<V, H>
	bool jeDosazitelny(Vrchol<V, H>* a, Vrchol<V, H>* b) {
		bool ukonci = true;
		Vrchol<V, H>* tmp;
		push(a);
		if (a = b) {
			return true;			
		}
		while (ukonci) {
			tmp = pop();
			if (tmp = b) {
				return true;
			}
			for (int i = 0; i < limit; i++)
			{
				if (dosazene[i] == tmp) {
					break;
				}
				if (dosazene[i] == nullptr) {
					dosazene[i] = tmp;
				}
			}
			if (isEmpty()) {
				return false;
			}
			push(tmp->hrany->dejOpacnouStranu(tmp));
		}		

		return false;
	}

	int isEmpty() {
		if (TOP == -1)
			return 1;
		else
			return 0;
	}

	int isFull() {
		if (TOP == limit - 1)
			return 1;
		else
			return 0;
	}

	void push(Vrchol<V, H>* a) {
		if (isFull()) {			
			return;
		}
		++TOP;
		zasobnik[TOP] = a;
		
	}

	Vrchol<V, H>* pop(){
		Vrchol<V, H>* temp;
    if(isEmpty()){       
        return;
    }
     
    temp=zasobnik[TOP];
    TOP--;   
	return temp;
}


};



