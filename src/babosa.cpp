#include "babosa.h"
#include "Vector2D.h"
#include "freeglut.h"
#include "Hombre.h"

Babosa::Babosa() {
	setColor(2, 0, 0);
	prx = pry = 1;		//prx=1 derecha   pry=1 arriba
}
Babosa::Babosa(float px, float py) {
	setColor(2, 0, 0);
	setPos(px, py);
	prx = pry = 1;		//px=1 derecha   py=1 arriba
}

void Babosa::dibuja() {
	glPushMatrix();
	glColor3f(color.r, color.g, color.b);
	glTranslatef(posicion.x, posicion.y, 0);
	glRotatef(-90, 0, 1, 0);
	glutSolidCylinder(longitud/3, longitud, 30, 30);
	//glRotatef(90, 0, 1, 0);
	glPopMatrix();

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

void Babosa::mueve(float t) {
	posicion = posicion + velocidad * t + aceleracion * 0.5f * t * t;
	velocidad = velocidad + aceleracion * t;
	
	if (cerca) {
		if (prx)
			aceleracion.x = -1;
		else
			aceleracion.x = 1;

		if (pry)
			aceleracion.y = -1;
		else
			aceleracion.y = 1;
		
		if (velocidad.x > 2)
			velocidad.x = 2;
		if (velocidad.y > 2)
			velocidad.y = 2;
	}
	else {
		if (prx)
			aceleracion.x = -1;
		else
			aceleracion.x = 1;

		if (pry)
			aceleracion.y = -1;
		else
			aceleracion.y = 1;
		if (velocidad.x > 3)
			velocidad.x = 3;
		if (velocidad.y > 3)
			velocidad.y = 3;
	}

	Vector2D e1, e2, e3, e4;
	e1.x = posicion.x - longitud;	e1.y = posicion.y + longitud / 3;
	e2.x = posicion.x + 0;			e2.y = posicion.y + longitud / 3;
	e3.x = posicion.x - longitud;	e3.y = posicion.y - longitud / 3;
	e4.x = posicion.x + 0;			e4.y = posicion.y - longitud / 3;
	hitbox.setPos(e1, e2, e3, e4);
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