#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
using namespace std;
/*
operator index, ++, cast, functie, unar

tema: supraincarcare << pentru un enum
*/

class Produs
{
	char* denumire = NULL;
	int nrZile = 0;
	float* preturi = NULL;
	int stoc = 0;

public:
	Produs(const char* denumire, int stoc)
	{
		this->denumire = new char[strlen(denumire) + 1];
		strcpy(this->denumire, denumire);
		this->stoc = stoc;
	}

	Produs(const Produs& p)
	{
		this->denumire = new char[strlen(p.denumire) + 1];
		strcpy(this->denumire, p.denumire);
		this->stoc = p.stoc;
		this->nrZile = p.nrZile;
		this->preturi = new float[this->nrZile];
		for (int i = 0; i < this->nrZile; i++)
			this->preturi[i] = p.preturi[i];
	}

	Produs& operator=(const Produs& p)
	{
		if (this != &p)
		{
			delete[] this->denumire;
			delete[] this->preturi;
			this->denumire = new char[strlen(p.denumire) + 1];
			strcpy(this->denumire, p.denumire);
			this->stoc = p.stoc;
			this->nrZile = p.nrZile;
			this->preturi = new float[this->nrZile];
			for (int i = 0; i < this->nrZile; i++)
				this->preturi[i] = p.preturi[i];
		}
		return *this;
	}
	//prefix ++
	Produs operator++() {
		++this->stoc;
		return *this; //returnam obiectul actual modificat;
	}

	//postfix ++
	Produs operator++(int) {
		Produs aux = *this;
		++this->stoc;
		return aux; //returnam starea anterioara modificarilor a obiectului curent
	}

	//cast to float
	operator float() {
		return this->preturi[this->nrZile - 1];
	}

	//cast explicit la int
	explicit operator int() {
		return this->stoc;
	}

	float operator()(int lower, int upper) {
		float average = 0;
		int counter = upper - lower + 1;
		for (int i = lower; i <= upper; i++) {
			average += this->preturi[i];
		}
		return average / counter;
	}

	float& operator[](int index) { //pt a permite si modificari, nu doar consulatare returnam o referinta la float
		if(index >=0 && index < this->nrZile) {
			return this->preturi[index];
		}
	}

	bool operator!() {
		if (this->preturi == nullptr && this->nrZile == 0) {
			return true;
		}
		return false;
	}

	friend ostream& operator<<(ostream& os, const Produs& p) {
		os << "\n----------<<----------";
		os << "\nDenumire: " << p.denumire;
		os << "\nStoc: " << p.stoc;
		os << "\nNr zile: " << p.nrZile;
		os << "\nIstoric preturi: ";
		for (int i = 0; i < p.nrZile; i++)
			os << p.preturi[i] << " ";
		os << "\n----------<<----------";
		return os;
	}

	friend istream& operator>>(istream& is, Produs& p) {
		delete[] p.denumire;
		delete[] p.preturi;
		cout << "\nIntroduceti denumire: ";
		char aux[100];
		is >> aux;
		p.denumire = new char[strlen(aux) + 1];
		strcpy(p.denumire, aux);
		cout << "\nIntroduceti stoc: ";
		is >> p.stoc;
		cout << "\nNumar zile: ";
		is >> p.nrZile;
		if (p.nrZile > 0) {
			p.preturi = new float[p.nrZile];
			for (int i = 0; i < p.nrZile; i++) {
				cout << "p[" << i << "]: ";
				is >> p.preturi[i];
			}
		}
		else {
			p.nrZile = 0;
			p.preturi = nullptr;
		}
		return is;
	}

	void setPreturi(float* preturi, int nrZile)
	{
		if (nrZile > 0 && preturi != NULL)
		{
			delete[] this->preturi;
			this->nrZile = nrZile;
			this->preturi = new float[this->nrZile];
			for (int i = 0; i < this->nrZile; i++)
				this->preturi[i] = preturi[i];
		}
	}

	void adaugaPret(float pretNou)
	{
		Produs p = *this;
		delete[] this->preturi;
		this->nrZile++;
		this->preturi = new float[this->nrZile];
		for (int i = 0; i < p.nrZile; i++)
			this->preturi[i] = p.preturi[i];
		this->preturi[this->nrZile - 1] = pretNou;
	}

	void afisare()
	{
		cout << "\n--------------------";
		cout << "\nDenumire: " << this->denumire;
		cout << "\nStoc: " << this->stoc;
		cout << "\nNr zile: " << this->nrZile;
		cout << "\nIstoric preturi: ";
		for (int i = 0; i < this->nrZile; i++)
			cout << this->preturi[i] << " ";
		cout << "\n--------------------";
	}

	~Produs()
	{
		delete[] this->denumire;
		delete[] this->preturi;
	}
};

int main()
{
	Produs p1("paine graham", 100);
	p1.afisare();
	p1.adaugaPret(8.5);
	p1.adaugaPret(8.7);
	p1.adaugaPret(9.1);
	p1.afisare();
	Produs p2(p1);
	p2.afisare();
	Produs p3("Produs", 0);
	p3 = p2;
	p3.afisare();

	float pret = p3[2];
	cout << "\nPret: " << pret; 

	p3[1] = 17.7;
	p3.afisare();

	p1=++p3;
	p1.afisare();
	p3.afisare();

	p1=p3++;
	p1.afisare();
	p3.afisare();

	float pretCurent;
	pretCurent = p3;
	cout << "\nPret curent: " << pretCurent;

	int stoc = (int)p3;

	/*int test;
	test = p1 + p3;
	test = 2 + p1;
	test += p2;*/

	float pretMediu = p3(0, 1);
	cout << "\nPret Mediu: " << pretMediu;
	//float valoare = p3();

	/*Produs* listaProduse;
	int nrProduse;
	bool found = p3(listaProduse, nrProduse);*/

	cout << p3;
	/*cin >> p3;
	cout << p3;*/

	int n = 2;
	if (!n) {
		cout << "\nn-ul e 0";
	}
	cout << "\n" << n;

	int a, b = 2;
	a = !b; //! nu modifica b
	cout << "\na: " << a << "\nb: " << b;

	p1 = !p3;
	cout << "\np1: " << p1 << "\np3:" << p3;

	return 0;
}