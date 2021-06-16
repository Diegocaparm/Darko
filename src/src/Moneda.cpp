#include "Moneda.h"
#include "freeglut.h"

Moneda::Moneda()
{
	radio = 1;
	posicion.x = 10;
	posicion.y = 10;
	sprite.setCenter(1, 0);
	sprite.setSize(2, 2);

}

Moneda::Moneda(float x, float y)
{
	radio = 1;
	posicion.x = x;
	posicion.y = y;
	sprite.setCenter(1, 0);
	sprite.setSize(2, 2);
}

void Moneda::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(1.0f, 1.0f, 0.0f);
	glutSolidSphere(radio, 20, 20);

	//gestion de direccion y animacion
	/*if (velocidad.x > 0.01)sprite.flip(false, false);
	if (velocidad.x < -0.01)sprite.flip(true, false);
	if ((velocidad.x < 0.01) && (velocidad.x > -0.01))
		sprite.setState(0);
	else if (sprite.getState() == 0)
		sprite.setState(1, false);*/

	if (sprite.getState() == 0) {
		sprite.setState(1, false);
	}

	sprite.draw();

	glPopMatrix();
}

void Moneda::setPos(float x, float y)
{
	posicion.x = x;
	posicion.y = y;
}


void Moneda::mueve(float t)
{
	posicion = posicion + velocidad * t + aceleracion * 0.5f * t * t;
	velocidad = velocidad + aceleracion * t;
	sprite.loop();
}
