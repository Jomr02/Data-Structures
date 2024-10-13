#include "DobleCircular.h"
#include "cassert"





DobleCircular::DobleCircular() {

	punteroPrimerNodo = nullptr;
	punteroUltimoNodoAccedido = nullptr;

	posicionUltimoNodoAccedido = -1;
	n = 0;

}
Nodo* DobleCircular::getNodo(int posicion) {
	assert(n > 0);
	assert(posicion >= 0);
	assert(posicion < n);

	Nodo* nodoParaDevolver = nullptr;

	if (posicionUltimoNodoAccedido == posicion) {
		nodoParaDevolver = punteroUltimoNodoAccedido;

	}
	else {

		if (posicion <= (n)) {
			nodoParaDevolver = punteroPrimerNodo;

			for (int i = 0; i < posicion; i++) {
				nodoParaDevolver = nodoParaDevolver->nodoSiguiente;
				
			}

		}
		else {
			nodoParaDevolver = punteroPrimerNodo->nodoAnterior;

			for (int i = n - 1; i > posicion; i--) {
				nodoParaDevolver = nodoParaDevolver->nodoAnterior;
				
			}


		}

		punteroUltimoNodoAccedido = nodoParaDevolver;
		posicionUltimoNodoAccedido = posicion;

	}



	return nodoParaDevolver;


}
void DobleCircular::setValor(int posicion, int elemento) {
	assert(n > 0);
	assert(posicion >= 0);
	assert(posicion < n);


	Nodo* nodo = getNodo(posicion);
	nodo->elemento = elemento;

}
int DobleCircular::getElemento(int posicion) {
	assert(n > 0);
	assert(posicion >= 0);
	assert(posicion < n);


	Nodo* nodo = getNodo(posicion);

	return nodo->elemento;

}
int DobleCircular::getN() {
	return n;

}
void DobleCircular::insertar(int posicion, int elemento) {
	assert(posicion >= 0);
	assert(posicion <= n);




	Nodo* nodoParaInsertar = new Nodo;
	nodoParaInsertar->elemento = elemento;
	nodoParaInsertar->nodoSiguiente = nullptr;
	nodoParaInsertar->nodoAnterior = nullptr;


	if (n == 0) {
		punteroPrimerNodo = nodoParaInsertar;

		nodoParaInsertar->nodoAnterior = nodoParaInsertar;
		nodoParaInsertar->nodoSiguiente = nodoParaInsertar;
	}
	else {

		if (posicion == 0) {
			Nodo* ultimoNodo = getNodo(n - 1);

			nodoParaInsertar->nodoSiguiente = punteroPrimerNodo;
			punteroPrimerNodo = nodoParaInsertar;
			nodoParaInsertar->nodoAnterior = ultimoNodo;
			ultimoNodo->nodoSiguiente = nodoParaInsertar;

		}
		else if (posicion == n) {
			Nodo* ultimoNodo = getNodo(n - 1);

			ultimoNodo->nodoSiguiente = nodoParaInsertar;
			nodoParaInsertar->nodoAnterior = ultimoNodo;

			punteroPrimerNodo->nodoAnterior = nodoParaInsertar;
			nodoParaInsertar->nodoSiguiente = punteroPrimerNodo;

		}
		else {
			Nodo* nodoAnterior = getNodo(posicion - 1);
			Nodo* nodoSiguiente = getNodo(posicion);

			nodoAnterior->nodoSiguiente = nodoParaInsertar;
			nodoParaInsertar->nodoAnterior = nodoAnterior;

			nodoParaInsertar->nodoSiguiente = nodoSiguiente;
			nodoSiguiente->nodoAnterior = nodoParaInsertar;


		}

	}

	punteroUltimoNodoAccedido = nullptr;
	posicionUltimoNodoAccedido = -1;


	n++;
}
void DobleCircular::eliminar(int posicion) {
	assert(n > 0);
	assert(posicion >= 0);
	assert(posicion < n);

	Nodo* nodoParaEliminar = getNodo(posicion);

	if (n == 1) {
		punteroPrimerNodo = nullptr;
	}
	else {
		if (posicion == 0) {
			Nodo* ultimoNodo = getNodo(n - 1);
			Nodo* nodoSiguiente = punteroPrimerNodo->nodoSiguiente;

			ultimoNodo->nodoSiguiente = nodoSiguiente;
			nodoSiguiente->nodoAnterior = ultimoNodo;

			punteroPrimerNodo = nodoSiguiente;


		}
		else if (posicion == n - 1) {
			Nodo* penultimoNodo = getNodo(n - 2);

			penultimoNodo->nodoSiguiente = punteroPrimerNodo;
			punteroPrimerNodo->nodoAnterior = penultimoNodo;

		}
		else {
			Nodo* nodoAnterior = getNodo(posicion - 1);
			Nodo* nodoSiguiente = getNodo(posicion + 1);

			nodoAnterior->nodoSiguiente = nodoSiguiente;
			nodoSiguiente->nodoAnterior = nodoAnterior;


		}

	}


	punteroUltimoNodoAccedido = nullptr;
	posicionUltimoNodoAccedido = -1;

	delete nodoParaEliminar;
	n--;

}
int DobleCircular::buscar(int elemento) {

	int posicion = -1;

	for (int i = 0; i < n; i++) {

		if (getNodo(i)->elemento = elemento) {
			posicion = i;
			break;
		}
	}

	return posicion;

}
void DobleCircular::concatenar(DobleCircular* lista) {
	assert(lista != nullptr);


	int nLista = lista->getN();

	for (int i = 0; i < nLista; i++) {
		insertar(n, lista->getElemento(i));
	}


}
DobleCircular::~DobleCircular() {
	
	while (n > 0) {
		eliminar(0);

	}
	
}