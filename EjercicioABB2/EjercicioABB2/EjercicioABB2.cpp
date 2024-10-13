// EjercicioABB2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "ArbolBinarioDeBusqueda.h"

using namespace std;

int main()
{
    ArbolBinarioDeBusqueda arbol;
    arbol.insertar(5);
    arbol.insertar(1);
    arbol.insertar(6);
    arbol.insertar(3);
    arbol.insertar(7);
    arbol.insertar(2);
    arbol.insertar(4);
    arbol.imprimir();
    arbol.borrar(5);
    arbol.imprimir();
    arbol.borrar(6);
    arbol.imprimir();
    arbol.borrar(4);
    arbol.imprimir();
    arbol.borrar(7);
    arbol.imprimir();

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
