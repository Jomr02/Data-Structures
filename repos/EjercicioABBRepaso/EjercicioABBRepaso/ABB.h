#pragma once
#include "Nodo.h"

class ABB
{
private:

	Nodo* punteroPrimerNodo;
	int n;
	int orientacion;

	Nodo* buscarRecursivo(Nodo* raiz, int elemento);
	void imprimirRecursivo(Nodo* raiz, int tabulaciones, int izquierdoOderecho); //-1 izquierdo, 0 sin padre, 1 derecho
	void eliminarRecursivo(Nodo* raiz);
	Nodo* maximoSubArbol(Nodo* raiz);
	Nodo* minimoSubArbol(Nodo* raiz);

public:

	ABB();
	void insertar(int elementoParaInsertar);
	void eliminar(int elementoParaEliminar);
	bool buscar(int elementoBuscado);
	void imprimir();
	~ABB();
};

