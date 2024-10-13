// EnlazadaDobleCircular.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <cassert>

using namespace std;



struct Nodo {
    int elemento;
    Nodo* siguiente;
    Nodo* anterior;
};

class EnlazadaDobleCircular {
	// Puntero que apuntará al primer nodo de la lista, o será NULL si la lista está vacía
	Nodo* punteroAPrimerNodo;

	// Numero actual de elementos que tiene la lista
	// Precondición: n>=0
	int n;

	// Posición y puntero del nodo que devolvió la última llamada a getNodo()
	int posicionUltimoNodoAccedido;
	Nodo* ultimoNodoAccedido;

	// Obtiene un nodo de la lista
	// Parámetro: la posición del nodo
	// Retorno: un puntero al nodo que está en dicha posición
	// Precondiciones: 
	// - la posición debe estar en el intervalo [0, n-1]
	// - La lista no esta vacia (n>0)
	// Complejidad temporal: O(n). Como máximo hace n/2 iteraciones porque decide si ir hacia delante o hacia atrás
	Nodo* getNodo(int posicion);

public:

	// Constructor. Crea una lista de tamaño 0
	// Complejidad temporal: O(1)
	EnlazadaDobleCircular();

	// Devuelve un elemento de la lista en determinada posición
	// Parámetro: la posición del elemento
	// Retorno: una copia del elemento encontrado en esa posición
	// Precondiciones: posicion en [0, n-1] y n>0
	// Complejidad temporal: O(n)
	int getValor(int posicion);

	// Modifica un elemento de la lista
	// Parámetros:
	// - posicion: la posición del elemento que queremos modificar
	// - nuevoValor: el nuevo valor del elemento
	// Precondiciones: posicion en [0, n-1] y n>0
	// Complejidad temporal: O(n)
	void setValor(int posicion, int nuevoValor);

	// Devuelve el tamaño actual de la lista
	// Complejidad temporal: O(1)
	int getN();

	// Inserta un nuevo elemento en una posición de la lista
	// Parámetros:
	// - posición: la posición en donde queremos poner el nuevo elemento. Si es 0 se inserta al principio, si es n se inserta al final
	// - nuevoValor: el nuevo elemento que queremos poner
	// Precondiciones: posicion en [0, n]
	// Complejidad temporal: O(n)
	void insertar(int posicion, int nuevoValor);

	// Elimina un elemento en una posición dada.
	// Parámetros:
	// - posicion: la posición del elemento que queremos borrar. Si es 0 se elimina el primero y si es n-1 se elimina el último
	// Precondiciones: posicion en [0, n-1] y n>0
	// Complejidad temporal: O(n)
	void eliminar(int posicion);

	// Concatena una lista al final de la lista actual
	// Cada uno de los elementos de la lista a concatenar se copian, en orden, al final de la lista actual
	// Parámetro: puntero a la lista cuyos elementos queremos concatenar al final de nuestra lista
	// Precondición: listaAConcatenar!=NULL
	// Complejidad temporal: O(m), siendo m = listaAConcatenar.getN()
	void concatenar(EnlazadaDobleCircular* listaAConcatenar);

	// Busca la posición de un elemento en la ListaContigua
	// Parámetro: el elemento a buscar
	// Retorno: posición del elemento (de 0 a n-1) si se encuentra, o -1 en caso contrario
	// Complejidad temporal: O(n)
	int buscar(int elementoABuscar);

	// Destructor. Libera memoria
	// Complejidad temporal: O(n)
	~EnlazadaDobleCircular();


	void imprimir();




};

EnlazadaDobleCircular::EnlazadaDobleCircular() {
	punteroAPrimerNodo = NULL;
	n = 0;
	posicionUltimoNodoAccedido = -1;
	ultimoNodoAccedido = NULL;
}

int EnlazadaDobleCircular::getN() {
	return n;
}

Nodo* EnlazadaDobleCircular::getNodo(int posicion) {
	assert(posicion >= 0 && posicion < n);

	Nodo *resultado = NULL;

	if (posicion == 0) {
		resultado = punteroAPrimerNodo;

	}
	else if (posicion == n - 1) {
		resultado = punteroAPrimerNodo->anterior;

	} else {
		if (posicion == posicionUltimoNodoAccedido) {
			resultado = ultimoNodoAccedido;
		}
		else if (posicion == (posicionUltimoNodoAccedido + 1) % n) {
			resultado = ultimoNodoAccedido->siguiente;
		}
		else if (posicion == (posicionUltimoNodoAccedido - 1) % n) {
			resultado = ultimoNodoAccedido->anterior;
		}
		else { //si tenemos que hacer busqueda secuencial
			resultado = punteroAPrimerNodo;
			for (int i = 0; i < posicion; i++) {
				resultado = resultado->siguiente;
			}
		}
		
	}

	ultimoNodoAccedido = resultado;
	posicionUltimoNodoAccedido = posicion;



	return resultado;
}


