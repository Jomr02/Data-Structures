#include "ListaEnlazadaSimple.h"
#include "cassert"

Nodo* ListaEnlazadaSimple::getNodo(int posicion) {
	assert(n > 0);
	assert(posicion >= 0 && posicion < n);


	Nodo* nodoBuscado = primerNodo;

	for (int i = 0; i < posicion; i++) {
		nodoBuscado = nodoBuscado->siguienteNodo;
	}

	return nodoBuscado;

}


ListaEnlazadaSimple::ListaEnlazadaSimple() {
	primerNodo = nullptr;
	n = 0;

}
void ListaEnlazadaSimple::setValor(int posicion, int elemento){

	Nodo* nodoBuscado = getNodo(posicion);
	nodoBuscado->elemento = elemento;

}
int ListaEnlazadaSimple::getValor(int posicion) {

	Nodo* nodoBuscado = getNodo(posicion);
	return nodoBuscado->elemento;

}
int ListaEnlazadaSimple::getN() {
	return n;

}
void ListaEnlazadaSimple::insertar(int posicion, int elemento) {
	assert(posicion >= 0 && posicion <= n);

	Nodo* nodoParaInsertar = new Nodo;
	nodoParaInsertar->elemento = elemento;
	nodoParaInsertar->siguienteNodo = nullptr;

	if (n == 0) {
		primerNodo = nodoParaInsertar;

	}
	else {
		if (posicion == 0) {
			Nodo* nodoAux = getNodo(0);
			nodoParaInsertar->siguienteNodo = nodoAux;
			primerNodo = nodoParaInsertar;
		}
		else if (posicion == n) {
			Nodo* nodoAux = getNodo(n-1);
			nodoAux->siguienteNodo = nodoParaInsertar;

		}
		else {
			Nodo* nodoAnterior = getNodo(posicion - 1);
			Nodo* nodoSiguiente = getNodo(posicion);

			nodoAnterior->siguienteNodo = nodoParaInsertar;
			nodoParaInsertar->siguienteNodo = nodoSiguiente;

		}



	}


	n++;

}
void ListaEnlazadaSimple::eliminar(int posicion) {
	assert(n > 0);
	assert(posicion >= 0 && posicion < n);


	if (n == 1) {
		delete(primerNodo);
		primerNodo = nullptr;

	}
	else {
		if (posicion == 0) {
			Nodo* aux = primerNodo;
			primerNodo = aux->siguienteNodo;
			delete (aux);

		}
		else if (posicion == n - 1) {
			Nodo* nodoAnterior = getNodo(n - 2);
			delete (nodoAnterior->siguienteNodo);
			nodoAnterior->siguienteNodo = nullptr;


		}
		else {
			Nodo* nodoAnterior = getNodo(posicion - 1);
			Nodo* nodoParaBorrar = nodoAnterior->siguienteNodo;
			Nodo* nodoSiguiente = nodoParaBorrar->siguienteNodo;

			nodoAnterior->siguienteNodo = nodoSiguiente;
			delete (nodoParaBorrar);

		}

	}

	n--;

}
ListaEnlazadaSimple::~ListaEnlazadaSimple() {
	while (n > 0)
		eliminar(0);

}


