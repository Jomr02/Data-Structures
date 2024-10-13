#include "cassert"
#include "iostream"
#include "cstdlib" // Para realloc()
#include "cstring" // Para memmove()
#include "string"
using namespace std;

// Nodo de un árbol de chars
struct Nodo {
	char contenido; // Contenido del nodo (el elemento)
	Nodo* padre; // Puntero al nodo padre. NULL si no hay
	Nodo* hijoIzquierdo; // Puntero al primer hijo. NULL si no hay
	Nodo* hermanoDerecho; // Puntero al hermano derecho. NULL si no hay
};

// Clase que representa un árbol generalista de chars
class Arbol
{

	Nodo* raiz; // Puntero al nodo raíz del árbol. NULL si el árbol está vacío
	int n; // Número de elementos (y nodos) del árbol. Sólo sirve para las precondiciones

	// Obtiene el número de hijos directos de un nodo
	// Parámetro: nodo cuyo número de hijos queremos obtener
	// Retorno: número de hijos del nodo
	// Precondición: padre!=NULL
	// Complejidad temporal: O(hijos), siendo hijos el número de hijos del nodo pasado como parámetro
	int getNumeroHijos(Nodo* padre);

	// Obtiene el puntero a un hijo concreto de un nodo
	// Parámetros:
	// - padre: nodo cuyo hijo queremos obtener
	// - posicionHijo: posición del hijo que queremos obtener
	// Retorno: puntero al nodo hijo
	// Precondiciones:
	// - padre!=NULL
	// - getNumeroHijos(padre)>0
	// - posicionHijo pertenece a [0, getNumeroHijos(padre)-1]
	// Complejidad temporal: O(hijos), siendo hijos el número de hijos del nodo pasado como parámetro
	Nodo* getHijo(Nodo* padre, int posicionHijo);

	// Obtiene el puntero a un nodo con un determinado contenido en un subárbol (método recursivo)
	// Parámetros: 
	// - raizSubarbol: nodo raíz en donde empieza el subárbol
	// - contenido: contenido que queremos buscar en el subárbol
	// Retorno: puntero al primer nodo encontrado con el contenido buscado, o NULL si no se encuentra ningun nodo
	// Precondición: raizSubarbol != NULL
	// Complejidad temporal: O(n), siendo n el número de nodos del subárbol que empieza en raizSubarbol 
	Nodo* buscarNodo(Nodo* raizSubarbol, char contenido);

	// Imprime un subarbol por pantalla en forma de esquema, sangrando los hijos con tabulaciones. Esta pensado para ser recursivo
	// Parámetros:
	// - subarbol: nodo raíz del subarbol que queremos imprimir
	// - numeroTabulaciones: numero de tabulaciones con la que imprimimos la raiz. Los hijos directos tendrán una tabulación más
	// Precondiciones: subarbol != NULL && numeroTabulaciones>=0
	// Complejidad temporal: O(n), siendo n el número de nodos del subárbol que empieza en raizSubarbol
	void imprimirRecursivo(Nodo* raizSubarbol, int numeroTabulaciones);

	// Elimina recursivamente los nodos de un subarbol. No toca los punteros que apuntan a la raíz del subarbol
	// Parámetro: el nodo raíz del subarbol a eliminar
	// Precondición: subarbol != NULL
	// Complejidad temporal: O(n), siendo n el número de nodos del subárbol que empieza en raizSubarbol
	void eliminarSubarbol(Nodo* subarbol);

public:

	// Crea un árbol de un solo nodo (su raíz)
	// Parámetro: el contenido de la raíz
	// Complejidad temporal: O(1)
	Arbol(char contenidoRaiz);

	// Inserta un nuevo elemento en el árbol genealógico, como último hijo de un nodo indicado en el parámetro
	// Parámetros:
	// - nuevoElemento: elemento que queremos insertar
	// - elementoPadre: padre del elemento que queremos insertar. Será su último hijo
	// Precondición: elementoPadre existe en el árbol
	// Complejidad temporal: O(n) 
	void insertar(char nuevoElemento, char elementoPadre);

	// Imprime el árbol en forma de esquema con tabulaciones
	// Precondicion: n>0
	// Complejidad temporal: O(n) 
	void imprimir();

	// Destructor. Destruye toda la memoria ocupada por los nodos del árbol
	// Complejidad temporal: O(n) 
	~Arbol();

};

int Arbol::getNumeroHijos(Nodo* padre) {
	assert(padre != NULL);

	Nodo* hijoActual = padre->hijoIzquierdo; // Hijo actual en el que estamos (inicialmente es el primero)
	int numeroHijosDirectos; // Resultado de la función

	// Si no tiene ni siquiera un primer hijo, no tiene ningún hijo
	if (hijoActual == NULL) numeroHijosDirectos = 0;

	// Si tiene hijos, vamos iterando por ellos (de hermano a hermano) para contar cuántos hay
	else {
		numeroHijosDirectos = 1; // Al menos tiene uno (el primer hijo)		
		// Vamos desplazándonos al hermano derecho hasta que ya no podamos más
		while (hijoActual->hermanoDerecho != NULL) {
			hijoActual = hijoActual->hermanoDerecho;
			numeroHijosDirectos++;
		}
	}
	return(numeroHijosDirectos);
}

