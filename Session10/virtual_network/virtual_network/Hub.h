#ifndef  HUB_H
#define HUB_H
#include "ASitovyPrvek.h"

class Hub : ASitovyPrvek
{
private:
	ASitovyPrvek** pripojenePrvky;
	int maximumPripojenychPrvku;
	Fronta<Zprava*> zpracovaneZpravy;
	void ZpracujPrichoziZpravu(ZpravaPort zp);
public:
	Hub(int max) {
		maximumPripojenychPrvku = max;
		pripojenePrvky = new ASitovyPrvek * [max];
		
		for (int i = 0; i < max; i++)
		{
			pripojenePrvky[i] = nullptr;
		}
	};
	void Pripoj(ASitovyPrvek* sitovyPrvek);
	void Provadej();
	
};

#endif // ! HUB_H