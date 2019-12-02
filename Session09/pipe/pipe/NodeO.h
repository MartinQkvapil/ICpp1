#ifndef _NODE_O_H
#define _NODE_O_H
#include "PipeNode.h"
#include "IPipe.h"

struct NodeO : PipeNode {
	NodeO(int x, int y) {
		_x = x;
		_y = y;
	}
	~NodeO() { }
	bool JeKorektneZapojen(const IPipe* potrubi) const;
	int _x;
	int _y;
};

#endif // !_NODE_O_H