#include "Corazon.h"

#include "Vidas.h"
#include "freeglut.h"
#include "Hombre.h"
#include "ETSIDI.h"
#include "Menu.h"

Corazon::Corazon()
{
	radio = 1;
}

Corazon::Corazon(float x, float y)
{
	radio = 1;
	posicion.x = x;
	posicion.y = y;
}


void Corazon::setPos(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
}

Vector2D Corazon::getPos()
{
	Vector2D pos;
	pos.x = posicion.x;
	pos.y = posicion.y;
	return pos;
}

void Corazon::dibuja()
{
	
		glPushMatrix();
		glTranslatef(posicion.x, posicion.y, 0); //Que avance hacia la derecha con el personaje, pero no hacia arriba
		glColor3f(1.0f, 0.0f, 0.0f);
		glutSolidSphere(radio, 20, 20);
		/*glEnable(GL_TEXTURE_2D);
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
		glDisable(GL_TEXTURE_2D);*/
		glPopMatrix();
}

void Corazon::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * 0.5f * t * t;
	velocidad = velocidad + aceleracion * t;
}

//void Corazon::mueve(float x, float y) {
//	/*posicion.x += x;
//	posicion.y += y;*/
//	float t = 0.025f;
//	posicion = posicion + velocidad * t + aceleracion * 0.5f * t * t;
//	velocidad = velocidad + aceleracion * t;
//}


