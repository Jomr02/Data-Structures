#include "ArbolBinarioDeBusqueda.h"
#include <cassert>
#include <iostream>
using namespace std;

ArbolBinarioDeBusqueda::ArbolBinarioDeBusqueda() {
	punteroRaiz = nullptr;
	n = 0;
	orientacion = 1;

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

void ArbolBinarioDeBusqueda::borrarRecursivo(Nodo* raiz) {
	assert(raiz != nullptr);

	if (raiz->hijoDerecho == NULL && raiz->hijoIzquierdo == NULL) {

		if (raiz->padre->hijoDerecho == raiz) {
			raiz->padre->hijoDerecho = nullptr;
		}
		else {
			raiz->padre->hijoIzquierdo = nullptr;

		}

		delete raiz;
	}

	//si solo tengo hijo izquierdo
	else if (raiz->hijoDerecho == nullptr) {

		Nodo* nodoMaximo = buscaMaximo(raiz->hijoIzquierdo);

		raiz->elemento = nodoMaximo->elemento;

		borrarRecursivo(nodoMaximo);

		orientacion = 1;
	} 
	//si solo tengo hijo derecho
	else if (raiz->hijoIzquierdo == nullptr) {
		
		Nodo* nodoMinimo = buscaMinimo(raiz->hijoDerecho);

		raiz->elemento = nodoMinimo->elemento;

		borrarRecursivo(nodoMinimo);

		orientacion = -1;

	}
	//si tengo los dos hijos
	else {
		if (orientacion == 1) {
			Nodo* nodoMinimo = buscaMinimo(raiz->hijoDerecho);

			raiz->elemento = nodoMinimo->elemento;

			borrarRecursivo(nodoMinimo);

			orientacion = -1;
		}
		else {
			Nodo* nodoMaximo = buscaMaximo(raiz->hijoIzquierdo);

			raiz->elemento = nodoMaximo->elemento;

			borrarRecursivo(nodoMaximo);

			orientacion = 1;

		}


	}



}

void ArbolBinarioDeBusqueda::borrar(int elemento) {
	assert(buscar(elemento));

	Nodo* nodoParaEliminar = buscarRecursivo(punteroRaiz, elemento);

	borrarRecursivo(nodoParaEliminar);

}


Nodo* ArbolBinarioDeBusqueda::buscaMinimo(Nodo* raiz) {
	assert(raiz != nullptr);

	if (raiz->hijoIzquierdo == nullptr) {
		return raiz;
	}
	else {
		return buscaMinimo(raiz->hijoIzquierdo);
	}


}
Nodo* ArbolBinarioDeBusqueda::buscaMaximo(Nodo* raiz) {
	assert(raiz != nullptr);

	if (raiz->hijoDerecho == nullptr) {
		return raiz;
	}
	else {
		return buscaMaximo(raiz->hijoDerecho);
	}

}


ArbolBinarioDeBusqueda::~ArbolBinarioDeBusqueda() {
	eliminarRecursivo(punteroRaiz);

}