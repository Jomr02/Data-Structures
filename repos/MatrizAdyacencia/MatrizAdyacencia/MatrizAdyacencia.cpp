// MatrizAdyacencia.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
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
    ListaContigua *arcos;
    int n;

    bool existeNodo(char letra);
    bool existeArco(int posicionOrigen, int posicionDestino);
    int obtenerPosicion(char letra);
    string recorridoProfundidadRecursivo(int posicionOrigen, bool *vistos);

public:
    Grafo();
    void insertarNodo(char letra);
    void insertarArco(char origen, char destino);
    void eliminarNodo(char letra);
    void eliminarArco(char origen, char destino);
    string recorridoProfundidad(char origen);
    void imprimir();

};

Grafo::Grafo() {
    arcos = NULL;
    n = 0;
}

bool Grafo::existeNodo(char letra) {
    if (nodos.find(letra) == string::npos)
        return false;
    else
        return true;

}

int Grafo::obtenerPosicion(char letra) {
    assert(existeNodo(letra));

    int posicion = nodos.find(letra);

    return posicion;
}

bool Grafo::existeArco(int posicionOrigen, int posicionDestino) {
    assert(posicionOrigen >= 0 && posicionOrigen < n);
    assert(posicionDestino >= 0 && posicionDestino < n);

    if (arcos[posicionOrigen].getValor(posicionDestino) != 0)
        return true;
    else
        return false;


}

void Grafo::insertarArco(char origen, char destino) {
    assert(existeNodo(origen));
    assert(existeNodo(destino));
    assert(!existeArco(obtenerPosicion(origen), obtenerPosicion(destino)));

    int posicionOrigen = obtenerPosicion(origen);
    int posicionDestino = obtenerPosicion(destino);

    arcos[posicionOrigen].setValor(posicionDestino, 1);

}

void Grafo::eliminarArco(char origen, char destino) {
    assert(existeNodo(origen));
    assert(existeNodo(destino));

    int posicionOrigen = obtenerPosicion(origen);
    int posicionDestino = obtenerPosicion(destino);

    arcos[posicionOrigen].setValor(posicionDestino, 0);

}



void Grafo::insertarNodo(char letra) {
    assert(!existeNodo(letra));

    //añadimos la letra a la lista de nodos
    nodos.append(1, letra);

    //por cada fila, añadimos una elemento mas inicializado a 0 para insertar la columna
    for (int i = 0; i < n; i++) {
        arcos[i].insertarAlFinal(0);
    }
    

    ListaContigua* nuevaFila = new ListaContigua; //nueva fila

    //rellenamos la nueva fila con 0
    for (int i = 0; i < n + 1; i++) {
        nuevaFila->insertarAlFinal(0);
    }

    ListaContigua* nuevosArcos = new ListaContigua[n + 1]; //nuevo espacio para la nueva matriz de arcos

    //rellenamos la nueva matriz con los antiguos arcos (con la columna de ceros previamente añadida)
    for (int i = 0; i < n; i++) {
        nuevosArcos[i].concatenar(&arcos[i]);
    }

    nuevosArcos[n].concatenar(nuevaFila);

    delete[] (arcos);
    delete (nuevaFila);

    arcos = nuevosArcos;

    n++;
}

void Grafo::eliminarNodo(char letra) {
    assert(existeNodo(letra));

    int posicionNodo = obtenerPosicion(letra);

    for (int i = 0; i < n; i++) {
        arcos[i].eliminar(posicionNodo);
    }


    ListaContigua* nuevosArcos = new ListaContigua[n - 1];

    for (int i = 0; i < posicionNodo; i++) {
        nuevosArcos[i].concatenar(&arcos[i]);
    }
    
    int posicionNodoAux = posicionNodo;

    for (int i = posicionNodo + 1; i < n; i++) {
        nuevosArcos[posicionNodoAux].concatenar(&arcos[i]);
        posicionNodoAux++;
    }
    
    nodos.erase(posicionNodo, 1);

    delete[] arcos;

    arcos = nuevosArcos;

    n--;

}

string Grafo::recorridoProfundidadRecursivo(int posicionOrigen, bool* vistos) {

    vistos[posicionOrigen] = true;

    int nAdyacentes = 0;

    string recorrido;
    recorrido.append(1, nodos[posicionOrigen]);

    for (int i = 0; i < n; i++) {
        if (arcos[posicionOrigen].getValor(i) != 0) {
            nAdyacentes++;
        }
    }

    if (nAdyacentes > 0) { 
        for (int i = 0; i < n; i++) {

            if (arcos[posicionOrigen].getValor(i) != 0 && !vistos[i]) {
                recorrido.append(recorridoProfundidadRecursivo(i, vistos));
            }
        }
    }
    else {
        return recorrido;
    }

    return recorrido;


}

string Grafo::recorridoProfundidad (char origen){
    assert(existeNodo(origen));

    int posicionOrigen = obtenerPosicion(origen);
    string recorrido;

    bool* vistos = (bool*)malloc(sizeof(bool) * n);

    for (int i = 0; i < n; i++) {
        vistos[i] = false;
    }
    
    recorrido = recorrido.append(recorridoProfundidadRecursivo(posicionOrigen, vistos));

    free(vistos);


    return recorrido;

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

    // Insertamos arcos
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

    // Borramos nodos
    grafo.eliminarNodo('B'); grafo.imprimir();
    grafo.eliminarNodo('A'); grafo.imprimir();
    grafo.eliminarNodo('E'); grafo.imprimir();

    // Insertamos nuevos nodos
    grafo.insertarNodo('H');
    grafo.insertarNodo('G');
    grafo.insertarNodo('F');
    grafo.insertarNodo('E');
    grafo.imprimir();

    // Borramos los arcos que quedan en el grafo
    grafo.eliminarArco('C', 'C');
    grafo.eliminarArco('D', 'D');
    grafo.imprimir();

    // Insertamos varios arcos para formar el grafo del enunciado
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
