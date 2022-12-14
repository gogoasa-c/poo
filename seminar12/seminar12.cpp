#include<iostream>
#include<string>
#include <fstream>
using namespace std;

//TEMA: De implementat o clasa de baza si 2 derivate. De implementat "must-ul" in clase.
//De adaugat o metoda virtuala si de exemplificat virtualizarea in main pe baza unui vector de pointeri la clasa de baza
//TEMA OPTIONALA: De virtualizat conceptul de cout.

//TEMA1: clasa de baza(min 1 met virtuala + un atribut alocat dinamic) + 2 derivate (1 clasa are minim un atribut alocat dinamic); o clasa tip colectie (has a)
//in care sa se evidentieze virtualizarea ( vector de pointeri la obj din tipul de baza)

//TEMA2:
class Clasa {
	string atributString;
	char atributChar;
	char* atributChar2;
	char atributSirCaracter[100];
	int atributInt;
	int* atributVectorDinamicInt;
	enum enumeratie;
	float atributVectorStatic[100];


};
//TEMA3: Cum virtualizam scrierea folosind cout
//TEMA4: Sa se realizeze virtualizarea pt citirea si scrierea in/din fisiere binare.
class iFile { // i de la interface; clasa abstracta 
	virtual void writeToFile(fstream& f) = 0; // virtual pure method
	virtual void readFromFile(fstream& f) = 0;
};

enum Grad
{
	ASIST = 1, LECT = 2, CONF = 3, PROF = 4
};

class Angajat : public iFile
{
private:
	string nume = "Anonim";
protected:
	int vechime = 0;
	int nrLocuriMunca = 0;
	string* locuriMunca = NULL;
	float salariu = 0;

public:

	virtual void writeToFile(fstream& f) {
		//scriere nume
		//scriere lungime sir
		int lg = this->nume.size() + 1; 
		//f.write((char*)&(lg), sizeof(int)); // adresa, apoi sizeof
		f.write((char*)&lg, sizeof(int));
		//nume
		f.write(this->nume.data(), lg);
		//vechime
		f.write((char*)&this->vechime, sizeof(int));
		//nrlocuri munca
		f.write((char*)&this->nrLocuriMunca, sizeof(int));
		//locuri munca vector
		for (int i = 0; i < this->nrLocuriMunca; i++){
			lg = this->locuriMunca[i].size() + 1;
			f.write((char*)&lg, sizeof(int));
			f.write(this->locuriMunca[i].data(), lg);
		}

		//scriere salariu
		f.write((char*)&this->salariu, sizeof(float));

	}

	virtual void readFromFile(fstream& f) {
		//citire nume
		int lg;
		f.read((char*)&lg, sizeof(int));
		char* buffer = new char[lg];
		f.read(buffer, lg);
		this->nume = buffer;
		delete[] buffer;
		f.read((char*)&this->vechime, sizeof(int));
		delete[] this->locuriMunca;
		f.read((char*)&this->nrLocuriMunca, sizeof(int));
		this->locuriMunca = new string[this->nrLocuriMunca];
		for (int i = 0; i < this->nrLocuriMunca; i++) {
			f.read((char*)&lg, sizeof(int));
			buffer = new char[lg];
			f.read(buffer, lg);
			this->locuriMunca[i] = buffer;
			delete[] buffer;
		}
		f.read((char*)&this->salariu, sizeof(float));

	}

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

	virtual float calculSalariu()
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
		return Angajat::calculSalariu() + this->nrOreSuplimentare * 15;
	}
};

int main()
{
	string lista[] = { "CNCV","ASE" };
	Angajat a("Costelus", 10, 2, lista, 5000);
	Profesor p("Gigel", 5, 2, lista, 4000, Grad::LECT, 15);
	Angajat a2 = a;
	//evidentiem virtualizarea 
	cout << "\nLucrul cu obiecte: \n";
	cout << "\nSalariu Angajat: " << a.calculSalariu();
	cout << "\nSalariu Profesor: " << p.calculSalariu();

	//upcast la angajat
	a = p;
	cout << "\nSalariu Angajat(fost Profesor): " << a.calculSalariu();
	a = a2;
	cout << "\nLucrul cu pointeri: \n";
	Angajat* pa = &a; // nu se dezaloca
	Profesor* pp = &p;
	cout << "\nSalariu Angajat(Pointer): " << pa->calculSalariu();
	cout << "\nSalariu Profesor(Pointer): " << pp->calculSalariu();

	//upcast pe pointer
	pa = pp;
	cout << "\nSalariu Angajat(Pointer, fost Profesor): " << pa->calculSalariu();




	//lucru cu fisiere binare

	//iFile f; nu se poate
	iFile* pf;
		
	fstream fOut("fisier.txt", ios::out|ios::binary);
	a.writeToFile(fOut);
	fOut.close();

	fstream fIn("fisier.txt", ios::in | ios::binary);
	Angajat aNou;
	aNou.readFromFile(fIn);
	fIn.close();
	cout << aNou;

	return 0;
}