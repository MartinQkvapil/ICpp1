#include "NodePlus.h"

bool NodePlus::JeKorektneZapojen(const IPipe* potrubi) const
{
	if (potrubi->DejPrvek(_x, _y + 1) != nullptr && potrubi->DejPrvek(_x, _y - 1) != nullptr &&
		potrubi->DejPrvek(_x, _y + 1) != nullptr && potrubi->DejPrvek(_x, _y - 1) != nullptr) {
		return true;
	}
	return false;
}
