#pragma once
#define INCREMENTO 2


class Cola
{
private:

	int* cola;
	int capacidad;
	int n;

	void modificaCapacidad(int nuevaCapacidad);

public:

	Cola();
	void push(int elemento);
	int pop();
	int getElemento(int posicion);
	void imprimir();
	int getN();
	~Cola();

};

