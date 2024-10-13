#include "Cola.h"
#include <malloc.h>
#include <cassert>
#include <vcruntime_string.h>
#include <iostream>
using namespace std;


Cola::Cola() {

	int capacidad = 0;
	int n = 0;

	cola = NULL;

}
void Cola::modificaCapacidad(int nuevaCapacidad) {

	cola = (int*) realloc(cola, (capacidad + nuevaCapacidad) * sizeof(int));

	capacidad = capacidad + nuevaCapacidad;



}
void Cola::push(int elemento) {


	if (capacidad == n) {
		modificaCapacidad(INCREMENTO);
	}

	cola[n] = elemento;

	n++;

}
int Cola::pop() {
	assert(n > 0);

	int elemento = cola[0];

	memmove(cola, cola + 1, (n - 1) * sizeof(int));


	n--;

	if ((capacidad - n) == (2 * INCREMENTO)) {
		modificaCapacidad(-INCREMENTO);

	}

	return elemento;
}
int Cola::getElemento(int posicion) {
	return cola[posicion];

}
void Cola::imprimir() {

	if (n == 0) {
		cout << "Cola Vacia";
	}
	else {
		for (int i = 0; i < n; i++) {
			cout << getElemento(i);

			if (i < n - 1) {
				cout << ", ";
			}

		}


	}

	cout << "\n";

}

int Cola::getN() {
	return n;

}

Cola::~Cola() {
	free(cola);

}
