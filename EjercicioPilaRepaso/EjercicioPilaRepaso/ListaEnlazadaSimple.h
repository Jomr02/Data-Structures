#pragma once
#include "Nodo.h"


class ListaEnlazadaSimple
{
private:
	Nodo* primerNodo;
	int n; //numero actual de nodos en la lista

	Nodo* getNodo(int posicion);


public:
	ListaEnlazadaSimple();
	void setValor(int posicion, int elemento);
	int getValor(int posicion);
	int getN();
	void insertar(int posicion, int elemento);
	void eliminar(int posicion);
	~ListaEnlazadaSimple();

};

