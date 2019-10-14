#ifndef STATIC_OBJECT_H
#define STATIC_OBJECT_H

#include "Object.h"
#include "TypeOfObstacle.h"

class StaticObject : public Object {
public:
	StaticObject(int id, TypeOfObstacle type);
	TypeOfObstacle GetTypeOfObstacle();
private:
	TypeOfObstacle typPrekazky;

};


#endif // !STATIC_OBJECT_H
