// ExamenExtraordinario.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <cassert>
#include <stdlib.h>
#include <time.h>
#include <chrono>
using namespace std::chrono;


using namespace std;

class PilaContigua {
    int* pila;
    int cima;
    int n;
    int capacidad;
    int base;
    int incremento;

    void ampliaCapacidad(int nuevaCapacidad);

public:
    PilaContigua(int incremento);
    void push(int nuevoElemento);
    int pop();
    int verCima();
    bool esVacia();
    void imprimir();
    ~PilaContigua();

};

PilaContigua::PilaContigua(int incremento) {
    pila = NULL;
    cima = -1;
    n = 0;
    capacidad = 0;
    base = 0;
    this->incremento = incremento;
}

void PilaContigua::ampliaCapacidad(int nuevaCapacidad) {
    assert(nuevaCapacidad >= n);

    pila = (int*)realloc(pila, sizeof(int) * nuevaCapacidad);
    capacidad = nuevaCapacidad;
}

void PilaContigua::push(int nuevoElemento) {

    if (capacidad == n)
        ampliaCapacidad(capacidad + incremento);

    cima++;
    pila[cima] = nuevoElemento;
    n++;
}

int PilaContigua::pop() {
    assert(!esVacia());

    int resultado = pila[cima];
    cima--;

    n--;
    return (resultado);
}

int PilaContigua::verCima() {
    assert(!esVacia());

    return(pila[cima]);
}

bool PilaContigua::esVacia() {
    return (n == 0);
}

void PilaContigua::imprimir() {
    if (esVacia()) {
        cout << "Pila Vacia" << endl;
    }
    else {
        for (int i = 0; i <= cima; i++)
            cout << pila[i] << " ";

    }

    cout << endl;


}

PilaContigua::~PilaContigua() {
    free(pila);
}



void ordenaArray(int* vector, int n, int limiteInferior, int limiteSuperior) {
    //para asegurarnos que los nuemeros del vector estan dentro de los limites
    bool fueraDeLimites = false;

    for (int i = 0; i < n; i++) {
        if (vector[i] < limiteInferior || vector[i] > limiteSuperior) {
            fueraDeLimites = true;
        }
    }

    assert(!fueraDeLimites); 
    
    int* vectorOrdenado = (int*)malloc(sizeof(int) * n);

    int maximo = limiteInferior; 
    int contador = 0;
    int posicionMaximo;

    while (contador < n) {
        maximo = limiteInferior;

        //ordenaremos, buscando en cada iteración el mayor elemento (o el menor si se quiere ordenar de menor a mayor) del array, una vez encontrado se borra y se copia en el array ordenado
        for (int i = 0; i < n; i++) {
            if (vector[i] > maximo) { 
                maximo = vector[i];
                posicionMaximo = i;
                
            }
        }

        vector[posicionMaximo] = limiteInferior - 1; //"borramos" el elemento seleccionado, se puede hacer con memmove pero sería más costoso en tiempo

        vectorOrdenado[contador] = maximo;
        contador++;
    }

    //copiamos el vector ordenado al vector inicial
    for (int i = 0; i < n; i++) {
        vector[i] = vectorOrdenado[i];
    }
    

}


int evaluarPostfijo(string expresion) {

    PilaContigua pila (2);

    int resultado;

    //elementos temporales para operar
    int a;
    int b;
    int charAint;
    char caracter;

    for (int i = 0; i < expresion.size(); i++) {
        if (expresion[i] == '+' || expresion[i] == '*') {
            if (expresion[i] == '+') {
                a = pila.pop();
                b = pila.pop();
                
                resultado = a + b;
                //cout << resultado << endl;
                pila.push(resultado);

            }
            else {
                a = pila.pop();
                b = pila.pop();

                resultado = a * b;
                //cout << resultado << endl;
                pila.push(resultado);
            }

        }
        else if (expresion[i] >= '0' && expresion[i] <= '9') {
            caracter = expresion[i];
            charAint = atoi(&caracter);

            pila.push(charAint);


        }

    }

    return (pila.pop());

}

