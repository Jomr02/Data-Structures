#pragma once
#include "Nodo.h"

class ArbolBinarioDeBusqueda
{

	Nodo* punteroRaiz;
	int n;


	Nodo* buscarRecursivo(Nodo* raiz, int elemento);
	void eliminarRecursivo(Nodo* raiz);
	void imprimirRecursivo(Nodo* raiz, int tabulaciones);


public:

	ArbolBinarioDeBusqueda();
	void insertar(int elemento);
	bool buscar(int elemento);
	void imprimir();
	~ArbolBinarioDeBusqueda();

};

