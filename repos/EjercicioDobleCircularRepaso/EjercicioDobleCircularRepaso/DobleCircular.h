#pragma once
#include "Nodo.h"

class DobleCircular
{
private:

	Nodo* punteroPrimerNodo;

	int posicionUltimoNodoAccedido;
	Nodo* punteroUltimoNodoAccedido;

	int n;

	Nodo* getNodo(int posicion);

public:

	DobleCircular();
	void setValor(int posicion, int elemento);
	int getElemento(int posicion);
	int getN();
	void insertar(int posicion, int elemento);
	void eliminar(int posicion);
	int buscar(int elemento);
	void concatenar(DobleCircular* lista);
	~DobleCircular();
};

