// HashEstudiantesAbierta.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#pragma once
#include "string"
#include "ListaEnlazada.h"
#include "ListaEnlazada.h"
#include "cassert"
#include "iostream"
#include "impresionListasEnlazadas.h" 

using namespace std;






class HashEstudiantesAbierta
{

private:

	int capacidad; // Capacidad de la tabla. Permanece invariante a lo largo de la vida del objeto
	int n; // Numero actual de elementos de la tabla. Puede ser mayor que capacidad

	ListaEnlazada* tabla; // La tabla hash será un vector de listas enlazadas

	// Método de hashing (tenemos dos versiones). 
	// Parámetros: 
	// - clave: la clave del estudiante (es su número de matrícula)
	// - version: 0 ó 1 según el método de hashing que queramos ejecutar. 
	//   Si es 0, devuelve el resto de dividir la clave entre capacidad. Si es 1, devuelve su simétrico en la tabla.
	// Retorno: la posición donde el estudiante debería estar o ponerse en la tabla hash
	// Precondición: version es 0 ó 1
	// Complejidad temporal en todos los casos: O(1)
	int obtenerPosicion(int clave, int version);

public:

	// Constructor
	// Parámetro: la capacidad (capacidad) de la lista
	// Precondición: capacidad > 0
	// Complejidad temporal: O(capacidad) en todos los casos (porque "new" llama al constructor de todos las listas)
	HashEstudiantesAbierta(int capacidad);

	// Comprueba si un estudiante está o no en la tabla hash
	// Parámetro: la clave del estudiante
	// Retorno: true si está, false si no
	// Complejidad temporal: O(1) en mejor caso, O(n) en peor caso
	bool existeEstudiante(int clave);

	// Obtiene un estudiante (su nombre) a partir de su clave
	// Parámetro: la clave del estudiante
	// Retorno: el nombre del estudiante
	// Precondición: el estudiante debe estar en la tabla hash
	// Complejidad temporal: O(1) en mejor caso, O(n) en peor caso
	string getEstudiante(int clave);

	// Inserta un estudiante en la tabla
	// Parámetros:
	// - clave: el número de matrícula del estudiante
	// - estudiante: el nombre del estudiante
	// Precondición: el estudiante no existe en la tabla hash
	// Complejidad temporal: O(1) en todos los casos
	void introducirEstudiante(int clave, string estudiante);

	// Elimina un estudiante de la tabla
	// Parámetro: la clave del estudiante a eliminar
	// Precondición: el estudiante debe estar en la tabla hash
	// Complejidad temporal: O(1) en mejor caso, O(n) en peor caso
	void eliminarEstudiante(int clave);

	// Imprime toda la tabla hash
	// Complejidad temporal:
	// - O(capacidad) en el mejor caso (tabla vacia)
	// - O(n+capacidad) en el peor (los n elementos en una única posición de la tabla)
	void imprimir();

	// Destructor
	// Complejidad: al destruir la tabla, también se llama a los destructores de cada lista, 
	// así pues la complejidad es igual que en imprimir
	~HashEstudiantesAbierta();

};


HashEstudiantesAbierta::HashEstudiantesAbierta(int capacidad) {
	assert(capacidad >= 0);

	tabla = new ListaEnlazada[capacidad];

	this->capacidad = capacidad;
	n = 0;

}

int HashEstudiantesAbierta::obtenerPosicion(int clave, int version) {
	assert(version == 0 || version == 1);

	int posicion;

	if (version == 0)
		posicion = clave % capacidad;
	else
		posicion = (clave + capacidad / 2) % capacidad;

	return posicion;

}

void HashEstudiantesAbierta::introducirEstudiante(int clave, string estudiante) {

	int posicion;
	int tamanoLista1, tamanoLista2;

	posicion = obtenerPosicion(clave, 0);
	tamanoLista1 = tabla[posicion].getN();

	posicion = obtenerPosicion(clave, 1);
	tamanoLista2 = tabla[posicion].getN();

	Estudiante datosEstudiante;
	datosEstudiante.clave = clave;
	datosEstudiante.nombre = estudiante;
	

	if (tamanoLista1 <= tamanoLista2) {
		posicion = obtenerPosicion(clave, 0);
		tabla[posicion].insertar(0, datosEstudiante);
	}
	else {
		tabla[posicion].insertar(0, datosEstudiante);
	}

	n++;

}

