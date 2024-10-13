// ListaContigua.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <cassert>
#define INCREMENTO 2

using namespace std;


class ListaContigua
{
	// Puntero que apuntará a la zona de memoria en donde empieza la ListaContigua
	int* lista;

	// Numero actual de elementos que tiene la ListaContigua
	// Precondición: n>=0
	int n;

	// Capacidad actual de la ListaContigua
	// Precondiciones: capacidad >= n
	int capacidad;

	// Nos dice si la ListaContigua está llena o no.
	// Retorno: verdadero si está llena, falso si no está llena
	// Complejidad temporal: O(1)
	bool isLlena();

public:

	// Constructor. Crea una ListaContigua de tamaño 0
	// Complejidad temporal: O(1)
	ListaContigua();

	// Devuelve un elemento de la ListaContigua
	// Parámetro: la posición del elemento
	// Retorno: el elemento encontrado en esa posición
	// Precondiciones: posicion en [0, n-1]
	// Complejidad temporal: O(1)
	int getValor(int posicion);

	// Modifica un elemento de la ListaContigua
	// Parámetros:
	// - posicion: la posición del elemento que queremos modificar
	// - nuevoValor: el nuevo valor del elemento
	// Precondiciones:
	// - posicion en [0, n-1]
	// Complejidad temporal: O(1)
	void setValor(int posicion, int nuevoValor);

	// Devuelve el tamaño actual de la ListaContigua
	// Retorno: número actual de elementos de la ListaContigua
	// Complejidad temporal: O(1)
	int getN();

	// Devuelve la capacidad actual de la ListaContigua
	// Retorno: número máximo que actualmente podría contener la ListaContigua
	// Complejidad temporal: O(1)
	int getCapacidad();

	// Inserta un nuevo elemento en la última posición de la ListaContigua, 
	// ampliando previamente la capacidad si es necesario
	// Parámetros:
	// - nuevoValor: el nuevo elemento que queremos poner
	// Complejidad temporal: O(n)
	void insertarAlFinal(int nuevoValor);

	// Elimina el elemento de la última posición de la ListaContigua,
	// disminuyendo posteriormente la capacidad si es necesario
	// Complejidad temporal: O(1)
	void eliminarAlFinal();

	// Inserta un nuevo elemento en una posición de la lista, dejando primero un hueco para meterlo ahí
	// Los elementos que había desde la posición hasta el final de la ListaContigua se desplazarán una posición a la derecha
	// Parámetros:
	// - posición: la posición en donde queremos poner el nuevo elemento. Si es 0 se inserta al principio, si es n se inserta al final
	// - nuevoValor: el nuevo elemento que queremos poner
	// Precondiciones:
	// - posicion en [0, n]
	// Complejidad temporal: O(n)
	void insertar(int posicion, int nuevoValor);

	// Elimina un elemento en una posición dada.
	// Los elementos que había desde posicion+1 hasta el final de la ListaContigua se desplazarán una posición a la izquierda
	// Parámetros:
	// - posicion: la posición del elemento que queremos borrar. Si es 0 se elimina el primero y si es n-1 se elimina el último
	// Precondiciones:
	// - posicion en [0, n-1]
	// Complejidad temporal: O(n)
	void eliminar(int posicion);

	// Concatena una lista al final de la lista actual. 
	// Cada uno de los elementos de la lista a concatenar se copian, en orden, al final de la lista actual
	// Parámetro: puntero a la lista cuyos elementos queremos concatenar al final de nuestra lista
	// Precondición: listaAConcatenar!=NULL
	// Complejidad temporal: O(n+m), siendo m = listaAConcatenar.getN()
	void concatenar(ListaContigua* listaAConcatenar);

	// Busca la posición de un elemento en la ListaContigua
	// Parámetro: el elemento a buscar
	// Retorno: posición del elemento (de 0 a n-1) si se encuentra, o -1 en caso contrario
	// Complejidad temporal: O(n)
	int buscar(int elementoABuscar);

	void imprimir();

	// Destructor. Libera memoria
	// Complejidad temporal: O(1)
	~ListaContigua();
};

ListaContigua::ListaContigua() {
	lista = NULL;
	n = 0;
	capacidad = 0;
}

bool ListaContigua::isLlena() {
	return (n == capacidad);

}

void ListaContigua::insertar(int posicion, int nuevoValor) {
	assert(posicion >= 0 && posicion <= capacidad);

	if (isLlena()) {
		lista = (int*)realloc(lista, sizeof(int) * (capacidad + INCREMENTO));
		capacidad = capacidad + INCREMENTO;
	}

	memmove(&lista[posicion + 1], &lista[posicion], sizeof(int) * (n - posicion + 1));

	lista[posicion] = nuevoValor;

	n++;


}

void ListaContigua::imprimir() {
	if (n == 0) {
		cout << "Lista vacia";
	}
	else {
		cout << "Lista de capacidad " << capacidad << " y " << n << " elementos" << endl;
		for (int i = 0; i < n; i++) {
			cout << lista[i] << " ";
		}
	}

	cout << endl;


}

void ListaContigua::eliminar(int posicion) {
	assert(n > 0);
	assert(posicion >= 0 && posicion < n);

	memmove(&lista[posicion], &lista[posicion + 1], sizeof(int) * (n - posicion));

	n--;


	if (capacidad - n >= 2 * INCREMENTO) {
		lista = (int*)realloc(lista, sizeof(int) * (capacidad - INCREMENTO));
		capacidad = capacidad - INCREMENTO;
	}
}

int ListaContigua::buscar(int elementoABuscar) {
	int posicion = -1;

	for (int i = 0; i < n; i++) {
		if (lista[i] == elementoABuscar)
			posicion = i;
	}

	return posicion;
}

void ListaContigua::insertarAlFinal(int nuevoValor) {
	insertar(n, nuevoValor);
}

int ListaContigua::getN() {
	return n;
}

int ListaContigua::getValor(int posicion) {
	assert(posicion >= 0 && posicion < n);

	return lista[posicion];
}

int ListaContigua::getCapacidad() {
	return capacidad;
}

void ListaContigua::setValor(int posicion, int nuevoValor) {
	assert(posicion >= 0 && posicion < n);

	lista[posicion] = nuevoValor;

}

void ListaContigua::eliminarAlFinal() {
	eliminar(n - 1);
}



void ListaContigua::concatenar(ListaContigua* listaAConcatenar) {
	assert(listaAConcatenar != NULL);

	for (int i = 0; i < listaAConcatenar->getN(); i++) {
		insertarAlFinal(listaAConcatenar->getValor(i));
	}

}



ListaContigua::~ListaContigua() {
	lista = NULL;
}



int main()
{
	ListaContigua lista;
	lista.imprimir();
	lista.insertar(0, 1);
	lista.imprimir();
	lista.insertar(1, 4);
	lista.insertar(2, 3);
	lista.insertar(3, 2);
	lista.insertar(1, 4);
	lista.insertar(2, 3);
	lista.insertar(3, 2);
	lista.imprimir();
	lista.eliminar(1);
	lista.imprimir();
	lista.eliminar(1);
	lista.imprimir();
	lista.eliminar(1);
	lista.imprimir();
	cout << lista.buscar(1) << endl;

	ListaContigua *lista2 = new ListaContigua;

	lista2->insertar(0, 50);
	lista2->insertarAlFinal(30);
	lista2->insertarAlFinal(100);
	lista2->imprimir();

	lista.concatenar(lista2);
	lista.imprimir();
	lista.insertarAlFinal(80);
	lista.imprimir();
	lista.insertarAlFinal(200);
	lista.imprimir();

}


