#include "NodeT.h"

bool NodeT::JeKorektneZapojen(const IPipe* potrubi) const
{
	return true;// (potrubi->DejPrvek(_x, _y + 1) != nullptr &&
		//potrubi->DejPrvek(_x + 1, _y) != nullptr &&
		//potrubi->DejPrvek(_x - 1, _y) != nullptr);
}
