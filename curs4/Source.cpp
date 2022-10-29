//operatori unari binari

#include <iostream>
using namespace std;

//in clasa:
//static = instanta de clasa
//metoda statica nu primeste this

//in afara clasei:
//automatic - pe stack, static - pe heap, extern - kind of global, dar declarate altundeva(in librarii), register - pe registrii, mult mai rapid

//supraincarcari operatori si functii:

class Pers {
	int varsta = 20;
	friend ostream& operator<<(ostream& ost, Pers& p) {
		ost << p.varsta;
		return ost;
	}
	friend Pers& operator++(Pers& p) {
		++p.varsta;
		return p;
	}
	friend Pers& operator++(Pers& p, int) {
		Pers aux;
		aux = p;
		++p.varsta;
		return aux;
	}
};

int main() {
	/*for (int i = 0; i < 10; i++) {
		int j = 0;
		static int k = 0;
		cout << "\ni= " << i << "   j= " << j << "   k= " << k;
		j++;
		k++;
	}*/
	int x = 0;
	Pers p1, p2;
	p2 = p1++;
	++++x;
	cout << x <<"\n";
	//++p1;
	cout << p2 <<"\n"<<p1;

	return 0;
}
