#include "Grafo.h"
#include "cassert"
#include "iostream"
#include "impresionListasEnlazadas.h"

Grafo::Grafo() {
	n = 0;

}

bool Grafo::existeAeropuerto(string nombreAeropuerto) {

	int posicionAeropuerto = aeropuertos.buscar(nombreAeropuerto);

	return (posicionAeropuerto != -1);

}
ListaEnlazada* Grafo::getRutasSalientes(string nombreAeropuertoOrigen) {
	assert(existeAeropuerto(nombreAeropuertoOrigen));


	int posicionAeropuerto = aeropuertos.buscar(nombreAeropuertoOrigen);

	return (aeropuertos.getValor(posicionAeropuerto).rutasSalientes);

}
ListaEnlazada* Grafo::getRutasEntrantes(string nombreAeropuertoDestino) {
	assert(existeAeropuerto(nombreAeropuertoDestino));


	int posicionAeropuerto = aeropuertos.buscar(nombreAeropuertoDestino);

	return (aeropuertos.getValor(posicionAeropuerto).rutasEntrantes);

}
bool Grafo::existeRuta(string nombreAeropuertoOrigen, string nombreAeropuertoDestino) {
	assert(existeAeropuerto(nombreAeropuertoOrigen));
	assert(existeAeropuerto(nombreAeropuertoDestino));

	int posicionRutaEnOrigen = getRutasSalientes(nombreAeropuertoOrigen)->buscar(nombreAeropuertoDestino);
	int posicionRutaEnDestino = getRutasEntrantes(nombreAeropuertoDestino)->buscar(nombreAeropuertoOrigen);

	return ((posicionRutaEnOrigen != -1) && (posicionRutaEnDestino != -1));

}


void Grafo::insertarAeropuerto(string nombreAeropuerto) {
	assert(!existeAeropuerto(nombreAeropuerto));
	
	Aeropuerto *nuevoAeropuerto = new Aeropuerto;
	nuevoAeropuerto->nombre = new string;
	*nuevoAeropuerto->nombre = nombreAeropuerto;
	nuevoAeropuerto->rutasEntrantes = new ListaEnlazada;
	nuevoAeropuerto->rutasSalientes = new ListaEnlazada;

	
	aeropuertos.insertarAlFinal(*nuevoAeropuerto);

	n++;

}
void Grafo::insertarRuta(string nombreAeropuertoOrigen, string nombreAeropuertoDestino, int kms, string aerolinea) {
	assert(!existeRuta(nombreAeropuertoOrigen, nombreAeropuertoDestino));

	Ruta *rutaSaleDeOrigen = new Ruta;
	rutaSaleDeOrigen->aeropuerto = new string(nombreAeropuertoDestino);
	rutaSaleDeOrigen->empresa = new string(aerolinea);
	rutaSaleDeOrigen->kilometros = kms;

	Ruta* rutaEntraEnDestino = new Ruta;
	rutaEntraEnDestino->aeropuerto = new string(nombreAeropuertoOrigen);
	rutaEntraEnDestino->empresa = new string(aerolinea);
	rutaEntraEnDestino->kilometros = kms;

	getRutasSalientes(nombreAeropuertoOrigen)->insertar(0, *rutaSaleDeOrigen);
	getRutasEntrantes(nombreAeropuertoDestino)->insertar(0, *rutaEntraEnDestino);


}
void Grafo::eliminarRuta(string nombreAeropuertoOrigen, string nombreAeropuertoDestino) {
	assert(existeRuta(nombreAeropuertoOrigen, nombreAeropuertoDestino));

	ListaEnlazada* rutasSalientes = getRutasSalientes(nombreAeropuertoOrigen);
	ListaEnlazada* rutasEntrantes = getRutasEntrantes(nombreAeropuertoDestino);

	rutasSalientes->eliminar(rutasSalientes->buscar(nombreAeropuertoDestino));
	rutasEntrantes->eliminar(rutasEntrantes->buscar(nombreAeropuertoOrigen));

}
void Grafo::eliminarAeropuerto(string nombreAeropuerto) {
	assert(existeAeropuerto(nombreAeropuerto));

	ListaEnlazada* rutasSalientes = getRutasSalientes(nombreAeropuerto);
	ListaEnlazada* rutasEntrantes = getRutasEntrantes(nombreAeropuerto);

	int nRutasSalientes = rutasSalientes->getN();
	int nRutasEntrantes = rutasEntrantes->getN();

	for (int i = 0; i < nRutasSalientes; i++) {
		eliminarRuta(nombreAeropuerto, *rutasSalientes->getValor(0).aeropuerto);

	}

	for (int j = 0; j < nRutasEntrantes; j++) {
		eliminarRuta(*rutasEntrantes->getValor(0).aeropuerto, nombreAeropuerto);

	}

	int posicionAeropuerto = aeropuertos.buscar(nombreAeropuerto);

	aeropuertos.eliminar(posicionAeropuerto);

	n--;

}

void Grafo::imprimir() {

	if (n == 0) {
		cout << "Grafo vacio";

	}
	else {
		for (int i = 0; i < n; i++) {
			cout << *aeropuertos.getValor(i).nombre << endl;
			cout << "\t";
			imprimirListaEnlazada(aeropuertos.getValor(i).rutasSalientes);
			cout << "\t";
			imprimirListaEnlazada(aeropuertos.getValor(i).rutasEntrantes);

		}
	}


	cout << endl;

}