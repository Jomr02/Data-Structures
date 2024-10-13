// ColaVectorCircular.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#include <iostream>
#include <cassert>
using namespace std;

class ColaVectorCircular {

    char* cola;
    int primero;
    int ultimo;
    int capacidad;
    int n; 
    int incremento;

    void modificaCapacidad(int nuevaCapacidad);
    bool esCasillaValida(int posicion);



public:
    ColaVectorCircular (int incremento);

    void push(char nuevoElemento);
    bool esVacia();
    char pop();
    void imprimir();

    ~ColaVectorCircular();



};

ColaVectorCircular::ColaVectorCircular(int incremento) {
    cola = NULL;
    primero = 0;
    ultimo = -1;
    capacidad = 0;
    n = 0;
    this->incremento = incremento;
}

void ColaVectorCircular::modificaCapacidad(int nuevaCapacidad) {
    assert(nuevaCapacidad >= n);

    char* nuevaCola = (char*)malloc(sizeof(char) * nuevaCapacidad);
    int nSalvada = n; //IMPORTANTE porque al hacer pop () modificamos n


    for (int i = 0; i < nSalvada; i++) {
       nuevaCola[i] = pop();
    }

    free(cola);

    cola = nuevaCola;

    primero = 0;
    ultimo = nSalvada - 1;
    n = nSalvada;
    capacidad = nuevaCapacidad;

}

bool ColaVectorCircular::esVacia() {
    return (n == 0);
}

void ColaVectorCircular::push(char nuevoElemento) {
   
    if (n == capacidad)
        modificaCapacidad(capacidad + incremento);

    ultimo = (ultimo + 1) % capacidad;
    cola[ultimo] = nuevoElemento;

    n++;
}

char ColaVectorCircular::pop() {
    assert(!esVacia());

    char resultado = cola[primero];

    primero = (primero + 1) % capacidad;

    n--;

    if (capacidad - n >= 2 * incremento)
        modificaCapacidad(capacidad - incremento);

    return resultado;

}


bool ColaVectorCircular::esCasillaValida(int posicion) {
    assert(posicion >= 0 && posicion < capacidad);

    bool resultado = true;

    if (primero <= ultimo) {
        if (posicion > ultimo || posicion < primero)
            resultado = false;
    }
    else {
        if (posicion < primero && posicion > ultimo)
            resultado = false;
    }

    return resultado;
}

void ColaVectorCircular::imprimir() {
    if (capacidad == 0) {
        cout << "Cola sin capacidad" << endl;
    }
    else {
        cout << "|";
        for (int i = 0; i < capacidad; i++) {
            if (!esCasillaValida(i)) {
                cout << " |";
            }
            else {
                cout << cola[i] << "|";
            }
        }
    }
    cout << endl;
    cout << n << endl;
    cout << capacidad << endl;
    cout << primero << endl;
    cout << ultimo << endl;
    cout << endl;

}


ColaVectorCircular::~ColaVectorCircular() {
    free(cola);
}





int main()
{
    // Creamos una cola con incremento 2 y la imprimimos
    ColaVectorCircular cola(2);
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


