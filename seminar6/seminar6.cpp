#include <iostream>
using namespace std;

class Student
{
	const int codMatricol;

	string nume = "Anonim";
	int nrNote = 0;
	int* note = NULL;
	float soldCont = 0;
	static float taxaRestanta;

public:
	Student(int codMatricol) :codMatricol(codMatricol)
	{
		cout << "\nApel constructori cu 1 param";

	}

	Student(int codMatricol, string nume, int nrNote, int* note) :codMatricol(codMatricol)
	{
		cout << "\nApel constructori cu toti param";
		this->nume = nume;

		if (nrNote > 0 && note != NULL)
		{
			this->nrNote = nrNote;
			this->note = new int[this->nrNote];
			for (int i = 0; i < this->nrNote; i++)
				this->note[i] = note[i];
		}

	}

	Student(const Student& s) :codMatricol(s.codMatricol)
	{
		cout << "\nApel constructori de copiere";
		this->nume = s.nume;

		if (s.nrNote > 0 && s.note != NULL)
		{
			this->nrNote = s.nrNote;
			this->note = new int[this->nrNote];
			for (int i = 0; i < this->nrNote; i++)
				this->note[i] = s.note[i];
			this->soldCont = s.soldCont;
		}

	}

	Student& operator=(const Student& s) {
		if (this != &s) {
			delete[] this->note;
			this->nume = s.nume;
			if (s.nrNote > 0 && s.note != NULL)
			{
				this->nrNote = s.nrNote;
				this->note = new int[this->nrNote];
				for (int i = 0; i < this->nrNote; i++)
					this->note[i] = s.note[i];
				this->soldCont = s.soldCont;
			}
		}
		return *this;
	}

	Student& operator+=(int newNota) {
		Student copie = *this;
		delete[] this->note;
		++this->nrNote;
		this->note = new int[this->nrNote];
		for (int i = 0; i < copie.nrNote; i++) {
			this->note[i] = copie.note[i];
		}
		this->note[this->nrNote - 1] = newNota;
		return *this;
	}

	Student operator+(int newNota) {
		Student rez = *this;//LUCRAM CU REZ, NU CU THIS
		rez += newNota;
		return rez;
	}

	bool operator>(Student s) {
		return this->soldCont > s.soldCont;
	}

	//transf prin valoare doar daca fac consultare
	//transf prin referinta daca fac si modificari
	int& operator[](int index) {
		if (index >= 0 && index < this->nrNote) {
			return this->note[index];
		}
	}


	void afisare()
	{
		cout << "\n-----------------";
		cout << "\nCod matricol: " << this->codMatricol;
		cout << "\nNume: " << this->nume;
		cout << "\nSold cont: " << this->soldCont;
		cout << "\nNr Note: " << this->nrNote;
		cout << "\nLista Note: ";
		for (int i = 0; i < this->nrNote; i++)
			cout << this->note[i] << " ";
		cout << "\n-------------";
	}

	float calculTotalTaxeRestante() {
		int count = 0;
		for (int i = 0; i < this->nrNote; i++) {
			if (this->note[i] < 5) {
				count++;
			}
		}
		return count * Student::taxaRestanta;
	}

	bool poatePlatiToateRestantele() {
		return this->soldCont >= calculTotalTaxeRestante();
	}

	void alimentareSold(int suma) {
		if(suma>0)
		{
			this->soldCont += suma;
		}
	}

	void retragereSold(int suma) {
		if (suma > 0 && this->soldCont >= suma) {
			this->soldCont -= suma;
		}
	}

	static float getTaxaRestanta() {
		return Student::taxaRestanta;
	}

	static void setTaxaRestanta(float newTaxaRestanta) {
		if (newTaxaRestanta > 0) {
			Student::taxaRestanta = newTaxaRestanta;
		}
	}

	~Student()
	{
		cout << "\nApel destructor";
		delete[] this->note;

	}	

	friend Student operator+(int newNota, Student s) {
		//return s + newNota; v1

		Student rez = s;
		rez += newNota;
		return rez;

		//cu get si set

		//cu friend

	}
};



float Student::taxaRestanta = 75;

//Student operator+(int newNota, Student s) { am mutat-o inline
//	//return s + newNota; v1
//
//	Student rez = s;
//	rez += newNota;
//	return rez;
//
//	//cu get si set
//
//	//cu friend
//
//}

int main()
{
	Student s1(1001);
	int note[] = { 6,8,10 };
	Student s2(1002, "Gigel", 3, note);
	Student s3(s2);
	s1 = s2;
	s1.afisare();
	s1.alimentareSold(200);
	s1.afisare();
	s1.retragereSold(50);
	s1.afisare();
	cout << "\nTaxa restanta: " << Student::getTaxaRestanta();
	Student::setTaxaRestanta(100);
	cout << "\nTaxa restanta: " << Student::getTaxaRestanta();

	s3 += 10; //adaugam o nota in plus la sfarsitul vectorului de note
	s3.afisare();

	//tema: s3 -= 2; elimina ultimele 2 note
	//tema: s3 -=5; elimina toate notele de 5 

	Student s4(101);
	s4 = s3 + 5; //s4.operator=(s3.operator+(5))
	s4.afisare();

	Student s5(10001);
	s5 = 5 + s3;//s5.operator=(operator+(5, s3))
	
	if (s1 > s2) {
		cout << "\nStudent s1 are un sold cont > ca s2";
	}
	else {
		cout << "\nInvers";
	}

	int nota = s5[2];
	cout << "\nNota: " << nota;
	s5[2] = 9;
	cout << "\nNota: " << nota;

	//tema clasa cu supraincarcari de operatori +, =, +=, [], <, >, <=, >=, etc.

	return 0;

}