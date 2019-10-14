#include "pch.h"
#include "Monster.h"


Monster::Monster(int id) : DynamicObject(id)
{
}


Monster::~Monster()
{
}

void Monster::setHp(int x)
{
	this->hp = x;
}

void Monster::setMaxHp(int x)
{
	this->maxHp = x;
}

int Monster::getHp()
{
	return this->hp;
}

int Monster::getMaxHp()
{
	return this->maxHp;
}
