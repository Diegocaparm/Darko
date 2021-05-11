#include "Esfera.h"
#include "Vector2D.h"
#include "freeglut.h"

Esfera::Esfera()
{
	radio = 1.5f;
	aceleracion.y = -9.8f;
}

void Esfera::dibuja()
{
	color.ponColor();
	glTranslatef(posicion.x, posicion.y, 0);
	glutSolidSphere(radio, 20, 20);
	glTranslatef(-posicion.x, -posicion.y, 0);
}

void Esfera::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * 0.5f * t * t;
	velocidad = velocidad + aceleracion * t;
}

void Esfera::setColor(Byte r, Byte g, Byte b) {
	color.r = r;
	color.g = g;
	color.b = b;
}

void Esfera::setRadio(float r) {
	radio = r;
}

void Esfera::setPos(float ix, float iy) {
	posicion.x = ix;
	posicion.y = iy;
}

void Esfera::setVel(float vx, float vy)
{
	velocidad.x = vx;
	velocidad.y = vy;
}
