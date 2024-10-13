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
	string recorridoProfundidadRecursivo(int posicionNodo,bool* vistos);
	int calcularGradoEntradaNodo(int posicionNodo, bool* borrados);
	string recorridoTopologicoRecursivo(int posicionNodo, bool *borrados);

public:

	Grafo();
	void insertarNodo(char nodo);
	void insertarArco(char nodoOrigen, char nodoDestino);
	void eliminaNodo(char nodo);
	void eliminaArco(char nodoOrigen, char nodoDestino);
	void imprimir();
	char* recorridoProfundidad(char nodo);
	string recorridoAnchura(char nodo);
	string recorridoTopologico();

	~Grafo();

};

