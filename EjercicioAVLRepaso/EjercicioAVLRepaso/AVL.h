#pragma once
#include "Nodo.h"

class AVL
{
	Nodo* punteroPrimerNodo;
	int n;

	void reequilibrar(Nodo* nodoHoja);
	Nodo* rotacionIzquierda(Nodo* raiz);
	Nodo* rotacionDerecha(Nodo* raiz);
	Nodo* rotacionDerechaIzquierda(Nodo* raiz);
	Nodo* rotacionIzquierdaDerecha(Nodo* raiz);
	void cambiarHijo(Nodo* antiguoHijo, Nodo* nuevoHijo);
	Nodo* buscarNodoRecursivo(Nodo* raiz, int elemento);
	void imprimirRecursivo(Nodo* raiz, int tabulaciones);

public:

	AVL();
	void insertar(int elemento);
	bool buscar(int elemento);
	void imprimir();
	~AVL();


};

