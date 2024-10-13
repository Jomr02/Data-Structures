#include <iostream>
#include "cassert"

using namespace std;

// Arbol general, implementado de hijo a padre, mediante dos arrays (uno con el valor de los elementos
// y otro con la posicion interna del padre de cada elemento) y con una capacidad estática. La raiz
// tendrá la posicion interna 0
class ArbolHijo2Padre {

	int* padres; // Array en el cual cada posicion i contiene la posicion del padre del elemento i
	int* elementos; // Array en el cual cada posicion i guarda el valor del elemento i
	int n; // Tamaño actual del arbol
	int capacidad; // Capacidad maxima del arbol

	// Obtiene el numero de hijos directos de un elemento cuya posicion se proporciona
	// Parametro: posicion interna del elemento cuyo numero de hijos se quiere conocer
	// Retorno: numero de hijos directos de ese elemento
	// Complejidad temporal: 
	int getNumeroHijosDirectos(int posicionPadre);

	// Obtiene el array de las posiciones de los hijos directos de un elemento
	// Parámetro: posicion interna del elemento cuyas posiciones de sus hijos queremos obtener
	// Retorno: direccion de comienzo de un array con las posiciones de todos los hijos
	// Complejidad temporal: 
	int* getPosicionHijosDirectos(int posicionPadre);

	// Averigua la posicion interna de un elemento
	// Parámetro: valor del elemento que queremos buscar
	// Retorno: posicion interna del elemento, o -1 si no está en el árbol
	// Complejidad temporal: 
	int buscarPosicion(int elemento);

	// Averigua la profundidad de un elemento cuya posicion interna se proporciona
	// Parámetro: posicion interna del elemento 
	// Retorno: profundidad del elemento 
	// Complejidad temporal: 
	int getProfundidadRecursivo(int posicionElemento);

	// Devuelve el recorrido en anchura del arbol. 
	// Retorno: array con una copia de los n elementos, ordenados segun el recorrido en anchura
	// Complejidad temporal: 
	int* recorrerAnchura();

public:

	// Construye un árbol con un solo elemento y con una capacidad maxima de elementos
	// Parámetros:
	// - Capacidad: capacidad máxima de elementos
	// - Raiz: valor de la raiz del árbol
	// Complejidad temporal: 
	ArbolHijo2Padre(int capacidad, int raiz);

	// Inserta un nuevo elemento en el arbol
	// Parámetros:
	// - nuevoElemento: valor del nuevo elemento
	// - valorPadre: valor del elemento que queremos que sea el padre del nuevo elemento (si hay varios, el primero que encuentre)
	// Precondición: valorPadre tiene que existir en el arbol
	// Complejidad temporal: 
	void insertar(int nuevoElemento, int valorPadre);

	// Obtiene la profundidad de un elemento
	// Parámetro: valor del elemento (si hay varios, el primero que se encuentre)
	// Retorno: profundidad del elemento 
	// Precondición: el elemento tiene que existir en el arbol
	// Complejidad temporal:
	int getProfundidad(int elemento);

	// Imprime por consola el recorrido en anchura. Cada elemento separado por un espacio del siguiente
	// Complejidad temporal: 
	void imprimir();

	// Destructor
	// Complejidad temporal: 
	~ArbolHijo2Padre();
};

int ArbolHijo2Padre::getNumeroHijosDirectos(int posicionPadre) {
	assert(posicionPadre >= 0 && posicionPadre < n);

	int nHijos = 0;

	for (int i = 0; i < n; i++) {
		if (padres[i] == posicionPadre) {
			nHijos++;
		}
	}

	return nHijos;

}

int* ArbolHijo2Padre::getPosicionHijosDirectos(int posicionPadre) {
	assert(posicionPadre >= 0 && posicionPadre < n);
	assert(getNumeroHijosDirectos(posicionPadre) > 0);

	int nHijos = getNumeroHijosDirectos(posicionPadre);

	int* arrayHijos = (int*)malloc(sizeof(int) * nHijos);
	int contadorHijos = 0;

	for (int i = 0; i < n; i++) {
		if (padres[i] == posicionPadre) {
			arrayHijos[contadorHijos] = i;
			contadorHijos++;
		}

	}

	
	return arrayHijos;
}

int ArbolHijo2Padre::buscarPosicion(int elemento) {

	int posicion = -1;

	for (int i = 0; i < n; i++) {
		if (elementos[i] == elemento) {
			posicion = i;
		}
	}

	return posicion;

}

