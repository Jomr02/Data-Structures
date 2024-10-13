#pragma once
#include "ListaContigua.h"

class Monticulo
{
private:
	ListaContigua monticulo;

	void imprimirRecursivo(int posicion, int tabulaciones);
	bool esMonticulo(int posicion);
	void reestructurar();
	void intercambiar(int posicion1, int posicion2);

public:

	void insertar(int elemento);
	int borrar();
	int getRaiz();
	void imprimir();
	
};

