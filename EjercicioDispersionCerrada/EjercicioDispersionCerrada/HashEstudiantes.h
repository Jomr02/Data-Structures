#pragma once
#include <string>
#include <assert.h>
#include <iostream>

using namespace std;

class HashEstudiantes
{
private:

	int* claves;
	string* estudiantes;
	bool* ocupado;
	bool* borrado;

	int capacidad;
	int n;


	int getPosicion(int clave);

public:

	HashEstudiantes(int nuevaCapacidad);
	bool existeEstudiante(int clave);
	string getEstudiante(int clave);
	void introducirEstudiante(int clave, string nombre);
	void eliminarEstudiante(int clave);
	bool esLlena();
	void imprimir();
	~HashEstudiantes();

};

