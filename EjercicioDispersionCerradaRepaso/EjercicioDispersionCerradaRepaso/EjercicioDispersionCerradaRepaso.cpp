// EjercicioDispersionCerradaRepaso.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "DispersionCerrada.h"


int main()
{
    DispersionCerrada tabla (10);

    tabla.imprimir();
    tabla.meterEstudiante(0, "Sergio");
    tabla.meterEstudiante(1, "Pepe");
    tabla.meterEstudiante(2, "Ronaldinho");
    tabla.meterEstudiante(3, "Pele");
    tabla.meterEstudiante(4, "Vinicius");
    tabla.meterEstudiante(5, "Maradona");
    tabla.meterEstudiante(6, "CR7");
    tabla.meterEstudiante(7, "Benzema");
    tabla.meterEstudiante(17, "Zidane");
    tabla.meterEstudiante(27, "Koeman");
    tabla.imprimir();
    tabla.eliminarEstudiante(5);
    tabla.imprimir();
    tabla.meterEstudiante(57, "Zico");
    tabla.imprimir();
    

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
