/*tema
functia care primeste un vector si dim sa si:
1. elim valorile din mijl
2. dubleaza toate valorile mai mari decat media
3. elimina primele si ultimele k valori din vector
4. elimina cele mai mari 2 valori din vector
*/

#include <iostream>
//elim valorile din mijl
void delMid(int*& v, int &size) {
	int* aux;
	if (size % 2 == 0) {
		aux = (int*)malloc((size - 2) * sizeof(int));
		int j = 0;
		for (int i = 0; i < size; i++) {
			if (i != size / 2 && i != size / 2 - 1) {
				aux[j] = v[i];
				++j;
			}
		}
		free(v);
		v = aux;
		size -= 2;
	}
	else {
		aux = (int*)malloc((size - 1) * sizeof(int));
		int j = 0;
		for (int i = 0; i < size; i++) {
			if (i != size / 2 + 1) {
				aux[j] = v[i];
				++j;
			}
		}
		free(v);
		v = aux;
		--size;
	}
}

//dubleaza toate valorile mai mari decat media
void doubleOverAvg(int*& v, int size) {
	double average = 0;
	for (int i = 0; i < size; i++) {
		average += v[i];
	}
	average /= size;
	for (int i = 0; i < size; i++) {
		if (v[i] > average) {
			v[i] *= 2;
		}
	}
}

//elimina primele si ultimele k valori din vector
void delKVal(int *&v, int &size, int k) {
	int newSize = size - 2 * k;
	int* aux = (int*)malloc(newSize * sizeof(int));
	int j = 0;
	for (int i = k; i < size - k; i++) {
		aux[j] = v[i];
		++j;
	}
	free(v);
	v = aux;
	size = newSize;
}

//elimina cele mai mari 2 valori din vector
void delGreatestTwo(int *&v, int &size) {
	if (size < 2) {
		std::cout << "Vectorul are mai putin de 2 elemente!";
		return;
	}
	int* aux = (int*)malloc((size - 2) * sizeof(int));
	int g1 = INT_MIN, g2 = INT_MIN;
	for (int i = 0; i < size; i++) {
		if (v[i] > g1) {
			g2 = g1;
			g1 = v[i];
		}
		else if (v[i] > g2) {
			g2 = v[i];
		}
	}
	int j = 0;
	for (int i = 0; i < size; i++) {
		if (v[i] != g1 && v[i] != g2) {
			aux[j] = v[i];
			++j;
		}
	}
	free(v);
	v = aux;
	size -= 2;
}

int main() {
	int* v1, * v2, * v3, * v4;
	int size1 = 10, size2 = 10, size3 = 10, size4 = 10;
	v1 = (int*)malloc(size1 * sizeof(int));
	v2 = (int*)malloc(size2 * sizeof(int));
	v3 = (int*)malloc(size3 * sizeof(int));
	v4 = (int*)malloc(size4 * sizeof(int));
	for (int i = 0; i < size1; i++) {
		v1[i] = i;
		v2[i] = i;
		v3[i] = i;
		v4[i] = 10 - i;
	}
	
	std::cout << "Elemente v1: ";
	for (int i = 0; i < size1; i++) {
		std::cout << v1[i] << " ";
	}
	std::cout << "\n";
	delMid(v1, size1);

	std::cout << "Elemente v1 post apel functie: ";
	for (int i = 0; i < size1; i++) {
		std::cout << v1[i] << " ";
	}
	std::cout << "\n";



	std::cout << "Elemente v2: ";
	for (int i = 0; i < size2; i++) {
		std::cout << v2[i] << " ";
	}
	std::cout << "\n";
	doubleOverAvg(v2, size2);

	std::cout << "Elemente v2 post apel functie: ";
	for (int i = 0; i < size2; i++) {
		std::cout << v2[i] << " ";
	}
	std::cout << "\n";



	std::cout << "Elemente v3: ";
	for (int i = 0; i < size3; i++) {
		std::cout << v3[i] << " ";
	}
	std::cout << "\n";
	int k = 2;
	delKVal(v3, size3, k);// face urat cand se dezaloca memoria lui v3 in main

	std::cout << "Elemente v3 post apel functie: ";
	for (int i = 0; i < size3; i++) {
		std::cout << v3[i] << " ";
	}
	std::cout << "\n";


	std::cout << "Elemente v4: ";
	for (int i = 0; i < size4; i++) {
		std::cout << v4[i] << " ";
	}
	std::cout << "\n";
	delGreatestTwo(v4, size4);

	std::cout << "Elemente v4 post apel functie: ";
	for (int i = 0; i < size4; i++) {
		std::cout << v4[i] << " ";
	}
	std::cout << "\n";

	free(v1);
	free(v2);
	free(v3);
	free(v4);
	return 0;
}