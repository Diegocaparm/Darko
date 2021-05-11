#include "Dinero.h"
#include "freeglut.h"

Dinero::Dinero()
{
	contador = 0;
	posicion.x = 10;
	posicion.y = 10;
	sprite.setCenter(1, 0);
	sprite.setSize(2, 2);

}

void Dinero::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glutSolidSphere(10, 20, 20);

	//gestion de direccion y animacion
	/*if (velocidad.x > 0.01)sprite.flip(false, false);
	if (velocidad.x < -0.01)sprite.flip(true, false);
	if ((velocidad.x < 0.01) && (velocidad.x > -0.01))
		sprite.setState(0);
	else if (sprite.getState() == 0)
		sprite.setState(1, false);*/
	sprite.setState(1, true);
	sprite.draw();
	glPopMatrix();
}
