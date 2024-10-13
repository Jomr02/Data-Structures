#pragma once
#include <string>

using namespace std;

struct Nodo {
	string nombre;
	Nodo* punteroPadre;
	Nodo* punteroPrimerHijo;
	Nodo* punteroHermanoDerecho;

};