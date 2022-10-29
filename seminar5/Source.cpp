#include <iostream>
using namespace std;
/*
enumuri, atribut const, supraincarcare operator =
*/

enum UM{
	BUC,
	LITRU,
	KILOGRAM
};

class Produs {
	const int cod;
	string denumire = "N/A";
	int nrZile = 0;
	float* preturi = nullptr;
	UM um = UM::BUC;
public:
	Produs(int cod): cod(cod) {
		cout << "\nApel constr cu un param";
	}
	Produs(int cod, string denumire, int nrZile, float* preturi, UM um): cod(cod) {
		cout << "\nApel constr cu toti param";
		this->denumire = denumire;
		this->um = um;
		if (nrZile < 1 || preturi == nullptr) {
			return;
		}
		this->nrZile = nrZile;
		this->preturi = new float[nrZile];
		for (int i = 0; i < nrZile; i++) {
			this->preturi[i] = preturi[i];
		}
	}
	Produs(const Produs& p): cod(p.cod) {
		cout << "\nApel constr copiere";
		this->denumire = p.denumire;
		this->um = p.um;
		if (p.nrZile < 1 || p.preturi == nullptr) {
			return;
		}
		this->nrZile = p.nrZile;
		this->preturi = new float[p.nrZile];
		for (int i = 0; i < p.nrZile; i++) {
			this->preturi[i] = p.preturi[i];
		}
	}

	Produs& operator= (const Produs& p) { //unsafe pentru ca putem accesa datele declarate dinamic
		cout << "\nApel operator = ";
		if (this==&p) {
			return *this;
		}
		delete[] this->preturi;
		this->denumire = p.denumire;
		this->um = p.um;
		if (p.nrZile < 1 || p.preturi == nullptr) {
			this->preturi = nullptr;
			this->nrZile = 0;
			return *this;
		}
		this->nrZile = p.nrZile;
		this->preturi = new float[p.nrZile];
		for (int i = 0; i < p.nrZile; i++) {
			this->preturi[i] = p.preturi[i];
		}
		return *this;
	}


	void print() {
		cout << "\n--------------------------------";
		cout << "\nDenumire: " << this->denumire;
		cout << "\nCod: " << this->cod;
		cout << "\nUnitate Masura: " << this->um;
		cout << "\nNr. Zile: " << this->nrZile;
		cout << "\nIstoric preturi: ";
		for (int i = 0; i < this->nrZile; i++) {
			cout << this->preturi[i] << " ";
		}
		cout << "\n--------------------------------";
	}


	 

	~Produs() {
		cout << "\nApel destr";
		delete[] this->preturi;
	}
};

Produs f1(Produs vp[10]) {
	Produs p(108);
	return p;
}

Produs& f2(Produs* vp, int nr) {
	return vp[7];
}

Produs& f3(Produs& p) {
	Produs p2(109);
	p2 = p;
	return p2; // crapa ca se distruge aici p2-ul alocat pe stack, se poate declara static p2 si practic e declarat global (adica pe heap)
}

Produs f4() {
	Produs p(102);
	return p;
}

int main() {
	Produs p1(102);
	p1.print();
	float preturi[] = { 10, 30, 40.5 };
	Produs p2(103, "Lapte", 3, preturi, UM::KILOGRAM);
	p2.print();
	Produs p3(p2);
	p3.print();

	Produs p4(106);
	p4 = p2;
	p4.print();
	p1 = p2 = p4; // p1.operator=(p2.operator=(p4));
	p1.print();

	p1 = p1;
	p1.print();

	cout << "\n----------------------------";
	cout << "\n-------------f4-------------";
	cout << "\n----------------------------";
	Produs p5 = f4(); //copy ellision, optimizare
	cout << "\n----------------------------";
	cout << "\n-------------f4'------------";
	cout << "\n----------------------------";
	p5 = f4();
 	return 0;

	/*
	tema
	clasa cu atribut const
	alocare dinamica de ceva
	si cu ce s-a mai facut azi
	operator = 
	destructors
	getteri
	setteri
	*/
}