#include<iostream>
#include<fstream>
using namespace std;


//fisiere text, relatia has a = compunere, try-catch
class Cadou {
private:
	string denumire = "Anonim";
	float pret = 0;

public:
	Cadou()
	{
	}

	Cadou(string denumire, float pret)
	{
		this->denumire = denumire;
		this->pret = pret;
	}

	Cadou(const Cadou& c)
	{
		this->denumire = c.denumire;
		this->pret = c.pret;
	}

	Cadou& operator=(const Cadou& c)
	{
		this->denumire = c.denumire;
		this->pret = c.pret;
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Cadou& c)
	{
		out << "\nDenumire: " << c.denumire << ", pret: " << c.pret;
		return out;
	}
	friend istream& operator>>(istream& in, Cadou& c)
	{
		cout << "Introduceti denumire: ";
		in >> c.denumire;
		cout << "Introduceti pret: ";
		in >> c.pret;
		return in;
	}
};

class WishList {
	string detinator = "N/A";
	int nrCadouri = 0;
	Cadou** listaCadouri = nullptr; // * - alocare dinamica, ** - alocare dinamica de pointeri
public:
	WishList(){}

	WishList(string detinator, int nrCadouri, Cadou** listaCadouri) {
		this->detinator = detinator;
		if (nrCadouri <= 0 || listaCadouri == nullptr) {
			return;
		}
		this->nrCadouri = nrCadouri;
		this->listaCadouri = new Cadou*[this->nrCadouri]; // - alocam dinamic un vector alocat dinamic de pointeri la obiecte
		for (int i = 0; i < this->nrCadouri; i++) {
			this->listaCadouri[i] = new Cadou(*listaCadouri[i]);
		}
	}

	WishList(const WishList& w) {
		this->detinator = w.detinator;
		if (w.nrCadouri <= 0 || w.listaCadouri == nullptr) {
			return;
		}
		this->nrCadouri = w.nrCadouri;
		this->listaCadouri = new Cadou * [this->nrCadouri]; // - alocam dinamic un vector alocat dinamic de pointeri la obiecte
		for (int i = 0; i < this->nrCadouri; i++) {
			this->listaCadouri[i] = new Cadou(*w.listaCadouri[i]);
		}
	}

	WishList operator=(const WishList& w) {
		if (this == &w) {
			return *this;
		}

		if (w.nrCadouri <= 0 || w.listaCadouri == nullptr) {
			this->nrCadouri = 0;
			this->listaCadouri = nullptr;
			return *this;
		}

		for (int i = 0; i < this->nrCadouri; i++) {
			delete this->listaCadouri[i];
		}
		delete[] this->listaCadouri;
		this->detinator = w.detinator;
		this->nrCadouri = w.nrCadouri;
		this->listaCadouri = new Cadou * [this->nrCadouri]; // - alocam dinamic un vector alocat dinamic de pointeri la obiecte
		for (int i = 0; i < this->nrCadouri; i++) {
			this->listaCadouri[i] = new Cadou(*w.listaCadouri[i]);
		}

		return *this;
	}

	friend ostream& operator << (ostream& o, const WishList& w) {
		o << "\nDetinator: " << w.detinator;
		o << "\nNr. Cadouri: " << w.nrCadouri;
		o << "\nCadouri:";
		for (int i = 0; i < w.nrCadouri; i++) {
			o << *w.listaCadouri[i];
		}
		return o;
	}


	~WishList() {
		for (int i = 0; i < this->nrCadouri; i++) {
			delete this->listaCadouri[i];
		}
		delete[] this->listaCadouri;
	}
};


int main()
{
	Cadou c1("carte", 100);
	Cadou c2("stilou", 600);
	Cadou c3("palarie", 324);
	Cadou* listaC[] = { &c1, &c2, &c3 };
	WishList w1;
	WishList w2("nume", 3, listaC);
	cout << w1 << "\n";
	cout << w2 << "\n";
	WishList w3(w2);
	cout << w3 << "\n";
	w1 = w3;
	cout << w1 << "\n";

	return 0;
}
