#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
/*
clasa, atribute, constructori, getteri, setteri

tema!
1.
adaptati sablonul de redimensionare pt lucrul cu vectori statici

2.
alegeti o clasa in care sa avem:
1 vec aloc stat char
1 vec aloc dinamic char
1 vec static/dinamic inturi sau floaturi etc.
si alte atribute
constr fara param
constr cu toti param
constr cu nu toti param
getteri si setteri pentru fiecare atribut
metoda de afisare

3. tema de documentat
ce este unsafe la el getNume?

TODO data viitoare:
pointeri constanti
operatorul new cu (), delete
constructori de copiere
vectori statici si dinamici de obiecte


ATENTIE LA SETTERII PE VECTOR
*/

class Student {
	char nume[100];
	int anStudiu;
	int nrNote;
	int* note;

public:
	/*
	tipuri de metode:
		1.constructori
		2.destructor
		3.metode de prelucrare
		4.supraincarcare de operatori
	*/
	Student() {
		std::cout << "Constructor fara parametri apelat";
		strcpy(nume, "Anonim");
		anStudiu = 0;
		nrNote = 0;
		note = nullptr;
	}

	Student(const char* nume, int anStudiu, int nrNote, int* note) {
		std::cout << "Constructor cu toti parametrii apelat";
		strcpy(this->nume, nume);
		this->anStudiu = anStudiu;
		this->nrNote = nrNote;
		//this->note = (int*)malloc(nrNote*sizeof(int));
		this->note = new int[nrNote];
		for (int i = 0; i < nrNote; i++) {
			this->note[i] = note[i];
		}
	}

	Student(const char* nume) {
		std::cout << "Constructor cu mai putini parametri";
		strcpy(this->nume, nume);
		this->anStudiu = 1;
		this->nrNote = 0;
		this->note = nullptr;
	}

	//metode accesor = getter si setter
	char* getNume() {
		return this->nume;
	}

	void setNume(const char* nume) {
		//grija la memory leaks!
		strcpy(this->nume, nume);
	}



	int getAnStudiu() {
		return this->anStudiu;
	}

	void afisare() {
		std::cout << "\n-------------";
		std::cout << "\nNume: " << nume;
		std::cout << "\nAn Studiu: " << anStudiu;
		std::cout << "\nNr. Note: " << nrNote;
		std::cout << "\nNote: ";
		for (int i = 0; i < nrNote; i++) {
			std::cout << note[i] << " ";
		}
		std::cout << "\n-------------";
	}



};

int main() {
	Student s; //ocupa 112bytes
	Student* ps; //ocupa 4bytes
	ps = &s;

	s.afisare();
	int note[] = { 10, 6, 5 };
	Student s2("Gigel", 1, 3, note);
	s2.afisare();
	Student s3("Costel");
	s3.afisare();
	std::cout << "\n" << s3.getNume();
	s3.setNume("Costelus");
	std::cout << "\n" << s3.getNume();
	return 0;
}