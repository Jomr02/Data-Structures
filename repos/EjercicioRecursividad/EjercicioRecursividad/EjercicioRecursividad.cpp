// EjercicioRecursividad.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include<cassert>

using namespace std;


int euclides(int n1, int n2);
float potencia(float numero, int exponente);
int sumaNaturales(int n);
int fibonacci(int n);
bool buscarNumero(int* array, int tamano, int numeroBuscado);
int multiplicaRusa(int n1, int n2);
bool buscarNumeroMitad(int* array, int tamano, int numeroBuscado);


int main()
{
    
    int array[4] = {3, 10, 11, 2};

    cout << "MCD es " << euclides(450, 360) << "\n";
    cout << "La potencia es: " << potencia(2, 10) << "\n";
    cout << "La suma es: " << sumaNaturales (10) << "\n";
    cout << "El fibonacci es: " << fibonacci(20) << "\n"; 
    cout << "Numero encontrado: " << buscarNumero(array, 11, 4) << "\n";
    cout << "La multiplicacion es: " << multiplicaRusa(981, 1234) <<"\n";
    cout << "Numero encontrado: " << buscarNumeroMitad(array, 4, 2) << "\n";
    cout << "Numero segunda parte" << *(array + (5 / 2) + 1);
    
    

}


int euclides(int n1, int n2) {
    assert(n1 >= n2);
    assert(n1 >= 0);
    assert(n2 >= 0);


    if (n1 % n2 == 0) {
        return n2;
    }
    else {
        return euclides(n2, n1 % n2);
    }

}


float potencia(float numero, int exponente) {
    assert(numero >= 0);
    assert(exponente >= 0);

    if (exponente == 1) {
        return numero;

    }
    else {
        return numero * potencia(numero, exponente - 1);

    }
}


int sumaNaturales(int n) {
    assert(n > 0);


    if (n == 1) {
        return 1;
    }
    else {

        return n + sumaNaturales(n - 1);
    }

}



int fibonacci (int n) {
    assert(n >= 0);

    if (n == 0 ) {
        return 0;

    }
    else if (n == 1) {
        return 1;

    }
    else {
        return (fibonacci(n - 2) + fibonacci(n - 1));

    }




}

bool buscarNumero(int* array, int tamano, int numeroBuscado) {

    if (tamano == 0) {
        return false;
    }
    else {
        if (array[tamano - 1] == numeroBuscado) {
            return true;
        }
        else {
            buscarNumero(array, tamano - 1, numeroBuscado);
        }
        

    }

}

bool buscarNumeroMitad(int* array, int tamano, int numeroBuscado) {
    cout << "Soy el array " << array[0] << " con tamano " << tamano << "en mi segunda posicion esta el "<< array [1] << "\n";

    if (tamano <= 0) {
        return false;

    }

    if (array[tamano / 2] == numeroBuscado) {
        return true;
        
    }
    else {

        return buscarNumeroMitad(array, tamano / 2, numeroBuscado) || buscarNumeroMitad((array + (tamano / 2)+1), tamano / 2, numeroBuscado);


    }




}

int multiplicaRusa(int n1, int n2) {

    if (n1 == 1) {
        return n2;

    }
    else {
        int terceraColumna = 0;

        if (n1 % 2 != 0) {
            terceraColumna = n2;
        }
        return terceraColumna + (multiplicaRusa(n1 / 2, n2 * 2));
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
