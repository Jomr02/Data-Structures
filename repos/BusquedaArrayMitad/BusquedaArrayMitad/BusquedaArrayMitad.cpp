// BusquedaArrayMitad.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

using namespace std;


bool busqueda(int* array, int n, int elemento);

int main()
{
    int array[10] = { 1, 3, 5, 99, 6, 7, 10, 560, 40, 20};

    cout << busqueda (array, 10, 4);
}



bool busqueda(int* array, int n, int elemento) {
    if (n == 0) {
        return false;
    }

    if (array[n / 2] == elemento) {
        return true;
    }
    else {
        return (busqueda(array, n / 2, elemento)) || busqueda(array + (n / 2 + 1), n - 1 - n / 2, elemento);
    }

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
