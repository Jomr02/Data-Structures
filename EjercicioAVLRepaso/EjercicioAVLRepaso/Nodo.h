#pragma once
class Nodo
{
private:

	int elemento;
	Nodo* punteroPadre;
	Nodo* punteroHijoIzquierdo;
	Nodo* punteroHijoDerecho;
	int altura;

	int calcularAlturaRecursivo(Nodo* nodo);

public:

	int getElemento();
	Nodo* getPadre();
	Nodo* getHijoIzquierdo();
	Nodo* getHijoDerecho();
	int getAltura();
	void setElemento(int nuevoElemento);
	void setPadre(Nodo* nuevoPadre);
	void setHijoIzquierdo(Nodo* nuevoHijo);
	void setHijoDerecho(Nodo* nuevoHijo);
	void setAltura(int nuevaAltura);
	void actualizarAltura();
	int calcularFactorEquilibrio();

};

