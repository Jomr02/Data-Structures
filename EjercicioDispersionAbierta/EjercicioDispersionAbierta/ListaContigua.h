#pragma once
#include "Estudiante.h"


class ListaContigua
{

private:

	Estudiante* lista;
	int n;
	int capacidad;

public:

	ListaContigua();
	void introducirEstudiante(int clave, string nombre);
	void eliminarEstudiante(int clave, string nombre);
	bool existeEstudiante(int clave, string nombre);
	Estudiante* getEstudiantePorPosicion(int posicion);
	int getPosicionEstudiante(int clave, string nombre);
	int getN();
	void imprimir();
	~ListaContigua();

};

