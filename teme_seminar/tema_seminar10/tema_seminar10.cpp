#include <iostream>

using namespace std;

//tema: 
//alegeti o clasa de baza cu 2 derivate - animal + caine, pisica
//alocare dinamica in clasa de baza si in una din cele 2 derivate
//implementare de istream

class animal {
    int varsta;
    string nume, *numeStapan;
public:
    animal(int newVarsta = 0, string newNume = "Nume Animal", string newNumeStapan = "N/A"): varsta(newVarsta), nume(newNume) {
        this->numeStapan = new string;
        *this->numeStapan = newNumeStapan;
    }

    animal(const animal& a): varsta(a.varsta), nume(a.nume) {
        this->numeStapan = new string;
        *this->numeStapan = *a.numeStapan;
    }

    animal& operator=(const animal& a) {
        this->varsta = a.varsta;
        this->nume = a.nume;
        *this->numeStapan = *a.numeStapan;
        return *this;
    }

    friend istream& operator>>(istream& in, animal& a) {
        cout << "\nVarsta: ";
        in >> a.varsta;
        cout << "\nNume: ";
        in >> a.nume;
        if (a.numeStapan != nullptr) {
            delete a.numeStapan;
        }
        a.numeStapan = new string;
        cout << "\nNume stapan: ";
        in >> *a.numeStapan;
        return in;
    }

    friend ostream& operator<<(ostream& out, animal& a) {
        out << "\n--------------------animal------------------";
        out << "\nVarsta: " << a.varsta;
        out << "\nNume: " << a.nume;
        out << "\nNume stapan: " << *a.numeStapan;
        out << "\n--------------------animal------------------";
        return out;
    }

    ~animal() {
        if(this->numeStapan != nullptr){
            delete this->numeStapan;
        }
    }
};

class caine : public animal {
    int nrPrieteni;
    string* numePrieteni;
public:
    caine(int newVarsta = 0, string newNume = "Nume Animal", string newNumeStapan = "N/A", int newNrPrieteni = 0, string* newNumePrieteni = nullptr): animal(newVarsta, newNume, newNumeStapan), nrPrieteni(newNrPrieteni) {
        this->numePrieteni = new string[this->nrPrieteni];
        for (int i = 0; i < this->nrPrieteni; i++) {
            this->numePrieteni[i] = newNumePrieteni[i];
        }
    }

    caine(const caine& c): animal(c), nrPrieteni(c.nrPrieteni) {
        this->numePrieteni = new string[this->nrPrieteni];
        for (int i = 0; i < this->nrPrieteni; i++) {
            this->numePrieteni[i] = c.numePrieteni[i];
        }
    }

    caine& operator=(const caine& c) {
        (animal)*this = (animal)c;
        this->nrPrieteni = c.nrPrieteni;
        if (this->numePrieteni != nullptr) {
            delete[] this->numePrieteni;
        }
        this->numePrieteni = new string[this->nrPrieteni];
        for (int i = 0; i < this->nrPrieteni; i++) {
            this->numePrieteni[i] = c.numePrieteni[i];
        }
        return *this;
    }

    friend istream& operator>>(istream& in, caine& c) {
        //animal a = c; varianta cu scarpinatura dupa cap, mai puteam si cu pointeri
        //in >> a;
        //(animal)c = a;
        //c.animal::operator=(a);
        in >> (animal&)c; // asa e cel mai simplu though
        cout << "\nNr. Prieteni: ";
        in >> c.nrPrieteni;
        cout << "\nNume prieteni: \n";
        if (c.numePrieteni != nullptr) {
            delete[] c.numePrieteni;
        }
        c.numePrieteni = new string[c.nrPrieteni];

        for (int i = 0; i < c.nrPrieteni; i++) {
            cout << "\nPrieten " << i + 1 << ": ";
            in >> c.numePrieteni[i];
        }
        return in;
    }

    friend ostream& operator<<(ostream& out, caine& c) {
        out << "\n--------------------caine------------------";
        out << (animal&)c;
        out << "\nNr. Prieteni: " << c.nrPrieteni;
        out << "\nNume Prieteni: ";
        for (int i = 0; i < c.nrPrieteni; i++) {
            out << c.numePrieteni[i] << " ";
        }
        out << "\n--------------------caine------------------";
        return out;
    }

    ~caine() {
        if (this->numePrieteni != nullptr) {
            delete[] this->numePrieteni;
        }
    }
};

class pisica : public animal {
    int nrVietiRamase;
public:
    pisica(int newVarsta = 0, string newNume = "Nume Animal", string newNumeStapan = "N/A", int newNrVietiRamase = 9): animal(newVarsta, newNume, newNumeStapan), nrVietiRamase(newNrVietiRamase) {}

    pisica(const pisica& p): animal(p), nrVietiRamase(p.nrVietiRamase) {}

    pisica& operator=(const pisica& p) {
        this->animal::operator=(p);
        this->nrVietiRamase = p.nrVietiRamase;
        return *this;
    }

    friend istream& operator>>(istream& in, pisica& p) {
        in >> (animal&)p;
        cout << "\nNumar vieti ramase: ";
        in >> p.nrVietiRamase;
        return in;
    }
    friend ostream& operator<<(ostream& out, pisica& p) {
        out << "\n--------------------pisica------------------";
        out << (animal&)p;
        out << "\nNr. vieti ramase: " << p.nrVietiRamase;
        out << "\n--------------------pisica------------------";
        return out;
    }

    ~pisica(){}
};

int main()
{
    animal a;
    cin >> a;
    cout << a;
    caine c;
    cin >> c;
    cout << c;
    animal a1 = a, a2;
    a2 = a;
    caine c1 = c, c2;
    c2 = c1;
    pisica p;
    cin >> p;
    cout << p;
    pisica p1 = p, p2;
    p2 = p;
    p = p1;
}
