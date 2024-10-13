#include "ImpresionListaEnlazada.h"
#include"cassert"
#include"iostream"

using namespace std;

void imprimirListaEnlazada(DobleEnlazadaCircular* lista) {
	assert(lista != nullptr);

	int longitudLista = lista->getN();


	if (longitudLista == 0) {
		cout << "Lista Vacia";
	}
	else {
		for (int i = 0; i < longitudLista; i++) {
			cout << lista->getValor(i);

			if (i < longitudLista - 1)
				cout << ", ";
		}
	}

	cout << "\n";

}


