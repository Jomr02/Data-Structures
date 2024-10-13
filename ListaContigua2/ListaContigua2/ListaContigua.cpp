#include "ListaContigua.h"
#include <cassert>
#include <malloc.h>
#include <vcruntime_string.h>


ListaContigua::ListaContigua() {
	lista = nullptr;
	n = 0;
	capacidad = 0;
}
int ListaContigua::getElemento(int posicion) {
	assert(posicion >= 0 && posicion < n);
	assert(!esVacia());

	return (lista[posicion]);


}

void ListaContigua::aumentaCapacidad(int incremento) {
	lista = (int*)realloc(lista, (capacidad + incremento) * sizeof(int));

	capacidad = capacidad + incremento;
}

void ListaContigua::setElemento(int posicion, int elemento) {
	assert(posicion >= 0 && posicion < n);
	assert(!esVacia());

	lista[posicion] = elemento;

}
void ListaContigua::insertarAlFinal(int elemento) {
	insertar(n, elemento);

}

void ListaContigua::eliminarAlFinal() {
	eliminar(n - 1);

}
void ListaContigua::insertar(int posicion, int elemento) {
	assert(posicion >= 0 && posicion <= n);

	if (n == capacidad) {
		aumentaCapacidad(INCREMENTO);
	}

	//si insertamos al final
	if (posicion == n) {
		lista[posicion] = elemento;
	}
	else {
		memmove(lista + posicion + 1, lista +posicion, (n - posicion) * sizeof(int));
		lista[posicion] = elemento;
	}

	n++;


}
void ListaContigua::eliminar(int posicion) {
	assert(posicion >= 0 && posicion < n);

	if (posicion == n - 1) {
		n--;

	}
	else {
		memmove(lista + posicion, lista + posicion + 1, (n - posicion - 1) * sizeof(int));
		n--;
	}

	

	if (capacidad - n == 2 * INCREMENTO) {
		aumentaCapacidad(-INCREMENTO);

	}

}
void ListaContigua::concatenar(ListaContigua* listaConcatenar) {
	assert(listaConcatenar != nullptr);

	int longitudListaConcatenar = listaConcatenar->getN();

	for (int i = 0; i < longitudListaConcatenar; i++) {
		insertarAlFinal(listaConcatenar->getElemento(i));
	}

}
int ListaContigua::buscar(int elemento) {

	int posicionElemento = -1;

	for (int i = 0; i < n; i++) {
		if (lista[i] == elemento) {
			posicionElemento = i;

		}

	}

	return posicionElemento;

}
int ListaContigua::getN() {
	return n;

}
int ListaContigua::getCapacidad() {
	return capacidad;

}

bool ListaContigua::esVacia() {
	return (n == 0);
}

ListaContigua::~ListaContigua() {
	free(lista);

}