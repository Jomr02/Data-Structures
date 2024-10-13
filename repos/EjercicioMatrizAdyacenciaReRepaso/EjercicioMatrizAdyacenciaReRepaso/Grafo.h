#pragma once
#include "ListaContigua.h"
#include "string"

using namespace std;

class Grafo
{
private:

	string nodos;
	ListaContigua* matriz;
	int n;

	bool existeNodo(char letraNodo);
	bool existeArco(char nodoOrigen, char nodoDestino);
	int getPosicionNodo(char letraNodo);

public:

	Grafo();
	void insertarNodo(char letraNodo);
	void eliminarNodo(char letraNodo);
	void insertarArco(char nodoOrigen, char nodoDestino);
	void eliminarArco(char nodoOrigen, char nodoDestino);
	void imprimir();
	~Grafo();

};

