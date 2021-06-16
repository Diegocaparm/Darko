#include "Pincho.h"

Pincho::Pincho() {
	altura = 1.5f;
}
Pincho::Pincho(float px, float py) {
	altura = 1.5f;
	setPos(px, py);

	Vector2D e1, e2, e3, e4;
	e1.x = posicion.x - 1.3;		e1.y = posicion.y + altura;
	e2.x = posicion.x + 1.3;		e2.y = posicion.y + altura;
	e3.x = posicion.x - 1.3;		e3.y = posicion.y - 0;
	e4.x = posicion.x + 1.3;		e4.y = posicion.y - 0;
	hitbox.setPos(e1, e2, e3, e4);
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