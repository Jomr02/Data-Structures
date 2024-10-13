#include "AVL.h"
#include <cassert>
#include <iostream>
#include <iostream>
using namespace std;


AVL::AVL() {
	n = 0;
	punteroRaiz = nullptr;
	orientacion = 1;

}

Nodo* AVL::eliminarRecursivo(Nodo* nodoParaEliminar) {
	assert(nodoParaEliminar != nullptr);


	if (nodoParaEliminar->getHijoIzquierdo() == nullptr && nodoParaEliminar->getHijoDerecho() == nullptr) {
		Nodo* padre = nodoParaEliminar->getPadre();
		
		if (padre != nullptr){
			if (padre->getHijoIzquierdo() == nodoParaEliminar) {
				padre->sethijoIzquierdo(nullptr);
			}
			else {
				padre->setHijoDerecho(nullptr);

			}
		}
		
		delete nodoParaEliminar;
		return padre;


	}
	else if ((nodoParaEliminar->getHijoIzquierdo() != nullptr && nodoParaEliminar->getHijoDerecho() != nullptr && orientacion == 1) || (nodoParaEliminar->getHijoIzquierdo() == nullptr && nodoParaEliminar->getHijoDerecho() != nullptr)) {
		Nodo* minimo = calcularMinimoSubArbol(nodoParaEliminar->getHijoDerecho());

		nodoParaEliminar->setElemento(minimo->getElemento());

		Nodo* padre = eliminarRecursivo(minimo);

		orientacion = -1;
		return padre;
	}
	else {
		Nodo* maximo = calcularMaximoSubArbol(nodoParaEliminar->getHijoIzquierdo());

		nodoParaEliminar->setElemento(maximo->getElemento());

		Nodo* padre = eliminarRecursivo(maximo);

		orientacion = 1;

		return padre;
	}



}
void AVL::eliminar(int elemento) {
	assert(buscar(elemento));

	Nodo* nodoParaEliminar = buscarRecursivo(punteroRaiz, elemento);
	Nodo* nodoPadreHojaEliminada = eliminarRecursivo(nodoParaEliminar);

	while (nodoPadreHojaEliminada != nullptr) {
		nodoPadreHojaEliminada->calcularAlturaNodo();
		reequilibrar(nodoPadreHojaEliminada);
		nodoPadreHojaEliminada = nodoPadreHojaEliminada->getPadre();
	}

	n--;


}

Nodo* AVL::calcularMinimoSubArbol(Nodo* raizSubArbol) {
	assert(raizSubArbol != nullptr);

	if (raizSubArbol->getHijoIzquierdo() == nullptr) {
		return raizSubArbol;
	}
	else {
		return calcularMinimoSubArbol(raizSubArbol->getHijoIzquierdo());
	}

}
Nodo* AVL::calcularMaximoSubArbol(Nodo* raizSubArbol) {
	assert(raizSubArbol != nullptr);


	if (raizSubArbol->getHijoDerecho() == nullptr) {
		return raizSubArbol;
	}
	else {
		return calcularMaximoSubArbol(raizSubArbol->getHijoDerecho());
	}

}

Nodo* AVL::insertarHoja(int elemento) {

	Nodo* nodoParaInsertar = new Nodo(elemento);

	if (n == 0) {
		punteroRaiz = nodoParaInsertar;
	}
	else {
		Nodo* nodoPadre = buscarRecursivo(punteroRaiz, elemento);
		nodoParaInsertar->setPadre(nodoPadre);

		if (elemento > nodoPadre->getElemento()) {
			nodoPadre->setHijoDerecho(nodoParaInsertar);
		}
		else {
			nodoPadre->sethijoIzquierdo(nodoParaInsertar);

		}

	}

	return nodoParaInsertar;

}
void AVL::reequilibrar(Nodo* nodo){
	assert(nodo != nullptr);


		int factorEquilibrio = nodo->calcularFactorEquilibrio();

		if (factorEquilibrio == 2) {
			if (nodo->getHijoDerecho()->calcularFactorEquilibrio() == 1) {
				rotacionSimpleIzquierda(nodo);
			}
			else if (nodo->getHijoDerecho()->calcularFactorEquilibrio() == -1) {
				rotacionCompuestaDerechaIzquierda(nodo);
			}
			else if (nodo->getHijoDerecho()->calcularFactorEquilibrio() == 0) {
				rotacionSimpleIzquierda(nodo);

			}


		}
		else if (factorEquilibrio == -2) {
			if (nodo->getHijoIzquierdo()->calcularFactorEquilibrio() == -1) {
				rotacionSimpleDerecha(nodo);

			}
			else if (nodo->getHijoIzquierdo()->calcularFactorEquilibrio() == 1) {
				rotacionCompuestaIzquierdaDerecha(nodo);

			}
			else if (nodo->getHijoIzquierdo()->calcularFactorEquilibrio() == 0) {
				rotacionSimpleDerecha(nodo);

			}

		}

	

}
void AVL::cambiarHijo(Nodo* antiguoHijo, Nodo* nuevoHijo) {

	Nodo* padreAntiguoHijo = antiguoHijo->getPadre();

	nuevoHijo->setPadre(padreAntiguoHijo);
	
	if (padreAntiguoHijo != nullptr) {
		if (padreAntiguoHijo->getHijoIzquierdo() == antiguoHijo) {
			padreAntiguoHijo->sethijoIzquierdo(nuevoHijo);

		}
		else {
			padreAntiguoHijo->setHijoDerecho(nuevoHijo);

		}
	}
	else {
		punteroRaiz = nuevoHijo;

	}

}


