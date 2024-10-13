#include "Nodo.h"
#include <cassert>

int Nodo::getElemento() {
	return elemento;

}

Nodo* Nodo::getPadre() {
	return punteroPadre;

}

Nodo* Nodo::getHijoIzquierdo() {
	return punteroHijoIzquierdo;

}

Nodo* Nodo::getHijoDerecho() {
	return punteroHijoDerecho;

}

int Nodo::getAltura() {
	return altura;

}

void Nodo::setElemento(int nuevoElemento) {
	elemento = nuevoElemento;

}

void Nodo::setPadre(Nodo* nuevoPadre) {
	punteroPadre = nuevoPadre;

}

void Nodo::setHijoIzquierdo(Nodo* nuevoHijo) {
	punteroHijoIzquierdo = nuevoHijo;

}

void Nodo::setHijoDerecho(Nodo* nuevoHijo) {
	punteroHijoDerecho = nuevoHijo;

}

void Nodo::setAltura(int nuevaAltura) {
	altura = nuevaAltura;

}

int Nodo::calcularAlturaRecursivo(Nodo* nodo) {
	assert(nodo != nullptr);

	int alturaHijoDerecho = -1;
	int alturaHijoIzquierdo = -1;

	if (nodo->getHijoDerecho() != nullptr) {
		alturaHijoDerecho = calcularAlturaRecursivo(nodo->getHijoDerecho());
	}

	if (nodo->getHijoIzquierdo() != nullptr) {
		alturaHijoIzquierdo = calcularAlturaRecursivo(nodo->getHijoIzquierdo());

	}

	if (alturaHijoDerecho > alturaHijoIzquierdo) {
		return alturaHijoDerecho + 1;
	}
	else {
		return alturaHijoIzquierdo + 1;
	}


}

void Nodo::actualizarAltura() {
	int altura = calcularAlturaRecursivo(this);

	setAltura(altura);

}

int Nodo::calcularFactorEquilibrio() {



	int alturaIzquierdo = -1;
	int alturaDerecho = -1;

	if (punteroHijoIzquierdo != nullptr) {
		punteroHijoIzquierdo->actualizarAltura();
		alturaIzquierdo = punteroHijoIzquierdo->altura;
	}

	if (punteroHijoDerecho != nullptr) {
		punteroHijoDerecho->actualizarAltura();
		alturaDerecho = punteroHijoDerecho->altura;

	}

	return (alturaDerecho - alturaIzquierdo);

	

}