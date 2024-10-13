// ListasDeAdyacencia.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
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
    ListaContigua aeropuertos;
    int n;

    bool existeAeropuerto(string nombreAeropuerto);
    ListaEnlazada* getDestinos(string nombreOrigen);
    ListaEnlazada* getOrigenes(string nombreDestino);
    bool existeRuta(string nombreOrigen, string nombreDestino);

public:

    EspacioAereo();
    void imprimir();
    void insertarAeropuerto(string nombreAeropuerto);
    void insertarRuta(string nombreOrigen, string nombreDestino, int distancia, string aerolinea);
    void eliminarRuta(string nombreOrigen, string nombreDestino);
    void eliminarAeropuerto(string nombreAeropuerto);

};

bool EspacioAereo::existeAeropuerto(string nombreAeropuerto) {
    
    if (aeropuertos.buscar(nombreAeropuerto) != -1)
        return true;
    else
        return false;
}

ListaEnlazada* EspacioAereo::getDestinos(string nombreOrigen) {
    assert(existeAeropuerto(nombreOrigen));

    return aeropuertos.getValor(aeropuertos.buscar(nombreOrigen)).rutasSalientes;

}

ListaEnlazada* EspacioAereo::getOrigenes(string nombreDestino) {
    assert(existeAeropuerto(nombreDestino));

    return aeropuertos.getValor(aeropuertos.buscar(nombreDestino)).rutasEntrantes;

}

bool EspacioAereo::existeRuta(string nombreOrigen, string nombreDestino) {
    assert(existeAeropuerto(nombreOrigen));
    assert(existeAeropuerto(nombreDestino));

    
    ListaEnlazada* destinos = aeropuertos.getValor(aeropuertos.buscar(nombreOrigen)).rutasSalientes; //sacamos la lista de destinos del aeropuerto origen

    

    if (destinos->buscar(nombreDestino) != -1) { //si encontramos el aeropuerto destino en la lista de destinos, exista la ruta
        return true;
    }
    else {
        return false;
    }
}

EspacioAereo::EspacioAereo() {
    n = 0;

}

void EspacioAereo::insertarAeropuerto(string nombreAeropuerto) {
    assert(!existeAeropuerto(nombreAeropuerto));

    Aeropuerto* nuevoAeropuerto = new Aeropuerto;
    nuevoAeropuerto->nombre = new string;
    *(nuevoAeropuerto->nombre) = nombreAeropuerto;
    nuevoAeropuerto->rutasEntrantes = new ListaEnlazada ();
    nuevoAeropuerto->rutasSalientes = new ListaEnlazada();

    aeropuertos.insertarAlFinal(*nuevoAeropuerto);

    n++;
}

void EspacioAereo::insertarRuta(string nombreOrigen, string nombreDestino, int distancia, string aerolinea) {
    assert(!existeRuta(nombreOrigen, nombreDestino));

    Ruta* nuevaRutaOrigen = new Ruta;
    nuevaRutaOrigen->aeropuerto = new string(nombreDestino); //como es la ruta origen (la que almacenamos en el origen) el aeropuerto que guardamos es el de destino
    nuevaRutaOrigen->empresa = new string(aerolinea);
    nuevaRutaOrigen->kilometros = distancia;

    //insertamos la ruta en el origen
    aeropuertos.getValor(aeropuertos.buscar(nombreOrigen)).rutasSalientes->insertar(0, *nuevaRutaOrigen);

    Ruta* nuevaRutaDestino = new Ruta; //ahora tenemos que insertar la ruta en el aeropuerto destino, la ruta llevara como dato, el aeropuerto origen
    nuevaRutaDestino->aeropuerto = new string(nombreOrigen); 
    nuevaRutaDestino->empresa = new string(aerolinea);
    nuevaRutaDestino->kilometros = distancia;

    aeropuertos.getValor(aeropuertos.buscar(nombreDestino)).rutasEntrantes->insertar(0, *nuevaRutaDestino);


}

void EspacioAereo::imprimir() {
    if (n == 0) cout << "Grafo vacio\n";
    else {
        // Por cada nodo, imprimimos sus destinos y sus orígenes
        for (int i = 0; i < n; i++) {
            Aeropuerto aeropuerto = aeropuertos.getValor(i);
            cout << "Nodo " << *(aeropuerto.nombre) << ":\n";
            cout << "\tRutas de salida: ";
            imprimirListaEnlazada(aeropuertos.getValor(i).rutasSalientes);
            cout << "\tRutas de entrada: ";
            imprimirListaEnlazada(aeropuertos.getValor(i).rutasEntrantes);
        }
    }
    cout << endl;
}

void EspacioAereo::eliminarRuta(string nombreOrigen, string nombreDestino) {
    assert(existeRuta(nombreOrigen, nombreDestino));

    aeropuertos.getValor(aeropuertos.buscar(nombreOrigen)).rutasSalientes->eliminar(aeropuertos.getValor(aeropuertos.buscar(nombreOrigen)).rutasSalientes->buscar(nombreDestino)); //eliminamos el destino en las rutas salientes del origen

    aeropuertos.getValor(aeropuertos.buscar(nombreDestino)).rutasEntrantes->eliminar(aeropuertos.getValor(aeropuertos.buscar(nombreDestino)).rutasEntrantes->buscar(nombreOrigen)); //eliminamos el origen en las rutas entrantes del destino

}

void EspacioAereo::eliminarAeropuerto(string nombreAeropuerto) {
    assert(existeAeropuerto(nombreAeropuerto));

 
    ListaEnlazada* destinos = getDestinos(nombreAeropuerto);

    while (destinos->getN() > 0) {
        eliminarRuta(nombreAeropuerto, *(destinos->getValor(0).aeropuerto));
    }

    ListaEnlazada* origenes = getOrigenes(nombreAeropuerto);

    while (origenes->getN() > 0) {
        eliminarRuta(*(origenes->getValor(0).aeropuerto), nombreAeropuerto);
    }

    aeropuertos.eliminar(aeropuertos.buscar(nombreAeropuerto));

    n--;
}

int main()
{

    EspacioAereo grafo;

    grafo.insertarAeropuerto("Barajas");
    grafo.insertarAeropuerto("Prat");
    grafo.insertarAeropuerto("Heathrow");
    grafo.insertarAeropuerto("JFK");
    grafo.insertarAeropuerto("Frankfurt");

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
