#include "Disparos.h"

//Constructores de los distintos disparos
Disparos::Disparos() {
	setAc(0, -0.5);
	sprite.setCenter(3, 2.9f);
	sprite.setSize(3, 6);
}
Disparos::Disparos(float px, float py) {
	setPos(px, py);
	setAc(0, -0.5);
	sprite.setCenter(3, 2.9f);
	sprite.setSize(3, 6);
}
DisparosAmigos::DisparosAmigos()
{
	radio = 0.15f;
	cosa = 1;
}
DisparosAmigos::DisparosAmigos(float px, float py, float vx, float vy) {
	cosa = 1;
	setPos(px, py);
	radio = 0.15f;
	setVel(vel+vx,vy);
}
Espada::Espada() {
	cosa = 1;
	radio = 2.0f;
	sprite.setCenter(3.1, 1.5f);
	sprite.setSize(4,4);
}
Espada::Espada(float px, float py) {
	setPos(px, py);
	radio = 2.0f;
}
DisparosEnemigos::DisparosEnemigos() {}
DisparosEnemigos::DisparosEnemigos(float px, float py) 
{
	cosa = 2;
	setPos(px, py);
	radio = 0.25f;
	setVel(-vel, 0);

}
Misiles::Misiles()
{
	cosa = 3;
	radio = 0.5f;
	misil.setCenter(3, 2.9f);
	misil.setSize(3, 6);
}
Misiles::Misiles(float px, float py) 
{
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
	if (existe) {
		glPushMatrix();
		glTranslatef(posicion.x, posicion.y - 0.5f, 0.2f);
		if (velocidad.x > 0.01f)sprite.flip(false, false);
		if (velocidad.x < -0.01f)sprite.flip(true, false);
		if ((velocidad.x < 0.01f) && (velocidad.x > -0.01f))
			sprite.setState(0);
		else if (sprite.getState() == 0)
			sprite.setState(0, true);
		sprite.draw();
		glPopMatrix();
	}
}
void Disparos::mueve(float t)
{
	//Este virtual genérico si que está con cosas porque es el que usan 
	//los disparos buenos y malos 
	ObjetoMovil::mueve(t);
	sprite.loop();
	if (temp < 120) 	//40 por cada 1 seg
		temp++;
	else 
		temp = 0;
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
float Disparos::getRadio() {
	return radio;
}

//Métodos propios de Espada
void Espada::dibuja() {
	glPushMatrix();
	glTranslatef(posicion.x, posicion.y, 0.2f);
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
	glTranslatef(posicion.x, posicion.y, 0.2f);
	if (velocidad.x > 0.01)misil.flip(true, false);
	if (velocidad.x < -0.01)misil.flip(false, false);
	if ((velocidad.x < 0.01) && (velocidad.x > -0.01))
		misil.setState(0);
	else if (misil.getState() == 0)
		misil.setState(0, true);
	misil.draw();
	glPopMatrix();
}
