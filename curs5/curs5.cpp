// curs5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//temaish: vector dinamic de pointeri la persoane
class Vector {
	int dim;
	double* pe; //pe = primul element

public:
	static double errPoint;

	Vector(int newDim = 1):dim(newDim) {
		this->pe = new double[this->dim];
		for (int i = 0; i < dim; i++) {
			this->pe[i] = 0.0f;
		}
	}

	Vector(int newDim, double *newPe) {
		//...
	}
	Vector(const Vector& v): dim(v.dim) {
		pe = new double[dim];
		for (int i = 0; i < dim; i++) {
			pe[i] = v.pe[i];
		}
	}

	Vector& operator = (const Vector& v) {
		if (pe == v.pe) { // sau this == &v
			return *this;
		}
		dim = v.dim;
		delete[] pe;
		pe = new double[dim];
		for (int i = 0; i < dim; i++) {
			pe[i] = v.pe[i];
		}
		return *this;
	}

	double& operator[](int index) {
		if (index >= dim || index < 0 ) {
			cerr << "\nIndex out of range";
			return Vector::errPoint;
		}
		return pe[index];
	}

	friend ostream& operator<<(ostream& o, Vector& v) {
		o << "\n";
		for (int i = 0; i < v.dim; i++) {
			o << v.pe[i] << " ";
		}
		return o;
	}

	~Vector() {
		if(pe!=nullptr) {
			delete[] pe;
		}
	}
};

double Vector::errPoint = -1;

int main() {
	Vector v1(5);
	v1[2] = 3.35;
	cout << v1;
	return 0;
}

