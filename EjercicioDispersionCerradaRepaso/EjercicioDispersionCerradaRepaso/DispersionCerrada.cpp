#include "DispersionCerrada.h"
#include <iostream>






DispersionCerrada::DispersionCerrada(int capacidadInicial) {

	tabla = new Elemento[capacidadInicial];

	capacidad = capacidadInicial;
	n = 0;

	for (int i = 0; i < capacidad; i++) {
		tabla[i].borrado = false;
		tabla[i].ocupado = false;

	}

}
int DispersionCerrada::obtenerPosicion(int clave) {
	return (clave % capacidad);

}
bool DispersionCerrada::existeEstudiante(int clave) {

	int posicion = obtenerPosicion(clave);

	int contador = 0;

	bool existeEstudiante = false;

	while ((contador < capacidad) && (tabla[posicion].ocupado || tabla[posicion].borrado)) {

		if (tabla[posicion].ocupado && tabla[posicion].clave == clave) {
			existeEstudiante = true;

		}

		contador++;
		posicion = (posicion + 1) % capacidad;

	}

	return existeEstudiante;

}

string DispersionCerrada::getEstudiante(int clave) {
	assert(existeEstudiante(clave));

	int posicion = obtenerPosicion(clave);

	return (tabla[posicion].valor);

}
void DispersionCerrada::meterEstudiante(int clave, string nombre) {
	assert(!existeEstudiante(clave));
	assert(!esLlena());

	int posicion = obtenerPosicion(clave);

	bool introducido = false;

	while (!introducido) {

		if (!tabla[posicion].ocupado) {
			tabla[posicion].clave = clave;
			tabla[posicion].valor = nombre;
			tabla[posicion].ocupado = true;

			introducido = true;


		}

		posicion = (posicion + 1) % capacidad;
	}



	n++;
}
void DispersionCerrada::eliminarEstudiante(int clave) {
	assert(existeEstudiante(clave));

	int posicion = obtenerPosicion(clave);

	bool encontrado = false;

	while (!encontrado) {
		if (tabla[posicion].clave == clave) {
			tabla[posicion].ocupado = false;
			tabla[posicion].borrado = true;

			encontrado = true;
		}


		posicion = (posicion + 1) % capacidad;
		
	}


	n--;
}
bool DispersionCerrada::esLlena() {
	return (n == capacidad);

}
void DispersionCerrada::imprimir() {

	for (int i = 0; i < capacidad; i++) {
		cout << "Posicion " << i;
		
		if (tabla[i].ocupado) {
			cout << " Matricula: " << tabla[i].clave;
			cout << " Nombre: " << tabla[i].valor;
			cout << " Ocupado " << tabla[i].ocupado;
			cout << " Borrado " << tabla[i].borrado;



		}
		else {
			cout << " Casilla Vacia";

		}

		cout << "\n";

	}

	cout << "\n";

}
DispersionCerrada::~DispersionCerrada() {
	delete [] tabla;

}