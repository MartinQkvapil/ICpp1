#ifndef _NODEMINUS_H
#include "PipeNode.h"
#include "IPipe.h"

struct NodeMinus : PipeNode
{
	NodeMinus() {};
	NodeMinus(int x, int y) { _x = x; _y = y; }
	~NodeMinus() { }
	virtual bool JeKorektneZapojen(const IPipe* potrubi) const;
	int _x;
	int _y;
};

#endif