#ifndef ENTITY_H
#define ENTITY_H

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

/**/

class Entity
{
public:
	Entity() {
		_id = 0;
		std::string _name =  "";
		
		int _data = 0;
	};
	Entity(int value) : _data(value) {};
	

	friend bool operator>(Entity& t1, Entity& t2) {
		return t1._data > t2._data;
	}
	friend bool operator<(Entity& t1, Entity& t2) {
		return t1._data < t2._data;
	}
	friend std::ostream& operator<<(std::ostream& os, Entity& t) {
		os << std::to_string(t._data);
		return os;
	}
	
	/*friend std::fstream& operator>>(std::fstream& os, Entity& t) {
		os >> std::to_string(t._data) << std::to_string(_name) << std::to_string(_id);
		return os;
	}*/

private:
	int _id;
	std::string _name;
	static int _countOfEntities;
	int _data;
};


#endif 
