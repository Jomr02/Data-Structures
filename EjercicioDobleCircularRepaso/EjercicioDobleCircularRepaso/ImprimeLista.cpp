#include "ImprimeLista.h"
#include <iostream>

using namespace std;


void imprimirLista(DobleCircular* lista) {

	int n = lista->getN();

	if (n == 0) {
		cout << "Lista vacia";

	}
	else {
		for (int i = 0; i < n; i++) {
			cout << lista->getElemento(i);

			if (i < n - 1) {
				cout << ", ";
			}

		}

	}

	cout << "\n";



}