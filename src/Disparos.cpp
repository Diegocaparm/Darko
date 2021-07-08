#include "Disparos.h"

//Constructores de los distintos disparos
Disparos::Disparos() {
	setColor(10, 100, 0);
	//radio = 0.15f;
	setAc(0, -0.5);
	sprite.setCenter(3, 2.9);
	sprite.setSize(3, 6);
}
Disparos::Disparos(float px, float py) {
	setColor(10, 100, 0);
	setPos(px, py);
	//radio = 0.15f;
	setAc(0, -0.5);
	sprite.setCenter(3, 2.9);
	sprite.setSize(3, 6);
}
DisparosAmigos::DisparosAmigos()
{
	radio = 0.15f;
	cosa = 1;
	//sprite.setCenter(1, 1);
	//sprite.setSize(2, 2);
}
DisparosAmigos::DisparosAmigos(float px, float py, float vx, float vy) {
	cosa = 1;
	setPos(px, py);
	radio = 0.15f;
	//la velocidad variable chunga
	setVel(vel+vx,vy);

}
Espada::Espada() {
	cosa = 1;
	setColor(0, 1, 1);
	radio = 1.5f;
	sprite.setCenter(3.1, 1.5);
	sprite.setSize(4,4);

}
Espada::Espada(float px, float py) {
	setPos(px, py);
	radio = 1.5f;

}
DisparosEnemigos::DisparosEnemigos() {}
DisparosEnemigos::DisparosEnemigos(float px, float py) {
	cosa = 2;
	//Disparos(px, py);
	setPos(px, py);
	radio = 0.25f;
	setVel(-vel, 0);

}
Misiles::Misiles()
{
	cosa = 3;
	radio = 0.5f;
	misil.setCenter(3, 2.9);
	misil.setSize(3, 6);
}
Misiles::Misiles(float px, float py) {
	cosa = 3;
	setPos(px, py);
	radio = 0.5f;
	setVel(-vel, 0);
	misil.setCenter(1,2);
	misil.setSize(3, 3);
}

//Métodos virtuales de Disparos
void Disparos::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.2);
	glColor3f(color.r, color.g, color.b);
	if (velocidad.x > 0.01)sprite.flip(false, false);
	if (velocidad.x < -0.01)sprite.flip(true, false);
	if ((velocidad.x < 0.01) && (velocidad.x > -0.01))
		sprite.setState(0);
	else if (sprite.getState() == 0)
		sprite.setState(0, true);
	sprite.draw();
	glPopMatrix();

}
void Disparos::mueve(float t)
{
	//Este virtual genérico si que está con cosas porque es el que usan 
	//los disparos buenos y malos 
	ObjetoMovil::mueve(t);
	sprite.loop();
	if (temp < 120) {		//40 para 1 seg
		temp++;
		//dispEnem1.mueve(t);
		if (temp == 120) {
			setColor(1, 0, 0);
		}
		if (temp == 80)
			setColor(0, 0, 10);
	}
	else {
		//~DispEnem();
		temp = 0;
	}
}
void Disparos::setPos(float ix, float iy) {
	posicion.x = ix;
	posicion.y = iy;
}
void Disparos::setVel(float vx, float vy) {
	velocidad.x = vx;
	velocidad.y = vy;
}
void Disparos::setAc(float ax, float ay) {
	aceleracion.x = ax;
	aceleracion.y = ay;
}
void Disparos::setColor(Byte r, Byte g, Byte b) {
	color.r = r;
	color.g = g;
	color.b = b;
}
float Disparos::getRadio() {
	return radio;
}

//Métodos propios de Espada
void Espada::dibuja() {
	glPushMatrix();
	glColor3f(color.r, color.g, color.b);
	glTranslatef(posicion.x, posicion.y, 0.2);
	glRotatef(angulo , 0, 0, -1);
	sprite.draw();
	glPopMatrix();
}
void Espada::mueve(float t) {
	ObjetoMovil::mueve(t);
	if (flag) {
		angulo += 9;
		if (angulo > 360) {
			flag = 0;
			angulo = 0;
		}
	}
}
int Espada::getFlag() {
	return flag;
}
void Espada::setFlag(int i) {
	flag = i;
}
float Espada::getLong() {
	return radio;
}

//Métodos propios de Misiles
void Misiles::mueve(float t) {
	ObjetoMovil::mueve(t);
	if (temp < 200) {
		temp++;
	}
	else {
		temp = 0;
	}
	misil.loop();
	if (cerca) {
		if (prx)
			aceleracion.x = -1.5;
		else
			aceleracion.x = 1.5;

		if (pry)
			aceleracion.y = -1.5;
		else
			aceleracion.y = 1.5;

		if (velocidad.x > 2.5)
			velocidad.x = 2.5;
		if (velocidad.y > 2.5)
			velocidad.y = 2.5;
	}
	else {
		if (prx)
			aceleracion.x = -1.5;
		else
			aceleracion.x = 1.5;

		if (pry)
			aceleracion.y = -1.5;
		else
			aceleracion.y = 1.5;
		if (velocidad.x > 3.5)
			velocidad.x = 3.5;
		if (velocidad.y > 3.5)
			velocidad.y = 3.5;
	}
}
void Misiles::dibuja()
{
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.2);
	if (velocidad.x > 0.01)misil.flip(true, false);
	if (velocidad.x < -0.01)misil.flip(false, false);
	if ((velocidad.x < 0.01) && (velocidad.x > -0.01))
		misil.setState(0);
	else if (misil.getState() == 0)
		misil.setState(0, true);
	misil.draw();
	glPopMatrix();
}
