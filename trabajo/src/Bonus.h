#pragma once
#include "Vector2D.h"
#include <math.h>
#include <stdlib.h>
class Bonus
{
public:
	Bonus();
	unsigned char rojo, verde, azul;
	float lado;
	Vector2D posicion, velocidad, aceleracion;
	void dibuja();
	void mueve(float);
};


