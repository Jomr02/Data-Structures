#include "Pila.h"
#include "cassert"
#include <iostream>

using namespace std;

Pila::Pila() {
	punteroPrimerNodo = nullptr;
	punteroUltimoNodo = nullptr;
	n = 0;

}
void Pila::push(int elemento) {

	Nodo* nodoInsertar = new Nodo;
	nodoInsertar->anteriorNodo = nullptr;
	nodoInsertar->siguienteNodo = nullptr;
	nodoInsertar->elemento = elemento;


	if (n == 0) {
		punteroPrimerNodo = nodoInsertar;
		punteroUltimoNodo = nodoInsertar;


	}
	else {
		punteroUltimoNodo->siguienteNodo = nodoInsertar;
		nodoInsertar->anteriorNodo = punteroUltimoNodo;
		punteroUltimoNodo = nodoInsertar;

	}


	n++;
}
int Pila::pop() {
	assert(!isVacia());

	

	Nodo* nodoEliminar = punteroUltimoNodo;

	int elemento = nodoEliminar->elemento;

	if (n == 1) {
		punteroPrimerNodo = nullptr;
		punteroUltimoNodo = nullptr;

	}
	else {
		punteroUltimoNodo = punteroUltimoNodo->anteriorNodo;

	}

	delete (nodoEliminar);

	n--;


	return elemento;
}
int Pila::verCima() {
	assert(!isVacia());

	return (punteroUltimoNodo->elemento);

}
bool Pila::isVacia() {
	return (n == 0);

}

void Pila::imprimePila (){
	
	if (isVacia()) {
		cout << "Lista Vacia";

	}
	else {

		Nodo* nodoImprimir = punteroPrimerNodo;

		for (int i = 0; i < n; i++) {
			cout << nodoImprimir->elemento;
			
			if (i < n - 1) {
				cout << ", ";
			}

			nodoImprimir = nodoImprimir->siguienteNodo;
		}
	}

	cout << "\n";

}
Pila::~Pila() {
	while (n > 0)
		pop();

}