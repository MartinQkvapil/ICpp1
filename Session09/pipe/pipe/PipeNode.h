#ifndef _IPIPENODE_H
#define _IPIPENODE_H

struct IPipe;
struct PipeNode;
struct PipeNode {

	virtual ~PipeNode() { }
	virtual bool JeKorektneZapojen(const IPipe* potrubi) const = 0;
	int _x;
	int _y;
};

#endif // IPIPENODE_H
