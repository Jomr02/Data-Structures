#include "HashCoches.h"
#include <cassert>
#include <iostream>



HashCoches::HashCoches(int capacidadInicial, int versionesIniciales) {
	capacidad = capacidadInicial;
	versiones = versionesIniciales;

	tabla = new Coche[capacidad];

	for (int i = 0; i < capacidad; i++) {
		tabla[i].ocupado = false;

	}

}

int HashCoches::obtenerPosicion(string matricula, int version) {
	assert(version > 0);

	int longitudMatricula = matricula.length();

	int suma = 0;

	for (int i = 0; i < longitudMatricula; i++) {
		suma = suma + ((int) matricula.at(i));

	}

	int posicion = suma + version * (capacidad / versiones);

	posicion = posicion % capacidad;


	return posicion;

}
void HashCoches::modificaCapacidad(int nuevaCapacidad, int nuevasVersiones) {
	assert(nuevaCapacidad > 0);
	assert(nuevasVersiones > 0);



	HashCoches *tablaNueva = new HashCoches (nuevaCapacidad, nuevasVersiones);


	for (int i = 0; i < capacidad; i++) {
		if (tabla[i].ocupado) {
			tablaNueva->insertar(tabla[i]);
		}

	}

	delete[] tabla;

	tabla = tablaNueva->tabla;

	capacidad = nuevaCapacidad;
	versiones = nuevasVersiones;



}
int HashCoches::existeCoche(string matricula) {

	int existePosicion = -1;

	for (int i = 1; i <= versiones; i++) {
		int posicion = obtenerPosicion(matricula, i);
		if (tabla[posicion].ocupado && tabla[posicion].matricula.compare(matricula) == 0) {
			existePosicion = i;

		}

	}

	return existePosicion;



}
void HashCoches::insertar(Coche coche) {
	assert(existeCoche(coche.matricula) == -1);


	bool insertado = false;


	for (int i = 1; i <= versiones; i++) {
		int posicion = obtenerPosicion(coche.matricula, i);
		if (!tabla[posicion].ocupado) {
			tabla[posicion] = coche;
			tabla[posicion].ocupado = true;

			insertado = true;
			break;
		}

	}

	if (!insertado) {
		modificaCapacidad(2 * capacidad, versiones + 1);
		insertar(coche);
	}


	

}
Coche HashCoches::getElemento(string matricula) {
	assert(existeCoche(matricula));

	int posicion = existeCoche(matricula);

	return tabla[posicion];

}
void HashCoches::imprimir() {

	for (int i = 0; i < capacidad; i++) {
		cout << "Posicion: " << i << " | ";
		cout << "Ocupada: " << tabla[i].ocupado << " | ";
		cout << "Clave: " << tabla[i].matricula << " | ";
		cout << "Contenido: " << tabla[i].modelo << "\n";


	}

	cout << "\n";

}

HashCoches::~HashCoches() {
	delete[] tabla;

}
