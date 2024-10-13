// MaztrizDeAdyacencia.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//


#pragma once

#include "ListaContigua.h"
#include <iostream>
#include <string>
#include "cstdlib"
#include "cassert"

using namespace std;

class Grafo {
    string nodos;
    ListaContigua* matriz;
    int n;

    bool existeNodo(char letra);
    bool existeArco(int posicionOrigen, int posicionDestino);
    string recorridoProfundidadRecursivo(int posicionNodo, bool *vistos);
    int obtenerPosicion(char letra);


public:
    Grafo();
    void insertarNodo(char letra);
    void insertarArco(char origen, char destino);
    void eliminarNodo(char letra);
    void eliminarArco(char origen, char destino);
    void imprimir();
    char* recorridoProfundidad(char nodoInicio);
    
};

Grafo::Grafo() {
    matriz = NULL;
    n = 0;
}

bool Grafo::existeNodo(char letra) {
    if (nodos.find(letra) != string::npos)
        return true;
    else
        return false;
}

int Grafo::obtenerPosicion(char letra) {
    assert(existeNodo(letra));

    return nodos.find(letra);
}


bool Grafo::existeArco(int posicionOrigen, int posicionDestino) {
    char origen = nodos[posicionOrigen];
    char destino = nodos[posicionDestino];
    assert(existeNodo(origen));
    assert(existeNodo(destino));

    return (matriz[posicionOrigen].getValor(posicionDestino) > 0);
}

void Grafo::insertarNodo(char letra) {
    assert(!existeNodo(letra));

    nodos.append(1, letra);

    //añadimos la columna al final
    for (int i = 0; i < n; i++) {
        matriz[i].insertarAlFinal(0);
    }

    ListaContigua* nuevaFila = new ListaContigua;

    //creamos la nueva fila
    for (int i = 0; i <= n; i++) {
        nuevaFila->insertarAlFinal(0);

    }

    ListaContigua* nuevaMatriz = new ListaContigua[n + 1];

    for (int i = 0; i < n; i++) {
        nuevaMatriz[i].concatenar(&matriz[i]);
    }

    nuevaMatriz[n].concatenar(nuevaFila);

    delete[] matriz;
    delete nuevaFila;

    matriz = nuevaMatriz;

    n++;
}

void Grafo::insertarArco(char origen, char destino) {
    assert(existeNodo(origen));
    assert(existeNodo(destino));
    

    int posicionOrigen = nodos.find(origen);
    int posicionDestino = nodos.find(destino);


    matriz[posicionOrigen].setValor(posicionDestino, 1);

}


void Grafo::eliminarNodo(char letra) {
    assert(existeNodo(letra));
    

    ListaContigua* nuevaMatriz = new ListaContigua[n - 1];

    int posicionNodo = nodos.find(letra);

    nodos.erase(posicionNodo, 1);

    //borramos la columna
    for (int i = 0; i < n; i++) {
        matriz[i].eliminar(posicionNodo);
    }

    //copiamos las filas a la nueva matriz menos la que queremos eliminar
    for (int i = 0; i < posicionNodo; i++) {
        nuevaMatriz[i].concatenar(&matriz[i]);
    }

    for (int i = posicionNodo + 1; i <= n - 1; i++) {
        nuevaMatriz[i - 1].concatenar(&matriz[i]);
    }

    delete[] matriz;

    matriz = nuevaMatriz;

    n--;
}

void Grafo::eliminarArco(char origen, char destino) {
    assert(existeNodo(origen));
    assert(existeNodo(destino));


    int posicionOrigen = nodos.find(origen);
    int posicionDestino = nodos.find(destino);

    matriz[posicionOrigen].setValor(posicionDestino, 0);
}

