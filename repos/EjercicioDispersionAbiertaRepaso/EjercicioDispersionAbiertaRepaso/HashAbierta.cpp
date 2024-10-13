#include "HashAbierta.h"
#include <cassert>
#include <iostream>





HashAbierta::HashAbierta(int capacidadInicial) {

	capacidad = capacidadInicial;

	tabla = new ListaEnlazada [capacidad];


}

int HashAbierta::obtenerPosicion(int clave) {
	return (clave % capacidad);


}
bool HashAbierta::existeEstudiante(int clave) {

	int posicion = obtenerPosicion(clave);

	int encontrado = tabla[posicion].buscar(clave);

	if (encontrado == -1)
		return false;
	else
		return true;

}
Estudiante HashAbierta::getEstudiante(int clave) {
	assert(existeEstudiante(clave));

	int posicion = obtenerPosicion(clave);

	int pos = tabla[posicion].buscar(clave);

	return (tabla[posicion].getNodo(pos)->estudiante);

}
void HashAbierta::meterEstudiante(int clave, string nombre) {
	assert(!existeEstudiante(clave));

	int posicion = obtenerPosicion(clave);

	tabla[posicion].insertar(tabla[posicion].getN(), clave, nombre);


}
void HashAbierta::eliminarEstudiante(int clave) {
	assert(existeEstudiante(clave));

	int posicion = obtenerPosicion(clave);

	tabla[posicion].eliminar(clave);

}
bool HashAbierta::esLlena() {
	return false;

}
void HashAbierta::imprimir() {

	for (int i = 0; i < capacidad; i++) {
		cout << "Posicion " << i;
		cout << "\n";

		tabla[i].imprimir();

	}

	cout << "\n";
}

HashAbierta::~HashAbierta() {
	//delete[] tabla;

}
