#include<iostream>
#include<string>
using namespace std;

//TEMA: De implementat o clasa de baza si 2 derivate. De implementat "must-ul" in clase.
//De adaugat o metoda virtuala si de exemplificat virtualizarea in main pe baza unui vector de pointeri la clasa de baza
//TEMA OPTIONALA: De virtualizat conceptul de cout.

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
	int vechime = 0;
	int nrLocuriMunca = 0;
	string* locuriMunca = NULL;
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

class Profesor : public Angajat
{
	Grad gradDidactic = Grad::ASIST;
	int nrOreSuplimentare = 0;

public:
	Profesor()
	{
		cout << "\nCONSTRUCTOR FARA PARAM PROFESOR";
	}

	Profesor(string n, int v, int nrL, string* lM, float s, Grad g, int nrO) :Angajat(n, v, nrL, lM, s)
	{
		cout << "\nCONSTRUCTOR CU PARAM PROFESOR";
		this->gradDidactic = g;
		this->nrOreSuplimentare = nrO;
	}

	Profesor(const Profesor& p) :Angajat(p)//apel copy constr din clasa Angajat + upcast de la Profesor la Angajat
	{
		cout << "\nCONSTRUCTOR COPIERE PROFESOR";
		this->gradDidactic = p.gradDidactic;
		this->nrOreSuplimentare = p.nrOreSuplimentare;
	}

	Profesor& operator=(const Profesor& p)
	{
		Angajat::operator=(p);
		cout << "\nOPERATOR = PROFESOR";
		this->gradDidactic = p.gradDidactic;
		this->nrOreSuplimentare = p.nrOreSuplimentare;
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Profesor& p)
	{
		out << (Angajat)p;
		out << "\nGrad didactic: " << p.gradDidactic;
		out << "\nNr ore suplimentare: " << p.nrOreSuplimentare;
		return out;
	}

	~Profesor()
	{
		cout << "\nDESTRUCTOR PROFESOR";
	}

	float calculSalariu()
	{
		return this->salariu + this->nrOreSuplimentare * 15;
	}
};

int main()
{
	Profesor p1;
	string lista[] = { "CNCV","ASE" };
	Angajat a("Costelus", 10, 2, lista, 5000);
	Profesor p2("Gigel", 5, 2, lista, 4000, Grad::LECT, 15);
	Profesor p3 = p2;

	cout << "\nTESTARE METODA DE CALCUL SALARIU:";
	cout << "\n" << a.calculSalariu();
	cout << "\n" << p2.calculSalariu();

	//upcast pe obiecte
	Angajat a2;
	a2 = p3;
	cout << "\nSalariu angajat fost profesor prin upcast: " << a2.calculSalariu();
	//calcul salarii angajati ASE
	Angajat listaAngajati[] = { a,p2,p3 };



	return 0;
}