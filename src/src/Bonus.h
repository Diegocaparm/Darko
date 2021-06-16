#pragma once
#include "Vector2D.h"
#include "ColorRGB.h"
#include "Hitbox.h"
#include <math.h>
#include <stdlib.h>
class Bonus
{
	ColorRGB color;
	Vector2D posicion;
	Hitbox hitbox;
public:
	Bonus();
	Bonus(float px, float py);
	float lado;
	void dibuja();
	//void mueve(float);
	void setPos(float, float);
	void setColor(Byte, Byte, Byte);

	friend class Interaccion;
};


