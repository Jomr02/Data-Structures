// ListasExamen.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <cassert>
using namespace std;

class ColaConVectorCircular {
    char* cola;
    int primero;
    int ultimo;
    int capacidad;
    int n;
    int incremento;

    void modificaCapacidad(int nuevaCapacidad);
    bool esCasillaVacia(int posicion);

public:
    ColaConVectorCircular(int incremento);
    void push(char nuevoElemento);
    bool esVacia();
    char pop();
    void imprimir();
    ~ColaConVectorCircular();

};

ColaConVectorCircular::ColaConVectorCircular(int incremento) {
    cola = NULL;
    primero = 0;
    ultimo = -1;
    capacidad = 0;
    n = 0;
    this->incremento = incremento;
}

void ColaConVectorCircular::modificaCapacidad(int nuevaCapacidad) {
    assert(nuevaCapacidad >= n);

    char* nuevaCola = (char*) malloc(sizeof(char) * nuevaCapacidad);


    int indiceAux = primero;

    for (int i = 0; i < n; i++) {
        nuevaCola[i] = cola[indiceAux];
        indiceAux = (indiceAux + 1) % capacidad;
    }

    free(cola);

    cola = nuevaCola;
    capacidad = nuevaCapacidad;
    primero = 0;
    ultimo = n - 1;

}

bool ColaConVectorCircular::esCasillaVacia(int posicion) {
    assert(posicion >= 0 && posicion < capacidad);

    if (primero <= ultimo) { //disposicion normal
        if (posicion >= primero && posicion <= ultimo) {
            return false;
        }
        else {
            return true;
        }
    }
    else { //disposicion inversa
        if (posicion > ultimo && posicion < primero) {
            return true;
        }
        else {
            return false;
        }
    }

}

void ColaConVectorCircular::push(char nuevoElemento) {

    if (n == capacidad) {
        modificaCapacidad(capacidad + incremento);
    }

    ultimo = (ultimo + 1) % capacidad;
    cola[ultimo] = nuevoElemento;
    n++;

}

bool ColaConVectorCircular::esVacia() {
    return (n == 0);

}

char ColaConVectorCircular::pop() {
    assert(!esVacia());

    char elementoSacado = cola[primero];

    primero = (primero + 1) % capacidad;
    n--;

    if (capacidad - n >= 2 * incremento) {
        modificaCapacidad(capacidad - incremento);
    }

    return elementoSacado;

}

void ColaConVectorCircular::imprimir() {

    if (capacidad == 0) {
        cout << "Cola Sin Capacidad" << endl;
    }
    else {
        for (int i = 0; i < capacidad; i++) {
            cout << "|";
          
            if (!esCasillaVacia(i)) {
                cout << cola[i];
            }
            else {
                cout << " ";
            }
            cout << "|";

        }

    }
    cout << endl;

}



ColaConVectorCircular::~ColaConVectorCircular() {
    free(cola);
}



int main()
{
    ColaConVectorCircular cola(2);
    cola.imprimir();
    // Hacemos unas cuantas operaciones para probarla
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
