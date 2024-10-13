#include "Grafo.h"
#include "cassert"
#include <iostream>


Grafo::Grafo() {
	n = 0;
	matriz = nullptr;
	nodos = "";

}

bool Grafo::existeNodo(char nodo) {
	
	bool existe = false;

	for (int i = 0; i < n; i++) {
		char nodoAux = nodos.at(i);
		if (nodoAux == nodo) {
			existe = true;
			break;
		}

	}

	return existe;
}

int Grafo::posicionNodo(char nodo) {
	assert(existeNodo(nodo));

	int posicion = -1;

	for (int i = 0; i < n; i++) {
		char nodoAux = nodos.at(i);
		if (nodoAux == nodo) {
			posicion = i;
			break;
		}

	}

	return posicion;

}

bool Grafo::existeArco(char nodoOrigen, char nodoDestino) {
	assert(existeNodo(nodoOrigen));
	assert(existeNodo(nodoDestino));

	int posicionOrigen = posicionNodo(nodoOrigen);
	int posicionDestino = posicionNodo(nodoDestino);

	return (matriz[posicionOrigen].getValor(posicionDestino) != 0);

}
void Grafo::insertarNodo(char nodo) {


	for (int i = 0; i < n; i++) {
		matriz[i].insertarAlFinal(0);
	}

	n++;

	matriz = (ListaContigua*) realloc(matriz, n * sizeof(ListaContigua));

	ListaContigua *nuevaFila = new ListaContigua;

	for (int i = 0; i < n; i++) {
		nuevaFila->insertarAlFinal(0);
	}

	matriz[n-1] = *nuevaFila;

	nodos.append(1, nodo);

}

void Grafo::insertarArco(char nodoOrigen, char nodoDestino) {
	assert(!existeArco(nodoOrigen, nodoDestino));

	int posicionOrigen = posicionNodo(nodoOrigen);
	int posicionDestino = posicionNodo(nodoDestino);

	matriz[posicionOrigen].setValor(posicionDestino, 1);

}

void Grafo::eliminaNodo(char nodo) {
	assert(existeNodo(nodo));

	int posicionNodoParaBorrar = posicionNodo(nodo);

	for (int i = 0; i < n; i++) {
		matriz[i].eliminar(posicionNodoParaBorrar);

	}

	memmove(&matriz[posicionNodoParaBorrar], &matriz[posicionNodoParaBorrar + 1], (n - 1) *sizeof(ListaContigua));

	nodos.erase(nodos.begin() + posicionNodoParaBorrar);

	n--;

}

void Grafo::eliminaArco(char nodoOrigen, char nodoDestino) {
	assert(existeArco(nodoOrigen, nodoDestino));

	int posicionOrigen = posicionNodo(nodoOrigen);
	int posicionDestino = posicionNodo(nodoDestino);

	matriz[posicionOrigen].setValor(posicionDestino, 0);

}

void Grafo::imprimir() {

	if (n == 0) {
		cout << "Matriz Vacia";
	}
	else {

		cout << "  ";

		for (int i = 0; i < n; i++) {
			cout << nodos.at(i) << " ";
		}

		cout << "\n";

		for (int i = 0; i < n; i++) {
			cout << nodos.at(i) << " ";
			for (int j = 0; j < n; j++) {
				cout << matriz[i].getValor(j) << " ";
			}
			cout << "\n";
		}


	}

	cout << "\n";

}
Grafo::~Grafo() {
	delete (matriz);

}