#include "HashEstudiantes.h"


HashEstudiantes::HashEstudiantes(int nuevaCapacidad) {
	capacidad = nuevaCapacidad;
	n = 0;

	claves = (int *) malloc(capacidad * sizeof(int));
	estudiantes = new string[capacidad];
	ocupado = (bool*) malloc(capacidad * sizeof(bool));
	borrado = (bool*)malloc(capacidad * sizeof(bool));


	for (int i = 0; i < capacidad; i++) {
		ocupado[i] = false;
		borrado[i] = false;

	}

}

int HashEstudiantes::getPosicion(int clave) {
	return (clave % capacidad);

}

bool HashEstudiantes::existeEstudiante(int clave) {
	if (n == 0) {
		return false;
	}

	int posicion = getPosicion(clave);

	int contador = 0;

	while (contador < capacidad) {
		if (claves[posicion] == clave && ocupado[posicion]) {
			return true;
		}
		else if (!ocupado[posicion] && !borrado[posicion]) {
			return false;

		}

			contador++;
			posicion = (posicion + 1) % capacidad;
		}

		return false;

}
string HashEstudiantes::getEstudiante(int clave) {
	assert(existeEstudiante(clave));

		int posicion = getPosicion(clave);

		int contador = 0;

		while (contador < capacidad) {
			if (claves[posicion] == clave && ocupado[posicion]) {
				return estudiantes[posicion];
			}


			contador++;
			posicion = (posicion + 1) % capacidad;
		}

}
void HashEstudiantes::introducirEstudiante(int clave, string nombre) {
	assert(!existeEstudiante(clave));
	assert(!esLlena());

	int posicion = getPosicion(clave);

	bool encontradoHueco = false;

	while (!encontradoHueco) {

		if (!ocupado[posicion]) {
			estudiantes[posicion] = nombre;
			claves[posicion] = clave;
			ocupado[posicion] = true;

			encontradoHueco = true;
		}

		posicion = (posicion + 1) % capacidad;
	}


	n++;

}
void HashEstudiantes::eliminarEstudiante(int clave) {
	assert(!existeEstudiante(clave));

	int posicion = getPosicion(clave);

	bool estudianteBorrado = false;

	while (!estudianteBorrado) {
		if (ocupado[posicion] && claves[posicion] == clave) {
			ocupado[posicion] = false;

			estudianteBorrado = true;
		}


		posicion = (posicion + 1) % capacidad;
	}



	n--;

}
bool HashEstudiantes::esLlena() {
	return (n == capacidad);

}
void HashEstudiantes::imprimir() {
	
	for (int i = 0; i < capacidad; i++) {
		cout << "Posicion: ";
		cout << i;
		cout << " Ocupada: ";
		cout << ocupado[i];
		cout << " Borrada: ";
		cout << borrado[i];

		if (ocupado[i]) {
			cout << " Clave: ";
			cout << claves[i];
			cout << " Nombre: ";
			cout << estudiantes[i];

		}

		cout << "\n";

	}

}
HashEstudiantes::~HashEstudiantes() {
	free(claves);
	delete[] estudiantes;
	free(ocupado);
	free(borrado);

}