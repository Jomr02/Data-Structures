#include "ListaContigua.h"
#include "cassert"
#include <malloc.h>
#include "string.h"






ListaContigua::ListaContigua() {
	n = 0;
	capacidad = 0;
	lista = nullptr;

}

void ListaContigua::incrementarCapacidad(int incremento) {

	int nuevaCapacidad = capacidad + incremento;

	lista = (int*) realloc(lista, (nuevaCapacidad) * sizeof(int));


	capacidad = nuevaCapacidad;
}

int ListaContigua::getElemento(int posicion) {
	assert(posicion >= 0);
	assert(posicion < n);
	assert(n > 0);

	return lista[posicion];


}
void ListaContigua::setElemento(int posicion, int elemento) {
	assert(posicion >= 0);
	assert(posicion < n);
	assert(n > 0);

	lista[posicion] = elemento;

}
void ListaContigua::insertar(int posicion, int elemento) {
	assert(posicion >= 0);
	assert(posicion <= n);
	
	if (capacidad == n) {
		incrementarCapacidad(INCREMENTO);
	}

	if (posicion != n) {
		memmove(lista + posicion + 1, lista + posicion, (n - posicion) * sizeof(int));

	}

	lista[posicion] = elemento;

	n++;

}
void ListaContigua::eliminar(int posicion) {
	assert(posicion >= 0);
	assert(posicion < n);
	assert(n > 0);

	memmove(lista + posicion, lista + posicion + 1, (n - posicion - 1) * sizeof(int));

	if (capacidad - n == 2 * INCREMENTO) {
		incrementarCapacidad(-INCREMENTO);
	}

	n--;

}
void ListaContigua::insertarAlFinal(int elemento) {
	insertar(n, elemento);

}
void ListaContigua::eliminarAlFinal() {
	eliminar(n - 1);

}
int ListaContigua::buscar(int elementoParaBuscar) {

	int posicionElementoBuscado = -1;

	for (int i = 0; i < n; i++) {

		if (lista[i] == elementoParaBuscar) {
			posicionElementoBuscado = i;
			break;

		}

	}


	return posicionElementoBuscado;

}
int ListaContigua::getN() {
	return n;

}
int ListaContigua::getCapacidad() {
	return capacidad;

}

void ListaContigua::concatenar(ListaContigua* listaParaConcatenar) {

	int numeroElementosListaConcatenar = listaParaConcatenar->getN();

	for (int i = 0; i < numeroElementosListaConcatenar; i++) {
		insertarAlFinal(listaParaConcatenar->getElemento(i));
	}


}


ListaContigua::~ListaContigua() {
	free (lista);
}