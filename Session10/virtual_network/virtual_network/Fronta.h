#ifndef _FRONTA_H
#define _FRONTA_H


template <typename T>
struct Fronta {
private:
	struct El {
		T hodnota;
		El* dalsi;
		El* predchozi;
	};

	El* prvni;
	El* posledni;
public:
	Fronta() {
		prvni = posledni = nullptr;
	}

	Fronta(const Fronta& f) {
		El* it = f.prvni;
		while (it) {
			Vloz(it->hodnota);
			it = it->dalsi;
		}
	}

	~Fronta() {
		while (prvni) {
			El* tmp = prvni;
			prvni = prvni->dalsi;
			delete tmp;
		}
	}

	void Vloz(T hodnota) {
		posledni = new El{ hodnota, nullptr, posledni };
		if (!prvni)
			prvni = posledni;
		else
			posledni->predchozi->dalsi = posledni;
	}

	T Odeber() {
		T hodnota = posledni->hodnota;
		El* tmp = posledni;

		if (posledni->predchozi) {
			posledni = posledni->predchozi;
			posledni->dalsi = nullptr;
		}
		else {
			posledni = nullptr;
			prvni = nullptr;
		}

		delete tmp;
		return hodnota;
	}

	bool Obsahuje(T hodnota) const {
		El* el = prvni;
		while (el) {
			if (el->hodnota == hodnota)
				return true;

			el = el->dalsi;
		}

		return false;
	}

	using ApplyFunkce = void(*) (T);

	void ZpracujPrvky(ApplyFunkce f) {
		El* el = prvni;
		while (el) {
			f(el->hodnota);

			el = el->dalsi;
		}
	}

	bool JePrazdna() const {
		return prvni == nullptr;
	}
};

#endif // !_FRONTA_H