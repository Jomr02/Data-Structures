// ArbolGenealogico.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <string>
#include <cassert>

using namespace std;

struct Nodo {
    string nombre;
    Nodo* padre;
    Nodo* hijoIzquierdo;
    Nodo* hermanoDerecho;
};



class ArbolGenealogico {
    Nodo* punteroPrimerNodo;
    int n;

    int numeroHijosDirectos(Nodo* nodoPadre);
    Nodo* getHijo(Nodo* nodoPadre, int posicion);
    Nodo* buscarRecursivo(Nodo* raiz, string nombreBuscado);
    void imprimirRecursivo(Nodo* raiz, int numeroTabulaciones);
    void eliminarSubarbolRecursivo(Nodo* raiz);
    

public:

    ArbolGenealogico(string nombreAntepasadoMasLejano);
    void insertar(string nombreNuevo, string nombrePadre);
    void imprimir();
    void eliminarSubarbol(string nodoRaiz);
    ~ArbolGenealogico();

};

int ArbolGenealogico::numeroHijosDirectos(Nodo* nodoPadre) {
    assert(nodoPadre != NULL);

    int nHijos;

    if (nodoPadre->hijoIzquierdo == NULL) {
        nHijos = 0;
    }
    else {
        nHijos = 0;
        Nodo* siguiente = nodoPadre->hijoIzquierdo;
        while (siguiente != NULL) {
            siguiente = siguiente->hermanoDerecho;
            nHijos++;
        }

    }

    return nHijos;
}

Nodo* ArbolGenealogico::getHijo(Nodo* nodoPadre, int posicion) {
    assert(nodoPadre != NULL);
    assert(numeroHijosDirectos(nodoPadre) > 0);
    assert(posicion >= 0 && posicion < numeroHijosDirectos(nodoPadre));

    Nodo* resultado = nodoPadre->hijoIzquierdo;

    for (int i = 0; i < posicion; i++) {
        resultado = resultado->hermanoDerecho;
    }

    return resultado;

}


Nodo* ArbolGenealogico::buscarRecursivo(Nodo* raiz, string nombreBuscado) {
    assert(raiz != NULL);



    if (raiz->nombre == nombreBuscado) {
        return raiz;
    }
    else {
        for (int i = 0; i < numeroHijosDirectos(raiz); i++) {
            Nodo* resultado;
            resultado = buscarRecursivo(getHijo(raiz, i), nombreBuscado);

            if (resultado != NULL)
                return resultado;
        }
    }

    return NULL;
}


void ArbolGenealogico::eliminarSubarbolRecursivo(Nodo* raiz) {
    assert(raiz != NULL);

    if (numeroHijosDirectos(raiz) == 0) {
        if (raiz->padre->hijoIzquierdo == raiz) {
            raiz->padre->hijoIzquierdo = NULL; 
            delete (raiz);
        }
        else {
            Nodo* hermanoIzquierdo = raiz->padre->hijoIzquierdo;
            for (int i = 0; i < numeroHijosDirectos(raiz->padre); i++) {
                if (getHijo(raiz->padre, i)->hermanoDerecho == raiz)
                    hermanoIzquierdo = getHijo(raiz->padre, i);
            }

            hermanoIzquierdo->hermanoDerecho = NULL;

            delete (raiz);
        }
    }
    else {
        for (int i = numeroHijosDirectos(raiz) - 1; i >= 0; i--) {
            eliminarSubarbolRecursivo (getHijo(raiz, i));
        }
    }

}

ArbolGenealogico::ArbolGenealogico(string nombreAntepasadoMasLejano) {
    Nodo* nodoParaInsertar = new Nodo;
    nodoParaInsertar->nombre = nombreAntepasadoMasLejano;
    nodoParaInsertar->hermanoDerecho = NULL;
    nodoParaInsertar->hijoIzquierdo = NULL;
    nodoParaInsertar->padre = NULL;

    punteroPrimerNodo = nodoParaInsertar;

    n = 1;
}


