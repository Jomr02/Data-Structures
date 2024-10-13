#include "HeapSort.h"
#include "Monticulo.h"
#include "cassert"

void heapSort(ListaContigua* lista) {
	assert(lista != nullptr);

	Monticulo heap;

	int n = lista->getN();

	for (int i = 0; i < n; i++) {
		heap.insertar(lista->getElemento(0));
		lista->eliminar(0);

	}

	for (int i = 0; i < n; i++) {
		lista->insertar(i, heap.borrar());
	}

}