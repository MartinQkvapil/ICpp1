#include "NodeMinus.h"


bool NodeMinus::JeKorektneZapojen(const IPipe* potrubi) const
{
	if (potrubi->DejPrvek(_x + 1, _y) != nullptr && potrubi->DejPrvek(_x - 1, _y) != nullptr) {
		return true;
	}
	return false;
}
