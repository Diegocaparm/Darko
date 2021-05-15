#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"

class Estela
{
	ColorRGB color;

public:
	float radio1;
	float radio2;
	Vector2D posicion, velocidad, aceleracion;
	Estela();
	void dibuja(float);
	void mueve(float);
	void setColor(Byte, Byte, Byte);
};

