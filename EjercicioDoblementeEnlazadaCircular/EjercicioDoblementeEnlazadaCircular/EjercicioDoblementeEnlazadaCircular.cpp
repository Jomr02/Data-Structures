// EjercicioDoblementeEnlazadaCircular.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "DobleEnlazadaCircular.h"
#include "ImpresionListaEnlazada.h"


using namespace std;

int main()
{
	DobleEnlazadaCircular lista;

	imprimirListaEnlazada(&lista);

	lista.insertar(0, 20);
	lista.eliminar(0);
	lista.insertar(0, 2);
	lista.insertar(1, 5);
	lista.insertar(1, 3);
	lista.eliminar(2);
	lista.insertar(2, 5);
	lista.eliminar(2);
	lista.insertar(0, 3);
	imprimirListaEnlazada(&lista);
	

	DobleEnlazadaCircular lista2;

	lista2.insertar(lista2.getN(), 20);
	lista2.insertar(lista2.getN(), 30);
	lista2.insertar(lista2.getN(), 50);

	imprimirListaEnlazada(&lista2);

	lista.concatenar(&lista2);
	imprimirListaEnlazada(&lista);

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
