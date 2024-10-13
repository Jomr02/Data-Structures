#pragma once
#include "ListaEnlazada.h"

class HashAbierta
{

private:

	ListaEnlazada* tabla;
	int capacidad;

	int obtenerPosicion(int clave);


public:

	HashAbierta(int capacidadInicial);
	bool existeEstudiante(int clave);
	Estudiante getEstudiante(int clave);
	void meterEstudiante(int clave, string nombre);
	void eliminarEstudiante(int clave);
	bool esLlena();
	void imprimir();
	~HashAbierta();



};