Nodo* Arbol::getHijo(Nodo* padre, int posicionHijo) {
	assert(padre != NULL);
	int numeroHijos = getNumeroHijos(padre); // Numero de hijos del padre
	assert(numeroHijos > 0);
	assert(posicionHijo >= 0 && posicionHijo < numeroHijos);

	// Llegamos hasta el hijo adecuado, iterando a lo largo de los hermanos
	Nodo* resultado = padre->hijoIzquierdo; // Puntero al nodo hijo al que queremos acceder. Inicializado con el primero
	for (int i = 0; i < posicionHijo; i++) resultado = resultado->hermanoDerecho; // Llegamos hasta el hijo adecuado

	// Devolvemos el puntero al nodo hijo
	return(resultado);
}

Nodo* Arbol::buscarNodo(Nodo* raizSubarbol, char contenido) {
	assert(raizSubarbol != NULL);

	// Primero buscamos en la propia raiz. Si encontramos el contenido ahí, hemos terminado
	if (raizSubarbol->contenido == contenido) return (raizSubarbol);

	// Si no, buscamos en sus subarboles hijos. 
	// Retornamos directamente si lo encontramos en alguno de sus subarboles hijos
	else {
		int numeroSubarboles = getNumeroHijos(raizSubarbol); // Número de hijos de la raizSubarbol
		for (int i = 0; i < numeroSubarboles; i++) {

			// Buscamos recursivamente en uno de los subárboles que cuelgan de la raíz
			Nodo* resultado = buscarNodo(getHijo(raizSubarbol, i), contenido);

			// Si lo hemos encontrado en el subárbol, terminamos
			if (resultado != NULL) return (resultado);
		}
	}

	// Si hemos llegado hasta aquí, no lo hemos encontrado en el subárbol actual
	return (NULL);
}

void Arbol::imprimirRecursivo(Nodo* raizSubarbol, int numeroTabulaciones) {
	assert(raizSubarbol != NULL);
	assert(numeroTabulaciones >= 0);

	// Imprimimos el nodo raiz con el nivel pasado como parametro
	for (int i = 0; i < numeroTabulaciones; i++) cout << "\t";
	cout << raizSubarbol->contenido << endl;

	// Imprimimos cada uno de sus subárboles con una tabulacion mas
	int numeroSubarboles = getNumeroHijos(raizSubarbol); // Número de hijos de la raizSubarbol
	for (int i = 0; i < numeroSubarboles; i++) imprimirRecursivo(getHijo(raizSubarbol, i), numeroTabulaciones + 1);
}

void Arbol::eliminarSubarbol(Nodo* raizSubarbol) {
	assert(raizSubarbol != NULL);

	// Primero eliminamos los hijos, si los hay. Lo hacemos desde el último hasta el primero
	int numeroSubarboles = getNumeroHijos(raizSubarbol); // Número de hijos de la raizSubarbol
	for (int i = numeroSubarboles - 1; i >= 0; i--) {

		// Obtenemos el hijo que queremos borrar
		Nodo* hijoActual = getHijo(raizSubarbol, i);

		// Si el hijoActual es primogénito (e hijo único), hacemos que su padre ya no apunte a él
		// Si no, hacemos que su hermano izquierdo ya no apunte a él.
		if (i == 0) hijoActual->padre->hijoIzquierdo = NULL;
		else getHijo(raizSubarbol, i - 1)->hermanoDerecho = NULL;

		// Finalmente, borramos al hijoActual
		eliminarSubarbol(hijoActual);
	}

	// Finalmente eliminamos la raiz
	// Los punteros hasta este nodo (de su padre y de su hijo izquierdo) no los tocamos
	// (asumimos que quien llame a eliminarSubarbol los pondrá a NULL antes o después de llamar a la funcion)
	delete raizSubarbol;
}

Arbol::Arbol(char contenidoRaiz) {
	raiz = new Nodo;
	raiz->contenido = contenidoRaiz;
	raiz->padre = NULL;
	raiz->hermanoDerecho = NULL;
	raiz->hijoIzquierdo = NULL;
	n = 1;
}

void Arbol::insertar(char nuevoElemento, char elementoPadre) {
	Nodo* padre = buscarNodo(raiz, elementoPadre); // Buscamos el futuro padre del nodo que vamos a insertar

	assert(padre != NULL); // El padre debe existir en el arbol
	assert(n > 0); // El arbol no puede estar vacio

	// Creamos el nuevo nodo que contendrá lo que queremos insertar en el árbol
	Nodo* nuevoNodo = new Nodo;
	nuevoNodo->contenido = nuevoElemento;
	nuevoNodo->padre = padre;
	nuevoNodo->hijoIzquierdo = NULL;
	nuevoNodo->hermanoDerecho = NULL; // Lo insertamos como último hijo de su padre

	// Hacemos que el nodo recién insertado sea el último hijo de su padre	
	int numeroHijos = getNumeroHijos(padre); // Numero de hijos que tiene el padre, antes de insertar el nuevo nodo
	if (numeroHijos == 0) padre->hijoIzquierdo = nuevoNodo; // Si el padre no tiene hijos, somos su primer hijo
	else {
		Nodo* ultimoHijo = getHijo(padre, numeroHijos - 1); // Ultimo hijo del padre, antes de insertar el nuevo nodo
		ultimoHijo->hermanoDerecho = nuevoNodo; // Hacemos que el último hijo nos apunte, para que ahora lo seamos nosotros
	}

	n++;
}

