// ColaVectorCircularRepaso.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "ColaCircular.h"


using namespace std;

int main()
{
    ColaCircular cola;

    cola.push('a'); cola.imprimir();
    cola.push('b'); cola.imprimir();
    cola.push('c'); cola.imprimir();
    cola.push('d'); cola.imprimir();
    cola.push('e'); cola.imprimir();
    cola.pop(); cola.imprimir();
    cola.pop(); cola.imprimir();
    cola.pop(); cola.imprimir();
    cola.pop(); cola.imprimir();
    cola.push('f'); cola.imprimir();
    cola.pop(); cola.imprimir();
    cola.push('g'); cola.imprimir();
    cola.push('h'); cola.imprimir();
    cola.push('i'); cola.imprimir();
    cola.pop(); cola.imprimir();
    cola.pop(); cola.imprimir();
    cola.pop(); cola.imprimir();
    cola.push('j'); cola.imprimir();
    cola.push('k'); cola.imprimir();
    cola.push('l'); cola.imprimir();
    cola.pop(); cola.imprimir();
    cola.pop(); cola.imprimir();
    cola.pop(); cola.imprimir();
    cola.pop(); cola.imprimir();

    // Volvemos a repetir todas las operaciones
    cola.push('a'); cola.imprimir();
    cola.push('b'); cola.imprimir();
    cola.push('c'); cola.imprimir();
    cola.push('d'); cola.imprimir();
    cola.push('e'); cola.imprimir();
    cola.pop(); cola.imprimir();
    cola.pop(); cola.imprimir();
    cola.pop(); cola.imprimir();
    cola.pop(); cola.imprimir();
    cola.push('f'); cola.imprimir();
    cola.pop(); cola.imprimir();
    cola.push('g'); cola.imprimir();
    cola.push('h'); cola.imprimir();
    cola.push('i'); cola.imprimir();
    cola.pop(); cola.imprimir();
    cola.pop(); cola.imprimir();
    cola.pop(); cola.imprimir();
    cola.push('j'); cola.imprimir();
    cola.push('k'); cola.imprimir();
    cola.push('l'); cola.imprimir();
    cola.pop(); cola.imprimir();
    cola.pop(); cola.imprimir();
    cola.pop(); cola.imprimir();
    cola.pop(); cola.imprimir();

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
