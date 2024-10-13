// EjercicioRecursividad2.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include "cassert"
#include "stdlib.h"

using namespace std;

int euclides(int n1, int n2);
int potencia(int base, int exponente);
int suma(int n);
int fibonacci(int n);
int buscar(int* vector, int tamano, int elemento);
int multiplicacionRusa(int operando1, int operando2);

int main()
{
	int vector[10] = { 40, 44, 67, 89, 39, 50 ,2 ,99, 192, 91 };

	cout << euclides (150, 33) <<"\n";
	cout << potencia (2, 10) << "\n";
	cout << suma (10) << "\n";
	cout << fibonacci(10) << "\n";
	cout << buscar(vector, 10, 2) << "\n";
	cout << multiplicacionRusa (981, 1234) << "\n";


	
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

int potencia(int base, int exponente) {
	assert(exponente >= 0);
	assert(base > 0);

	if (exponente == 0) {
		return 1;
	}
	else {
		return base * potencia(base, exponente - 1);
	}
}

int suma(int n) {
	if (n == 1) {
		return 1;
	}
	else {
		return n + suma(n - 1);
	}


}

int fibonacci(int n) {
	assert(n >= 0);

	if (n == 1) {
		return 1;
	} else if (n == 0) {
		return 0;
	} else {
		return fibonacci(n - 1) + fibonacci(n - 2);
	}

}


int buscar(int* vector, int tamano, int elemento) {
	assert(vector != nullptr);
	assert(tamano >= 0);


	if (tamano == 0) {
		return false;
	}

	if (vector[tamano - 1] == elemento) {
		return true;
	}

	return buscar(vector, tamano - 1, elemento);


}


int multiplicacionRusa(int operando1, int operando2) {
	assert(operando1 > 0 && operando2 > 0);

	int nuevoOperando1 = operando1 / 2;
	int nuevoOperando2 = operando2 * 2;

	if (operando1 == 1) {
		return operando2;
	} 

	if (operando1 % 2 != 0) {
		return operando2 + multiplicacionRusa(nuevoOperando1, nuevoOperando2);
	}
	else {
		return multiplicacionRusa(nuevoOperando1, nuevoOperando2);

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
