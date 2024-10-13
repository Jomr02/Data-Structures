// ABB.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <cassert>

using namespace std;

struct Nodo {
    int contenido;
    Nodo* hijoDerecho;
    Nodo* hijoIzquierdo;
    Nodo* padre;
};


class ABB {
    Nodo* punteroRaizArbol;
    int n;
    int orientacionGuardada;

    Nodo* buscarRecursivo(Nodo* raiz, int elementoBuscado);
    Nodo* calcularMaximo(Nodo* raiz);
    Nodo* calcularMinimo(Nodo* raiz);
    void eliminarNodo(Nodo* nodoParaEliminar);
    void imprimirRecursivo(Nodo* raizSubarbol, int numeroTabulaciones, int orientacion);

public:
    ABB();
    void insertar(int elementoParaInsertar);
    void eliminar(int elementoParaEliminar);
    bool buscar(int elementoBuscado);
    void imprimir();
    ~ABB();

};

ABB::ABB() {
    punteroRaizArbol = NULL;
    n = 0;
    orientacionGuardada = 1;
}

Nodo* ABB::buscarRecursivo(Nodo* raiz, int elementoBuscado) {
    if (raiz->contenido == elementoBuscado) { //encontramos el elemento
        return raiz;
    }
    else if (raiz->hijoDerecho == NULL && raiz->hijoIzquierdo == NULL) { //devuelve donde se debe insertar
        return raiz;
    }
    else if (elementoBuscado > raiz->contenido && raiz->hijoDerecho == NULL) { //devuelve donde se debe insertar
        return raiz;
    }
    else if (elementoBuscado < raiz->contenido && raiz->hijoIzquierdo == NULL) { //devuelve donde se debe insertar 
        return raiz;
    }
    else if (elementoBuscado < raiz->contenido && raiz->hijoIzquierdo != NULL){ //seguimos buscando
        return buscarRecursivo(raiz->hijoIzquierdo, elementoBuscado);
    }
    else if (elementoBuscado > raiz->contenido && raiz->hijoDerecho != NULL) { //seguimos buscando
        return buscarRecursivo(raiz->hijoDerecho, elementoBuscado);
    }
}

void ABB::insertar(int elementoParaInsertar) {
    assert(!buscar(elementoParaInsertar));

    Nodo* nodoParaInsertar = new Nodo;
    nodoParaInsertar->contenido = elementoParaInsertar;
    nodoParaInsertar->padre = NULL;
    nodoParaInsertar->hijoDerecho = NULL;
    nodoParaInsertar->hijoIzquierdo = NULL;


    if (n > 0) {
        Nodo* nodoPadre = buscarRecursivo(punteroRaizArbol, elementoParaInsertar);

        if (elementoParaInsertar > nodoPadre->contenido) {
            nodoPadre->hijoDerecho = nodoParaInsertar;
            nodoParaInsertar->padre = nodoPadre;
        }
        else {
            nodoPadre->hijoIzquierdo = nodoParaInsertar;
            nodoParaInsertar->padre = nodoPadre;
        }

        n++;
    }
    else {
        punteroRaizArbol = nodoParaInsertar;
        n++;
    }

}


