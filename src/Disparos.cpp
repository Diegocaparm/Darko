#include "Disparos.h"

Disparos::Disparos() {
	setColor(10, 100, 0);
	//radio = 0.15f;
	setAc(0, -0.5);
}
Disparos::Disparos(float px, float py) {
	setColor(10, 100, 0);
	setPos(px, py);
	//radio = 0.15f;
	setAc(0, -0.5);
}

void Disparos::dibuja()
{
	glColor3f(color.r, color.g, color.b);
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0); //disparo
	glutSolidSphere(radio, 20, 20);
	glTranslatef(0, -posicion.y, 0);
	glPopMatrix();
}

void Disparos::mueve(float t)
{
	ObjetoMovil::mueve(t);

	if (temp < 120) {		//40 para 1 seg
		temp++;
		//dispEnem1.mueve(t);
		if (temp == 120) {
			setColor(1, 0, 0);
		}
		if (temp == 80)
			setColor(0, 0, 10);
	}
	else {
		//~DispEnem();
		temp = 0;
	}
}

void Disparos::setPos(float ix, float iy) {
	posicion.x = ix;
	posicion.y = iy;
}

void Disparos::setVel(float vx, float vy) {
	velocidad.x = vx;
	velocidad.y = vy;
}
void Disparos::setAc(float ax, float ay) {
	aceleracion.x = ax;
	aceleracion.y = ay;
}
void Disparos::setColor(Byte r, Byte g, Byte b) {
	color.r = r;
	color.g = g;
	color.b = b;
}
float Disparos::getRadio() {
	return radio;
}



disparosAmigos::disparosAmigos(float px, float py) {
	Disparos(px, py);
	radio = 0.15f;
	//la velocidad variable chunga
	//setVel(3+vx,0);
}
disparosEnemigos::disparosEnemigos(float px, float py) {
	Disparos(px, py);
	radio = 0.25f;
	setVel(-vel, 0);
}
misiles::misiles(float px, float py) {
	Disparos(px, py);
	radio = 0.5f;
	setVel(-vel, 0);
}


void misiles::mueve(float t) {
	Disparos::mueve(t);
	if (cerca) {
		if (prx)
			aceleracion.x = -1.5;
		else
			aceleracion.x = 1.5;

		if (pry)
			aceleracion.y = -1.5;
		else
			aceleracion.y = 1.5;

		if (velocidad.x > 2.5)
			velocidad.x = 2.5;
		if (velocidad.y > 2.5)
			velocidad.y = 2.5;
	}
	else {
		if (prx)
			aceleracion.x = -1.5;
		else
			aceleracion.x = 1.5;

		if (pry)
			aceleracion.y = -1.5;
		else
			aceleracion.y = 1.5;
		if (velocidad.x > 3.5)
			velocidad.x = 3.5;
		if (velocidad.y > 3.5)
			velocidad.y = 3.5;
	}
}