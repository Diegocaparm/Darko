#include "bomber.h"
#include "Vector2D.h"
#include "freeglut.h"


bomber::bomber() {
	radio = 2.0f;
	aceleracion.x = 0.0f;
	aceleracion.y = -9.8f;
	//setPos(px, py);
}
bomber::bomber(float px, float py) {
	radio = 2.0f;
	aceleracion.x = 0.0f;
	aceleracion.y = -9.8f;
	setPos(px, py);
	setColor(200, 100, 0);
}

void bomber::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(color.r, color.g, color.b);
	glutSolidSphere(radio, 30, 30);

	glPopMatrix();

	//Añadido por Miguel (Dibuja los bordes de choque)
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

void bomber::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * 0.5f * t * t;
	velocidad = velocidad + aceleracion * t;


	//if (zonaH == 0) {
		if (sentido == 0) {
			velocidad.x = 1;
		}
		else
			velocidad.x = -1;
	//}

	//Añadido por Miguel (crea las paredes de choque)
	Vector2D e1, e2, e3, e4;
	e1.x = posicion.x - radio;	e1.y = posicion.y + radio;
	e2.x = posicion.x + radio;	e2.y = posicion.y + radio;
	e3.x = posicion.x - radio;	e3.y = posicion.y - radio;
	e4.x = posicion.x + radio;	e4.y = posicion.y - radio;
	hitbox.setPos(e1, e2, e3, e4);

	if (tempdmg) {
		tempdmg--;
		if (vida <= 0) {	//muerto
			setColor(1, 1, 1);
		}
	}
	else if (flagdmg) {
		vida -= 1 + flagesp;
		//destruir la vida de la interfaz
		flagdmg = 0;
		flagesp = 0;
	}
}

void bomber::setColor(Byte r, Byte g, Byte b) {
	color.r = r;
	color.g = g;
	color.b = b;
}

void bomber::setVelx(float vx)
{
	velocidad.x = vx;
	//velocidad.y = vy;
}

void bomber::setPos(float ix, float iy) {
	posicion.x = ix;
	posicion.y = iy;
}

Vector2D bomber::getPos() {
	Vector2D pos = posicion;
	return pos;
}