void EnlazadaDobleCircular::insertar(int posicion, int nuevoValor) {
	assert(posicion >= 0 && posicion <= n);

	Nodo *nodoAinsertar = new Nodo;
	nodoAinsertar->elemento = nuevoValor;

	if (n == 0) {
		nodoAinsertar->anterior = nodoAinsertar;
		nodoAinsertar->siguiente = nodoAinsertar;

		punteroAPrimerNodo = nodoAinsertar;
	}
	else {
		if (posicion == n) {
			Nodo* ultimoNodo = getNodo(n - 1);
			ultimoNodo->siguiente = nodoAinsertar;
			nodoAinsertar->anterior = ultimoNodo;
			nodoAinsertar->siguiente = punteroAPrimerNodo;
			punteroAPrimerNodo->anterior = nodoAinsertar;
		}
		else if (posicion == 0) {
				Nodo* ultimoNodo = getNodo(n - 1);
				ultimoNodo->siguiente = nodoAinsertar;
				nodoAinsertar->anterior = ultimoNodo;
				nodoAinsertar->siguiente = punteroAPrimerNodo;
				punteroAPrimerNodo->anterior = nodoAinsertar;

				punteroAPrimerNodo = nodoAinsertar;
			}

		else {
			Nodo* nodoSiguiente = getNodo (posicion);
			Nodo* nodoAnterior = nodoSiguiente->anterior;

			nodoAnterior->siguiente = nodoAinsertar;
			nodoAinsertar->anterior = nodoAnterior;
			nodoSiguiente->anterior = nodoAinsertar;
			nodoAinsertar->siguiente = nodoSiguiente;
		}

		ultimoNodoAccedido = NULL;
		posicionUltimoNodoAccedido = -1;
		

	}

	n++;
}

void EnlazadaDobleCircular::eliminar(int posicion) {
	assert(posicion >= 0 && posicion < n);
	assert(getN() > 0);

	Nodo* nodoAeliminar = getNodo(posicion);

	

	if (getN() == 1) { //solo hay un elemento
		punteroAPrimerNodo = NULL;
	}
	else {
		if (posicion == 0) {
			Nodo* ultimoNodo = punteroAPrimerNodo->anterior;
			Nodo* segundoNodo = punteroAPrimerNodo->siguiente;

			ultimoNodo->siguiente = segundoNodo;
			segundoNodo->anterior = ultimoNodo;

			punteroAPrimerNodo = segundoNodo;

		}
		else if (posicion == n - 1) {
			Nodo* penultimoNodo = nodoAeliminar->anterior;
			penultimoNodo->siguiente = punteroAPrimerNodo;
			punteroAPrimerNodo->anterior = penultimoNodo;
		}
		else {
			Nodo* anteriorNodo = nodoAeliminar->anterior;
			Nodo* siguienteNodo = nodoAeliminar->siguiente;

			anteriorNodo->siguiente = siguienteNodo;
			siguienteNodo->anterior = anteriorNodo;

		}

	}



	delete (nodoAeliminar);
	n--;


	ultimoNodoAccedido = NULL;
	posicionUltimoNodoAccedido = -1;

}


void EnlazadaDobleCircular::imprimir() {
	cout << "Numero de elementos: " << getN() << endl;

	for (int i = 0; i < n; i++) {
		cout << getValor(i);
		if (i != n - 1)
			cout << ",";

	}

	cout << endl;

}


int EnlazadaDobleCircular::buscar(int elemento) {
	int posicionElemento = -1;


	if (getNodo(0)->elemento == elemento) {
		posicionElemento = 0;
	}
	else if (getNodo(n - 1)->elemento == elemento) {
		posicionElemento = n - 1;
	}
	else {
		if (ultimoNodoAccedido->elemento == elemento) {
			posicionElemento = posicionUltimoNodoAccedido;
		}
		else if (ultimoNodoAccedido->anterior->elemento == elemento) {
			posicionElemento = (posicionUltimoNodoAccedido - 1) % n;
		}
		else if (ultimoNodoAccedido->siguiente->elemento == elemento) {
			posicionElemento = (posicionUltimoNodoAccedido + 1) % n;

		}
		else {
			Nodo* resultado = punteroAPrimerNodo;
			for (int i = 0; i < n; i++) {
				if (resultado->elemento == elemento) {
					posicionElemento = i;
				}
				resultado = resultado->siguiente;
			}
		}

	}

	return posicionElemento;

}

int EnlazadaDobleCircular::getValor(int posicion) {
	assert(posicion >= 0 && posicion < n);

	return (getNodo(posicion)->elemento);

}

void EnlazadaDobleCircular::setValor(int posicion, int nuevoValor) {
	assert(posicion >= 0 && posicion < n);

	getNodo(posicion)->elemento = nuevoValor;
}


void EnlazadaDobleCircular::concatenar(EnlazadaDobleCircular* listaAConcatenar) {
	assert(listaAConcatenar != NULL);

	int nListaAConcatenar = listaAConcatenar->getN();

	for (int i = 0; i < nListaAConcatenar; i++) {
		insertar(getN(), listaAConcatenar->getValor(i));
	}

}




EnlazadaDobleCircular::~EnlazadaDobleCircular() {
	while (n>0) {
		eliminar(0);
	}
}





int main()
{
	EnlazadaDobleCircular *lista = new EnlazadaDobleCircular;
	EnlazadaDobleCircular *lista2 = new EnlazadaDobleCircular;


	lista->insertar(0, 2);
	lista->insertar(1, 3);
	lista->insertar(2, 4);
	lista->insertar(3, 5);
	lista->insertar(4, 20);
	lista->insertar(2, 40);
	lista->insertar(6, 10);

	lista->imprimir();

	lista2->insertar(0, 21);
	lista2->insertar(0, 34);
	lista2->insertar(0, 56);

	lista2->imprimir();

	lista->concatenar(lista2);
	lista->imprimir();

	lista->~EnlazadaDobleCircular();
	lista2->~EnlazadaDobleCircular();

	

	return 0;
}


