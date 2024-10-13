#pragma once
#include "string"
#include "ListaContigua.h"

using namespace std;

class Grafo
{
private:
	string nodos;
	ListaContigua* matriz;
	int n;

	bool existeNodo(char nodo);
	bool existeArco(char nodoOrigen, char nodoDestino);
	int posicionNodo(char nodo);

public:

	Grafo();
	void insertarNodo(char nodo);
	void insertarArco(char nodoOrigen, char nodoDestino);
	void eliminaNodo(char nodo);
	void eliminaArco(char nodoOrigen, char nodoDestino);
	void imprimir();
	~Grafo();

};

