
#include "Nodo.h"

Nodo::Nodo(int elemento) {
	contenido = elemento;
	padre = NULL;
	hijoDerecho = NULL;
	hijoIzquierdo = NULL;

}

int Nodo::getAlturaSubarbolIzquierdo() {
	int alturaSubarbol;

	if (hijoIzquierdo == NULL) {
		alturaSubarbol = -1;
	}
	else {
		alturaSubarbol = hijoIzquierdo->getAltura();
	}

	return alturaSubarbol;

}
int Nodo::getAlturaSubarbolDerecho() {
	int alturaSubarbol;

	if (hijoDerecho == NULL) {
		alturaSubarbol = -1;
	}
	else {
		alturaSubarbol = hijoDerecho->getAltura();
	}

	return alturaSubarbol;

}


void Nodo::setContenido(int nuevoContenido) {
	contenido = nuevoContenido;

}
void Nodo::setPadre(Nodo* nuevoPadre) {
	padre = nuevoPadre;
}
void Nodo::setHijoIzquierdo(Nodo* nuevoHijoIzquierdo) {
	hijoIzquierdo = nuevoHijoIzquierdo;

}
void Nodo::setHijoDerecho(Nodo* nuevoHijoDerecho) {
	hijoDerecho = nuevoHijoDerecho;
}
void Nodo::actualizarAltura() {
	int alturaSubarbolDerecho = getAlturaSubarbolDerecho();
	int alturaSubarbolIzquierdo = getAlturaSubarbolIzquierdo();
	int alturaMaxima;

	if (alturaSubarbolDerecho >= alturaSubarbolIzquierdo)
		alturaMaxima = alturaSubarbolDerecho;
	else
		alturaMaxima = alturaSubarbolIzquierdo;

	alturaMaxima++;

	altura = alturaMaxima;

}
int Nodo::getFactorEquilibrio() {
	return (getAlturaSubarbolDerecho() - getAlturaSubarbolIzquierdo());
}
int Nodo::getContenido() {
	return contenido;
}
Nodo* Nodo::getPadre() {
	return padre;
}
Nodo* Nodo::getHijoIzquierdo() {
	return hijoIzquierdo;
}
Nodo* Nodo::getHijoDerecho() {
	return hijoDerecho;

}
int Nodo::getAltura() {
	return altura;

}

Nodo::~Nodo() {
	delete (this);
}