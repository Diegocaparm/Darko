#include "DispTank.h"
#include "Vector2D.h"
#include "freeglut.h"
#include "Tank.h"

DispTank::DispTank() {
	radio = 0.15f;
	aceleracion.x = 0.0f;
	aceleracion.y = -0.5;
	velocidad.x = -2.0f;
	velocidad.y = 0.0f;
}

void DispTank::dibuja()
{
	glColor3f(1.0f, 0.0f, 0.0f);
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0); //disparo
	glutSolidSphere(radio, 20, 20);
	glTranslatef(0, -posicion.y, 0);
	glPopMatrix();
}

void DispTank::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * 0.5f * t * t;
	velocidad = velocidad + aceleracion * t;
}

void DispTank::setPos(float ix, float iy) {
	posicion.x = ix;
	posicion.y = iy;
}

void DispTank::setVel(float vx, float vy) {
	velocidad.x = vx;
	velocidad.y = vy;
}
void DispTank::setColor(Byte r, Byte g, Byte b) {
	color.r = r;
	color.g = g;
	color.b = b;
}