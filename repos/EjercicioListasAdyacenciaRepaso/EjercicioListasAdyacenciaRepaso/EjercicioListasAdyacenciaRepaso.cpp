// EjercicioListasAdyacenciaRepaso.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Grafo.h"

int main()
{
    Grafo espacioAereo;

    espacioAereo.imprimir();
    espacioAereo.insertarAeropuerto("Barajas");
    espacioAereo.insertarAeropuerto("Prat");
    espacioAereo.insertarAeropuerto("Heathdrow");
    espacioAereo.insertarAeropuerto("JFK");
    espacioAereo.insertarAeropuerto("Frankfurt");
    espacioAereo.imprimir();

    espacioAereo.insertarRuta("Barajas", "Prat", 300 , "Vueling");
    espacioAereo.insertarRuta("Prat", "Barajas", 350, "Iberia");
    espacioAereo.insertarRuta("Barajas", "Heathdrow", 900, "Iberia");
    espacioAereo.insertarRuta("Barajas", "JFK", 3000, "Iberia");
    espacioAereo.insertarRuta("JFK", "Heathdrow", 2500, "Iberia");
    espacioAereo.imprimir();

    espacioAereo.eliminarAeropuerto("Frankfurt");
    espacioAereo.imprimir();

    espacioAereo.eliminarRuta("Prat", "Barajas");
    espacioAereo.imprimir();

  

    espacioAereo.eliminarAeropuerto("Barajas");
    espacioAereo.imprimir();

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
