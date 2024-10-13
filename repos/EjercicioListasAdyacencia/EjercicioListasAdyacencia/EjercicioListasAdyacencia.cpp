// EjercicioListasAdyacencia.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Grafo.h"

int main()
{
    Grafo grafo;

    grafo.imprimir();
    grafo.insertarAeropuerto("Barajas");
    grafo.insertarAeropuerto("Prat");
    grafo.insertarAeropuerto("Heathrow");
    grafo.insertarAeropuerto("JFK");
    grafo.insertarAeropuerto("Frankfurt");
    grafo.imprimir();
    grafo.insertarRuta("Barajas", "Prat", 300, "Vueling");
    grafo.insertarRuta("Prat", "Barajas", 350, "Iberia");
    grafo.insertarRuta("Barajas", "Heathrow", 900, "Iberia");
    grafo.insertarRuta("Barajas", "JFK", 3000, "Iberia");
    grafo.insertarRuta("JFK", "Heathrow", 2500, "Iberia");
    grafo.imprimir();
    grafo.eliminarAeropuerto("Frankfurt");
    grafo.imprimir();
    grafo.eliminarRuta("Prat", "Barajas");
    grafo.imprimir();
    grafo.eliminarAeropuerto("Barajas");
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