bool HashEstudiantesAbierta::existeEstudiante(int clave) {
	
	bool encontrado = false;

	int posicion1 = obtenerPosicion(clave, 0);
	int posicion2 = obtenerPosicion(clave, 1);

	Estudiante estudiante;
	estudiante.clave = clave;

	if (tabla[posicion1].buscar(estudiante) != -1 || tabla[posicion2].buscar(estudiante) != -1)
		encontrado = true;

	return encontrado;


}

string HashEstudiantesAbierta::getEstudiante(int clave) {
	assert(existeEstudiante(clave));

	int posicion1 = obtenerPosicion(clave, 0);
	int posicion2 = obtenerPosicion(clave, 1);
	int posicionEnLista;

	Estudiante estudiante;
	estudiante.clave = clave;

	string nombre;

	if (tabla[posicion1].buscar(estudiante) != -1) {
		posicionEnLista = tabla[posicion1].buscar(estudiante);
		nombre = tabla[posicion1].getValor(posicionEnLista).nombre;
	}

	if (tabla[posicion2].buscar(estudiante) != -1) {
		posicionEnLista = tabla[posicion2].buscar(estudiante);
		nombre = tabla[posicion2].getValor(posicionEnLista).nombre;
	}


	return nombre;
}

void HashEstudiantesAbierta::eliminarEstudiante(int clave) {
	assert(existeEstudiante(clave));

	int posicion1 = obtenerPosicion(clave, 0);
	int posicion2 = obtenerPosicion(clave, 1);
	int posicionEnLista;

	Estudiante estudiante;
	estudiante.clave = clave;

	if (tabla[posicion1].buscar(estudiante) != -1) {
		posicionEnLista = tabla[posicion1].buscar(estudiante);
		tabla[posicion1].eliminar(posicionEnLista);
	}

	if (tabla[posicion2].buscar(estudiante) != -1) {
		posicionEnLista = tabla[posicion2].buscar(estudiante);
		tabla[posicion2].eliminar(posicionEnLista);
	}

	n--;
}

void HashEstudiantesAbierta::imprimir() {

	if (n == 0) {
		cout << "Tabla vacia" << endl;
	} else {
		for (int i = 0; i < capacidad; i++) {
			cout << "Posicion: " << i << " n= " << tabla[i].getN() << " Lista enlazada:"<< endl;
			imprimirListaEnlazada(&tabla[i]);
		}
	}


}

HashEstudiantesAbierta::~HashEstudiantesAbierta() {
	delete[](tabla);
}

void main() {

	int capacidad; // Capacidad de la tabla hash
	int opcion; // Opcion de menu introducida por teclado

	cout << "Introduce la capacidad de la tabla: ";
	cin >> capacidad;

	HashEstudiantesAbierta tabla(capacidad);


	do {
		// Imprimimos el menu y pedimos la opcion
		cout << "0. Salir\n";
		cout << "1. Imprimir tabla\n";
		cout << "2. Comprobar si esta un estudiante\n";
		cout << "3. Ver un estudiante\n";
		cout << "4. Meter un estudiante\n";
		cout << "5. Eliminar un estudiante\n";
		cout << "Introduzca opcion: ";
		cin >> opcion;

		int clave; // Clave para algunas opciones
		string nombre; // Nombre del estudiante para la opcion de meter

		// Gestionamos la opcion
		switch (opcion) {
		case 0:
			break;
		case 1:
			tabla.imprimir();
			break;
		case 2:
			// Comprobar si está un estudiante
			cout << "Introduzca el numero de matricula del estudiante: ";
			cin >> clave;
			if (tabla.existeEstudiante(clave)) cout << "El estudiante SI esta\n";
			else cout << "El estudiante NO esta\n";
			break;
		case 3:
			// Ver un estudiante (obtener su nombre)
			cout << "Introduzca el numero de matricula del estudiante: ";
			cin >> clave;
			cout << "El estudiante se llama " << tabla.getEstudiante(clave) << endl;
			break;
		case 4:
			// Meter un estudiante
			cout << "Introduzca el numero de matricula del estudiante: ";
			cin >> clave;
			cout << "Introduzca el nombre del estudiante: ";
			cin >> nombre;
			tabla.introducirEstudiante(clave, nombre);
			break;
		case 5:
			// Eliminar un estudiante
			cout << "Introduzca el numero de matricula del estudiante: ";
			cin >> clave;
			tabla.eliminarEstudiante(clave);
			break;
		default:
			cout << "Opcion incorrecta\n";
			break;

		} // Fin switch

	} while (opcion != 0);

}
