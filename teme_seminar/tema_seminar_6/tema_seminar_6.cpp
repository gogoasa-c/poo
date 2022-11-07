// tema_seminar_6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

class Angajat {
    const int employeeID;
    static int currID;
    string nume, prenume;
    int varsta, salariu, nrBonusuri;
    int* bonusuri;
public:
    Angajat(string newNume = "N/A", string newPrenume = "N/A", int newVarsta = -1, int newSalariu = 0, int newNrBonusuri = 0, int* newBonusuri = nullptr) : employeeID(currID), nume(newNume), prenume(newPrenume), varsta(newVarsta), salariu(newSalariu), nrBonusuri(newNrBonusuri) {
        ++currID;
        bonusuri = new int[this->nrBonusuri];
        if (newBonusuri == nullptr) {
            return;
        }
        for (int i = 0; i < this->nrBonusuri; i++) {
            this->bonusuri[i] = newBonusuri[i];
        }
    }
    Angajat(const Angajat& a): employeeID(currID), nume(a.nume), prenume(a.prenume), varsta(a.varsta), salariu(a.salariu), bonusuri(nullptr) {
        if (a.bonusuri == nullptr || a.nrBonusuri < 1) {
            return;
        }
        this->nrBonusuri = a.nrBonusuri;
        this->bonusuri = new int[this->nrBonusuri];
        for (int i = 0; i < this->nrBonusuri; i++) {
            this->bonusuri[i] = a.bonusuri[i];
        }
    }

    Angajat& operator=(const Angajat a) { 
        if (this == &a) {
            return *this;
        }
        this->nume = a.nume;
        this->prenume = a.prenume;
        this->varsta = a.varsta;
        this->salariu = a.salariu;
        if (a.bonusuri == nullptr || a.nrBonusuri < 1) {
            return *this;
        }
        this->nrBonusuri = a.nrBonusuri; 
        delete[] this->bonusuri;
        this->bonusuri = new int[this->nrBonusuri];
        for (int i = 0; i < this->nrBonusuri; i++) {
            this->bonusuri[i] = a.bonusuri[i];
        }
        return *this;
    }

    Angajat operator++() { //prefix
        Angajat aux = *this;
        this->varsta++;
        return aux;
    }

    Angajat& operator++(int) { //postfix
        this->varsta++;
        return *this;
    }

    Angajat operator+(int addSalariu) { //marire de salariu pentru operatii tip Angajat a2 = a1 + 300;
        Angajat a = *this;
        a.salariu += addSalariu;
        return a;
    }

    Angajat& operator +=(int addSalariu) { //marire de salariu pentru operatii de tip a2+=500; unde a2 e un obiect de tip Angajat
        this->salariu += addSalariu;
        return *this;
    }

    bool operator<(Angajat a) {
        return this->salariu < a.salariu;
    }

    bool operator>(Angajat a) {
        return this->salariu > a.salariu;
    }

    friend Angajat operator+(int addSalariu, Angajat a);

    friend ostream& operator<<(ostream& os, const Angajat& a);

    friend istream& operator>>(istream& is, Angajat& a);

    ~Angajat() { // destructor
        delete[] this->bonusuri;
    }
};

Angajat operator+(int addSalariu, Angajat a) { //marire de salariu pentru operatii de tip 300 + a2; unde a2 e un obiect de tip Angajat
    return a.operator+(addSalariu);
}

ostream& operator<<(ostream& os, const Angajat& a) { // output 
    os << "\n--------------------------";
    os << "\nID: " << a.employeeID;
    os << "\nNume: " << a.nume;
    os << "\nPrenume: " << a.prenume;
    os << "\nVarsta: " << a.varsta;
    os << "\nSalariu: " << a.salariu;
    os << "\nNr. Bonusuri: " << a.nrBonusuri;
    if (a.nrBonusuri > 0) {
        os << "\nBonusuri: ";
    }
    for (int i = 0; i < a.nrBonusuri; i++) {
        os << a.bonusuri[i] << " ";
    }
    os << "\n--------------------------";
    return os;
}

istream& operator>>(istream& is, Angajat& a) { // input
    cout << "\nNume: "; is >> a.nume;
    cout << "\nPrenume: "; is >> a.prenume;
    cout << "\nVarsta: "; is >> a.varsta;
    cout << "\nSalariu: "; is >> a.salariu;
    cout << "\nNr. Bonusuri: "; is >> a.nrBonusuri;
    cout << "\nBonusuri: ";
    delete[] a.bonusuri;
    a.bonusuri = new int[a.nrBonusuri];
    for (int i = 0; i < a.nrBonusuri; i++) {
        is >> a.bonusuri[i];
    }
    return is;
}

int Angajat::currID = 1000; //initializare variabila statica

int main()
{
    int b[] = { 100, 100, 50 };
    Angajat a1("Gigel", "Costescu", 40, 2500, 3, b);
    cout << a1;
    Angajat a2;
    a2 = a1 + 300;
    cout << a2;
    a2 = 25 + a2;
    cout << a2;
    Angajat a3("Angajatul", "Trei", 38, 2000, 2, b);
    cout << a3;
    a3 = a3;
    a3 = a2 = a1;
    cout << a3;
    a3 += 1000;
    cout << a3;
    if (a3 > a1) {
        cout << "\na3 are salariul mai mare decat a1";
    }
    if (a3 < a1) {
        cout << "\na3 are salariul mai mic decat  a1";
    }
    else {
        cout << "\na3 nu are salariul mai mic decat  a1";
    }
    Angajat a4;
    cin >> a4;
    cout << a4;
    ++a4;
    cout << a4;
    a4++;
    cout << a4;
}
