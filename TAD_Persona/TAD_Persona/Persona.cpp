#include "Persona.h"
#include "string.h"


Persona::Persona(char* nombrePersona) {
	memcpy(nombre, nombrePersona, 20* sizeof(char));
	edad = 0;
}
void Persona::cumplirAno() {
	edad++;

}
void Persona::hacerDeporte() {
	if (edad > 20) {
		edad--;
	}
}
int Persona::verEdad() {
	return edad;

}
char* Persona::verNombre() {
	return nombre;

}