void Grafo::imprimir() {

    // Si el grafo está vacio, imprimimos mensaje informativo
    if (n == 0) cout << "La matriz esta vacia\n";

    // En caso contrario, imprimimos la matriz de adyacencia bien alineada
    else {

        // Imprimimos la primera línea de la matriz, con los nombres de los nodos
        cout << "  "; // Imprimimos espacio de la esquina superior izquierda de la matriz	
        for (int i = 0; i < n; i++) cout << nodos[i] << " "; // Imprimimos el nombre de los nodos en las columnas
        cout << endl;

        // Imprimimos las filas
        for (int i = 0; i < n; i++) {
            cout << nodos[i] << " "; // Imprimimos el nombre del nodo de la fila
            for (int j = 0; j < n; j++) cout << existeArco(i, j) << " ";
            cout << endl;
        }
        cout << endl;
    }
}

char* Grafo::recorridoProfundidad(char nodoInicio) {
    assert(existeNodo(nodoInicio));

    int posicionInicial = obtenerPosicion(nodoInicio);

    bool* vistos = (bool*)malloc(sizeof(bool) * n);

    for (int i = 0; i < n; i++) {
        vistos[i] = false;
    }

    string recorrido;

    recorrido.append(recorridoProfundidadRecursivo(posicionInicial, vistos));

    free(vistos);

    char* recorridoenProfundidad = (char*)malloc(sizeof(char) * recorrido.size());

    for (int i = 0; i < recorrido.size(); i++) {
        recorridoenProfundidad[i] = recorrido[i];
    }

    recorridoenProfundidad[recorrido.size()] = '\0';

    return recorridoenProfundidad;

}


string Grafo::recorridoProfundidadRecursivo(int posicionNodo, bool* vistos) {
    assert(posicionNodo >= 0 && posicionNodo < n);

    vistos[posicionNodo] = true;

    string recorrido;
    recorrido.append(1, nodos[posicionNodo]);

    for (int i = 0; i < n; i++) {
        if (!vistos[i] && matriz[posicionNodo].getValor(i) > 0) {
            recorrido.append(recorridoProfundidadRecursivo(i, vistos));
        }
    }

    return recorrido;
}







int main()
{
    Grafo grafo;
    grafo.imprimir();
    cout << endl;

    // Insertamos los nodos
    grafo.insertarNodo('A');
    grafo.insertarNodo('B');
    grafo.insertarNodo('C');
    grafo.insertarNodo('D');
    grafo.insertarNodo('E');
    grafo.imprimir();

    grafo.insertarArco('A', 'A');
    grafo.insertarArco('A', 'C');
    grafo.insertarArco('A', 'E');
    grafo.insertarArco('B', 'B');
    grafo.insertarArco('B', 'D');
    grafo.insertarArco('C', 'A');
    grafo.insertarArco('C', 'C');
    grafo.insertarArco('C', 'E');
    grafo.insertarArco('D', 'B');
    grafo.insertarArco('D', 'D');
    grafo.insertarArco('E', 'A');
    grafo.insertarArco('E', 'C');
    grafo.insertarArco('E', 'E');
    grafo.imprimir();

    grafo.eliminarNodo('B'); grafo.imprimir();
    grafo.eliminarNodo('A'); grafo.imprimir();
    grafo.eliminarNodo('E'); grafo.imprimir();

    grafo.insertarNodo('H');
    grafo.insertarNodo('G');
    grafo.insertarNodo('F');
    grafo.insertarNodo('E');
    grafo.imprimir();

    grafo.eliminarArco('C', 'C');
    grafo.eliminarArco('D', 'D');
    grafo.imprimir();

    grafo.insertarArco('C', 'D');
    grafo.insertarArco('D', 'C');
    grafo.insertarArco('D', 'G');
    grafo.insertarArco('G', 'D');
    grafo.insertarArco('G', 'H');
    grafo.insertarArco('C', 'E');
    grafo.insertarArco('E', 'C');
    grafo.insertarArco('C', 'F');
    grafo.insertarArco('F', 'C');
    grafo.insertarArco('F', 'G');
    grafo.insertarArco('G', 'F');
    grafo.imprimir();

    cout << grafo.recorridoProfundidad('C') << endl;
    cout << grafo.recorridoProfundidad('G') << endl;
    cout << grafo.recorridoProfundidad('H') << endl;

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
