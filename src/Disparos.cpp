#include "Disparos.h"

//Constructores de los distintos disparos
Disparos::Disparos() {
	setColor(10, 100, 0);
	//radio = 0.15f;
	setAc(0, -0.5);
}
Disparos::Disparos(float px, float py) {
	setColor(10, 100, 0);
	setPos(px, py);
	//radio = 0.15f;
	setAc(0, -0.5);
}
DisparosAmigos::DisparosAmigos(float px, float py) {
	Disparos(px, py);
	radio = 0.15f;
	//la velocidad variable chunga
	//setVel(3+vx,0);
}
Espada::Espada() {}
Espada::Espada(float px, float py) {
	Disparos(px, py);
	radio = 1.5f;
}
DisparosEnemigos::DisparosEnemigos() {}
DisparosEnemigos::DisparosEnemigos(float px, float py) {
	Disparos(px, py);
	radio = 0.25f;
	setVel(-vel, 0);
}
Misiles::Misiles(float px, float py) {
	Disparos(px, py);
	radio = 0.5f;
	setVel(-vel, 0);
}

//Métodos virtuales de Disparos
void Disparos::dibuja()
{

}
void Disparos::mueve(float t)
{
	//Este virtual genérico si que está con cosas porque es el que usan 
	//los disparos buenos y malos 
	ObjetoMovil::mueve(t);
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
	Disparos::mueve(t);
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