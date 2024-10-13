// EjercicioAVLRepaso.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "AVL.h"
using namespace std;

int main()
{
    AVL arbol;

    cout << "Probamos la rotacion simple izquierda" << endl;

    arbol.insertar(1);
    arbol.imprimir();
    arbol.insertar(2);
    arbol.imprimir();
    arbol.insertar(3);
    arbol.imprimir();
    arbol.insertar(4);
    arbol.imprimir();
    arbol.insertar(5);
    arbol.imprimir();
    arbol.insertar(6);
    arbol.imprimir();

    
    cout << "Probamos la rotacion simple derecha" << endl;

    AVL arbol2;
    arbol2.insertar(6);
    arbol2.imprimir();
    arbol2.insertar(5);
    arbol2.imprimir();
    arbol2.insertar(4);
    arbol2.imprimir();
    arbol2.insertar(3);
    arbol2.imprimir();
    arbol2.insertar(2);
    arbol2.imprimir();
    arbol2.insertar(1);
    arbol2.imprimir();

    cout << "Probamos la rotacion simple derecha-izquierda" << endl;

    AVL arbol3;
    arbol3.insertar(2);
    arbol3.imprimir();
    arbol3.insertar(5);
    arbol3.imprimir();
    arbol3.insertar(3);
    arbol3.imprimir();
    arbol3.insertar(9);
    arbol3.imprimir();
    arbol3.insertar(8);
    arbol3.imprimir();
    arbol3.insertar(1);
    arbol3.imprimir();
    arbol3.insertar(10);
    arbol3.imprimir();
    arbol3.insertar(4);
    arbol3.imprimir();
    arbol3.insertar(6);
    arbol3.imprimir();
    arbol3.insertar(7);
    arbol3.imprimir();

    cout << "Probamos la rotacion simple izquierda-derecha" << endl;

    AVL arbol4;
    arbol4.insertar(9);
    arbol4.imprimir();
    arbol4.insertar(6);
    arbol4.imprimir();
    arbol4.insertar(8);
    arbol4.imprimir();
    arbol4.insertar(2);
    arbol4.imprimir();
    arbol4.insertar(3);
    arbol4.imprimir();
    arbol4.insertar(10);
    arbol4.imprimir();
    arbol4.insertar(5);
    arbol4.imprimir();
    arbol4.insertar(7);
    arbol4.imprimir();
    arbol4.insertar(1);
    arbol4.imprimir();
    arbol4.insertar(4);
    arbol4.imprimir();
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
