#include "ObjetoMovil.h"

void ObjetoMovil::dibuja() {

}

void ObjetoMovil::mueve(float t) {
	posicion = posicion + velocidad * t + aceleracion * 0.5f * t * t;
	velocidad = velocidad + aceleracion * t;

}

void ObjetoMovil::setColor(Byte r, Byte g, Byte b) {
	color.r = r;
	color.g = g;
	color.b = b;
}

void ObjetoMovil::setPos(float px, float py) {
	posicion.x = px;
	posicion.y = py;
}

void ObjetoMovil::setVel(float vx, float vy) {
	velocidad.x = vx;
	velocidad.y = vy;
}

void ObjetoMovil::setAc(float ax, float ay) {
	aceleracion.x = ax;
	aceleracion.y = ay;
}

Vector2D ObjetoMovil::getPos() {
	return posicion;
}