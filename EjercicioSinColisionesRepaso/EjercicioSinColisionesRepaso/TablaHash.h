#pragma once
#include "cassert"
#include "Elemento.h"

class TablaHash
{
private:

	int capacidad;
	Elemento* tabla;

	int obtenerPosicion(int clave);

public:

	TablaHash(int capacidadInicial);
	bool existeEstudiante(int clave);
	string getEstudiante(int clave);
	void meterEstudiante(int clave, string nombre);
	void eliminarEstudiante(int clave);
	void imprimir();
	~TablaHash();



};

