#include "Hombre.h"
#include "Vector2D.h"
#include "freeglut.h"
#include "Caja.h"


Hombre::Hombre() {
	rojo = verde = azul = 255;
	altura = 1.8f;
	aceleracion.x = 0;
	aceleracion.y = 0;//-9.8;
}

void interaccionCaja(Vector2D *, Vector2D *, Vector2D *);


void Hombre::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(1.0f, 0.0f, 0.0f);
	//glutSolidSphere(altura, 20, 20);
	glRotatef(-90, 1, 0, 0);		//dibujar persona
	glTranslatef(-0.2, 0, 0);
	glutSolidCylinder(0.1, altura / 3, 30, 30);
	glTranslatef(0.4, 0, 0);
	glutSolidCylinder(0.1, altura / 3, 30, 30);
	glTranslatef(-0.2, 0, altura / 3);
	glutSolidCylinder(0.4, altura / 3, 30, 30);
	glTranslatef(0, 0, altura / 2);
	glutSolidSphere(altura / 6, 30, 30);
	glTranslatef(0, 0, -altura * 5 / 6);
	glRotatef(90, 1, 0, 0);

	glPopMatrix();
}

void Hombre::mueve(float t)
{
	posicion.x = posicion.x + velocidad.x * t + 0.5f * aceleracion.x * t * t;
	posicion.y = posicion.y + velocidad.y * t + 0.5f * aceleracion.y * t * t;
	velocidad.x = velocidad.x + aceleracion.x * t;
	velocidad.y = velocidad.y + aceleracion.y * t;

	Vector2D *pp = &posicion, *pv = &velocidad, *pa=&aceleracion;
	if (velocidad.y > 0)	//sentido=0 sube     sentido=1 baja
		sentido = 0;
	else
		sentido = 1;
	if (salto)				//salto=1 puede saltar	   salto=0 NO puede saltar
		interaccionCaja(pp, pv, pa);
	else {
		aceleracion.y = 250;
		salto = 1;
	}
	if (velocidad.y == 0) {
		salto = 1;
	}
	/*if (mov) {
		velocidad.x = velocidad.x;
	}
	else
		velocidad.x = 0;*/
	//mov = false; //no se que hacer con esto

	//velocidad.x = 0;
}

void Hombre::tecla(unsigned char key) {
	
	if ((velocidad.y == 0) && sentido == 1) {
		if (key == 'w') {
			salto = 0;
			mov = true;
		}
	}
	/*if (posicion.x > -10)
		if (key == 'a')
			posicion.x += -0.5;
	if (posicion.x < 10)
		if (key == 'd')
			posicion.x += 0.5;*/
	if (posicion.x > -10)
		if (key == 'a') {
			velocidad.x = -2;
			mov = true;
		}
	if (posicion.x < 10)
		if (key == 'd') {
			velocidad.x = 2;
			mov = true;
		}
	//if (key == '\0')
		//velocidad.x = 0;
	
}

void interaccionCaja(Vector2D* posicion, Vector2D* velocidad, Vector2D* aceleracion) {
	if (posicion->y <= 0) {		//interaccion con el suelo
		velocidad->y = aceleracion->y = 0;
		posicion->y = 0;
	}
	else
		aceleracion->y = -9.8;
	if (posicion->x <= -10) {	//interaccion con pared izquierda
		velocidad->x = aceleracion->x = 0;
		posicion->x = -10;
	}
	if (posicion->x >= 10) {	//interaccion con pared derecha
		velocidad->x = aceleracion->x = 0;
		posicion->x = 10;
	}
	if (posicion->y + 1.8 >= 15) {	//interaccion con techo     cambiar 1.8 por altura
		velocidad->y = aceleracion->y = 0;
		posicion->y = 15;
	}

}