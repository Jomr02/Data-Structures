#pragma once
#include "ListaEnlazadaSimple.h"

class Pila
{
private:

	ListaEnlazadaSimple lista;


public:

	void push(int elemento);
	int pop();
	int verCima();
	bool isVacia();
	ListaEnlazadaSimple* getLista();

};

