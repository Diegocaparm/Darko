#include "DisparosEnemigos.h"

DisparosEnemigos::DisparosEnemigos() {
	setColor(10, 0, 0);
	radio = 0.15f;
	aceleracion.x = 0.0f;
	aceleracion.y = -0.5;
}
DisparosEnemigos::DisparosEnemigos(float px, float py) {
	setColor(10, 100, 0);
	setPos(px, py);
	radio = 0.15f;
	aceleracion.x = 0.0f;
	aceleracion.y = -0.5;
}

void DisparosEnemigos::dibuja()
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

void DisparosEnemigos::mueve(float t)
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
}

void DisparosEnemigos::setPos(float ix, float iy) {
	posicion.x = ix;
	posicion.y = iy;
}

void DisparosEnemigos::setVel(float vx, float vy) {
	velocidad.x = vx;
	velocidad.y = vy;
}
void DisparosEnemigos::setAc(float ax, float ay) {
	aceleracion.x = ax;
	aceleracion.y = ay;
}
void DisparosEnemigos::setColor(Byte r, Byte g, Byte b) {
	color.r = r;
	color.g = g;
	color.b = b;
}
float DisparosEnemigos::getRadio() {
	return radio;
}
Vector2D DisparosEnemigos::getPos() {
	return posicion;
}