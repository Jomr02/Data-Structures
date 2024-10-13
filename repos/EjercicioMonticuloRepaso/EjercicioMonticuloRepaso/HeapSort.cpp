#include "HeapSort.h"


void heapSort(ListaContigua* listaParaOrdenar) {
	assert(listaParaOrdenar != nullptr);

	Monticulo monticulo;

	int n = listaParaOrdenar->getN();

	for (int i = 0; i < n; i++) {
		monticulo.insertar(listaParaOrdenar->getElemento(i));
	}

	for (int j = 0; j < n; j++) {
		listaParaOrdenar->setElemento(j, monticulo.borrar());
	}

}