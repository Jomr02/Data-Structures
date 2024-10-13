#pragma once
#include "ListaContigua.h"
#include "string"

using namespace std;

class Grafo
{
private:
	ListaContigua* matriz;
	string nodos;
	int n;

	bool existeNodo(char nodo);
	int getPosicionNodo(char nodo);

public:

	Grafo();
	void insertarNodo(char nodo);
	void insertarArco(char nodoOrigen, char nodoDestino);
	void eliminarNodo(char nodo);
	void eliminarArco(char nodoOrigen, char nodoDestino);
	void imprimir();
	~Grafo();

};

