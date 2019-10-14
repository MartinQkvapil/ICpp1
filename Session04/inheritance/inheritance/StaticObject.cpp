#include "pch.h"
#include "StaticObject.h"

StaticObject::StaticObject(int id, TypeOfObstacle type) : Object(id)
{
	
		this->typPrekazky = type;
	
}

TypeOfObstacle StaticObject::GetTypeOfObstacle()
{
	return this->typPrekazky;
}
