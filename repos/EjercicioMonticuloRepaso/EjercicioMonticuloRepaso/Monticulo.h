#pragma once
#include "ListaContigua.h"
class Monticulo
{
private:
	ListaContigua monticulo;

	bool esMonticulo(int posicionRaiz);
	void reestructurar(int posicionRaiz);
	void imprimirRecursivo(int posicionRaiz, int tabulaciones);

public:

	void insertar(int elemento);
	int borrar();
	int getRaiz(int posicionRaiz);
	void imprimir();

};

