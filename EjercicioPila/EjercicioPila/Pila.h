#pragma once

#include "Nodo.h"

class Pila
{
private:
	Nodo* punteroPrimerNodo;
	Nodo* punteroUltimoNodo;
	int n;

public:


	Pila();
	void push(int elemento);
	int pop();
	int verCima();
	bool isVacia();
	void imprimePila();
	~Pila();


};

