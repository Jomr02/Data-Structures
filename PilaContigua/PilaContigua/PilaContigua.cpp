// PilaContigua.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <cassert>


using namespace std;


class PilaContigua {
    int* pila;
    int cima;
    int n;
    int capacidad;
    int base;
    int incremento;

    void ampliaCapacidad(int nuevaCapacidad);

public:
    PilaContigua(int incremento);
    void push(int nuevoElemento);
    int pop();
    int verCima();
    bool esVacia();
    void imprimir();
    ~PilaContigua();

};

PilaContigua::PilaContigua(int incremento) {
    pila = NULL;
    cima = -1;
    n = 0;
    capacidad = 0;
    base = 0;
    this->incremento = incremento;
}

void PilaContigua::ampliaCapacidad(int nuevaCapacidad) {
    assert(nuevaCapacidad >= n);

    pila = (int*)realloc(pila, sizeof(int) * nuevaCapacidad);
    capacidad = nuevaCapacidad;
}

void PilaContigua::push(int nuevoElemento) {

    if (capacidad == n)
        ampliaCapacidad(capacidad + incremento);

    cima++;
    pila[cima] = nuevoElemento;
    n++;
}

int PilaContigua::pop() {
    assert(!esVacia());

    int resultado = pila[cima];
    cima--;

    n--;
    return (resultado);
}

int PilaContigua::verCima() {
    assert(!esVacia());

    return(pila[cima]);
}

bool PilaContigua::esVacia() {
    return (n == 0);
}

void PilaContigua::imprimir() {
    if (esVacia()) {
        cout << "Pila Vacia" << endl;
    }
    else {
        for (int i = 0; i <= cima; i++)
            cout << pila[i] << " ";

    }

    cout << endl;


}

PilaContigua::~PilaContigua(){
    free(pila);
}







int main()
{
    PilaContigua pila (2);

    pila.imprimir();
    pila.push(1);
    pila.imprimir();
    pila.push(2);
    pila.imprimir();
    pila.push(3);
    pila.imprimir();
    cout << pila.verCima()<< endl;
    pila.push(4);
    pila.imprimir();
    pila.pop();
    pila.imprimir();
    pila.pop();
    pila.pop();
    pila.imprimir();
    cout << pila.verCima() << endl;
    pila.pop();
    pila.imprimir();
}
