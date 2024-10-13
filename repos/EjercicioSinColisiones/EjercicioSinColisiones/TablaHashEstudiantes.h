#pragma once
#include "Estudiante.h"


class TablaHashEstudiantes
{
private:

	int capacidad;
	Estudiante *lista;

	int obtenerPosicion(int clave);


public:
	TablaHashEstudiantes(int capacidadInicial);

	bool existeEstudiante(int clave);
	string getNombre(int clave);
	void introducirEstudiante(int matricula, string nombre);
	void eliminaEstudiante(int matricula);
	void imprimeLista();

	~TablaHashEstudiantes();

};

