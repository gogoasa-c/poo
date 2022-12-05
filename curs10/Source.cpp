#include <iostream>
using namespace std;

class Pers {
	double salariu = 0;
protected:
	int marca = 100;
public:
	string nume = "";
	Pers(int m = 0, string n = "noname", double s = 2000) : marca(m), nume(n), salariu(s) {

	}
	friend ostream& operator<<(ostream& out, const Pers& p) {
		out << p.marca << '\t' << p.nume << '\t' << p.salariu;
		return out;
	}

	virtual double calculSalariu() {
		cout << "\nCalcul salariu din Pers: ";
		return salariu;
	}
};

class Muncitor : Pers {
	int nrPiese;
	float manPiesa; //bani/piesa
public:
	Muncitor(int m = 100, string n = "", double s = 2550, int nrP = 0, float manP = 100) : Pers(m, n, s), nrPiese(nrP), manPiesa(manP) {

	}

	Muncitor(const Muncitor& m) : Pers((Pers)m), nrPiese(m.nrPiese), manPiesa(m.manPiesa) {

	}

	friend ostream& operator<<(ostream& out, const Muncitor& m) {
		out << (Pers)m;
		out << '\t' << m.nrPiese << " x " << m.manPiesa << " = " << m.nrPiese * m.manPiesa;
		return out;
	}

	Muncitor(Muncitor& m): Pers(m) {
		nrPiese = m.nrPiese;
		manPiesa = m.manPiesa;
	}

	Muncitor& operator = (const Muncitor& m){
		if (this == &m) {
			exception* p = new exception("\nEroare de auto-asignare!");
			cerr << p->what();
			throw *p;
			return *this;
		}
		Pers::operator=(m); // ne folosim de operatorul = implicit pus de compilator din clasa de baza
		nrPiese = m.nrPiese; // restul le copiem normal ca avem acces
		manPiesa = m.manPiesa;		
		return *this;
	}

	double calculSalariu() {
		cout << "\nCalcul salariu din Muncitor: ";
		return nrPiese * manPiesa;
	}


};

double f2(int i) {
	return i / 2.;
}

double f3(int i) {
	return i / 3.;
}

int main() {
	Pers p1(101, "Ion Popescu", 2500.0);
	cout << p1;
	Muncitor m1(210, "Danciu Laura", 5400, 3, 275);
	cout << endl << m1;
	Muncitor m2(m1);
	cout << endl << m2;
	Muncitor m3; 
	cout << endl << "Muncitor Default: " << m3;
	m3 = m2;
	cout << endl << "Muncitor op= : " << m3;
	//m2 = m2;
	Pers* pp;
	pp = &p1;
	cout << pp->calculSalariu();
	pp = (Pers*)&m1;
	cout << pp->calculSalariu();
	//vector de pointer la functii
	double (*vpf[2])(int) = {f2, f3};
	cout << "\nValoare f3: " << vpf[1](10);
	cout << "\nValoare f2: " << vpf[0](10);
}