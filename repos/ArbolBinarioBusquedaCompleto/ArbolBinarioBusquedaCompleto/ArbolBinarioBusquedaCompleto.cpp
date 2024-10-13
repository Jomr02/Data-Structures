#pragma once

#include <iostream>
#include <cassert>

using namespace std;

struct Nodo {
	int contenido;
	Nodo* padre;
	Nodo* hijoIzquierdo;
	Nodo* hijoDerecho;
};

// Árbol binario de búsqueda. Se permiten duplicados, y éstos van hacia la izquierda
class ArbolBinarioDeBusqueda
{
	Nodo* raiz; // Raiz del árbol, o NULL si el arbol está vacío
	int n; // Numero de nodos del arbol
	int orientacionSiguienteEliminacion; // Orientacion (-1 si es izquierdo, 1 si es derecho) que tendrá que tener la siguiente eliminación a realizar

public:

	// Construye un árbol binario de búsqueda vacío
	// Complejidad temporal: O(1)
	ArbolBinarioDeBusqueda();

	// Inserta un elemento (siempre se insertará como hoja)
	// Parámetro: nuevo elemento a insertar. Lo coloca en su sitio adecuado
	// Precondición: nuevoElemento no existía previamente en el árbol
	// Complejidad temporal: O(lgn) con la mejor topología, O(n) con la peor
	void insertar(int nuevoElemento);

	// Busca un elemento en el arbol binario de busqueda
	// Parámetro: elementoABuscar es la clave del nodo que queremos encontrar
	// Retorno: true si se encuentra en el árbol, false si no
	// Complejidad temporal: O(lgn) con la mejor topología, O(n) con la peor
	bool buscar(int elementoABuscar);

	// Elimina el primer nodo que se encuentre con un elemento dado
	// Parámetro: elemento a eliminar
	// Precondiciones: elementoAEliminar existe en el árbol
	// Complejidad temporal: O(lgn) con la mejor topología, O(n) con la peor
	void eliminar(int elementoAEliminar);

	// Imprime el árbol en forma de esquema tabulado, indicando si cada nodo es hijo izquiero o derecho de su padre
	// Complejidad temporal: O(n), siendo n el número de nodos del subárbol, tanto con la mejor topología como con la peor
	void imprimir();

	// Destruye el árbol, liberando la memoria de todos los nodos
	// Complejidad temporal: O(n), siendo n el número de nodos del subárbol, tanto con la mejor topología como con la peor
	//~ArbolBinarioDeBusqueda();

private:

	// Busca recursivamente un elemento en el arbol binario de busqueda
	// Parámetros:
	// - raizSubarbol indica el subarbol en donde buscar
	// - elementoABuscar es la clave del nodo que queremos encontrar
	// Retorno: puntero al nodo que contiene el elementoABuscar si lo encuentra, o, 
	//          si no lo encuentra, puntero al nodo padre de donde se podría insertar
	// Precondición: raizSubarbol != NULL
	// Complejidad temporal: O(lgn) con la mejor topología, O(n) con la peor
	Nodo* buscarRecursivo(Nodo* raizSubarbol, int elementoABuscar);

	// Imprime un subarbol por pantalla en forma de esquema, sangrando los hijos con una tabulación. Esta pensado para ser recursivo
	// Parámetros:
	// - subarbol: nodo raíz del subarbol que queremos imprimir
	// - numeroTabulaciones: numero de tabulaciones con la que imprimimos la raiz. Los hijos directos tendrán una tabulación más
	// - orientacion indica si subarbol (primer parametro) es un hijo izquierdo de su padre (-1) o es derecho (+1) o no tiene padre (0)
	// Precondiciones: 
	// - subarbol != NULL
	// - numeroTabulaciones>=0
	// - orientacion == 1 || orientacion == -1 || orientacion == 0
	// Complejidad temporal: O(n), tanto con la mejor topología (T(n)=1+2T(n/2)) como con la peor (T(n)=1+T(n-1))
	void imprimirRecursivo(Nodo* subarbol, int numeroTabulaciones, int orientacion);

	// Elimina recursivamente los nodos de un subarbol
	// Parámetro: el nodo raíz del subarbol a eliminar
	// Precondición: subarbol != NULL
	// Complejidad temporal: O(n), siendo n el número de nodos del subárbol, tanto con la mejor topología como con la peor
	void eliminarSubarbol(Nodo* raizSubarbol);

	// Elimina el nodo pasado como parametro. Lo sustituye por un descendiente suyo (recursivamente)
	// Parámetros:
	// - nodoParaEliminar: puntero al nodo que queremos eliminar
	// Complejidad temporal: O(lgn) con la mejor topología, O(n) con la peor
	// (n es el número de nodos del subarbol que empieza en nodoParaEliminar)
	void eliminarNodo(Nodo* nodoParaEliminar);

