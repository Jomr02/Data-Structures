// HashEstudiantes.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <cassert>

using namespace std;

class HashEstudiantes
{

protected:

	int capacidad; // Capacidad de la tabla. Permanece invariante a lo largo de la vida del objeto
	int n; // Numero actual de elementos de la tabla. Precondición: n pertenece a [0,capacidad]

	// Vectores que guardarán la información de la tabla hash
	string* nombres; // Vector con los nombres de los estudiantes
	bool* vacias;   // Vector con los flags que indican si una posición está vacía (true) o no (false). Si esta vacia, tiene basura.
	int* claves; // Vector con las claves de los estudiantes
	bool* borradas; // Vector con los flags que indican si una posicion vacia ha sido borrada (true) o aun no (false). Si una casilla está borrada, entonces está vacia

	// Método de hashing
	// Parámetro: la clave del estudiante (es su número de matrícula)
	// Retorno: la posición donde el estudiante debería estar o ponerse en la tabla hash
	// Complejidad temporal en todos los casos: O(1)
	int obtenerPosicion(int clave);

	// Método que obtiene la posicion real de un estudiante en la tabla
	// Parámetro: la clave del estudiante
	// Retorno: posicion real en la tabla en donde el estudiante está, o -1 si no se encuentra
	// Complejidad temporal: O(1) mejor caso, y O(capacidad) peor caso
	int buscarEstudiante(int clave);

	// Busca el hueco adecuado para meter un estudiante. Empieza por la posición ideal y sigue buscando secuencialmente
	// (exploración lineal) mientras haya colisión
	// Parámetro: la clave del estudiante que se quiere meter
	// Retorno: posición real en la tabla en donde el estudiante se puede meter
	// Precondición: la tabla no está llena
	// Complejidad temporal: O(1) mejor caso, y O(capacidad) peor caso
	int buscarHueco(int clave);

public:

	// Constructor
	// Parámetro: la capacidad (capacidad) de la lista
	// Complejidad temporal: O(capacidad) en todos los casos (porque hay que inicializar los flags)
	HashEstudiantes(int capacidad);

	// Comprueba si un estudiante está o no en la tabla hash
	// Parámetro: la clave del estudiante
	// Retorno: true si está, false si no
	// Complejidad temporal: O(1) mejor caso, y O(capacidad) peor caso
	bool existeEstudiante(int clave);

	// Obtiene un estudiante (su nombre) a partir de su clave
	// Parámetro: la clave del estudiante
	// Retorno: el nombre del estudiante
	// Precondición: el estudiante debe estar en la tabla hash
	// Complejidad temporal: O(1) mejor caso, y O(capacidad) peor caso
	string getEstudiante(int clave);

	// Inserta un estudiante en la tabla
	// Parámetros:
	// - clave: el número de matrícula del estudiante
	// - estudiante: el nombre del estudiante
	// Precondición: la tabla no está llena y el estudiante no existe en la tabla
	// Complejidad temporal: O(1) mejor caso, y O(capacidad) peor caso
	void introducirEstudiante(int clave, string estudiante);

	// Elimina un estudiante de la tabla
	// Parámetro: la clave del estudiante a eliminar
	// Precondición: el estudiante debe estar en la tabla hash
	// Complejidad temporal: O(1) mejor caso, y O(capacidad) peor caso
	void eliminarEstudiante(int clave);

	// Imprime toda la tabla hash. Ojo: viola el principio de separación entre
	// interfaz y modelo
	// Complejidad temporal: O(capacidad) en todos los casos
	void imprimir();

	// Nos dice si la tabla está llena o no
	// Retorno: true si está llena, false si no lo está
	// Complejidad temporal: O(1) en todos los casos
	bool isLlena();

	// Destructor
	// Complejidad temporal: O(capacidad) en todos los casos
	~HashEstudiantes();

};


HashEstudiantes::HashEstudiantes(int capacidad) {
	nombres = new string[capacidad];
	vacias = (bool*)malloc(sizeof(bool) * capacidad);
	borradas = (bool*)malloc(sizeof(bool) * capacidad);
	claves = (int*)malloc(sizeof(int) * capacidad);

	for (int i = 0; i < capacidad; i++) {
		vacias[i] = true;
		borradas[i] = false;
	}

	n = 0;
	this->capacidad = capacidad;

}

int HashEstudiantes::obtenerPosicion(int clave) {
	return clave % capacidad;

}

int HashEstudiantes::buscarEstudiante(int clave) {
	int posicion = obtenerPosicion(clave);

	bool encontrado = false;
	int contador = 0;

	if (claves[posicion] == clave) {
		encontrado = true;
	}
	else {
		while (encontrado == false && !(vacias[posicion] == true && borradas[posicion] == true) && contador < capacidad) {
			posicion = (posicion + 1) % capacidad;

			if (claves[posicion] == clave) {
				encontrado = true;
			}
			contador++;
		}
		
		}

	if (encontrado)
		return posicion;
	else
		return -1;

	}

bool HashEstudiantes::isLlena() {
	return (n == capacidad);

}

int HashEstudiantes::buscarHueco(int clave) {
	assert(!isLlena());

	int posicion = obtenerPosicion(clave);

		while (!vacias[posicion]) {
			posicion = (posicion + 1) % capacidad;
		}


	return posicion;

}

bool HashEstudiantes::existeEstudiante(int clave) {
	int posicion = buscarEstudiante(clave);

	return (posicion >= 0);
}

string HashEstudiantes::getEstudiante(int clave) {
	assert(existeEstudiante(clave));

	int posicion = buscarEstudiante(clave);

	return (nombres[posicion]);

}

void HashEstudiantes::introducirEstudiante(int clave, string estudiante) {
	assert(!isLlena());
	assert(!existeEstudiante(clave));

	int posicion = buscarHueco(clave);
	claves[posicion] = clave;
	nombres[posicion] = estudiante;
	vacias[posicion] = false;

	n++;
}

void HashEstudiantes::eliminarEstudiante(int clave) {
	assert(existeEstudiante(clave));

	int posicion = buscarEstudiante(clave);
	vacias[posicion] = true;
	borradas[posicion] = true;

	n--;

}

void HashEstudiantes::imprimir() {
	if (n == 0) {
		cout << "Tabla vacia" << endl;
	}
	else {
		for (int i = 0; i < capacidad; i++) {
			if (vacias[i])
				cout << "Posicion " << i << " Vacia: " << vacias[i] << " Borrada: " << borradas[i] << " Clave: N/A " << " Nombre: N/A" << endl;
			else
				cout << "Posicion " << i << " Vacia: " << vacias[i] << " Borrada: " << borradas[i] << " Clave " << claves[i] << " Nombre: " << nombres[i] << endl;
		}

	}
	cout << endl;
}



HashEstudiantes::~HashEstudiantes(){
	delete[] (nombres);
	free(vacias);
	free(borradas);
	free(claves);
}
	




int main()
{
	HashEstudiantes hash(10);

	hash.imprimir();

	hash.introducirEstudiante(123, "Jose");
	hash.introducirEstudiante(40, "Nelida");
	hash.imprimir();
	hash.eliminarEstudiante(123);
	hash.introducirEstudiante(80, "Pepito");
	hash.imprimir();
	cout << hash.getEstudiante(40) << endl;

    
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
