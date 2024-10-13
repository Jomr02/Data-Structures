#include "ListaEnlazada.h"
#include "cassert"





ListaEnlazada::ListaEnlazada() {
	punteroPrimerNodo = nullptr;
	n = 0;


}

Nodo* ListaEnlazada::getNodo(int posicion) {
	assert(posicion >= 0);
	assert(posicion < n);

	Nodo* nodoSeleccionado = punteroPrimerNodo;
	

	for (int i = 0; i < posicion; i++) {
		nodoSeleccionado = nodoSeleccionado->nodoSiguiente;
	}

	return nodoSeleccionado;

}
void ListaEnlazada::setValor(int posicion, int elemento) {
	assert(posicion >= 0);
	assert(posicion < n);

	Nodo* nodoSeleccionado = getNodo(posicion);

	nodoSeleccionado->elemento = elemento;

}
int ListaEnlazada::getElemento(int posicion) {
	assert(posicion >= 0);
	assert(posicion < n);

	Nodo* nodoSeleccionado = getNodo(posicion);


	return nodoSeleccionado->elemento;

}
int ListaEnlazada::getN() {
	return n;

}
void ListaEnlazada::insertar(int posicion, int elemento) {
	assert(posicion >= 0);
	assert(posicion <= n);

	Nodo* nodoParaInsertar = new Nodo;
	nodoParaInsertar->elemento = elemento;
	nodoParaInsertar->nodoSiguiente = nullptr;


	if (n == 0) {
		punteroPrimerNodo = nodoParaInsertar;

	}
	else {
		if (posicion == 0) {
			nodoParaInsertar->nodoSiguiente = punteroPrimerNodo;
			punteroPrimerNodo = nodoParaInsertar;

		}
		else if (posicion == n) {
			Nodo* ultimoNodo = getNodo(n - 1);
			ultimoNodo->nodoSiguiente = nodoParaInsertar;

		}
		else {
			Nodo* nodoAnterior = getNodo(posicion - 1);
			Nodo* nodoSiguiente = nodoAnterior->nodoSiguiente;

			nodoAnterior->nodoSiguiente = nodoParaInsertar;
			nodoParaInsertar->nodoSiguiente = nodoSiguiente;

		}


	}



	n++;

}
void ListaEnlazada::eliminar(int posicion) {
	assert(n > 0);
	assert(posicion >= 0);
	assert(posicion < n);

	Nodo* nodoParaEliminar = nullptr;

	if (n == 1) {
		nodoParaEliminar = punteroPrimerNodo;
		punteroPrimerNodo = nullptr;
	}
	else if (posicion == 0){
		nodoParaEliminar = punteroPrimerNodo;
		punteroPrimerNodo = punteroPrimerNodo->nodoSiguiente;

	} 
	else if (posicion == (n - 1)) {
		Nodo* nodoAnterior = getNodo(n - 2);
		nodoParaEliminar = nodoAnterior->nodoSiguiente;

		nodoAnterior->nodoSiguiente = nullptr;

	}
	else {
		Nodo* nodoAnterior = getNodo(posicion - 1);
		nodoParaEliminar = nodoAnterior->nodoSiguiente;
		Nodo* nodoSiguiente = nodoParaEliminar->nodoSiguiente;

		nodoAnterior->nodoSiguiente = nodoSiguiente;

	}

	delete nodoParaEliminar;
	n--;
}

ListaEnlazada::~ListaEnlazada() {
	while (n > 0) 
		eliminar(0);

	

}

