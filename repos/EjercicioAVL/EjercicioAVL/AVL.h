#pragma once
#include "Nodo.h"

class AVL
{
	int n;
	Nodo* punteroRaiz;
	int orientacion;

	Nodo* insertarHoja(int elemento);
	void reequilibrar(Nodo* nodo);
	void cambiarHijo(Nodo* antiguoHijo, Nodo* nuevoHijo);
	void imprimirRecursivo(Nodo* nodo, int tabulaciones);
	Nodo* buscarRecursivo(Nodo* nodo, int elemento);
	Nodo* rotacionSimpleIzquierda(Nodo* raiz);
	Nodo* rotacionSimpleDerecha(Nodo* raiz);
	Nodo* rotacionCompuestaIzquierdaDerecha(Nodo* raiz);
	Nodo* rotacionCompuestaDerechaIzquierda(Nodo* raiz);
	Nodo* eliminarRecursivo(Nodo *nodoParaEliminar);
	Nodo* calcularMinimoSubArbol(Nodo* raizSubArbol);
	Nodo* calcularMaximoSubArbol(Nodo* raizSubArbol);

public:

	AVL();
	void insertar(int elemento);
	void eliminar(int elemento);
	void imprimir();
	bool buscar(int elemento);

};

