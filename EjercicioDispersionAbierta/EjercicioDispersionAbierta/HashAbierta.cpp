#include "HashAbierta.h"
#include <cassert>
#include <iostream>

using namespace std;


HashAbierta::HashAbierta(int capacidadInicial) {
	capacidad = capacidadInicial;
	hash = new ListaContigua[capacidad];
	

}
int HashAbierta::obtenerPosicion(int clave) {

	int posicion = clave % capacidad;
	int posicionSimetrica = (posicion + capacidad / 2) % capacidad;


	if (hash[posicion].getN() <= hash[posicionSimetrica].getN())
		return posicion;
	else
		return posicionSimetrica;

}
bool HashAbierta::existeEstudiante(int clave, string nombre) {

	int posicion = clave % capacidad;
	int posicionSimetrica = (posicion + capacidad / 2) % capacidad;

	return (hash[posicion].existeEstudiante(clave, nombre) || hash[posicionSimetrica].existeEstudiante(clave, nombre));


}
void HashAbierta::introducirEstudiante(int clave, string nombre) {
	assert(!existeEstudiante(clave, nombre));

	int posicion = obtenerPosicion(clave);

	hash[posicion].introducirEstudiante(clave, nombre);

}
void HashAbierta::eliminarEstudiante(int clave, string nombre) {
	assert(existeEstudiante(clave, nombre));

	int posicion = clave % capacidad;
	int posicionSimetrica = (posicion + capacidad / 2) % capacidad;

	if (hash[posicion].existeEstudiante(clave, nombre)) {
		hash[posicion].eliminarEstudiante(clave, nombre);

	}
	else {
		hash[posicionSimetrica].eliminarEstudiante(clave, nombre);

	}

}
void HashAbierta::imprimir() {
	for (int i = 0; i < capacidad; i++) {
		cout << "Posicion " << i << "\n";
		hash[i].imprimir();

	}

	cout << "\n";

}
HashAbierta::~HashAbierta() {
	delete[] hash;

}