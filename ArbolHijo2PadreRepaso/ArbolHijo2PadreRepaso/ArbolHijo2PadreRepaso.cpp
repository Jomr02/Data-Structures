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

ArbolHijo2Padre::ArbolHijo2Padre(int capacidad, int raiz) {

	elementos = (int*)malloc(capacidad * sizeof(int));
	padres = (int*)malloc(capacidad * sizeof(int));

	this->capacidad = capacidad;
	n = 1;

	elementos[0] = raiz;
	padres[0] = -1;

}

int ArbolHijo2Padre::getNumeroHijosDirectos(int posicionPadre) {
	assert(posicionPadre >= 0);
	assert(posicionPadre < n);

	int numeroHijos = 0;

	for (int i = 0; i < n; i++) {
		if (padres[i] == posicionPadre) {
			numeroHijos++;
		}

	}

	return numeroHijos;
}

int* ArbolHijo2Padre::getPosicionHijosDirectos(int posicionPadre) {
	assert(posicionPadre >= 0);
	assert(posicionPadre < n);
	int nHijos = getNumeroHijosDirectos(posicionPadre);
	assert(nHijos > 0);

	int* posicionesHijos = (int*)malloc(nHijos * sizeof(int));

	int contadorHijos = 0;

	for (int i = 0; i < n; i++) {
		if (padres[i] == posicionPadre) {
			posicionesHijos[contadorHijos] = i;
			contadorHijos++;
		}

	}

	return posicionesHijos;

}

int ArbolHijo2Padre::buscarPosicion(int elemento) {

	int posicionElemento = -1;

	for (int i = 0; i < n; i++) {
		if (elementos[i] == elemento) {
			posicionElemento = i;
			break;
		}
	}

	return posicionElemento;
}

int ArbolHijo2Padre::getProfundidadRecursivo(int posicionElemento) {

	if (padres[posicionElemento] < 0) {
		return 0;

	}
	else {
		return 1 + getProfundidadRecursivo(padres[posicionElemento]);
	}



}

int* ArbolHijo2Padre::recorrerAnchura() {
	assert(n > 0);

	int* cola = (int*)malloc(n * sizeof(int));
	int inicioCola = 0;
	int finalCola = 0;
	cola[0] = elementos[0];
	int nCola = 1;

	while (nCola > 0) {
		int nHijos = getNumeroHijosDirectos(buscarPosicion(cola[inicioCola]));
		if (nHijos > 0) {
			int* posicionesHijos = getPosicionHijosDirectos(buscarPosicion(cola[inicioCola]));
			for (int i = 0; i < nHijos; i++) {
				finalCola++;
				cola[finalCola] = elementos[posicionesHijos[i]];
				nCola++;
			}
		}
		inicioCola++;
		nCola--;

	}

	return cola;
}

void ArbolHijo2Padre::insertar(int nuevoElemento, int valorPadre) {
	assert(buscarPosicion(valorPadre) >= 0);
	assert(n != capacidad);

	int posicionPadre = buscarPosicion(valorPadre);

	elementos[n] = nuevoElemento;
	padres[n] = posicionPadre;

	n++;


}

int ArbolHijo2Padre::getProfundidad(int elemento) {
	assert(buscarPosicion(elemento) >= 0);

	int posicionElemento = buscarPosicion(elemento);

	int profundidad = getProfundidadRecursivo(posicionElemento);


	return profundidad;
}

void ArbolHijo2Padre::imprimir() {
	

	int* recorrido = recorrerAnchura();

	for (int i = 0; i < n; i++) {
		cout << recorrido[i];

		if (i < n - 1) {
			cout << ", ";

		}

	}

	cout << endl;

}

ArbolHijo2Padre::~ArbolHijo2Padre() {
	free(padres);
	free(elementos);
}


int main() {

	ArbolHijo2Padre arbol(50, 1); 
	arbol.insertar(2, 1);
	arbol.insertar(3, 1);
	arbol.insertar(4, 2);
	arbol.insertar(5, 2);
	arbol.insertar(6, 5);
	arbol.insertar(7, 5);
	arbol.insertar(8, 5);
	arbol.insertar(9, 3);
	arbol.insertar(10, 3);
	arbol.imprimir();

	
}