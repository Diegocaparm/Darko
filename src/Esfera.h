#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"
class Esfera
{
	float radio;
	ColorRGB color;
	Vector2D posicion, velocidad, aceleracion;
public:
	Esfera();
	void dibuja();
	void mueve(float);
	void setColor(Byte, Byte, Byte);
	void setRadio(float);
	void setPos(float, float);
	void setVel(float, float);


	friend class Interaccion;
};

