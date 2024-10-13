#include "TablaHashEstudiantes.h"
#include <cassert>
#include <iostream>

using namespace std;



TablaHashEstudiantes::TablaHashEstudiantes(int capacidadInicial) {
	capacidad = capacidadInicial;

	lista = new Estudiante[capacidad];

	for (int i = 0; i < capacidad; i++) {
		lista[i].ocupado = false;
	}

}


int TablaHashEstudiantes::obtenerPosicion(int clave) {
	return (clave % capacidad);

}
bool TablaHashEstudiantes::existeEstudiante(int clave) {
	int posicion = obtenerPosicion(clave);

	return (lista[posicion].ocupado && lista[posicion].matricula == clave);

}

string TablaHashEstudiantes::getNombre(int clave) {
	assert(existeEstudiante(clave));

	int posicion = obtenerPosicion(clave);

	return (lista[posicion].nombre);

}
void TablaHashEstudiantes::introducirEstudiante(int matricula, string nombre) {
	assert(!existeEstudiante(matricula));


	int posicion = obtenerPosicion(matricula);


	lista[posicion].matricula = matricula;
	lista[posicion].nombre = nombre;
	lista[posicion].ocupado = true;

}
void TablaHashEstudiantes::eliminaEstudiante(int matricula) {
	assert(existeEstudiante(matricula));

	int posicion = obtenerPosicion(matricula);

	lista[posicion].ocupado = false;

}
void TablaHashEstudiantes::imprimeLista() {

	for (int i = 0; i < capacidad; i++) {
		if (lista[i].ocupado) {
			cout << " Matricula: " << lista[i].matricula;
			cout << " Nombre: " << lista[i].nombre << "\n";

		}
	}

	cout << "\n";

}


TablaHashEstudiantes::~TablaHashEstudiantes() {
	delete [] lista; 

	
}