#include "Monticulo.h"
#include "cassert"
#include <iostream>

using namespace std;

void Monticulo::imprimirRecursivo(int posicion, int tabulaciones) {
	assert(posicion >= 0);
	assert(posicion < monticulo.getN());

	int posicionHijoDerecho = ((posicion + 1) * 2 + 1) - 1;
	int posicionHijoIzquierdo = ((posicion + 1) * 2) - 1;


	for (int i = 0; i < tabulaciones; i++) {
			cout << "\t";
	}

	cout << monticulo.getElemento(posicion) << "\n";
	
	//si tiene dos hijos
	if (posicionHijoDerecho < monticulo.getN()) {
		imprimirRecursivo(posicionHijoIzquierdo, tabulaciones + 1);
		imprimirRecursivo(posicionHijoDerecho, tabulaciones + 1);

	}
	//si tiene un hijo (el izquierdo)
	else if (posicionHijoIzquierdo < monticulo.getN()){
		imprimirRecursivo(posicionHijoIzquierdo, tabulaciones + 1);

	}


}
bool Monticulo::esMonticulo(int posicion) {
	assert(posicion >= 0);
	assert(posicion < monticulo.getN());


	int posicionHijoDerecho = ((posicion + 1) * 2 + 1) - 1;
	int posicionHijoIzquierdo = ((posicion + 1) * 2) - 1;

	//si no tiene hijos
	if (posicionHijoIzquierdo >= monticulo.getN()) {
		return true;
	} 
	//si tiene dos hijos
	else if (posicionHijoDerecho < monticulo.getN()) {

		if (monticulo.getElemento(posicion) > monticulo.getElemento(posicionHijoDerecho) || monticulo.getElemento(posicion) > monticulo.getElemento(posicionHijoIzquierdo)) {
			return false;
		}
		else {
			return esMonticulo(posicionHijoIzquierdo) && esMonticulo(posicionHijoDerecho);
		}

	} 
	//si tiene un hijo (el izquierdo)
	else {
		if (monticulo.getElemento(posicion) > monticulo.getElemento(posicionHijoIzquierdo)) {
			return false;
		}
		else {
			return esMonticulo(posicionHijoIzquierdo);

		}


	}


}
void Monticulo::reestructurar() {
	assert(!monticulo.esVacia());

	int posicion = 0;
	

	int contador = 0;
	while (!esMonticulo(0) ) {

		int posicionHijoIzquierdo = ((posicion + 1) * 2) - 1;
		int posicionHijoDerecho = (((posicion + 1) * 2) + 1) - 1;

		//si tengo dos hijos
		if (posicionHijoDerecho < monticulo.getN()) {

			//si el hijo izquierdo es menor que el el derecho lo intercambiamos con la raiz
			if (monticulo.getElemento(posicionHijoIzquierdo) < monticulo.getElemento(posicionHijoDerecho)) {
				intercambiar(posicion, posicionHijoIzquierdo);
				posicion = posicionHijoIzquierdo;

			}
			else {
				intercambiar(posicion, posicionHijoDerecho);
				posicion = posicionHijoDerecho;
			}

		} 
		//si solo tengo un hijo
		else if (posicionHijoIzquierdo < monticulo.getN()){
			intercambiar(posicion, posicionHijoIzquierdo);
			posicion = posicionHijoIzquierdo;
		}

		
	}




}


void Monticulo::insertar(int elemento) {


	monticulo.insertarAlFinal(elemento);

	bool colocado = false;
	int posicionElemento = monticulo.getN() - 1;
	int posicionPadre;

	while (!colocado && posicionElemento != 0) {
		posicionPadre = ((posicionElemento + 1) /2) - 1;

		if (monticulo.getElemento(posicionPadre) < monticulo.getElemento(posicionElemento)) {
			colocado = true;

		}
		else {
			int auxPadre = monticulo.getElemento(posicionPadre);

			monticulo.setElemento(posicionPadre, monticulo.getElemento(posicionElemento));
			monticulo.setElemento(posicionElemento, auxPadre);

			posicionElemento = posicionPadre;

		}


	}


	assert(esMonticulo(0));

}
int Monticulo::borrar() {

	int elemento = monticulo.getElemento(0);
	monticulo.setElemento(0 ,monticulo.getElemento(monticulo.getN() - 1));
	monticulo.eliminarAlFinal();

	if (!monticulo.esVacia()) {
		reestructurar();
		assert(esMonticulo(0));
	}

	

	return elemento;

}
int Monticulo::getRaiz() {
	assert(monticulo.getN() > 0);

	return monticulo.getElemento(0);

}

void Monticulo::intercambiar(int posicion1, int posicion2) {
	assert(posicion1 >= 0);
	assert(posicion1 < monticulo.getN());
	assert(posicion2 >= 0);
	assert(posicion2 < monticulo.getN());

	int pos1Aux = monticulo.getElemento(posicion1);

	monticulo.setElemento(posicion1, monticulo.getElemento(posicion2));
	monticulo.setElemento(posicion2, pos1Aux);



}
void Monticulo::imprimir() {
	imprimirRecursivo(0, 0);

}