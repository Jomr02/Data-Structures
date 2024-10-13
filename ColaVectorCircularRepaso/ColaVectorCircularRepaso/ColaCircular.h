#pragma once

#define INCREMENTO 2


class ColaCircular
{
private:
	char* cola;
	int posPrimerElemento;
	int posUltimoElemento;

	int capacidad;
	int n;


	void modificaCapacidad(int nuevaCapacidad);
	bool esCasillaVacia(int posicion);

public:

	ColaCircular();
	void push(char elemento);
	bool esVacia();
	int pop();
	void imprimir();
	~ColaCircular();


};

