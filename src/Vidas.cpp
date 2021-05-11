#include "Vidas.h"
#include "freeglut.h"
#include "Hombre.h"
#include "ETSIDI.h"

Vidas::Vidas()
{
	actual = 3;
	maximo = 5;
	aumento = 1;
	desviacion = 7;
}

void Vidas::setPos(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
}

void Vidas::dibuja(int posicion)
{
	glPushMatrix();
	glTranslatef(posicion, 15, 0);
	glColor3f(1.0f, 1.0f, 0.0f);
	//glutSolidSphere(1, 20, 20);
	

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("imagenes/corazon.png").id);
	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3f(1, 1, 1);
	glTexCoord2d(0, 1); glVertex2f(0, 0);
	glTexCoord2d(1, 1); glVertex2f(2.5, 0);
	glTexCoord2d(1, 0); glVertex2f(2.5, 2);
	glTexCoord2d(0, 0); glVertex2f(0, 2);
	glEnd();
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	glPopMatrix();
}

int Vidas::getCantidad()
{
	return actual;
}
