#include "Rodokmen.h"

int main() {
	std::ifstream in{};
	in.open("rodokmen.txt");
	
	if (in.is_open())
	{
		Rodokmen* r = new Rodokmen(in);
	
	
	int pocet = 0;
	for (int i = 1; i < 10; i++)
	{
		std::cout << "ID: " << i;
		pocet = r->dejPocetPrimychPotomku(i);
		std::cout << ", pocet primych potomku: " << pocet;
		pocet = r->dejPocetVsechPotomku(i);
		std::cout << ", pocet vsech potomku: " << pocet << std::endl;
	}
	delete r;
	}
	return 0;
}