void Arbol::imprimir() {
	assert(n > 0);
	imprimirRecursivo(raiz, 0);
}

Arbol::~Arbol() {
	assert(n > 0);
	assert(raiz != NULL);
	eliminarSubarbol(raiz);
}

// Numero de posiciones en que se incrementa/decrementa la capacidad de la ListaContigua cada vez que es necesario
// Precondición: INCREMENTO >= 1
#define INCREMENTO 2

// Clase que representa a una lista contigua en memoria y cuya capacidad se redimensiona automáticamente
// de modo que el usuario no tiene que preocuparse por su capacidad
class ListaContigua
{
	// Puntero que apuntará a la zona de memoria en donde empieza la ListaContigua
	int* vector;

	// Numero actual de elementos que tiene la ListaContigua
	// Precondición: n>=0
	int n;

	// Capacidad actual de la ListaContigua
	// Precondiciones: capacidad >= n
	int capacidad;

	// Nos dice si la ListaContigua está llena o no.
	// Retorno: verdadero si está llena, falso si no está llena
	// Complejidad temporal: O(1)
	bool isLlena();

public:

	// Constructor. Crea una ListaContigua de tamaño 0
	// Complejidad temporal: O(1)
	ListaContigua();

	// Devuelve un elemento de la ListaContigua
	// Parámetro: la posición del elemento
	// Retorno: el elemento encontrado en esa posición
	// Precondiciones: posicion en [0, n-1]
	// Complejidad temporal: O(1)
	int getValor(int posicion);

	// Modifica un elemento de la ListaContigua
	// Parámetros:
	// - posicion: la posición del elemento que queremos modificar
	// - nuevoValor: el nuevo valor del elemento
	// Precondiciones:
	// - posicion en [0, n-1]
	// Complejidad temporal: O(1)
	void setValor(int posicion, int nuevoValor);

	// Devuelve el tamaño actual de la ListaContigua
	// Retorno: número actual de elementos de la ListaContigua
	// Complejidad temporal: O(1)
	int getN();

	// Devuelve la capacidad actual de la ListaContigua
	// Retorno: número máximo que actualmente podría contener la ListaContigua
	// Complejidad temporal: O(1)
	int getCapacidad();

	// Inserta un nuevo elemento en la última posición de la ListaContigua, 
	// ampliando previamente la capacidad si es necesario
	// Parámetros:
	// - nuevoValor: el nuevo elemento que queremos poner
	// Complejidad temporal: O(n)
	void insertarAlFinal(int nuevoValor);

	// Elimina el elemento de la última posición de la ListaContigua,
	// disminuyendo posteriormente la capacidad si es necesario
	// Complejidad temporal: O(1)
	void eliminarAlFinal();

	// Inserta un nuevo elemento en una posición de la lista, dejando primero un hueco para meterlo ahí
	// Los elementos que había desde la posición hasta el final de la ListaContigua se desplazarán una posición a la derecha
	// Parámetros:
	// - posición: la posición en donde queremos poner el nuevo elemento. Si es 0 se inserta al principio, si es n se inserta al final
	// - nuevoValor: el nuevo elemento que queremos poner
	// Precondiciones:
	// - posicion en [0, n]
	// Complejidad temporal: O(n)
	void insertar(int posicion, int nuevoValor);

	// Elimina un elemento en una posición dada.
	// Los elementos que había desde posicion+1 hasta el final de la ListaContigua se desplazarán una posición a la izquierda
	// Parámetros:
	// - posicion: la posición del elemento que queremos borrar. Si es 0 se elimina el primero y si es n-1 se elimina el último
	// Precondiciones:
	// - posicion en [0, n-1]
	// Complejidad temporal: O(n)
	void eliminar(int posicion);

	// Concatena una lista al final de la lista actual. 
	// Cada uno de los elementos de la lista a concatenar se copian, en orden, al final de la lista actual
	// Parámetro: puntero a la lista cuyos elementos queremos concatenar al final de nuestra lista
	// Precondición: listaAConcatenar!=NULL
	// Complejidad temporal: O(n+m), siendo m = listaAConcatenar.getN()
	void concatenar(ListaContigua* listaAConcatenar);

	// Busca la posición de un elemento en la ListaContigua
	// Parámetro: el elemento a buscar
	// Retorno: posición del elemento (de 0 a n-1) si se encuentra, o -1 en caso contrario
	// Complejidad temporal: O(n)
	int buscar(int elementoABuscar);

