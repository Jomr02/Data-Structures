// AVL.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include<cassert>
#include "Nodo.h"

using namespace std;



class AVL {
    Nodo* punteroRaizArbol;
    int n;

    //Nodo* insertarHoja();
    Nodo* reequilibrar(Nodo* raiz);
    void cambiarHijo(Nodo* antiguoHijo, Nodo* nuevoHijo);
    Nodo* rotarDerecha(Nodo* raiz);
    Nodo* rotarIzquierda(Nodo* raiz);
    Nodo* rotarCompuestaDerechaIzquierda(Nodo* raiz);
    Nodo* rotarCompuestaIzquierdaDerecha(Nodo* raiz);
    Nodo* buscarRecursivo(Nodo* raiz, int elementoBuscado);
    void imprimirRecursivo(Nodo* raizSubarbol, int numeroTabulaciones, int orientacion);

public:
    AVL();
    void insertar(int nuevoElemento);
    void imprimir();

};

AVL::AVL() {
    punteroRaizArbol = NULL;
    n = 0;
}

Nodo* AVL::buscarRecursivo(Nodo* raiz, int elementoBuscado) {
    if (raiz->getContenido() == elementoBuscado) { //encontramos el elemento
        return raiz;
    }
    else if (raiz->getHijoDerecho() == NULL && raiz->getHijoIzquierdo() == NULL) { //devuelve donde se debe insertar
        return raiz;
    }
    else if (elementoBuscado > raiz->getContenido() && raiz->getHijoDerecho() == NULL) { //devuelve donde se debe insertar
        return raiz;
    }
    else if (elementoBuscado < raiz->getContenido() && raiz->getHijoIzquierdo() == NULL) { //devuelve donde se debe insertar 
        return raiz;
    }
    else if (elementoBuscado < raiz->getContenido() && raiz->getHijoIzquierdo() != NULL) { //seguimos buscando
        return buscarRecursivo(raiz->getHijoIzquierdo(), elementoBuscado);
    }
    else if (elementoBuscado > raiz->getContenido() && raiz->getHijoDerecho() != NULL) { //seguimos buscando
        return buscarRecursivo(raiz->getHijoDerecho(), elementoBuscado);
    }
}

void AVL::insertar(int elementoParaInsertar) {
    //assert(!buscar(elementoParaInsertar));

    Nodo* nodoParaInsertar = new Nodo (elementoParaInsertar);


    if (n > 0) {
        Nodo* nodoPadre = buscarRecursivo(punteroRaizArbol, elementoParaInsertar);

        if (elementoParaInsertar > nodoPadre->getContenido()) {
            nodoPadre->setHijoDerecho(nodoParaInsertar);
            nodoParaInsertar->setPadre(nodoPadre);
        }
        else {
            nodoPadre->setHijoIzquierdo(nodoParaInsertar);
            nodoParaInsertar->setPadre(nodoPadre);
        }
        n++;
    }
    else {
        punteroRaizArbol = nodoParaInsertar;
        n++;
    }

    Nodo* nodoSiguiente = nodoParaInsertar;
    nodoSiguiente->actualizarAltura();

    nodoSiguiente = nodoSiguiente->getPadre();

    while (nodoSiguiente != NULL) {
        nodoSiguiente->actualizarAltura();
        cout << "FE Nodo" << nodoSiguiente->getContenido() << " es " << nodoSiguiente->getFactorEquilibrio() << endl;

        if (nodoSiguiente->getFactorEquilibrio() == 2 || nodoSiguiente->getFactorEquilibrio() == -2) {
            nodoSiguiente = reequilibrar(nodoSiguiente);
        }

        nodoSiguiente = nodoSiguiente->getPadre();
    }



}

void AVL::imprimirRecursivo(Nodo* raizSubarbol, int numeroTabulaciones, int orientacion) {
    assert(raizSubarbol != NULL);
    assert(numeroTabulaciones >= 0);
    assert(orientacion == 1 || orientacion == -1 || orientacion == 0);

    // Imprimimos el nodo raiz con el nivel pasado como parametro
    for (int i = 0; i < numeroTabulaciones; i++) cout << "\t";
    cout << raizSubarbol->getContenido();
    if (orientacion == -1) cout << " (izquierdo)";
    if (orientacion == 1) cout << " (derecho)";
    cout << endl;

    // Imprimimos sus hijos con una tabulacion mas
    if (raizSubarbol->getHijoIzquierdo() != NULL) imprimirRecursivo(raizSubarbol->getHijoIzquierdo(), numeroTabulaciones + 1, -1);
    if (raizSubarbol->getHijoDerecho() != NULL) imprimirRecursivo(raizSubarbol->getHijoDerecho(), numeroTabulaciones + 1, 1);
}


void AVL::imprimir() {
    if (punteroRaizArbol != NULL) imprimirRecursivo(punteroRaizArbol, 0, 0);
    else cout << "Arbol vacio\n";
}

