#include "NodeMinus.h"


bool NodeMinus::JeKorektneZapojen(const IPipe* potrubi) const
{
	return true;// (potrubi->DejPrvek(_x + 1, _y) != nullptr && potrubi->DejPrvek(_x - 1, _y) != nullptr);
}
