#include "BolaFuego.h"
#include "freeglut.h"
#include "Interaccion.h"


BolaFuego::BolaFuego(){
	radio = 0.75f;
	aceleracion.x = aceleracion.y = 0.0f;
	velocidad.x = 0.0f;
	velocidad.y = 2.0f;
}

BolaFuego::BolaFuego(float x, float y) {
	radio = 0.75f;
	aceleracion.x = aceleracion.y = 0.0f;
	velocidad.x = 0.0f;
	velocidad.y = 2.0f;
	setPos(x, y);
}


void BolaFuego::dibuja() {

	//Dibujo
	glPushMatrix();
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
	if (posicion.y > 16.0f)
	{
		velocidad.y = -velocidad.y;
	}
	else if (posicion.y < -5.0f)
	{
		velocidad.y = -(velocidad.y);
	}
	posicion.y = posicion.y + velocidad.y * t + 0.5f * aceleracion.y * t * t;
	velocidad.y = velocidad.y + aceleracion.y * t;
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
