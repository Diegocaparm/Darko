#include "DispEnem.h"
#include "Vector2D.h"
#include "freeglut.h"
#include "EnemigoDisp.h"

DispEnem::DispEnem() {
	radio = 0.15f;
	aceleracion.x = 0.0f;
	aceleracion.y = -0.5;
}

void DispEnem::dibuja()
{
	glColor3f(1.0f, 0.0f, 0.0f);
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0); //disparo
	glutSolidSphere(radio, 20, 20);
	glTranslatef(0, -posicion.y, 0);
	glPopMatrix();
}

void DispEnem::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * 0.5f * t * t;
	velocidad = velocidad + aceleracion * t;
}

void DispEnem::setPos(float ix, float iy) {
	posicion.x = ix;
	posicion.y = iy;
}

void DispEnem::setColor(Byte r, Byte g, Byte b) {
	color.r = r;
	color.g = g;
	color.b = b;
}