	// Destructor. Libera memoria
	// Complejidad temporal: O(1)
	~ListaContigua();
};

bool ListaContigua::isLlena() {
	return (n == capacidad);
}

ListaContigua::ListaContigua() {
	vector = NULL; // No hay que reservar memoria ya que la ListaContigua se crea vacía en un principio
	n = 0;
	capacidad = 0;
}

int ListaContigua::getValor(int posicion) {
	assert(posicion >= 0 && posicion <= n - 1);
	return (vector[posicion]);
}

void ListaContigua::setValor(int posicion, int nuevoValor) {
	assert(posicion >= 0 && posicion <= n - 1);
	vector[posicion] = nuevoValor;
}

int ListaContigua::getN() {
	return (n);
}

int ListaContigua::getCapacidad() {
	return (capacidad);
}

void ListaContigua::insertarAlFinal(int nuevoValor) {
	insertar(n, nuevoValor);
}

void ListaContigua::eliminarAlFinal() {
	eliminar(n - 1);
}

void ListaContigua::insertar(int posicion, int nuevoValor) {
	assert(posicion >= 0 && posicion <= n);

	// Si la ListaContigua está ya llena, antes de insertar ampliamos su capacidad en INCREMENTO
	if (isLlena()) {
		vector = (int*)realloc(vector, sizeof(int) * (capacidad + INCREMENTO));
		capacidad += INCREMENTO;
	}

	// Dejamos hueco para el nuevo elemento, desplazando a la derecha los que hay a partir de posicion hasta el final
	memmove(&vector[posicion + 1], &vector[posicion], sizeof(int) * (n - posicion));

	// Metemos el nuevo elemento
	n++;
	setValor(posicion, nuevoValor);
}

void ListaContigua::eliminar(int posicion) {
	assert(posicion >= 0 && posicion <= n - 1);

	// Tapamos el hueco dejado por el elemento eliminado. Para ello, desplazamos a la izquierda los
	// elementos que hay a partir de posicion+1 hasta el final
	memmove(&vector[posicion], &vector[posicion + 1], sizeof(int) * (n - posicion - 1));
	n--;

	// Si la capacidad sobrante es demasiada (2*INCREMENTO), la reducimos en INCREMENTO unidades
	if (capacidad - n == 2 * INCREMENTO) {
		vector = (int*)realloc(vector, sizeof(int) * (capacidad - INCREMENTO));
		capacidad -= INCREMENTO;
	}

}

void ListaContigua::concatenar(ListaContigua* listaAConcatenar) {
	assert(listaAConcatenar != NULL);

	// Tamaño de la lista a concatenar. Por convención, cuando tenemos
	// dos listas, el tamaño de una es "n" y el de la otra es "m"
	int m = listaAConcatenar->getN();

	// Primero vamos a ampliar la capacidad para asegurarnos de que los
	// nuevos elementos quepan. Para curarnos en salud, ampliamos la 
	// capacidad en el tamaño de la listaAConcatenar
	// Complejidad temporal O(n) 
	vector = (int*)realloc(vector, sizeof(int) * (capacidad + m));
	capacidad += m;

	// Vamos insertando al final elemento a elemento. Fíjate en que insertar un elemento al final
	// es O(1) si no tenemos que ampliar la capacidad (la cual ya está ampliada)
	// Complejidad temporal O(m)
	for (int i = 0; i < m; i++) {
		insertarAlFinal(listaAConcatenar->getValor(i));
	}
}

int ListaContigua::buscar(int elementoABuscar) {
	int posicion = 0; // Posición actual en donde buscamos
	bool encontrado = false; // Nos indica si hemos encontrado o no el elemento

	// Buscamos el elemento hasta que lo encontremos o hasta que lleguemos al final
	while (!encontrado && posicion < n) {
		if (vector[posicion] == elementoABuscar) encontrado = true;
		posicion++;
	}

	// Devolvemos la posición si lo hemos encontrado, o -1 en caso contrario
	if (encontrado) return (posicion - 1);
	else return (-1);
}


ListaContigua::~ListaContigua() {
	free(vector);
}

// Grafo dirigido, no acíclico, no multigrafo, pseudografo, no necesariamente conexo, no etiquetado
// Implementado con matriz de adyacencia
class Grafo
{
private:

	ListaContigua* matriz; // Apuntador al comienzo de un array de objetos de tipo lista. Cada uno será una fila de la matriz de adyacencia
	int n; // Numero de nodos
	string nombresNodos; // Lista de nombres de los nodos. Como el nombre de cada nodo es un carácter, la lista es un string

	// Comprobamos si existe un arco entre dos nodos
	// Parámetros: 
	// - indiceNodoOrigen: el indice del nodo origen
	// - indiceNodoDestino: el indice del nodo destino
	// Retorno: true si existe el arco, false si no
	// Precondición: indiceNodoOrigen e indiceNodoDestino pertenece a [0, n-1]
	// Complejidad temporal: O(1)
	bool existeArco(int indiceNodoOrigen, int indiceNodoDestino);

