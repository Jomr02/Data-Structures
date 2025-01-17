#include "ListaEnlazada.h"

#include "ListaEnlazada.h"
#include "cassert"
#include <iostream>
using namespace std;

Nodo* ListaEnlazada::getNodo(int posicion) {
	assert(n > 0);
	assert(posicion >= 0 && posicion <= n - 1);

	Nodo* resultado = NULL; // Aqu� guardaremos el puntero al nodo resultado 

	// Si el nodo que queremos buscar es igual que el �ltimo accedido
	if (posicion == posicionUltimoNodoAccedido && posicionUltimoNodoAccedido != -1)
		resultado = punteroUltimoNodoAccedido;

	// Si el nodo que queremos buscar es el siguiente al �ltimo accedido
	else if (posicion == posicionUltimoNodoAccedido + 1 && posicionUltimoNodoAccedido != -1) {
		resultado = punteroUltimoNodoAccedido->siguienteNodo;
	}

	// Si el nodo que queremos buscar es el anterior al �ltimo accedido
	else if (posicion == posicionUltimoNodoAccedido - 1 && posicionUltimoNodoAccedido != -1) {
		resultado = punteroUltimoNodoAccedido->anteriorNodo;
	}

	// Si el nodo no es contiguo al ultimo accedido, y se llega antes a �l iterando hacia delante	
	else if (posicion <= n / 2) {
		resultado = punteroAPrimerNodo; // Hacemos que el resultado apunte al primer nodo
		for (int i = 0; i < posicion; i++) resultado = resultado->siguienteNodo;
	}

	// Si el nodo no es contiguo al ultimo accedido, y se llega antes a �l iterando hacia atr�s	
	else {
		resultado = punteroAPrimerNodo->anteriorNodo; // Hacemos que el resultado apunte al �ltimo nodo
		for (int i = n - 1; i > posicion; i--)
			resultado = resultado->anteriorNodo;
	}

	// Actualizamos los atributos del ultimo nodo accedido
	posicionUltimoNodoAccedido = posicion;
	punteroUltimoNodoAccedido = resultado;

	return (resultado);
}

ListaEnlazada::ListaEnlazada() {
	punteroAPrimerNodo = NULL;
	n = 0;
	posicionUltimoNodoAccedido = -1; // -1 significa que no se ha accedido aun a ninguno
	punteroUltimoNodoAccedido = NULL; // NULL significa que no se ha accedido aun a ninguno
}

int ListaEnlazada::getValor(int posicion) {
	assert(n > 0);
	assert(posicion >= 0 && posicion <= n - 1);
	// Obtenemos el nodo que contiene el elemento
	Nodo* nodoQueContieneResultado = getNodo(posicion);
	return (nodoQueContieneResultado->estudiante.clave);
}

void ListaEnlazada::setValor(int posicion, string nuevoValor) {
	assert(n > 0);
	assert(posicion >= 0 && posicion <= n - 1);
	getNodo(posicion)->estudiante.valor = nuevoValor;
}

int ListaEnlazada::getN() {
	return (n);
}

