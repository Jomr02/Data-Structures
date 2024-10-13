#include "ArbolGenealogico.h"
#include <cassert>
#include <iostream>


ArbolGenealogico::ArbolGenealogico(string nombreRaiz) {
	
	Nodo* nodo = new Nodo;

	nodo->nombre = nombreRaiz;
	nodo->punteroHermanoDerecho = nullptr;
	nodo->punteroPadre = nullptr;
	nodo->punteroPrimerHijo = nullptr;

	punteroPrimerNodo = nodo;

	n = 1;

}

int ArbolGenealogico::getNumeroHijosDirectos(Nodo* padre) {
	assert(padre != nullptr);

	int nHijos = 0;

	Nodo* nodoHijo = padre->punteroPrimerHijo;

	while (nodoHijo != nullptr) {
		nodoHijo = nodoHijo->punteroHermanoDerecho;
		nHijos++;
	}

	
	return nHijos;

}
Nodo* ArbolGenealogico::getHijoDirecto(Nodo* padre, int posicion){
	assert(padre != nullptr);
	int nHijos = getNumeroHijosDirectos(padre);
	assert(nHijos > 0);
	assert(posicion >= 0);
	assert(posicion < nHijos);

	Nodo* nodoHijo = padre->punteroPrimerHijo;

	for (int i = 0; i < posicion; i++) {
		nodoHijo = nodoHijo->punteroHermanoDerecho;
	}
	
	return nodoHijo;

}

Nodo* ArbolGenealogico::buscarRecursivo(Nodo* raiz, string nombre) {
	assert(raiz != nullptr);

	if (nombre.compare(raiz->nombre) == 0) {
		return raiz;

	}

	int nHijos = getNumeroHijosDirectos(raiz);


	for (int i = 0; i < nHijos; i++) {
		Nodo* nodo = buscarRecursivo(getHijoDirecto(raiz, i), nombre);

		if (nodo != nullptr) {
			return nodo;
		}
	}
	

	return nullptr;


}
void ArbolGenealogico::imprimirRecursivo(Nodo* raiz, int tabulaciones) {
	assert(raiz != nullptr);

	for (int i = 0; i < tabulaciones; i++) {
		cout << "\t";
	}

	cout << raiz->nombre;

	cout << "\n";

	int nHijos = getNumeroHijosDirectos(raiz);

	for (int j = 0; j < nHijos; j++) {
		imprimirRecursivo(getHijoDirecto(raiz, j), tabulaciones + 1);
	}

}
void ArbolGenealogico::eliminarSubArbolRecursivo(Nodo* raiz) {
	assert(raiz != nullptr);

	int nHijos = getNumeroHijosDirectos(raiz);

	if (nHijos == 0) {
		if (punteroPrimerNodo != raiz) {
			if (raiz->punteroPadre->punteroPrimerHijo == raiz) {
				raiz->punteroPadre->punteroPrimerHijo = nullptr;
			}
			else {
				int indice;
				int nHijosPadre = getNumeroHijosDirectos(raiz->punteroPadre);

				for (int i = 0; i < nHijosPadre; i++) {
					if (getHijoDirecto(raiz->punteroPadre, i) == raiz) {
						indice = i;
					}
				}
				Nodo* hermanoIzquierdo = getHijoDirecto(raiz->punteroPadre, indice - 1);

				hermanoIzquierdo->punteroHermanoDerecho = nullptr;
			}
		}
		n--;
		delete raiz;
	}
	else {
		for (int i = nHijos - 1; i >= 0; i--) {
			eliminarSubArbolRecursivo(getHijoDirecto(raiz, i));

		}
		
		eliminarSubArbolRecursivo(raiz);

	}

}


void ArbolGenealogico::insertar(string nombrePadre, string nombre) {

	Nodo* nodoPadre = buscarRecursivo(punteroPrimerNodo, nombrePadre);

	assert(nodoPadre != nullptr);

	Nodo* nodoParaInsertar = new Nodo;
	nodoParaInsertar->nombre = nombre;
	nodoParaInsertar->punteroHermanoDerecho = nullptr;
	nodoParaInsertar->punteroPrimerHijo = nullptr;
	nodoParaInsertar->punteroPadre = nodoPadre;

	int nHijos = getNumeroHijosDirectos(nodoPadre);

	if (nHijos > 0) {
		Nodo* punteroUltimoHijo = getHijoDirecto(nodoPadre, nHijos - 1);
		punteroUltimoHijo->punteroHermanoDerecho = nodoParaInsertar;
	}
	else {
		nodoPadre->punteroPrimerHijo = nodoParaInsertar;

	}

}
void ArbolGenealogico::imprimir() {
	imprimirRecursivo(punteroPrimerNodo, 0);

}
ArbolGenealogico::~ArbolGenealogico() {
	eliminarSubArbolRecursivo(punteroPrimerNodo);

}