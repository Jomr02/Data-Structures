#include "ListaContiguaOrdenada.h"
#include <stdlib.h>
#include "string.h"
#include <iostream>

ListaContiguaOrdenada::ListaContiguaOrdenada() {
	lista = nullptr;
	capacidad = 0;
	n = 0;

}

void ListaContiguaOrdenada::aumentaCapacidad(int incremento) {
	assert((capacidad + incremento) > 0);

	lista = (int*) realloc(lista, (capacidad + incremento) * sizeof(int));

	capacidad = capacidad + incremento;

}

int ListaContiguaOrdenada::getElemento(int posicion) {
	assert(n > 0);
	assert(posicion >= 0 && posicion < n);

	return (lista[posicion]);

}
void ListaContiguaOrdenada::setElemento(int posicion, int elemento) {
	assert(n > 0);
	assert(posicion >= 0 && posicion < n);

	lista[posicion] = elemento;

}
void ListaContiguaOrdenada::insertar(int elemento) {
	
	if (n == capacidad) {
		aumentaCapacidad(INCREMENTO);
	}

	if (n == 0) {
		lista[0] = elemento;
	}
	else {
		int posicion = buscar(elemento);

			memcpy(lista + posicion + 1, lista + posicion, (n - posicion) * sizeof(int));

			lista[posicion] = elemento;


	}



	n++;

}
void ListaContiguaOrdenada::eliminar(int posicion) {
	assert(posicion >= 0 && posicion < n);
	assert(n > 0);

	memcpy(lista + posicion, lista + posicion + 1, (n - posicion - 1) * sizeof(int));

	n--;

	if (capacidad - n == 2 * INCREMENTO) {
		aumentaCapacidad(-INCREMENTO);
	}


}
int ListaContiguaOrdenada::getN() {
	return n;

}
int ListaContiguaOrdenada::getCapacidad() {
	return capacidad;

}
void ListaContiguaOrdenada::concatenar(ListaContiguaOrdenada* listaConcatenar) {
	assert(listaConcatenar != nullptr);

	int tamano = listaConcatenar->getN();

	for (int i = 0; i < tamano; i++) {
		insertar(listaConcatenar->getElemento(i));
	}


}
int ListaContiguaOrdenada::buscar(int elemento) {
	return (buscarBinario(lista, n, elemento));

}

int ListaContiguaOrdenada::buscarBinario(int* vector, int tamano, int elemento) {
	assert(vector != nullptr);


	if (tamano == 0) {
		return vector - lista;
		
	}

	if (vector[tamano / 2] == elemento) {
		return (vector + tamano / 2) - lista;
	}

	if (elemento < vector[tamano / 2] ) {
		return buscarBinario(vector, tamano / 2, elemento);

	}
	else {
		return buscarBinario(vector + tamano / 2 + 1, tamano - 1 - tamano / 2, elemento);

	}


}

ListaContiguaOrdenada::~ListaContiguaOrdenada() {
	free(lista);
}