	// Buscar el maximo de un subarbol (ir por la rama derecha hasta no poder más)
	// Parámetro: raiz del subarbol en donde buscar
	// Retorno: puntero al nodo que contiene el máximo
	// Precondicion: raizSubarbol != NULL
	// Complejidad temporal: O(lgn) con la mejor topología, O(n) con la peor
	Nodo* buscarMaximo(Nodo* raizSubarbol);

	// Buscar el minimo de un subarbol (ir por la rama izquierda hasta no poder más)
	// Parámetro: raiz del subarbol en donde buscar
	// Retorno: puntero al nodo que contiene el minimo
	// Precondicion: raizSubarbol != NULL
	// Complejidad temporal: O(lgn) con la mejor topología, O(n) con la peor
	Nodo* buscarMinimo(Nodo* raizSubarbol);

};


ArbolBinarioDeBusqueda::ArbolBinarioDeBusqueda() {
	raiz = NULL;
	n = 0;
	orientacionSiguienteEliminacion = 1;

}

Nodo* ArbolBinarioDeBusqueda::buscarRecursivo(Nodo* raizSubarbol, int elementoABuscar){
	assert(n > 0);
	assert(raizSubarbol != NULL);

	if (raizSubarbol->contenido == elementoABuscar) {
		return raizSubarbol;
	}
	else {
		if (raizSubarbol->hijoIzquierdo != NULL && raizSubarbol->hijoDerecho != NULL) { //si tengo dos hijos
			if (elementoABuscar > raizSubarbol->contenido) {
				return buscarRecursivo(raizSubarbol->hijoDerecho, elementoABuscar);
			}
			else {
				return buscarRecursivo(raizSubarbol->hijoIzquierdo, elementoABuscar);
			}

		}
		else if (raizSubarbol->hijoIzquierdo != NULL && raizSubarbol->hijoDerecho == NULL) { //si tengo solo hijo izquierdo
			if (elementoABuscar > raizSubarbol->contenido) {
				return raizSubarbol;
			}
			else {
				return buscarRecursivo(raizSubarbol->hijoIzquierdo, elementoABuscar);
			}

		}
		else if (raizSubarbol->hijoIzquierdo == NULL && raizSubarbol->hijoDerecho != NULL) { //si tengo solo hijo derecho
			if (elementoABuscar > raizSubarbol->contenido) {
				return buscarRecursivo(raizSubarbol->hijoDerecho, elementoABuscar);
			}
			else {
				return raizSubarbol;
			}


		}
		else { //si no tengo hijos
			return raizSubarbol;
		}

	}
}


void ArbolBinarioDeBusqueda::insertar(int nuevoElemento) {

	Nodo* nuevoNodo = new Nodo;
	nuevoNodo->contenido = nuevoElemento;
	nuevoNodo->hijoDerecho = NULL;
	nuevoNodo->hijoIzquierdo = NULL;

	if (n == 0) {
		raiz = nuevoNodo;
		nuevoNodo->padre = NULL;
	}
	else {
		Nodo* nodoPadre = buscarRecursivo(raiz, nuevoElemento);

		if (nuevoElemento <= nodoPadre->contenido) {
			nodoPadre->hijoIzquierdo = nuevoNodo;
		}
		else {
			nodoPadre->hijoDerecho = nuevoNodo;
		}

		nuevoNodo->padre = nodoPadre;
	}

	n++;

}

bool ArbolBinarioDeBusqueda::buscar(int elementoABuscar) {

	Nodo* nodoBuscado = buscarRecursivo(raiz, elementoABuscar);

	if (nodoBuscado->contenido == elementoABuscar)
		return true;
	else
		return false;
}

void ArbolBinarioDeBusqueda::imprimirRecursivo(Nodo* raizSubarbol, int numeroTabulaciones, int orientacion) {
	assert(raizSubarbol != NULL);
	assert(numeroTabulaciones >= 0);
	assert(orientacion == 1 || orientacion == -1 || orientacion == 0);

	// Imprimimos el nodo raiz con el nivel pasado como parametro
	for (int i = 0; i < numeroTabulaciones; i++) cout << "\t";
	cout << raizSubarbol->contenido;
	if (orientacion == -1) cout << " (izquierdo)";
	if (orientacion == 1) cout << " (derecho)";
	cout << endl;

	// Imprimimos sus hijos con una tabulacion mas
	if (raizSubarbol->hijoIzquierdo != NULL) imprimirRecursivo(raizSubarbol->hijoIzquierdo, numeroTabulaciones + 1, -1);
	if (raizSubarbol->hijoDerecho != NULL) imprimirRecursivo(raizSubarbol->hijoDerecho, numeroTabulaciones + 1, 1);
}

void ArbolBinarioDeBusqueda::imprimir() {
	if (raiz != NULL) imprimirRecursivo(raiz, 0, 0);
	else cout << "Arbol vacio\n";
}


Nodo* ArbolBinarioDeBusqueda::buscarMaximo(Nodo* raizSubarbol) {
	assert(raizSubarbol != NULL);

	if (raizSubarbol->hijoDerecho == NULL) {
		return raizSubarbol;
	}
	else {
		buscarMaximo(raizSubarbol->hijoDerecho);
	}

}

