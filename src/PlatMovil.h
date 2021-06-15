#pragma once
#include "Pared.h"
class PlatMovil :public Pared
{
	Vector2D vel;
	Vector2D extremo1, extremo2;
public:
	PlatMovil(float, float, float, float, float, float, float, float, float, float, Byte, Byte, Byte);
	void mueve(float);
};

