#include "ImprimeLista.h"
#include <cassert>
#include "iostream"

using namespace std;

void imprimirLista(ListaContigua *lista) {
	assert(lista != nullptr);


	if (lista->getN() == 0) {
		cout << "Lista Vacia\n";

	}
	else {
		if (lista->getN() == 20) {
			cout << "Lista demasiado grande\n";

		}
		else {

			for (int i = 0; i < lista->getN(); i++) {
				cout << lista->getElemento(i);
				if (i < lista->getN() - 1)
					cout << ", ";
			}

		}

	}

	cout << "\n";



}