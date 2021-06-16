#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"
#include "misil.h"
#include "Hitbox.h"
class bossFinal
{
	ColorRGB color;
	Vector2D posicion, velocidad, aceleracion;
	Hitbox hitbox;

public:
	bossFinal();
	bossFinal(float px, float py);
	float altura;
	void dibuja();
	void mueve(float);
	void setColor(Byte, Byte, Byte);
	void setVelx(float);		//antes era void setVel(float, float);
	void setPos(float x, float y);
	Vector2D getPos();
	
	friend class Interaccion;
	friend class Mundo;
	friend class Nivel1;

	int zonaV = 0, zonaH = 0;	//zonaV=0 abajo =1 arriba		zonaH=-1 izq =0 dentro =1 dcha
	int temp = 0, sentido = 1;	//temp contador para disparar	sentido=0 izq =1 dcha
	misil* misil1 = new misil(),
		* misil2 = new misil(),
		* misil3 = new misil(),
		* misil4 = new misil(),
		* misil5 = new misil(),
		* misil6 = new misil(),
		* misil7 = new misil(),
		* misil8 = new misil(),
		* misil9 = new misil(),
		* misil10 = new misil();

};

