#pragma once
#pragma once
#include "Nodo.h"


// Clase que representa a una lista enlazada doble y circular. No tiene restricci�n de tama�o
// Se trata de una lista enlazada de nodos, en donde cada nodo tiene un elemento (un int), y punteros al siguiente y anterior nodo
class ListaEnlazada
{
	// Puntero que apuntar� al primer nodo de la lista, o ser� NULL si la lista est� vac�a
	Nodo* punteroAPrimerNodo;

	// Numero actual de elementos que tiene la lista
	// Precondici�n: n>=0
	int n;

	// Posici�n y puntero del nodo que devolvi� la �ltima llamada a getNodo()
	int posicionUltimoNodoAccedido;
	Nodo* punteroUltimoNodoAccedido;

	// Obtiene un nodo de la lista
	// Par�metro: la posici�n del nodo
	// Retorno: un puntero al nodo que est� en dicha posici�n
	// Precondiciones: 
	// - la posici�n debe estar en el intervalo [0, n-1]
	// - La lista no esta vacia (n>0)
	// Complejidad temporal: O(n). Como m�ximo hace n/2 iteraciones porque decide si ir hacia delante o hacia atr�s


public:

	// Constructor. Crea una lista de tama�o 0
	// Complejidad temporal: O(1)
	ListaEnlazada();


	Nodo* getNodo(int posicion);
	// Devuelve un elemento de la lista en determinada posici�n
	// Par�metro: la posici�n del elemento
	// Retorno: una copia del elemento encontrado en esa posici�n
	// Precondiciones: posicion en [0, n-1] y n>0
	// Complejidad temporal: O(n)
	int getValor(int posicion);

	// Modifica un elemento de la lista
	// Par�metros:
	// - posicion: la posici�n del elemento que queremos modificar
	// - nuevoValor: el nuevo valor del elemento
	// Precondiciones: posicion en [0, n-1] y n>0
	// Complejidad temporal: O(n)
	void setValor(int posicion, string nuevoValor);

	// Devuelve el tama�o actual de la lista
	// Complejidad temporal: O(1)
	int getN();

	// Inserta un nuevo elemento en una posici�n de la lista
	// Par�metros:
	// - posici�n: la posici�n en donde queremos poner el nuevo elemento. Si es 0 se inserta al principio, si es n se inserta al final
	// - nuevoValor: el nuevo elemento que queremos poner
	// Precondiciones: posicion en [0, n]
	// Complejidad temporal: O(n)
	void insertar(int posicion, int clave, string nuevoValor);

	// Elimina un elemento en una posici�n dada.
	// Par�metros:
	// - posicion: la posici�n del elemento que queremos borrar. Si es 0 se elimina el primero y si es n-1 se elimina el �ltimo
	// Precondiciones: posicion en [0, n-1] y n>0
	// Complejidad temporal: O(n)
	void eliminar(int clave);

	// Concatena una lista al final de la lista actual
	// Cada uno de los elementos de la lista a concatenar se copian, en orden, al final de la lista actual
	// Par�metro: puntero a la lista cuyos elementos queremos concatenar al final de nuestra lista
	// Precondici�n: listaAConcatenar!=NULL
	// Complejidad temporal: O(m), siendo m = listaAConcatenar.getN()
	void concatenar(ListaEnlazada* listaAConcatenar);

	// Busca la posici�n de un elemento en la ListaContigua
	// Par�metro: el elemento a buscar
	// Retorno: posici�n del elemento (de 0 a n-1) si se encuentra, o -1 en caso contrario
	// Complejidad temporal: O(n)
	int buscar(int elementoABuscar);


	void imprimir();

	// Destructor. Libera memoria
	// Complejidad temporal: O(n)
	~ListaEnlazada();
};







