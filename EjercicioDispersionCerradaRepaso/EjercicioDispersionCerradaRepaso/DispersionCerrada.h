#pragma once
#include "DispersionCerrada.h"
#include "cassert"
#include "Elemento.h"


using namespace std;


class DispersionCerrada
{
private:

	Elemento* tabla;
	int capacidad;
	int n;

	int obtenerPosicion(int clave);

public:

	DispersionCerrada(int capacidadInicial);
	bool existeEstudiante(int clave);
	string getEstudiante(int clave);
	void meterEstudiante(int clave, string nombre);
	void eliminarEstudiante(int clave);
	bool esLlena();
	void imprimir();
	~DispersionCerrada();
};