	// Comprueba si existe un nodo en el grafo
	// Parámetro: nombre del nodo que queremos comprobar si está en el grafo
	// Retorno: true si el nodo existe, false si no
	// Complejidad temporal: O(n) porque recorremos el vector de nombres para encontrar el nodo (búsqueda secuencial, pues los nodos están desordenados)
	bool existeNodo(char nombreNodo);

	// Obtiene el indice de un nodo (número de columna o fila de la matriz de adyacencia en donde está)
	// Parámetro: nombre del nodo cuyo índice se quiere obtener
	// Retorno: el índice del nodo (de 0 a n-1)
	// Precondición: el nodo cuyo nombre se proporciona existe dentro del grafo
	// Complejidad temporal: O(n) porque buscamos secuencialmente el nodo en la lista de nombres de nodos
	int obtenerIndice(char nombreNodo);

	// Devuelve el recorrido en profundidad del grafo
	// Parámetros: 
	// - índice del nodo inicial por el que empezar
	// - vistos: array en el cual en cada posicion es true si el nodo de esa posición ya ha sido visto, o false en caso contrario
	// Retorno: lista de caracteres con el recorrido en profundidad
	// Precondiciones: indiceNodoInicial pertenece a [0, n-1], vistos != NULL
	// Complejidad temporal: O(n^2) porque hay que sacar todos los nodos a una lista, y cada uno de ellos lo añadimos 
	// al final de la lista (añadir al final es O(n))
	string recorrerEnProfundidadRecursivo(int indiceNodoInicial, bool* vistos);

	// Obtiene el numero de arcos de entrada de un nodo
	// Parámetro: posicion interna del nodo
	// Retorno: numero de arcos de entrada del nodo
	int getGradoEntrada(int posicionNodo);

	// Obtiene una lista con las posiciones internas de los nodos a los que se puede llegar desde el especificado
	// Parámetro: posición interna del nodo origen desde el que parten los arcos a los nodos destinos
	// Resultado: lista contigua con las posiciones de todos los nodos destinos a los que se puede llegar directamente
	//            desde el nodo origen especificado
	ListaContigua* getPosicionesAdyacentes(int posicionNodoOrigen);

	// Convierte el grafo en un árbol, recursivamente
	// Parámetros:
	// - indiceNodoInicial: posición interna del nodo por el que empezar
	// - vistos: array booleano que nos indica si cada nodo del grafo ya ha sido visto o no
	// - arbol: puntero al arbol que vamos construyendo recursivamente
	void convertirEnArbolRecursivo(int indiceNodoInicial, bool* vistos, Arbol* arbol);

public:

	// Crea un grafo vacío
	// Complejidad temporal: O(1)
	Grafo();

	// Imprime el grafo por pantalla en forma de matriz de adyacencia, imprimiendo títulos de las columnas y filas
	// OJO: este método viola el principio de separación entre interfaz y modelo
	// Complejidad temporal: O(n^2) porque imprimimos todos los posibles arcos
	void imprimir();

	// Inserta un nodo desconectado en el grafo
	// Parámetro: nombre del nuevo nodo que queremos insertar
	// Precondición: no existe ningún nodo en el grafo que tenga dicho nombre
	// Complejidad temporal: O(n^2) porque por dentro usamos una matriz temporal en la cual copiamos la matriz original 
	void insertarNodo(char nombreNodo);

	// Inserta un arco en el grafo
	// Parámetros: nombres del nodo origen y del nodo destino del arco que queremos añadir
	// Precondición: los dos nodos deben existir previamente en el grafo
	// Complejidad temporal: O(n) porque hay que obtener el indice del nodo a partir de su nombre
	void insertarArco(char nodoOrigen, char nodoDestino);

	// Borra un arco del nodo
	// Parámetros: nombres del nodo origen y del nodo destino del arco que queremos eliminar
	// Precondición: los dos nodos deben existir previamente en el grafo
	// Complejidad temporal: O(n) porque hay que obtener el indice del nodo a partir de su nombre
	void borrarArco(char nodoOrigen, char nodoDestino);

	// Borrar un nodo del grafo. Borramos automáticamente todos los arcos que llegan y que parten del nodo a eliminar
	// Parámetro: nombre del nodo a eliminar
	// Precondición: el nodo debe previamente existir
	// Complejidad temporal: O(n^2) porque por dentro usamos una matriz temporal en la cual copiamos la matriz original 
	void borrarNodo(char nombreNodo);

	// Devuelve el recorrido en profundidad del grafo
	// Parámetro: 
	// - nombre del nodo por el que empezar el recorrido
	// Retorno: puntero a comienzo de zona de memoria en donde se guarda el recorrido en forma de array de caracteres,
	// terminado por el caracter nulo '\0'
	// Precondición: el nodo de comienzo debe existir en el grafo
	// Complejidad temporal: O(n^2) porque hay que sacar todos los nodos a una lista, y cada uno de ellos lo añadimos 
	// al final de la lista (añadir al final es O(n))
	char* recorrerEnProfundidad(char nodoInicial);

