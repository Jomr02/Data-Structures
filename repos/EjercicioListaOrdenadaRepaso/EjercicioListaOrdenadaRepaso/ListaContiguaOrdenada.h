#pragma once
#include "ListaContigua.h"

class ListaContiguaOrdenada
{
private:
	ListaContigua* lista;


	int busquedaBinaria(int elemento, int inicioSubVector, int tamano);

public:

	ListaContiguaOrdenada();
	int buscar(int elemento);
	void eliminar(int elemento);
	void insertar(int elemento);
	void imprimir();
	~ListaContiguaOrdenada();

};

