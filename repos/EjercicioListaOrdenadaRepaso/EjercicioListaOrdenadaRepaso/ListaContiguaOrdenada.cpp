#include "ListaContiguaOrdenada.h"
#include "cassert"
#include "impresionListasContiguas.h"





ListaContiguaOrdenada::ListaContiguaOrdenada() {
	lista = new ListaContigua;

}

int ListaContiguaOrdenada::busquedaBinaria(int elemento, int inicioSubVector, int tamano) {

	int posicionMedia = inicioSubVector + (tamano / 2);


	if (tamano <= 0) {
		return posicionMedia;

	}

	int elementoPosMedia = lista->getValor(posicionMedia);

	if (elementoPosMedia == elemento) {
		return posicionMedia;
	}

	if (elemento < elementoPosMedia) {
		return busquedaBinaria(elemento, inicioSubVector, tamano / 2);
	}
	else {
		return busquedaBinaria(elemento, posicionMedia + 1, (tamano / 2) - 1);

	}



}
int ListaContiguaOrdenada::buscar(int elemento) {

	int posicionBusqueda = busquedaBinaria(elemento, 0, lista->getN());


	if (lista->getValor(posicionBusqueda) == elemento) {
		return posicionBusqueda;
	}
	else {
		return -1;

	}

	return 0;
}
void ListaContiguaOrdenada::eliminar(int elemento) {
	assert(lista->getN() > 0);
	assert(buscar(elemento) != -1);
	
	int posicion = buscar(elemento);

	lista->eliminar(posicion);


}

void ListaContiguaOrdenada::insertar(int elemento) {

	int posicion = busquedaBinaria(elemento, 0, lista->getN());

	lista->insertar(posicion, elemento);

}

void ListaContiguaOrdenada::imprimir() {
	imprimirListaContigua(lista);

}

ListaContiguaOrdenada::~ListaContiguaOrdenada() {
	delete lista;

}