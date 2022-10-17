#include <iostream>
#include <malloc.h>

/*
20% lucrare - saptamanile 7-8
10% proiect (individual/echipa) - saptamana 14
10% teste grila (curs sau seminar)
10% activitate

minim 20/50% pentru intrare in examen
*/

//elimina din vector elem pare

void deleteEven(int *&v, int &size) {
	int newSize = 0; //determin noua marime numarand numarul de elemente impare
	for (int i = 0; i < size; i++) {
		if (v[i] % 2 != 0) {
			++newSize;		
		}
	}
	int* a = (int*)malloc(newSize * sizeof(int)); //aloc un nou vector de elemente care le va contine doar pe cele impare
	int j = 0;
	for (int i = 0; i < size; i++) {
		if (v[i] % 2 != 0) {
			a[j] = v[i];
			++j;
		}
	}
	size = newSize; //inlocuiesc marimea initiala
	free(v);//eliberez memoria pentru v
	v = (int*)malloc(newSize * sizeof(int)); //realoc memorie fix cata imi trebuie
	for (int i = 0; i < size; i++) { 
		v[i] = a[i]; //inlocuiesc fiecare element din v cu cele din a
	}
	free(a); // eliberez memoria pentru a 
}


int main() {
	int size;
	
	std::cin >> size;
	int* v = (int*)malloc(size*sizeof(int));
	for (int i = 0; i < size; i++) {
		std::cin >> v[i];
	}
	deleteEven(v, size);
	for (int i = 0; i < size; i++) {
		std::cout << v[i] << " ";
	}
	free(v);
	return 0;
}