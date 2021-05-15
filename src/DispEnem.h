#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"
class DispEnem
{
	ColorRGB color;
public:
	DispEnem();
	//~DispEnem();
	Vector2D posicion, velocidad, aceleracion;

	float radio;
	float origen = posicion.x;
	
	void dibuja();
	void mueve(float);
	void setPos(float, float);
	void setColor(Byte, Byte, Byte);

	friend class EnemigoDisp;

	int ini = 0;
};

