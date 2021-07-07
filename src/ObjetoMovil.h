#pragma once
#include "ColorRGB.h"
#include "Vector2D.h"
#include "freeglut.h"
#include "Hitbox.h"
class ObjetoMovil
{
protected:
	ColorRGB color;
	Vector2D posicion, velocidad, aceleracion;
	Hitbox hitbox;
	int zonaV = 0, zonaH = 0;	//zonaV=0 abajo =1 arriba		zonaH =-1 izq = 0 dentro = 1 dcha
	int flagdmg, flagesp, tempdmg;
		//temporizadores, vida, flagdmg, flagesp, 
		//posicion relativa, flag direccion
public:
	virtual void dibuja();
	virtual void mueve(float);
	void setColor(Byte, Byte, Byte);
	void setPos(float, float);
	void setVel(float, float);
	void setAc(float, float);
	Vector2D getPos();

	friend class Interaccion;
};


