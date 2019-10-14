#ifndef MONSTER_H
#define MONSTER_H

#include "DynamicObject.h"

class Monster : public DynamicObject
{
private:
	int id;
	int hp;
	int maxHp;
public:
	Monster(int id);
	~Monster();

	void setHp(int);
	void setMaxHp(int);

	int getHp();
	int getMaxHp();
};


#endif // !MONSTER_H
