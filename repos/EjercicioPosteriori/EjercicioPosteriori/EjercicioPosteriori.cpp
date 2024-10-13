// EjercicioPosteriori.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <cassert>
#include <stdlib.h>  
#include <cstdlib>
#include <ctime>

using namespace std;

void selectionSort(int* array, int n);
int calculaMinimoArray(int* array, int n, int posInicio, int posFinal);
void imprimirArray(int* array, int n);
int* generaArray(int tamano);
int compara(const void* a, const void* b);
int* copiarArray(int* array, int tamano);


int main()
{
    int tamano;
    clock_t inicio;
    double duracion;

    cout << "Introduce el tamano del array de numeros\n";
    cin >> tamano;

    int* arraySelection = generaArray(tamano);
    int* arrayQSort = copiarArray(arraySelection, tamano); //porque selectionSort MODIFICA el array pasado por funcion, y entonces qsort se encontraria el array ya ordenado 
    imprimirArray(arraySelection, tamano);


    inicio = clock();
    selectionSort(arraySelection, tamano);
    duracion = (clock() - inicio) / (double)(CLOCKS_PER_SEC/1000);
    imprimirArray(arraySelection, tamano);
    cout << "Tarda: " << duracion << " milisegundos\n";

    inicio = clock();
    qsort(arrayQSort, tamano, sizeof (int), compara);
    duracion = (clock() - inicio) / (double)(CLOCKS_PER_SEC / 1000);
    imprimirArray(arrayQSort, tamano);
    cout << "Tarda: " << duracion << " milisegundos\n";




}

int* copiarArray(int* array, int tamano) {
    int* arrayCopia = (int*)malloc(tamano * sizeof(int));

    for (int i = 0; i < tamano; i++) {
        arrayCopia[i] = array[i];
    }

    return arrayCopia;

}

void selectionSort(int *array, int n) {
    assert(n > 0);
    assert(array != nullptr);

    int posMinimo;

    for (int i = 0; i<n; i++) {
        posMinimo = calculaMinimoArray(array, n, i, n - 1);

        if (array[posMinimo] < array[i]) {
            int aux = array[posMinimo];
            array[posMinimo] = array[i];
            array[i] = aux;
        }

    }

}

int calculaMinimoArray(int* array, int n, int posInicio, int posFinal) {
    assert(n > 0);
    assert(posFinal >= posInicio);
    assert(array != nullptr);

    int posMinimo = posInicio;
    int valorMinimo = array[posInicio];

    for (int i = posInicio; i <= posFinal; i++) {
        if (array[i] < valorMinimo) {
            posMinimo = i;
            valorMinimo = array[i];
        }
    }

    return posMinimo;

}


void imprimirArray(int* array, int n) {
    if (n > 20) {
        cout << "Array demasiado grande para imprimir\n";
        return;
    }


    for (int i = 0; i < n; i++) {
        cout << " " << array[i] << " ";
    }

    cout << "\n";

}

int* generaArray(int tamano) {
    srand(time(NULL)); //genera semilla aleatoria a partir del reloj del ordenador


    int* array = (int*) malloc(tamano * sizeof(int));

    for (int i = 0; i < tamano; i++) {
        array[i] = rand() % tamano;

    }

    return array;

}

int compara(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
