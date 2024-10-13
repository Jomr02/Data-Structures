// EjercicioDobleCircular.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <cassert>

using namespace std;

struct Nodo {
	int elemento;
	Nodo* anterior;
	Nodo* siguiente;
};


class DobleCircular {
	Nodo* punteroPrimerNodo;
	int n;
	int posicionUltimoNodoAccedido;
	Nodo* ultimoNodoAccedido;

	Nodo* getNodo(int posicion);

public:
	DobleCircular();

	int getValor(int posicion);
	void setValor(int posicion, int nuevoValor);
	int getN();
	void insertar(int posicion, int nuevoValor);
	void eliminar(int posicion);
	void concatenar(DobleCircular* listaAConcatenar);
	int buscar(int elementoABuscar);
	void imprimir();


	~DobleCircular();



};

DobleCircular::DobleCircular() {
	punteroPrimerNodo = NULL;
	n = 0;
	posicionUltimoNodoAccedido = -1;
	ultimoNodoAccedido = NULL;
}

Nodo* DobleCircular::getNodo(int posicion) {
	assert(n > 0);
	assert(posicion >= 0 && posicion < n);

	Nodo* nodoSeleccionado = NULL;

	if (posicion == 0) {
		nodoSeleccionado = punteroPrimerNodo;
	}
	else if (posicion == posicionUltimoNodoAccedido) {
		nodoSeleccionado = ultimoNodoAccedido;
	}
	else if (posicion == posicionUltimoNodoAccedido + 1) {
		nodoSeleccionado = ultimoNodoAccedido->siguiente;
	}
	else if (posicion == posicionUltimoNodoAccedido - 1) {
		nodoSeleccionado = ultimoNodoAccedido->anterior;
	}
	else if (posicion == n - 1) {
		nodoSeleccionado = punteroPrimerNodo->anterior;
	}

	if (nodoSeleccionado == NULL) {
		if (posicion <= n / 2) {
			nodoSeleccionado = punteroPrimerNodo;
			for (int i = 0; i < posicion; i++) {
				nodoSeleccionado = nodoSeleccionado->siguiente;
			}
		}
		else {
			nodoSeleccionado = punteroPrimerNodo->anterior;
			for (int i = n - 1; i > posicion; i--) {
				nodoSeleccionado = nodoSeleccionado->anterior;
			}
		}

	}

	ultimoNodoAccedido = nodoSeleccionado;
	posicionUltimoNodoAccedido = posicion;


	return nodoSeleccionado;

}


int DobleCircular::getValor(int posicion) {
	assert(n > 0);
	assert(posicion >= 0 && posicion < n);

	Nodo* buscado = getNodo(posicion);

	return buscado->elemento;
}

void DobleCircular::setValor(int posicion, int nuevoValor) {
	assert(n > 0);
	assert(posicion >= 0 && posicion < n);

	Nodo* buscado = getNodo(posicion);

	buscado->elemento = nuevoValor;

}

int DobleCircular::getN() {
	return n;

}

void DobleCircular::insertar(int posicion, int nuevoValor) {
	assert(posicion >= 0 && posicion <= n);

	Nodo* nodoParaInsertar = new Nodo;
	nodoParaInsertar->elemento = nuevoValor;

	if (n == 0) {
		punteroPrimerNodo = nodoParaInsertar;
		nodoParaInsertar->anterior = nodoParaInsertar;
		nodoParaInsertar->siguiente = nodoParaInsertar;
	}
	else {
		if (posicion == 0) {
			Nodo* ultimoNodo = getNodo(n - 1);
			Nodo* primerNodo = punteroPrimerNodo;

			ultimoNodo->siguiente = nodoParaInsertar;
			nodoParaInsertar->anterior = ultimoNodo;
			primerNodo->anterior = nodoParaInsertar;
			nodoParaInsertar->siguiente = primerNodo;

			punteroPrimerNodo = nodoParaInsertar;
		} 
		else if (posicion == n) {
			Nodo* ultimoNodo = getNodo(n - 1);
			Nodo* primerNodo = punteroPrimerNodo;

			ultimoNodo->siguiente = nodoParaInsertar;
			nodoParaInsertar->anterior = ultimoNodo;
			nodoParaInsertar->siguiente = punteroPrimerNodo;
			punteroPrimerNodo->anterior = nodoParaInsertar;

		}
		else {
			Nodo* anteriorNodo = getNodo(posicion - 1);
			Nodo* siguienteNodo = getNodo(posicion);

			anteriorNodo->siguiente = nodoParaInsertar;
			nodoParaInsertar->anterior = anteriorNodo;
			siguienteNodo->anterior = nodoParaInsertar;
			nodoParaInsertar->siguiente = siguienteNodo;
		}

	}


	n++;
}

