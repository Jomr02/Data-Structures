#pragma once
#include "string"
#include "ListaEnlazada.h"

using namespace std;


struct Aeropuerto {
	string* nombre;
	ListaEnlazada* rutasEntrantes;
	ListaEnlazada* rutasSalientes;



};