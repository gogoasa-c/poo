#include <iostream>
#include <string>

using namespace std;

class Angajat {
	float salariu;
	friend ostream& operator << (ostream& out, const Angajat& a) {
		out << "\nNume: " << a.nume;
		out << "\nSalariu: " << a.salariu;
		return out;
	}
public:
	string nume;
	Angajat(float s = 2500.0, string n = "") : nume(n), salariu(s) {}


};

class Stud {
	int matricol = 100;
	double media = 10;
public:
	string nume = "Anonim doi";

	explicit operator double() {
		return media;
	}

	operator Angajat() {
		//return Angajat(3500.0, this->nume);
		Angajat aux(3500.0, this->nume);
		return aux;

	}

	Stud(int m = 100, string n = "Anonim", double med = 10) : matricol(m), nume(n), media(med) {

	}

	friend ostream& operator << (ostream& out, const Stud& s) {
		out << "\nMatricol: " << s.matricol;
		out << "\nMedia: " << s.media;
		out << "\nNume: " << s.nume;
		return out;
	}
};

int main() {
	Stud s1(123, "Popescu Ion", 7.50), s2;
	cout << s1;
	cout << "\nMedia celor 2 studenti: " << ((double)s1 + (double)s2) / 2;
	cout << endl;
	Angajat a1(3000.0, "Popa Ion");
	cout << a1;
	Angajat a2;
	a2 = (Angajat)s1;
	cout << a2;
}