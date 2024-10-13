#pragma once

#define INCREMENTO 2

class ListaContigua
{
private:
	int* lista;
	int n;
	int capacidad;

	void aumentaCapacidad(int incremento);

public:

	ListaContigua();
	int getElemento(int posicion);
	void setElemento(int posicion, int elemento);
	void insertarAlFinal(int elemento);
	void eliminarAlFinal();
	void insertar(int posicion, int elemento);
	void eliminar(int posicion);
	void concatenar(ListaContigua *listaConcatenar);
	int buscar(int elemento);
	int getN();
	int getCapacidad();
	bool esVacia();
	void imprimir();

	~ListaContigua();

};

