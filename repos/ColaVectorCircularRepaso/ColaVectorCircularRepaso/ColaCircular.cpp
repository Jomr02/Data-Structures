#include "ColaCircular.h"
#include <malloc.h>
#include <cassert>
#include <iostream>


using namespace std;




ColaCircular::ColaCircular() {
	cola = nullptr;
	posPrimerElemento = 0;
	posUltimoElemento = -1;

	int capacidad = 0;
	int n = 0;

}
void ColaCircular::modificaCapacidad(int nuevaCapacidad) {

	//reservamos memoria para la nueva cola
	char* nuevaCola = (char*)malloc(nuevaCapacidad * sizeof(char));
	int posAux = posPrimerElemento;
	
	//copiamos los elementos de la anterior cola a la nueva
	for (int i = 0; i < n; i++) {
		nuevaCola[i] = cola[posAux];

		posAux = (posAux + 1) % capacidad;
	}

	free(cola);

	cola = nuevaCola;
	posPrimerElemento = 0;
	posUltimoElemento = n - 1;
	capacidad = nuevaCapacidad;

}
bool ColaCircular::esCasillaVacia(int posicion) {
	assert(posicion >= 0);
	assert(posicion < capacidad);


	if (posPrimerElemento <= posUltimoElemento) {

		if (posicion < posPrimerElemento || posicion > posUltimoElemento) {
			return true;

		}
		else {
			return false;
			
		}

	}
	else {
		if (posicion < posPrimerElemento && posicion > posUltimoElemento) {
			return true;

		}
		else {
			return false;

		}
	}

}
void ColaCircular::push(char elemento) {
	assert(elemento >= 'a' && elemento <= 'z');


	if (n == capacidad) {
		modificaCapacidad(capacidad + INCREMENTO);

	}

	posUltimoElemento = (posUltimoElemento + 1) % capacidad;

	cola[posUltimoElemento] = elemento;

	n++;
}
bool ColaCircular::esVacia() {
	return (n == 0);


}
int ColaCircular::pop() {

	char elemento = cola[posPrimerElemento];

	posPrimerElemento = (posPrimerElemento + 1) % capacidad;

	n--;

	if (capacidad - n == 2 * INCREMENTO) {
		modificaCapacidad(capacidad - INCREMENTO);

	}

	return elemento;

}
void ColaCircular::imprimir() {


	if (esVacia()) {
		cout << "Cola vacia";

	}
	else {
		cout << "|";
		for (int i = 0; i < capacidad; i++) {

			if (esCasillaVacia(i)) {
				cout << " ";
			}
			else {
				cout << cola[i];
			}

			cout << "|";
		}

	}

	cout << "\n";

}
ColaCircular::~ColaCircular() {
	free(cola);

}