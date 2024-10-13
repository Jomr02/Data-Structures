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

	for (int i = 1; i < n; i++) {
		if (padres[i] == posicionPadre)
			nHijos++;
	}

	return nHijos;

}

int* ArbolHijo2Padre::getPosicionHijosDirectos(int posicionPadre) {
	assert(posicionPadre >= 0 && posicionPadre < n);
	assert(getNumeroHijosDirectos(posicionPadre) > 0);

	int nHijos = getNumeroHijosDirectos(posicionPadre);

	int* arrayPosicionesHijos = (int*) malloc(sizeof(int) * nHijos);

	int i = 1;
	int contadorHijos = 0;

	while (i < n && contadorHijos < nHijos) {
		if (padres[i] == posicionPadre) {
			arrayPosicionesHijos[contadorHijos] = i;
			contadorHijos++;
		}
		i++;
	}

	return arrayPosicionesHijos;
}

int ArbolHijo2Padre::buscarPosicion(int elemento) {

	bool encontrado = false;
	int posicionElemento = -1;
	int i = 0;

	while (!encontrado && i < n)
	{
		if (elementos[i] == elemento) {
			posicionElemento = i;
			encontrado = true;
		}
		i++;
	}

	return posicionElemento;

}

int ArbolHijo2Padre::getProfundidadRecursivo(int posicionElemento) {
	assert(posicionElemento >= 0 && posicionElemento < n);

	if (posicionElemento == 0) {
		return 0;
	}
	else {
		int posicionPadre = padres[posicionElemento];
		return (1 + getProfundidadRecursivo(posicionPadre));
	}

}

ArbolHijo2Padre::ArbolHijo2Padre(int capacidad, int raiz) {
	elementos = (int*)malloc(sizeof(int) * capacidad);
	padres = (int*)malloc(sizeof(int) * capacidad);

	this->capacidad = capacidad;

	elementos[0] = raiz;

	n = 1;


}

int* ArbolHijo2Padre::recorrerAnchura() {

	int profundidadMaxima = 0;

	for (int i = 0; i < n; i++) {
		int profundidad = getProfundidadRecursivo(i);
		if (profundidad > profundidadMaxima) {
			profundidadMaxima = profundidad;
		}
	}

	int* recorridoAnchura = (int*)malloc(sizeof(int) * n);
	int indiceRecorrido = 0;

	for (int j = 0; j <= profundidadMaxima; j++) {
		for (int k = 0; k < n; k++) {
			if (getProfundidadRecursivo(k) == j) {
				recorridoAnchura[indiceRecorrido] = elementos[k];
				indiceRecorrido++;
			}

		}
	}

	return (recorridoAnchura);


}

void ArbolHijo2Padre::insertar(int nuevoElemento, int valorPadre) {
	assert(buscarPosicion(valorPadre) != -1);

	elementos[n] = nuevoElemento;
	padres[n] = buscarPosicion(valorPadre);


	n++;


}

int ArbolHijo2Padre::getProfundidad(int elemento) {
	assert(buscarPosicion(elemento) != -1);

	int posicionElemento = buscarPosicion(elemento);

	int profundidad = getProfundidadRecursivo(posicionElemento);

	return profundidad;

}

void ArbolHijo2Padre::imprimir() {

	int *recorridoAnchura = recorrerAnchura();

	for (int i = 0; i < n; i++) {
		cout << recorridoAnchura[i] << " ";
	}
	cout << endl;

}

ArbolHijo2Padre::~ArbolHijo2Padre() {
	free(padres);
	free(elementos);

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