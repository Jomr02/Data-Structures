#include "string"
#include "cassert"
#include "iostream"
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
	
	int hashing(string matricula, int version);
	void modificaTabla(int nuevaCapacidad, int nuevasVersiones);
	int buscaPosicion(string matricula);

public:
	ConjuntoCoches(int capacidad, int versiones);
	void insertar(Coche coche);
	Coche getElemento(string matricula);
	void imprimir();

};


int ConjuntoCoches::hashing(string matricula, int version) {
	assert(version >= 0 && version < versiones);

	int sumaCaracteres = 0;

	for (int i = 0; i < matricula.size(); i++) {
		sumaCaracteres = sumaCaracteres + (int)matricula[i];
	}


	int posicion = sumaCaracteres + version * (capacidad / versiones);
	posicion = sumaCaracteres % capacidad;


	return posicion;
}


void ConjuntoCoches::modificaTabla(int nuevaCapacidad, int nuevasVersiones) {
	assert(nuevasVersiones > 0);

	ConjuntoCoches *nuevoConjunto = new ConjuntoCoches (nuevaCapacidad, nuevasVersiones);

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

int ConjuntoCoches::buscaPosicion(string matricula) {

	int posicion = -1;

	for (int i = 0; i < versiones; i++) {
		int hash = hashing(matricula, i);
		if (tabla[hash].matricula == matricula && tabla[hash].ocupado) {
			posicion = hash;
		}
	}

	return posicion;

}


ConjuntoCoches::ConjuntoCoches(int capacidad, int versiones) {
	assert(capacidad > 0);
	assert(versiones > 0);

	tabla = new Coche[capacidad];

	for (int i = 0; i < capacidad; i++) {
		tabla[i].ocupado = false;
	}

	this->versiones = versiones;
	this->capacidad = capacidad;
	n = 0;
}

void ConjuntoCoches::insertar(Coche coche) {

	bool insertado = false;
	int contadorVersiones = 0;
	int hash;

	while (contadorVersiones < versiones && insertado == false) {
		hash = hashing(coche.matricula, contadorVersiones);

		if (!tabla[hash].ocupado) {
			tabla[hash] = coche;
			tabla[hash].ocupado = true;
			insertado = true;
		}
		contadorVersiones++;
	}

	if (!insertado) {
		modificaTabla(2 * capacidad, versiones + 1);
		insertar(coche);
	}



}



Coche ConjuntoCoches::getElemento(string matricula) {
	assert(buscaPosicion (matricula) != -1);

	int posicion = buscaPosicion(matricula);


	return (tabla[posicion]);
}


void ConjuntoCoches::imprimir() {
	
	for (int i = 0; i < capacidad; i++) {
		cout << "Posicion " << i << " |  Ocupada " << tabla[i].ocupado << " | Clave " << tabla[i].matricula << " | Modelo " << tabla[i].modelo << endl;
	}
}







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
} 