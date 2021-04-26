#pragma once
#include "Vector2D.h"
class Pared
{
	unsigned char rojo, verde, azul;
	Vector2D limite1, limite2;
public:
	Pared();
	void dibuja();
	void SetPos(float, float, float, float);
	void SetColor(unsigned char, unsigned char, unsigned char);
};

