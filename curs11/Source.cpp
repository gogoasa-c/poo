#include <iostream>

using namespace std;

class Animal {
public:
	int varsta;
	Animal(int v = 0): varsta(v) {
		cout << "\nConstructor Animal";
	}

	virtual void Speak(){
		cout << "\nAnimal speaks";
	}
};

class Pasare : virtual public Animal {
public:
	Pasare(int v = 1) : Animal(v) {
		cout << "\nConstructor Pasare";
	}

	void Speak() {
		cout << "\nPasarea ciripeste";
	}
};

class Cal : virtual public Animal {
public:
	Cal(int v = 2) : Animal(v) {
		cout << "\nConstructor Cal";
	}

	void Speak() {
		cout << "\nCalul necheaza";
	}
};
//la virtualizate nu ia duplicate, ia doar campul din primul derivat de aici
class Pegas : public Cal, public Pasare{
public:
	Pegas(int v = 3) : Cal(v), Pasare(v) {
		cout << "\nConstructor Pegas";
	}

	void Speak() {
		//cout << "\nPegasul necheaza?";
		Cal::Speak();
	}
};

int main() {
	Animal a;
	Pasare p;
	Cal c;
	Animal *va[] = { &a, &p, &c };
	for (int i = 0; i < sizeof(va)/sizeof(va[0]); i++) {
		va[i]->Speak();
		cout << " si are varsta: " << va[i]->varsta;
	}
	cout << "\n\n\n\n";
	Pegas pg;
	cout << "\nVarsta Pegas: " << pg.Cal::varsta << " sau " << pg.Pasare::varsta;
}