void AVL::imprimirRecursivo(Nodo* nodo, int tabulaciones) {
	assert(nodo != nullptr);


	for (int i = 0; i < tabulaciones; i++) {
		cout << "\t";
	}

	cout << nodo->getElemento();

	cout << "\n";

	if (nodo->getHijoIzquierdo() != nullptr) {
		imprimirRecursivo(nodo->getHijoIzquierdo(), tabulaciones + 1);

	}

	if (nodo->getHijoDerecho() != nullptr) {
		imprimirRecursivo(nodo->getHijoDerecho(), tabulaciones + 1);
	}




}
Nodo* AVL::buscarRecursivo(Nodo* nodo, int elemento) {
	assert(nodo != nullptr);

	if (nodo->getElemento() == elemento) {
		return nodo;
	}

	if (nodo->getHijoIzquierdo() == nullptr && nodo->getHijoDerecho() == nullptr) {
		return nodo;
	}

	if (elemento > nodo->getElemento() && nodo->getHijoDerecho() == nullptr) {
		return nodo;

	}

	if (elemento < nodo->getElemento() && nodo->getHijoIzquierdo() == nullptr) {
		return nodo;

	}

	if (elemento > nodo->getElemento()) {
		return buscarRecursivo(nodo->getHijoDerecho(), elemento);
	}
	else {
		return buscarRecursivo(nodo->getHijoIzquierdo(), elemento);

	}
	

}
Nodo* AVL::rotacionSimpleIzquierda(Nodo* raiz) {
	assert(raiz != nullptr);

	Nodo* x = raiz;
	Nodo* y = x->getHijoDerecho();
	Nodo* A = x->getHijoIzquierdo();
	Nodo* B = y->getHijoIzquierdo();
	Nodo* C = y->getHijoDerecho();

	cambiarHijo(x, y);
	if (B != nullptr) {
		B->setPadre(x);
	}
	x->setHijoDerecho(B);
	y->sethijoIzquierdo(x);
	x->setPadre(y);

	x->calcularAlturaNodo();
	y->calcularAlturaNodo();

	return y;


}
Nodo* AVL::rotacionSimpleDerecha(Nodo* raiz) {
	assert(raiz != nullptr);

	Nodo* y = raiz;
	Nodo* x = raiz->getHijoIzquierdo();
	Nodo* A = x->getHijoIzquierdo();
	Nodo* B = x->getHijoDerecho();
	Nodo* C = y->getHijoDerecho();

	cambiarHijo(y, x);
	y->setPadre(x);
	x->setHijoDerecho(y);
	y->sethijoIzquierdo(B);
	if (B != nullptr) {
		B->setPadre(y);
	}

	x->calcularAlturaNodo();
	y->calcularAlturaNodo();

	return x;

}
Nodo* AVL::rotacionCompuestaIzquierdaDerecha(Nodo* raiz) {
	assert(raiz != nullptr);

	Nodo* z = raiz;
	Nodo* x = z->getHijoIzquierdo();
	Nodo* y = x->getHijoDerecho();
	Nodo* A = x->getHijoIzquierdo();
	Nodo* B = y->getHijoIzquierdo();
	Nodo* C = y->getHijoDerecho();
	Nodo* D = z->getHijoDerecho();

	cambiarHijo(z, y);
	z->sethijoIzquierdo(C);
	if (C != nullptr) {
		C->setPadre(z);
	}
	x->setHijoDerecho(B);
	if (B != nullptr) {
		B->setPadre(x);
	}
	y->sethijoIzquierdo(x);
	x->setPadre(y);
	y->setHijoDerecho(z);
	z->setPadre(y);

	x->calcularAlturaNodo();
	y->calcularAlturaNodo();
	z->calcularAlturaNodo();

	return y;
}
Nodo* AVL::rotacionCompuestaDerechaIzquierda(Nodo* raiz) {
	assert(raiz != nullptr);

	Nodo* x = raiz;
	Nodo* z = x->getHijoDerecho();
	Nodo* y = z->getHijoIzquierdo();
	Nodo* A = x->getHijoIzquierdo();
	Nodo* B = y->getHijoIzquierdo();
	Nodo* C = y->getHijoDerecho();
	Nodo* D = z->getHijoDerecho();


	cambiarHijo(x, y);
	x->setHijoDerecho(B);
	if (B != nullptr) {
		B->setPadre(x);
	}
	z->sethijoIzquierdo(C);
	if (C != nullptr) {
		C->setPadre(z);
	}
	y->sethijoIzquierdo(x);
	x->setPadre(y);
	y->setHijoDerecho(z);
	z->setPadre(y);

	x->calcularAlturaNodo();
	y->calcularAlturaNodo();
	z->calcularAlturaNodo();

	return y;

}
void AVL::insertar(int elemento) {
	assert(!buscar(elemento));

	Nodo* nodoInsertado = insertarHoja(elemento);
	while (nodoInsertado != nullptr) {
		nodoInsertado->calcularAlturaNodo();
		reequilibrar(nodoInsertado);
		nodoInsertado = nodoInsertado->getPadre();
	}
	n++;


}
void AVL::imprimir() {
	imprimirRecursivo(punteroRaiz, 0);

}
bool AVL::buscar(int elemento) {

	if (n > 0) {
		Nodo* nodoBuscado = buscarRecursivo(punteroRaiz, elemento);

		return (nodoBuscado->getElemento() == elemento);
	}
	else {
		return false;
	}


}