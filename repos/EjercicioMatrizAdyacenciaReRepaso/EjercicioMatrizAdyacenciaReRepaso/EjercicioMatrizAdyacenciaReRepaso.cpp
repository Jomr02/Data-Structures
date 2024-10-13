// EjercicioMatrizAdyacenciaReRepaso.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Grafo.h"

int main()
{
    Grafo grafo;

    grafo.imprimir();
    grafo.insertarNodo('A');
    grafo.insertarNodo('B');
    grafo.insertarNodo('C');
    grafo.insertarNodo('D');
    grafo.insertarNodo('E');
    grafo.imprimir();

    grafo.insertarArco('A', 'A');
    grafo.insertarArco('A', 'C');
    grafo.insertarArco('A', 'E');
    grafo.insertarArco('B', 'B');
    grafo.insertarArco('B', 'D');
    grafo.insertarArco('C', 'A');
    grafo.insertarArco('C', 'C');
    grafo.insertarArco('C', 'E');
    grafo.insertarArco('D', 'B');
    grafo.insertarArco('D', 'D');
    grafo.insertarArco('E', 'A');
    grafo.insertarArco('E', 'C');
    grafo.insertarArco('E', 'E');
    grafo.imprimir();

    grafo.eliminarNodo('B');
    grafo.imprimir();

    grafo.eliminarNodo('A');
    grafo.imprimir();

    grafo.eliminarNodo('E');
    grafo.imprimir();

    grafo.insertarNodo('H');
    grafo.insertarNodo('G');
    grafo.insertarNodo('F');
    grafo.insertarNodo('E');
    grafo.imprimir();

    grafo.eliminarArco('C', 'C');
    grafo.eliminarArco('D', 'D');
    grafo.imprimir();

    grafo.insertarArco('C', 'D');
    grafo.insertarArco('D', 'C');
    grafo.insertarArco('D', 'G');
    grafo.insertarArco('G', 'D');
    grafo.insertarArco('G', 'H');
    grafo.insertarArco('C', 'E');
    grafo.insertarArco('E', 'C');
    grafo.insertarArco('C', 'F');
    grafo.insertarArco('F', 'C');
    grafo.insertarArco('F', 'G');
    grafo.insertarArco('G', 'F');
    grafo.imprimir();


}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
