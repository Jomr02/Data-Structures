#pragma once
#include "Cola.h"

class ColaDePrioridad
{
private:

	Cola *colaPrioridad;

	int prioridades;
	int n;



public:

	ColaDePrioridad(int nPrioridades);
	void modificaPrioridades(int nPrioridades);
	void push(int prioridad, int elemento);
	int pop();
	void imprimir();
	~ColaDePrioridad();


};


