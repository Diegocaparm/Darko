#include "Estela.h"
#include "Disparo.h"
#include "freeglut.h"

Estela::Estela() {
	radio1 = 0.1;
	radio2 = 0.2;
	posicion.x = -5.0f;
	posicion.y = 0.0f;
	velocidad.x = 0;
	velocidad.y = 1;
	aceleracion.x = aceleracion.y = 0;
}

void Estela::dibuja(float posiciony) {
	glTranslatef(0, posiciony, 0);
	glRotatef(-90, 1, 0, 0);
	glColor3ub(100, 0, 200);
	glutSolidTorus(radio1, radio2, 30, 30);
	glRotatef(90, 1, 0, 0);
	glTranslatef(0, -posiciony, 0);
}

void Estela::mueve(float t) {
	radio2 += 0.03;
	posicion.x = posicion.x + velocidad.x * t + 0.5f * aceleracion.x * t * t;
	posicion.y = posicion.y + velocidad.y * t + 0.5f * aceleracion.y * t * t;
	velocidad.x = velocidad.x + aceleracion.x * t;
	velocidad.y = velocidad.y + aceleracion.y * t;
}