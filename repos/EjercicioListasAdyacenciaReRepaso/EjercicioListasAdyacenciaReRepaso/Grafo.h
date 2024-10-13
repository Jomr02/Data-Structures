#pragma once
#include "ListaContigua.h"
#include "Aeropuerto.h"
#include "Ruta.h"

class Grafo
{
private: 

	ListaContigua aeropuertos;
	int n;

	bool existeAeropuerto(string nombreAeropuerto);
	ListaEnlazada* getRutasSalientes(string nombreAeropuertoOrigen);
	ListaEnlazada* getRutasEntrantes(string nombreAeropuertoDestino);
	bool existeRuta(string nombreAeropuertoOrigen, string nombreAeropuertoDestino);

public:

	Grafo();
	void imprimir();
	void insertarAeropuerto(string nombreAeropuerto);
	void insertarRuta(string nombreAeropuertoOrigen, string nombreAeropuertoDestino, int kms, string aerolinea);
	void eliminarRuta(string nombreAeropuertoOrigen, string nombreAeropuertoDestino);
	void eliminarAeropuerto(string nombreAeropuerto);



};

