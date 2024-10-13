#include "ImprimirLista.h"
#include<iostream>


using namespace std;

void imprimeLista(ListaContiguaOrdenada* lista) {
	assert(lista != nullptr);

	int tamano = lista->getN();

	for (int i = 0; i < tamano; i++) {
		cout << lista->getElemento(i);

		if (i < tamano - 1)
			cout << ", ";

	}


	cout << "\n";

}