void ArbolGenealogico::insertar(string nombreNuevo, string nombrePadre) {

    Nodo *nodoParaInsertar = new Nodo;
    nodoParaInsertar->nombre = nombreNuevo;
    nodoParaInsertar->hermanoDerecho = NULL;
    nodoParaInsertar->hijoIzquierdo = NULL;
    nodoParaInsertar->padre = NULL;

    Nodo* padre = buscarRecursivo(punteroPrimerNodo, nombrePadre);

    if (numeroHijosDirectos(padre) == 0) {
        padre->hijoIzquierdo = nodoParaInsertar;
        nodoParaInsertar->padre = padre;
    }
    else {
        int numeroHijos = numeroHijosDirectos(padre);
        getHijo(padre, numeroHijos - 1)->hermanoDerecho = nodoParaInsertar;
        nodoParaInsertar->padre = padre;
    }

}



void ArbolGenealogico::imprimirRecursivo(Nodo* raizSubarbol, int numeroTabulaciones) {
    assert(raizSubarbol != NULL);
    assert(numeroTabulaciones >= 0);

    // Imprimimos el nodo raiz con el nivel pasado como parametro
    for (int i = 0; i < numeroTabulaciones; i++) cout << "\t";
    cout << raizSubarbol->nombre << endl;

    // Imprimimos cada uno de sus subárboles con una tabulacion mas
    int numeroSubarboles = numeroHijosDirectos(raizSubarbol); // Número de hijos de la raizSubarbol
    for (int i = 0; i < numeroSubarboles; i++) imprimirRecursivo(getHijo(raizSubarbol, i), numeroTabulaciones + 1);
}

void ArbolGenealogico::imprimir() {
    assert(n > 0);
    imprimirRecursivo(punteroPrimerNodo, 0);
}

void ArbolGenealogico::eliminarSubarbol(string nodoRaiz) {

    Nodo* nodoRaizSubarbol = buscarRecursivo(punteroPrimerNodo, nodoRaiz);
    eliminarSubarbolRecursivo(nodoRaizSubarbol);

}



ArbolGenealogico::~ArbolGenealogico() {
    eliminarSubarbolRecursivo(punteroPrimerNodo);
}



int main() {

    // Pedimos nuestro antepasado más lejano y creamos el árbol con él
    string antepasadoMasLejano; // Contendra la raiz del arbol
    cout << "Introduce tu antepasado mas lejano: ";
    cin >> antepasadoMasLejano;
    ArbolGenealogico arbol(antepasadoMasLejano); // Arbol que manejamos en el programa

    int opcion;
    do {

        string nuevoNombre; // Nuevo nombre que pedimos al usuario para insertar un nuevo nombre
        string nombrePadre; // Nuevo padre que pedimos al usuario para insertar un nuevo nombre

        cout << "0. Salir" << endl;
        cout << "1. Insertar nuevo nombre" << endl;
        cout << "2. Mostrar arbol genealogico" << endl;
        cout << "3. Eliminar un subarbol" << endl;
        cout << "Introduce opcion: ";
        cin >> opcion;

        switch (opcion) {
        case (0): // Terminar programa
            break;
        case (1):
            cout << "Escriba el nuevo nombre: ";
            cin >> nuevoNombre;
            cout << "Escriba el nombre de su padre: ";
            cin >> nombrePadre;
            arbol.insertar(nuevoNombre, nombrePadre);
            break;
        case (2):
            arbol.imprimir();
            break;
        case (3):
            cout << "Escriba la raiz del subarbol a eliminar: ";
            cin >> nuevoNombre;
            arbol.eliminarSubarbol(nuevoNombre);
            break;
        default:
            cout << "Opcion incorrecta" << endl;
            break;
        }
    } while (opcion != 0);


    return 0;

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
