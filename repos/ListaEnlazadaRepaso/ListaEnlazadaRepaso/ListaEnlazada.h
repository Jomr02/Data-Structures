#pragma once
#include "Nodo.h"


class ListaEnlazada
{
private:

	Nodo* punteroPrimerNodo;
	int n;


	Nodo* getNodo(int posicion);

public:

	ListaEnlazada();
	void setValor(int posicion, int elemento);
	int getElemento(int posicion);
	int getN();
	void insertar(int posicion, int elemento);
	void eliminar(int posicion);

	~ListaEnlazada();

};

