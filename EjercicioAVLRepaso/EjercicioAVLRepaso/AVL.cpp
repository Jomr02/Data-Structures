#include "AVL.h"
#include <cassert>
#include <iostream>
using namespace std;

AVL::AVL() {
	punteroPrimerNodo = nullptr;
	n = 0;

}
void AVL::reequilibrar(Nodo* nodoHoja) {
	
	if (nodoHoja != nullptr) {
		int factorEquilibrio = nodoHoja->calcularFactorEquilibrio();

		if (factorEquilibrio == 2 && nodoHoja->getHijoDerecho()->calcularFactorEquilibrio() == 1) {
			nodoHoja = rotacionIzquierda(nodoHoja);

		}
		else if (factorEquilibrio == -2 && nodoHoja->getHijoIzquierdo()->calcularFactorEquilibrio() == -1) {
			nodoHoja = rotacionDerecha(nodoHoja);

		}
		else if (factorEquilibrio == 2 && nodoHoja->getHijoDerecho()->calcularFactorEquilibrio() == -1) {
			nodoHoja = rotacionDerechaIzquierda(nodoHoja);

		}
		else if (factorEquilibrio == -2 && nodoHoja->getHijoIzquierdo()->calcularFactorEquilibrio() == 1) {
			nodoHoja = rotacionIzquierdaDerecha(nodoHoja);

		}

		nodoHoja->actualizarAltura();
		reequilibrar(nodoHoja->getPadre());
		
		

	}

}
Nodo* AVL::rotacionIzquierda(Nodo* raiz) {
	assert(raiz != nullptr);

	Nodo* x = raiz;
	Nodo* y = x->getHijoDerecho();
	Nodo* A = x->getHijoIzquierdo();
	Nodo* B = y->getHijoIzquierdo();
	Nodo* C = y->getHijoDerecho();

	if (x == punteroPrimerNodo) {
		punteroPrimerNodo = y;
	}

	cambiarHijo(x, y);
	y->setHijoIzquierdo(x);
	x->setHijoDerecho(B);
	x->setPadre(y);
	if (B != nullptr)
		B->setPadre(x);

	return y;

}
Nodo* AVL::rotacionDerecha(Nodo* raiz) {
	assert(raiz != nullptr);

	
	Nodo* y = raiz;
	Nodo* x = y->getHijoIzquierdo();
	Nodo* A = x->getHijoIzquierdo();
	Nodo* B = x->getHijoDerecho();
	Nodo* C = y->getHijoDerecho();

	if (y == punteroPrimerNodo) {
		punteroPrimerNodo = x;
	}

	cambiarHijo(y, x);
	x->setHijoDerecho(y);
	y->setPadre(x);
	y->setHijoIzquierdo(B);
	if (B != nullptr) {
		B->setPadre(y);
	}
	

	return x;

}
Nodo* AVL::rotacionDerechaIzquierda(Nodo* raiz) {
	assert(raiz != nullptr);

	Nodo* x = raiz;
	Nodo* z = x->getHijoDerecho();
	Nodo* y = z->getHijoIzquierdo();
	Nodo* A = x->getHijoIzquierdo();
	Nodo* B = y->getHijoIzquierdo();
	Nodo* C = y->getHijoDerecho();
	Nodo* D = z->getHijoDerecho();

	if (x == punteroPrimerNodo) {
		punteroPrimerNodo = y;
	}

	cambiarHijo(x, y);
	z->setHijoIzquierdo(C);
	if (C != nullptr) {
		C->setPadre(z);
	}
	x->setHijoDerecho(B);
	if (B != nullptr) {
		B->setPadre(x);
	}
	y->setHijoDerecho(z);
	z->setPadre(y);
	y->setHijoIzquierdo(x);
	x->setPadre(y);

	return y;

}
Nodo* AVL::rotacionIzquierdaDerecha(Nodo* raiz) {
	assert(raiz != nullptr);

	Nodo* z = raiz;
	Nodo* x = z->getHijoIzquierdo();
	Nodo* y = x->getHijoDerecho();
	Nodo* A = x->getHijoIzquierdo();
	Nodo* B = y->getHijoIzquierdo();
	Nodo* C = y->getHijoDerecho();
	Nodo* D = z->getHijoDerecho();

	if (z == punteroPrimerNodo) {
		punteroPrimerNodo = y;
	}

	cambiarHijo(z, y);
	x->setHijoDerecho(B);
	if (B != nullptr) {
		B->setPadre(x);
	}
	z->setHijoIzquierdo(C);
	if (C != nullptr) {
		C->setPadre(z);
	}
	y->setHijoIzquierdo(x);
	x->setPadre(y);
	y->setHijoDerecho(z);
	z->setPadre(y);

	return y;


}
void AVL::cambiarHijo(Nodo* antiguoHijo, Nodo* nuevoHijo) {
	//el padre de antiguoHijo apunta a nuevoHijo
	assert(antiguoHijo != nullptr);
	assert(nuevoHijo != nullptr);

	Nodo* padreAntiguoHijo = antiguoHijo->getPadre();

	
	if (padreAntiguoHijo != nullptr) {
		if (padreAntiguoHijo->getHijoIzquierdo() == antiguoHijo) {
			padreAntiguoHijo->setHijoIzquierdo(nuevoHijo);
		}
		else {
			padreAntiguoHijo->setHijoDerecho(nuevoHijo);

		}

	}


	nuevoHijo->setPadre(padreAntiguoHijo);

}
Nodo* AVL::buscarNodoRecursivo(Nodo* raiz, int elemento) {
	assert(raiz != nullptr);

	int elementoNodo = raiz->getElemento();

	if (elementoNodo == elemento) {
		return raiz;

	}

	if ((elemento < elementoNodo) && (raiz->getHijoIzquierdo() != nullptr)) {
		return buscarNodoRecursivo(raiz->getHijoIzquierdo(), elemento);

	}

	if ((elemento > elementoNodo) && (raiz->getHijoDerecho() != nullptr)) {
		return buscarNodoRecursivo(raiz->getHijoDerecho(), elemento);

	}

	return raiz;

}
void AVL::insertar(int elemento) {
	assert(!buscar(elemento));

	Nodo* nodoParaInsertar = new Nodo;
	nodoParaInsertar->setElemento(elemento);
	nodoParaInsertar->setHijoIzquierdo(nullptr);
	nodoParaInsertar->setHijoDerecho(nullptr);
	nodoParaInsertar->setPadre(nullptr);
	nodoParaInsertar->setAltura(0);


	if (n == 0) {
		punteroPrimerNodo = nodoParaInsertar;

	}
	else {
		Nodo* nodoPadre = buscarNodoRecursivo(punteroPrimerNodo, elemento);
		nodoParaInsertar->setPadre(nodoPadre);

		if (elemento < nodoPadre->getElemento()) {
			nodoPadre->setHijoIzquierdo(nodoParaInsertar);

		}
		else {
			nodoPadre->setHijoDerecho(nodoParaInsertar);

		}
	}

	if (n > 0) {
		reequilibrar(nodoParaInsertar);

	}
	

	n++;


}
bool AVL::buscar(int elemento) {
	
	if (n == 0) {
		return false;

	}

	Nodo* nodo = buscarNodoRecursivo(punteroPrimerNodo, elemento);

	return (nodo->getElemento() == elemento);

}

void AVL::imprimirRecursivo(Nodo* raiz, int tabulaciones) {
	assert(raiz != nullptr);

	for (int i = 0; i < tabulaciones; i++) {
		cout << "\t";

	}

	cout << raiz->getElemento() << endl;

	if (raiz->getHijoIzquierdo() != nullptr) {
		imprimirRecursivo(raiz->getHijoIzquierdo(), tabulaciones + 1);
	}

	if (raiz->getHijoDerecho() != nullptr) {
		imprimirRecursivo(raiz->getHijoDerecho(), tabulaciones + 1);
	}


}

void AVL::imprimir() {

	if (n == 0) {
		cout << "Arbol Vacio";

	}
	else {
		imprimirRecursivo(punteroPrimerNodo, 0);

	}

	cout << endl;


}
AVL::~AVL() {


}