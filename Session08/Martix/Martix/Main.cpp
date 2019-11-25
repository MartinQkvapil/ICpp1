#include <iostream>
#include <string>
#include "Matrix.h"



int main() {
	//matrix creation
	Matrix<int> m{ 3,3 };

	int testArr[] = { 0,1,2,3,4,5,6,7,8 };
	m.SetZ(testArr);
	m.Print();

	Matrix<int> mt = m.Transposition();
	mt.Print();
	Matrix<int> mmt = m.MullMatrix(mt);
	mmt.Print();
	Matrix<double> mmt_d = mmt.ReType<double>();
	mmt_d.Print();
	Matrix<double> n_d{ 3,3 };
	double arr2[] = { 4.5,5,0,2,-0.5,7,1.5,9,6 };
	n_d.SetZ(arr2);
	n_d.Print();
	Matrix<double> mmtn_d = mmt_d.MullMatrix(n_d);
	Matrix<int> r = mmtn_d.ReType<int>();
	r.Print();
	Matrix<int> t{ 3,3 };
	int tpole[] = { 85,225,236,292,819,866,499,1413,1496 };
	t.SetZ(tpole);
	std::cout << "r==t ? " << (r.IsEqual(t) ? "true" : "false") << std::endl;

	return 0;
}