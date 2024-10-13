#pragma once

class Persona {
private:
	char nombre[20];
	int edad;

public:
	Persona(char* nombrePersona);
	void cumplirAno();
	void hacerDeporte();
	int verEdad();
	char* verNombre();

};