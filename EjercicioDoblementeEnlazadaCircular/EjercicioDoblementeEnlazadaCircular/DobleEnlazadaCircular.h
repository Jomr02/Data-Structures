#pragma once
#include "Nodo.h"

class DobleEnlazadaCircular
{
private:
	Nodo* punteroPrimerNodo;
	int n;
	Nodo* punteroUltimoNodoAccedido;
	int posicionUltimoNodoAccedido;


	Nodo* getNodo(int posicion);

public:
	DobleEnlazadaCircular();
	void setValor(int posicion, int elemento);
	int getValor(int posicion);
	int getN();
	void insertar(int posicion, int elemento);
	void eliminar(int posicion);
	void concatenar(DobleEnlazadaCircular* listaConcatenar);
	bool buscar(int elemento);
	~DobleEnlazadaCircular();
};

