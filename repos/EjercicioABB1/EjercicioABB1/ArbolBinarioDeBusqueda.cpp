#include "ArbolBinarioDeBusqueda.h"
#include <cassert>
#include <iostream>
using namespace std;







ArbolBinarioDeBusqueda::ArbolBinarioDeBusqueda() {
	punteroRaiz = nullptr;
	n = 0;

}
Nodo* ArbolBinarioDeBusqueda::buscarRecursivo(Nodo* raiz, int elemento) {
	assert(raiz != nullptr);

	if (raiz->elemento == elemento) {
		return raiz;
	}

	if (raiz->hijoIzquierdo != nullptr) {
		if (elemento < raiz->elemento) {
			return buscarRecursivo(raiz->hijoIzquierdo, elemento);
		}

	}

	if (raiz->hijoDerecho != nullptr) {
		if (elemento > raiz->elemento) {
			return buscarRecursivo(raiz->hijoDerecho, elemento);
		}

	}

	return raiz;
	

}
void ArbolBinarioDeBusqueda::eliminarRecursivo(Nodo* raiz) {
	assert(raiz != nullptr);

	if (raiz->hijoIzquierdo != nullptr) {
		eliminarRecursivo(raiz->hijoIzquierdo);

	}

	if (raiz->hijoDerecho != nullptr) {
		eliminarRecursivo(raiz->hijoDerecho);

	}

	delete raiz;
	n--;

}
void ArbolBinarioDeBusqueda::imprimirRecursivo(Nodo* raiz, int tabulaciones) {

	if (raiz != nullptr) {

		for (int i = 0; i < tabulaciones; i++) {
			cout << "\t";
		}

		cout << raiz->elemento << "\n";

		imprimirRecursivo(raiz->hijoIzquierdo, tabulaciones + 1);
		imprimirRecursivo(raiz->hijoDerecho, tabulaciones + 1);
	}

	

}
void ArbolBinarioDeBusqueda::insertar(int elemento) {

	Nodo* nodoParaInsertar = new Nodo;
	nodoParaInsertar->elemento = elemento;
	nodoParaInsertar->hijoDerecho = nullptr;
	nodoParaInsertar->hijoIzquierdo = nullptr;

	if (n != 0) {
		Nodo* padre = buscarRecursivo(punteroRaiz, elemento);

		nodoParaInsertar->padre = padre;

		if (elemento < padre->elemento) {
			padre->hijoIzquierdo = nodoParaInsertar;
		}
		else {
			padre->hijoDerecho = nodoParaInsertar;
		}

	}
	else {
		punteroRaiz = nodoParaInsertar;

	}


	n++;

}
bool ArbolBinarioDeBusqueda::buscar(int elemento) {

	Nodo* buscado = buscarRecursivo(punteroRaiz, elemento);

	return (buscado != nullptr);


}
void ArbolBinarioDeBusqueda::imprimir() {
	if (n != 0) {
		imprimirRecursivo(punteroRaiz, 0);
	}
	else {
		cout << "Arbol Vacio\n";

	}
}
ArbolBinarioDeBusqueda::~ArbolBinarioDeBusqueda() {
	eliminarRecursivo(punteroRaiz);

}