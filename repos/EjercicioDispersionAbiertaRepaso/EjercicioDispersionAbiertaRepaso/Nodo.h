#pragma once
#include "string"
#include "Estudiante.h"


using namespace std;

struct Nodo {

	Estudiante estudiante; // El elemento que guarda el nodo
	Nodo* anteriorNodo; // Puntero al nodo anterior de la lista enlazada
	Nodo* siguienteNodo; // Puntero al siguiente nodo de la lista enlazada

};