#include "Grafo.h"
#include <cassert>
#include <iostream>
#include "impresionListasEnlazadas.h"


Grafo::Grafo() {
	n = 0;

}
bool Grafo::existeAeropuerto(string nombreAeropuerto) {

	return (listaAeropuertos.buscar(nombreAeropuerto) != -1);

}
ListaEnlazada* Grafo::getRutasSalientes(string nombreAeropuertoOrigen) {
	assert(existeAeropuerto (nombreAeropuertoOrigen));

	int posicionAeropuerto = listaAeropuertos.buscar(nombreAeropuertoOrigen);

	return (listaAeropuertos.getValor(posicionAeropuerto).rutasSalientes);

}
ListaEnlazada* Grafo::getRutasEntrantes(string nombreAeropuertoDestino) {
	assert(existeAeropuerto(nombreAeropuertoDestino));

	int posicionAeropuerto = listaAeropuertos.buscar(nombreAeropuertoDestino);

	return (listaAeropuertos.getValor(posicionAeropuerto).rutasEntrantes);

}
bool Grafo::existeRuta(string nombreAeropuertoOrigen, string nombreAeropuertoDestino) {
	assert(existeAeropuerto(nombreAeropuertoOrigen));
	assert(existeAeropuerto(nombreAeropuertoDestino));

	ListaEnlazada* rutasSalientesOrigen = getRutasSalientes(nombreAeropuertoOrigen);
	ListaEnlazada* rutasEntrantesDestino = getRutasEntrantes(nombreAeropuertoDestino);

	bool existeSaliente = rutasSalientesOrigen->buscar(nombreAeropuertoDestino) != -1;
	bool existeEntrante = rutasEntrantesDestino->buscar(nombreAeropuertoOrigen) != -1;

	return (existeSaliente && existeEntrante);

}
void Grafo::insertarAeropuerto(string nombreAeropuerto) {
	assert(!existeAeropuerto(nombreAeropuerto));

	Aeropuerto* nuevoAeropuerto = new Aeropuerto;
	nuevoAeropuerto->nombre = new string(nombreAeropuerto);
	nuevoAeropuerto->rutasSalientes = new ListaEnlazada;
	nuevoAeropuerto->rutasEntrantes = new ListaEnlazada;

	listaAeropuertos.insertarAlFinal(*nuevoAeropuerto);

	n++;

}
void Grafo::insertarRuta(string nombreAeropuertoOrigen, string nombreAeropuertoDestino, int kms, string empresa) {
	assert(existeAeropuerto(nombreAeropuertoOrigen));
	assert(existeAeropuerto(nombreAeropuertoDestino));
	assert(!existeRuta(nombreAeropuertoOrigen, nombreAeropuertoDestino));

	Ruta* nuevaRutaSaliente = new Ruta;
	nuevaRutaSaliente->aeropuerto = new string(nombreAeropuertoDestino);
	nuevaRutaSaliente->kilometros = kms;
	nuevaRutaSaliente->empresa = new string(empresa);

	Ruta* nuevaRutaEntrante = new Ruta;
	nuevaRutaEntrante->aeropuerto = new string(nombreAeropuertoOrigen);
	nuevaRutaEntrante->kilometros = kms;
	nuevaRutaEntrante->empresa = new string(empresa);

	ListaEnlazada* rutasSalientesOrigen = getRutasSalientes(nombreAeropuertoOrigen);
	ListaEnlazada* rutasEntrantesDestino = getRutasEntrantes(nombreAeropuertoDestino);

	rutasSalientesOrigen->insertar(0, *nuevaRutaSaliente);
	rutasEntrantesDestino->insertar(0, *nuevaRutaEntrante);


}
void Grafo::eliminarAeropuerto(string nombreAeropuerto) {
	assert(existeAeropuerto(nombreAeropuerto));


	ListaEnlazada* rutasSalientesOrigen = getRutasSalientes(nombreAeropuerto);
	int nRutasSalientes = rutasSalientesOrigen->getN();

	
	while (nRutasSalientes > 0) {
		eliminarRuta(nombreAeropuerto, *(rutasSalientesOrigen->getValor(0).aeropuerto));

		nRutasSalientes = rutasSalientesOrigen->getN();
	}

	ListaEnlazada* rutasEntrantesOrigen = getRutasEntrantes(nombreAeropuerto);
	int nRutasEntrantes = rutasEntrantesOrigen->getN();

	while (nRutasEntrantes > 0) {
		eliminarRuta(*(rutasEntrantesOrigen->getValor(0).aeropuerto), nombreAeropuerto);


		nRutasEntrantes = rutasEntrantesOrigen->getN();
	}


	listaAeropuertos.eliminar(listaAeropuertos.buscar(nombreAeropuerto));


	n--;

}
void Grafo::eliminarRuta(string nombreAeropuertoOrigen, string nombreAeropuertoDestino) {
	assert(existeRuta(nombreAeropuertoOrigen, nombreAeropuertoDestino));

	ListaEnlazada* rutasSalientesOrigen = getRutasSalientes(nombreAeropuertoOrigen);
	ListaEnlazada* rutasEntrantesDestino = getRutasEntrantes(nombreAeropuertoDestino);

	rutasSalientesOrigen->eliminar(rutasSalientesOrigen->buscar (nombreAeropuertoDestino));
	rutasEntrantesDestino->eliminar(rutasEntrantesDestino->buscar(nombreAeropuertoOrigen));

}
void Grafo::imprimir() {

	if (n == 0) {
		cout << "Espacio Aereo Vacio";
	}
	else {

		for (int i = 0; i < n; i++) {
			cout << *listaAeropuertos.getValor(i).nombre << endl;
			cout << "\tRutas Salientes" << endl;
			cout << "\t";
			imprimirListaEnlazada(listaAeropuertos.getValor(i).rutasSalientes);
			cout << "\tRutas Entrantes" << endl;
			cout << "\t";
			imprimirListaEnlazada(listaAeropuertos.getValor(i).rutasEntrantes);


		}


	}

	cout << "\n";

}
