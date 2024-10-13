// ColaPrioridad.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Cola.h"
#include "ColaDePrioridad.h"


using namespace std;


int main()
{
    ColaDePrioridad colaPrioridad (10);
    colaPrioridad.push(0, 10100);
    colaPrioridad.push(1, 20);
    colaPrioridad.push(1, 40);
    colaPrioridad.push(1, 60);
    colaPrioridad.push(4, 10);
    colaPrioridad.push(6, 440);
    colaPrioridad.push(7, 6120);
    colaPrioridad.imprimir();
    colaPrioridad.pop();
    colaPrioridad.imprimir();



    



}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
