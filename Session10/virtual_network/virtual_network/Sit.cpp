#include "Sit.h"

int Sit::idZpravy = 0;
int Sit::DejNoveId()
{
	return idZpravy;
}

void Sit::Pripoj(ASitovyPrvek* sitovyPrvek)
{
	if (sitovePrvky.Obsahuje(sitovyPrvek)) {
		throw "Uz obsahuje sitovy prvek";
	}

	sitovePrvky.Vloz(sitovyPrvek);
	
}

void Sit::Provadej()
{
}

void Sit::ZpracujPrichoziZpravu(ZpravaPort zp)
{
}



void Sit::ProvadejVse()
{
	sitovePrvky.ZpracujPrvky([](ASitovyPrvek* a) {a->Provadej(); });
}


