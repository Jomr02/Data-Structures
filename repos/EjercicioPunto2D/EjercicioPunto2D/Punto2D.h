#pragma once
class Punto2D
{

private:
	float x;
	float y;



public:
	Punto2D(float x, float y);
	void desplazar(float incrX, float incrY);
	float distanciaCentro();
	void imprimePunto();

};

