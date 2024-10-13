#pragma once
#include "ListaContigua.h"

class Grafo
{
private:

	ListaContigua nodos;
	int n;

	bool existeAeropuerto(string nombre);
	ListaEnlazada* getDestinos(string nombreAeropuertoOrigen);
	ListaEnlazada* getOrigenes(string nombreAeropuertoDestino);
	bool existeRuta(string nombreAeropuertoOrigen, string nombreAeropuertoDestino);

public:

	Grafo();
	void imprimir();
	void insertarAeropuerto(string nombreAeropuerto);
	void insertarRuta(string nombreAeropuertoOrigen, string nombreAeropuertoDestino, int kms, string compania);
	void eliminarRuta(string nombreAeropuertoOrigen, string nombreAeropuertoDestino);
	void eliminarAeropuerto(string nombre);

};

