// ListaContigua2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "ListaContigua.h"
#include "ImprimeLista.h"

using namespace std;

int main()
{
    ListaContigua lista;


    imprimirLista(&lista);
    lista.insertarAlFinal(2);
    lista.insertarAlFinal(4);
    lista.insertarAlFinal(6);
    lista.insertarAlFinal(10);
    lista.insertar(0, 20);
    imprimirLista(&lista);
    lista.eliminarAlFinal();
    imprimirLista(&lista);
    lista.insertarAlFinal(10);
    imprimirLista(&lista);
    lista.eliminar(1);
    imprimirLista(&lista);
    cout << lista.buscar(10) << "\n";

    ListaContigua lista2;

    lista2.insertarAlFinal(40);
    lista2.insertarAlFinal(44);
    lista2.insertarAlFinal(28);
    lista2.insertarAlFinal(56);

    lista.concatenar(&lista2);
    imprimirLista(&lista2);
    imprimirLista(&lista);
    

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
