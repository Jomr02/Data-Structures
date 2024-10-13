#pragma once
#include "ListaContigua.h"

class Grafo
{
private:
	ListaContigua listaAeropuertos;
	int n;

	bool existeAeropuerto(string nombreAeropuerto);
	ListaEnlazada* getRutasSalientes(string nombreAeropuertoOrigen);
	ListaEnlazada* getRutasEntrantes(string nombreAeropuertoDestino);
	bool existeRuta(string nombreAeropuertoOrigen, string nombreAeropuertoDestino);

public:

	Grafo();
	void insertarAeropuerto(string nombreAeropuerto);
	void insertarRuta(string nombreAeropuertoOrigen, string nombreAeropuertoDestino, int kms, string empresa);
	void eliminarAeropuerto(string nombreAeropuerto);
	void eliminarRuta(string nombreAeropuertoOrigen, string nombreAeropuertoDestino);
	void imprimir();



};

