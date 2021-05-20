#include "babosa.h"
#include "Vector2D.h"
#include "freeglut.h"
#include "Hombre.h"

Babosa::Babosa() {
	setColor(50, 220, 50);
	px = py = 1;		//px=1 derecha   py=1 arriba
}

void Babosa::dibuja() {
	glPushMatrix();
	
	glTranslatef(posicion.x, posicion.y, 0);
	glRotatef(-90, 0, 1, 0);
	glutSolidCylinder(longitud/3, longitud, 30, 30);
	//glRotatef(90, 0, 1, 0);
	glPopMatrix();
}

void Babosa::mueve(float t) {
	posicion = posicion + velocidad * t + aceleracion * 0.5f * t * t;
	velocidad = velocidad + aceleracion * t;
	
	if (cerca) {
		if (px)
			aceleracion.x = -1;
		else
			aceleracion.x = 1;

		if (py)
			aceleracion.y = -1;
		else
			aceleracion.y = 1;
		
		if (velocidad.x > 2)
			velocidad.x = 2;
		if (velocidad.y > 2)
			velocidad.y = 2;
	}
	else {
		if (px)
			aceleracion.x = -1;
		else
			aceleracion.x = 1;

		if (py)
			aceleracion.y = -1;
		else
			aceleracion.y = 1;
		if (velocidad.x > 3)
			velocidad.x = 3;
		if (velocidad.y > 3)
			velocidad.y = 3;
	}
}

void Babosa::setColor(Byte r, Byte g, Byte b) {
	color.r = r;
	color.g = g;
	color.b = b;
}

void Babosa::setVelx(float vx) {
	velocidad.x = vx;
}

void Babosa::setPos(float px, float py) {
	posicion.x = px;
	posicion.y = py;
}