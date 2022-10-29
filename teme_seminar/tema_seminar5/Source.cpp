#include <iostream>

using namespace std;

class Carte {
	const int bookCode;
	string title, author;
	int* capitole;
	int nrCapitole;
public:
	Carte(int newBookCode, string newTitle = "", string newAuthor = "N/A", int* newCapitole = nullptr, int newNrCapitole = 0) : bookCode(newBookCode), title(newTitle), author(newAuthor)
	{
		if (newNrCapitole < 1 || newCapitole == nullptr) {
			return;
		}
		this->capitole = new int[newNrCapitole];
		this->nrCapitole = newNrCapitole;
		for (int i = 0; i < this->nrCapitole; i++) {
			this->capitole[i] = newCapitole[i];
		}
	}
	Carte(const Carte& c):bookCode(c.bookCode) {
		this->title = c.title;
		this->author = c.author;
		if (c.capitole == nullptr || c.nrCapitole < 1) {
			return;
		}
		this->nrCapitole = c.nrCapitole;
		this->capitole = new int[this->nrCapitole];
		for (int i = 0; i < this->nrCapitole; i++) {
			this->capitole[i] = c.capitole[i];
		}
	}

	Carte operator=(const Carte& c) { //bookCode ramane acelasi
		this->title = c.title;
		this->author = c.author;
		if (c.capitole == nullptr || c.nrCapitole < 1) {
			return *this;
		}
		this->nrCapitole = c.nrCapitole;
		delete[] this->capitole;
		this->capitole = new int[this->nrCapitole];
		for (int i = 0; i < this->nrCapitole; i++) {
			this->capitole[i] = c.capitole[i];
		}
		return *this;
	}


	


	int getBookCode() {
		return this->bookCode;
	}
	string getTitle() {
		return this->title;
	}
	string getAuthor() {
		return this->author;
	}
	int getNrCapitole() {
		return this->nrCapitole;
	}
	int* getCapitole() {
		return this->capitole;
	}


	void setTitle(string newTitle) {
		this->title = newTitle;
	}
	void setAuthor(string newAuthor) {
		this->author = newAuthor;
	}
	void setCapitole(int newNrCapitole, int* newCapitole) {
		if (newNrCapitole < 1 || newCapitole == nullptr) {
			cout << "\nInput invalid.\n";
			return;
		}
		this->nrCapitole = newNrCapitole;
		for (int i = 0; i < this->nrCapitole; i++) {
			this->capitole[i] = newCapitole[i];
		}
	}

	void print() {
		cout << "\n--------------------------------------------------------";
		cout << "\nCod: " << this->bookCode << " Titlu: " << this->title << " Autor: " << this->author;
		if (this->capitole == nullptr || this->nrCapitole < 1) {
			return;
		}
		cout << " Nr. Capitole: " << this->nrCapitole;
		for (int i = 0; i < this->nrCapitole; i++) {
			cout << "\nCapitolul " << i << " incepe la pagina " << this->capitole[i];
		}
		cout << "\n--------------------------------------------------------";
	}


	~Carte() {
		delete[] this->capitole;
	}
};


int main() {
	int a[] = {15, 24, 76, 145};
	Carte c1(100);
	Carte c2(101, "Baltagul", "M. Sadoveanu", a, 4);
	c2.print();
	Carte c3(102);
	c3 = c2;
	c3.setAuthor("Not M. Sadoveanu");
	c3.print();
	Carte c4(103);
	c4 = c3;
	c4.setTitle("Not Baltagul");
	c4.print();
	return 0;

}