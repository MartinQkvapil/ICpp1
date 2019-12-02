#ifndef _NODET_H
#define _NODET_H
#include "PipeNode.h"
#include "IPipe.h"

struct NodeT : PipeNode {
	NodeT(int x, int y) { _x = x; _y = y; };
	~NodeT() { }
	bool JeKorektneZapojen(const IPipe* potrubi) const;
	int _x;
	int _y;
};

#endif // !_NODET_H