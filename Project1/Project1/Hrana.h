#pragma once

template<typename V, typename H>
class  Vrchol;

template <typename V, typename H>
class Hrana
{
public: 
	H data; 
	Vrchol<V, H> * v1;
	Vrchol<V, H> * v2;
public:
	Hrana();
	~Hrana();
	
	Vrchol<V, H>* dejOpacnouStranu(Vrchol<V, H>*v) {
		if (v1 != v && v2 != v) {
			throw Vyjimka{};
		}
		if (v1 == v) {
			return v2;
		}
		else {
			return v1;
		}
		
	}
};



class Vyjimka {


};