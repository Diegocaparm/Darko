#include "Tank.h"
#include "Vector2D.h"
#include "freeglut.h"
#include "disparosEnemigos.h"

Tank::Tank() {
	altura = 7.0f;
	aceleracion.x = 0.0f;
	aceleracion.y = -9.8f;
	dispTank1->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
	dispTank2->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
	dispTank3->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
	dispTank4->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
	dispTank5->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
	dispTank1->setVel(-dispTank1->vel, 0.0f);
	dispTank2->setVel(-dispTank1->vel * 0.707, dispTank1->vel * 0.707);
	dispTank3->setVel(0.0f, dispTank1->vel);
	dispTank4->setVel(dispTank1->vel * 0.707, dispTank1->vel * 0.707);
	dispTank5->setVel(dispTank1->vel, 0.0f);
	dispTank1->setColor(10, 0, 0);
	dispTank2->setColor(10, 0, 0);
	dispTank3->setColor(10, 0, 0);
	dispTank4->setColor(10, 0, 0);
	dispTank5->setColor(10, 0, 0);
}

Tank::Tank(float px, float py) {
	altura = 7.0f;
	aceleracion.x = 0.0f;
	aceleracion.y = -9.8f;
	setPos(px, py);
	dispTank1->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
	dispTank2->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
	dispTank3->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
	dispTank4->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
	dispTank5->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
	dispTank1->setVel(-dispTank1->vel, 0.0f);
	dispTank2->setVel(-dispTank1->vel * 0.707, dispTank1->vel * 0.707);
	dispTank3->setVel(0.0f, dispTank1->vel);
	dispTank4->setVel(dispTank1->vel * 0.707, dispTank1->vel * 0.707);
	dispTank5->setVel(dispTank1->vel, 0.0f);
	dispTank1->setColor(10, 0, 0);
	dispTank2->setColor(10, 0, 0);
	dispTank3->setColor(10, 0, 0);
	dispTank4->setColor(10, 0, 0);
	dispTank5->setColor(10, 0, 0);
}

void Tank::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(0.8f, 0.4f, 0.2f);
	glRotatef(-90, 1, 0, 0);		//dibujar persona
	glutSolidCylinder(altura / 3, altura / 3, 30, 30);
	glTranslatef(0, 0, altura / 3);
	glutSolidSphere(altura / 3, 30, 30);
	//glTranslatef(0, 0, -altura * 5 / 6);
	//glRotatef(90, 1, 0, 0);

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

void Tank::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * 0.5f * t * t;
	velocidad = velocidad + aceleracion * t;

	if (temp < 120) {		//40 para 1 seg
		temp++;
		//mueve?

		if (temp == 120) {
			dispTank1->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
			dispTank2->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
			dispTank3->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
			dispTank4->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
			dispTank5->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
			dispTank1->setVel(-dispTank1->vel+velocidad.x, 0.0f);
			dispTank2->setVel(-dispTank1->vel * 0.707 + velocidad.x, dispTank1->vel * 0.707);
			dispTank3->setVel(0.0f + velocidad.x, dispTank1->vel);
			dispTank4->setVel(dispTank1->vel * 0.707 + velocidad.x, dispTank1->vel * 0.707);
			dispTank5->setVel(dispTank1->vel + velocidad.x, 0.0f);
			dispTank1->flagdibujar = 1;
			dispTank2->flagdibujar = 1;
			dispTank3->flagdibujar = 1;
			dispTank4->flagdibujar = 1;
			dispTank5->flagdibujar = 1;
			//dibuja?
		}

	}
	else {
		//~DispEnem();
		temp = 0;
	}

	if (zonaH == 0) {
		if (sentido == 0) {
			velocidad.x = -1;
		}
		else
			velocidad.x = 1;
	}

	Vector2D e1, e2, e3, e4;
	e1.x = posicion.x - altura / 3;		e1.y = posicion.y + altura * 2 / 3;
	e2.x = posicion.x + altura / 3;		e2.y = posicion.y + altura * 2 / 3;
	e3.x = posicion.x - altura / 3;		e3.y = posicion.y - 0;
	e4.x = posicion.x + altura / 3;		e4.y = posicion.y - 0;
	hitbox.setPos(e1, e2, e3, e4);
}

void Tank::setColor(Byte r, Byte g, Byte b) {
	color.r = r;
	color.g = g;
	color.b = b;
}

void Tank::setVelx(float vx)
{
	velocidad.x = vx;
	//velocidad.y = vy;
}

void Tank::setPos(float ix, float iy) {
	posicion.x = ix;
	posicion.y = iy;
}
