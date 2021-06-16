#include "espada.h"

espada::espada() {
	setColor(0, 1, 1);
}
espada::espada(float px, float py) {
	setPos(px, py);
	setColor(0, 1, 1);
}

void espada::dibuja() {
	glPushMatrix();
	glColor3f(color.r, color.g, color.b);
	glTranslatef(posicion.x, posicion.y, 0);
	glRotatef(90, -1, 0, 0);
	glRotatef(angulo-45, 0, 1, 0);
	glutSolidCylinder(longitud / 12, longitud, 30, 30);
	glPopMatrix();
}

void espada::mueve(float t) {
	posicion = posicion + velocidad * t + aceleracion * 0.5f * t * t;
	velocidad = velocidad + aceleracion * t;
	if (flag) {
		angulo += 9;
		if (angulo > 360) {
			flag = 0;
			angulo = 0;
		}
	}
}

void espada::setColor(Byte r, Byte g, Byte b) {
	color.r = r;
	color.g = g;
	color.b = b;
}

void espada::setPos(float px, float py) {
	posicion.x = px;
	posicion.y = py;
}

void espada::setVel(float vx, float vy) {
	velocidad.x = vx;
	velocidad.y = vy;
}
Vector2D espada::getPos() {
	return posicion;
}
int espada::getFlag() {
	return flag;
}
void espada::setFlag(int i) {
	flag = i;
}
float espada::getLong() {
	return longitud;
}