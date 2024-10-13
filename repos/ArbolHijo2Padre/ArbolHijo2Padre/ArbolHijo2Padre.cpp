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

	void imprimirRecursivo(int posicionElemento, int tabulaciones);

	void recorridoPreOrden(int posicionElemento);
	void recorridoInOrden(int posicionElemento);
	void recorridoPostOrden(int posicionElemento);

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
	assert(posicionPadre < n);
	assert(posicionPadre >= 0);

	int numeroHijosDirectos = 0;

	for (int i = 0; i < n; i++) {
		if (padres[i] == posicionPadre) {
			numeroHijosDirectos++;
		}

	}

	return numeroHijosDirectos;
}

int* ArbolHijo2Padre::getPosicionHijosDirectos(int posicionPadre) {
	assert(posicionPadre < n);
	assert(posicionPadre >= 0);
	assert(getNumeroHijosDirectos(posicionPadre) > 0);

	int numeroHijosDirectos = getNumeroHijosDirectos(posicionPadre);

	int* posicionesHijosDirectos = (int*)malloc(numeroHijosDirectos * sizeof(int));
	int indice = 0;

	for (int i = 0; i < n; i++) {
		if (padres[i] == posicionPadre) {
			posicionesHijosDirectos[indice] = i;
			indice++;
		}
	}

	return posicionesHijosDirectos;

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
	assert(posicionElemento < n);
	assert(posicionElemento >= 0);

	if (padres[posicionElemento] >= n || padres[posicionElemento] < 0) {
		return 0;
	}
	else {
		return 1 + getProfundidadRecursivo(padres[posicionElemento]);
	}

}

ArbolHijo2Padre::ArbolHijo2Padre(int capacidad, int raiz) {

	padres = (int*) malloc(capacidad * sizeof(int));
	elementos = (int*) malloc(capacidad * sizeof(int));

	padres[0] = -1;
	elementos[0] = raiz;

	n = 1;

	this->capacidad = capacidad;

}

void ArbolHijo2Padre::imprimirRecursivo(int posicionElemento, int tabulaciones) {
	assert(tabulaciones >= 0);

	for (int i = 0; i < tabulaciones; i++) {
		cout << "\t";
	}

	cout << elementos[posicionElemento] << endl;
	

	int nHijos = getNumeroHijosDirectos(posicionElemento);

	if (nHijos > 0) {
		int* arrayHijos = getPosicionHijosDirectos(posicionElemento);

		for (int i = 0; i < nHijos; i++) {
			imprimirRecursivo(arrayHijos[i], tabulaciones + 1);
		}
	}


}

int* ArbolHijo2Padre::recorrerAnchura() {


	int* recorrido = (int*)malloc(n * sizeof(int));

	recorrido[0] = elementos[0];

	int posicion = 0;
	int numeroDeElementosEnRecorrido = 1;
	int indice = 1;

	int* cola = (int*)malloc(n * sizeof(int));
	int finalCola = -1;
	int inicioCola = 0;

	while (numeroDeElementosEnRecorrido < n) {
		int numeroHijos = getNumeroHijosDirectos(posicion);

		if (numeroHijos > 0) {
			int* hijosDirectos = getPosicionHijosDirectos(posicion);

			for (int i = 0; i < numeroHijos; i++) {
				cola[finalCola + 1] = hijosDirectos[i];
				finalCola++;
				recorrido[indice] = elementos[hijosDirectos[i]];
				numeroDeElementosEnRecorrido++;
				indice++;
			}
		}
		posicion = cola[inicioCola];
		inicioCola++;
	}

	return recorrido;

}

void ArbolHijo2Padre::insertar(int nuevoElemento, int valorPadre) {
	assert(buscarPosicion(valorPadre) != -1);

	int posicionPadre = buscarPosicion(valorPadre);

	elementos[n] = nuevoElemento;
	padres[n] = posicionPadre;

	n++;

}

int ArbolHijo2Padre::getProfundidad(int elemento) {
	assert(buscarPosicion(elemento) != -1);

	int posicionElemento = buscarPosicion(elemento);

	return (getProfundidadRecursivo(posicionElemento));

}

void ArbolHijo2Padre::imprimir() {

	imprimirRecursivo(0, 0);



	cout << "Recorrido en anchura: ";
	int* recorridoAnchura = recorrerAnchura();

	for (int i = 0; i < n; i++) {
		cout << recorridoAnchura[i] << " ";

	}

	cout << endl;

	cout << "Recorrido en preorden: ";
	recorridoPreOrden(0);
	cout << endl;

	cout << "Recorrido en inorden: ";
	recorridoInOrden(0);
	cout << endl;

	cout << "Recorrido en postorden: ";
	recorridoPostOrden(0);
	cout << endl;

}

void ArbolHijo2Padre::recorridoPreOrden(int posicionElemento) {
	assert(posicionElemento >= 0);

	cout << elementos[posicionElemento] << " ";

	int nHijos = getNumeroHijosDirectos(posicionElemento);
	

	if (nHijos > 0) {
		int* arrayHijos = getPosicionHijosDirectos(posicionElemento);
		for (int i = 0; i < nHijos; i++) {
			recorridoPreOrden(arrayHijos[i]);

		}
	}
}
void ArbolHijo2Padre::recorridoInOrden(int posicionElemento) {
	assert(posicionElemento >= 0);

	int nHijos = getNumeroHijosDirectos(posicionElemento);
	

	if (nHijos > 0) {
		int* arrayHijos = getPosicionHijosDirectos(posicionElemento);
		recorridoInOrden(arrayHijos [0]);

	}

	cout << elementos[posicionElemento] << " ";

	if (nHijos > 1) {
		int* arrayHijos = getPosicionHijosDirectos(posicionElemento);
		for (int i = 1; i < nHijos; i++) {
			recorridoInOrden(arrayHijos[i]);
		}

	}


}
void ArbolHijo2Padre::recorridoPostOrden(int posicionElemento) {
	assert(posicionElemento >= 0);

	int nHijos = getNumeroHijosDirectos(posicionElemento);

	if (nHijos > 0) {
		int* arrayHijos = getPosicionHijosDirectos(posicionElemento);
		if (nHijos > 0) {
			for (int i = 0; i < nHijos; i++) {
				recorridoPostOrden(arrayHijos[i]);

			}
		}


	}

	cout << elementos[posicionElemento] << " ";

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



	/*
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

	*/
}