#include "DobleEnlazadaCircular.h"
#include "cassert"


DobleEnlazadaCircular::DobleEnlazadaCircular() {
	punteroPrimerNodo = nullptr;
	punteroUltimoNodoAccedido = nullptr;
	n = 0;
	posicionUltimoNodoAccedido = -1;


}


Nodo* DobleEnlazadaCircular::getNodo(int posicion) {
	assert(posicion >= 0);
	assert(posicion < n);

	
	if (posicion == posicionUltimoNodoAccedido)
		return punteroUltimoNodoAccedido;

	if ((posicion - 1) == (posicionUltimoNodoAccedido - 1))
		return punteroUltimoNodoAccedido->punteroNodoAnterior;

	if ((posicion + 1) == (posicionUltimoNodoAccedido + 1))
		return punteroUltimoNodoAccedido->punteroNodoSiguiente;
	

	Nodo* nodoEncontrado;

	if (posicion <= n / 2) {
		nodoEncontrado = punteroPrimerNodo;
		for (int i = 0; i < posicion; i++) {
			nodoEncontrado = nodoEncontrado->punteroNodoSiguiente;
		}

	}
	else {
		nodoEncontrado = punteroPrimerNodo->punteroNodoAnterior;

		for (int i = n - 1; i > posicion; i--) {
			nodoEncontrado = nodoEncontrado->punteroNodoAnterior;

		}
	}

	


	punteroUltimoNodoAccedido = nodoEncontrado;
	posicionUltimoNodoAccedido = posicion;

	return nodoEncontrado;

}

void DobleEnlazadaCircular::setValor(int posicion, int elemento){
	assert(posicion >= 0);
	assert(posicion < n);

	Nodo* nodoSet = getNodo(posicion);

	nodoSet->elemento = elemento;

}
int DobleEnlazadaCircular::getValor(int posicion) {
	assert(posicion >= 0);
	assert(posicion < n);

	Nodo* nodoGet = getNodo(posicion);

	return nodoGet->elemento;
}
int DobleEnlazadaCircular::getN() {
	return n;

}
void DobleEnlazadaCircular::insertar(int posicion, int elemento) {
	assert(posicion >= 0);
	assert(posicion <= n);

	Nodo* nodoInsertar = new Nodo;
	nodoInsertar->punteroNodoAnterior = nullptr;
	nodoInsertar->punteroNodoSiguiente = nullptr;
	nodoInsertar->elemento = elemento;

	if (n == 0) {
		punteroPrimerNodo = nodoInsertar;
		nodoInsertar->punteroNodoSiguiente = nodoInsertar;
		nodoInsertar->punteroNodoAnterior = nodoInsertar;

	}
	else {
		if (posicion == 0) {
			Nodo* nodoUltimo = punteroPrimerNodo->punteroNodoAnterior;

			nodoInsertar->punteroNodoSiguiente = punteroPrimerNodo;
			nodoInsertar->punteroNodoAnterior = nodoUltimo;
			nodoUltimo->punteroNodoSiguiente = nodoInsertar;

			punteroPrimerNodo = nodoInsertar;

		}
		else if (posicion == n) {
			Nodo* nodoUltimo = punteroPrimerNodo->punteroNodoAnterior;

			nodoUltimo->punteroNodoSiguiente = nodoInsertar;
			nodoInsertar->punteroNodoAnterior = nodoUltimo;
			nodoInsertar->punteroNodoSiguiente = punteroPrimerNodo;
			punteroPrimerNodo->punteroNodoAnterior = nodoInsertar;

		}
		else {
			Nodo* nodoSiguiente = getNodo(posicion);
			Nodo* nodoAnterior = getNodo(posicion -1);

			nodoAnterior->punteroNodoSiguiente = nodoInsertar;
			nodoInsertar->punteroNodoAnterior = nodoAnterior;

			nodoSiguiente->punteroNodoAnterior = nodoInsertar;
			nodoInsertar->punteroNodoSiguiente = nodoSiguiente;

		}


	}


	n++;
}
void DobleEnlazadaCircular::eliminar(int posicion) {
	assert(posicion >= 0);
	assert(posicion < n);
	assert(n > 0);

	Nodo* nodoParaEliminar;

	if (n == 1) {
		nodoParaEliminar = punteroPrimerNodo;
		punteroPrimerNodo = nullptr;
	}
	else {
		if (posicion == 0) {
			nodoParaEliminar = punteroPrimerNodo;
			Nodo* nodoUltimo = punteroPrimerNodo->punteroNodoAnterior;
			Nodo* nodoSiguiente = punteroPrimerNodo->punteroNodoSiguiente;

			nodoUltimo->punteroNodoSiguiente = nodoSiguiente;
			nodoSiguiente->punteroNodoAnterior = nodoUltimo;

			punteroPrimerNodo = nodoSiguiente;

		}
		else if (posicion == (n - 1)) {
			nodoParaEliminar = punteroPrimerNodo->punteroNodoAnterior;
			Nodo* nodoAnterior = getNodo(posicion - 1);

			nodoAnterior->punteroNodoSiguiente = punteroPrimerNodo;
			punteroPrimerNodo->punteroNodoAnterior = nodoAnterior;

		}
		else {
			nodoParaEliminar = getNodo(posicion);
			Nodo* nodoAnterior = nodoParaEliminar->punteroNodoAnterior;
			Nodo* nodoSiguiente = nodoParaEliminar->punteroNodoSiguiente;

			nodoAnterior->punteroNodoSiguiente = nodoSiguiente;
			nodoSiguiente->punteroNodoAnterior = nodoAnterior;





		}



	}

	delete (nodoParaEliminar);

	n--;
}

bool DobleEnlazadaCircular::buscar(int elemento) {

	bool encontrado = false;
	int contador = 0;
	Nodo* nodoAux;

	while (!encontrado && contador < n) {
		nodoAux = getNodo(contador);
		if (nodoAux->elemento == elemento) {
			encontrado = true;
		}

		contador++;
	}


	return encontrado;

}

void DobleEnlazadaCircular::concatenar(DobleEnlazadaCircular* listaConcatenar) {
	assert(listaConcatenar != nullptr);

	int longitudListaParaInsertar = listaConcatenar->getN();
	int elemento;

	for (int i = 0; i < longitudListaParaInsertar; i++) {
		elemento = listaConcatenar->getValor(i);

		insertar(n, elemento);
	}



}


DobleEnlazadaCircular::~DobleEnlazadaCircular() {
	while (n > 0)
		eliminar(0);


}