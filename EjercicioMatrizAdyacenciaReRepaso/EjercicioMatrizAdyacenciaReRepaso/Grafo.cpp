#include "Grafo.h"
#include "cassert"
#include <iostream>


Grafo::Grafo() {
	n = 0;

}
bool Grafo::existeNodo(char letraNodo) {
	return (string::npos != nodos.find(letraNodo, 0));

}
bool Grafo::existeArco(char nodoOrigen, char nodoDestino) {
	assert(existeNodo(nodoOrigen));
	assert(existeNodo(nodoDestino));

	int posicionOrigen = getPosicionNodo(nodoOrigen);
	int posicionDestino = getPosicionNodo(nodoDestino);


	return (matriz[posicionOrigen].getValor(posicionDestino) != 0);

}
int Grafo::getPosicionNodo(char letraNodo) {
	assert(existeNodo (letraNodo));

	return (nodos.find(letraNodo, 0));

}

void Grafo::insertarNodo(char letraNodo) {
	assert(!existeNodo(letraNodo));

	nodos.append(1, letraNodo);

	matriz = (ListaContigua*)realloc(matriz, (n + 1) * sizeof(ListaContigua));

	ListaContigua* nuevaFila = new ListaContigua;
	
	for (int i = 0; i <= n; i++) {
		nuevaFila->insertarAlFinal(0);
	}

	for (int i = 0; i < n; i++) {
		matriz[i].insertarAlFinal(0);
	}

	matriz[n] = *nuevaFila;

	n++;

}
void Grafo::eliminarNodo(char letraNodo) {
	assert(existeNodo(letraNodo));

	int posicionNodo = getPosicionNodo(letraNodo);


	for (int i = 0; i < n; i++) {
		matriz[i].eliminar(posicionNodo);
	}

	memmove(&matriz[posicionNodo], &matriz[posicionNodo + 1], (n - posicionNodo - 1) * sizeof (ListaContigua));

	nodos.erase(nodos.begin() + posicionNodo);

	n--;

}
void Grafo::insertarArco(char nodoOrigen, char nodoDestino) {
	assert(existeNodo(nodoOrigen));
	assert(existeNodo(nodoDestino));
	assert(!existeArco (nodoOrigen, nodoDestino));

	
	int posicionOrigen = getPosicionNodo(nodoOrigen);
	int posicionDestino = getPosicionNodo(nodoDestino);

	matriz[posicionOrigen].setValor(posicionDestino, 1);


}
void Grafo::eliminarArco(char nodoOrigen, char nodoDestino) {
	assert(existeNodo(nodoOrigen));
	assert(existeNodo(nodoDestino));
	assert(existeArco(nodoOrigen, nodoDestino));


	int posicionOrigen = getPosicionNodo(nodoOrigen);
	int posicionDestino = getPosicionNodo(nodoDestino);

	matriz[posicionOrigen].setValor(posicionDestino, 0);

}
void Grafo::imprimir() {

	if (n == 0) {
		cout << "Grafo Vacio";

	}
	else {

		cout << "  ";

		for (int i = 0; i < n; i++) {
			cout << nodos.at(i) << " ";

		}

		cout << endl;

		for (int i = 0; i < n; i++) {
			cout << nodos.at(i) << " ";

			for (int j = 0; j < n; j++) {
				cout << matriz[i].getValor(j) << " ";

			}

			cout << endl;

		}


	}


	cout << endl;

}
Grafo::~Grafo() {
	free(matriz);


}