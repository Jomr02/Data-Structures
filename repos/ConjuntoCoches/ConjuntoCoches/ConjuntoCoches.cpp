// ConjuntoCoches.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <cassert>
#include <string>

using namespace std;


struct Coche {
    string matricula;
    string modelo;
    bool ocupado;
};
class ConjuntoCoches {
    Coche* tabla;
    int n;
    int capacidad;
    int versiones;
    // Poner aquí la declaración de los 3 métodos privados
    int obtenerPosicion(string matricula, int version);
    void modificaTabla(int nuevaCapacidad, int nuevasVersiones);
    int getPosicionCoche(string matricula);

public:
    // Poner aquí la declaración de los 4 métodos públicos
    ConjuntoCoches(int capacidad, int versiones);
    void insertar(Coche coche);
    Coche getElemento(string clave);
    void imprimir();


};

ConjuntoCoches::ConjuntoCoches(int capacidad, int versiones) {
    tabla = new Coche[capacidad];

    for (int i = 0; i < capacidad; i++) {
        tabla[i].ocupado = false;
    }

    n = 0;
    this->capacidad = capacidad;
    this->versiones = versiones;

}


int ConjuntoCoches::obtenerPosicion(string matricula, int version) {
    assert(version >= 0 && version < versiones);

    int posicion;
    int sumaString = 0;

    for (int i = 0; i < matricula.length(); i++) {
        sumaString = sumaString + (int) matricula.at(i);
    }

    posicion = (sumaString + version * (capacidad / versiones));
    posicion = posicion % capacidad;


    return posicion;

}

void ConjuntoCoches::modificaTabla(int nuevaCapacidad, int nuevasVersiones) {
    assert(nuevaCapacidad >= n);
    assert(nuevasVersiones >= 1);
    ConjuntoCoches *nuevoConjunto = new ConjuntoCoches(nuevaCapacidad, nuevasVersiones);


    for (int i = 0; i < capacidad; i++) {
        if (tabla[i].ocupado) {
            nuevoConjunto->insertar(tabla[i]);
        }
    }

    delete [] (tabla);
    tabla = nuevoConjunto->tabla;
    capacidad = nuevaCapacidad;
    versiones = nuevasVersiones;
    

}

int ConjuntoCoches::getPosicionCoche(string matricula) {
    
    bool encontrado = false;
    int version = 0;
    int posicion;

    while (!encontrado && version < versiones) {
        posicion = obtenerPosicion(matricula, version);
        if (tabla[posicion].matricula == matricula) {
            encontrado = true;
        }
        version++;
    }
    

    if (encontrado)
        return posicion;
    else
        return -1;

}

void ConjuntoCoches::insertar(Coche coche) {
    assert(getPosicionCoche(coche.matricula) == -1);

    bool insertado = false;
    int version = 0;
    int posicion;

 

    while (!insertado && version < versiones) {
        posicion = obtenerPosicion(coche.matricula, version);
        if (!tabla[posicion].ocupado) {
            tabla[posicion].matricula = coche.matricula;
            tabla[posicion].modelo = coche.modelo;
            tabla[posicion].ocupado = true;
            insertado = true;
            n++;
        }
        version++;
    }

    if (!insertado) {
        modificaTabla(2 * capacidad, versiones + 1);
        insertar(coche);
    }

}

Coche ConjuntoCoches::getElemento(string clave) {
    assert(getPosicionCoche(clave) != -1);

    int posicion = getPosicionCoche(clave);

    return (tabla[posicion]);
}

void ConjuntoCoches::imprimir() {
    if (n == 0) {
        cout << "Lista vacia" << endl;
    }
    else {
        for (int i = 0; i < capacidad; i++) {
            if (tabla[i].ocupado)
                cout << " Posicion " << i << " Ocupada " << tabla[i].ocupado << " Clave: " << tabla[i].matricula << " Contenido: " << tabla[i].modelo << endl;
            else
                cout << " Posicion " << i << " Ocupada " << tabla[i].ocupado << " Clave: N/A "<< " Contenido: N/A " << endl;
        }
    }

}








// Poner aquí la definición de los métodos
int main() {
    int capacidad; // Capacidad de la tabla hash
    int versiones; // Numero de versiones de la función hash
    int opcion; // Opcion de menu introducida por teclado
    cout << "Introduce la capacidad de la tabla: ";
    cin >> capacidad;
    cout << "Introduce el numero de versiones de la funcion hash: ";
    cin >> versiones;
    ConjuntoCoches coches(capacidad, versiones);
    do {
        // Imprimimos el menu y pedimos la opcion
        cout << "0. Salir\n";
        cout << "1. Imprimir conjunto de coches\n";
        cout << "2. Obtener modelo de un coche\n";
        cout << "3. Meter un nuevo coche\n";
        cout << "Introduzca opcion: ";
        cin >> opcion;
        string clave; // Clave para algunas opciones
        string valor; // Modelo de coche para la opcion de meter
        Coche coche; // Para la opcion de meter
        switch (opcion) {
        case 0: break;
        case 1:
            coches.imprimir();
            break;
        case 2:
            // Obtener un modelo de coche
            cout << "Introduzca la matricula del coche: ";
            cin >> clave;
            cout << "Su modelo es: " << coches.getElemento(clave).modelo << endl;
            break;
        case 3:
            // Meter un nuevo coche
            cout << "Introduzca la matricula del coche: ";
            cin >> clave;
            cout << "Introduzca el modelo de coche: ";
            cin >> valor;
            coche.matricula = clave;
            coche.modelo = valor;
            coches.insertar(coche);
            break;
        default:
            cout << "Opcion incorrecta\n"; break;
        } // Fin switch
    } while (opcion != 0);
} // Fin main
