// ConjuntoCochesRepaso.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "HashCoches.h"

int main()
{
    int capacidad; // Capacidad de la tabla hash
    int versiones; // Numero de versiones de la función hash
    int opcion; // Opcion de menu introducida por teclado
    cout << "Introduce la capacidad de la tabla: ";
    cin >> capacidad;
    cout << "Introduce el numero de versiones de la funcion hash: ";
    cin >> versiones;
    HashCoches coches(capacidad, versiones);
    do {
        // Imprimimos el menu y pedimos la opcion
        cout << "0. Salir\n";
        cout << "1. Imprimir conjunto de coches\n";
        cout << "2. Obtener modelo de un coche\n";
        cout << "3. Meter un nuevo coche\n";
        cout << "Introduzca opcion: ";
        cin >> opcion;
        string clave; // Clave para algunas opciones
        string valor; // Modelo de coche para la opcion de meter
        Coche coche; // Para la opcion de meter
        switch (opcion) {
        case 0: break;
        case 1:
            coches.imprimir();
            break;
        case 2:
            // Obtener un modelo de coche
            cout << "Introduzca la matricula del coche: ";
            cin >> clave;
            cout << "Su modelo es: " << coches.getElemento(clave).modelo << endl;
            break;
        case 3:
            // Meter un nuevo coche
            cout << "Introduzca la matricula del coche: ";
            cin >> clave;
            cout << "Introduzca el modelo de coche: ";
            cin >> valor;
            coche.matricula = clave;
            coche.modelo = valor;
            coches.insertar(coche);
            break;
        default:
            cout << "Opcion incorrecta\n"; break;
        } // Fin switch
    } while (opcion != 0);
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
