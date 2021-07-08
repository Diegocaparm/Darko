#include "Personaje.h"
#include "stdio.h"

Personaje::Personaje() :sprite_darko("bin/imagenes/darkopist.png", 2), sprite_humano("bin/imagenes/astropist.png", 2) {
	//fin = 200;		//MIRAR CUANDO SE TERMINA EL NIVEL
	setPos(-4, 16);		//-4 o 180
	setAc(0, -9.8);
	setColor(1, 1, 0);
	sprite_darko.setCenter(1.5, 0.1);
	sprite_darko.setSize(3, 3);
	sprite_humano.setCenter(1.5, 0.1);
	sprite_humano.setSize(3, 3);

	if (guardapersonaje == 1)
		puntero = &sprite_darko;
	if (guardapersonaje == 2)
		puntero = &sprite_humano;
}

int Personaje::setPersonaje(unsigned char key)		//Elecci�n de personajes Sof�a
{
	if (key == 'P' || key == 'p')  //Elegimos Darko
	{
		setDarko();
		printf_s("perro");
		return 1;
	}

	if (key == 'H' || key == 'h')  //Elegimos Humano
	{
		setHumano();
		printf_s("humano");
		return 2;
	}
}

void Personaje::dibuja() {
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(color.r, color.g, color.b);
	if (velocidad.x > 0.01)puntero->flip(false, false); //Para la selecci�n del personaje pongo un puntero para no poner el sprite directamente
	if (velocidad.x < -0.01)puntero->flip(true, false);
	if ((velocidad.x < 0.01) && (velocidad.x > -0.01))
		puntero->setState(0);
	else if (puntero->getState() == 0)
		puntero->setState(1, false);
	puntero->draw();

	glPopMatrix();

	//A�adido por Miguel (Dibuja los bordes de choque)
	/*glPushMatrix();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(hitbox.top_l.x, hitbox.top_l.y, 0);
	glVertex3f(hitbox.top_r.x, hitbox.top_r.y, 0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(hitbox.top_r.x, hitbox.top_r.y, 0);
	glVertex3f(hitbox.bot_r.x, hitbox.bot_r.y, 0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(hitbox.bot_r.x, hitbox.bot_r.y, 0);
	glVertex3f(hitbox.bot_l.x, hitbox.bot_l.y, 0);
	glEnd();
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex3f(hitbox.bot_l.x, hitbox.bot_l.y, 0);
	glVertex3f(hitbox.top_l.x, hitbox.top_l.y, 0);
	glEnd();
	glPopMatrix();*/
}

void Personaje::mueve(float t) {
	ObjetoMovil::mueve(t);
	//velocidad horizontal
	if (flagH == -1)
		setVel(-7.5f, velocidad.y);
	else if (flagH == 0)
		setVel(0.0f, velocidad.y);
	else if (flagH == 1)
		setVel(7.5f, velocidad.y);

	//Salto de David
	if (velocidad.y > 0.3f)
		sentido = 0;			//0 subiendo    1 bajando
	if (velocidad.y < -2)
		//else
		sentido = 1;

	if (flag == 0) {
		aceleracion.y = -9.8f;
	}
	else {
		if (salto == 1) {
			aceleracion.y = 300;
			flag = 0;
			salto = 1;		//comentar para salto infinito
		}
	}
	if (tempdmg)	//volverse invulnerable
		tempdmg--;
	//if (velocidad.y < 0.3f && velocidad.y > -0.3f && sentido == 1 && salto == 0)
		//salto = 1;

	//A�adido por Miguel (crea las paredes hitbox)
	Vector2D e1, e2, e3, e4;
	e1.x = posicion.x - 0.3f;	e1.y = posicion.y + 1.8f;
	e2.x = posicion.x + 0.3f;	e2.y = posicion.y + 1.8f;
	e3.x = posicion.x - 0.3f;	e3.y = posicion.y - 0.0f;
	e4.x = posicion.x + 0.3f;	e4.y = posicion.y - 0.0f;
	hitbox.setPos(e1, e2, e3, e4);

	sprite_darko.loop();
	sprite_humano.loop();
}
bool Personaje::caida(VidasRecolectadas* v)
{
	if (posicion.y < -10.0f) {
		setPos(-4, 16);
		v->reduceVida();
		return true;
	}
	return false;
}
int Personaje::getNivel()
{
	return flagnivel;
}