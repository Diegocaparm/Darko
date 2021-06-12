#include "Tentaculo.h"
#include "Vector2D.h"
#include "freeglut.h"
#include "Hombre.h"

Tentaculo::Tentaculo() {
	setColor(150, 0, 150);
	prx = 1;						//prx=1 derecha   pry=1 arriba
	flag = 0;
	a = 0;
}

Tentaculo::Tentaculo(float px, float py) {
	setColor(150, 0, 0);
	setPos(px, py);
	flag = 0;
	a = 0;
}

void Tentaculo::dibuja() {
	glPushMatrix();

	glTranslatef(posicion.x, posicion.y, 0);
	glRotatef(-90, 1, 0, 0);
	glRotatef(a, 0, 1, 0);
	glutSolidCylinder(longitud / 6, longitud, 30, 30);
	glutSolidSphere(longitud / 6, 30, 30);
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(hitbox[0].esquina1.x, hitbox[0].esquina1.y, 0);
	glVertex3f(hitbox[0].esquina2.x, hitbox[0].esquina2.y, 0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(hitbox[0].esquina2.x, hitbox[0].esquina2.y, 0);
	glVertex3f(hitbox[0].esquina4.x, hitbox[0].esquina4.y, 0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(hitbox[0].esquina4.x, hitbox[0].esquina4.y, 0);
	glVertex3f(hitbox[0].esquina3.x, hitbox[0].esquina3.y, 0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(hitbox[0].esquina3.x, hitbox[0].esquina3.y, 0);
	glVertex3f(hitbox[0].esquina1.x, hitbox[0].esquina1.y, 0);
	glEnd();


	glTranslatef(0, 0, longitud);
	glRotatef(a, 0, 1, 0);
	glutSolidCylinder(longitud / 7, longitud, 30, 30);
	glutSolidSphere(longitud / 7, 30, 30);
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(hitbox[1].esquina1.x, hitbox[1].esquina1.y, 0);
	glVertex3f(hitbox[1].esquina2.x, hitbox[1].esquina2.y, 0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(hitbox[1].esquina2.x, hitbox[1].esquina2.y, 0);
	glVertex3f(hitbox[1].esquina4.x, hitbox[1].esquina4.y, 0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(hitbox[1].esquina4.x, hitbox[1].esquina4.y, 0);
	glVertex3f(hitbox[1].esquina3.x, hitbox[1].esquina3.y, 0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(hitbox[1].esquina3.x, hitbox[1].esquina3.y, 0);
	glVertex3f(hitbox[1].esquina1.x, hitbox[1].esquina1.y, 0);
	glEnd();


	glTranslatef(0, 0, longitud);
	glRotatef(a, 0, 1, 0);
	glutSolidCylinder(longitud / 8, longitud, 30, 30);
	glutSolidSphere(longitud / 8, 30, 30);
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(hitbox[2].esquina1.x, hitbox[2].esquina1.y, 0);
	glVertex3f(hitbox[2].esquina2.x, hitbox[2].esquina2.y, 0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(hitbox[2].esquina2.x, hitbox[2].esquina2.y, 0);
	glVertex3f(hitbox[2].esquina4.x, hitbox[2].esquina4.y, 0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(hitbox[2].esquina4.x, hitbox[2].esquina4.y, 0);
	glVertex3f(hitbox[2].esquina3.x, hitbox[2].esquina3.y, 0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(hitbox[2].esquina3.x, hitbox[2].esquina3.y, 0);
	glVertex3f(hitbox[2].esquina1.x, hitbox[2].esquina1.y, 0);
	glEnd();


	//glRotatef(90, 0, 1, 0);
	glPopMatrix();
}

void Tentaculo::mueve(float t) {
	posicion = posicion + velocidad * t + aceleracion * 0.5f * t * t;
	velocidad = velocidad + aceleracion * t;
	velocidad.x = aceleracion.x = 0;
	
	int lim=15;
	if (a > lim)
		flag = 1;
	if (a < -lim)
		flag = 0;

	if (flag == 0)
		a += 0.2f;
	else
		a -= 0.2f;
	
	Vector2D e1, e2, e3, e4;
	e1.x = posicion.x - longitud;	e1.y = posicion.y + longitud / 3;
	e2.x = posicion.x + 0;			e2.y = posicion.y + longitud / 3;
	e3.x = posicion.x - longitud;	e3.y = posicion.y - longitud / 3;
	e4.x = posicion.x + 0;			e4.y = posicion.y - longitud / 3;
	hitbox[0].setPos(e1, e2, e3, e4);

	Vector2D e11, e21, e31, e41;
	e11.x = posicion.x - longitud;	e11.y = posicion.y + longitud / 3;
	e21.x = posicion.x + 0;			e21.y = posicion.y + longitud / 3;
	e31.x = posicion.x - longitud;	e31.y = posicion.y - longitud / 3;
	e41.x = posicion.x + 0;			e41.y = posicion.y - longitud / 3;
	hitbox[1].setPos(e11, e21, e31, e41);

	Vector2D e12, e22, e32, e42;
	e12.x = posicion.x - longitud;	e12.y = posicion.y + longitud / 3;
	e22.x = posicion.x + 0;			e22.y = posicion.y + longitud / 3;
	e32.x = posicion.x - longitud;	e32.y = posicion.y - longitud / 3;
	e42.x = posicion.x + 0;			e42.y = posicion.y - longitud / 3;
	hitbox[2].setPos(e12, e22, e32, e42);
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