void ListaEnlazada::insertar(int posicion,int clave, string nuevoValor) {
	assert(posicion >= 0 && posicion <= n);

	// Creamos el nuevo nodo con el nuevo valor
	Nodo* nuevoNodo = new Nodo;
	nuevoNodo->estudiante.clave = clave;
	nuevoNodo->estudiante.valor = nuevoValor;

	// Si la lista estaba vacia...
	if (n == 0) {
		nuevoNodo->siguienteNodo = nuevoNodo;
		nuevoNodo->anteriorNodo = nuevoNodo;
	}

	// Si la lista no est� vac�a
	else {
		// Primero obtenemos el nodo que est� a continuaci�n del que queremos insertar
		// Nota que, si queremos insertar al final, su siguiente es el primero
		Nodo* nodoSiguiente; // Nodo a continuaci�n del que queremos insertar
		if (posicion == n) nodoSiguiente = punteroAPrimerNodo;
		else nodoSiguiente = getNodo(posicion);

		// Obtenemos el nodo anterior al que queremos insertar
		// Tengamos cuidado en hacerlo en O(1)
		Nodo* nodoAnterior = nodoSiguiente->anteriorNodo;

		// Actualizamos los punteros del nuevo nodo
		nuevoNodo->anteriorNodo = nodoAnterior;
		nuevoNodo->siguienteNodo = nodoSiguiente;

		// Actualizamos los punteros de los dos nodos que rodean al nuevo nodo
		// El puntero siguiente del anterior y el puntero anterior del siguiente apuntar�n ambos al nuevo nodo
		nodoSiguiente->anteriorNodo = nuevoNodo;
		nodoAnterior->siguienteNodo = nuevoNodo;
	} // Fin else

	// Si estamos insertando al principio de la lista, hay que modificar el puntero a la lista
	if (posicion == 0) punteroAPrimerNodo = nuevoNodo;

	// Incrementamos el numero de elementos
	n++;

	// Como hemos cambiado la configuracion de la lista, reseteamos el ultimo nodo accedido
	posicionUltimoNodoAccedido = -1; // -1 significa que no se ha accedido aun a ninguno
	punteroUltimoNodoAccedido = NULL; // NULL significa que no se ha accedido aun a ninguno
}


void ListaEnlazada::eliminar(int clave) {
	assert(n > 0);
	assert(buscar(clave) != -1);

	// Obtenemos el nodo que queremos eliminar

	int posicion = buscar(clave);
	Nodo* nodoAEliminar = getNodo(posicion);

	// Si la lista s�lo tiene un elemento, actualizamos el atributo lista pues la lista se queda vacia
	if (n == 1) punteroAPrimerNodo = NULL;

	// Si la lista tiene m�s de un elemento, hacemos el caso general
	else {

		// Obtenemos los dos nodos que le rodean
		Nodo* nodoAnterior = nodoAEliminar->anteriorNodo;
		Nodo* nodoSiguiente = nodoAEliminar->siguienteNodo;

		// Modificamos los punteros de cada uno de los dos nodos que rodean al que queremos eliminar
		nodoAnterior->siguienteNodo = nodoSiguiente;
		nodoSiguiente->anteriorNodo = nodoAnterior;

		// Si el nodo a eliminar era el 0, tenemos que actualizar el atributo lista
		if (posicion == 0) punteroAPrimerNodo = nodoSiguiente;
	} // Fin else

	// Liberamos la memoria del nodo
	delete(nodoAEliminar);

	// Actualizamos n
	n--;

	// Como hemos cambiado la configuracion de la lista, reseteamos el ultimo nodo accedido
	posicionUltimoNodoAccedido = -1; // -1 significa que no se ha accedido aun a ninguno
	punteroUltimoNodoAccedido = NULL; // NULL significa que no se ha accedido aun a ninguno
}


int ListaEnlazada::buscar(int clave) {
	int posicion = 0; // Posici�n actual en donde buscamos
	bool encontrado = false; // Nos indica si hemos encontrado o no el elemento

	// Buscamos el elemento hasta que lo encontremos o hasta que lleguemos al final
	while (!encontrado && posicion < n) {
		// Cada llamada a getValor() es O(1) porque getNodo() recuerda el �ltimo nodo accedido
		if (getValor(posicion) == clave) encontrado = true;
		posicion++;
	}

	// Devolvemos la posici�n si lo hemos encontrado, o -1 en caso contrario
	if (encontrado) return (posicion - 1);
	else return (-1);
}


void ListaEnlazada::imprimir() {

	if (n == 0) {
		cout << "Lista Vacia\n";

	}
	else {
		for (int i = 0; i < n; i++) {

			Nodo* nodo = getNodo(i);

			cout << "Clave: " << nodo->estudiante.clave;
			cout << "Nombre: " << nodo->estudiante.valor;

			cout << "\n";
		}

	}



}

ListaEnlazada::~ListaEnlazada() {
	// Eliminamos el primer elemento de la lista. Esta operaci�n la repetimos n veces
	// Eliminar el primer elemento de la lista es O(1)
	while (n > 0) eliminar(0);
}



