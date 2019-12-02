#ifndef _NODEI_H
#define _NODEI_H
#include "PipeNode.h"
#include "IPipe.h"

struct NodeI : PipeNode
{
	NodeI(int x, int y) {
		_x = x;
		_y = y;
	}
	~NodeI() {  }
	bool JeKorektneZapojen(const IPipe* potrubi) const;
	int _x;
	int _y;
};

#endif