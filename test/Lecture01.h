#ifndef LECTURE01_H
#define LECTURE01_H

#include<iostream>
#include<string>
#include<time.h>

namespace LectureX {
	static void testNamespaceCalling() {
		std::cout << "Called namespace Lecture01" << std::endl;
	}
};

struct ExceptionTest {
	ExceptionTest() {};
	ExceptionTest(std::string msg) {
		std::cout << msg << std::endl;
	};
	~ExceptionTest() {};
};

using namespace LectureX;

class Lecture01 {
public:
	Lecture01() {};
	~Lecture01() {};

	void testNamespace() {
		testNamespaceCalling();
	}
	void callException(int index) {
		
		for (int i = 0; i < index; i++)
		{
			/*srand(time(NULL));
			int random = rand();
			if (random % 2 == 0) {
				throw ExceptionTest("Exception called.");
			}
			else {
				std::cout << "No exception..." << std::endl;
			}*/
		}
	};



private:
	


};

#endif // !LECTURE01_H
