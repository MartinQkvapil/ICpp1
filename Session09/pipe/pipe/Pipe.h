#ifndef PIPE_H
#define PIPE_H

#include "IPipe.h"
#include <iostream>
#include <sstream>
#include <string>

struct Pipe : IPipe {

	Pipe(int vel, std::istringstream iss);
	~Pipe() {};
	const PipeNode* DejPrvek(int x, int y) const;
	bool JePotrubiOk() const;

	PipeNode*** matice;
	int velikost;
};


#endif
