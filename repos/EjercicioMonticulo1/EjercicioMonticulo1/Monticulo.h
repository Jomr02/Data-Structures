#pragma once
#include"ListaContigua.h"

class Monticulo
{
private:
	ListaContigua arbol;

	bool esMonticulo(int posicionRaiz);
	void imprimirRecursivo(int posicionRaiz, int tabulaciones);


public:
	
	void imprimir();
	void insertar(int clave);


};

