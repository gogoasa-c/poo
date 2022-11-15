#include <iostream>
#include<string>

using namespace std;

class Student{
	int matricol = 100;
public:
	string nume = "Anonim Doi";


	/*friend ostream& operator>>(const Student& s, ostream& os) {
		os << s.matricol << " " << s.nume << "\n";
		return os;
	}*/

	friend ostream& operator<<(ostream& os, const Student& s) {
		os << s.matricol << " " << s.nume << "\n";
		return os;
	}

	friend istream& operator>>(istream& is, Student& s) {
		cout << "\nMatricol: ";
		is >> s.matricol;
		cout << "\nNume: ";
		is.ignore();
		getline(is, s.nume); //luat din <string>
		return is;
	}
};


int main() {
	Student s1, s2;
	s2.nume = "Altcineva";
	/*s2 >> (s1 >> cout); */
	cin >> s1;
	cout << s1;

	string text = "Ceva text";
	cout << "\nsizeof(text): " << sizeof(text); //sizeof se evalueaza in compilare doar! daca redimensionam stringul tot la fel de mult spatiu va avea alocat 
	cout << "\ntext.size(): " << text.length();


	return 0;
}