#include "bossFinal.h"
#include "Vector2D.h"
#include "freeglut.h"
#include "misil.h"

bossFinal::bossFinal() {
	altura = 7.0f;
	aceleracion.x = 0.0f;
	aceleracion.y = -9.8f;
	setColor(1, 1, 1);
	misil1->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
	misil2->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
	misil3->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
	misil4->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
	misil5->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
	misil6->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
	misil7->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
	misil8->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
	misil9->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
	misil10->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial

	misil1->setVel(-misil1->vel, 0.0f);
	misil2->setVel(-misil1->vel * 0.94, misil1->vel * 0.342);
	misil3->setVel(-misil1->vel * 0.766, misil1->vel * 0.643);
	misil4->setVel(-misil1->vel * 0.5, misil1->vel * 0.866);
	misil5->setVel(-misil1->vel * 0.174, misil1->vel * 0.985);

	misil6->setVel(-misil1->vel, -misil1->vel * 0.174);
	misil7->setVel(-misil1->vel * 0.94, -misil1->vel * 0.342);
	misil8->setVel(misil1->vel * 0.766, misil1->vel * 0.643);
	misil9->setVel(misil1->vel * 0.5, misil1->vel * 0.866);
	misil10->setVel(misil1->vel * 0.174, misil1->vel * 0.985);

	misil1->setColor(10, 0, 0);
	misil2->setColor(10, 0, 0);
	misil3->setColor(10, 0, 0);
	misil4->setColor(10, 0, 0);
	misil5->setColor(10, 0, 0);
	misil6->setColor(10, 0, 0);
	misil7->setColor(10, 0, 0);
	misil8->setColor(10, 0, 0);
	misil9->setColor(10, 0, 0);
	misil10->setColor(10, 0, 0);
}

bossFinal::bossFinal(float px, float py) {
	altura = 14.0f;
	aceleracion.x = 0.0f;
	aceleracion.y = -9.8f;
	setColor(1, 1, 1);
	setPos(px, py);
	misil1->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
	misil2->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
	misil3->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
	misil4->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
	misil5->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
	misil6->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
	misil7->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
	misil8->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
	misil9->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
	misil10->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial

	misil1->setVel(-misil1->vel, 0.0f);								
	misil2->setVel(-misil1->vel * 0.94, misil1->vel * 0.342);		
	misil3->setVel(-misil1->vel * 0.766, misil1->vel * 0.643);
	misil4->setVel(-misil1->vel * 0.5, misil1->vel * 0.866);
	misil5->setVel(-misil1->vel * 0.174, misil1->vel * 0.985);

	misil6->setVel(-misil1->vel, -misil1->vel * 0.174);
	misil7->setVel(-misil1->vel * 0.94, -misil1->vel * 0.342);
	misil8->setVel(misil1->vel * 0.766, misil1->vel * 0.643);
	misil9->setVel(misil1->vel * 0.5, misil1->vel * 0.866);
	misil10->setVel(misil1->vel * 0.174, misil1->vel * 0.985);

	misil1->setColor(10, 0, 0);
	misil2->setColor(10, 0, 0);
	misil3->setColor(10, 0, 0);
	misil4->setColor(10, 0, 0);
	misil5->setColor(10, 0, 0);
	misil6->setColor(10, 0, 0);
	misil7->setColor(10, 0, 0);
	misil8->setColor(10, 0, 0);
	misil9->setColor(10, 0, 0);
	misil10->setColor(10, 0, 0);
}

void bossFinal::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(color.r, color.g, color.b);
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

void bossFinal::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * 0.5f * t * t;
	velocidad = velocidad + aceleracion * t;

	if (temp < 120) {		//40 para 1 seg
		temp++;
		//mueve?

		if (temp == 120) {
			misil1->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
			misil2->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
			misil3->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
			misil4->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
			misil5->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
			misil6->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
			misil7->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
			misil8->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
			misil9->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
			misil10->setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial

			misil1->setVel(-misil1->vel, 0.0f);
			misil2->setVel(-misil1->vel * 0.94, misil1->vel * 0.342);
			misil3->setVel(-misil1->vel * 0.766, misil1->vel * 0.643);
			misil4->setVel(-misil1->vel * 0.5, misil1->vel * 0.866);
			misil5->setVel(-misil1->vel * 0.174, misil1->vel * 0.985);
			misil6->setVel(-misil1->vel, -misil1->vel * 0.174);
			misil7->setVel(-misil1->vel * 0.94, -misil1->vel * 0.342);
			misil8->setVel(misil1->vel * 0.766, misil1->vel * 0.643);
			misil9->setVel(misil1->vel * 0.5, misil1->vel * 0.866);
			misil10->setVel(misil1->vel * 0.174, misil1->vel * 0.985);
			
			misil1->flagdibujar = 1;
			misil2->flagdibujar = 1;
			misil3->flagdibujar = 1;
			misil4->flagdibujar = 1;
			misil5->flagdibujar = 1;
			misil6->flagdibujar = 1;
			misil7->flagdibujar = 1;
			misil8->flagdibujar = 1;
			misil9->flagdibujar = 1;
			misil10->flagdibujar = 1;
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

void bossFinal::setColor(Byte r, Byte g, Byte b) {
	color.r = r;
	color.g = g;
	color.b = b;
}

void bossFinal::setVelx(float vx)
{
	velocidad.x = vx;
	//velocidad.y = vy;
}

void bossFinal::setPos(float ix, float iy) {
	posicion.x = ix;
	posicion.y = iy;
}

Vector2D bossFinal::getPos() {
	return posicion;
}