#include "disparosAmigos.h"

disparosAmigos::disparosAmigos() {
	setColor(10, 0, 0);
	radio = 0.15f;
	aceleracion.x = 0.0f;
	aceleracion.y = -0.5;
}
disparosAmigos::disparosAmigos(float px, float py, float vx, float vy) {
	setColor(10, 0, 0);
	setPos(px, py);
	setVel(3 + vx, 0);
	radio = 0.15f;
	aceleracion.x = 0.0f;
	aceleracion.y = -0.5;
}

void disparosAmigos::dibuja()
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

void disparosAmigos::mueve(float t)
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

void disparosAmigos::setPos(float ix, float iy) {
	posicion.x = ix;
	posicion.y = iy;
}

void disparosAmigos::setVel(float vx, float vy) {
	velocidad.x = vx;
	velocidad.y = vy;
}
void disparosAmigos::setAc(float ax, float ay) {
	aceleracion.x = ax;
	aceleracion.y = ay;
}
void disparosAmigos::setColor(Byte r, Byte g, Byte b) {
	color.r = r;
	color.g = g;
	color.b = b;
}
float disparosAmigos::getRadio() {
	return radio;
}
Vector2D disparosAmigos::getPos() {
	return posicion;
}

