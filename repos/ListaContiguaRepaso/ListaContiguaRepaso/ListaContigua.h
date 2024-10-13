#pragma once

#define INCREMENTO 2


class ListaContigua
{
private:

	int* lista;
	int capacidad;
	int n;

	void incrementarCapacidad(int incremento);

public:

	ListaContigua();
	int getElemento(int posicion);
	void setElemento(int posicion, int elemento);
	void insertar(int posicion, int elemento);
	void eliminar(int posicion);
	void insertarAlFinal(int elemento);
	void eliminarAlFinal();
	int buscar(int elementoParaBuscar);
	int getN();
	int getCapacidad();
	void concatenar(ListaContigua* listaParaConcatenar);


	~ListaContigua();

};

