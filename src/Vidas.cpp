#include "Vidas.h"
#include "freeglut.h"
#include "Hombre.h"
#include "ETSIDI.h"
#include "Menu.h"

Vidas::Vidas()
{
	actual = 2;
	maximo = 5;
	recoger = true;
}

void Vidas::setPos(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
}

Vector2D Vidas::getPos()
{
	Vector2D pos;
	pos.x = posicion.x;
	pos.y = posicion.y;
	return pos;
}

void Vidas::dibuja(float posx, float posy, bool r)
{
	if (r = true) {
		glPushMatrix();
		glTranslatef(posx, posy, 0); //Que avance hacia la derecha con el personaje, pero no hacia arriba
		glColor3f(1.0f, 1.0f, 0.0f);
		//glutSolidSphere(1, 20, 20);
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/corazon.png").id);
		glDisable(GL_LIGHTING);
		glBegin(GL_POLYGON);
		glColor3f(1, 1, 1);
		glTexCoord2d(0, 1); glVertex2f(0, 0);
		glTexCoord2d(1, 1); glVertex2f(1.5, 0);
		glTexCoord2d(1, 0); glVertex2f(1.5, 1.5);
		glTexCoord2d(0, 0); glVertex2f(0, 1.5);
		glEnd();
		glEnable(GL_LIGHTING);
		glDisable(GL_TEXTURE_2D);
		glPopMatrix();
	}
	if (r = false) {
		glPushMatrix();
		glTranslatef(posx, posy, 0); //Que avance hacia la derecha con el personaje, pero no hacia arriba
		glColor3f(1.0f, 1.0f, 0.0f);
		glutSolidSphere(1, 20, 20);
		glPopMatrix();
	}
}

void Vidas::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * 0.5f * t * t;
	velocidad = velocidad + aceleracion * t;


}

void Vidas::daño()
{
	actual -= 1;

	if (actual == 0) {
		Menu GAMEOVER;	//Si se queda sin vidas el pj salta al gameover.
	}
}

void Vidas::aumento()
{
	actual += 1;
	if (actual >= maximo) {
		actual = maximo;		//Se tiene un maximo de 5 vidas.
	}
}


int Vidas::getCantidad()
{
	return actual;	//Accede al atributo Cantidad
}

void Vidas::setRecogido(bool a)
{
	recoger = a;
}

bool Vidas::getRecogido()
{

	return recoger;
}
