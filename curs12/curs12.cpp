//#include <iostream>
//using namespace std;
//
//				MACRODEFINITII
//#define BLOC for(int i=0; i<n; i++
////paranteza trebuie lipita de numele simbolului, slash continua pe randul urmator
//
//#define COMUTA(T) \
//void comuta(T& a, T& b)\
//{\
//    T aux; aux = a; a = b; b = aux;\
//}
//
//
//COMUTA(int)
//
//COMUTA(double)
//
//int main()
//{
//    int vi[] = { 23, -5, 17, 32 }, n = sizeof(vi)/sizeof(vi[0]);
//    BLOC ) cout << vi[i] << " ";
//
//    comuta(vi[0], vi[1]);
//    cout << endl;
//    BLOC ) cout << vi[i] << " ";
//    
//
//    double vd[] = { 12.5, -84.2, 67., 23.6 };
//    cout << "\n\n";
//    BLOC ) cout << vd[i] << " ";
//    comuta(vd[0], vd[2]);
//    cout << endl;
//    BLOC ) cout << vd[i] << " ";
//
//}
//


#include <iostream>

using namespace std;


class Auto {
	string id, marca;
public:
	Auto(string newId = "B-00-ABC", string newMarca = "Dacia"): id(newId), marca(newMarca) {}

	friend ostream& operator<<(ostream& out, const Auto& a) { 
		out << "\n-------------------------------------------";
		out << "\nID: " << a.id;
		out << "\nMarca: " << a.marca;
		out << "\n-------------------------------------------";
		return out;
	}

};


template<class T>
void comuta(T& a, T& b)
{
	T aux = a; 
	a = b; 
	b = aux; 
}

int main() {
	int vi[] = { 23, -5, 17, 32 }, n = sizeof(vi) / sizeof(vi[0]);
	for (int i = 0; i < n; i++) {
		cout << vi[i] << " ";
	}

	comuta(vi[0], vi[1]);
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << vi[i] << " ";
	}


	double vd[] = { 12.5, -84.2, 67., 23.6 };
	cout << "\n\n";
	for (int i = 0; i < n; i++) {
		cout << vd[i] << " ";
	}
	comuta(vd[0], vd[2]);
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << vd[i] << " ";
	}

	Auto vA[] = { Auto("IL-21-XYZ", "Opel"), Auto("GL-33-ABC"), Auto("VN-99-ACS", "BMW"), Auto("OT-100-ADI", "Mistubishi")};
	n = sizeof(vA) / sizeof(vA[0]);
	cout << "\n\n";
	for (int i = 0; i < n; i++) {
		cout << vA[i] << " ";
	}
	comuta(vA[0], vA[2]);
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << vA[i] << " ";
	}


}