void DobleCircular::eliminar(int posicion) {
	assert(posicion >= 0 && posicion <= n);
	assert(n > 0);

	Nodo* nodoParaBorrar = getNodo(posicion);

	if (n == 1) {
		punteroPrimerNodo = NULL;
	}
	else if (posicion == 0) {
		Nodo* ultimoNodo = punteroPrimerNodo->anterior;
		Nodo* siguienteNodo = nodoParaBorrar->siguiente;

		ultimoNodo->siguiente = siguienteNodo;
		siguienteNodo->anterior = ultimoNodo;

		punteroPrimerNodo = siguienteNodo;

	}
	else if (posicion == n - 1) {
		Nodo* anteriorNodo = nodoParaBorrar->anterior;
		Nodo* primerNodo = punteroPrimerNodo;

		anteriorNodo->siguiente = primerNodo;
		primerNodo->anterior = anteriorNodo;

	}
	else {
		Nodo* anteriorNodo = nodoParaBorrar->anterior;
		Nodo* siguienteNodo = nodoParaBorrar->siguiente;

		anteriorNodo->siguiente = siguienteNodo;
		siguienteNodo->anterior = anteriorNodo;

	}




	delete (nodoParaBorrar);
	n--;

}

int DobleCircular::buscar(int elementoABuscar) {

	int posicion = -1;

	for (int i = 0; i < n; i++) {
		if (getNodo(i)->elemento == elementoABuscar) {
			posicion = i;
		}
	}


	return posicion;

}

void DobleCircular::imprimir() {
	cout << "n=" << getN() << "|ListaEnlazada=";

	// Si la lista está vacía, imprimimos algo especial
	if (getN() == 0) cout << "vacia";

	// Si no está vacía, imprimimos los elementos separados por comas, siempre que no sea demasiado grande
	// Si es demasiado grande, imprimimos un mensaje especial
	else {
		if (getN() > 20) cout << "demasiadosElementosParaMostrar";
		else {
			for (int i = 0; i < getN(); i++) {
				cout << getValor(i);
				if (i < getN() - 1) cout << ","; // Imprimimos "," si no estamos al final
			}
		}
	}
	cout << endl;
}

void DobleCircular::concatenar(DobleCircular* listaAConcatenar) {
	assert(listaAConcatenar != NULL);

	for (int i = 0; i < listaAConcatenar->getN(); i++) {
		insertar(n, listaAConcatenar->getValor(i));
	}

}

DobleCircular::~DobleCircular() {
	while (n > 0)
		eliminar(0);

}




int main()
{
	DobleCircular lista;
	cout << "Nueva ListaEnlazada creada:\n";
	lista.imprimir();

	cout << "Inserto 10 con la lista vacia:\n";
	lista.insertar(0, 10);
	lista.imprimir();

	for (int i = 20; i <= 21; i++) {
		int n = lista.getN(); // Obtenemos el numero de elementos de la lista
		lista.insertar(n, i); // Insertamos al final
		lista.imprimir();
	}

	cout << "Inserto 30 al principio:\n";
	lista.insertar(0, 30);
	lista.imprimir();

	cout << "Inserto 40 en la posicion 2:\n";
	lista.insertar(2, 40);
	lista.imprimir();

	cout << "Elimino el primer elemento:\n";
	lista.eliminar(0);
	lista.imprimir();

	cout << "Elimino el ultimo elemento:\n";
	int n = lista.getN(); // Numero actual de elementos de la lista
	lista.eliminar(n - 1);
	lista.imprimir();

	cout << "Elimino el elemento del medio:\n";
	lista.eliminar(1);
	lista.imprimir();


	cout << "Nueva lista2:\n";
	DobleCircular lista2;
	for (int i = 0; i <= 5; i++) lista2.insertar(i, i + 500);
	lista2.imprimir();

	// Concatenamos la lista2 con la primera lista, e imprimimos esta ultima
	cout << "Concatenamos la nueva lista a la vieja:\n";
	lista.concatenar(&lista2);
	lista.imprimir();




}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
