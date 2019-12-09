#include <iostream>
#include <sstream>

#include "Pipe.h"
#include "PipeNode.h"


using namespace std;

std::istringstream data() {
	ostringstream oss{};
	
	oss << "  0" << '\n';
	oss << "0I0" << '\n';
	oss << " 0 ";

	istringstream iss{
		oss.str()
	};

	return iss;
}


int main() {

	ostringstream oss{};
		oss << 3 << '\n';
		oss << "  0" << '\n';
		oss << "0I0" <<'\n';
		oss << " 0 ";		

	istringstream iss{
		oss.str()		
	};

	int rozmer;
	iss >> rozmer;

	if (iss.peek() == '\n')
	{
		iss.get();
	}

	IPipe* pipe = new Pipe(5, data());

	for (int i = 0; i < rozmer; i++){
		string str{};
		getline(iss, str);
		for (int j = 0; j < rozmer; j++){
			cout << str[j] << ';';
		}
		cout << endl;
	}

	//std::cout << pipe->() << std::endl;
	std::cout << pipe->JePotrubiOk() << std::endl;


	return 0;
}