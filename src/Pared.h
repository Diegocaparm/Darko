#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"

class Pared
{
	ColorRGB color;
	Vector2D limite1, limite2;
public:
	Pared();
	Pared(float x1, float y1, float x2, float y2, Byte r, Byte g, Byte b);
	void dibuja();
	void setPos(float, float, float, float);	//x1,y1,x2,y2
	void setColor(Byte, Byte, Byte);
	float distancia(Vector2D punto, Vector2D* direccion = 0);

	friend class Interaccion;

};

