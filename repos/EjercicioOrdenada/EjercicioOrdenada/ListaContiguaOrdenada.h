#pragma once
#include "cassert"
#define INCREMENTO 2

class ListaContiguaOrdenada
{
private:

	int* lista;
	int capacidad;
	int n;

	void aumentaCapacidad(int incremento);

public:

	ListaContiguaOrdenada();

	int getElemento(int posicion);
	void setElemento(int posicion, int elemento);
	void insertar(int elemento);
	void eliminar(int posicion);
	int getN();
	int getCapacidad();
	void concatenar(ListaContiguaOrdenada* listaConcatenar);
	int buscar(int elemento);
	int buscarBinario(int* vector, int tamano, int elemento);

	~ListaContiguaOrdenada();

};

