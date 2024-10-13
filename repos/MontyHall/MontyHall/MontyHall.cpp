// MontyHall.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <cassert>
#define PUERTAS 3
#define REPETIR 10000
#define CAMBIAR_PUERTA false

using namespace std;

int main()
{
    assert(PUERTAS > 1);
    int contadorGanados = 0;
    int contadorPerdidos = 0;

    for (int j = 0; j < REPETIR; j++) {
        int indicePuertaPremio = rand() % PUERTAS;
        cout << indicePuertaPremio << endl;

        int indicePuertaSeleccionada = rand() % PUERTAS;
        bool cambiar = CAMBIAR_PUERTA; 
        int indicePuertaPosibleCambio;


        if (indicePuertaPremio == indicePuertaSeleccionada) {
            bool diferentes = false;

            while (!diferentes) {
                indicePuertaPosibleCambio = rand() % PUERTAS;
                if (indicePuertaPosibleCambio != indicePuertaSeleccionada) {
                    diferentes = true;
                }
            }

        }
        else {
            indicePuertaPosibleCambio = indicePuertaPremio;
        }

        if (cambiar) {
            indicePuertaSeleccionada = indicePuertaPosibleCambio;
        }


        if (indicePuertaSeleccionada == indicePuertaPremio) {
            cout << "Has ganado el premio" << endl;
            contadorGanados++;
        }
        else {
            cout << "No has ganado el premio" << endl;
            contadorPerdidos++;
        }


    }

    double porcentajeAciertos = ((double)contadorGanados / (double)(contadorGanados + contadorPerdidos)) * 100;

    cout << "\nEl porcentaje de acierto es " << porcentajeAciertos;





}

// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
