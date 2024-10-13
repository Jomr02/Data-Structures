#include "Grafo.h"
#include <cassert>
#include <iostream>
#include "impresionListasEnlazadas.h"



Grafo::Grafo() {
	n = 0;

}

bool Grafo::existeAeropuerto(string nombre) {
	return (nodos.buscar(nombre) != -1);

}
ListaEnlazada* Grafo::getDestinos(string nombreAeropuertoOrigen){
	assert(existeAeropuerto(nombreAeropuertoOrigen));

	int posicionAeropuerto = nodos.buscar(nombreAeropuertoOrigen);
	return nodos.getValor(posicionAeropuerto).rutasSalientes;

}
ListaEnlazada* Grafo::getOrigenes(string nombreAeropuertoDestino) {
	assert(existeAeropuerto(nombreAeropuertoDestino));

	int posicionAeropuerto = nodos.buscar(nombreAeropuertoDestino);
	return nodos.getValor(posicionAeropuerto).rutasEntrantes;

}
bool Grafo::existeRuta(string nombreAeropuertoOrigen, string nombreAeropuertoDestino) {
	assert(existeAeropuerto(nombreAeropuertoOrigen));
	assert(existeAeropuerto(nombreAeropuertoDestino));

	ListaEnlazada* destinos = getDestinos(nombreAeropuertoOrigen);

	return (destinos->buscar(nombreAeropuertoDestino) != -1);

}
void Grafo::insertarAeropuerto(string nombreAeropuerto) {
	assert(!existeAeropuerto(nombreAeropuerto));

	Aeropuerto* aeropuertoParaInsertar = new Aeropuerto;
	aeropuertoParaInsertar->nombre = new string(nombreAeropuerto);
	aeropuertoParaInsertar->rutasEntrantes = new ListaEnlazada();
	aeropuertoParaInsertar->rutasSalientes = new ListaEnlazada();

	nodos.insertarAlFinal(*aeropuertoParaInsertar);
	n++;
}
void Grafo::insertarRuta(string nombreAeropuertoOrigen, string nombreAeropuertoDestino, int kms, string compania) {
	assert(existeAeropuerto(nombreAeropuertoOrigen));
	assert(existeAeropuerto(nombreAeropuertoDestino));
	assert(!existeRuta(nombreAeropuertoOrigen, nombreAeropuertoDestino));

	Ruta* ruta = new Ruta;
	ruta->aeropuerto = new string;
	(*ruta->aeropuerto) = nombreAeropuertoDestino;
	ruta->empresa = new string;
	(*ruta->empresa) = compania;
	ruta->kilometros = kms;

	Ruta* rutaDestino = new Ruta;
	rutaDestino->aeropuerto = new string;
	(*rutaDestino->aeropuerto) = nombreAeropuertoOrigen;
	rutaDestino->empresa = new string;
	(*rutaDestino->empresa) = compania;
	rutaDestino->kilometros = kms;

	int posicionAeropuertoOrigen = nodos.buscar(nombreAeropuertoOrigen);
	nodos.getValor(posicionAeropuertoOrigen).rutasSalientes->insertar(0, *ruta);

	int posicionAeropuertoDestino = nodos.buscar(nombreAeropuertoDestino);
	nodos.getValor(posicionAeropuertoDestino).rutasEntrantes->insertar(0, *rutaDestino);


}
void Grafo::eliminarRuta(string nombreAeropuertoOrigen, string nombreAeropuertoDestino){
	assert(existeAeropuerto(nombreAeropuertoOrigen));
	assert(existeAeropuerto(nombreAeropuertoDestino));
	assert(existeRuta(nombreAeropuertoOrigen, nombreAeropuertoDestino));

	int posicionAeropuerto = nodos.buscar(nombreAeropuertoOrigen);
	ListaEnlazada* rutasSalientes = getDestinos(nombreAeropuertoOrigen);
	int posicionRuta = rutasSalientes->buscar(nombreAeropuertoDestino);
	rutasSalientes->eliminar(posicionRuta);

}
void Grafo::eliminarAeropuerto(string nombre) {
	assert(existeAeropuerto(nombre));

	int posicionAeropuerto = nodos.buscar(nombre);
	nodos.eliminar(posicionAeropuerto);

	int nNodos = nodos.getN();

	for (int i = 0; i < nNodos; i++) {
		Aeropuerto aeropuerto = nodos.getValor(i);
		if (aeropuerto.rutasEntrantes->buscar(nombre) != -1) {
			int posicionAeropuerto = aeropuerto.rutasEntrantes->buscar(nombre);
			aeropuerto.rutasEntrantes->eliminar(posicionAeropuerto);

		}

		if (aeropuerto.rutasSalientes->buscar(nombre) != -1) {
			int posicionAeropuerto = aeropuerto.rutasSalientes->buscar(nombre);
			aeropuerto.rutasSalientes->eliminar(posicionAeropuerto);

		}

	}

	n--;

}
void Grafo::imprimir() {

	if (n == 0) {
		cout << "Grafo Vacio\n";

	}
	else {
		int nNodos = nodos.getN();

		for (int i = 0; i < nNodos; i++) {
			Aeropuerto aeropuerto = nodos.getValor(i);
			cout << *aeropuerto.nombre << endl;
			cout << "\t";
			imprimirListaEnlazada(aeropuerto.rutasEntrantes);
			cout << "\n\t";
			imprimirListaEnlazada(aeropuerto.rutasSalientes);

		}


	}


}