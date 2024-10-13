#include "Monticulo.h"
#include "cassert"
#include <iostream>

using namespace std;

void Monticulo::imprimir() {
	imprimirRecursivo(0, 0);
}

void Monticulo::imprimirRecursivo(int posicionRaiz, int tabulaciones) {
	assert(posicionRaiz >= 0);
	assert(posicionRaiz < arbol.getN());
	assert(tabulaciones >= 0);

	int posicionHijoIzquierdo = ((posicionRaiz + 1) * 2) - 1;
	int posicionHijoDerecho = ((posicionRaiz + 1) * 2);
	int nodosArbol = arbol.getN();

	for (int i = 0; i < tabulaciones; i++) {
		cout << "\t" ;
	}

	cout << arbol.getElemento(posicionRaiz) << "\n";

	// si el nodo tiene dos hijos los imprimimos
	if (posicionHijoIzquierdo < nodosArbol && posicionHijoDerecho < nodosArbol) {
		imprimirRecursivo(posicionHijoIzquierdo, tabulaciones + 1);
		imprimirRecursivo(posicionHijoDerecho, tabulaciones + 1);
	}

	// si solo tiene un hijo lo imprimimos
	else if (posicionHijoIzquierdo < nodosArbol) {
		imprimirRecursivo(posicionHijoIzquierdo, tabulaciones + 1);

	}

	


}

void Monticulo::insertar(int clave) {

	arbol.insertarAlFinal(clave);

	bool posicionCorrecta = false;
	int posicionNodo = arbol.getN() - 1;
	int claveNodo = clave;


	int posPadre = ((posicionNodo + 1) / 2) - 1;

	//si tengo padre compruebo si estoy en la posicion correcta

		while (!posicionCorrecta && posPadre >= 0) {
			
			
			if (arbol.getElemento(posPadre) > arbol.getElemento(posicionNodo)) {
				arbol.setElemento(posicionNodo, arbol.getElemento(posPadre));
				arbol.setElemento(posPadre, claveNodo);

				posicionNodo = posPadre;
				posPadre = ((posicionNodo + 1) / 2) - 1;
			}
			else {
				posicionCorrecta = true;
			}
		}
	


	assert(esMonticulo(0));
	
}


bool Monticulo::esMonticulo(int posicionRaiz) {
	assert(posicionRaiz >= 0 && posicionRaiz < arbol.getN());


	int posicionHijoIzquierdo = ((posicionRaiz + 1) * 2) - 1;
	int posicionHijoDerecho = ((posicionRaiz + 1) * 2);
	int nodosArbol = arbol.getN();



	// si el nodo raiz tiene dos hijos
	if (posicionHijoIzquierdo < nodosArbol && posicionHijoDerecho < nodosArbol) {
		int claveRaiz = arbol.getElemento(posicionRaiz);
		int claveHijoIzquierdo = arbol.getElemento(posicionHijoIzquierdo);
		int claveHijoDerecho = arbol.getElemento(posicionHijoDerecho);


		if (claveRaiz < claveHijoIzquierdo && claveRaiz < claveHijoDerecho)
			return esMonticulo(posicionHijoIzquierdo) || esMonticulo(posicionHijoDerecho);
		else
			return false;
	}
	//si el nodo raiz tiene solo hijo izquierdo
	else if (posicionHijoIzquierdo < nodosArbol) {
		int claveRaiz = arbol.getElemento(posicionRaiz);
		int claveHijoIzquierdo = arbol.getElemento(posicionHijoIzquierdo);

		if (claveRaiz < claveHijoIzquierdo)
			return esMonticulo(posicionHijoIzquierdo);
		else
			return false;

	}
	// si el nodo raiz no tiene hijos
	else {
		return true;
	}

}
