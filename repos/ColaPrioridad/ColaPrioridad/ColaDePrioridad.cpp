#include "ColaDePrioridad.h"
#include <cassert>
#include "Cola.h"
#include <malloc.h>
#include <iostream>
using namespace std;


ColaDePrioridad::ColaDePrioridad(int nPrioridades) {


	n = 0;
	prioridades = nPrioridades;

	colaPrioridad = new Cola [nPrioridades];

	for (int i = 0; i < nPrioridades; i++) {
		Cola colaAux;
		colaPrioridad[i] = colaAux;
	}

}
void ColaDePrioridad::modificaPrioridades(int nPrioridades) {

	colaPrioridad = (Cola*)realloc(colaPrioridad, nPrioridades * sizeof(Cola));

}
void ColaDePrioridad::push(int prioridad, int elemento) {
	assert(prioridad >= 0 && prioridad < prioridades);

	colaPrioridad[prioridad].push(elemento);

	n++;


}
int ColaDePrioridad::pop() {
	assert(n > 0);

	bool sacado = false;
	int prioridad = 0;
	int elemento;

	while (!sacado) {

		if (colaPrioridad[prioridad].getN() > 0) {
			elemento = colaPrioridad[prioridad].pop();

			sacado = true;
		}

		prioridad++;

	}

	n--;

	return elemento;

}
void ColaDePrioridad::imprimir() {

	for (int i = 0; i < prioridades; i++) {
		cout << "Prioridad: " << i << "\n";
		colaPrioridad[i].imprimir();
		
	}

}
ColaDePrioridad::~ColaDePrioridad() {
	delete[] colaPrioridad;

}