	// Devuelve el número de nodos del grafo
	// Retorno: número de nodos del grafo
	// Complejidad temporal: O(1)
	int getN();

	// Destruye el grafo y libera la memoria de todos sus nodos
	// Complejidad temporal: O(n) porque hay que llamar al destructor de cada fila, el cual es O(1)
	~Grafo();

	// Convierte el grafo en árbol
	// Parámetro: contenido del nodo del grafo que será la raíz del árbol
	// Retorno: puntero al árbol resultado
	Arbol* convertirEnArbol(char raiz);

	// Obtiene el recorrido en anchura del grafo
	// Parámetro: contenido del nodo por el que empezar
	// Retorno: string con el recorrido en anchura
	string recorrerAnchura(char nodoInicial);

	// Obtiene el recorrido topologico, destruyendo el grafo en el proceso
	// Retorno: string con el recorrido topológico
	string recorrerTopologico();

};

bool Grafo::existeArco(int indiceNodoOrigen, int indiceNodoDestino) {
	assert(indiceNodoOrigen >= 0 && indiceNodoOrigen <= n - 1);
	assert(indiceNodoDestino >= 0 && indiceNodoDestino <= n - 1);
	if (matriz[indiceNodoOrigen].getValor(indiceNodoDestino) > 0) return true;
	else return false;
}

bool Grafo::existeNodo(char nombreNodo) {
	// Si find() no encuentra el caracter, devuelve string::npos, que suele ser -1.
	// Si lo encuentra, devuelve su posición en el string (empezando por 0)
	if (string::npos == nombresNodos.find(nombreNodo)) return false;
	else return true;
}

int Grafo::obtenerIndice(char nombreNodo) {
	assert(existeNodo(nombreNodo));
	// Si find() no encuentra el caracter, devuelve string::npos, que suele ser -1.
	// Si lo encuentra, devuelve su posición en el string (empezando por 0)
	int posicion = nombresNodos.find(nombreNodo);
	return (posicion);
}

string Grafo::recorrerEnProfundidadRecursivo(int indiceNodoInicial, bool* vistos) {
	assert(indiceNodoInicial >= 0 && indiceNodoInicial <= n - 1);
	assert(vistos != NULL);

	string resultado; // Resultado que contendrá el recorrido
	char nombreNodoInicial = nombresNodos[indiceNodoInicial]; // Nombre del nodo inicial

	resultado.append(1, nombreNodoInicial); // Añadimos al recorrido el nodo inicial
	vistos[indiceNodoInicial] = true; // Guardamos que el nodo inicial ya ha sido visto

	// Vemos los nodos inmediatamente consecutivos al inicial y nos llamamos recursivamente
	// con cualquiera de ellos que aún no hayamos visto
	for (int indiceNodoDestino = 0; indiceNodoDestino < n; indiceNodoDestino++) {

		// Si el posible nodo consecutivo no está aún visto
		if (vistos[indiceNodoDestino] == false) {

			// Si existe un arco del nodo origen al nodo destino "no visto", nos llamamos recursivamente
			// con el nodo destino como nuevo origen
			if (existeArco(indiceNodoInicial, indiceNodoDestino))
				resultado.append(recorrerEnProfundidadRecursivo(indiceNodoDestino, vistos));
		}
	}
	return (resultado);
}

Grafo::Grafo() {
	matriz = NULL;
	n = 0;
}

void Grafo::imprimir() {

	// Si el grafo está vacio, imprimimos mensaje informativo
	if (n == 0) cout << "La matriz esta vacia\n";

	// En caso contrario, imprimimos la matriz de adyacencia bien alineada
	else {

		// Imprimimos la primera línea de la matriz, con los nombres de los nodos
		cout << "  "; // Imprimimos espacio de la esquina superior izquierda de la matriz	
		for (int i = 0; i < n; i++) cout << nombresNodos[i] << " "; // Imprimimos el nombre de los nodos en las columnas
		cout << endl;

		// Imprimimos las filas
		for (int i = 0; i < n; i++) {
			cout << nombresNodos[i] << " "; // Imprimimos el nombre del nodo de la fila
			for (int j = 0; j < n; j++) cout << existeArco(i, j) << " ";
			cout << endl;
		}
		cout << endl;
	}
}

void Grafo::insertarNodo(char nombreNodo) {
	assert(!existeNodo(nombreNodo));

	nombresNodos.append(1, nombreNodo); // Insertamos el nuevo nombre en la lista de nombres

	// Añadimos una columna mas a todas las filas que ya hay. Ponemos 0 en ella
	// Complejidad temporal: O(n^2)
	// Complejidad espacial: O(n), porque cada vez que insertamos en una fila es posible que haya que copiarla temporalmente en otro lugar
	for (int i = 0; i < n; i++) matriz[i].insertar(n, 0);

	// Creamos la nueva fila y la rellenamos con ceros
	// Complejidad temporal y espacial: O(n)
	ListaContigua* nuevaFila = new ListaContigua;
	for (int i = 0; i <= n; i++) nuevaFila->insertar(0, 0);

	// Creamos espacio para la nueva matriz de adyacencia
	// Creamos n+1 listas vacías. Complejidad temporal y espacial: O(n)
	ListaContigua* nuevaMatriz = new ListaContigua[n + 1];

	// Copiamos la antigua matriz y la nueva fila en el nuevo espacio
	// Complejidad temporal: O(n^2)
	// Complejidad espacial: O(n^2), porque creamos n filas temporales, cada una con n columnas
	for (int i = 0; i < n; i++) nuevaMatriz[i].concatenar(&matriz[i]);
	nuevaMatriz[n].concatenar(nuevaFila);

	// Borramos el antiguo espacio y ajustamos variables
	delete[] matriz;
	delete nuevaFila;
	matriz = nuevaMatriz;

	// Incrementamos n
	n++;
}

