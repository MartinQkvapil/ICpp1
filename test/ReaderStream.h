#ifndef READ_H
#define READ_H

#include <fstream>


class ReaderStream {
public:
	ReaderStream(std::istream * in): _vstup(in) {};



	~ReaderStream() {};
private:
	std::istream* _vstup;

};

#endif