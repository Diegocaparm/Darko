#include "Esfera.h"
#include "Vector2D.h"
#include "freeglut.h"

Esfera::Esfera()
{
	rojo = 0;
	verde = 0;
	azul = 255;
	radio = 1.5f;
	aceleracion.y = -9.8f;
	posicion.x = 2;
	posicion.y = 4;
}

void Esfera::dibuja()
{
	glColor3ub(rojo, verde, azul);
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, 0);
}

void Esfera::mueve(float t)
{
	posicion.x = posicion.x + velocidad.x * t + 0.5f * aceleracion.x * t * t;
	posicion.y = posicion.y + velocidad.y * t + 0.5f * aceleracion.y * t * t;
	velocidad.x = velocidad.x + aceleracion.x * t;
	velocidad.y = velocidad.y + aceleracion.y * t;
}

void Esfera::setColor(unsigned char r, unsigned char g, unsigned char b) {
	rojo = r;
	verde = g;
	azul = b;
}

void Esfera::setRadio(float r) {
	radio = r;
}

void Esfera::setPos(float x, float y) {
	posicion.x = x;
	posicion.y = y;
}
