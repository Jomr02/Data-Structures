#include "TablaHash.h"
#include <iostream>



TablaHash::TablaHash(int capacidadInicial) {
	assert(capacidadInicial > 0);

	capacidad = capacidadInicial;

	tabla = new Elemento[capacidad];

	for (int i = 0; i < capacidad; i++) {
		tabla[i].ocupado = false;

	}

}


int TablaHash::obtenerPosicion(int clave) {
	return (clave % capacidad);

}

bool TablaHash::existeEstudiante(int clave) {

	int posicion = obtenerPosicion(clave);

	if (tabla[posicion].clave == clave && tabla[posicion].ocupado) {
		return true;
	}
	else {
		return false;
	}

}
string TablaHash::getEstudiante(int clave) {
	assert(existeEstudiante(clave));

	int posicion = obtenerPosicion(clave);

	return (tabla[posicion].valor);
}
void TablaHash::meterEstudiante(int clave, string nombre) {
	assert(!existeEstudiante(clave));

	int posicion = obtenerPosicion(clave);

	tabla[posicion].clave = clave;
	tabla[posicion].valor = nombre;
	tabla[posicion].ocupado = true;

}
void TablaHash::eliminarEstudiante(int clave) {
	assert(existeEstudiante(clave));

	int posicion = obtenerPosicion(clave);

	tabla[posicion].ocupado = false;
}
void TablaHash::imprimir() {

	for (int i = 0; i < capacidad; i++) {
		cout << "Posicion " << i;
		if (tabla[i].ocupado) {
			cout << " Matricula " << tabla[i].clave;
			cout << " Nombre " << tabla[i].valor;
		}
		else {
			cout << " Vacia";

		}
		
		cout << "\n";

	}


}

TablaHash::~TablaHash() {
	delete[] tabla;

}