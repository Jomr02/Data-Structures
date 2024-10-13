#pragma once

class Nodo
{
private:

	int elemento;
	int altura;

	Nodo* punteroPadre;
	Nodo* punteroHijoIzquierdo;
	Nodo* punteroHijoDerecho;

	int calcularAlturaNodoRecursivo(Nodo* nodo);
	int maximo(int n1, int n2);



public:

	Nodo(int nuevoElemento);
	int calcularAlturaNodo();
	int calcularFactorEquilibrio();

	int getAltura();
	void setAltura(int nuevaAltura);
	int getElemento();
	void setElemento(int nuevoElemento);
	Nodo* getPadre();
	void setPadre(Nodo* nuevoPadre);
	Nodo* getHijoIzquierdo();
	void sethijoIzquierdo (Nodo* hijoIzquierdo);
	Nodo* getHijoDerecho();
	void setHijoDerecho(Nodo* hijoDerecho);
	

};

