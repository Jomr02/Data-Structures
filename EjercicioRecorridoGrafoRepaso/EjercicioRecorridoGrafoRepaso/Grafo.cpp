#include "Grafo.h"
#include "cassert"
#include <iostream>


Grafo::Grafo() {
	n = 0;
	matriz = nullptr;
	nodos = "";

}

bool Grafo::existeNodo(char nodo) {
	
	bool existe = false;

	for (int i = 0; i < n; i++) {
		char nodoAux = nodos.at(i);
		if (nodoAux == nodo) {
			existe = true;
			break;
		}

	}

	return existe;
}

int Grafo::posicionNodo(char nodo) {
	assert(existeNodo(nodo));

	int posicion = -1;

	for (int i = 0; i < n; i++) {
		char nodoAux = nodos.at(i);
		if (nodoAux == nodo) {
			posicion = i;
			break;
		}

	}

	return posicion;

}

bool Grafo::existeArco(char nodoOrigen, char nodoDestino) {
	assert(existeNodo(nodoOrigen));
	assert(existeNodo(nodoDestino));

	int posicionOrigen = posicionNodo(nodoOrigen);
	int posicionDestino = posicionNodo(nodoDestino);

	return (matriz[posicionOrigen].getValor(posicionDestino) != 0);

}
void Grafo::insertarNodo(char nodo) {


	for (int i = 0; i < n; i++) {
		matriz[i].insertarAlFinal(0);
	}

	n++;

	matriz = (ListaContigua*) realloc(matriz, n * sizeof(ListaContigua));

	ListaContigua *nuevaFila = new ListaContigua;

	for (int i = 0; i < n; i++) {
		nuevaFila->insertarAlFinal(0);
	}

	matriz[n-1] = *nuevaFila;

	nodos.append(1, nodo);

}

void Grafo::insertarArco(char nodoOrigen, char nodoDestino) {
	assert(!existeArco(nodoOrigen, nodoDestino));

	int posicionOrigen = posicionNodo(nodoOrigen);
	int posicionDestino = posicionNodo(nodoDestino);

	matriz[posicionOrigen].setValor(posicionDestino, 1);

}

void Grafo::eliminaNodo(char nodo) {
	assert(existeNodo(nodo));

	int posicionNodoParaBorrar = posicionNodo(nodo);

	for (int i = 0; i < n; i++) {
		matriz[i].eliminar(posicionNodoParaBorrar);

	}

	memmove(&matriz[posicionNodoParaBorrar], &matriz[posicionNodoParaBorrar + 1], (n - 1) *sizeof(ListaContigua));

	nodos.erase(nodos.begin() + posicionNodoParaBorrar);

	n--;

}

void Grafo::eliminaArco(char nodoOrigen, char nodoDestino) {
	assert(existeArco(nodoOrigen, nodoDestino));

	int posicionOrigen = posicionNodo(nodoOrigen);
	int posicionDestino = posicionNodo(nodoDestino);

	matriz[posicionOrigen].setValor(posicionDestino, 0);

}

void Grafo::imprimir() {

	if (n == 0) {
		cout << "Matriz Vacia";
	}
	else {

		cout << "  ";

		for (int i = 0; i < n; i++) {
			cout << nodos.at(i) << " ";
		}

		cout << "\n";

		for (int i = 0; i < n; i++) {
			cout << nodos.at(i) << " ";
			for (int j = 0; j < n; j++) {
				cout << matriz[i].getValor(j) << " ";
			}
			cout << "\n";
		}


	}

	cout << "\n";

}

char* Grafo::recorridoProfundidad(char nodo) {
	assert(existeNodo(nodo));

	bool* vistos = (bool*)malloc(n * sizeof(bool));

	int posicionNodoInicio = posicionNodo(nodo);

	for (int i = 0; i < n; i++) {
		vistos[i] = false;

	}

	string recorrido = recorridoProfundidadRecursivo(posicionNodoInicio, vistos);

	int longitudRecorrido = recorrido.size();

	char* recorridoChar = (char*)malloc((longitudRecorrido + 1) * sizeof(char));

	for (int i = 0; i < longitudRecorrido; i++) {
		recorridoChar[i] = recorrido.at(i);

	}

	recorridoChar[longitudRecorrido] = '\0';

	return recorridoChar;

}

