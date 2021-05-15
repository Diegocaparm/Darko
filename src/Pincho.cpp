#include "Pincho.h"

Pincho::Pincho() {
	altura = 2.5f;
}

void Pincho::setPos(float x, float y) {
	posicion.x = x;
	posicion.y = y;
}

void Pincho::dibuja()
{
	glPushMatrix();
	glColor3f(0.5f, 0.5f, 0.5f);
	glTranslatef(posicion.x + 1, posicion.y, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(0.5f, altura, 20, 10);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5f, 0.5f, 0.5f);
	glTranslatef(posicion.x, posicion.y, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(0.5f, altura, 20, 10);
	glPopMatrix();

	glPushMatrix();
	glColor3f(0.5f, 0.5f, 0.5f);
	glTranslatef(posicion.x - 1, posicion.y, 0);
	glRotatef(-90, 1, 0, 0);
	glutSolidCone(0.5f, altura, 20, 10);
	glPopMatrix();
}