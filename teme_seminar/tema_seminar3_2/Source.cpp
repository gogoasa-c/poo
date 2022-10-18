#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
/*
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
*/
class Carte{
	char denumire[50], autor1[50];
	char* autor2;
	int nrPagini, nrCapitole;
	int* capitole;
public:
	Carte():denumire(""), autor1(""), autor2(nullptr), nrPagini(0), nrCapitole(0), capitole(nullptr) {}
	Carte(char newDenumire[50], char newAutor1[50], char* newAutor2 = nullptr, int newNrPagini = -1, int newNrCapitole = -1, int* newCapitole = nullptr): autor2(newAutor2), nrPagini(newNrPagini), nrCapitole(newNrCapitole), capitole(newCapitole) {
		strcpy_s(this->denumire, newDenumire);
		strcpy_s(this->autor1, newAutor1);
	}

	char* getDenumire() {
		return this->denumire;
	}
	char* getAutor1() {
		return this->autor1;
	}
	char* getAutor2() {
		return this->autor2;
	}
	int getNrPagini() {
		return this->nrPagini;
	}
	int getNrCapitole() {
		return this->nrCapitole;
	}
	int* getCapitole() {
		return this->capitole;
	}

	void setDenumire(const char* newDenumire) {
		strcpy_s(this->denumire, newDenumire);
	}
	void setAutor1(const char* newAutor1) {
		strcpy_s(this->autor1, newAutor1);
	}
	void setAutor2(char* newAutor2) {
		this->autor2 = newAutor2;
	}
	void setNrPagini(int newNrPagini) {
		this->nrPagini = newNrPagini;
	}
	void setCapitole(int* newCapitole, int newNrCaptiole) {
		this->nrCapitole = newNrCaptiole;
		this->capitole = new int[newNrCaptiole];
		for (int i = 0; i < newNrCaptiole; i++) {
			this->capitole[i] = newCapitole[i];
		}
	}

	void show() {
		std::cout <<"\n" << denumire << " de ";
		std::cout << autor1 << " ";
		if (autor2) {
			std::cout <<"si " << autor2 << " ";
		}
		std::cout << "\nNr. pagini: " << nrPagini << "; ";
		std::cout << "\nNr. capitole: " << nrCapitole << "; ";
		if(capitole)
		{
			std::cout << "\nCapitolele sunt la paginile: \n";
			for (int i = 0; i < nrCapitole; i++) {
				std::cout << "Capitolul " << i << " la pagina " << capitole[i] << "\n";
			}
		}
		std::cout << "\n";
	}

	~Carte() {
		delete this->autor2;
		delete this->capitole;
	}
};



void f() {
	Carte c1;
	char* autor2 = new char[7];
	strcpy(autor2, "autor2");
	int* capitole = new int[6];
	int j = 0;
	for (int i = 0; i < 6; i++) {
		capitole[i] = j;
		j += 50;
	}
	char denum[] = "Carte2";
	char a[] = "autor12";
	Carte c2(denum, a);

	char* autor3 = new char[7];
	strcpy(autor3, "autor3");
	int* capitole1 = new int[6];
	j = 0;
	for (int i = 0; i < 6; i++) {
		capitole1[i] = j;
		j += 50;
	}

	Carte c3(denum, a, autor3, 400, 5, capitole1);

	c1.setDenumire("Carte1");
	c1.setAutor1("Autor1");
	c1.setAutor2(autor2);
	c1.setNrPagini(300);
	c1.setCapitole(capitole, 6);
	c1.show();
	c2.show();
	c3.show();
	std::cout << "\n\n";
	std::cout << c1.getAutor1() << "\n";
	std::cout << c1.getDenumire() << "\n";
	std::cout << "------------------\n";
	c3.getDenumire()[0] = 'x';
	char* sir = new char[strlen(c3.getDenumire()) + 1];
	strcpy(sir, c3.getDenumire());
	sir[0] = 'a';
	char* sir2 = c3.getDenumire(); //rvalue = right value; lvalue = left value
	std::cout << c3.getDenumire() << "\n";
}

int main() {
	while (true) {
		int n;
		std::cout << "1. Show\n2. Exit\n";
		std::cin >> n;
		switch (n) {
		case 1:
			f();
			break;
		case 2:
			return 0;
		default:
			std::cout << "Invalid.";
		}
	}
	return 0;
}