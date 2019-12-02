#ifndef IPIPE_H
#define IPIPE_H
#include"PipeNode.h"

struct IPipe {
	virtual ~IPipe() { }
	virtual const PipeNode* DejPrvek(int x, int y) const = 0;
	virtual bool JePotrubiOk() const = 0;
};

#endif // !IPIPE_H
