#include "Pila.h"


void Pila::push(int elemento) {

	lista.insertar(0, elemento);

}
int Pila::pop() {

	int valor = lista.getValor(0);

	lista.eliminar(0);

	return valor;

}
int Pila::verCima() {

	return lista.getValor(0);;

}
bool Pila::isVacia() {
	return (lista.getN() == 0);

}
ListaEnlazadaSimple* Pila::getLista() {
	return &lista;

}