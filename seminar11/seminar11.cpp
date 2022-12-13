#include<iostream>
#include<string>
#include<map>
#include<set>
#include<vector>
#include<list>
using namespace std;


class Eveniment {
private:
	int nrPers = 0;
	string locatie;
public:
	Eveniment() {}
	Eveniment(int nrPers, string locatie) {
		this->nrPers = nrPers;
		this->locatie = locatie;
	}
	Eveniment(const Eveniment& e) {
		this->nrPers = e.nrPers;
		this->locatie = e.locatie;
	}
	Eveniment& operator=(const Eveniment& e) {
		this->nrPers = e.nrPers;
		this->locatie = e.locatie;
		return *this;
	}
	friend ostream& operator<<(ostream& out, const Eveniment& e) {
		out << "\nNr pers eveniment: " << e.nrPers;
		out << "\nLocatie eveniment: " << e.locatie;
		return out;
	}


	friend bool operator<(const Eveniment& e1, const Eveniment& e2);
};

bool operator<(const Eveniment& e1, const Eveniment& e2) {
	return e1.nrPers < e2.nrPers;
}

template<class T>

class Colectie {
	int nrObiecte = 0;
	T* listaObiecte = nullptr;
public:
	Colectie() {}

	Colectie(int newNrObiecte, T* newListObiecte) {
		this->nrObiecte = newNrObiecte;
		this->listaObiecte = new T[this->nrObiecte];
		for (int i = 0; i < this->nrObiecte; i++) {
			this->listaObiecte[i] = newListObiecte[i];
		}
	}

	Colectie(const Colectie& c) {
		this->nrObiecte = c.nrObiecte;
		this->listaObiecte = new T[this->nrObiecte];
		for (int i = 0; i < this->nrObiecte; i++) {
			this->listaObiecte[i] = c.listaObiecte[i];
		}
	}

	Colectie& operator=(const Colectie& c) {
		if (this == &c) {
			return *this;
		}
		delete[] this->listaObiecte;
		this->nrObiecte = c.nrObiecte;
		this->listaObiecte = new T[this->nrObiecte];
		for (int i = 0; i < this->nrObiecte; i++) {
			this->listaObiecte[i] = c.listaObiecte[i];
		}
		return *this;
	}

	friend ostream& operator<<(ostream& out, const Colectie& c) {
		cout << "\nNr. Obiecte: " << c.nrObiecte;
		cout << "\nLista Obiecte: ";
		for (int i = 0; i < c.nrObiecte; i++) {
			cout << c.listaObiecte[i] << " ";
		}
		return out;
	}

	~Colectie() {
		delete[] this->listaObiecte;
	}
};

int main()
{
	int v[] = { 10, 30, 40 };
	Colectie<int> cInt(3, v);
	cout << cInt;
	Eveniment e1(100, "Petrecere Facultate"), e2(15000, "Targ Craciun Craiova"), e3(1200, "Targ Craciun Sibiu");
	Eveniment ev[] = { e1, e2, e3 };
	Colectie<Eveniment> cEvent(3, ev);
	cout << cEvent;

	cout << "\n------------STL Vector---------------";
	vector<int> v1;
	v1.push_back(10);
	v1.push_back(20);
	cout << endl;
	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << " ";
	}
	cout << endl;
	vector<int>::iterator it1; //iteratorul se face in functie de ce strucutra avem
	for (it1 = v1.begin(); it1 != v1.end(); it1++) {
		cout << *it1 << " ";
	}

	cout << "\n------------STL List---------------\n";
	list<float> l2;
	l2.push_back(10.);
	l2.push_front(5.3);
	l2.push_back(14.);
	list<float>::reverse_iterator it2;
	for (it2 = l2.rbegin(); it2 != l2.rend(); it2++) {
		cout << *it2 << " ";
	}

	
	cout << "\n------------STL Set---------------\n";
	set<string> s3;
	s3.insert("Ionescu Maria");
	s3.insert("Ionescu Maria");
	s3.insert("Balan Monica");
	set<string>::iterator it3;
	for (it3 = s3.begin(); it3 != s3.end(); it3++) {
		cout << *it3 << "\n";
	}

	it3 = s3.find("Ionescu Maria");
	if (it3 != s3.end()) {
		cout << "\nS-a gasit!";
	}
	else {
		cout << "\nNu s-a gasit!";
	}

	set<Eveniment> sEv3;
	sEv3.insert(e1);
	sEv3.insert(e2);
	set<Eveniment>::iterator itEv3;
	cout << endl;
	for (itEv3 = sEv3.begin(); itEv3 != sEv3.end(); itEv3++) {
		cout << *itEv3 << " ";
	}

	cout << "\n------------STL Map---------------\n";
	map<int, string> m4;
	m4[10] = "Ionescu";
	m4[51] = "Popescu";
	map<int, string>::iterator it4;
	cout << endl;
	for (it4 = m4.begin(); it4 != m4.end(); it4++) {
		cout << it4->first << " " << it4->second << '\n';
	}


	return 0;
}