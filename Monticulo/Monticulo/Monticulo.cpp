// Monticulo.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#pragma once
#include <iostream>
#include"ListaContigua.h"
#include <cassert>

using namespace std;


class Monticulo {
    ListaContigua monticulo;


    bool esMonticulo(int raiz);
    void reestructurar(int raiz);

public:
    void insertar(int clave);
    void borrar();
    int getRaiz();
    void imprimirRecursivo(int raiz, int numeroTabulaciones);



};


bool Monticulo::esMonticulo(int raiz) {

    if (raiz * 2 + 1 > monticulo.getN() && raiz * 2 > monticulo.getN()) { //si no tengo hijos
        return true;
    }
    else if (raiz * 2 <= monticulo.getN() && raiz * 2 + 1 > monticulo.getN()) { //si tengo un hijo
        if (esMonticulo(raiz * 2) && monticulo.getValor(raiz - 1) < monticulo.getValor((raiz * 2) - 1)) {
            return true;
        }
        else {
            return false;
        }


    }
    else { //si tengo dos hijos
        if (esMonticulo(raiz * 2) && monticulo.getValor(raiz - 1) < monticulo.getValor((raiz * 2) + 1 - 1) && esMonticulo(raiz * 2 + 1) && monticulo.getValor(raiz - 1) < monticulo.getValor((raiz * 2) + 1 - 1)) {
            return true;
        }
        else {
            return false;
        }

    }

}

void Monticulo::insertar(int nuevoElemento) {

    monticulo.insertarAlFinal(nuevoElemento);
    int posicionPadre = monticulo.getN() / 2;
    int posicionHijo = monticulo.getN();
    int aux;
    
    if (monticulo.getN() > 1) {
        

        while (posicionPadre >= 1 ) {
            if (monticulo.getValor(posicionPadre - 1) > monticulo.getValor(posicionHijo-1)) {
                    aux = monticulo.getValor(posicionPadre - 1);
                    monticulo.setValor(posicionPadre - 1, monticulo.getValor(posicionHijo-1)); //ponemos en la posicion del padre el valor del hijo
                    monticulo.setValor(posicionHijo - 1, aux);
            }

            posicionHijo = posicionPadre;
            posicionPadre = posicionHijo / 2;
            
        }
    }

    assert(esMonticulo(1));
}

void Monticulo::reestructurar(int raiz) {
    assert(esMonticulo(2 * raiz) && esMonticulo(2 * raiz + 1));

    int posicion = raiz;
    int posicionMenorHijo;
    int aux;


    while (posicion * 2 <= monticulo.getN()) { // mientras tenga al menos un hijo
        if (posicion * 2 + 1 <= monticulo.getN()) { //si tengo dos hijos
            while (monticulo.getValor(posicion - 1) > monticulo.getValor(posicion * 2 - 1) || monticulo.getValor(posicion - 1) > monticulo.getValor(posicion * 2 + 1 - 1)) { //mientras alguno de sus hijos sea mayor que el
                if (monticulo.getValor(posicion * 2 - 1) < monticulo.getValor(posicion * 2 + 1 - 1)) { //si el hijo de la izquierda es el menor
                    aux = monticulo.getValor(posicion * 2 - 1); //valor del hijo de la izquierda
                    monticulo.setValor(posicion * 2 - 1, monticulo.getValor(posicion - 1)); //pongo en el hijo el valor del padre
                    monticulo.setValor(posicion - 1, aux); //pongo en el padre el valor del hijo

                    posicion = 2 * posicion;

                    if (posicion * 2 + 1 > monticulo.getN()) //si el siguiente elemento no tiene dos hijos paramos
                        break;

                }
                else {
                    aux = monticulo.getValor(posicion * 2 + 1 - 1); //valor del hijo de la derecha
                    monticulo.setValor(posicion * 2 + 1 - 1, monticulo.getValor(posicion - 1)); //pongo en el hijo el valor del padre
                    monticulo.setValor(posicion - 1, aux); //pongo en el padre el valor del hijo

                    posicion = 2 * posicion + 1;

                    if (posicion * 2 + 1 > monticulo.getN()) //si el siguiente elemento no tiene dos hijos paramos
                        break;

                }
            }
        }
        else { //si tengo solo un hijo (el izquierdo)
            if (monticulo.getValor(posicion * 2 - 1) < monticulo.getValor(posicion)) { //si el hijo es menor que el padre
                aux = monticulo.getValor(posicion * 2 - 1); //valor del hijo de la izquierda
                monticulo.setValor(posicion * 2 - 1, monticulo.getValor(posicion - 1)); //pongo en el hijo el valor del padre
                monticulo.setValor(posicion - 1, aux); //pongo en el padre el valor del hijo

                posicion = 2 * posicion;
            }
            else {
                break; //si no, paramos terminamos
            }

        } 

    }
}

 
    


void Monticulo::borrar() {
    assert(monticulo.getN() > 0);

    monticulo.setValor(0, monticulo.getValor(monticulo.getN() - 1));
    monticulo.eliminarAlFinal();
    reestructurar(1);

}

int Monticulo::getRaiz() {
    return (monticulo.getValor(0));
}

void Monticulo::imprimirRecursivo(int raiz, int numeroTabulaciones) {
    assert(raiz >= 1);
    assert(numeroTabulaciones >= 0);

    if (raiz <= monticulo.getN()) {

        // Imprimimos el nodo raiz con el nivel pasado como parametro
        for (int i = 0; i < numeroTabulaciones; i++) cout << "\t";
        cout << monticulo.getValor(raiz - 1) << endl;

        // Imprimimos sus hijos con una tabulacion mas
        imprimirRecursivo(raiz * 2, numeroTabulaciones + 1);
        imprimirRecursivo(raiz * 2 + 1, numeroTabulaciones + 1);

    }
}

int main()
{
    Monticulo monticulo;

    // Creamos la lista de inserciones
    int inserciones[] = { 3, 4, 6, 7, 5, 2 };

    ListaContigua lista;
    lista.insertarAlFinal(3);
    lista.insertarAlFinal(4);
    lista.insertarAlFinal(6);
    lista.insertarAlFinal(7);
    lista.insertarAlFinal(5);
    lista.insertarAlFinal(2);

    int tamanoLista = lista.getN();

    // Vamos insertando e imprimiendo
    for (int i = 0; i < lista.getN(); i++) {
        cout << "Insercion de " << lista.getValor(i) << ":\n";
        monticulo.insertar(lista.getValor(i));
        monticulo.imprimirRecursivo(1, 0);
    }

    int array [6];
    for (int j = 0; j < tamanoLista; j++) {
        lista.insertar(j, monticulo.getRaiz());
        monticulo.borrar();
        monticulo.imprimirRecursivo(1, 0);
    }

    cout << "Impresion lista ordenada: " << endl;

    for (int k = 0; k < tamanoLista; k++) {
        cout << lista.getValor(k) << " ";
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
