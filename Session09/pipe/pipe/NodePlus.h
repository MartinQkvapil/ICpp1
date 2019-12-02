#ifndef _NODEPLUS_H
#define _NODEPLUS_H
#include "PipeNode.h"
#include "Ipipe.h"

struct NodePlus : PipeNode {
	NodePlus(int x, int y) {
		_x = x;
		_y = y;
	}
	~NodePlus() { }
	bool JeKorektneZapojen(const IPipe* potrubi) const;
	int _x;
	int _y;
};

#endif // !_NODEPLUS_H