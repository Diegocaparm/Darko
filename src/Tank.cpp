#include "Tank.h"
#include "Vector2D.h"
#include "freeglut.h"
#include "DispTank.h"

Tank::Tank() {
	altura = 7.0f;
	aceleracion.x = 0.0f;
	aceleracion.y = -9.8f;
	dispTank1.setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
	dispTank2.setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
	dispTank3.setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
	dispTank4.setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
	dispTank5.setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
	dispTank1.setVel(-dispTank1.vel, 0.0f);
	dispTank2.setVel(-dispTank1.vel * 0.707, dispTank1.vel * 0.707);
	dispTank3.setVel(0.0f, dispTank1.vel);
	dispTank4.setVel(dispTank1.vel * 0.707, dispTank1.vel * 0.707);
	dispTank5.setVel(dispTank1.vel, 0.0f);
}

Tank::Tank(float px, float py) {
	altura = 7.0f;
	aceleracion.x = 0.0f;
	aceleracion.y = -9.8f;
	setPos(px, py);
	dispTank1.setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
	dispTank2.setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
	dispTank3.setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
	dispTank4.setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
	dispTank5.setPos(posicion.x, posicion.y + altura / 2);	//esta aqui para que este bien la posicion del disparo inicial
	dispTank1.setVel(-dispTank1.vel, 0.0f);
	dispTank2.setVel(-dispTank1.vel * 0.707, dispTank1.vel * 0.707);
	dispTank3.setVel(0.0f, dispTank1.vel);
	dispTank4.setVel(dispTank1.vel * 0.707, dispTank1.vel * 0.707);
	dispTank5.setVel(dispTank1.vel, 0.0f);
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

	dispTank1.dibuja();
	dispTank2.dibuja();
	dispTank3.dibuja();
	dispTank4.dibuja();
	dispTank5.dibuja();

}

void Tank::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * 0.5f * t * t;
	velocidad = velocidad + aceleracion * t;

	if (temp < 80) {		//80 para 2 seg
		temp++;
		dispTank1.mueve(t);
		dispTank2.mueve(t);
		dispTank3.mueve(t);
		dispTank4.mueve(t);
		dispTank5.mueve(t);

		if (temp == 80) {
			dispTank1.setPos(posicion.x, posicion.y + altura / 2);
			dispTank2.setPos(posicion.x, posicion.y + altura / 2);
			dispTank3.setPos(posicion.x, posicion.y + altura / 2);
			dispTank4.setPos(posicion.x, posicion.y + altura / 2);
			dispTank5.setPos(posicion.x, posicion.y + altura / 2);

			dispTank1.setVel(-dispTank1.vel + velocidad.x, 0.0f + velocidad.y);
			dispTank2.setVel(-dispTank1.vel * 0.707 + velocidad.x, dispTank1.vel * 0.707 + velocidad.y);
			dispTank3.setVel(0.0f + velocidad.x, dispTank1.vel + velocidad.y);
			dispTank4.setVel(dispTank1.vel * 0.707 + velocidad.x, dispTank1.vel * 0.707 + velocidad.y);
			dispTank5.setVel(dispTank1.vel + velocidad.x, 0.0f + velocidad.y);

			dispTank1.dibuja();
			dispTank2.dibuja();
			dispTank3.dibuja();
			dispTank4.dibuja();
			dispTank5.dibuja();
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
