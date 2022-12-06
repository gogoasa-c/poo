#include<iostream>
#include<string>
using namespace std;

//tema: 
//alegeti o clasa de baza cu 2 derivate - animal + caine, pisica
//alocare dinamica in clasa de baza si in una din cele 2 derivate
//implementare de istream


enum Grad
{
	ASIST = 1,
	LECT = 2, 
	CONF = 3, 
	PROF = 4
};

class Angajat
{
private:
	string nume = "Anonim";
protected:
	int vechime = 0; // ani
	int nrLocuriMunca = 0; // anterioare
	string* locuriMunca = NULL; // unde a lucrat 
	float salariu = 0;

public:
	Angajat()
	{
		cout << "\nCONSTRUCTOR FARA PARAM ANGAJAT";
	}

	Angajat(string nume, int vechime, int nrLocuriMunca, string* locuriMunca, float salariu)
	{
		cout << "\nCONSTRUCTOR CU PARAM ANGAJAT";
		this->nume = nume;
		this->vechime = vechime;
		this->salariu = salariu;
		if (locuriMunca != NULL && nrLocuriMunca != 0)
		{
			this->nrLocuriMunca = nrLocuriMunca;
			this->locuriMunca = new string[this->nrLocuriMunca];
			for (int i = 0; i < this->nrLocuriMunca; i++)
				this->locuriMunca[i] = locuriMunca[i];
		}
	}

	Angajat(const Angajat& a)
	{
		cout << "\nCONSTRUCTOR COPIERE ANGAJAT";
		this->nume = a.nume;
		this->vechime = a.vechime;
		this->salariu = a.salariu;
		if (a.locuriMunca != NULL && a.nrLocuriMunca > 0)
		{
			this->nrLocuriMunca = a.nrLocuriMunca;
			this->locuriMunca = new string[this->nrLocuriMunca];
			for (int i = 0; i < this->nrLocuriMunca; i++)
				this->locuriMunca[i] = a.locuriMunca[i];
		}
	}

	Angajat& operator=(const Angajat& a)
	{
		cout << "\nOPERATOR = ANGAJAT";
		this->nume = a.nume;
		this->vechime = a.vechime;
		this->salariu = a.salariu;
		delete[] this->locuriMunca;
		if (a.locuriMunca != NULL && a.nrLocuriMunca > 0)
		{
			this->nrLocuriMunca = a.nrLocuriMunca;
			this->locuriMunca = new string[this->nrLocuriMunca];
			for (int i = 0; i < this->nrLocuriMunca; i++)
				this->locuriMunca[i] = a.locuriMunca[i];
		}
		else
		{
			this->nrLocuriMunca = 0;
			this->locuriMunca = NULL;
		}
		return *this;
	}

	~Angajat()
	{
		cout << "\nDESTRUCTOR ANGAJAT";
		delete[] this->locuriMunca;
	}


	friend ostream& operator<<(ostream& out, const Angajat& a)
	{
		out << "\nNume: " << a.nume;
		out << "\nVechime: " << a.vechime;
		out << "\nSalariu: " << a.salariu;
		if (a.locuriMunca != NULL)
		{
			out << "\nLocuri munca: ";
			for (int i = 0; i < a.nrLocuriMunca; i++)
				out << a.locuriMunca[i] << ", ";
		}
		return out;
	}

	float calculSalariu()
	{
		return this->salariu;
	}
};


//relatie is a
class Profesor: public Angajat {
	Grad gradDidactic = Grad::ASIST;
	int nrStudentiCoordonati = 0;
public:
	Profesor(): Angajat() {
		cout << "\nCONSTRUCTOR FARA PARAM PROFESOR";
	}

	Profesor(string n, int v, int nrL, string* l, float s, Grad gradDidactic, int nrStudentiCoordonati): Angajat(n, v, nrL, l, s) {
		cout << "\nCONSTRUCTOR CU PARAM PROFESOR";
		this->gradDidactic = gradDidactic;
		this->nrStudentiCoordonati = nrStudentiCoordonati;
	}

	Profesor(Angajat a, Grad g, int nrStud): Angajat(a) {
		cout << "\nCONSTRUCTOR CU PARAM 2 PROFESOR";
		this->gradDidactic = gradDidactic;
		this->nrStudentiCoordonati = nrStudentiCoordonati;
	}

	Profesor(const Profesor& p): Angajat(p) {
		cout << "\nCONSTRUCTOR COPIERE PROFESOR";
		this->gradDidactic = p.gradDidactic;
		this->nrStudentiCoordonati = p.nrStudentiCoordonati;
	}

	Profesor& operator=(const Profesor& p) {
		cout << "\nOPERATOR = PROFESOR";
		if (this == &p) {
			return *this;
		}
		//(Angajat)(*this) = (Angajat)p;
		/*this->*/Angajat::operator=(p);
		this->gradDidactic = p.gradDidactic;
		this->nrStudentiCoordonati = p.nrStudentiCoordonati;
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Profesor& p) {
		out << (Angajat)p;
		out << "\nGrad didactic: " << p.gradDidactic;
		out << "\nNr. Studenti Coordonati: " << p.nrStudentiCoordonati;
		return out;
	}

	~Profesor() {
		cout << "\nDESTRUCTOR PROFESOR";
	}
};

int main()
{
	Profesor p1;
	Profesor p2("Gigel", 10, 0, nullptr, 4000.50, Grad::ASIST, 4);
	Angajat a("Costel", 5, 0, nullptr, 5000.);
	Profesor p3(a, Grad::ASIST, 0);
	Profesor p4 = p3;
	p1 = p4;
	cout << p1;
	return 0;
}