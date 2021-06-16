#include "EnemigoDisp.h"
#include "Vector2D.h"
#include "freeglut.h"

EnemigoDisp::EnemigoDisp() {
	altura = 2.0f;
	aceleracion.x = 0.0f;
	aceleracion.y = -9.8f;
	//setPos(px, py);
	dispEnem1->setPos(posicion.x, posicion.y + altura * 2 / 3);	//esta aqui para que este bien la posicion del disparo inicial
	setColor(1,0,0);
}
EnemigoDisp::EnemigoDisp(float px, float py) {
	altura = 2.0f;
	aceleracion.x = 0.0f;
	aceleracion.y = -9.8f;
	setPos(px, py);
	dispEnem1->setPos(posicion.x, posicion.y + altura * 2 / 3);	//esta aqui para que este bien la posicion del disparo inicial
	setColor(1,0,0);
}

void EnemigoDisp::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(color.r, color.g, color.b);
	glRotatef(-90, 1, 0, 0);		//dibujar persona
	glTranslatef(-0.2, 0, 0);
	glutSolidCylinder(0.1, altura / 3, 30, 30);
	glTranslatef(0.4, 0, 0);
	glutSolidCylinder(0.1, altura / 3, 30, 30);
	glTranslatef(-0.2, 0, altura / 3);
	glutSolidCylinder(0.35, altura / 3, 30, 30);
	glTranslatef(0, 0, altura / 2);
	glRotatef(90, 1, 0, 0);
	//glutSolidTeapot(altura/6);
	glutSolidSphere(altura / 6, 30, 30);
	glTranslatef(0, 0, -altura * 5 / 6);
	//glRotatef(90, 1, 0, 0);
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

	//dispEnem1.dibuja();
}

void EnemigoDisp::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * 0.5f * t * t;
	velocidad = velocidad + aceleracion * t;

	//Disparo de los enemigos cada 3 segundos
	if (temp < 120) {		//40 para 1 seg
		temp++;
		if (temp == 120) {		//volver a disparar
			dispEnem1->setPos(posicion.x, posicion.y + altura * 2 / 3);
			dispEnem1->setVel(-dispEnem1->vel + velocidad.x, 0.0f);
			//dispEnem1->dibuja();
			dispEnem1->flagdibujar = 1;
		}
	}
	else {
		//~DispEnem();
		temp = 0;
	}

	if (zonaH ==0) {
		if (sentido == 0) {
			velocidad.x = 1;
		}
		else
			velocidad.x = -1;
	}

	//Añadido por Miguel (crea las paredes de choque)
	Vector2D e1, e2, e3, e4;
	e1.x = posicion.x - 0.3f;	e1.y = posicion.y + 2.0f;
	e2.x = posicion.x + 0.3f;	e2.y = posicion.y + 2.0f;
	e3.x = posicion.x - 0.3f;	e3.y = posicion.y - 0.0f;
	e4.x = posicion.x + 0.3f;	e4.y = posicion.y - 0.0f;
	hitbox.setPos(e1,e2,e3,e4);

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

void EnemigoDisp::setColor(Byte r, Byte g, Byte b) {
	color.r = r;
	color.g = g;
	color.b = b;
}

void EnemigoDisp::setVelx(float vx)
{
	velocidad.x = vx;
	//velocidad.y = vy;
}

void EnemigoDisp::setPos(float ix, float iy) {
	posicion.x = ix;
	posicion.y = iy;
}