#include "ImprimeLista.h"
#include "cassert"
#include <iostream>

using namespace std;

void imprimirLista(ListaEnlazada* lista) {
	assert(lista != NULL);

	int n = lista->getN();

	if (n == 0) {
		cout << "Lista Vacia";

	}
	else {
		for (int i= 0; i < n; i++) {
			cout << lista->getElemento(i);

			if (i < (n - 1)) {
				cout << ", ";

			}

		}

	}


	cout << "\n";




}