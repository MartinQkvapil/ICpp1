#include <iostream>
#include <string>
#include "Matrix.h"



int main() {
	//matrix creation
	Matrix<int> m{ 3,3 };

	int testArr[] = { 0,1,2,3,4,5,6,7,8 };
	m.SetZ(testArr);
	m.Print();

	return 0;
}