void AVL::cambiarHijo(Nodo* antiguoHijo, Nodo* nuevoHijo) {
    assert(antiguoHijo != NULL);

    Nodo* padre = antiguoHijo->getPadre();

    if (padre == NULL) {
        punteroRaizArbol = nuevoHijo;
        nuevoHijo->setPadre(NULL);
    }

    else {
        if (padre->getHijoIzquierdo() == antiguoHijo) padre->setHijoIzquierdo(nuevoHijo);
        if (padre->getHijoDerecho() == antiguoHijo) padre->setHijoDerecho(nuevoHijo);
    }

    antiguoHijo->setPadre(NULL);

}

Nodo* AVL::reequilibrar(Nodo* raiz) {
    Nodo* nuevaRaiz = NULL;

    if (raiz->getFactorEquilibrio() == 2 && raiz->getHijoDerecho()->getFactorEquilibrio() == 1) {
        nuevaRaiz = rotarIzquierda(raiz);
    }
    else if (raiz->getFactorEquilibrio() == -2 && raiz->getHijoIzquierdo()->getFactorEquilibrio() == -1) {
        nuevaRaiz = rotarDerecha(raiz);
    }
    else if (raiz->getFactorEquilibrio() == 2 && raiz->getHijoDerecho()->getFactorEquilibrio() == -1) {
        nuevaRaiz = rotarCompuestaDerechaIzquierda(raiz);
    }
    else if (raiz->getFactorEquilibrio() == -2 && raiz->getHijoIzquierdo()->getFactorEquilibrio() == 1) {
        nuevaRaiz = rotarCompuestaIzquierdaDerecha(raiz);
    }

    return nuevaRaiz;
}

Nodo* AVL::rotarDerecha(Nodo* raiz) {
    Nodo* y = raiz;
    Nodo* x = raiz->getHijoIzquierdo();
    Nodo* A = x->getHijoIzquierdo();
    Nodo* B = x->getHijoDerecho();
    Nodo* C = y->getHijoDerecho();

    
    cambiarHijo(y, x);

    y->setHijoIzquierdo(B);


    x->setHijoDerecho(y);


    y->actualizarAltura();
    x->actualizarAltura();

    return x;
}

Nodo* AVL::rotarIzquierda(Nodo* raiz) {
    Nodo* x = raiz;
    Nodo* y = raiz->getHijoDerecho();
    Nodo* A = x->getHijoIzquierdo();
    Nodo* B = y->getHijoIzquierdo();
    Nodo* C = y->getHijoDerecho();


    cambiarHijo(x, y);

    x->setHijoDerecho(B);

    y->setHijoIzquierdo(x);

    x->actualizarAltura();
    y->actualizarAltura();
    cout << "Termino rotar";
    

    return y;
}

Nodo* AVL::rotarCompuestaIzquierdaDerecha(Nodo* raiz) {
    Nodo* z = raiz;
    Nodo* x = z->getHijoIzquierdo();
    Nodo* y = x->getHijoDerecho();
    Nodo* A = raiz->getHijoIzquierdo();
    Nodo* B = y->getHijoIzquierdo();
    Nodo* C = y->getHijoDerecho();
    Nodo* D = z->getHijoDerecho();

    cambiarHijo(z, y);

    x->setHijoDerecho(B);


    z->setHijoIzquierdo(C);


    y->setHijoIzquierdo(x);

    y->setHijoDerecho(z);


    x->actualizarAltura();
    z->actualizarAltura();
    y->actualizarAltura();

    return y;

}

Nodo* AVL::rotarCompuestaDerechaIzquierda(Nodo* raiz) {
    Nodo* x = raiz;
    Nodo* z = raiz->getHijoDerecho();
    Nodo* y = z->getHijoIzquierdo();
    Nodo* A = raiz->getHijoIzquierdo();
    Nodo* B = y->getHijoIzquierdo();
    Nodo* C = y->getHijoDerecho();
    Nodo* D = z->getHijoDerecho();

    cambiarHijo(x, y);

    x->setHijoDerecho(B);


    z->setHijoIzquierdo(C);


    y->setHijoIzquierdo(x);

    y->setHijoDerecho(z);


    x->actualizarAltura();
    z->actualizarAltura();
    y->actualizarAltura();


    return y;

}

int main()
{
    AVL arbol; //probar simpleizquierda

    arbol.insertar(1);
    arbol.imprimir();
    arbol.insertar(2);
    arbol.imprimir();
    arbol.insertar(3);
    arbol.imprimir();
    arbol.insertar(4);
    arbol.imprimir();
    arbol.insertar(5);
    arbol.imprimir();
    arbol.insertar(6);
    arbol.imprimir();
    arbol.insertar(7);
    arbol.imprimir();
    /*
    AVL arbol2; //probar simplederecha

    arbol2.insertar(7);
    arbol2.imprimir();
    arbol2.insertar(6);
    arbol2.imprimir();
    arbol2.insertar(5);
    arbol2.imprimir();
    arbol2.insertar(4);
    arbol2.imprimir();
    arbol2.insertar(3);
    arbol2.imprimir();
    arbol2.insertar(2);
    arbol2.imprimir();
    arbol2.insertar(1);
    arbol2.imprimir(); */
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
