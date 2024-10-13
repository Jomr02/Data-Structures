#pragma once
#include "ListaContigua.h"
class HashAbierta
{
private:

	ListaContigua* hash;
	int capacidad;
	

	int obtenerPosicion(int clave);

public:

	HashAbierta(int capacidadInicial);
	bool existeEstudiante(int clave, string nombre);
	void introducirEstudiante(int clave, string nombre);
	void eliminarEstudiante(int clave, string nombre);
	void imprimir();
	~HashAbierta();


};

