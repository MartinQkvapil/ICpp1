#include "Pipe.h"
#include "NodeI.h"
#include "NodePlus.h"
#include "NodeMinus.h"
#include "NodeT.h"
#include "NodeO.h"
#include "PipeNode.h"



Pipe::Pipe(int vel, std::istringstream iss)
{
	velikost = vel;
	matice = new PipeNode **[vel];
	for (int i = 0; i < 3; i++) {
		matice[i] = new PipeNode * [vel];
	}
	NodeMinus p;
	for (int i = 0; i < vel; i++) {
		std::string str{};
		getline(iss, str);
		for (int j = 0; j < vel; j++) {
			if (str[j] == '-') {
				matice[i][j] = new NodeMinus{i, j};
			}
			else if (str[j] == 'I') {
				matice[i][j] = new NodeI{ i,j };
			}
			else if (str[j] == '+') {
				matice[i][j] = new NodePlus{ i,j };
			}
			else if (str[j] == 'O') {
				matice[i][j] = new NodeO{ i,j };
			}
			else if (str[j] == 'T') {
				matice[i][j] = new NodeT{ i,j };
			}
			else
			{

				matice[i][j] = nullptr;
			}
		}

	}
}

const PipeNode* Pipe::DejPrvek(int x, int y) const {
	if (x < velikost && y < velikost && y >= 0 && x >= 0) {
		return matice[x][y];
	}
	return nullptr;
}

bool Pipe::JePotrubiOk() const {
	for (int x = 0; x < velikost; x++) {
		for (int y = 0; y < velikost; y++) {
			matice[x][y]->JeKorektneZapojen(this);
		}
	}
	return false;
}
