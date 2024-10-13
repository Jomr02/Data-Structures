#include "ImprimirListaEnlazada.h"
#include "iostream"

using namespace std;

void imprimirListaEnlazada(ListaEnlazadaSimple* lista) {

	int tamanoLista = lista->getN();


	if (tamanoLista == 0) {
		cout << "Lista Vacia";
	}
	else {

		for (int i = 0; i < tamanoLista; i++) {
			cout << lista->getValor(i);

			if (i < tamanoLista - 1) {
				cout << ", ";
			}
		}
	}

	cout << "\n";
}