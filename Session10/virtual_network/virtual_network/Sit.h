#ifndef SIT_H
#define SIT_H

#include "ASitovyPrvek.h"

struct Sit : ASitovyPrvek
{
private:
	static int idZpravy;
	Fronta<ASitovyPrvek*> sitovePrvky; // dost
public:
	Sit() {
		//idZpravy = 0;
	};
	
	int DejNoveId();
	void Pripoj(ASitovyPrvek* sitovyPrvek);
	void Provadej();
	void ZpracujPrichoziZpravu(ZpravaPort zp);
	void ProvadejVse();

};


#endif // !SIT_H
