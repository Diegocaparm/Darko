#include "Tentaculo.h"
#include "Vector2D.h"
#include "freeglut.h"
#include "Hombre.h"

Tentaculo::Tentaculo() {
	setColor(150, 0, 150);
	px = 1;						//px=1 derecha   py=1 arriba
}

void Tentaculo::dibuja() {
	glPushMatrix();

	glTranslatef(posicion.x, posicion.y, 0);
	glRotatef(-90, 1, 0, 0);
	glRotatef(a, 0, 1, 0);
	glutSolidCylinder(longitud / 6, longitud, 30, 30);
	glutSolidSphere(longitud / 6, 30, 30);
	glTranslatef(0, 0, longitud);
	glRotatef(a, 0, 1, 0);
	glutSolidCylinder(longitud / 7, longitud, 30, 30);
	glutSolidSphere(longitud / 7, 30, 30);
	glTranslatef(0, 0, longitud);
	glRotatef(a, 0, 1, 0);
	glutSolidCylinder(longitud / 8, longitud, 30, 30);
	glutSolidSphere(longitud / 8, 30, 30);

	//glRotatef(90, 0, 1, 0);
	glPopMatrix();
}

void Tentaculo::mueve(float t) {
	posicion = posicion + velocidad * t + aceleracion * 0.5f * t * t;
	velocidad = velocidad + aceleracion * t;
	velocidad.x = aceleracion.x = 0;
	static int flag=0;
	int lim=15;
	if (a > lim)
		flag = 1;
	if (a < -lim)
		flag = 0;

	if (flag == 0)
		a += 0.2f;
	else
		a -= 0.2f;
	
}

void Tentaculo::setColor(Byte r, Byte g, Byte b) {
	color.r = r;
	color.g = g;
	color.b = b;
}

void Tentaculo::setPos(float px, float py) {
	posicion.x = px;
	posicion.y = py;
}