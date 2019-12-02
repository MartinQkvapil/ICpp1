#include <iostream>
#include <sstream>
using namespace std;


int main() {
	ostringstream oss{};
		oss << 3 << '\n';
		oss << "  0" << '\n';
		oss << "0I0" <<'\n';
		oss << " 0 ";
	

	istringstream iss{
		oss.str()
		/*string("2") + "\n" +
		" 0" + "\n" +
		"0 "*/
	};

	int rozmer;
	iss >> rozmer;

	if (iss.peek() == '\n')
	{
		iss.get();
	}

	for (int i = 0; i < rozmer; i++){
		string str{};
		getline(iss, str);
		for (int j = 0; j < rozmer; j++){
			cout << str[j] << ';';
		}
		cout << endl;



	}

	return 0;
}