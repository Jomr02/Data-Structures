// ListaDeAdyacencia.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#pragma once

#include "ListaContigua.h"
#include "Aeropuerto.h"
#include "string"
#include "ListaEnlazada.h"
#include "impresionListasEnlazadas.h"
#include "iostream"
#include "cassert"


using namespace std;


class EspacioAereo {
    ListaContigua nodos;
    int n;

    bool existeAeropuerto(string nombreAeropuerto);
    ListaEnlazada* getDestinos(string aeropuertoOrigen);
    ListaEnlazada* getOrigenes(string aeropuertoDestino);
    bool existeRuta(string origen, string destino);

public:
    EspacioAereo();
    void imprimir();
    void insertarAeropuerto(string nombreAeropuerto);
    void insertarRuta(string aeropuertoOrigen, string aeropuertoDestino, int distancia, string aerolinea);
    void eliminarRuta(string aeropuertoOrigen, string aeropuertoDestino);
    void eliminarAeropuerto(string nombreAeropuerto);



};


bool EspacioAereo::existeAeropuerto(string nombreAeropuerto) {
    if (nodos.buscar(nombreAeropuerto) != -1)
        return true;
    else
        return false;

}

ListaEnlazada* EspacioAereo::getDestinos(string aeropuertoOrigen) {
    assert(existeAeropuerto(aeropuertoOrigen));

    int posicionAeropuerto = nodos.buscar(aeropuertoOrigen);

    return nodos.getValor(posicionAeropuerto).rutasSalientes;
}

ListaEnlazada* EspacioAereo::getOrigenes(string aeropuertoDestino) {
    assert(existeAeropuerto(aeropuertoDestino));

    int posicionAeropuerto = nodos.buscar(aeropuertoDestino);

    return nodos.getValor(posicionAeropuerto).rutasEntrantes;

}

bool EspacioAereo::existeRuta(string origen, string destino) {
    assert(existeAeropuerto(origen));
    assert(existeAeropuerto(destino));

    ListaEnlazada* rutasSalientesOrigen = getDestinos(origen);
    ListaEnlazada* rutasEntrantesDestino = getOrigenes(destino);

    if (rutasSalientesOrigen->buscar(destino) != -1 && rutasEntrantesDestino->buscar(origen) != -1)
        return true;
    else
        return false;

}


EspacioAereo::EspacioAereo() {
    n = 0;
}

void EspacioAereo::insertarAeropuerto(string nombreAeropuerto) {
    assert(!existeAeropuerto(nombreAeropuerto));

    Aeropuerto* nuevoAeropuerto = new Aeropuerto;
    nuevoAeropuerto->nombre = new string(nombreAeropuerto);
    nuevoAeropuerto->rutasEntrantes = new ListaEnlazada();
    nuevoAeropuerto->rutasSalientes = new ListaEnlazada();
    
    nodos.insertarAlFinal(*nuevoAeropuerto);

    
    n++;
}


void EspacioAereo::insertarRuta(string aeropuertoOrigen, string aeropuertoDestino, int distancia, string aerolinea) {
    assert(existeAeropuerto(aeropuertoOrigen));
    assert(existeAeropuerto(aeropuertoDestino));
    assert(!existeRuta(aeropuertoOrigen, aeropuertoDestino));

    ListaEnlazada* rutasSalientesOrigen = getDestinos(aeropuertoOrigen);
    ListaEnlazada* rutasEntrantesDestino = getOrigenes(aeropuertoDestino);

    Ruta* nuevaRutaIda = new Ruta;
    nuevaRutaIda->aeropuerto = new string(aeropuertoDestino);
    nuevaRutaIda->empresa = new string(aerolinea);
    nuevaRutaIda->kilometros = distancia;

    rutasSalientesOrigen->insertar(rutasSalientesOrigen->getN(), *nuevaRutaIda);

    Ruta* nuevaRutaVuelta = new Ruta;
    nuevaRutaVuelta->aeropuerto = new string(aeropuertoOrigen);
    nuevaRutaVuelta->empresa = new string(aerolinea);
    nuevaRutaVuelta->kilometros = distancia;

    rutasEntrantesDestino->insertar(rutasEntrantesDestino->getN(), *nuevaRutaVuelta);
}

void EspacioAereo::eliminarRuta(string aeropuertoOrigen, string aeropuertoDestino) {
    assert(existeAeropuerto(aeropuertoOrigen));
    assert(existeAeropuerto(aeropuertoDestino));
    assert(existeRuta(aeropuertoOrigen, aeropuertoDestino));

    ListaEnlazada* rutasSalientesOrigen = getDestinos(aeropuertoOrigen);
    ListaEnlazada* rutasEntrantesDestino = getOrigenes(aeropuertoDestino);

    int posicionDestino = rutasSalientesOrigen->buscar(aeropuertoDestino);
    int posicionOrigen = rutasEntrantesDestino->buscar(aeropuertoOrigen);

    rutasSalientesOrigen->eliminar(posicionDestino);
    rutasEntrantesDestino->eliminar(posicionOrigen);
}

void EspacioAereo::eliminarAeropuerto(string nombreAeropuerto) {
    assert(existeAeropuerto(nombreAeropuerto));

    int posicionAeropuerto = nodos.buscar(nombreAeropuerto);

    Aeropuerto aeropuerto = nodos.getValor(posicionAeropuerto);

    ListaEnlazada* rutasSalientes = getDestinos(nombreAeropuerto);
    ListaEnlazada* rutasEntrantes = getOrigenes(nombreAeropuerto);

    while (rutasSalientes->getN() > 0) {
        eliminarRuta(nombreAeropuerto, *rutasSalientes->getValor(0).aeropuerto);
    }

    while (rutasEntrantes->getN() > 0) {
        eliminarRuta(*rutasEntrantes->getValor(0).aeropuerto, nombreAeropuerto);
    }

    nodos.eliminar(posicionAeropuerto);

    n--;
}

void EspacioAereo::imprimir() {
    if (n == 0) cout << "Grafo vacio\n";
    else {
        // Por cada nodo, imprimimos sus destinos y sus orígenes
        for (int i = 0; i < n; i++) {
            Aeropuerto aeropuerto = nodos.getValor(i);
            cout << "Nodo " << *(aeropuerto.nombre) << ":\n";
            cout << "\tRutas de salida: ";
            imprimirListaEnlazada(nodos.getValor(i).rutasSalientes);
            cout << "\tRutas de entrada: ";
            imprimirListaEnlazada(nodos.getValor(i).rutasEntrantes);
        }
    }
    cout << endl;

}




int main()
{
    EspacioAereo grafo;

    grafo.insertarAeropuerto("Barajas");
    grafo.insertarAeropuerto("Prat");
    grafo.insertarAeropuerto("Heathrow");
    grafo.insertarAeropuerto("JFK");
    grafo.insertarAeropuerto("Frankfurt");
    grafo.imprimir();

    grafo.insertarRuta("Barajas", "Prat", 300, "Vueling");
    grafo.insertarRuta("Prat", "Barajas", 350, "Iberia");
    grafo.insertarRuta("Barajas", "Heathrow", 900, "Iberia");
    grafo.insertarRuta("Barajas", "JFK", 3000, "Iberia");
    grafo.insertarRuta("JFK", "Heathrow", 2500, "Iberia");

    grafo.imprimir();

    grafo.eliminarAeropuerto("Frankfurt");
    grafo.imprimir();

    grafo.eliminarRuta("Prat", "Barajas");
    grafo.imprimir();

    grafo.eliminarAeropuerto("Barajas");
    grafo.imprimir();

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
