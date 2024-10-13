#pragma once
#include "Nodo.h"

class ArbolGenealogico
{

private:
	Nodo* punteroPrimerNodo;
	int n;

	int getNumeroHijosDirectos(Nodo* padre);
	Nodo* getHijoDirecto(Nodo* padre, int posicion);
	Nodo* buscarRecursivo(Nodo* raiz, string nombre);
	void imprimirRecursivo(Nodo* raiz, int tabulaciones);
	void eliminarSubArbolRecursivo(Nodo* raiz);

public:
	ArbolGenealogico(string nombreRaiz);
	void insertar(string nombrePadre, string nombre);
	void imprimir();
	~ArbolGenealogico();

};

