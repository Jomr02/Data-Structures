#pragma once
#include "Nodo.h"

class ArbolBinarioDeBusqueda
{

	Nodo* punteroRaiz;
	int n;
	int orientacion;


	Nodo* buscarRecursivo(Nodo* raiz, int elemento);
	void eliminarRecursivo(Nodo* raiz);
	void imprimirRecursivo(Nodo* raiz, int tabulaciones);
	void borrarRecursivo(Nodo* raiz);
	Nodo* buscaMinimo(Nodo* raiz);
	Nodo* buscaMaximo(Nodo* raiz);


public:

	ArbolBinarioDeBusqueda();
	void insertar(int elemento);
	bool buscar(int elemento);
	void borrar(int elemento);
	void imprimir();
	~ArbolBinarioDeBusqueda();

};

