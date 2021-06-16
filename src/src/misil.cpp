#include "misil.h"

misil::misil() {
	setColor(10, 0, 0);
	radio = 0.15f;
	aceleracion.x = 0.0f;
	aceleracion.y = -0.5;
}
misil::misil(float px, float py) {
	setColor(10, 100, 0);
	setPos(px, py);
	radio = 0.15f;
	aceleracion.x = 0.0f;
	aceleracion.y = -0.5;
}

void misil::dibuja()
{
	if (flagdibujar) {			//si choca con plataforma deja de dibujarlo
		glColor3f(color.r, color.g, color.b);
		glPushMatrix();
		glTranslatef(posicion.x, posicion.y, 0); //disparo
		glutSolidSphere(radio, 20, 20);
		glTranslatef(0, -posicion.y, 0);
		glPopMatrix();
	}
}

void misil::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * 0.5f * t * t;
	velocidad = velocidad + aceleracion * t;

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

void misil::setPos(float ix, float iy) {
	posicion.x = ix;
	posicion.y = iy;
}

void misil::setVel(float vx, float vy) {
	velocidad.x = vx;
	velocidad.y = vy;
}
void misil::setAc(float ax, float ay) {
	aceleracion.x = ax;
	aceleracion.y = ay;
}
void misil::setColor(Byte r, Byte g, Byte b) {
	color.r = r;
	color.g = g;
	color.b = b;
}
float misil::getRadio() {
	return radio;
}
Vector2D misil::getPos() {
	return posicion;
}