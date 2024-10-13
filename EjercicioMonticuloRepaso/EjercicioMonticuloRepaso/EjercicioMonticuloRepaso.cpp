// EjercicioMonticuloRepaso.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "Monticulo.h"
#include "ImprimeLista.h"
#include "HeapSort.h"

int main()
{
    Monticulo monticulo;

    monticulo.insertar(2);
    monticulo.imprimir();
    monticulo.insertar(3);
    monticulo.imprimir();
    monticulo.insertar(4);
    monticulo.imprimir();
    monticulo.insertar(7);
    monticulo.imprimir();
    monticulo.insertar(5);
    monticulo.imprimir();
    monticulo.insertar(6);
    monticulo.imprimir();
    monticulo.borrar();
    monticulo.imprimir();
    monticulo.borrar();
    monticulo.imprimir();


    ListaContigua listaParaOrdenar;
    listaParaOrdenar.insertarAlFinal(3);
    listaParaOrdenar.insertarAlFinal(65);
    listaParaOrdenar.insertarAlFinal(2);
    listaParaOrdenar.insertarAlFinal(69);
    listaParaOrdenar.insertarAlFinal(1);
    listaParaOrdenar.insertarAlFinal(4);

    imprimirLista(&listaParaOrdenar);

    heapSort(&listaParaOrdenar);

    imprimirLista(&listaParaOrdenar);
    
    

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln