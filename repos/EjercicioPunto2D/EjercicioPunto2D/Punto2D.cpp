#include "Punto2D.h"
#include "iostream"
#include "math.h"

using namespace std;

Punto2D::Punto2D(float x, float y) {
	this->x = x;
	this->y = y;
}


void Punto2D::desplazar(float incrX, float incrY) {
	x = x + incrX;
	y = y + incrY;
}

float Punto2D::distanciaCentro() {
	return (sqrt((x*x + y*y)));

}
void Punto2D::imprimePunto() {
	cout << "El punto es (" << x << ", " << y << ")" << "\n";

}