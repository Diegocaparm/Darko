#include "Tentaculo.h"
#include "Vector2D.h"
#include "freeglut.h"
#include "Hombre.h"
#include <math.h>
#define pi 3.14159265359
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
	glColor3f(color.r, color.g, color.b);
	glTranslatef(posicion.x, posicion.y, 0);
	glRotatef(-90, 1, 0, 0);
	glRotatef(a, 0, 1, 0);
	glutSolidCylinder(longitud / 6, longitud, 30, 30);
	glutSolidSphere(longitud / 6, 30, 30);

	glTranslatef(0, 0, longitud);
	glRotatef(a, 0, 1, 0);
	glutSolidCylinder(longitud / 7, longitud, 30, 30);
	glutSolidSphere(longitud / 7, 30, 30);

	glTranslatef(0, 0, longitud);
	glRotatef(a, 0, 1, 0);
	glutSolidCylinder(longitud / 8, longitud, 30, 30);
	glutSolidSphere(longitud / 8, 30, 30);

	//glRotatef(90, 0, 1, 0);
	glPopMatrix();

	glPushMatrix();
	//glTranslatef(posicion.x, posicion.y, 0);
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
	glPopMatrix();
}

void Tentaculo::mueve(float t) {
	posicion = posicion + velocidad * t + aceleracion * 0.5f * t * t;
	velocidad = velocidad + aceleracion * t;
	velocidad.x = aceleracion.x = 0;

	int lim = 15;
	if (a > lim)
		flag = 1;
	if (a < -lim)
		flag = 0;

	if (flag == 0)
		a += 0.2f;
	else
		a -= 0.2f;

	Vector2D e1, e2, e3, e4;
	/*float h0 = sqrt(longitud * longitud + longitud * longitud / 36);
	float beta0 = atan(1 / 6);
	e1.x = h0 * sin((a) * pi / 180 - beta0);		e1.y = h0 * sin((a )*pi/180 - beta0);
	e2.x = h0* sin((a) * pi / 180 + beta0);			e2.y = h0 * cos((a ) * pi / 180 + beta0);
	e3.x = -(longitud / 6) * cos(a * pi / 180);		e3.y = (longitud / 6) * (sin(a * pi / 180));
	e4.x = (longitud / 6) * cos(a * pi / 180);		e4.y = -(longitud / 6) * (sin(a * pi / 180));*/

	e1.x = -(longitud / 6) + longitud * sin(a * pi / 180) + posicion.x;		e1.y = (longitud) * (cos(-a * pi / 180))+ posicion.y;
	e2.x = (longitud / 6) + longitud * sin(a * pi / 180) + posicion.x;			e2.y = (longitud) * (cos(-a * pi / 180))+posicion.y;
	e3.x = -(longitud / 6) * cos(-a * pi / 180) + posicion.x;				e3.y = -(longitud / 6) * (sin(-a * pi / 180))+posicion.y;
	e4.x = (longitud / 6) * cos(-a * pi / 180) + posicion.x;					e4.y = (longitud / 6) * (sin(-a * pi / 180))+posicion.y;
	hitbox[0].setPos(e1, e2, e3, e4);


	Vector2D e11, e21, e31, e41;
	e11.x = -(longitud / 6) + longitud * sin(3 * a * pi / 180);		e11.y = (longitud) * (cos(3 * a * pi / 180)) + 2 * sin(a * pi / 180) * sin(a * pi / 180);
	e21.x = (longitud / 6) + longitud * sin(3 * a * pi / 180);		e21.y = (longitud) * (cos(3 * a * pi / 180)) + 2 * sin(a * pi / 180) * sin(a * pi / 180);
	e31.x = -(longitud / 6) + longitud * sin(a * pi / 180) + posicion.x;			e31.y = (longitud) * (cos(-a * pi / 180))+posicion.y;
	e41.x = (longitud / 6) + longitud * sin(a * pi / 180) + posicion.x;			e41.y = (longitud) * (cos(-a * pi / 180))+posicion.y;
	Vector2D e111 = { e11.x + posicion.x, e1.y + e11.y }, e211 = { e21.x + posicion.x, e2.y + e21.y };
	hitbox[1].setPos(e111, e211, e31, e41);

	Vector2D e12, e22, e32, e42;
	e12.x = -(longitud / 6) + longitud * 2 * sin(3.2 * a * pi / 180);		e12.y = (longitud) * (cos(a * pi / 180)) - 0.5 * (cos(a * pi / 180));
	e22.x = (longitud / 6) + longitud * 2 * sin(3.2 * a * pi / 180);		e22.y = (longitud) * (cos(a * pi / 180)) - 0.5 * (cos(a * pi / 180));
	e32.x = -(longitud / 6) + longitud * sin(3 * a * pi / 180);			e32.y = (longitud) * (cos(3 * a * pi / 180)) + 2 * sin(a * pi / 180) * sin(a * pi / 180);
	e42.x = (longitud / 6) + longitud * sin(3 * a * pi / 180);			e42.y = (longitud) * (cos(3 * a * pi / 180)) + 2 * sin(a * pi / 180) * sin(a * pi / 180);
	Vector2D e121 = { e12.x + posicion.x, e111.y + e12.y }, e221 = { e22.x + posicion.x, e211.y + e22.y };
	hitbox[2].setPos(e121, e221, e111, e211);

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
