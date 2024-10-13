#pragma once
#include "Coche.h"

class HashCoches
{

private:

	Coche* tabla;

	int capacidad;
	int versiones;

	int obtenerPosicion(string matricula, int version);
	void modificaCapacidad(int nuevaCapacidad, int nuevasVersiones);
	int existeCoche(string matricula);


public:

	HashCoches(int capacidadInicial, int versionesIniciales);
	void insertar(Coche coche);
	Coche getElemento(string matricula);
	void imprimir();
	~HashCoches();
};

