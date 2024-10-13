#include "ArbolGenealogico.h"

#include <string>
#include <cassert>
#include <iostream>

using namespace std;

ArbolGenealogico::ArbolGenealogico(string nombre) {

	Nodo* raiz = new Nodo;
	raiz->nombre = nombre;
	raiz->punteroHermanoDerecho = NULL;
	raiz->punteroPadre = NULL;
	raiz->punteroPrimerHijo = NULL;


	punteroRaiz = raiz;

	n = 1;

}
int ArbolGenealogico::getNumeroHijos(Nodo* padre) {
	assert(padre != NULL);

	
	if (padre->punteroPrimerHijo == NULL) {
		return 0;
	}

	int nHijos = 1;
	Nodo* hijo = padre->punteroPrimerHijo;



	while (hijo->punteroHermanoDerecho != NULL) {

		hijo = hijo->punteroHermanoDerecho;
		nHijos++;
	}


	return nHijos;
}
Nodo* ArbolGenealogico::getHijo(Nodo* padre, int nHijo) {
	assert(padre != NULL);
	assert(getNumeroHijos(padre) > 0);
	assert(nHijo < getNumeroHijos(padre));

	Nodo* hijo = padre->punteroPrimerHijo;

	for (int i = 0; i < nHijo; i++) {
		hijo = hijo->punteroHermanoDerecho;
	}


	return hijo;

}
Nodo* ArbolGenealogico::buscar(Nodo* raiz, string nombre) {
	assert(raiz != NULL);


	if (raiz->nombre.compare(nombre) == 0) {
		return raiz;

	}

	int nHijos = getNumeroHijos(raiz);

	if (nHijos == 0) {
		return NULL;
	}

	for (int i = 0; i < nHijos; i++) {
		Nodo * nodo = buscar(getHijo(raiz, i), nombre);

		if (nodo != NULL) {
			return nodo;
		}

	}

	return NULL;

}
void ArbolGenealogico::imprimirSubArbol(Nodo* raiz, int tabulacion) {

	for (int i = 0; i < tabulacion; i++) {

		cout << "\t";
	}

	cout << raiz->nombre;

	cout << "\n";

	int nHijos = getNumeroHijos(raiz);

	for (int i = 0; i < nHijos; i++) {
		imprimirSubArbol(getHijo(raiz, i), tabulacion + 1);
	}

	

}
void ArbolGenealogico::eliminarSubarbol(Nodo* raiz) {
	assert(raiz != NULL);

	int nHijos = getNumeroHijos(raiz);


	for (int i = nHijos - 1; i >= 0; i--) {


		Nodo* hijoActual = getHijo(raiz, i);

		if (i == 0) hijoActual->punteroPadre->punteroPrimerHijo = NULL;
		else getHijo(raiz, i - 1)->punteroHermanoDerecho = NULL;

		eliminarSubarbol(hijoActual);
	}

	delete raiz;
	n--;

}
void ArbolGenealogico::insertar(string nombre, string nombrePadre) {
	assert(buscar(punteroRaiz, nombrePadre) != NULL);


	Nodo* padre = buscar(punteroRaiz, nombrePadre);
	int nHijos = getNumeroHijos(padre);


	Nodo *nodoParaInsertar = new Nodo;
	nodoParaInsertar->nombre = nombre;
	nodoParaInsertar->punteroHermanoDerecho = NULL;
	nodoParaInsertar->punteroPadre = padre;
	nodoParaInsertar->punteroPrimerHijo = NULL;

	if (nHijos == 0) {
		padre->punteroPrimerHijo = nodoParaInsertar;

	}
	else {
		Nodo* ultimoHijo = getHijo (padre, nHijos - 1);

		ultimoHijo->punteroHermanoDerecho = nodoParaInsertar;

	}

	n++;

}
void ArbolGenealogico::imprimir() {
	imprimirSubArbol(punteroRaiz, 0);

}
ArbolGenealogico::~ArbolGenealogico() {
	eliminarSubarbol(punteroRaiz);

}