string generaPostfijo(int tokens) {
    assert(tokens >= 3);

    string postfijo;

    srand(time(NULL));
    int aleatorio;

    int contadorDigitos = 0;
    int contadorOperandos = 0;


    // los dos primeros digitos deben ser numeros en cualquier caso
    for (int i = 0; i < 2; i++) {
        aleatorio = rand() % 10 + 0; //genera numero aleatorio entre 0 y 9

        switch (aleatorio) {
        case (0):
            postfijo.append(1, '0');
            break;
        case (1):
            postfijo.append(1, '1');
            break;
        case (2):
            postfijo.append(1, '2');
            break;
        case (3):
            postfijo.append(1, '3');
            break;
        case (4):
            postfijo.append(1, '4');
            break;
        case (5):
            postfijo.append(1, '5');
            break;
        case (6):
            postfijo.append(1, '6');
            break;
        case (7):
            postfijo.append(1, '7');
            break;
        case (8):
            postfijo.append(1, '8');
            break;
        case (9):
            postfijo.append(1, '9');
            break;
        }

        contadorDigitos++;

    }


    for (int i = 2; i < tokens; i++) {
            //usamos estos limites para que la expresion sea correcta (que no todo sean operando o numeros por ejemplo)
            int limiteDigitos = tokens / 2; 
            int limiteOperandos = limiteDigitos - 2;



            if (contadorDigitos > limiteDigitos) {
                aleatorio = rand() % 2 + 0; //genera numero aleatorio entre 0 y 1

                switch (aleatorio) {
                case (0):
                    postfijo.append(1, '+');
                    break;
                case (1):
                    postfijo.append(1, '*');
                    break;


                    
                }
                contadorOperandos++;
            }
            else if (contadorOperandos > limiteOperandos) {
                aleatorio = rand() % 10 + 0; //genera numero aleatorio entre 0 y 9

                switch (aleatorio) {
                case (0):
                    postfijo.append(1, '0');
                    contadorDigitos++;
                    break;
                case (1):
                    postfijo.append(1, '1');
                    contadorDigitos++;
                    break;
                case (2):
                    postfijo.append(1, '2');
                    contadorDigitos++;
                    break;
                case (3):
                    postfijo.append(1, '3');
                    contadorDigitos++;
                    break;
                case (4):
                    postfijo.append(1, '4');
                    contadorDigitos++;
                    break;
                case (5):
                    postfijo.append(1, '5');
                    contadorDigitos++;
                    break;
                case (6):
                    postfijo.append(1, '6');
                    contadorDigitos++;
                    break;
                case (7):
                    postfijo.append(1, '7');
                    contadorDigitos++;
                    break;
                case (8):
                    postfijo.append(1, '8');
                    contadorDigitos++;
                    break;
                case (9):
                    postfijo.append(1, '9');
                    contadorDigitos++;
                    break;


                }

            }
            else {
                aleatorio = rand() % 12 + 0; //genera numero aleatorio entre 0 y 11

                switch (aleatorio) {
                case (0):
                    postfijo.append(1, '0');
                    contadorDigitos++;
                    break;
                case (1):
                    postfijo.append(1, '1');
                    contadorDigitos++;
                    break;
                case (2):
                    postfijo.append(1, '2');
                    contadorDigitos++;
                    break;
                case (3):
                    postfijo.append(1, '3');
                    contadorDigitos++;
                    break;
                case (4):
                    postfijo.append(1, '4');
                    contadorDigitos++;
                    break;
                case (5):
                    postfijo.append(1, '5');
                    contadorDigitos++;
                    break;
                case (6):
                    postfijo.append(1, '6');
                    contadorDigitos++;
                    break;
                case (7):
                    postfijo.append(1, '7');
                    contadorDigitos++;
                    break;
                case (8):
                    postfijo.append(1, '8');
                    contadorDigitos++;
                    break;
                case (9):
                    postfijo.append(1, '9');
                    contadorDigitos++;
                    break;
                case (10):
                    postfijo.append(1, '+');
                    contadorOperandos++;
                    break;
                case (11):
                    postfijo.append(1, '*');
                    contadorOperandos++;
                    break;

                }


            }
        

    }

    return postfijo;
}

    




int main()
{


    int n;
    int limiteInferior;
    int limiteSuperior;

    cout << "Vamos a ordenar un array de numeros. Introduce n:" << endl;
    cin >> n;
    cout << "Ahora, introduce el limite inferior" << endl;
    cin >> limiteInferior;
    cout << "Ahora, introduce el limite superior" << endl;
    cin >> limiteSuperior;
    cout << "Generando array de numeros aleatorios..." << endl;

    int* vector = (int*)malloc(sizeof(int) * n);

    srand(time(NULL));

    //genera numeros aleatorios entre los limites selccionados
    for (int i = 0; i < n; i++) {
        vector [i] = rand() % limiteSuperior + limiteInferior;
    }

    cout << "\nVector generado aleatoriamente:" << endl;
    //imprime vector
    for (int i = 0; i < n; i++) {
        cout << vector[i] << " ";
    }
    

    auto start = high_resolution_clock::now();
    
    ordenaArray(vector, n, limiteInferior, limiteSuperior);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start); //se puede cambiar microsegundos por otra medida
    cout << " "<<duration.count() << endl;

    cout << "\nVector ordenado:" << endl;

    //imprime vector ordenado
    for (int i = 0; i < n; i++) {
        cout << vector[i] << " ";
    }

    cout << "\nHa tardado en ordenarlos " << duration.count() << " microsegundos "<< endl;

    cout << endl;


    int tokens;
    cout << "Introduce el numero de tokens de la expresion" << endl;
    cin >> tokens;


    string postfijo = generaPostfijo(tokens);
    //string postfijo = "6523+8*+3+*";
    cout << "Expresion generada: \n" << postfijo << endl;

    cout << "\nExpresion evaluada: " << endl;

    cout << evaluarPostfijo(postfijo) << endl;

}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
