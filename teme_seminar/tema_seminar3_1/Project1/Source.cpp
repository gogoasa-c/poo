#include <iostream>
//elim val din mijl

void delMidVal(int v[], int& size) {
	int j = 0;
	if(size%2 == 0){
		for (int i = 0; i < size; i++) {
			if (i != size / 2 && i != size / 2 - 1) {
				v[j] = v[i];
				++j;
			}
		}
		size -= 2;
	}
	else {
		for (int i = 0; i < size; i++) {
			if (i != size / 2) {
				v[j] = v[i];
				++j;
			}
		}
		--size;
	}
}


int main() {
	int size = 10;
	int v[10];
	std::cout << "V : ";
	for (int i = 0; i < size; i++) {
		v[i] = i;
		std::cout << v[i] << " ";
	}
	std::cout << "\n";
	delMidVal(v, size);
	std::cout << "V : ";
	for (int i = 0; i < size; i++) {
		std::cout << v[i] << " ";
	}
	std::cout << "\n";
}