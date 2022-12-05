#include <iostream>
using namespace std;

class Pers {
	double salariu = 0;
protected:
	int marca = 100;
public:
	string nume = "";
	Pers(int m = 0, string n = "noname", double s = 2000): marca(m), nume(n), salariu(s) {

	}
	friend ostream& operator<<(ostream& out, const Pers& p) {
		out << p.marca << '\t' << p.nume << '\t' << p.salariu;
		return out;
	}
};

class Muncitor: Pers {
	int nrPiese;
	float manPiesa; //bani/piesa
public:
	Muncitor(int m = 100, string n = "", double s = 2550, int nrP = 0, float manP = 100) : Pers(m, n, s), nrPiese(nrP), manPiesa(manP) {

	}

	Muncitor(const Muncitor& m): Pers((Pers)m), nrPiese(m.nrPiese), manPiesa(m.manPiesa) {

	}

	friend ostream& operator<<(ostream& out, const Muncitor& m) {
		out << (Pers)m;
		out << '\t' << m.nrPiese << " x " << m.manPiesa << " = " << m.nrPiese * m.manPiesa;
		return out;
	}

};


int main() {
	Pers p1(101, "Ion Popescu", 2500.0);
	cout << p1;
	Muncitor m1(210, "Danciu Laura", 5400, 3, 275);
	cout << endl << m1;
	Muncitor m2(m1);
	cout << endl << m2;
}