#include "Grafo.h"
#include <cassert>
#include <iostream>


Grafo::Grafo() {
	matriz = nullptr;
	nodos = "";

}




bool Grafo::existeNodo(char nodo) {

	int posicion = nodos.find(nodo, 0);

	
	return (posicion != string::npos);

}

int Grafo::getPosicionNodo(char nodo) {
	assert(existeNodo(nodo));


	int posicion = nodos.find(nodo, 0);

	return (posicion);

}

void Grafo::insertarNodo(char nodo) {

	nodos.append(1, nodo);

	matriz = (ListaContigua*)realloc(matriz, (n + 1) * sizeof(ListaContigua));

	for (int i = 0; i < n; i++) {
		matriz[i].insertarAlFinal(0);

	}



	ListaContigua *listaParaInsertar = new ListaContigua;
	for (int i = 0; i <= n; i++) {
		listaParaInsertar->insertarAlFinal(0);

	}
	
	matriz[n] = *listaParaInsertar;

	n++;

}

void Grafo::insertarArco(char nodoOrigen, char nodoDestino) {
	assert(existeNodo(nodoOrigen));
	assert(existeNodo(nodoDestino));


	int posicionOrigen = getPosicionNodo(nodoOrigen);
	int posicionDestino = getPosicionNodo(nodoDestino);


	matriz[posicionOrigen].setValor(posicionDestino, 1);

}
void Grafo::eliminarNodo(char nodo) {
	assert(n > 0);
	assert(existeNodo(nodo));

	int posicionNodo = getPosicionNodo(nodo);

	nodos.erase(nodos.begin() + posicionNodo);


	for (int i = 0; i < n; i++) {
		matriz[i].eliminar(posicionNodo);

	}

	memmove(&matriz[posicionNodo], &matriz[posicionNodo + 1], (n - posicionNodo - 1) * sizeof (ListaContigua));

	n--;

}
void Grafo::eliminarArco(char nodoOrigen, char nodoDestino) {
	assert(existeNodo(nodoOrigen));
	assert(existeNodo(nodoDestino));

	int posicionOrigen = getPosicionNodo(nodoOrigen);
	int posicionDestino = getPosicionNodo(nodoDestino);

	matriz[posicionOrigen].setValor(posicionDestino, 0);


}
void Grafo::imprimir() {

	if (n == 0) {
		cout << "Grafo vacio";


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

			cout << endl;

		}


	}


	cout << endl;

}


Grafo::~Grafo() {
	free(matriz);

}