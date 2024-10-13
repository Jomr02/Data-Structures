#include "Nodo.h"


Nodo::Nodo(int nuevoElemento) {
	elemento = nuevoElemento;
	altura = 0; //siempre insertamos en una hoja al principio

	punteroPadre = nullptr;
	punteroHijoIzquierdo = nullptr;
	punteroHijoDerecho = nullptr;
}


int Nodo::maximo(int n1, int n2) {
	int maximo = n1;

	if (n2 > n1) {
		maximo = n2;
	}

	return maximo;
}

int Nodo::calcularAlturaNodoRecursivo(Nodo* nodo) {
	//si soy una hoja
	if (nodo->punteroHijoIzquierdo == nullptr && nodo->punteroHijoDerecho == nullptr) {
		return 0;

	}
	//si solo tengo hijo izquierdo
	else if (nodo->punteroHijoIzquierdo != nullptr && nodo->punteroHijoDerecho == nullptr) {
		return 1 + calcularAlturaNodoRecursivo(nodo->punteroHijoIzquierdo);

	}
	//si tengo hijo derecho
	else if (nodo->punteroHijoIzquierdo == nullptr && nodo->punteroHijoDerecho != nullptr) {
		return 1 + calcularAlturaNodoRecursivo(nodo->punteroHijoDerecho);

	}
	//si tengo dos hijos
	else {
		int alturaArbolIzquierdo = calcularAlturaNodoRecursivo(nodo->punteroHijoIzquierdo);
		int alturaArbolDerecho = calcularAlturaNodoRecursivo(nodo->punteroHijoDerecho);

		int altura = maximo(alturaArbolIzquierdo, alturaArbolDerecho);

		return 1 + altura;

	}

}

int Nodo::calcularAlturaNodo() {
	int nuevaAltura = calcularAlturaNodoRecursivo(this);

	altura = nuevaAltura;

	return altura;

}
int Nodo::calcularFactorEquilibrio() {

	int alturaArbolDerecho = -1;
	int alturaArbolIzquierdo = -1;

	if (punteroHijoIzquierdo != nullptr) {
		alturaArbolIzquierdo = punteroHijoIzquierdo->altura;
	}

	if (punteroHijoDerecho != nullptr) {
		alturaArbolDerecho = punteroHijoDerecho->altura;
	}

	return (alturaArbolDerecho - alturaArbolIzquierdo);

}

int Nodo::getAltura() {
	return altura;

}
void Nodo::setAltura(int nuevaAltura) {
	altura = nuevaAltura;

}
int Nodo::getElemento() {
	return elemento;

}
void Nodo::setElemento(int nuevoElemento) {
	elemento = nuevoElemento;

}
Nodo* Nodo::getPadre() {
	return punteroPadre;

}
void Nodo::setPadre(Nodo* nuevoPadre) {
	punteroPadre = nuevoPadre;

}
Nodo* Nodo::getHijoIzquierdo() {
	return punteroHijoIzquierdo;

}
void Nodo::sethijoIzquierdo(Nodo* hijoIzquierdo) {
	punteroHijoIzquierdo = hijoIzquierdo;

}
Nodo* Nodo::getHijoDerecho() {
	return punteroHijoDerecho;

}
void Nodo::setHijoDerecho(Nodo* hijoDerecho) {
	punteroHijoDerecho = hijoDerecho;

}
