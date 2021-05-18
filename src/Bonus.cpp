#include "Bonus.h"
#include "Vector2D.h"
#include "freeglut.h"

Bonus::Bonus() {
	color.r = 100.0f;
	color.g = 100.0f;
	color.b = 150.0f;
	lado = 2;
}

void Bonus::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3b(color.r, color.g, color.b);
	//glRotatef(30, 1, 1, 1);
	//glColor3f(rand() / (float)RAND_MAX, rand() / (float)RAND_MAX,
		//rand() / (float)RAND_MAX);//color aleatorio
	glutSolidCube(lado);
	glPopMatrix();
}
/*void Bonus::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * 0.5f * t * t;
	velocidad = velocidad + aceleracion * t;
}*/

void Bonus::setPos(float ix, float iy) {
	posicion.x = ix;
	posicion.y = iy;
}

void Bonus::setColor(Byte r, Byte g, Byte b) {
	color.r = r;
	color.g = g;
	color.b = b;
}