int ArbolHijo2Padre::getProfundidadRecursivo(int posicionElemento) {
	assert(posicionElemento >= 0 && posicionElemento < n);

	if (posicionElemento == 0) {
		return 0;
	}
	else {
		return 1 + getProfundidadRecursivo(padres[posicionElemento]);
	}

}

ArbolHijo2Padre::ArbolHijo2Padre(int capacidad, int raiz) {
	elementos = (int*)malloc(sizeof(int) * capacidad);
	padres = (int*)malloc(sizeof(int) * capacidad);

	elementos[0] = raiz;
	padres[0] = -1; //la raiz no tiene padre;

	n = 1;
	this->capacidad = capacidad;

}

int* ArbolHijo2Padre::recorrerAnchura() {
	
	int* recorrido = (int*)malloc(sizeof(int) * n);
	int* cola = (int*)malloc(sizeof(int) * n);
	cola[0] = elementos[0];
	int inicioCola = 0;
	int finalCola = 0;
	int nCola = 1;
	int contadorRecorrido = 0;
	

	while (nCola > 0) {

		recorrido[contadorRecorrido] = cola[inicioCola];
		nCola--;
		inicioCola++;

		int nHijos = getNumeroHijosDirectos(buscarPosicion(recorrido[contadorRecorrido]));

		if (nHijos > 0) {
			int* posicionesHijos = getPosicionHijosDirectos(buscarPosicion(recorrido[contadorRecorrido]));
			for (int i = 0; i < nHijos; i++) {
				finalCola++;
				cola[finalCola] = elementos[posicionesHijos[i]];
				nCola++;
			}
		}
		contadorRecorrido++;

	}

	return recorrido;


	/*
	int profundidadMaxima = 0;
	int profundidadElemento;

	for (int i = 0; i < n; i++) {
		profundidadElemento = getProfundidad(elementos[i]);
		if (profundidadElemento > profundidadMaxima) {
			profundidadMaxima = profundidadElemento;
		}
	}

	int *recorrido = (int*)malloc(sizeof(int) * n);
	int contadorRecorrido = 0;

	for (int i = 0; i <= profundidadMaxima; i++) {
		for (int j = 0; j < n; j++) {
			if (getProfundidadRecursivo(j) == i) {
				recorrido[contadorRecorrido] = elementos[j];
				contadorRecorrido++;
			}

		}
	}

	return recorrido; */

}

void ArbolHijo2Padre::insertar(int nuevoElemento, int valorPadre) {
	assert(buscarPosicion(valorPadre) != -1);
	assert(n < capacidad);

	elementos[n] = nuevoElemento;
	padres[n] = buscarPosicion(valorPadre);

	n++;

}

int ArbolHijo2Padre::getProfundidad(int elemento) {
	assert(buscarPosicion(elemento) != -1);

	int posicion = buscarPosicion(elemento);

	int profundidad = getProfundidadRecursivo(posicion);

	return profundidad;

}

void ArbolHijo2Padre::imprimir() {
	
	int* recorrido = recorrerAnchura();
	

	for (int i = 0; i < n; i++) {
		cout << recorrido[i] << " ";

	}

	cout << endl;


}

ArbolHijo2Padre::~ArbolHijo2Padre() {
	free(elementos);
	free(padres);

}


int main() {

	cout << "Introduzca el elemento raiz: ";
	int raiz;
	cin >> raiz;
	ArbolHijo2Padre arbol(50, raiz); // Arbol de 50 nodos como máximo

	int opcion;
	do {

		int nuevoEntero; // Nuevo entero que pedimos al usuario para insertar
		int padre; // Padre del entero que queremos insertar 

		cout << "0. Salir" << endl;
		cout << "1. Insertar" << endl;
		cout << "2. Imprimir recorrido en anchura" << endl;
		cout << "3. Mostrar profundidad de un nodo" << endl;
		cout << "Introduce opcion: ";
		cin >> opcion;

		switch (opcion) {
		case (0): // Terminar programa
			break;
		case (1):
			cout << "Escriba el nuevo entero: ";
			cin >> nuevoEntero;
			cout << "Escriba el entero padre: ";
			cin >> padre;
			arbol.insertar(nuevoEntero, padre);
			break;
		case (2):
			arbol.imprimir();
			break;
		case (3):
			cout << "Escriba el elemento: ";
			cin >> nuevoEntero;
			cout << "Su profundidad es: " << arbol.getProfundidad(nuevoEntero) << endl;
		default:
			cout << "Opcion incorrecta" << endl;
			break;
		}
	} while (opcion != 0);
}