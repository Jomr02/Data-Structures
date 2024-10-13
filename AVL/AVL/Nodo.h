#pragma once
#include <iostream>


class Nodo {
	int contenido;
	Nodo* padre;
	Nodo* hijoIzquierdo;
	Nodo* hijoDerecho;

	int altura;
	
	int getAlturaSubarbolIzquierdo ();
	int getAlturaSubarbolDerecho();

public:

	Nodo(int elemento);

	void setContenido(int nuevoContenido);
	void setPadre(Nodo* nuevoPadre);
	void setHijoIzquierdo(Nodo* nuevoHijoIzquierdo);
	void setHijoDerecho(Nodo* nuevoHijoDerecho);
	void actualizarAltura();
	int getFactorEquilibrio();
	int getContenido();
	Nodo* getPadre();
	Nodo* getHijoIzquierdo();
	Nodo* getHijoDerecho();
	int getAltura();

	~Nodo();


};