bool ABB::buscar(int elementoBuscado) {

    if (n != 0) {
        Nodo* encontrado = buscarRecursivo(punteroRaizArbol, elementoBuscado);

        if (encontrado->contenido == elementoBuscado) {
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

Nodo* ABB::calcularMaximo(Nodo* raiz) {
    assert(raiz != NULL);

    if (raiz->hijoDerecho == NULL)
        return raiz;
    else
        return calcularMaximo(raiz->hijoDerecho);

}

Nodo* ABB::calcularMinimo(Nodo* raiz) {
    assert(raiz != NULL);

    if (raiz->hijoIzquierdo == NULL)
        return raiz;
    else
        return calcularMinimo(raiz->hijoIzquierdo);

}

void ABB::eliminarNodo(Nodo* nodoParaEliminar) {
    assert(nodoParaEliminar != NULL);

    Nodo* nodoParaIntercambiar;

    if (nodoParaEliminar->hijoDerecho == NULL && nodoParaEliminar->hijoIzquierdo == NULL) { //si el nodo a eliminar tiene dos hijos (es una hoja)
        if (nodoParaEliminar->padre->hijoDerecho == nodoParaEliminar) { //borramos la referencia hacia nosotros en nuestro padre
            nodoParaEliminar->padre->hijoDerecho = NULL;
            delete (nodoParaEliminar);
        }
        else if (nodoParaEliminar->padre->hijoIzquierdo == nodoParaEliminar){
            nodoParaEliminar->padre->hijoIzquierdo = NULL;
            delete (nodoParaEliminar);
        }
    }
    else if (nodoParaEliminar->hijoDerecho != NULL && nodoParaEliminar->hijoIzquierdo != NULL){ //si el nodo a eliminar tiene dos hijos
        if (orientacionGuardada == 1) {
            nodoParaIntercambiar = calcularMinimo(nodoParaEliminar->hijoDerecho);
            nodoParaEliminar->contenido = nodoParaIntercambiar->contenido;
            eliminarNodo(nodoParaIntercambiar);
            orientacionGuardada = -1;
        }
        else {
            nodoParaIntercambiar = calcularMaximo(nodoParaEliminar->hijoIzquierdo);
            nodoParaEliminar->contenido = nodoParaIntercambiar->contenido;
            eliminarNodo(nodoParaIntercambiar);
            orientacionGuardada = 1;
        }
    }
    else if (nodoParaEliminar->hijoDerecho == NULL && nodoParaEliminar->hijoIzquierdo != NULL) { //si el nodo a eliminar tiene solo hijo izquierdo
        nodoParaIntercambiar = calcularMaximo(nodoParaEliminar->hijoIzquierdo);
        nodoParaEliminar->contenido = nodoParaIntercambiar->contenido;
        eliminarNodo(nodoParaIntercambiar);
        orientacionGuardada = 1;

    }
    else if (nodoParaEliminar->hijoDerecho != NULL && nodoParaEliminar->hijoIzquierdo == NULL){
        nodoParaIntercambiar = calcularMinimo(nodoParaEliminar->hijoDerecho);
        nodoParaEliminar->contenido = nodoParaIntercambiar->contenido;
        eliminarNodo(nodoParaIntercambiar);
        orientacionGuardada = -1;
    }

    n--;
}

void ABB::eliminar(int elementoParaEliminar) {
    assert(buscar(elementoParaEliminar));

    Nodo* nodoParaEliminar = buscarRecursivo(punteroRaizArbol, elementoParaEliminar);
    eliminarNodo(nodoParaEliminar);

}

void ABB::imprimirRecursivo(Nodo* raizSubarbol, int numeroTabulaciones, int orientacion) {
    assert(raizSubarbol != NULL);
    assert(numeroTabulaciones >= 0);
    assert(orientacion == 1 || orientacion == -1 || orientacion == 0);

    // Imprimimos el nodo raiz con el nivel pasado como parametro
    for (int i = 0; i < numeroTabulaciones; i++) cout << "\t";
    cout << raizSubarbol->contenido;
    if (orientacion == -1) cout << " (izquierdo)";
    if (orientacion == 1) cout << " (derecho)";
    cout << endl;

    // Imprimimos sus hijos con una tabulacion mas
    if (raizSubarbol->hijoIzquierdo != NULL) imprimirRecursivo(raizSubarbol->hijoIzquierdo, numeroTabulaciones + 1, -1);
    if (raizSubarbol->hijoDerecho != NULL) imprimirRecursivo(raizSubarbol->hijoDerecho, numeroTabulaciones + 1, 1);
}


void ABB::imprimir() {
    if (punteroRaizArbol != NULL) imprimirRecursivo(punteroRaizArbol, 0, 0);
    else cout << "Arbol vacio\n";
}

ABB::~ABB() {
    while (n > 0)
        eliminarNodo(punteroRaizArbol);
}


int main()
{
    ABB arbolBinarioBusqueda;

    arbolBinarioBusqueda.insertar(5);
    arbolBinarioBusqueda.imprimir();
    arbolBinarioBusqueda.insertar(1);
    arbolBinarioBusqueda.imprimir();
    arbolBinarioBusqueda.insertar(6);
    arbolBinarioBusqueda.imprimir();
    arbolBinarioBusqueda.insertar(3);
    arbolBinarioBusqueda.imprimir();
    arbolBinarioBusqueda.insertar(7);
    arbolBinarioBusqueda.imprimir();
    arbolBinarioBusqueda.insertar(2);
    arbolBinarioBusqueda.imprimir();
    arbolBinarioBusqueda.insertar(4);
    arbolBinarioBusqueda.imprimir();
    cout << "Busca el 2: " << arbolBinarioBusqueda.buscar(2) << endl;
    cout << "Busca el 20: " << arbolBinarioBusqueda.buscar(20) << endl;
    arbolBinarioBusqueda.eliminar(2);
    arbolBinarioBusqueda.imprimir();
    arbolBinarioBusqueda.eliminar(5);
    arbolBinarioBusqueda.imprimir();
    arbolBinarioBusqueda.eliminar(3);
    arbolBinarioBusqueda.imprimir();
    
}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
