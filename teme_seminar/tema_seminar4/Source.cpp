#include <iostream>
#include <string>
using namespace std;

/*
alegem o clasa cu:
1 string
1 vector alocat dinamic de stringuri - string*
constructori de toate felurile
afisare
destructor
setteri si getteri
exemple in main
*/



class Carte{
	string titlu, autor;
	int nrCapitole;
	string* capitole;
public:
	Carte(string titlu = "N/A", string autor = "Nimeni", int nrCapitole = 1, string * capitole = nullptr) {
		this->titlu = titlu;
		this->autor = autor;
		this->nrCapitole = nrCapitole;
		if (nrCapitole < 1 || capitole == nullptr) {
			return;
		}
		this->capitole = new string[this->nrCapitole];
		for (int i = 0; i < this->nrCapitole; i++) {
			this->capitole[i] = capitole[i];
		}
		/* sau
		if (nrCapitole > 0 && capitole != nullptr) {
			this->nrCapitole = nrCapitole;
			this->capitole = new string[nrCapitole];
			for (int i = 0; i < nrCapitole; i++) {
				this->capitole[i] = capitole[i];
			}
		}*/
	}
	
	Carte(const Carte& c) {
		this->titlu = c.titlu;
		this->autor = c.autor;
		this->nrCapitole = c.nrCapitole;
		if (c.capitole == nullptr) {
			this->capitole = nullptr;
			return;
		}
		this->capitole = new string[this->nrCapitole];
		for (int i = 0; i < this->nrCapitole; i++) {
			this->capitole[i] = c.capitole[i];
		}
	}

	void setTitlu(string newTitlu) {
		this->titlu = newTitlu;
	}
	void setAutor(string newAutor) {
		this->autor = newAutor;
	}
	void setCapitole(string* newCapitole, int newNrCapitole) {
		if (newCapitole == nullptr) {
			cout << "Nu s-au modificat capitolele!";
			return;
		}
		if (newNrCapitole < 1) {
			cout << "Nr. invalid de capitole!";
			return;
		}
		delete[] this->capitole;
		this->capitole = new string[newNrCapitole];
		this->nrCapitole = newNrCapitole;
		for (int i = 0; i < this->nrCapitole; i++) {
			this->capitole[i] = newCapitole[i];
		}
	}

	string getTitlu() {
		return this->titlu;
	}
	string getAutor() {
		return this->autor;
	}
	int getNrCapitole() {
		return this->nrCapitole;
	}
	string* getCapitole() {
		return this->capitole;
	}

	void print() {
		cout << "\n--------------------------------";
		cout << "\nTitlu: " << titlu;
		cout << "\nAutor: " << autor;
		cout << "\nNr. capitole: " << nrCapitole;
		if (capitole == nullptr) {
			cout << "\nFara capitole.";
			cout << "\n--------------------------------";
			return;
		}
		cout << "\nCapitole: ";
		for (int i = 0; i < this->nrCapitole; i++) {
			cout << "\n" << i+1 << ". " << capitole[i];
		}
		cout << "\n--------------------------------";
	}

	~Carte() {
		delete[] this->capitole;
	}
};

int main() {
	Carte c1;
	c1.print();
	string s[] = {"unu", "doi", "trei"};
	Carte c2("Baltagul", "M. Sadoveanu", 3, s);
	c2.print();
	Carte c3(c2);
	c3.print();
	c1.setAutor("Eminescu");
	c1.setTitlu("Ceva opera");
	c1.setCapitole(s, 3);
	c1.print();

	string* cap = c1.getCapitole();
	cout << "\nGetteri pentru c1: ";
	cout << "\nTitlu: " << c1.getTitlu();
	cout << "\nAutor: " << c1.getAutor();
	cout << "\nNr. Capitole: " << c1.getNrCapitole();
	for (int i = 0; i < c1.getNrCapitole(); i++) {
		cout << "\n" << i + 1 << ". " << cap[i];
	}


	return 0;
}