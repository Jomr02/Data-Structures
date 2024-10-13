#include "ListaContigua.h"
#include <cassert>
#include <iostream>

using namespace std;


ListaContigua::ListaContigua() {
	capacidad = 50;
	n = 0;
	lista = new Estudiante[capacidad];


}
void ListaContigua::introducirEstudiante(int clave, string nombre) {
	assert(n < capacidad);
	assert(!existeEstudiante(clave, nombre));

	Estudiante estudiante;
	estudiante.matricula = clave;
	estudiante.nombre = nombre;


	lista[n] = estudiante;

	n++;
}
void ListaContigua::eliminarEstudiante(int clave, string nombre) {
	assert(n > 0);
	assert(existeEstudiante(clave, nombre));

	int posicion = getPosicionEstudiante(clave, nombre);


	memmove(lista + posicion, lista + posicion + 1, (n - posicion - 1) * sizeof(Estudiante));


	n--;

}
bool ListaContigua::existeEstudiante(int clave, string nombre) {

	bool encontrado = false;

	for (int i = 0; i < n; i++) {
		if (lista[i].matricula == clave && lista[i].nombre.compare( nombre) == 0)
			encontrado = true;

	}

	return encontrado;

}

int ListaContigua::getPosicionEstudiante(int clave, string nombre) {
	assert(existeEstudiante(clave, nombre));

	int posicion;

	for (int i = 0; i < n; i++) {
		if (lista[i].matricula == clave && lista[i].nombre.compare(nombre) == 0)
			posicion = i;

	}

	return posicion;
}

Estudiante* ListaContigua::getEstudiantePorPosicion(int posicion) {
	return (&lista[posicion]);

}
void ListaContigua::imprimir() {


	if (n == 0) {

		cout << "Lista Vacia";
	}
	else {
		for (int i = 0; i < n; i++) {
			cout << lista[i].matricula << "  " << lista[i].nombre;
			cout << "\n";
		}
	}

	cout << "\n";

}

int ListaContigua::getN() {
	return (n);

}
ListaContigua::~ListaContigua(){ 
	delete[] lista;
}