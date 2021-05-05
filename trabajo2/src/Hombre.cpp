#include "Hombre.h"
#include "Vector2D.h"
#include "freeglut.h"

Hombre::Hombre() {
	altura = 1.8f;
	aceleracion.x = aceleracion.y = 0.0f;
}

void Hombre::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(1.0f, 0.0f, 0.0f);
	//glutSolidSphere(altura, 20, 20);
	glRotatef(-90, 1, 0, 0);		//dibujar persona
	glTranslatef(-0.2, 0, 0);
	glutSolidCylinder(0.1, altura / 3, 30, 30);
	glTranslatef(0.4, 0, 0);
	glutSolidCylinder(0.1, altura / 3, 30, 30);
	glTranslatef(-0.2, 0, altura / 3);
	glutSolidCylinder(0.4, altura / 3, 30, 30);
	glTranslatef(0, 0, altura / 2);
	glutSolidSphere(altura / 6, 30, 30);
	glTranslatef(0, 0, -altura * 5 / 6);
	glRotatef(90, 1, 0, 0);

	glPopMatrix();
}

void Hombre::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * 0.5f * t * t;
	velocidad = velocidad + aceleracion * t;


	Vector2D* pp = &posicion, * pv = &velocidad, * pa = &aceleracion;
	if (velocidad.y > 0)	//sentido=0 sube     sentido=1 baja
		sentido = 0;
	else
		sentido = 1;
	if (salto == 0){		//salto=1 puede saltar		salto=0 no puede saltar
		aceleracion.y = 250;
		salto = 1;
	}
	else
		aceleracion.y = -9.8;

	if (velocidad.y == 0) {
		salto = 1;

	}
}

void Hombre::setColor(Byte r, Byte g, Byte b) {
	color.r = r;
	color.g = g;
	color.b = b;
}

void Hombre::setVel(float vx, float vy)
{
	velocidad.x = vx;
	velocidad.y = vy;
}

