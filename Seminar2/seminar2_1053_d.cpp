#include <iostream>
/*
debugger si sablon pentru redimensionare de vector
*/

/*tema
functia care primeste un vector si dim sa si:
1. elim valorile din mijl
2. dubleaza toate valorile mai mari decat media
3. elimina primele si ultimele k valori din vector
4. elimina cele mai mari 2 valori din vector
*/

void ElimValPare(int *&v, int &n) {
	//calc noua dim
	int newSize = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] % 2 == 1) {
			++newSize;
		}
	}
	//alocam noua zona de mem
	int* aux = (int*)malloc(newSize * sizeof(int));
	//copiem in aux ce se pastreaza
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (v[i] % 2 == 1) {
			aux[j] = v[i];
			++j;
		}
	}
	//dezalocare v
	free(v);
	//vector vechi pointeaza spre vector nou
	v = aux;
}

void f1(int a, int b) {
	int aux;
	aux = a;
	a = b;
	b = aux;
}

void f2(int &a, int &b) {
	int aux;
	aux = a;
	a = b;
	b = aux;
}

void f3(int* a, int* b) {
	int aux;
	aux = *a;
	*a = *b;
	*b = aux;
}

void f4(int* a, int* b) {
	int *aux;
	aux = a;
	a = b;
	b = aux;
}

int main() {
	int x, y;
	std::cout << "\nApel f1 cu transfer prin valoare";
	x = 2;
	y = 5;
	f1(x, y);
	std::cout << "\nx = " << x << ", y = " << y;

	std::cout << "\nApel f2 cu transfer prin referinta";
	x = 2;
	y = 5;
	f2(x, y);
	std::cout << "\nx = " << x << ", y = " << y;

	std::cout << "\nApel f3 cu transfer prin pointer";
	x = 2;
	y = 5;
	f3(&x, &y);
	std::cout << "\nx = " << x << ", y = " << y;

	std::cout << "\nApel f4 cu transfer prin pointer";
	x = 2;
	y = 5;
	f4(&x, &y);
	std::cout << "\nx = " << x << ", y = " << y;

	std::cout << "\nLucrul cu vector statiic & dinamici: ";
	int v[10];
	int* v2;
	v[0] = 50;
	v2 = (int*)malloc(5*sizeof(int));
	v2[0] = 12;
	free(v2);

	char sir[100];
	strcpy_s(sir, "Gigel invata la poo");
	std::cout << sir;
	return 0;
}