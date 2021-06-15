#include "BolaFuego.h"
#include "freeglut.h"
#include "Interaccion.h"


BolaFuego::BolaFuego(){
	radio = 0.75f;
	velocidad.x = 0.0f;
	velocidad.y = 2.0f;
}

BolaFuego::BolaFuego(float posx, float posy, float limtop, float limbot) {
	radio = 0.75f;
	velocidad.x = 0.0f;
	velocidad.y = 10.0f;
	setPos(posx, posy);
	limitesy = { limbot,limtop };
	setColor(1, 0, 0);
}

void BolaFuego::dibuja() {

	//Dibujo
	glPushMatrix();
	glColor3f(color.r, color.g, color.b);
	glTranslatef(posicion.x, posicion.y, 0.5);
	glutWireSphere(radio, 15, 15);
	glPopMatrix();

	//hitbox
	glPushMatrix();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(hitbox.esquina1.x, hitbox.esquina1.y, 0);
	glVertex3f(hitbox.esquina2.x, hitbox.esquina2.y, 0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(hitbox.esquina2.x, hitbox.esquina2.y, 0);
	glVertex3f(hitbox.esquina4.x, hitbox.esquina4.y, 0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(hitbox.esquina4.x, hitbox.esquina4.y, 0);
	glVertex3f(hitbox.esquina3.x, hitbox.esquina3.y, 0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(hitbox.esquina3.x, hitbox.esquina3.y, 0);
	glVertex3f(hitbox.esquina1.x, hitbox.esquina1.y, 0);
	glEnd();
	glPopMatrix();

}

void BolaFuego::mueve(float t) {
	if (posicion.y > limitesy.y)
	{
		velocidad.y = -velocidad.y;
	}
	else if (posicion.y < limitesy.x)
	{
		velocidad.y = -(velocidad.y);
	}
	posicion.y = posicion.y + velocidad.y * t;
	//posicion hitbox
	Vector2D e1, e2, e3, e4;
	e1.x = posicion.x - radio;			e1.y = posicion.y + radio;
	e2.x = posicion.x + radio;			e2.y = posicion.y + radio;
	e3.x = posicion.x - radio;			e3.y = posicion.y - radio;
	e4.x = posicion.x + radio;			e4.y = posicion.y - radio;
	hitbox.setPos(e1, e2, e3, e4);
}

void BolaFuego::setPos(float ix, float iy) {
	posicion.x = ix;
	posicion.y = iy;
}

float BolaFuego::getRadio() {
	return radio;
}

Vector2D BolaFuego::getPos() {
	return posicion;
}

void BolaFuego::setColor(Byte r, Byte g, Byte b) {
	color.r = r;
	color.g = g;
	color.b = b;
}