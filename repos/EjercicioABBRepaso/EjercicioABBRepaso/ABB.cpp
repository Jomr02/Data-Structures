#include "ABB.h"
#include <cassert>
#include <iostream>
using namespace std;




ABB::ABB() {
	punteroPrimerNodo = nullptr;
	n = 0;
	orientacion = 1;

}
Nodo* ABB::buscarRecursivo(Nodo* raiz, int elemento) {
	assert(raiz != nullptr);

	if ((raiz->elemento == elemento) || ((raiz->punteroHijoIzquierdo == nullptr) && (raiz->punteroHijoDerecho == nullptr))) {
		return raiz;
	}

	if ((elemento < raiz->elemento) && (raiz->punteroHijoIzquierdo != nullptr)) {
		return buscarRecursivo(raiz->punteroHijoIzquierdo, elemento);

	}
	else if ((elemento > raiz->elemento) && (raiz->punteroHijoDerecho != nullptr)){
		return buscarRecursivo(raiz->punteroHijoDerecho, elemento);

	}

	return raiz;

}
void ABB::imprimirRecursivo(Nodo* raiz, int tabulaciones, int izquierdoOderecho) { //-1 izquierdo, 0 sin padre, 1 derecho
	assert(raiz != nullptr);

	for (int i = 0; i < tabulaciones; i++) {
		cout << "\t";
	}

	cout << raiz->elemento;

	if (izquierdoOderecho == -1) {
		cout << " (Izquierdo)";

	}

	if ((izquierdoOderecho) == 1) {
		cout << " (Derecho)";

	}


	cout << "\n";

	if (raiz->punteroHijoIzquierdo != nullptr) {
		imprimirRecursivo(raiz->punteroHijoIzquierdo, tabulaciones + 1, -1);

	}

	if (raiz->punteroHijoDerecho != nullptr) {
		imprimirRecursivo(raiz->punteroHijoDerecho, tabulaciones + 1, 1);

	}

	

}


void ABB::eliminarRecursivo(Nodo* raiz) {
	assert(raiz != nullptr);

	if (raiz->punteroHijoIzquierdo == nullptr && raiz->punteroHijoDerecho == nullptr) {
		
		if (raiz->punteroPadre != nullptr) {
			if (raiz->punteroPadre->punteroHijoDerecho == raiz) {
				raiz->punteroPadre->punteroHijoDerecho = nullptr;

			}
			else {
				raiz->punteroPadre->punteroHijoIzquierdo = nullptr;

			}
		}

		delete raiz;
	}
	else {

		if (raiz->punteroHijoIzquierdo != nullptr && raiz->punteroHijoDerecho != nullptr) {

			if (orientacion == 1) { //minimo subarbol derecho
				Nodo* minimoDerecho = minimoSubArbol(raiz->punteroHijoDerecho);

				raiz->elemento = minimoDerecho->elemento;

				orientacion = -1;

				eliminarRecursivo(minimoDerecho);
			}
			else { // maximo subarbolizquierdo

				Nodo* maximoIzquierdo = maximoSubArbol(raiz->punteroHijoIzquierdo);

				raiz->elemento = maximoIzquierdo->elemento;

				orientacion = 1;

				eliminarRecursivo(maximoIzquierdo);
			}

		}
		else {
			if (raiz->punteroHijoIzquierdo != nullptr) {
				Nodo* maximoIzquierdo = maximoSubArbol(raiz->punteroHijoIzquierdo);

				raiz->elemento = maximoIzquierdo->elemento;

				orientacion = 1;

				eliminarRecursivo(maximoIzquierdo);

			}
			else {
				Nodo* minimoDerecho = minimoSubArbol(raiz->punteroHijoDerecho);

				raiz->elemento = minimoDerecho->elemento;

				orientacion = -1;

				eliminarRecursivo(minimoDerecho);
			}

		}


	}

}
Nodo* ABB::maximoSubArbol(Nodo* raiz) {
	assert(raiz != nullptr);


	while (raiz->punteroHijoDerecho != nullptr) {
		raiz = raiz->punteroHijoDerecho;

	}

	return raiz;


}
Nodo* ABB::minimoSubArbol(Nodo* raiz) {
	assert(raiz != nullptr);

	while (raiz->punteroHijoIzquierdo != nullptr) {
		raiz = raiz->punteroHijoIzquierdo;

	}

	return raiz;

}
void ABB::insertar(int elementoParaInsertar) {
	assert(!buscar(elementoParaInsertar));

	Nodo* nodoParaInsertar = new Nodo;
	nodoParaInsertar->elemento = elementoParaInsertar;
	nodoParaInsertar->punteroHijoIzquierdo = nullptr;
	nodoParaInsertar->punteroHijoDerecho = nullptr;
	nodoParaInsertar->punteroPadre = nullptr;

	if (n == 0) {
		punteroPrimerNodo = nodoParaInsertar;

	}
	else {

		Nodo* nodoPadre = buscarRecursivo(punteroPrimerNodo, elementoParaInsertar);

		nodoParaInsertar->punteroPadre = nodoPadre;

		if (elementoParaInsertar < nodoPadre->elemento) {
			nodoPadre->punteroHijoIzquierdo = nodoParaInsertar;

		}
		else {
			nodoPadre->punteroHijoDerecho = nodoParaInsertar;

		}

	}

	n++;

}

void ABB::imprimir() {
	
	if (n == 0) {
		cout << "Arbol Vacio";
	}
	else {
		imprimirRecursivo(punteroPrimerNodo, 0, 0);
	}

}

void ABB::eliminar(int elementoParaEliminar) {
	assert(buscar(elementoParaEliminar));

	Nodo* nodoParaEliminar = buscarRecursivo(punteroPrimerNodo, elementoParaEliminar);

	eliminarRecursivo(nodoParaEliminar);

	n--;

}
bool ABB::buscar(int elementoBuscado) {

	if (n > 0) {
		Nodo* nodo = buscarRecursivo(punteroPrimerNodo, elementoBuscado);

		return (nodo->elemento == elementoBuscado);
	}
	else {
		return false;

	}

}
ABB::~ABB() {

}