void Grafo::insertarArco(char nodoOrigen, char nodoDestino) {
	assert(existeNodo(nodoOrigen));
	assert(existeNodo(nodoDestino));
	int posicionNodoOrigen = obtenerIndice(nodoOrigen);
	int posicionNodoDestino = obtenerIndice(nodoDestino);
	matriz[posicionNodoOrigen].setValor(posicionNodoDestino, 1);
}

void Grafo::borrarArco(char nodoOrigen, char nodoDestino) {
	assert(existeNodo(nodoOrigen));
	assert(existeNodo(nodoDestino));
	int posicionNodoOrigen = obtenerIndice(nodoOrigen);
	int posicionNodoDestino = obtenerIndice(nodoDestino);
	matriz[posicionNodoOrigen].setValor(posicionNodoDestino, 0);
}

void Grafo::borrarNodo(char nombreNodo) {
	assert(existeNodo(nombreNodo));

	int posicionNodo = obtenerIndice(nombreNodo); // Indice del nodo
	nombresNodos.erase(posicionNodo, 1); // Borrar el nombre de la lista de nombres

	// Creo un nuevo espacio para la matriz resultante de borrar la fila del nodo
	ListaContigua* nuevaMatriz = new ListaContigua[n - 1];

	// Copiamos la antigua matriz (excepto la fila borrada) en el nuevo espacio
	for (int i = 0; i < posicionNodo; i++) nuevaMatriz[i].concatenar(&matriz[i]);
	for (int i = posicionNodo + 1; i < n; i++) nuevaMatriz[i - 1].concatenar(&matriz[i]);

	// Actualizamos n
	n--;

	// Borramos la columna
	for (int i = 0; i < n; i++) nuevaMatriz[i].eliminar(posicionNodo);

	// Borramos el antiguo espacio de la matriz y reasignamos variables
	delete[] matriz;
	matriz = nuevaMatriz;
}

char* Grafo::recorrerEnProfundidad(char nodoInicial) {
	assert(existeNodo(nodoInicial));

	// Indice del nodo inicial
	int indiceNodoInicial = obtenerIndice(nodoInicial);

	// Creamos el array que nos dice si un nodo ha sido visto o no, y lo inicializamos a falso
	bool* vistos = (bool*)malloc(sizeof(bool) * n); // Array que nos dice si un nodo ha sido visto o no
	for (int i = 0; i < n; i++) vistos[i] = false;

	// Recorremos en profundidad el grafo y guardamos el tamaño del recorrido
	string resultado = recorrerEnProfundidadRecursivo(indiceNodoInicial, vistos);
	int longitudRecorrido = resultado.size(); // Numero de nodos que tiene el recorrido

	// Liberamos el array de vistos
	free(vistos);

	// Copiamos el string resultado en un array de caracteres. Dejamos un espacio mas
	// para el caracter nulo que hay que poner al final del array para que cout sepa donde parar
	char* recorrido = (char*)malloc(sizeof(char) * (longitudRecorrido + 1)); // Recorrido en forma de array de caracteres (será lo que devuelva la función)
	memcpy(recorrido, resultado.data(), longitudRecorrido * sizeof(char)); // Copiamos el array interno del string en el array de caracteres que vamos a devolver
	recorrido[longitudRecorrido] = '\0'; // Ponemos el caracter nulo al final

	// Devolvemos el recorrido
	return (recorrido); // Devolvemos el array de caracteres resultado del recorrido en profundidad
}

int Grafo::getN() {
	return (n);
}

Grafo::~Grafo() {
	delete[] matriz;
}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                RELLENAR A PARTIR DE AQUÍ (las complejidades pedidas ponlas también aquí, antes de la definición)           //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////



int Grafo::getGradoEntrada(int posicionNodo) {

	int grado = 0;

	for (int i = 0; i < n; i++) {
		if (matriz[i].getValor(posicionNodo) != 0) {
			grado++;
		}
	}

	return grado;
}

ListaContigua* Grafo::getPosicionesAdyacentes(int posicionNodoOrigen) {

	ListaContigua* posicionesAdyacentes = new ListaContigua();

	for (int i = 0; i < n; i++) {
		if (matriz[posicionNodoOrigen].getValor(i) != 0) {
			posicionesAdyacentes->insertarAlFinal(i);
		}
	}

	return posicionesAdyacentes;
}

