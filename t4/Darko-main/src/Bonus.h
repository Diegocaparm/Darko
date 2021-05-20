#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"
#include <math.h>
#include <stdlib.h>
class Bonus
{
	ColorRGB color;
	Vector2D posicion, velocidad, aceleracion;

public:

	Bonus();
	float lado;
	void dibuja();
	void mueve(float);
	void setPos(float, float);
	void setColor(Byte, Byte, Byte);

};


