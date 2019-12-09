#include "NodeI.h"

bool NodeI::JeKorektneZapojen(const IPipe* potrubi) const
{	
	return true; // (potrubi->DejPrvek(_x, _y + 1) != nullptr && potrubi->DejPrvek(_x, _y - 1) != nullptr);
}
