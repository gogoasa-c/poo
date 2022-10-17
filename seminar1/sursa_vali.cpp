#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

void elim_pare(int &nr, int *&v)
{
	int i, auxnr = 0, *aux = NULL;
	for (i = 0; i < nr; i++) {
		if (*(v + i) % 2 == 1) {
			auxnr += 1;
		}
	}
	aux = (int*)malloc(auxnr * sizeof(int));
	int j = 0;
	for (i = 0; i < nr; i++) {
		if (*(v + i) % 2 == 1) {
			*(aux+j) = *(v + i);
			++j;
		}
	}
	nr = auxnr;
	free(v);
	v = (int*)malloc(nr * sizeof(int));
	for (i = 0; i < nr; i++) {
		*(v + i) = *(aux + i);
	}
	free(aux);
}

int main()
{
	int i, * v;
	int nr;
	printf("Cate elem are vectorul? ");
	std::cin >> nr;
	v = (int*)malloc(nr * sizeof(int));
	for (i = 0; i < nr; i++) {
		scanf("%i", v + i);
	}
	elim_pare(nr, v);

	for (i = 0; i < nr; i++) {
		printf("%i ", *(v+i));
	}

	free(v);
	return 0;
}