#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"
class DispTank
{
	ColorRGB color;
public:
	DispTank();
	//~DispEnem();
	Vector2D posicion, velocidad, aceleracion;

	float radio, vel = 3;
	float origen = posicion.x;

	void dibuja();
	void mueve(float);
	void setPos(float, float);
	void setVel(float, float);
	void setColor(Byte, Byte, Byte);

	friend class Tank;

	int ini = 0;
};
