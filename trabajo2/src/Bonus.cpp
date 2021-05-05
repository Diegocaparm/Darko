#include "Bonus.h"
#include "Vector2D.h"
#include "freeglut.h"

Bonus::Bonus() {
	aceleracion.y = -9.8f;
	lado = 0.5;
}

void Bonus::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glRotatef(30, 1, 1, 1);
	glColor3f(rand() / (float)RAND_MAX, rand() / (float)RAND_MAX,
		rand() / (float)RAND_MAX);//color aleatorio
	glutSolidCube(lado);
	glPopMatrix();
}
void Bonus::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * 0.5f * t * t;
	velocidad = velocidad + aceleracion * t;
}

void Bonus::setPos(float ix, float iy) {
	posicion.x = ix;
	posicion.y = iy;
}

void Bonus::setColor(Byte r, Byte g, Byte b) {
	color.r = r;
	color.g = g;
	color.b = b;
}