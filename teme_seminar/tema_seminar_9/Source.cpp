#include<iostream>
#include<fstream>
#include <string>
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
	WishList() {}

	WishList(string detinator, int nrCadouri, Cadou** listaCadouri) {
		this->detinator = detinator;
		if (nrCadouri <= 0 || listaCadouri == nullptr) {
			return;
		}
		this->nrCadouri = nrCadouri;
		this->listaCadouri = new Cadou * [this->nrCadouri]; // - alocam dinamic un vector alocat dinamic de pointeri la obiecte
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
//constructori de toate tipurile, <<, >> pt ostream istream si ofstream ifstream si tot ce am facut pe aici + 2 rapoarte text = probleme simple pe baza datelor de aici
//optional: istream overloading care poate sa citeasca un const; hint: pointer

class WishList4{
	Cadou cadouri[100];
	string detinator;
	int nrCadouri;
public:
	WishList4(string newDetinator = "N/A", Cadou* newCadouri = nullptr, int newNrCadouri = 0) : detinator(newDetinator) {
		if (newNrCadouri < 0) {
			cout << "\nInput invalid\n";
			return;
		}
		this->nrCadouri = newNrCadouri;
		for (int i = 0; i < this->nrCadouri; i++) {
			this->cadouri[i] = newCadouri[i];
		}
	}

	WishList4(const WishList4& w) : detinator(w.detinator) {
		if (w.nrCadouri < 0) {
			cout << "\nInput invalid\n";
			return;
		}
		this->nrCadouri = w.nrCadouri;
		for (int i = 0; i < this->nrCadouri; i++) {
			this->cadouri[i] = w.cadouri[i];
		}
	}

	WishList4& operator=(const WishList4& w) {
		if (this == &w) {
			return *this;
		}
		if (w.nrCadouri < 0 || w.cadouri == nullptr) {
			cout << "\nInput invalid\n";
			return *this;
		}
		this->detinator = w.detinator;
		this->nrCadouri = w.nrCadouri;
		for (int i = 0; i < this->nrCadouri; i++) {
			this->cadouri[i] = w.cadouri[i];
		}
		return *this;
	}

	~WishList4() {
		
	}
};

class WishList3 {
	Cadou* cadouri;
	string detinator;
	int nrCadouri;
public:
	WishList3(string newDetinator = "N/A", Cadou* newCadouri = nullptr, int newNrCadouri = 0): detinator(newDetinator) {
		if (newNrCadouri < 0 || newCadouri == nullptr) {
			cout << "\nInput invalid\n";
			return;
		}
		this->nrCadouri = newNrCadouri;
		this->cadouri = new Cadou[this->nrCadouri];
		for (int i = 0; i < this->nrCadouri; i++) {
			this->cadouri[i] = newCadouri[i];
		}
	}

	WishList3(const WishList3& w): detinator(w.detinator) {
		if (w.nrCadouri < 0 || w.cadouri == nullptr) {
			cout << "\nInput invalid\n";
			return;
		}
		this->nrCadouri = w.nrCadouri;
		this->cadouri = new Cadou[this->nrCadouri];
		for (int i = 0; i < this->nrCadouri; i++) {
			this->cadouri[i] = w.cadouri[i];
		}
	}

	WishList3& operator=(const WishList3& w) {
		if (this == &w) {
			return *this;
		}
		if (w.nrCadouri < 0 || w.cadouri == nullptr) {
			cout << "\nInput invalid\n";
			return *this;
		}
		this->detinator = w.detinator;
		this->nrCadouri = w.nrCadouri;
		delete[] this->cadouri;
		this->cadouri = new Cadou[this->nrCadouri];
		for (int i = 0; i < this->nrCadouri; i++) {
			this->cadouri[i] = w.cadouri[i];
		}
		return *this;
	}

	~WishList3() {
		delete[] this->cadouri;
	}
};


class WishList2 {
	string detinator;
	Cadou* cadouri[50];
	int nrCadouri;
public:
	WishList2(): detinator("N/A"), nrCadouri(0) {
		for (int i = 0; i < 50; i++) {
			cadouri[i] = nullptr;
		}
	}
	WishList2(string newDetinator, Cadou* newCadouri[], int newNrCadouri) : detinator(newDetinator) {
		if (newNrCadouri < 0) {
			cout << "\nNr. Invalid de cadouri\n";
			return;
		}
		this->nrCadouri = newNrCadouri;
		for (int i = 0; i < this->nrCadouri; i++) {
			this->cadouri[i] = new Cadou(*newCadouri[i]);
		}
	}
	
	WishList2(const WishList2& w) {
		if (w.nrCadouri < 0) {
			cout << "\nNr. Invalid de cadouri\n";
			return;
		}
		this->detinator = w.detinator;
		this->nrCadouri = w.nrCadouri;
		for (int i = 0; i < this->nrCadouri; i++) {
			this->cadouri[i] = new Cadou(*w.cadouri[i]);
		}
	}
	
	WishList2& operator=(const WishList2& w) {
		if (w.nrCadouri < 0) {
			cout << "\nNr. Invalid de cadouri\n";
			return *this;
		}
		this->detinator = w.detinator;
		this->nrCadouri = w.nrCadouri;
		for (int i = 0; i < this->nrCadouri; i++) {
			if (this->cadouri[i] != nullptr) {
				delete this->cadouri[i];
			}
			this->cadouri[i] = new Cadou(*w.cadouri[i]);
		}
		return *this;
	}
//constructori de toate tipurile, <<, >> pt ostream istream si ofstream ifstream si tot ce am facut pe aici 
//+ 2 rapoarte text = probleme simple pe baza datelor de aici

	friend ostream& operator<<(ostream& out, const WishList2& w) {
		out << "\nDetinator WishList: " << w.detinator;
		out << "\nNr. Cadouri: " << w.nrCadouri;
		out << "\nCadouri: ";
		for (int i = 0; i < w.nrCadouri; i++) {
			out << *w.cadouri[i] << " ";
		}
		return out;
	}
	friend istream& operator>>(istream& in, WishList2& w) {
		cout << "\nDetinator WishList: ";
		in >> w.detinator;
		cout << "\nNr. Cadouri: ";
		in >> w.nrCadouri;
		cout << "\nCadouri: ";
		for (int i = 0; i < w.nrCadouri; i++) {
			in >> *w.cadouri[i];
		}
		return in;
	}

	friend ofstream& operator<<(ofstream& out, const WishList2& w) {
		out << w.detinator << " ";
		out << w.nrCadouri << " ";
		for (int i = 0; i < w.nrCadouri; i++) {
			out << *w.cadouri[i] << " ";
		}
		out << "\n";
		return out;
	}
	friend ifstream& operator>>(ifstream& in, WishList2& w) {
		in >> w.detinator;
		in >> w.nrCadouri;
		for (int i = 0; i < w.nrCadouri; i++) {
			in >> *w.cadouri[i];
		}
		return in;
	}

	~WishList2() {
		for (int i = 0; i < this->nrCadouri; i++) {
			delete this->cadouri[i];
		}
	}
};


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

	
	//g << c1; // ofstream is a ostream
	//g.close();

	
	Cadou c4;
	//f >> c4;
	//cout << "\n" << c4 << "\n";


	try {
		c1.setPret(-120);
		cout << c1;
	}
	catch (exception* e) {
		cout << e->what();
	}
	string n = "ion";
	Cadou* listAlocDin[10];
	listAlocDin[0] = new Cadou(c1);
	listAlocDin[1] = new Cadou(c2);
	listAlocDin[2] = new Cadou(c3);
	WishList2 a;
	WishList2 b(n, listAlocDin, 3); //nu functioneaza
	WishList2 c(b);
	a = b;
	Cadou cadouri[] = { c1, c3, c2 };
	WishList3 ww1(n, cadouri, 3);
	WishList3 ww2(ww1);
	ww1 = ww2;

	WishList4 ww3(n, cadouri, 3);
	WishList4 ww4(ww3);
	WishList4 ww5;
	ww5 = ww3;

	//cin >> a;
	//cout << a;
	ofstream g("fis.txt");
	ifstream f("fis.txt");

	//g << a;
	f >> a;
	g << a;
	f.close();
	g.close();
	return 0;
}
