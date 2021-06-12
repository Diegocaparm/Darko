#include "Bonus.h"
#include "Vector2D.h"
#include "freeglut.h"

Bonus::Bonus() {
	color.r = 100.0f;
	color.g = 100.0f;
	color.b = 150.0f;
	lado = 2;
}
Bonus::Bonus(float px, float py) {
	color.r = 100.0f;
	color.g = 100.0f;
	color.b = 150.0f;
	lado = 2;
	setPos(px, py);

	Vector2D e1, e2, e3, e4;
	e1.x = posicion.x - lado / 2;		e1.y = posicion.y + lado / 2;
	e2.x = posicion.x + lado / 2;		e2.y = posicion.y + lado / 2;
	e3.x = posicion.x - lado / 2;		e3.y = posicion.y - lado / 2;
	e4.x = posicion.x + lado / 2;		e4.y = posicion.y - lado / 2;
	hitbox.setPos(e1, e2, e3, e4);
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

void Bonus::setPos(float ix, float iy) {
	posicion.x = ix;
	posicion.y = iy;
}

void Bonus::setColor(Byte r, Byte g, Byte b) {
	color.r = r;
	color.g = g;
	color.b = b;
}