void Grafo::convertirEnArbolRecursivo(int indiceNodoInicial, bool* vistos, Arbol* arbol) {

	vistos[indiceNodoInicial] = true;

	ListaContigua* adyacentes = getPosicionesAdyacentes(indiceNodoInicial);
	int nAdyacentes = adyacentes->getN();



	for (int i = 0; i < nAdyacentes; i++) {
		if (!vistos[adyacentes->getValor(i)]) {
			arbol->insertar(nombresNodos[adyacentes->getValor(i)], nombresNodos[indiceNodoInicial]);
			convertirEnArbolRecursivo(adyacentes->getValor(i), vistos, arbol);
		}
	}
}

Arbol* Grafo::convertirEnArbol(char raiz) {
	assert(existeNodo(raiz));

	int posicionOrigen = obtenerIndice(raiz);
	bool* vistos = (bool*)malloc(sizeof(bool) * n);

	for (int i = 0; i < n; i++) {
		vistos[i] = false;
	}

	Arbol* arbol = new Arbol(raiz);

	convertirEnArbolRecursivo(posicionOrigen, vistos, arbol);

	
	return arbol;

}

string Grafo::recorrerAnchura(char nodoInicial) {
	
	char* cola = (char *)malloc(sizeof(char) * n);

	cola[0] = nodoInicial;
	int inicioCola = 0;
	int finalCola = 0;

	int* vistos = (int*)malloc(sizeof(int) * n); 

	for (int i = 0; i < n; i++) {
		vistos[i] = false;
	}

	vistos[obtenerIndice(nodoInicial)];

	string recorrido;

	ListaContigua *adyacentes;
	
	while (finalCola >= inicioCola) {
		
		recorrido.append(1, cola[inicioCola]); //añadimos el nodo a la lista
		adyacentes = getPosicionesAdyacentes(obtenerIndice(cola[inicioCola])); //array de adyacentes al nodo

		inicioCola++; //elimino el caracter de la cola

		for (int i = 0; i < adyacentes->getN(); i++) { //por cada nodo adyacente no visitado metemos el nodo a la cola y lo marcamos como visitado
			if (!vistos[adyacentes->getValor(i)]) {
				finalCola++;
				cola[finalCola] = nombresNodos[adyacentes->getValor(i)];

				vistos[adyacentes->getValor(i)] = true;
			}

		}

	}

	return recorrido;

}

string Grafo::recorrerTopologico() {
	
	string recorrido;

	int posicionNodoSinArcosEntrantes = -1;
	
	bool encontrado = false;
	int i = 0;

	while (!encontrado && i < n) {
		if (getGradoEntrada(i) == 0) {
			posicionNodoSinArcosEntrantes = i;
			encontrado = true;
		}
		i++;
	}

	if (encontrado) {
		recorrido.append(1, nombresNodos[posicionNodoSinArcosEntrantes]);

		borrarNodo(nombresNodos[posicionNodoSinArcosEntrantes]);

		return recorrido.append(recorrerTopologico());
	}
	else {
		return recorrido;
	}




}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                             FIN DE LA PARTE QUE HAY QUE RELLENAR                                           //
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




int main() {
	Grafo g; // Grafo con el que trabajamos
	int opcion; // Opcion de menu elegida

	do {

		char nodo1, nodo2; // Variables para usar en las opciones del menu
		Arbol* a; // Variable para la opción 3

		cout << "0. Salir" << endl;
		cout << "1. Insertar nodo" << endl;
		cout << "2. Insertar arco" << endl;
		cout << "3. Convertir en arbol e imprimirlo" << endl;
		cout << "4. Recorrido en anchura e imprimirlo" << endl;
		cout << "5. Recorrido topologico recursivo e imprimirlo" << endl;
		cout << "6. Imprimir grafo" << endl;
		cout << "Introduce opcion: ";
		cin >> opcion;

		switch (opcion) {
		case (0): // Terminar programa
			break;
		case (1):
			cout << "Escriba el nuevo nodo (una letra): ";
			cin >> nodo1;
			g.insertarNodo(nodo1);
			break;
		case (2):
			cout << "Escriba el nodo origen (una letra): ";
			cin >> nodo1;
			cout << "Escriba el nodo destino (una letra): ";
			cin >> nodo2;
			g.insertarArco(nodo1, nodo2);
			break;
		case (3):
			cout << "Escriba el nodo por el que empezar (una letra): ";
			cin >> nodo1;
			a = g.convertirEnArbol(nodo1);
			a->imprimir();
			delete(a);
			break;
		case (4):
			cout << "Escriba el nodo por el que empezar (una letra): ";
			cin >> nodo1;
			cout << "Su recorrido en anchura es: " << g.recorrerAnchura(nodo1) << endl;
			break;
		case (5):
			cout << "Recorrido topologico recursivo: " << g.recorrerTopologico() << endl;
			break;
		case (6):
			g.imprimir();
			break;
		default:
			cout << "Opcion incorrecta" << endl;
			break;
		}
	} while (opcion != 0);
}
