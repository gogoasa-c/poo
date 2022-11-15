#include<iostream>
#include<fstream>
using namespace std;

//alternativ la exceptii
class CustomExecption {
	string mesaj;
public:
	CustomExecption(string mesaj) {
		this->mesaj = mesaj;
	}
	string getMesaj() {
		return this->mesaj;
	}
};

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

	void setPret(float pret) {
		if (pret < 0) {
			throw new exception("Pretul este invalid!"); //arunca un pointer la exception
		}
		this->pret = pret;
	}


	friend ostream& operator<<(ostream& out, const Cadou& c)
	{
		out << "\nDenumire: " << c.denumire << ", pret: " << c.pret;
		return out;
	}

	friend ofstream& operator<<(ofstream& out, const Cadou& c)
	{
		out << c.denumire << "\n" << c.pret;
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

	friend ifstream& operator>>(ifstream& in, Cadou& c)
	{
		in >> c.denumire;
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

//tema pentru peste 2 saptamani: clasa WishList2 = vector static de Cadou* 
//clasa WishList3 = vector dinamic de Cadou
//clasa WishList4 = vector static de Cadou
//constructori de toate tipurilor, <<, >> pt ostream istream si ofstream ifstream si tot ce am facut pe aici + 2 rapoarte text = probleme simple pe baza datelor de aici
//optional: istream overloading care poate sa citeasca un const; hint: pointer
class WishList5 { 
	string detinator;
	Cadou* cadouSpecial;
	int nrPrieteni;
	Cadou*** listaCadouri; //matrice de pointeri la cadou de tip zig zag = differing lengths of columns
	int* nrCadouriPrieteni;
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

	ofstream g("fisier.txt");
	g << c1; // ofstream is a ostream
	g.close();

	ifstream f("fisier.txt");
	Cadou c4;
	f >> c4;
	cout << "\n" << c4 << "\n";


	try{
		c1.setPret(-120);
		cout << c1;
	}
	catch (exception *e) {
		cout << e->what();
	}
	


	return 0;
}
