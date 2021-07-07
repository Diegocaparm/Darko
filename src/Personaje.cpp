#include "Personaje.h"

Personaje::Personaje():sprite_darko("bin/imagenes/darkoespfvect.png", 2 ), sprite_humano("bin/imagenes/astrofvect.png", 2 ) {
	fin = 200;		//MIRAR CUANDO SE TERMINA EL NIVEL
	setPos(-4, 16);		//-4 o 180
	setAc(0, -9.8);
	setColor(1, 1, 0);
	sprite_darko.setCenter(1.5, 0);
	sprite_darko.setSize(3, 3);
	sprite_humano.setCenter(1.5, 0);
	sprite_humano.setSize(3, 3);

	puntero = &sprite_darko;
	guardapersonaje = 2;
	//bala->setPos(posicion.x, posicion.y + altura * 2 / 3);
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
			aceleracion.y = 250;
			flag = 0;
			//salto = 0;						//comentar para salto infinito
		}
	}
	if (velocidad.y < 0.3f && velocidad.y > -0.3f && sentido == 1 && salto == 0)
		salto = 1;

	//Añadido por Miguel (crea las paredes hitbox)
	Vector2D e1, e2, e3, e4;
	e1.x = posicion.x - 0.3f;	e1.y = posicion.y + 1.8f;
	e2.x = posicion.x + 0.3f;	e2.y = posicion.y + 1.8f;
	e3.x = posicion.x - 0.3f;	e3.y = posicion.y - 0.0f;
	e4.x = posicion.x + 0.3f;	e4.y = posicion.y - 0.0f;
	hitbox.setPos(e1, e2, e3, e4);

	sprite_darko.loop();
	sprite_humano.loop();
}

void Personaje::setPersonaje(unsigned char key)		//Elección de personajes Sofía
{
	if (key == 'P' || key == 'p')  //Elegimos Darko
	{
		setDarko();
		setguardapersonaje(0);
	}

	if (key == 'H' || key == 'h')  //Elegimos Humano
	{
		setHumano();
		setguardapersonaje(1);
	}
} 

void Personaje::dibuja() {
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0);
	glColor3f(color.r, color.g, color.b);
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
	//gestion de direccion y animacion
	if (velocidad.x > 0.01)puntero->flip(false, false); //Para la selección del personaje pongo un puntero para no poner el sprite directamente
	if (velocidad.x < -0.01)puntero->flip(true, false);
	if ((velocidad.x < 0.01) && (velocidad.x > -0.01))
		puntero->setState(0);
	else if (puntero->getState() == 0)
		puntero->setState(1, false);
	puntero->draw();

	glPopMatrix();

	//Añadido por Miguel (Dibuja los bordes de choque)
	glPushMatrix();
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
	glPopMatrix();
}

/*void Personaje::mueve(float t) {
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
			aceleracion.y = 250;
			flag = 0;
			//salto = 0;						//comentar para salto infinito
		}
	}
	if (velocidad.y < 0.3f && velocidad.y > -0.3f && sentido == 1 && salto == 0)
		salto = 1;

	//Añadido por Miguel (crea las paredes hitbox)
	Vector2D e1, e2, e3, e4;
	e1.x = posicion.x - 0.3f;	e1.y = posicion.y + 1.8f;
	e2.x = posicion.x + 0.3f;	e2.y = posicion.y + 1.8f;
	e3.x = posicion.x - 0.3f;	e3.y = posicion.y - 0.0f;
	e4.x = posicion.x + 0.3f;	e4.y = posicion.y - 0.0f;
	hitbox.setPos(e1, e2, e3, e4);
}*/

int Personaje::getNivel()
{
	return flagnivel;
}
