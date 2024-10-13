#pragma once
#include "Nodo.h"

class ArbolGenealogico
{
private:
	Nodo* punteroRaiz;
	int n;

	int getNumeroHijos(Nodo* padre);
	Nodo* getHijo(Nodo* padre, int nHijo);
	Nodo* buscar(Nodo* raiz, string nombre);
	void imprimirSubArbol(Nodo* raiz, int tabulacion);
	void eliminarSubarbol(Nodo* raiz);

public:

	ArbolGenealogico(string nombre);
	void insertar(string nombre, string nombrePadre);
	void imprimir();
	~ArbolGenealogico();

};