Nodo* ArbolBinarioDeBusqueda::buscarMinimo(Nodo* raizSubarbol) {
	assert(raizSubarbol != NULL);

	if (raizSubarbol->hijoIzquierdo == NULL) {
		return raizSubarbol;
	}
	else {
		buscarMaximo(raizSubarbol->hijoDerecho);
	}

}

void ArbolBinarioDeBusqueda::eliminarSubarbol(Nodo* raizSubarbol) {
	assert (raizSubarbol != NULL);

	if (raizSubarbol->hijoDerecho == NULL && raizSubarbol->hijoIzquierdo == NULL) { //si no tengo hijos
		eliminarNodo (raizSubarbol);
	}
	else if (raizSubarbol->hijoDerecho != NULL && raizSubarbol->hijoIzquierdo != NULL) { //si tengo dos hijos 
		eliminarSubarbol(raizSubarbol->hijoIzquierdo);
		eliminarSubarbol(raizSubarbol->hijoDerecho);
	}
	else if (raizSubarbol->hijoDerecho == NULL && raizSubarbol->hijoIzquierdo != NULL) { //slo hijo izquierdo
		eliminarSubarbol(raizSubarbol->hijoIzquierdo);
	}
	else { //solo hijo derecho
		eliminarSubarbol(raizSubarbol->hijoDerecho);
	}
}

void ArbolBinarioDeBusqueda::eliminarNodo(Nodo* nodoParaEliminar) {
	assert(nodoParaEliminar != NULL);

	if (nodoParaEliminar->hijoDerecho == NULL && nodoParaEliminar->hijoIzquierdo == NULL) { //si no tengo hijos
		Nodo* padre = nodoParaEliminar->padre;
		
		if (padre->hijoDerecho == nodoParaEliminar) {
			padre->hijoDerecho = NULL;
			
		}
		else {
			padre->hijoIzquierdo = NULL;
		}

		delete (nodoParaEliminar);
	}
	else if (nodoParaEliminar->hijoDerecho != NULL && nodoParaEliminar->hijoIzquierdo != NULL) { //si tengo dos hijos 
		if (orientacionSiguienteEliminacion == 1) {
			Nodo* nodoMinimo = buscarMinimo(nodoParaEliminar->hijoDerecho);
			nodoParaEliminar->contenido = nodoMinimo->contenido;

			orientacionSiguienteEliminacion = -1;

			eliminarNodo(nodoMinimo);

			
		}
		else {
			Nodo* nodoMaximo = buscarMaximo(nodoParaEliminar->hijoIzquierdo);
			nodoParaEliminar->contenido = nodoMaximo->contenido;

			orientacionSiguienteEliminacion = 1;

			eliminarNodo(nodoMaximo);

			
		}
	}
	else if (nodoParaEliminar->hijoDerecho == NULL && nodoParaEliminar->hijoIzquierdo != NULL) { //solo hijo izquierdo
		Nodo* nodoMaximo = buscarMaximo(nodoParaEliminar->hijoIzquierdo);
		nodoParaEliminar->contenido = nodoMaximo->contenido;


		orientacionSiguienteEliminacion = 1;
		eliminarNodo(nodoMaximo);

		

	}
	else { //solo hijo derecho
		Nodo* nodoMinimo = buscarMinimo(nodoParaEliminar->hijoDerecho);
		nodoParaEliminar->contenido = nodoMinimo->contenido;

		orientacionSiguienteEliminacion = -1;
		eliminarNodo(nodoMinimo);

	}

	

}

void ArbolBinarioDeBusqueda::eliminar(int elementoAEliminar) {
	assert(buscar(elementoAEliminar));

	Nodo* nodoParaEliminar = buscarRecursivo(raiz, elementoAEliminar);

	eliminarNodo(nodoParaEliminar);

	n--;

}




int main()
{
	ArbolBinarioDeBusqueda ABB;

	ABB.imprimir();

	ABB.insertar(5);
	ABB.imprimir();

	ABB.insertar(1);
	ABB.imprimir();
	ABB.insertar(6);
	ABB.imprimir();
	ABB.insertar(3);
	ABB.imprimir();
	ABB.insertar(7);
	ABB.imprimir();
	ABB.insertar(2);
	ABB.imprimir();
	ABB.insertar(4);
	ABB.imprimir();

	cout << "Buscamos el 7: " << ABB.buscar(7) << endl;
	cout << "Buscamos el 3: " << ABB.buscar(3) << endl;
	cout << "Buscamos el 4: " << ABB.buscar(4) << endl;
	cout << "Buscamos el 100: " << ABB.buscar(100) << endl;

	ABB.eliminar(5);
	ABB.imprimir();
	ABB.eliminar(6);
	ABB.imprimir();
	ABB.eliminar(4);
	ABB.imprimir();
	ABB.eliminar(7);
	ABB.imprimir();


}

