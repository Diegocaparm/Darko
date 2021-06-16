#include "Hombre.h"
#include "Vector2D.h"
#include "freeglut.h"

Hombre::Hombre() {
	altura = 1.8f;
	aceleracion.x =  0.0f;
	aceleracion.y = -9.8f;
	mov = 0;
	setColor(1,1,0);
}

void Hombre::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(color.r, color.g, color.b);
	//glutSolidSphere(altura, 20, 20);
	glRotatef(-90, 1, 0, 0);		//dibujar persona
	glTranslatef(-0.2, 0, 0);
	glutSolidCylinder(0.1, altura / 3, 30, 30);
	glTranslatef(0.4, 0, 0);
	glutSolidCylinder(0.1, altura / 3, 30, 30);
	glTranslatef(-0.2, 0, altura / 3);
	glutSolidCylinder(0.4, altura / 3, 30, 30);
	glTranslatef(0, 0, altura / 2);
	glutSolidSphere(altura / 6, 30, 30);
	glTranslatef(0, 0, -altura * 5 / 6);
	glRotatef(90, 1, 0, 0);
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

void Hombre::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * 0.5f * t * t;
	velocidad = velocidad + aceleracion * t;
	//velocidad horizontal
	if (flagH == -1)
		setVelx(-7.5f);
	else if (flagH == 0)
		setVelx(0.0f);
	else if (flagH == 1)
		setVelx(7.5f);

	//Salto de David
	if (velocidad.y > 0.3f)
		sentido = 0;			//0 subiendo    1 bajando
	if (velocidad.y < -2)
	//else
		sentido = 1;
	
	if (flag == 0) {
		aceleracion.y = -9.8f;
	}
	else {
		if (salto == 1) {
			aceleracion.y = 250;
			flag = 0;
			//salto = 0;						//comentar para salto infinito
		}
	}
	if (velocidad.y < 0.3f && velocidad.y > -0.3f && sentido == 1 && salto == 0)
		salto = 1;

	//Añadido por Miguel (crea las paredes hitbox)
	Vector2D e1, e2, e3, e4;
	e1.x = posicion.x - 0.3f;	e1.y = posicion.y + 1.8f;
	e2.x = posicion.x + 0.3f;	e2.y = posicion.y + 1.8f;
	e3.x = posicion.x - 0.3f;	e3.y = posicion.y - 0.0f;
	e4.x = posicion.x + 0.3f;	e4.y = posicion.y - 0.0f;
	hitbox.setPos(e1, e2, e3, e4);
}

void Hombre::setColor(Byte r, Byte g, Byte b) {
	color.r = r;
	color.g = g;
	color.b = b;
}

void Hombre::setVelx(float vx)
{
	velocidad.x = vx;
	//velocidad.y = vy;
}

Vector2D Hombre::getPos()
{
	Vector2D pos;
	pos.x = posicion.x;
	pos.y = posicion.y;
	return pos;
}

