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
};


