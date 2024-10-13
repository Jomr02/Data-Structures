#include "Monticulo.h"
#include <cassert>
#include <iostream>
using namespace std;


bool Monticulo::esMonticulo(int posicionRaiz) {
	assert(posicionRaiz >= 0);
	assert(posicionRaiz < monticulo.getN());

	int posicionHijoIzquierdo = (2 * (posicionRaiz + 1)) - 1 ;
	int posicionHijoDerecho = posicionHijoIzquierdo + 1;

	int elemento = monticulo.getElemento(posicionRaiz);

	//si no tengo hijos
	if (posicionHijoIzquierdo > (monticulo.getN() - 1)) {
		return true;
	}
	else {
		//si tengo dos hijos
		if (posicionHijoDerecho < monticulo.getN()) {
			if (monticulo.getElemento(posicionHijoIzquierdo) > elemento && monticulo.getElemento(posicionHijoDerecho) > elemento)
				return (esMonticulo(posicionHijoIzquierdo) && esMonticulo(posicionHijoDerecho));
			else {
				return false;
			}
		}
		//si tengo un hijo, el izquierdo
		else {

			if (monticulo.getElemento(posicionHijoIzquierdo) > elemento) {
				return (esMonticulo(posicionHijoIzquierdo));
			}
			else {
				return false;
			}
			
		}
	}

}
void Monticulo::reestructurar(int posicionRaiz) {
	assert(posicionRaiz >= 0);
	assert(posicionRaiz < monticulo.getN());

	int posicionHijoIzquierdo = (2 * (posicionRaiz + 1)) - 1;
	int posicionHijoDerecho = posicionHijoIzquierdo + 1;

	
	while (!esMonticulo (0)) {
		//si tiene dos hijos
		if (posicionHijoDerecho < monticulo.getN()) {
			int posicionHijoMenor = posicionHijoIzquierdo;
			int claveHijoDerecho = monticulo.getElemento(posicionHijoDerecho);
			int claveHijoIzquierdo = monticulo.getElemento(posicionHijoIzquierdo);

			if (claveHijoDerecho < claveHijoIzquierdo) {
				posicionHijoMenor = posicionHijoDerecho;
			}

			int claveHijoMenor = monticulo.getElemento(posicionHijoMenor);

			monticulo.setElemento(posicionHijoMenor, monticulo.getElemento(posicionRaiz));
			monticulo.setElemento(posicionRaiz, claveHijoMenor);

			posicionRaiz = posicionHijoMenor;
		}
		//si tengo un hijo, el izquierdo
		else {
			int claveHijoIzquierdo = monticulo.getElemento(posicionHijoIzquierdo);

			monticulo.setElemento(posicionHijoIzquierdo, monticulo.getElemento(posicionRaiz));
			monticulo.setElemento(posicionRaiz, claveHijoIzquierdo);

			posicionRaiz = posicionHijoIzquierdo;

		}

		posicionHijoIzquierdo = (2 * (posicionRaiz + 1)) - 1;
		posicionHijoDerecho = posicionHijoIzquierdo + 1;
	}

}
void Monticulo::insertar(int elemento) {
	
	monticulo.insertarAlFinal(elemento);

	int posicionElemento = monticulo.getN() - 1;
	int posicionPadre = ((posicionElemento + 1) / 2) -1;

	while (posicionElemento > 0) {

		int claveElemento = monticulo.getElemento(posicionElemento);
		int clavePadre = monticulo.getElemento(posicionPadre);

		if (clavePadre > claveElemento) {
			monticulo.setElemento(posicionPadre, claveElemento);
			monticulo.setElemento(posicionElemento, clavePadre);
		}

		posicionElemento = posicionPadre;
		posicionPadre = ((posicionElemento + 1) / 2) - 1;
	}

	assert(esMonticulo(0));


}

void Monticulo::imprimirRecursivo(int posicionRaiz, int tabulaciones) {
	assert(posicionRaiz >= 0);
	assert(posicionRaiz < monticulo.getN());
	assert(tabulaciones >= 0);

	int posicionHijoIzquierdo = (2 * (posicionRaiz + 1)) - 1;
	int posicionHijoDerecho = posicionHijoIzquierdo + 1;

	for (int i = 0; i < tabulaciones; i++) {
		cout << "\t";
	}

	cout << getRaiz(posicionRaiz) << endl;


	//si tengo dos hijos
	if (posicionHijoDerecho < monticulo.getN()) {
		imprimirRecursivo(posicionHijoIzquierdo, tabulaciones + 1);
		imprimirRecursivo(posicionHijoDerecho, tabulaciones + 1);

	}
	//si tengo un hijo, el izquierdo
	else if (posicionHijoIzquierdo < monticulo.getN()){
		imprimirRecursivo(posicionHijoIzquierdo, tabulaciones + 1);
	}



}

void Monticulo::imprimir() {
	imprimirRecursivo(0, 0);

}
int Monticulo::borrar() {

	int raiz = getRaiz(0);
	int claveUltimoElemento = monticulo.getElemento(monticulo.getN() - 1);

	monticulo.setElemento(0, claveUltimoElemento);
	monticulo.eliminarAlFinal();

	if (monticulo.getN() > 0) {
		reestructurar(0);
		assert(esMonticulo(0));
	}
	
	return raiz;

}
int Monticulo::getRaiz(int posicionRaiz) {
	assert(posicionRaiz >= 0);
	assert(posicionRaiz < monticulo.getN());

	return (monticulo.getElemento(posicionRaiz));
}