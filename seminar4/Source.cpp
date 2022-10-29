#include <iostream>
using namespace std;


/*
tema
1. de ce impl asta de copy constr nu e totally safe?

2. alegem o clasa cu:
1 string
1 vector alocat dinamic de stringuri - string
constructori de toate felurile
afisare
destructor
setteri si getteri
exempl in main

next time operatorul =

*/
class Student {
	string nume = "Anonim";
	int nrNote = 0;
	int* note = nullptr;
public:
	Student() {
		cout << "\n Apel constr fara param";
	}

	Student(string nume, int nrNote, int* note) {
		this->nume = nume;
		cout << "\n Apel constr cu toti param";
		if (nrNote < 0 || note==NULL) {
			return;
		}
		this->nrNote = nrNote;
		this->note = new int[this->nrNote];
		for (int i = 0; i < nrNote; i++) {
			this->note[i] = note[i];
		}
	}

	Student(const Student& s) {
		cout << "\nApel copy constr";
		this->nume = s.nume;
		if (s.nrNote < 0 || s.note == nullptr) {
			return;
		}
		this->nrNote = s.nrNote;
		note = new int[nrNote];
		for (int i = 0; i < this->nrNote; i++) {
			this->note[i] = s.note[i];
		}
	}

	void afisare() {
		cout << "\n-----------------------\nNume: "<< this->nume;
		if (this->nrNote == 0) {
			cout << "\nNote: -";
		}
		else {
			cout << "\nNr. note: " << this->nrNote;
			cout << "\nLista note: ";
			for (int i = 0; i < this->nrNote; i++) {
				cout << this->note[i] << " ";
			}
		}
	}

	~Student() {
		cout << "\nApel destructor";
		delete[] this->note;
	}
};


int main() {
	int* a = new int[3];
	for (int i = 0; i < 3; i++) {
		a[i] = i - 1;
	}
	Student s1("Gigel", 3, a);
	Student s2;
	s1.afisare();
	s2.afisare();

	Student* ps1;
	ps1 = new Student();
	Student* ps2;
	ps2 = new Student[5];
	Student* ps3;
	ps3 = &s1;

	Student s3 = s1;
	s3.afisare();

	delete ps1;
	delete[] ps2;

	return 0;
}