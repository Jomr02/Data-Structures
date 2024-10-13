// EjercicioMatrizAdyacencia.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Grafo.h"

int main()
{
	Grafo matriz;
	matriz.insertarNodo('A');
	matriz.imprimir();
	matriz.insertarNodo('B');
	matriz.imprimir();
	matriz.insertarNodo('C');
	matriz.imprimir();
	matriz.insertarNodo('D');
	matriz.imprimir();
	matriz.insertarNodo('E');
	matriz.imprimir();
	matriz.insertarArco('A', 'A');
	matriz.insertarArco('A', 'C');
	matriz.insertarArco('A', 'E');
	matriz.insertarArco('B', 'B');
	matriz.insertarArco('B', 'D');
	matriz.insertarArco('C', 'A');
	matriz.insertarArco('C', 'C');
	matriz.insertarArco('C', 'E');
	matriz.insertarArco('D', 'B');
	matriz.insertarArco('D', 'D');
	matriz.insertarArco('E', 'A');
	matriz.insertarArco('E', 'C');
	matriz.insertarArco('E', 'E');
	matriz.imprimir();

	matriz.eliminaNodo('B');
	matriz.imprimir();
	matriz.eliminaNodo('A');
	matriz.imprimir();
	matriz.eliminaNodo('E');
	matriz.imprimir();

	matriz.insertarNodo('H');
	matriz.imprimir();
	matriz.insertarNodo('G');
	matriz.imprimir();
	matriz.insertarNodo('F');
	matriz.imprimir();
	matriz.insertarNodo('E');
	matriz.imprimir();

	matriz.eliminaArco('C', 'C');
	matriz.eliminaArco('D', 'D');
	matriz.imprimir();

	matriz.insertarArco('C', 'D');
	matriz.insertarArco('D', 'C');
	matriz.insertarArco('D', 'G');
	matriz.insertarArco('G', 'D');
	matriz.insertarArco('G', 'H');
	matriz.insertarArco('C', 'E');
	matriz.insertarArco('E', 'C');
	matriz.insertarArco('C', 'F');
	matriz.insertarArco('F', 'C');
	matriz.insertarArco('F', 'G');
	matriz.insertarArco('G', 'F');
	matriz.imprimir();


}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