string Grafo::recorridoProfundidadRecursivo(int posicionNodo, bool* vistos) {
	assert(posicionNodo >= 0 && posicionNodo < n);
	assert(vistos != nullptr);


	string recorrido = "";

	if (!vistos[posicionNodo]) {
		vistos[posicionNodo] = true;
		recorrido.append(1, nodos.at(posicionNodo));

		for (int i = 0; i < n; i++) {
			int existeNodoAdyacente = matriz[posicionNodo].getValor(i);
			if (!vistos[i] && existeNodoAdyacente != 0) {
				recorrido.append(recorridoProfundidadRecursivo (i, vistos));

			}
		}
	}


	return recorrido;

}

string Grafo::recorridoAnchura(char nodo) {
	assert(existeNodo(nodo));
	
	int* cola = (int*)malloc(n * sizeof(int)); //guarda las posiciones de los nodos
	bool* visitados = (bool*)malloc(n * sizeof(int)); // guarda las posiciones de los nodos ya visitados

	for (int i = 0; i < n; i++) {
		visitados[i] = false;
	}

	int posicionNodoActual = posicionNodo(nodo);
	cola[0] = posicionNodoActual;
	visitados[posicionNodoActual] = true;

	int inicioCola = 0;
	int finalCola = 0;
	int nCola = 1;

	string recorrido = "";
	

	while (nCola > 0) {

		
		recorrido.append(1, nodos[cola[inicioCola]]);
		inicioCola++;
		nCola--;

		for (int i = 0; i < n; i++) {
			if (matriz[posicionNodoActual].getValor(i) != 0 && !visitados [i]) {
				visitados[i] = true;
				finalCola++;
				cola[finalCola] = i;
				nCola++;
			}
		}

		posicionNodoActual = cola[inicioCola];

	}

	return recorrido;


}

int Grafo::calcularGradoEntradaNodo(int posicionNodo, bool* borrados) {
	assert(posicionNodo >= 0 && posicionNodo < n);
	assert(borrados != nullptr);

	int gradoEntrada = 0;

	for (int i = 0; i < n; i++) {
		if (matriz[i].getValor(posicionNodo) != 0 && !borrados[i]) {
			gradoEntrada++;

		}


	}


	return gradoEntrada;

}

string Grafo::recorridoTopologicoRecursivo(int posicionNodo, bool* borrados) {
	assert(posicionNodo >= 0 && posicionNodo < n);
	assert(borrados != nullptr);

	string recorrido = "";

	recorrido.append(1, nodos.at(posicionNodo));
	borrados[posicionNodo] = true;



	for (int i = 0; i < n; i++) {
		

		if (calcularGradoEntradaNodo(i, borrados) == 0 && !borrados[i]) {
			recorrido.append(recorridoTopologicoRecursivo(i, borrados));

		}

	}

	return recorrido;

}


string Grafo::recorridoTopologico() {

	bool* borrados = (bool*)malloc(n * sizeof(bool));

	for (int i = 0; i < n; i++) {
		borrados[i] = false;

	}

	int posicionNodo = 0;
	bool alMenosUnNodoGradoEntradaCero = false;
	string recorrido = "";

	for (int i = 0; i < n; i++) {
		if (calcularGradoEntradaNodo(i, borrados) == 0) {
			alMenosUnNodoGradoEntradaCero = true;
			posicionNodo = i;
			break;
		}

	}

	if (alMenosUnNodoGradoEntradaCero)
		recorrido = recorridoTopologicoRecursivo(posicionNodo, borrados);
	


	return recorrido;



}

Grafo::~Grafo() {
	delete (matriz);

}